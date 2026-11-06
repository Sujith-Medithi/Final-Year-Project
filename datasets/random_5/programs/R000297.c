/*
 * Benchmark Program: R000297
 * Security Family: nested_implicit_flow
 * Generator Seed: 529713
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000297_9713_0 {
    int timestamp;
    unsigned char facility;
    short signature;
    int buffer[3];
};

struct Transaction_R000297_9713_1 {
    unsigned char fee;
    unsigned char auth_code;
    unsigned char account_id;
    int rate;
    unsigned char status;
    unsigned char balance;
    int buffer[3];
};

struct Vector3D_R000297_9713_2 {
    int heading;
    unsigned char coord_y;
    short pitch;
    unsigned char coord_z;
    short norm_sq;
    int coord_x;
    int buffer[3];
};

struct MatrixBlock_R000297_9713_3 {
    short trace;
    short scale;
    int stride;
    short determinant;
    int dim;
    short density;
    int buffer[3];
};

union PacketPayload_R000297_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000297_9713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000297_9713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_16 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_16 > 15) {
        acc = (acc + residue_16 * 2 + 5) & 127;
        aux ^= (residue_16 & 15);
    } else {
        acc = (acc - residue_16 + 11) & 127;
        aux += 3;
    }
    int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_31 = local_arr[aux % 3];
    acc = (acc + sample_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_75) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_65 = local_arr[aux % 3];
    acc = (acc + quantum_65 * 2) & 127;
    int phase_50 = (aux + st.buffer[1]) & 3;
    switch (phase_50) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_2(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000297_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_41 = local_arr[aux % 3];
    acc = (acc + threshold_41 * 2) & 127;
    int phase_72 = (aux + st.buffer[1]) & 3;
    switch (phase_72) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000297_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000297_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int stride_36 = local_arr[aux % 3];
    acc = (acc + stride_36 * 2) & 127;
    int scale_92 = (aux + st.buffer[1]) & 3;
    switch (scale_92) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_23 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_23 > 21) {
        acc = (acc + residue_23 * 2 + 5) & 127;
        aux ^= (residue_23 & 15);
    } else {
        acc = (acc - residue_23 + 11) & 127;
        aux += 3;
    }
    int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000297_9713_4(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_15) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_51 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_51 > 12) {
        acc = (acc + margin_51 * 2 + 5) & 127;
        aux ^= (margin_51 & 15);
    } else {
        acc = (acc - margin_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int threshold_89 = local_arr[aux % 3];
    acc = (acc + threshold_89 * 2) & 127;
    int segment_99 = (aux + st.buffer[1]) & 3;
    switch (segment_99) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_66 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_66 > 49) {
        acc = (acc + weight_66 * 2 + 5) & 127;
        aux ^= (weight_66 & 15);
    } else {
        acc = (acc - weight_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int offset_71 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_71 > 18) {
        acc = (acc + offset_71 * 2 + 5) & 127;
        aux ^= (offset_71 & 15);
    } else {
        acc = (acc - offset_71 + 11) & 127;
        aux += 3;
    }
    int scale_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_89) & 63;
    acc ^= aux;
    int index_reg_42 = (aux + st.buffer[1]) & 3;
    switch (index_reg_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_7(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000297_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_23 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_23 > 50) {
        acc = (acc + anchor_23 * 2 + 5) & 127;
        aux ^= (anchor_23 & 15);
    } else {
        acc = (acc - anchor_23 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_12 = local_arr[aux % 3];
    acc = (acc + segment_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000297_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_41) & 63;
    acc ^= aux;
    int metric_83 = (aux + st.buffer[1]) & 3;
    switch (metric_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_21 = local_arr[aux % 3];
    acc = (acc + damping_21 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000297_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_66 = local_arr[aux % 3];
    acc = (acc + mask_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000297_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int margin_65 = local_arr[aux % 3];
    acc = (acc + margin_65 * 2) & 127;
    int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_16) & 63;
    acc ^= aux;
    int bound_54 = (aux + st.buffer[1]) & 3;
    switch (bound_54) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000297_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_91 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_91 > 19) {
        acc = (acc + sample_91 * 2 + 5) & 127;
        aux ^= (sample_91 & 15);
    } else {
        acc = (acc - sample_91 + 11) & 127;
        aux += 3;
    }
    int threshold_16 = (aux + st.buffer[1]) & 3;
    switch (threshold_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000297_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_43 = local_arr[aux % 3];
    acc = (acc + vector_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000297_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_48 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_48 > 24) {
        acc = (acc + pivot_48 * 2 + 5) & 127;
        aux ^= (pivot_48 & 15);
    } else {
        acc = (acc - pivot_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000297_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_91 = (aux + st.buffer[1]) & 3;
    switch (margin_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_59 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_59 > 36) {
        acc = (acc + phase_59 * 2 + 5) & 127;
        aux ^= (phase_59 & 15);
    } else {
        acc = (acc - phase_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000297_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int accumulator_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_63) & 63;
    acc ^= aux;
    int mask_58 = (aux + st.buffer[1]) & 3;
    switch (mask_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000297_9713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000297_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int factor_83 = (aux + st.buffer[1]) & 3;
    switch (factor_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000297_9713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000297_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int accumulator_84 = local_arr[aux % 3];
    acc = (acc + accumulator_84 * 2) & 127;
    int index_reg_16 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_16 > 30) {
        acc = (acc + index_reg_16 * 2 + 5) & 127;
        aux ^= (index_reg_16 & 15);
    } else {
        acc = (acc - index_reg_16 + 11) & 127;
        aux += 3;
    }
    int stride_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000297_0;
    int sec_r000297_1;
    int sec_r000297_2;
    int sec_r000297_3;
    int sec_r000297_4;
    int sec_r000297_5;
    int sec_r000297_6;
    int sec_r000297_7;
    int sec_r000297_8;
    int sec_r000297_9;
    int sec_r000297_10;
    int sec_r000297_11;
    int sec_r000297_12;
    int sec_r000297_13;
    int sec_r000297_14;
    int sec_r000297_15;
    int sec_r000297_16;
    int sec_r000297_17;
    int sec_r000297_18;
    int pub_r000297_0;
    int pub_r000297_1;
    int pub_r000297_2;
    int pub_r000297_3;
    int pub_r000297_4;
    int pub_r000297_5;
    int pub_r000297_6;
    int pub_r000297_7;
    int pub_r000297_8;
    int pub_r000297_9;
    int pub_r000297_10;
    int pub_r000297_11;
    int pub_r000297_12;
    int pub_r000297_13;
    int pub_r000297_14;
    int pub_r000297_15;
    int pub_r000297_16;
    int pub_r000297_17;
    int pub_r000297_18;
    int pub_r000297_19;
    int pub_r000297_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000297_0 >= -100 && pub_r000297_0 <= 100);
    __CPROVER_assume(pub_r000297_1 >= -100 && pub_r000297_1 <= 100);
    __CPROVER_assume(pub_r000297_2 >= -100 && pub_r000297_2 <= 100);
    __CPROVER_assume(pub_r000297_3 >= -100 && pub_r000297_3 <= 100);
    __CPROVER_assume(pub_r000297_4 >= -100 && pub_r000297_4 <= 100);
    __CPROVER_assume(pub_r000297_5 >= -100 && pub_r000297_5 <= 100);
    __CPROVER_assume(pub_r000297_6 >= -100 && pub_r000297_6 <= 100);
    __CPROVER_assume(pub_r000297_7 >= -100 && pub_r000297_7 <= 100);
    __CPROVER_assume(pub_r000297_8 >= -100 && pub_r000297_8 <= 100);
    __CPROVER_assume(pub_r000297_9 >= -100 && pub_r000297_9 <= 100);
    __CPROVER_assume(pub_r000297_10 >= -100 && pub_r000297_10 <= 100);
    __CPROVER_assume(pub_r000297_11 >= -100 && pub_r000297_11 <= 100);
    __CPROVER_assume(pub_r000297_12 >= -100 && pub_r000297_12 <= 100);
    __CPROVER_assume(pub_r000297_13 >= -100 && pub_r000297_13 <= 100);
    __CPROVER_assume(pub_r000297_14 >= -100 && pub_r000297_14 <= 100);
    __CPROVER_assume(pub_r000297_15 >= -100 && pub_r000297_15 <= 100);
    __CPROVER_assume(pub_r000297_16 >= -100 && pub_r000297_16 <= 100);
    __CPROVER_assume(pub_r000297_17 >= -100 && pub_r000297_17 <= 100);
    __CPROVER_assume(pub_r000297_18 >= -100 && pub_r000297_18 <= 100);
    __CPROVER_assume(pub_r000297_19 >= -100 && pub_r000297_19 <= 100);
    __CPROVER_assume(pub_r000297_20 >= -100 && pub_r000297_20 <= 100);
    __CPROVER_assume(sec_r000297_0 >= 0 && sec_r000297_0 <= 255);
    __CPROVER_assume(sec_r000297_1 >= 0 && sec_r000297_1 <= 255);
    __CPROVER_assume(sec_r000297_2 >= 0 && sec_r000297_2 <= 255);
    __CPROVER_assume(sec_r000297_3 >= 0 && sec_r000297_3 <= 255);
    __CPROVER_assume(sec_r000297_4 >= 0 && sec_r000297_4 <= 255);
    __CPROVER_assume(sec_r000297_5 >= 0 && sec_r000297_5 <= 255);
    __CPROVER_assume(sec_r000297_6 >= 0 && sec_r000297_6 <= 255);
    __CPROVER_assume(sec_r000297_7 >= 0 && sec_r000297_7 <= 255);
    __CPROVER_assume(sec_r000297_8 >= 0 && sec_r000297_8 <= 255);
    __CPROVER_assume(sec_r000297_9 >= 0 && sec_r000297_9 <= 255);
    __CPROVER_assume(sec_r000297_10 >= 0 && sec_r000297_10 <= 255);
    __CPROVER_assume(sec_r000297_11 >= 0 && sec_r000297_11 <= 255);
    __CPROVER_assume(sec_r000297_12 >= 0 && sec_r000297_12 <= 255);
    __CPROVER_assume(sec_r000297_13 >= 0 && sec_r000297_13 <= 255);
    __CPROVER_assume(sec_r000297_14 >= 0 && sec_r000297_14 <= 255);
    __CPROVER_assume(sec_r000297_15 >= 0 && sec_r000297_15 <= 255);
    __CPROVER_assume(sec_r000297_16 >= 0 && sec_r000297_16 <= 255);
    __CPROVER_assume(sec_r000297_17 >= 0 && sec_r000297_17 <= 255);
    __CPROVER_assume(sec_r000297_18 >= 0 && sec_r000297_18 <= 255);

    struct EventLog_R000297_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000297_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000297_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000297_0 + 7) & 15;
    struct Transaction_R000297_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000297_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000297_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000297_0 + 9) & 15;
    struct Vector3D_R000297_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000297_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000297_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000297_0 + 11) & 15;
    struct MatrixBlock_R000297_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000297_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000297_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000297_0 + 13) & 15;

    union PacketPayload_R000297_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 30) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 45) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 17) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 32) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 15) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 30) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 33) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 48) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 40) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 55) {
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
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 13) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 28) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 31) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 46) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 45) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 19) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 34) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 38) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 53) {
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
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 28) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 43) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 16) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 31) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 37) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 52) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000297_4 & 1) != 0) {
        if ((sec_r000297_7 & 2) != 0) {
            stage_v_72 = (pub_r000297_13 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000297_13 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000297_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_73 = (pub_r000297_7 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000297_7 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000297_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000297_18 & 2) != 0) {
            stage_v_74 = (pub_r000297_20 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000297_20 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000297_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000297_7 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_75 = (pub_r000297_1 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000297_1 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000297_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_76 = (pub_r000297_10 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000297_10 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000297_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_77 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_78 = (pub_r000297_7 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000297_7 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000297_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000297_5 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_79 = (pub_r000297_13 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000297_13 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000297_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000297_6 & 2) != 0) {
            stage_v_80 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000297_7 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_81 = (pub_r000297_19 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000297_19 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000297_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_82 = (pub_r000297_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000297_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000297_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000297_9 & 2) != 0) {
            stage_v_83 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_84 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_85 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000297_11 & 1) != 0) {
        if ((sec_r000297_7 & 2) != 0) {
            stage_v_86 = (pub_r000297_19 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000297_19 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000297_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000297_9 & 2) != 0) {
            stage_v_87 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_88 = (pub_r000297_13 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000297_13 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000297_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000297_18 & 2) != 0) {
            stage_v_89 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000297_13 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_90 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000297_6 & 1) != 0) {
        if ((sec_r000297_3 & 2) != 0) {
            stage_v_91 = (pub_r000297_18 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000297_18 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000297_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_92 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_93 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000297_15 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_94 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000297_18 & 2) != 0) {
            stage_v_95 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_96 = (pub_r000297_19 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000297_19 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000297_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000297_12 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_97 = (pub_r000297_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000297_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000297_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000297_9 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_98 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000297_9 & 2) != 0) {
            stage_v_99 = (pub_r000297_2 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000297_2 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000297_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_100 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000297_8 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_101 = (pub_r000297_20 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000297_20 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000297_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000297_1 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_102 = (pub_r000297_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000297_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000297_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000297_2 & 1) != 0) {
        if ((sec_r000297_18 & 2) != 0) {
            stage_v_103 = (pub_r000297_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000297_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000297_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_104 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_105 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_106 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000297_15 & 2) != 0) {
            stage_v_107 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_108 = (pub_r000297_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000297_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000297_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_109 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000297_1 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_110 = (pub_r000297_15 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000297_15 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000297_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_111 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000297_7 & 2) != 0) {
            stage_v_112 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000297_0 & 1) != 0) {
        if ((sec_r000297_7 & 2) != 0) {
            stage_v_113 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_114 = (pub_r000297_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000297_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000297_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000297_17 & 1) != 0) {
        if ((sec_r000297_3 & 2) != 0) {
            stage_v_115 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_116 = (pub_r000297_10 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000297_10 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000297_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_117 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000297_18 & 2) != 0) {
            stage_v_118 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_119 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_120 = (pub_r000297_13 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000297_13 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000297_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_121 = (pub_r000297_19 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000297_19 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000297_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_122 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_123 = (pub_r000297_8 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000297_8 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000297_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_124 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000297_2 & 2) != 0) {
            stage_v_125 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000297_5 & 2) != 0) {
            stage_v_126 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000297_11 & 2) != 0) {
            stage_v_127 = (pub_r000297_1 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000297_1 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000297_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_128 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_129 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_130 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000297_3 & 2) != 0) {
            stage_v_131 = (pub_r000297_15 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000297_15 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000297_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_132 = (pub_r000297_8 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000297_8 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000297_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000297_1 & 2) != 0) {
            stage_v_133 = (pub_r000297_2 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000297_2 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000297_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000297_5 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_134 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_135 = (pub_r000297_0 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000297_0 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000297_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000297_15 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_136 = (pub_r000297_8 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000297_8 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000297_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_137 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000297_14 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_138 = (pub_r000297_20 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000297_20 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000297_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000297_6 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_139 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000297_3 & 2) != 0) {
            stage_v_140 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000297_3 & 2) != 0) {
            stage_v_141 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000297_4 & 1) != 0) {
        if ((sec_r000297_13 & 2) != 0) {
            stage_v_142 = (pub_r000297_7 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000297_7 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000297_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000297_13 & 2) != 0) {
            stage_v_143 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000297_15 & 2) != 0) {
            stage_v_144 = (pub_r000297_5 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000297_5 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000297_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_145 = (pub_r000297_16 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000297_16 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000297_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_146 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000297_1 & 2) != 0) {
            stage_v_147 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000297_12 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_148 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_149 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000297_6 & 2) != 0) {
            stage_v_150 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000297_3 & 1) != 0) {
        if ((sec_r000297_5 & 2) != 0) {
            stage_v_151 = (pub_r000297_15 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000297_15 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000297_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000297_6 & 2) != 0) {
            stage_v_152 = (pub_r000297_11 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000297_11 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000297_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000297_11 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_153 = (pub_r000297_3 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000297_3 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000297_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000297_7 & 2) != 0) {
            stage_v_154 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000297_15 & 2) != 0) {
            stage_v_155 = (pub_r000297_1 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000297_1 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000297_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000297_14 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_156 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000297_8 & 1) != 0) {
        if ((sec_r000297_1 & 2) != 0) {
            stage_v_157 = (pub_r000297_2 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000297_2 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000297_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000297_1 & 2) != 0) {
            stage_v_158 = (pub_r000297_1 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000297_1 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000297_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000297_17 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_159 = (pub_r000297_17 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000297_17 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000297_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000297_13 & 1) != 0) {
        if ((sec_r000297_2 & 2) != 0) {
            stage_v_160 = (pub_r000297_10 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000297_10 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000297_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r000297_15 & 2) != 0) {
            stage_v_161 = (pub_r000297_14 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000297_14 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000297_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_162 = (pub_r000297_20 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000297_20 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000297_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000297_4 & 1) != 0) {
        if ((sec_r000297_4 & 2) != 0) {
            stage_v_163 = (pub_r000297_20 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000297_20 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000297_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000297_1 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_164 = (pub_r000297_15 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000297_15 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000297_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000297_1 & 1) != 0) {
        if ((sec_r000297_12 & 2) != 0) {
            stage_v_165 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000297_16 & 2) != 0) {
            stage_v_166 = (pub_r000297_10 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000297_10 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000297_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000297_0 & 2) != 0) {
            stage_v_167 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((sec_r000297_8 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_168 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_156 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_169 = (pub_r000297_7 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000297_7 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000297_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000297_17 & 2) != 0) {
            stage_v_170 = (pub_r000297_13 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000297_13 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000297_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r000297_8 & 2) != 0) {
            stage_v_171 = (pub_r000297_9 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000297_9 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000297_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000297_10 & 2) != 0) {
            stage_v_172 = (pub_r000297_12 + 31) & 127;
        } else {
            stage_v_172 = (pub_r000297_12 + 13) & 127;
        }
    } else {
        stage_v_172 = (pub_r000297_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000297_15 & 2) != 0) {
            stage_v_173 = (pub_r000297_6 + 31) & 127;
        } else {
            stage_v_173 = (pub_r000297_6 + 13) & 127;
        }
    } else {
        stage_v_173 = (pub_r000297_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r000297_14 & 2) != 0) {
            stage_v_174 = (pub_r000297_4 + 31) & 127;
        } else {
            stage_v_174 = (pub_r000297_4 + 13) & 127;
        }
    } else {
        stage_v_174 = (pub_r000297_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
