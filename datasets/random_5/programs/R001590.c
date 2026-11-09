/*
 * Benchmark Program: R001590
 * Security Family: mixed_control_data
 * Generator Seed: 659013
 * High Inputs: 21 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001590_9013_0 {
    int trace;
    int dim;
    int determinant;
    short stride;
    int density;
    short scale;
    int buffer[3];
};

struct CipherContext_R001590_9013_1 {
    int flags;
    unsigned char counter;
    short round_key;
    int buffer[3];
};

struct AudioFrame_R001590_9013_2 {
    int sample_rate;
    int envelope;
    unsigned char rms;
    int buffer[3];
};

struct Vector3D_R001590_9013_3 {
    int norm_sq;
    short pitch;
    unsigned char heading;
    unsigned char coord_x;
    unsigned char coord_y;
    int coord_z;
    int buffer[3];
};

union ColorPixel_R001590_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001590_9013_0(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int index_reg_37 = local_arr[aux % 3];
    acc = (acc + index_reg_37 * 2) & 127;
    int threshold_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_53) & 63;
    acc ^= aux;
    int window_43 = (st.buffer[0] * 3 + aux) & 63;
    if (window_43 > 39) {
        acc = (acc + window_43 * 2 + 5) & 127;
        aux ^= (window_43 & 15);
    } else {
        acc = (acc - window_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_78 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_78 > 35) {
        acc = (acc + cursor_78 * 2 + 5) & 127;
        aux ^= (cursor_78 & 15);
    } else {
        acc = (acc - cursor_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_38 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_38 = (anchor_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_38) & 127;
    }
    int metric_79 = (aux + st.buffer[1]) & 3;
    switch (metric_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int offset_13 = local_arr[aux % 3];
    acc = (acc + offset_13 * 2) & 127;
    int window_68 = (aux + st.buffer[1]) & 3;
    switch (window_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001590_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int cursor_87 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_87 = (cursor_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_87) & 127;
    }
    int accumulator_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001590_9013_4(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int quantum_66 = local_arr[aux % 3];
    acc = (acc + quantum_66 * 2) & 127;
    int scale_14 = 0;
    for (int k = 0; k < 2; k++) {
        scale_14 = (scale_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001590_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int residue_60 = local_arr[aux % 3];
    acc = (acc + residue_60 * 2) & 127;
    int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_52) & 63;
    acc ^= aux;
    int stride_85 = 0;
    for (int k = 0; k < 2; k++) {
        stride_85 = (stride_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_6(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001590_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_32 = local_arr[aux % 3];
    acc = (acc + phase_32 * 2) & 127;
    int bound_19 = 0;
    for (int k = 0; k < 2; k++) {
        bound_19 = (bound_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_19) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_7(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int scale_94 = (aux + st.buffer[1]) & 3;
    switch (scale_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_40 = local_arr[aux % 3];
    acc = (acc + quotient_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001590_9013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int stride_28 = local_arr[aux % 3];
    acc = (acc + stride_28 * 2) & 127;
    int vector_41 = 0;
    for (int k = 0; k < 2; k++) {
        vector_41 = (vector_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_41) & 127;
    }
    int metric_77 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_77 > 15) {
        acc = (acc + metric_77 * 2 + 5) & 127;
        aux ^= (metric_77 & 15);
    } else {
        acc = (acc - metric_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001590_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_84) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_39 = local_arr[aux % 3];
    acc = (acc + margin_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001590_9013_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001590_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_16 = (aux + st.buffer[1]) & 3;
    switch (quantum_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001590_9013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_34 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_34 > 13) {
        acc = (acc + accumulator_34 * 2 + 5) & 127;
        aux ^= (accumulator_34 & 15);
    } else {
        acc = (acc - accumulator_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_15 = local_arr[aux % 3];
    acc = (acc + weight_15 * 2) & 127;
    int weight_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001590_9013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_41 = 0;
    for (int k = 0; k < 2; k++) {
        phase_41 = (phase_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_41) & 127;
    }
    int stride_23 = (aux + st.buffer[1]) & 3;
    switch (stride_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_60 = local_arr[aux % 3];
    acc = (acc + mask_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001590_9013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_70) & 63;
    acc ^= aux;
    int parity_62 = (aux + st.buffer[1]) & 3;
    switch (parity_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_72 = 0;
    for (int k = 0; k < 2; k++) {
        scale_72 = (scale_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_32 = (aux + st.buffer[1]) & 3;
    switch (factor_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001590_9013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_34 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_34 > 18) {
        acc = (acc + index_reg_34 * 2 + 5) & 127;
        aux ^= (index_reg_34 & 15);
    } else {
        acc = (acc - index_reg_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_76 = 0;
    for (int k = 0; k < 2; k++) {
        mask_76 = (mask_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_16(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001590_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_38) & 63;
    acc ^= aux;
    int tracker_37 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_37 > 41) {
        acc = (acc + tracker_37 * 2 + 5) & 127;
        aux ^= (tracker_37 & 15);
    } else {
        acc = (acc - tracker_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_13 = local_arr[aux % 3];
    acc = (acc + anchor_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001590_9013_17(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001590_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_50 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_50 = (anchor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_50) & 127;
    }
    int accumulator_46 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_46 > 45) {
        acc = (acc + accumulator_46 * 2 + 5) & 127;
        aux ^= (accumulator_46 & 15);
    } else {
        acc = (acc - accumulator_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001590_9013_18(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001590_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int parity_76 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_76 > 20) {
        acc = (acc + parity_76 * 2 + 5) & 127;
        aux ^= (parity_76 & 15);
    } else {
        acc = (acc - parity_76 + 11) & 127;
        aux += 3;
    }
    int quotient_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001590_0;
    int sec_r001590_1;
    int sec_r001590_2;
    int sec_r001590_3;
    int sec_r001590_4;
    int sec_r001590_5;
    int sec_r001590_6;
    int sec_r001590_7;
    int sec_r001590_8;
    int sec_r001590_9;
    int sec_r001590_10;
    int sec_r001590_11;
    int sec_r001590_12;
    int sec_r001590_13;
    int sec_r001590_14;
    int sec_r001590_15;
    int sec_r001590_16;
    int sec_r001590_17;
    int sec_r001590_18;
    int sec_r001590_19;
    int sec_r001590_20;
    int pub_r001590_0;
    int pub_r001590_1;
    int pub_r001590_2;
    int pub_r001590_3;
    int pub_r001590_4;
    int pub_r001590_5;
    int pub_r001590_6;
    int pub_r001590_7;
    int pub_r001590_8;
    int pub_r001590_9;
    int pub_r001590_10;
    int pub_r001590_11;
    int pub_r001590_12;
    int pub_r001590_13;
    int pub_r001590_14;
    int pub_r001590_15;
    int pub_r001590_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001590_0 >= -100 && pub_r001590_0 <= 100);
    __CPROVER_assume(pub_r001590_1 >= -100 && pub_r001590_1 <= 100);
    __CPROVER_assume(pub_r001590_2 >= -100 && pub_r001590_2 <= 100);
    __CPROVER_assume(pub_r001590_3 >= -100 && pub_r001590_3 <= 100);
    __CPROVER_assume(pub_r001590_4 >= -100 && pub_r001590_4 <= 100);
    __CPROVER_assume(pub_r001590_5 >= -100 && pub_r001590_5 <= 100);
    __CPROVER_assume(pub_r001590_6 >= -100 && pub_r001590_6 <= 100);
    __CPROVER_assume(pub_r001590_7 >= -100 && pub_r001590_7 <= 100);
    __CPROVER_assume(pub_r001590_8 >= -100 && pub_r001590_8 <= 100);
    __CPROVER_assume(pub_r001590_9 >= -100 && pub_r001590_9 <= 100);
    __CPROVER_assume(pub_r001590_10 >= -100 && pub_r001590_10 <= 100);
    __CPROVER_assume(pub_r001590_11 >= -100 && pub_r001590_11 <= 100);
    __CPROVER_assume(pub_r001590_12 >= -100 && pub_r001590_12 <= 100);
    __CPROVER_assume(pub_r001590_13 >= -100 && pub_r001590_13 <= 100);
    __CPROVER_assume(pub_r001590_14 >= -100 && pub_r001590_14 <= 100);
    __CPROVER_assume(pub_r001590_15 >= -100 && pub_r001590_15 <= 100);
    __CPROVER_assume(pub_r001590_16 >= -100 && pub_r001590_16 <= 100);
    __CPROVER_assume(sec_r001590_0 >= 0 && sec_r001590_0 <= 255);
    __CPROVER_assume(sec_r001590_1 >= 0 && sec_r001590_1 <= 255);
    __CPROVER_assume(sec_r001590_2 >= 0 && sec_r001590_2 <= 255);
    __CPROVER_assume(sec_r001590_3 >= 0 && sec_r001590_3 <= 255);
    __CPROVER_assume(sec_r001590_4 >= 0 && sec_r001590_4 <= 255);
    __CPROVER_assume(sec_r001590_5 >= 0 && sec_r001590_5 <= 255);
    __CPROVER_assume(sec_r001590_6 >= 0 && sec_r001590_6 <= 255);
    __CPROVER_assume(sec_r001590_7 >= 0 && sec_r001590_7 <= 255);
    __CPROVER_assume(sec_r001590_8 >= 0 && sec_r001590_8 <= 255);
    __CPROVER_assume(sec_r001590_9 >= 0 && sec_r001590_9 <= 255);
    __CPROVER_assume(sec_r001590_10 >= 0 && sec_r001590_10 <= 255);
    __CPROVER_assume(sec_r001590_11 >= 0 && sec_r001590_11 <= 255);
    __CPROVER_assume(sec_r001590_12 >= 0 && sec_r001590_12 <= 255);
    __CPROVER_assume(sec_r001590_13 >= 0 && sec_r001590_13 <= 255);
    __CPROVER_assume(sec_r001590_14 >= 0 && sec_r001590_14 <= 255);
    __CPROVER_assume(sec_r001590_15 >= 0 && sec_r001590_15 <= 255);
    __CPROVER_assume(sec_r001590_16 >= 0 && sec_r001590_16 <= 255);
    __CPROVER_assume(sec_r001590_17 >= 0 && sec_r001590_17 <= 255);
    __CPROVER_assume(sec_r001590_18 >= 0 && sec_r001590_18 <= 255);
    __CPROVER_assume(sec_r001590_19 >= 0 && sec_r001590_19 <= 255);
    __CPROVER_assume(sec_r001590_20 >= 0 && sec_r001590_20 <= 255);

    struct MatrixBlock_R001590_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001590_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001590_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001590_0 + 7) & 15;
    struct CipherContext_R001590_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001590_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001590_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001590_0 + 9) & 15;
    struct AudioFrame_R001590_9013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001590_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001590_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001590_0 + 11) & 15;
    struct Vector3D_R001590_9013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001590_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001590_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001590_0 + 13) & 15;

    union ColorPixel_R001590_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001590_9013_0(sec_r001590_0, sec_r001590_1);
    int helper_flow_1 = fn_R001590_9013_1(sec_r001590_1, pub_r001590_2, pub_r001590_3, pub_r001590_4, pub_r001590_5);
    int helper_flow_2 = fn_R001590_9013_2(sec_r001590_2, pub_r001590_3, pub_r001590_4, pub_r001590_5, pub_r001590_6);
    int helper_flow_3 = fn_R001590_9013_3(sec_r001590_3, pub_r001590_4, pub_r001590_5, pub_r001590_6, pub_r001590_7);
    int helper_flow_4 = fn_R001590_9013_4(sec_r001590_4, pub_r001590_5);
    int helper_flow_5 = fn_R001590_9013_5(sec_r001590_5, pub_r001590_6, pub_r001590_7, pub_r001590_8, pub_r001590_9);
    int helper_flow_6 = fn_R001590_9013_6(sec_r001590_6, sec_r001590_7);
    int helper_flow_7 = fn_R001590_9013_7(sec_r001590_7, pub_r001590_8, pub_r001590_9);
    int helper_flow_8 = fn_R001590_9013_8(sec_r001590_8, sec_r001590_9, pub_r001590_10, pub_r001590_11);
    int helper_flow_9 = fn_R001590_9013_9(sec_r001590_9, pub_r001590_10, pub_r001590_11, pub_r001590_12);
    int helper_flow_10 = fn_R001590_9013_10(sec_r001590_10, pub_r001590_11, pub_r001590_12, pub_r001590_13);
    int helper_flow_11 = fn_R001590_9013_11(sec_r001590_11, pub_r001590_12, pub_r001590_13, pub_r001590_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_0 > 39) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_1 > 44) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001590_10 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_2 > 44) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_3 > 23) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001590_5 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_4 > 38) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001590_12 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_5 > 32) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_6 > 36) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_7 > 28) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001590_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001590_17 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001590_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001590_10 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_11 > 31) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_12 > 46) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001590_0 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001590_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_15 > 28) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001590_15 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_17 > 23) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_18 > 42) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_19 > 38) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_20 > 49) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_21 > 29) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001590_9 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_22 > 28) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_23 > 29) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_24 > 42) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_25 > 47) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_26 > 44) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001590_6 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_27 > 40) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_28 > 41) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_29 > 31) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_30 > 50) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_31 > 42) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_32 > 34) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001590_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_34 > 48) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001590_10 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_35 > 39) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_36 > 45) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_37 > 24) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001590_3 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_38 > 39) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_39 > 23) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_40 > 40) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001590_6 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_41 > 39) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001590_5 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_42 > 39) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_43 > 35) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_44 > 41) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_45 > 46) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_46 > 30) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_47 > 25) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001590_16 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_48 > 40) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_49 > 50) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_50 > 34) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001590_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001590_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001590_11 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_53 > 37) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001590_15 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_54 > 37) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001590_10 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_55 > 45) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_56 > 39) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001590_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001590_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001590_19 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_59 > 43) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_60 > 21) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_61 > 29) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_62 > 45) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001590_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_64 > 47) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_65 > 21) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001590_3 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_66 > 33) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_67 > 50) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_68 > 35) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_69 > 31) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_70 > 26) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_71 > 32) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_72 > 22) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_73 > 29) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001590_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001590_9 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_77 > 38) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001590_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_79 > 38) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001590_14 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_80 > 40) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_81 > 20) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001590_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_83 > 46) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_84 > 43) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_85 > 28) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001590_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001590_10 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_87 > 32) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_88 > 47) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001590_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001590_15 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_90 > 28) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_91 > 45) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_92 > 45) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_93 > 45) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_94 > 47) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_95 > 45) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_96 > 35) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_97 > 47) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_98 > 40) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_99 > 34) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_100 > 32) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_101 > 42) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001590_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_103 > 20) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001590_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_105 > 50) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001590_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_107 > 37) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001590_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_109 > 47) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_110 > 29) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_111 > 43) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001590_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_113 > 35) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_114 > 32) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_115 > 28) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_116 > 50) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001590_15 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_117 > 20) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_118 > 40) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_120 > 29) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_121 > 28) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_122 > 48) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001590_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_124 > 23) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001590_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001590_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_127 > 36) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001590_7 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_128 > 32) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_129 > 41) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_130 > 44) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_131 > 30) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001590_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001590_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_134 > 31) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_135 > 49) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_136 > 42) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001590_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_138 > 33) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001590_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_140 > 33) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_141 > 20) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001590_5 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_142 > 37) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001590_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001590_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_146 > 23) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_147 > 50) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_148 > 43) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001590_5 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_149 > 47) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001590_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001590_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001590_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_153 > 39) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_154 > 20) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001590_14 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_155 > 42) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_156 > 27) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001590_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001590_6 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_158 > 27) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_159 > 41) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_160 > 47) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_161 > 28) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001590_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001590_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_164 > 22) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_165 > 30) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_166 > 28) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001590_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_168 > 31) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_169 > 30) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_170 > 41) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_171 > 22) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001590_11) & 127;
    if (stage_v_172 > 44) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_173 > 42) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_174 > 39) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001590_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_176 > 36) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_177 > 33) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001590_5 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_179 > 21) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_180 > 40) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_182 > 28) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_183 > 29) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_184 > 49) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001590_3) & 127;
    if (stage_v_185 > 26) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_186 > 34) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_184 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_187 > 32) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_188 > 25) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_189 > 47) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001590_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_191 > 47) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001590_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001590_1 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_193 > 42) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001590_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001590_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_196 > 39) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_197 > 31) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_198 > 46) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001590_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_200 > 32) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_201 > 29) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_202 > 49) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_203 > 40) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001590_13) & 127;
    if (stage_v_204 > 48) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001590_4) & 127;
    if (stage_v_205 > 23) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001590_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_207 > 37) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_208 > 26) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_209 > 35) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001590_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_211 > 36) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001590_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_213 > 21) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001590_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_215 > 44) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001590_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_217 > 30) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001590_2 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_218 > 23) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001590_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_220 > 26) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001590_6) & 127;
    if (stage_v_221 > 32) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_222 > 36) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001590_2) & 127;
    if (stage_v_223 > 27) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001590_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_166 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_225 > 39) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001590_6 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_226 > 44) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001590_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001590_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001590_7) & 127;
    if (stage_v_229 > 44) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_171 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_230 > 26) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001590_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001590_0) & 127;
    if (stage_v_232 > 40) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_233 > 35) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_234 > 43) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001590_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_205 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_236 > 21) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001590_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_238 > 43) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001590_1) & 127;
    if (stage_v_239 > 27) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001590_5) & 127;
    if (stage_v_240 > 40) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_241 > 34) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001590_15) & 127;
    if (stage_v_242 > 35) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001590_12) & 127;
    if (stage_v_243 > 48) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001590_8) & 127;
    if (stage_v_244 > 42) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_244 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_245 > 25) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001590_14) & 127;
    if (stage_v_246 > 29) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_247 > 33) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001590_16) & 127;
    if (stage_v_248 > 30) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001590_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_202 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_250 > 41) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r001590_4 ^ 0x2A) * 2 + pub_r001590_10) & 127;
    if (stage_v_251 > 29) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001590_9) & 127;
    if (stage_v_252 > 41) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
