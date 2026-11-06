/*
 * Benchmark Program: R000227
 * Security Family: nested_implicit_flow
 * Generator Seed: 522713
 * High Inputs: 20 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000227_2713_0 {
    int fee;
    int balance;
    int rate;
    int buffer[3];
};

struct SensorNode_R000227_2713_1 {
    int offset;
    unsigned char gain;
    unsigned char reading;
    unsigned char calib;
    int status;
    int buffer[3];
};

struct MatrixBlock_R000227_2713_2 {
    int scale;
    int dim;
    int stride;
    int density;
    unsigned char determinant;
    short trace;
    int buffer[3];
};

union ColorPixel_R000227_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000227_2713_0(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_97 = (aux + st.buffer[1]) & 3;
    switch (delta_97) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_42 = local_arr[aux % 3];
    acc = (acc + scale_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_36 = local_arr[aux % 3];
    acc = (acc + delta_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_2(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int quotient_38 = local_arr[aux % 3];
    acc = (acc + quotient_38 * 2) & 127;
    int cursor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_79 > 11) {
        acc = (acc + cursor_79 * 2 + 5) & 127;
        aux ^= (cursor_79 & 15);
    } else {
        acc = (acc - cursor_79 + 11) & 127;
        aux += 3;
    }
    int margin_89 = (aux + st.buffer[1]) & 3;
    switch (margin_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int mask_66 = local_arr[aux % 3];
    acc = (acc + mask_66 * 2) & 127;
    int index_reg_36 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_36 > 17) {
        acc = (acc + index_reg_36 * 2 + 5) & 127;
        aux ^= (index_reg_36 & 15);
    } else {
        acc = (acc - index_reg_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int tracker_69 = local_arr[aux % 3];
    acc = (acc + tracker_69 * 2) & 127;
    int accumulator_53 = (aux + st.buffer[1]) & 3;
    switch (accumulator_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_60 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_60 > 31) {
        acc = (acc + sample_60 * 2 + 5) & 127;
        aux ^= (sample_60 & 15);
    } else {
        acc = (acc - sample_60 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_23 = local_arr[aux % 3];
    acc = (acc + vector_23 * 2) & 127;
    int damping_37 = (aux + st.buffer[1]) & 3;
    switch (damping_37) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_6(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_95 = local_arr[aux % 3];
    acc = (acc + stride_95 * 2) & 127;
    int accumulator_18 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_18 > 23) {
        acc = (acc + accumulator_18 * 2 + 5) & 127;
        aux ^= (accumulator_18 & 15);
    } else {
        acc = (acc - accumulator_18 + 11) & 127;
        aux += 3;
    }
    int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000227_2713_7(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int pivot_67 = (aux + st.buffer[1]) & 3;
    switch (pivot_67) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_82) & 63;
    acc ^= aux;
    int delta_32 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_32 > 29) {
        acc = (acc + delta_32 * 2 + 5) & 127;
        aux ^= (delta_32 & 15);
    } else {
        acc = (acc - delta_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_36) & 63;
    acc ^= aux;
    int offset_59 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_59 > 46) {
        acc = (acc + offset_59 * 2 + 5) & 127;
        aux ^= (offset_59 & 15);
    } else {
        acc = (acc - offset_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_87 = local_arr[aux % 3];
    acc = (acc + factor_87 * 2) & 127;
    int pivot_38 = (aux + st.buffer[1]) & 3;
    switch (pivot_38) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_97) & 63;
    acc ^= aux;
    int index_reg_73 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_73 > 33) {
        acc = (acc + index_reg_73 * 2 + 5) & 127;
        aux ^= (index_reg_73 & 15);
    } else {
        acc = (acc - index_reg_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_69 = (aux + st.buffer[1]) & 3;
    switch (quotient_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_11(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_89 = (aux + st.buffer[1]) & 3;
    switch (tracker_89) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_52) & 63;
    acc ^= aux;
    int bound_71 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_71 > 29) {
        acc = (acc + bound_71 * 2 + 5) & 127;
        aux ^= (bound_71 & 15);
    } else {
        acc = (acc - bound_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int window_40 = (st.buffer[0] * 3 + aux) & 63;
    if (window_40 > 36) {
        acc = (acc + window_40 * 2 + 5) & 127;
        aux ^= (window_40 & 15);
    } else {
        acc = (acc - window_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000227_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_69 = (aux + st.buffer[1]) & 3;
    switch (scale_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000227_2713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int pivot_27 = local_arr[aux % 3];
    acc = (acc + pivot_27 * 2) & 127;
    int tally_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000227_2713_15(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_85 = (aux + st.buffer[1]) & 3;
    switch (cursor_85) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_45 = local_arr[aux % 3];
    acc = (acc + quotient_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_97 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_97 > 28) {
        acc = (acc + delta_97 * 2 + 5) & 127;
        aux ^= (delta_97 & 15);
    } else {
        acc = (acc - delta_97 + 11) & 127;
        aux += 3;
    }
    int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_65) & 63;
    acc ^= aux;
    int tally_30 = (aux + st.buffer[1]) & 3;
    switch (tally_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_17(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_15 = (aux + st.buffer[1]) & 3;
    switch (window_15) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_97 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_97 > 49) {
        acc = (acc + accumulator_97 * 2 + 5) & 127;
        aux ^= (accumulator_97 & 15);
    } else {
        acc = (acc - accumulator_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_18(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_21 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_21 > 36) {
        acc = (acc + factor_21 * 2 + 5) & 127;
        aux ^= (factor_21 & 15);
    } else {
        acc = (acc - factor_21 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_35 = local_arr[aux % 3];
    acc = (acc + weight_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_59 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_59 > 43) {
        acc = (acc + tracker_59 * 2 + 5) & 127;
        aux ^= (tracker_59 & 15);
    } else {
        acc = (acc - tracker_59 + 11) & 127;
        aux += 3;
    }
    int damping_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000227_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int window_25 = local_arr[aux % 3];
    acc = (acc + window_25 * 2) & 127;
    int mask_86 = (aux + st.buffer[1]) & 3;
    switch (mask_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_72) & 63;
    acc ^= aux;
    int accumulator_65 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_65 > 38) {
        acc = (acc + accumulator_65 * 2 + 5) & 127;
        aux ^= (accumulator_65 & 15);
    } else {
        acc = (acc - accumulator_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000227_2713_21(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int vector_86 = (aux + st.buffer[1]) & 3;
    switch (vector_86) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000227_2713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int threshold_93 = local_arr[aux % 3];
    acc = (acc + threshold_93 * 2) & 127;
    int delta_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_35) & 63;
    acc ^= aux;
    int scale_55 = (aux + st.buffer[1]) & 3;
    switch (scale_55) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_92 = (st.buffer[0] * 3 + aux) & 63;
    if (window_92 > 30) {
        acc = (acc + window_92 * 2 + 5) & 127;
        aux ^= (window_92 & 15);
    } else {
        acc = (acc - window_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000227_0;
    int sec_r000227_1;
    int sec_r000227_2;
    int sec_r000227_3;
    int sec_r000227_4;
    int sec_r000227_5;
    int sec_r000227_6;
    int sec_r000227_7;
    int sec_r000227_8;
    int sec_r000227_9;
    int sec_r000227_10;
    int sec_r000227_11;
    int sec_r000227_12;
    int sec_r000227_13;
    int sec_r000227_14;
    int sec_r000227_15;
    int sec_r000227_16;
    int sec_r000227_17;
    int sec_r000227_18;
    int sec_r000227_19;
    int pub_r000227_0;
    int pub_r000227_1;
    int pub_r000227_2;
    int pub_r000227_3;
    int pub_r000227_4;
    int pub_r000227_5;
    int pub_r000227_6;
    int pub_r000227_7;
    int pub_r000227_8;
    int pub_r000227_9;
    int pub_r000227_10;
    int pub_r000227_11;
    int pub_r000227_12;
    int pub_r000227_13;
    int pub_r000227_14;
    int pub_r000227_15;
    int pub_r000227_16;
    int pub_r000227_17;
    int pub_r000227_18;
    int pub_r000227_19;
    int pub_r000227_20;
    int pub_r000227_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000227_0 >= -100 && pub_r000227_0 <= 100);
    __CPROVER_assume(pub_r000227_1 >= -100 && pub_r000227_1 <= 100);
    __CPROVER_assume(pub_r000227_2 >= -100 && pub_r000227_2 <= 100);
    __CPROVER_assume(pub_r000227_3 >= -100 && pub_r000227_3 <= 100);
    __CPROVER_assume(pub_r000227_4 >= -100 && pub_r000227_4 <= 100);
    __CPROVER_assume(pub_r000227_5 >= -100 && pub_r000227_5 <= 100);
    __CPROVER_assume(pub_r000227_6 >= -100 && pub_r000227_6 <= 100);
    __CPROVER_assume(pub_r000227_7 >= -100 && pub_r000227_7 <= 100);
    __CPROVER_assume(pub_r000227_8 >= -100 && pub_r000227_8 <= 100);
    __CPROVER_assume(pub_r000227_9 >= -100 && pub_r000227_9 <= 100);
    __CPROVER_assume(pub_r000227_10 >= -100 && pub_r000227_10 <= 100);
    __CPROVER_assume(pub_r000227_11 >= -100 && pub_r000227_11 <= 100);
    __CPROVER_assume(pub_r000227_12 >= -100 && pub_r000227_12 <= 100);
    __CPROVER_assume(pub_r000227_13 >= -100 && pub_r000227_13 <= 100);
    __CPROVER_assume(pub_r000227_14 >= -100 && pub_r000227_14 <= 100);
    __CPROVER_assume(pub_r000227_15 >= -100 && pub_r000227_15 <= 100);
    __CPROVER_assume(pub_r000227_16 >= -100 && pub_r000227_16 <= 100);
    __CPROVER_assume(pub_r000227_17 >= -100 && pub_r000227_17 <= 100);
    __CPROVER_assume(pub_r000227_18 >= -100 && pub_r000227_18 <= 100);
    __CPROVER_assume(pub_r000227_19 >= -100 && pub_r000227_19 <= 100);
    __CPROVER_assume(pub_r000227_20 >= -100 && pub_r000227_20 <= 100);
    __CPROVER_assume(pub_r000227_21 >= -100 && pub_r000227_21 <= 100);
    __CPROVER_assume(sec_r000227_0 >= 0 && sec_r000227_0 <= 255);
    __CPROVER_assume(sec_r000227_1 >= 0 && sec_r000227_1 <= 255);
    __CPROVER_assume(sec_r000227_2 >= 0 && sec_r000227_2 <= 255);
    __CPROVER_assume(sec_r000227_3 >= 0 && sec_r000227_3 <= 255);
    __CPROVER_assume(sec_r000227_4 >= 0 && sec_r000227_4 <= 255);
    __CPROVER_assume(sec_r000227_5 >= 0 && sec_r000227_5 <= 255);
    __CPROVER_assume(sec_r000227_6 >= 0 && sec_r000227_6 <= 255);
    __CPROVER_assume(sec_r000227_7 >= 0 && sec_r000227_7 <= 255);
    __CPROVER_assume(sec_r000227_8 >= 0 && sec_r000227_8 <= 255);
    __CPROVER_assume(sec_r000227_9 >= 0 && sec_r000227_9 <= 255);
    __CPROVER_assume(sec_r000227_10 >= 0 && sec_r000227_10 <= 255);
    __CPROVER_assume(sec_r000227_11 >= 0 && sec_r000227_11 <= 255);
    __CPROVER_assume(sec_r000227_12 >= 0 && sec_r000227_12 <= 255);
    __CPROVER_assume(sec_r000227_13 >= 0 && sec_r000227_13 <= 255);
    __CPROVER_assume(sec_r000227_14 >= 0 && sec_r000227_14 <= 255);
    __CPROVER_assume(sec_r000227_15 >= 0 && sec_r000227_15 <= 255);
    __CPROVER_assume(sec_r000227_16 >= 0 && sec_r000227_16 <= 255);
    __CPROVER_assume(sec_r000227_17 >= 0 && sec_r000227_17 <= 255);
    __CPROVER_assume(sec_r000227_18 >= 0 && sec_r000227_18 <= 255);
    __CPROVER_assume(sec_r000227_19 >= 0 && sec_r000227_19 <= 255);

    struct Transaction_R000227_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000227_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000227_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000227_0 + 7) & 15;
    struct SensorNode_R000227_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000227_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000227_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000227_0 + 9) & 15;
    struct MatrixBlock_R000227_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000227_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000227_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000227_0 + 11) & 15;

    union ColorPixel_R000227_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 16) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 31) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 31) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 46) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 50) {
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
    if ((sec_r000227_3 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_9 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_9 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_9 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_10 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_10 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_10 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_11 = (pub_r000227_2 + 31) & 127;
        } else {
            stage_v_11 = (pub_r000227_2 + 13) & 127;
        }
    } else {
        stage_v_11 = (pub_r000227_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((sec_r000227_2 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_12 = (pub_r000227_14 + 31) & 127;
        } else {
            stage_v_12 = (pub_r000227_14 + 13) & 127;
        }
    } else {
        stage_v_12 = (pub_r000227_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_13 = (pub_r000227_2 + 31) & 127;
        } else {
            stage_v_13 = (pub_r000227_2 + 13) & 127;
        }
    } else {
        stage_v_13 = (pub_r000227_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((sec_r000227_6 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_14 = (pub_r000227_6 + 31) & 127;
        } else {
            stage_v_14 = (pub_r000227_6 + 13) & 127;
        }
    } else {
        stage_v_14 = (pub_r000227_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_15 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_15 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_15 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_16 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_16 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_16 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((sec_r000227_15 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_17 = (pub_r000227_17 + 31) & 127;
        } else {
            stage_v_17 = (pub_r000227_17 + 13) & 127;
        }
    } else {
        stage_v_17 = (pub_r000227_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((sec_r000227_6 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_18 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_18 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_18 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_19 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_19 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_19 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((sec_r000227_13 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_20 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_20 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_20 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000227_18 & 2) != 0) {
            stage_v_21 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_22 = (pub_r000227_19 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000227_19 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000227_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((sec_r000227_8 & 1) != 0) {
        if ((sec_r000227_16 & 2) != 0) {
            stage_v_23 = (pub_r000227_2 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000227_2 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000227_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_24 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_25 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((sec_r000227_9 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_26 = (pub_r000227_18 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000227_18 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000227_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_27 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000227_12 & 2) != 0) {
            stage_v_28 = (pub_r000227_9 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000227_9 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000227_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000227_10 & 2) != 0) {
            stage_v_29 = (pub_r000227_17 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000227_17 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000227_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_30 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_31 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_32 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_33 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_34 = (pub_r000227_13 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000227_13 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000227_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((sec_r000227_4 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_35 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_36 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_37 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000227_12 & 2) != 0) {
            stage_v_38 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000227_9 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_39 = (pub_r000227_18 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000227_18 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000227_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_40 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000227_7 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_41 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_42 = (pub_r000227_0 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000227_0 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000227_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_43 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000227_16 & 1) != 0) {
        if ((sec_r000227_17 & 2) != 0) {
            stage_v_44 = (pub_r000227_18 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000227_18 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000227_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_45 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_46 = (pub_r000227_2 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000227_2 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000227_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000227_10 & 1) != 0) {
        if ((sec_r000227_16 & 2) != 0) {
            stage_v_47 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000227_16 & 1) != 0) {
        if ((sec_r000227_8 & 2) != 0) {
            stage_v_48 = (pub_r000227_18 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000227_18 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000227_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_49 = (pub_r000227_9 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000227_9 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000227_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000227_8 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_50 = (pub_r000227_19 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000227_19 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000227_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000227_3 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_51 = (pub_r000227_14 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000227_14 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000227_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000227_18 & 2) != 0) {
            stage_v_52 = (pub_r000227_0 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000227_0 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000227_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000227_19 & 2) != 0) {
            stage_v_53 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000227_11 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_54 = (pub_r000227_0 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000227_0 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000227_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000227_11 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_55 = (pub_r000227_2 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000227_2 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000227_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000227_12 & 2) != 0) {
            stage_v_56 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000227_4 & 1) != 0) {
        if ((sec_r000227_3 & 2) != 0) {
            stage_v_57 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000227_18 & 1) != 0) {
        if ((sec_r000227_7 & 2) != 0) {
            stage_v_58 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000227_12 & 1) != 0) {
        if ((sec_r000227_7 & 2) != 0) {
            stage_v_59 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000227_6 & 1) != 0) {
        if ((sec_r000227_17 & 2) != 0) {
            stage_v_60 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000227_14 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_61 = (pub_r000227_13 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000227_13 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000227_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_62 = (pub_r000227_9 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000227_9 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000227_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_63 = (pub_r000227_6 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000227_6 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000227_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_64 = (pub_r000227_6 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000227_6 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000227_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000227_16 & 2) != 0) {
            stage_v_65 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000227_12 & 1) != 0) {
        if ((sec_r000227_10 & 2) != 0) {
            stage_v_66 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_67 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_68 = (pub_r000227_17 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000227_17 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000227_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_69 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000227_15 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_70 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_71 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000227_1 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_72 = (pub_r000227_11 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000227_11 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000227_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_73 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_74 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000227_2 & 1) != 0) {
        if ((sec_r000227_8 & 2) != 0) {
            stage_v_75 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000227_17 & 2) != 0) {
            stage_v_76 = (pub_r000227_15 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000227_15 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000227_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_77 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_78 = (pub_r000227_14 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000227_14 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000227_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000227_13 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_79 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_80 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000227_7 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_81 = (pub_r000227_20 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000227_20 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000227_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000227_7 & 1) != 0) {
        if ((sec_r000227_7 & 2) != 0) {
            stage_v_82 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000227_14 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_83 = (pub_r000227_17 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000227_17 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000227_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_84 = (pub_r000227_19 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000227_19 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000227_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000227_4 & 1) != 0) {
        if ((sec_r000227_10 & 2) != 0) {
            stage_v_85 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_86 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_87 = (pub_r000227_19 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000227_19 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000227_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000227_7 & 2) != 0) {
            stage_v_88 = (pub_r000227_6 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000227_6 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000227_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_89 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_90 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_91 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_92 = (pub_r000227_14 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000227_14 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000227_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000227_17 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_93 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_94 = (pub_r000227_11 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000227_11 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000227_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000227_19 & 2) != 0) {
            stage_v_95 = (pub_r000227_0 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000227_0 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000227_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000227_18 & 1) != 0) {
        if ((sec_r000227_10 & 2) != 0) {
            stage_v_96 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_97 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_98 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_99 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_100 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_101 = (pub_r000227_6 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000227_6 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000227_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000227_3 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_102 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000227_8 & 2) != 0) {
            stage_v_103 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000227_2 & 2) != 0) {
            stage_v_104 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000227_18 & 2) != 0) {
            stage_v_105 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_106 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000227_12 & 2) != 0) {
            stage_v_107 = (pub_r000227_8 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000227_8 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000227_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_108 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000227_9 & 2) != 0) {
            stage_v_109 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_110 = (pub_r000227_13 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000227_13 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000227_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_111 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000227_12 & 1) != 0) {
        if ((sec_r000227_4 & 2) != 0) {
            stage_v_112 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_113 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000227_8 & 2) != 0) {
            stage_v_114 = (pub_r000227_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000227_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000227_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_115 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000227_11 & 2) != 0) {
            stage_v_116 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000227_3 & 2) != 0) {
            stage_v_117 = (pub_r000227_13 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000227_13 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000227_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000227_10 & 2) != 0) {
            stage_v_118 = (pub_r000227_16 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000227_16 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000227_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000227_17 & 1) != 0) {
        if ((sec_r000227_17 & 2) != 0) {
            stage_v_119 = (pub_r000227_11 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000227_11 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000227_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000227_14 & 2) != 0) {
            stage_v_120 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000227_19 & 2) != 0) {
            stage_v_121 = (pub_r000227_10 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000227_10 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000227_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000227_6 & 2) != 0) {
            stage_v_122 = (pub_r000227_17 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000227_17 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000227_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_123 = (pub_r000227_1 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000227_1 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000227_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000227_10 & 1) != 0) {
        if ((sec_r000227_3 & 2) != 0) {
            stage_v_124 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_125 = (pub_r000227_3 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000227_3 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000227_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000227_5 & 2) != 0) {
            stage_v_126 = (pub_r000227_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000227_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000227_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000227_17 & 2) != 0) {
            stage_v_127 = (pub_r000227_7 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000227_7 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000227_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000227_12 & 2) != 0) {
            stage_v_128 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000227_15 & 2) != 0) {
            stage_v_129 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000227_1 & 2) != 0) {
            stage_v_130 = (pub_r000227_4 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000227_4 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000227_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000227_19 & 2) != 0) {
            stage_v_131 = (pub_r000227_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000227_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000227_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000227_8 & 1) != 0) {
        if ((sec_r000227_13 & 2) != 0) {
            stage_v_132 = (pub_r000227_21 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000227_21 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000227_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000227_16 & 2) != 0) {
            stage_v_133 = (pub_r000227_11 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000227_11 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000227_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000227_10 & 1) != 0) {
        if ((sec_r000227_0 & 2) != 0) {
            stage_v_134 = (pub_r000227_12 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000227_12 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000227_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
