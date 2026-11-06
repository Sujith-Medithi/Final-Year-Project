/*
 * Benchmark Program: R000783
 * Security Family: multi_step_explicit
 * Generator Seed: 578313
 * High Inputs: 17 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000783_8313_0 {
    int tag;
    int iv;
    short flags;
    unsigned char counter;
    short nonce;
    int buffer[3];
};

struct Transaction_R000783_8313_1 {
    int auth_code;
    int rate;
    int status;
    short fee;
    int buffer[3];
};

struct MatrixBlock_R000783_8313_2 {
    unsigned char determinant;
    int scale;
    unsigned char trace;
    short density;
    short dim;
    int stride;
    int buffer[3];
};

struct Vector3D_R000783_8313_3 {
    int coord_z;
    int pitch;
    int coord_x;
    int heading;
    unsigned char coord_y;
    int buffer[3];
};

union RegisterBank_R000783_8313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000783_8313_0(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000783_8313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000783_8313_1(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int margin_32 = local_arr[aux % 3];
    acc = (acc + margin_32 * 2) & 127;
    int pivot_97 = (aux + st.buffer[1]) & 3;
    switch (pivot_97) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_39 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_39 > 22) {
        acc = (acc + coefficient_39 * 2 + 5) & 127;
        aux ^= (coefficient_39 & 15);
    } else {
        acc = (acc - coefficient_39 + 11) & 127;
        aux += 3;
    }
    int tracker_16 = (aux + st.buffer[1]) & 3;
    switch (tracker_16) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_3(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int margin_38 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_38 > 29) {
        acc = (acc + margin_38 * 2 + 5) & 127;
        aux ^= (margin_38 & 15);
    } else {
        acc = (acc - margin_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_54 = local_arr[aux % 3];
    acc = (acc + tracker_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000783_8313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_36 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_36 > 25) {
        acc = (acc + residue_36 * 2 + 5) & 127;
        aux ^= (residue_36 & 15);
    } else {
        acc = (acc - residue_36 + 11) & 127;
        aux += 3;
    }
    int mask_95 = (aux + st.buffer[1]) & 3;
    switch (mask_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_70 = local_arr[aux % 3];
    acc = (acc + margin_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000783_8313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_78 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_78 > 47) {
        acc = (acc + vector_78 * 2 + 5) & 127;
        aux ^= (vector_78 & 15);
    } else {
        acc = (acc - vector_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_6(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000783_8313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int phase_41 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_41 > 21) {
        acc = (acc + phase_41 * 2 + 5) & 127;
        aux ^= (phase_41 & 15);
    } else {
        acc = (acc - phase_41 + 11) & 127;
        aux += 3;
    }
    int offset_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_89) & 63;
    acc ^= aux;
    int threshold_46 = (aux + st.buffer[1]) & 3;
    switch (threshold_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_7(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000783_8313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_87 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_87 > 37) {
        acc = (acc + parity_87 * 2 + 5) & 127;
        aux ^= (parity_87 & 15);
    } else {
        acc = (acc - parity_87 + 11) & 127;
        aux += 3;
    }
    int window_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_82) & 63;
    acc ^= aux;
    int vector_97 = (aux + st.buffer[1]) & 3;
    switch (vector_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_17 = local_arr[aux % 3];
    acc = (acc + damping_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_9(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_27) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_19 = (aux + st.buffer[1]) & 3;
    switch (scale_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_10(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000783_8313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_13) & 63;
    acc ^= aux;
    int margin_46 = (aux + st.buffer[1]) & 3;
    switch (margin_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_38 = local_arr[aux % 3];
    acc = (acc + mask_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000783_8313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_89 > 38) {
        acc = (acc + quantum_89 * 2 + 5) & 127;
        aux ^= (quantum_89 & 15);
    } else {
        acc = (acc - quantum_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000783_8313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_61 = (aux + st.buffer[1]) & 3;
    switch (metric_61) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_89 = local_arr[aux % 3];
    acc = (acc + factor_89 * 2) & 127;
    int pivot_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_70) & 63;
    acc ^= aux;
    int vector_94 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_94 > 22) {
        acc = (acc + vector_94 * 2 + 5) & 127;
        aux ^= (vector_94 & 15);
    } else {
        acc = (acc - vector_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000783_8313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_20 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_20 > 25) {
        acc = (acc + index_reg_20 * 2 + 5) & 127;
        aux ^= (index_reg_20 & 15);
    } else {
        acc = (acc - index_reg_20 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_14(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000783_8313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int tally_26 = local_arr[aux % 3];
    acc = (acc + tally_26 * 2) & 127;
    int phase_98 = (aux + st.buffer[1]) & 3;
    switch (phase_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000783_8313_15(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000783_8313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int window_59 = (aux + st.buffer[1]) & 3;
    switch (window_59) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_43 = local_arr[aux % 3];
    acc = (acc + tally_43 * 2) & 127;
    int margin_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_81) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000783_8313_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000783_8313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int metric_43 = local_arr[aux % 3];
    acc = (acc + metric_43 * 2) & 127;
    int pivot_16 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_16 > 20) {
        acc = (acc + pivot_16 * 2 + 5) & 127;
        aux ^= (pivot_16 & 15);
    } else {
        acc = (acc - pivot_16 + 11) & 127;
        aux += 3;
    }
    int coefficient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000783_8313_17(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000783_8313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_48 = (aux + st.buffer[1]) & 3;
    switch (mask_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_49) & 63;
    acc ^= aux;
    int index_reg_18 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_18 > 31) {
        acc = (acc + index_reg_18 * 2 + 5) & 127;
        aux ^= (index_reg_18 & 15);
    } else {
        acc = (acc - index_reg_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000783_0;
    int sec_r000783_1;
    int sec_r000783_2;
    int sec_r000783_3;
    int sec_r000783_4;
    int sec_r000783_5;
    int sec_r000783_6;
    int sec_r000783_7;
    int sec_r000783_8;
    int sec_r000783_9;
    int sec_r000783_10;
    int sec_r000783_11;
    int sec_r000783_12;
    int sec_r000783_13;
    int sec_r000783_14;
    int sec_r000783_15;
    int sec_r000783_16;
    int pub_r000783_0;
    int pub_r000783_1;
    int pub_r000783_2;
    int pub_r000783_3;
    int pub_r000783_4;
    int pub_r000783_5;
    int pub_r000783_6;
    int pub_r000783_7;
    int pub_r000783_8;
    int pub_r000783_9;
    int pub_r000783_10;
    int pub_r000783_11;
    int pub_r000783_12;
    int pub_r000783_13;
    int pub_r000783_14;
    int pub_r000783_15;
    int pub_r000783_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000783_0 >= -100 && pub_r000783_0 <= 100);
    __CPROVER_assume(pub_r000783_1 >= -100 && pub_r000783_1 <= 100);
    __CPROVER_assume(pub_r000783_2 >= -100 && pub_r000783_2 <= 100);
    __CPROVER_assume(pub_r000783_3 >= -100 && pub_r000783_3 <= 100);
    __CPROVER_assume(pub_r000783_4 >= -100 && pub_r000783_4 <= 100);
    __CPROVER_assume(pub_r000783_5 >= -100 && pub_r000783_5 <= 100);
    __CPROVER_assume(pub_r000783_6 >= -100 && pub_r000783_6 <= 100);
    __CPROVER_assume(pub_r000783_7 >= -100 && pub_r000783_7 <= 100);
    __CPROVER_assume(pub_r000783_8 >= -100 && pub_r000783_8 <= 100);
    __CPROVER_assume(pub_r000783_9 >= -100 && pub_r000783_9 <= 100);
    __CPROVER_assume(pub_r000783_10 >= -100 && pub_r000783_10 <= 100);
    __CPROVER_assume(pub_r000783_11 >= -100 && pub_r000783_11 <= 100);
    __CPROVER_assume(pub_r000783_12 >= -100 && pub_r000783_12 <= 100);
    __CPROVER_assume(pub_r000783_13 >= -100 && pub_r000783_13 <= 100);
    __CPROVER_assume(pub_r000783_14 >= -100 && pub_r000783_14 <= 100);
    __CPROVER_assume(pub_r000783_15 >= -100 && pub_r000783_15 <= 100);
    __CPROVER_assume(pub_r000783_16 >= -100 && pub_r000783_16 <= 100);
    __CPROVER_assume(sec_r000783_0 >= 0 && sec_r000783_0 <= 255);
    __CPROVER_assume(sec_r000783_1 >= 0 && sec_r000783_1 <= 255);
    __CPROVER_assume(sec_r000783_2 >= 0 && sec_r000783_2 <= 255);
    __CPROVER_assume(sec_r000783_3 >= 0 && sec_r000783_3 <= 255);
    __CPROVER_assume(sec_r000783_4 >= 0 && sec_r000783_4 <= 255);
    __CPROVER_assume(sec_r000783_5 >= 0 && sec_r000783_5 <= 255);
    __CPROVER_assume(sec_r000783_6 >= 0 && sec_r000783_6 <= 255);
    __CPROVER_assume(sec_r000783_7 >= 0 && sec_r000783_7 <= 255);
    __CPROVER_assume(sec_r000783_8 >= 0 && sec_r000783_8 <= 255);
    __CPROVER_assume(sec_r000783_9 >= 0 && sec_r000783_9 <= 255);
    __CPROVER_assume(sec_r000783_10 >= 0 && sec_r000783_10 <= 255);
    __CPROVER_assume(sec_r000783_11 >= 0 && sec_r000783_11 <= 255);
    __CPROVER_assume(sec_r000783_12 >= 0 && sec_r000783_12 <= 255);
    __CPROVER_assume(sec_r000783_13 >= 0 && sec_r000783_13 <= 255);
    __CPROVER_assume(sec_r000783_14 >= 0 && sec_r000783_14 <= 255);
    __CPROVER_assume(sec_r000783_15 >= 0 && sec_r000783_15 <= 255);
    __CPROVER_assume(sec_r000783_16 >= 0 && sec_r000783_16 <= 255);

    struct CipherContext_R000783_8313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000783_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000783_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000783_0 + 7) & 15;
    struct Transaction_R000783_8313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000783_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000783_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000783_0 + 9) & 15;
    struct MatrixBlock_R000783_8313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000783_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000783_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000783_0 + 11) & 15;
    struct Vector3D_R000783_8313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000783_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000783_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000783_0 + 13) & 15;

    union RegisterBank_R000783_8313_0 u_var;
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
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 36) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 51) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 39) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 54) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 11) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 26) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

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
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 21) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 36) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 26) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 41) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 21) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 36) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 17) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 32) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

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
    if (stage_v_50 > 28) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 43) {
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 25) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 40) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 20) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 35) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int sub_step_71 = (sec_r000783_11 + pub_r000783_5 + 11) & 127;
    int stage_v_71 = (sub_step_71 * 2 + pub_r000783_5) & 127;
    st_var_3.buffer[2] = (stage_v_71 & 15);
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (sec_r000783_5 + pub_r000783_1 + 18) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000783_11) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (stage_v_72 + pub_r000783_0 + 33) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000783_1) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (sub_step_71 + pub_r000783_10 + 34) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000783_16) & 127;
    st_var_2.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (stage_v_71 + pub_r000783_3 + 19) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000783_2) & 127;
    st_var_3.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (sec_r000783_13 + pub_r000783_10 + 30) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000783_13) & 127;
    st_var_0.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (sec_r000783_3 + pub_r000783_8 + 23) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000783_13) & 127;
    st_var_1.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (stage_v_72 + pub_r000783_8 + 24) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000783_2) & 127;
    st_var_2.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sub_step_74 + pub_r000783_15 + 33) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000783_16) & 127;
    st_var_3.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (stage_v_71 + pub_r000783_7 + 31) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000783_8) & 127;
    st_var_0.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000783_4 + pub_r000783_3 + 19) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sec_r000783_4 + pub_r000783_4 + 30) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000783_5) & 127;
    st_var_2.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (stage_v_71 + pub_r000783_8 + 15) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000783_5) & 127;
    st_var_3.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sec_r000783_5 + pub_r000783_10 + 14) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000783_4) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sec_r000783_6 + pub_r000783_12 + 18) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (stage_v_77 + pub_r000783_4 + 20) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000783_0) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (stage_v_75 + pub_r000783_13 + 31) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (sub_step_79 + pub_r000783_8 + 9) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000783_10) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sec_r000783_11 + pub_r000783_3 + 24) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000783_0) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sec_r000783_11 + pub_r000783_15 + 28) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000783_8) & 127;
    st_var_2.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sub_step_84 + pub_r000783_13 + 15) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000783_16) & 127;
    st_var_3.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sub_step_76 + pub_r000783_16 + 25) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (stage_v_87 + pub_r000783_7 + 11) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000783_3) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sub_step_71 + pub_r000783_9 + 14) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000783_1) & 127;
    st_var_2.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sec_r000783_6 + pub_r000783_9 + 16) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000783_3 + pub_r000783_3 + 34) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (stage_v_92 + pub_r000783_10 + 19) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000783_5) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (stage_v_95 + pub_r000783_9 + 25) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000783_0) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000783_13 + pub_r000783_10 + 14) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000783_16) & 127;
    st_var_3.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_85 + pub_r000783_13 + 7) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000783_10) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (stage_v_92 + pub_r000783_14 + 7) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000783_6) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000783_8 + pub_r000783_3 + 19) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000783_1) & 127;
    st_var_2.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sub_step_98 + pub_r000783_9 + 20) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000783_7) & 127;
    st_var_3.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sub_step_92 + pub_r000783_3 + 19) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000783_8) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (stage_v_83 + pub_r000783_2 + 24) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000783_5) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sec_r000783_2 + pub_r000783_0 + 16) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000783_3) & 127;
    st_var_2.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sub_step_102 + pub_r000783_9 + 6) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000783_6) & 127;
    st_var_3.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_71 + pub_r000783_4 + 19) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000783_16) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sub_step_95 + pub_r000783_15 + 25) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000783_12) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sub_step_83 + pub_r000783_0 + 12) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000783_11) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sub_step_92 + pub_r000783_10 + 17) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000783_8) & 127;
    st_var_3.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000783_5 + pub_r000783_1 + 6) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000783_15) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sub_step_90 + pub_r000783_9 + 17) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000783_16) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sub_step_102 + pub_r000783_8 + 5) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000783_1) & 127;
    st_var_2.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_105 + pub_r000783_0 + 34) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000783_8) & 127;
    st_var_3.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sec_r000783_13 + pub_r000783_2 + 35) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000783_6) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_100 + pub_r000783_13 + 25) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000783_13) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_100 + pub_r000783_13 + 15) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000783_9) & 127;
    st_var_2.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sec_r000783_8 + pub_r000783_9 + 31) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000783_3 + pub_r000783_15 + 19) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000783_11) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (stage_v_78 + pub_r000783_7 + 8) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (stage_v_90 + pub_r000783_2 + 35) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000783_14) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (stage_v_117 + pub_r000783_3 + 25) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000783_4) & 127;
    st_var_3.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_106 + pub_r000783_1 + 22) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000783_8) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (stage_v_91 + pub_r000783_10 + 9) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_89 + pub_r000783_10 + 23) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000783_13) & 127;
    st_var_2.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (stage_v_116 + pub_r000783_3 + 20) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000783_12) & 127;
    st_var_3.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (sec_r000783_2 + pub_r000783_7 + 32) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000783_5) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (stage_v_86 + pub_r000783_16 + 9) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000783_3) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sec_r000783_4 + pub_r000783_13 + 20) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000783_12) & 127;
    st_var_2.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000783_4 + pub_r000783_10 + 19) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000783_5) & 127;
    st_var_3.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (sub_step_122 + pub_r000783_1 + 28) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000783_3) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sec_r000783_6 + pub_r000783_7 + 8) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sec_r000783_14 + pub_r000783_4 + 11) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sub_step_99 + pub_r000783_8 + 16) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000783_3) & 127;
    st_var_3.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_122 + pub_r000783_10 + 19) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000783_6) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sec_r000783_15 + pub_r000783_6 + 31) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000783_2) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sub_step_129 + pub_r000783_16 + 31) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000783_9) & 127;
    st_var_2.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_102 + pub_r000783_5 + 16) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000783_14) & 127;
    st_var_3.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sub_step_101 + pub_r000783_13 + 34) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sec_r000783_15 + pub_r000783_16 + 35) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000783_4) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (stage_v_121 + pub_r000783_13 + 16) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000783_13) & 127;
    st_var_2.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000783_2 + pub_r000783_2 + 29) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000783_8) & 127;
    st_var_3.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (sub_step_127 + pub_r000783_16 + 16) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000783_4) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sec_r000783_13 + pub_r000783_7 + 26) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000783_0) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_112 + pub_r000783_15 + 21) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (stage_v_137 + pub_r000783_5 + 13) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000783_6) & 127;
    st_var_3.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000783_14 + pub_r000783_12 + 15) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000783_6) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sub_step_91 + pub_r000783_13 + 21) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000783_5) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sec_r000783_2 + pub_r000783_1 + 32) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000783_2) & 127;
    st_var_2.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sub_step_85 + pub_r000783_14 + 11) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000783_13) & 127;
    st_var_3.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sec_r000783_15 + pub_r000783_11 + 23) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sec_r000783_11 + pub_r000783_10 + 13) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_97 + pub_r000783_9 + 6) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000783_4 + pub_r000783_12 + 19) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000783_15) & 127;
    st_var_3.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000783_2 + pub_r000783_9 + 25) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sub_step_133 + pub_r000783_13 + 6) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000783_0) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sec_r000783_13 + pub_r000783_9 + 31) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000783_13) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (stage_v_112 + pub_r000783_6 + 10) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000783_8) & 127;
    st_var_3.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (stage_v_117 + pub_r000783_2 + 9) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000783_11) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (stage_v_130 + pub_r000783_15 + 25) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000783_14) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (stage_v_99 + pub_r000783_11 + 26) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000783_5) & 127;
    st_var_2.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (stage_v_129 + pub_r000783_2 + 22) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000783_5) & 127;
    st_var_3.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000783_4 + pub_r000783_0 + 35) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000783_10) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sec_r000783_4 + pub_r000783_7 + 31) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sub_step_113 + pub_r000783_1 + 11) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000783_11) & 127;
    st_var_2.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (stage_v_109 + pub_r000783_10 + 31) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sub_step_120 + pub_r000783_10 + 30) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sub_step_133 + pub_r000783_14 + 32) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_88 + pub_r000783_9 + 35) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000783_9) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000783_1 + pub_r000783_11 + 17) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000783_14) & 127;
    st_var_3.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (stage_v_149 + pub_r000783_10 + 13) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000783_12) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sub_step_93 + pub_r000783_7 + 5) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000783_0) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sec_r000783_0 + pub_r000783_15 + 34) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000783_3) & 127;
    st_var_2.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (sec_r000783_5 + pub_r000783_0 + 18) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000783_14) & 127;
    st_var_3.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sub_step_141 + pub_r000783_9 + 6) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000783_0) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sub_step_164 + pub_r000783_3 + 19) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sec_r000783_16 + pub_r000783_11 + 7) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000783_1) & 127;
    st_var_2.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sub_step_99 + pub_r000783_16 + 34) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000783_4) & 127;
    st_var_3.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sec_r000783_9 + pub_r000783_8 + 9) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000783_16) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sub_step_106 + pub_r000783_7 + 15) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000783_9) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (stage_v_115 + pub_r000783_15 + 24) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000783_0) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (stage_v_109 + pub_r000783_12 + 33) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000783_0) & 127;
    st_var_3.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (stage_v_92 + pub_r000783_0 + 8) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000783_12) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000783_15 + pub_r000783_1 + 32) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sub_step_165 + pub_r000783_1 + 13) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000783_5) & 127;
    st_var_2.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sub_step_112 + pub_r000783_3 + 31) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_125 + pub_r000783_16 + 20) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000783_1) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sec_r000783_12 + pub_r000783_6 + 26) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000783_15) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sub_step_109 + pub_r000783_9 + 13) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000783_8) & 127;
    st_var_2.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_101 + pub_r000783_12 + 31) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000783_3) & 127;
    st_var_3.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (stage_v_129 + pub_r000783_4 + 22) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000783_12) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000783_14 + pub_r000783_0 + 12) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000783_6) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (sec_r000783_0 + pub_r000783_5 + 12) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000783_11) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000783_15 + pub_r000783_10 + 22) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000783_5) & 127;
    st_var_3.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_78 + pub_r000783_4 + 27) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000783_15) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (stage_v_106 + pub_r000783_11 + 14) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000783_4) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (stage_v_105 + pub_r000783_2 + 19) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000783_7) & 127;
    st_var_2.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_77 + pub_r000783_10 + 20) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (stage_v_96 + pub_r000783_15 + 33) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000783_15) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sub_step_131 + pub_r000783_4 + 16) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000783_4) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (stage_v_123 + pub_r000783_7 + 27) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000783_11) & 127;
    st_var_2.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sub_step_182 + pub_r000783_4 + 18) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000783_15 + pub_r000783_7 + 31) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000783_8) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (stage_v_114 + pub_r000783_2 + 23) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000783_2) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (stage_v_72 + pub_r000783_5 + 10) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (stage_v_200 + pub_r000783_2 + 21) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000783_16) & 127;
    st_var_3.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000783_10 + pub_r000783_5 + 19) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000783_8) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sec_r000783_7 + pub_r000783_7 + 28) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000783_3) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sub_step_191 + pub_r000783_9 + 31) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000783_5) & 127;
    st_var_2.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000783_1 + pub_r000783_7 + 31) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000783_12) & 127;
    st_var_3.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sub_step_128 + pub_r000783_6 + 16) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000783_1) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_122 + pub_r000783_9 + 30) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000783_2) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_153 + pub_r000783_12 + 18) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000783_15) & 127;
    st_var_2.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_132 + pub_r000783_5 + 21) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000783_4) & 127;
    st_var_3.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000783_16 + pub_r000783_12 + 33) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000783_9) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sub_step_178 + pub_r000783_1 + 26) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000783_2) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sub_step_116 + pub_r000783_16 + 23) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sub_step_106 + pub_r000783_12 + 18) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000783_6) & 127;
    st_var_3.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sub_step_171 + pub_r000783_7 + 25) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000783_10) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_194 + pub_r000783_9 + 17) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000783_14) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_207 + pub_r000783_12 + 19) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000783_10) & 127;
    st_var_2.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (stage_v_113 + pub_r000783_6 + 33) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000783_2) & 127;
    st_var_3.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000783_16 + pub_r000783_5 + 26) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sec_r000783_4 + pub_r000783_9 + 32) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000783_7) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sub_step_204 + pub_r000783_5 + 23) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000783_12) & 127;
    st_var_2.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sub_step_110 + pub_r000783_10 + 35) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000783_7) & 127;
    st_var_3.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (sub_step_76 + pub_r000783_3 + 35) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000783_4) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sub_step_106 + pub_r000783_1 + 30) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000783_2) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000783_9 + pub_r000783_9 + 16) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000783_4) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sec_r000783_9 + pub_r000783_2 + 33) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000783_6) & 127;
    st_var_3.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sub_step_147 + pub_r000783_6 + 29) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000783_4) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (stage_v_209 + pub_r000783_14 + 7) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000783_5) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sub_step_229 + pub_r000783_6 + 33) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000783_0) & 127;
    st_var_2.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_173 + pub_r000783_2 + 21) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000783_15) & 127;
    st_var_3.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (sub_step_170 + pub_r000783_7 + 24) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_195 + pub_r000783_11 + 17) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000783_1) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sub_step_189 + pub_r000783_3 + 12) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000783_15) & 127;
    st_var_2.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000783_8 + pub_r000783_10 + 27) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000783_14) & 127;
    st_var_3.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sec_r000783_1 + pub_r000783_14 + 29) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000783_13) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_123 + pub_r000783_2 + 7) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000783_4) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000783_7 + pub_r000783_9 + 7) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000783_16) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sec_r000783_16 + pub_r000783_10 + 13) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000783_8) & 127;
    st_var_3.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (stage_v_214 + pub_r000783_7 + 21) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000783_6) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000783_5 + pub_r000783_9 + 22) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000783_9) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (stage_v_168 + pub_r000783_11 + 9) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000783_8) & 127;
    st_var_2.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (sub_step_89 + pub_r000783_11 + 23) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000783_13) & 127;
    st_var_3.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sec_r000783_2 + pub_r000783_5 + 18) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000783_1) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (sub_step_197 + pub_r000783_8 + 5) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000783_7) & 127;
    st_var_1.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (stage_v_106 + pub_r000783_2 + 22) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000783_16) & 127;
    st_var_2.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (sec_r000783_4 + pub_r000783_6 + 32) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000783_15) & 127;
    st_var_3.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (stage_v_159 + pub_r000783_12 + 7) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000783_3) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (stage_v_186 + pub_r000783_0 + 20) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000783_9) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (stage_v_212 + pub_r000783_9 + 18) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000783_10) & 127;
    st_var_2.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sub_step_154 + pub_r000783_5 + 17) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000783_0) & 127;
    st_var_3.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sub_step_84 + pub_r000783_13 + 24) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000783_7) & 127;
    st_var_0.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (sec_r000783_11 + pub_r000783_2 + 16) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000783_6) & 127;
    st_var_1.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (sec_r000783_9 + pub_r000783_5 + 18) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000783_9) & 127;
    st_var_2.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (sec_r000783_1 + pub_r000783_5 + 14) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000783_12) & 127;
    st_var_3.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (stage_v_99 + pub_r000783_14 + 20) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000783_16) & 127;
    st_var_0.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int sub_step_261 = (sub_step_228 + pub_r000783_16 + 16) & 127;
    int stage_v_261 = (sub_step_261 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[0] = (stage_v_261 & 15);
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int sub_step_262 = (sec_r000783_16 + pub_r000783_7 + 27) & 127;
    int stage_v_262 = (sub_step_262 * 2 + pub_r000783_11) & 127;
    st_var_2.buffer[1] = (stage_v_262 & 15);
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int sub_step_263 = (sub_step_180 + pub_r000783_15 + 33) & 127;
    int stage_v_263 = (sub_step_263 * 2 + pub_r000783_2) & 127;
    st_var_3.buffer[2] = (stage_v_263 & 15);
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int sub_step_264 = (stage_v_232 + pub_r000783_15 + 9) & 127;
    int stage_v_264 = (sub_step_264 * 2 + pub_r000783_5) & 127;
    st_var_0.buffer[0] = (stage_v_264 & 15);
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int sub_step_265 = (sec_r000783_8 + pub_r000783_9 + 33) & 127;
    int stage_v_265 = (sub_step_265 * 2 + pub_r000783_0) & 127;
    st_var_1.buffer[1] = (stage_v_265 & 15);
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int sub_step_266 = (sub_step_185 + pub_r000783_8 + 35) & 127;
    int stage_v_266 = (sub_step_266 * 2 + pub_r000783_7) & 127;
    st_var_2.buffer[2] = (stage_v_266 & 15);
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int sub_step_267 = (sec_r000783_10 + pub_r000783_11 + 30) & 127;
    int stage_v_267 = (sub_step_267 * 2 + pub_r000783_11) & 127;
    st_var_3.buffer[0] = (stage_v_267 & 15);
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int sub_step_268 = (stage_v_177 + pub_r000783_4 + 17) & 127;
    int stage_v_268 = (sub_step_268 * 2 + pub_r000783_1) & 127;
    st_var_0.buffer[1] = (stage_v_268 & 15);
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int sub_step_269 = (sec_r000783_14 + pub_r000783_16 + 28) & 127;
    int stage_v_269 = (sub_step_269 * 2 + pub_r000783_9) & 127;
    st_var_1.buffer[2] = (stage_v_269 & 15);
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int sub_step_270 = (sec_r000783_7 + pub_r000783_11 + 29) & 127;
    int stage_v_270 = (sub_step_270 * 2 + pub_r000783_15) & 127;
    st_var_2.buffer[0] = (stage_v_270 & 15);
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int sub_step_271 = (sub_step_79 + pub_r000783_15 + 35) & 127;
    int stage_v_271 = (sub_step_271 * 2 + pub_r000783_11) & 127;
    st_var_3.buffer[1] = (stage_v_271 & 15);
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int sub_step_272 = (stage_v_243 + pub_r000783_9 + 22) & 127;
    int stage_v_272 = (sub_step_272 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[2] = (stage_v_272 & 15);
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int sub_step_273 = (stage_v_104 + pub_r000783_4 + 9) & 127;
    int stage_v_273 = (sub_step_273 * 2 + pub_r000783_10) & 127;
    st_var_1.buffer[0] = (stage_v_273 & 15);
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int sub_step_274 = (sub_step_202 + pub_r000783_6 + 34) & 127;
    int stage_v_274 = (sub_step_274 * 2 + pub_r000783_15) & 127;
    st_var_2.buffer[1] = (stage_v_274 & 15);
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int sub_step_275 = (sub_step_227 + pub_r000783_4 + 11) & 127;
    int stage_v_275 = (sub_step_275 * 2 + pub_r000783_11) & 127;
    st_var_3.buffer[2] = (stage_v_275 & 15);
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int sub_step_276 = (sub_step_80 + pub_r000783_16 + 31) & 127;
    int stage_v_276 = (sub_step_276 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[0] = (stage_v_276 & 15);
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int sub_step_277 = (sec_r000783_3 + pub_r000783_2 + 5) & 127;
    int stage_v_277 = (sub_step_277 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[1] = (stage_v_277 & 15);
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int sub_step_278 = (sub_step_263 + pub_r000783_6 + 8) & 127;
    int stage_v_278 = (sub_step_278 * 2 + pub_r000783_7) & 127;
    st_var_2.buffer[2] = (stage_v_278 & 15);
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int sub_step_279 = (sub_step_227 + pub_r000783_16 + 31) & 127;
    int stage_v_279 = (sub_step_279 * 2 + pub_r000783_15) & 127;
    st_var_3.buffer[0] = (stage_v_279 & 15);
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int sub_step_280 = (stage_v_194 + pub_r000783_13 + 9) & 127;
    int stage_v_280 = (sub_step_280 * 2 + pub_r000783_16) & 127;
    st_var_0.buffer[1] = (stage_v_280 & 15);
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int sub_step_281 = (sub_step_73 + pub_r000783_9 + 32) & 127;
    int stage_v_281 = (sub_step_281 * 2 + pub_r000783_12) & 127;
    st_var_1.buffer[2] = (stage_v_281 & 15);
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int sub_step_282 = (sec_r000783_14 + pub_r000783_9 + 30) & 127;
    int stage_v_282 = (sub_step_282 * 2 + pub_r000783_1) & 127;
    st_var_2.buffer[0] = (stage_v_282 & 15);
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int sub_step_283 = (sec_r000783_14 + pub_r000783_7 + 33) & 127;
    int stage_v_283 = (sub_step_283 * 2 + pub_r000783_15) & 127;
    st_var_3.buffer[1] = (stage_v_283 & 15);
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int sub_step_284 = (sec_r000783_10 + pub_r000783_11 + 30) & 127;
    int stage_v_284 = (sub_step_284 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[2] = (stage_v_284 & 15);
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int sub_step_285 = (sub_step_90 + pub_r000783_5 + 33) & 127;
    int stage_v_285 = (sub_step_285 * 2 + pub_r000783_4) & 127;
    st_var_1.buffer[0] = (stage_v_285 & 15);
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int sub_step_286 = (sub_step_278 + pub_r000783_2 + 13) & 127;
    int stage_v_286 = (sub_step_286 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[1] = (stage_v_286 & 15);
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int sub_step_287 = (sub_step_237 + pub_r000783_1 + 24) & 127;
    int stage_v_287 = (sub_step_287 * 2 + pub_r000783_4) & 127;
    st_var_3.buffer[2] = (stage_v_287 & 15);
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int sub_step_288 = (sec_r000783_13 + pub_r000783_16 + 22) & 127;
    int stage_v_288 = (sub_step_288 * 2 + pub_r000783_14) & 127;
    st_var_0.buffer[0] = (stage_v_288 & 15);
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int sub_step_289 = (sub_step_284 + pub_r000783_15 + 12) & 127;
    int stage_v_289 = (sub_step_289 * 2 + pub_r000783_16) & 127;
    st_var_1.buffer[1] = (stage_v_289 & 15);
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int sub_step_290 = (sub_step_289 + pub_r000783_5 + 14) & 127;
    int stage_v_290 = (sub_step_290 * 2 + pub_r000783_16) & 127;
    st_var_2.buffer[2] = (stage_v_290 & 15);
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int sub_step_291 = (sec_r000783_5 + pub_r000783_2 + 24) & 127;
    int stage_v_291 = (sub_step_291 * 2 + pub_r000783_4) & 127;
    st_var_3.buffer[0] = (stage_v_291 & 15);
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int sub_step_292 = (sec_r000783_0 + pub_r000783_7 + 35) & 127;
    int stage_v_292 = (sub_step_292 * 2 + pub_r000783_5) & 127;
    st_var_0.buffer[1] = (stage_v_292 & 15);
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int sub_step_293 = (sub_step_110 + pub_r000783_3 + 15) & 127;
    int stage_v_293 = (sub_step_293 * 2 + pub_r000783_1) & 127;
    st_var_1.buffer[2] = (stage_v_293 & 15);
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int sub_step_294 = (sub_step_216 + pub_r000783_2 + 16) & 127;
    int stage_v_294 = (sub_step_294 * 2 + pub_r000783_2) & 127;
    st_var_2.buffer[0] = (stage_v_294 & 15);
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int sub_step_295 = (sec_r000783_2 + pub_r000783_10 + 17) & 127;
    int stage_v_295 = (sub_step_295 * 2 + pub_r000783_12) & 127;
    st_var_3.buffer[1] = (stage_v_295 & 15);
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int sub_step_296 = (stage_v_143 + pub_r000783_0 + 7) & 127;
    int stage_v_296 = (sub_step_296 * 2 + pub_r000783_2) & 127;
    st_var_0.buffer[2] = (stage_v_296 & 15);
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int sub_step_297 = (sec_r000783_5 + pub_r000783_10 + 10) & 127;
    int stage_v_297 = (sub_step_297 * 2 + pub_r000783_16) & 127;
    st_var_1.buffer[0] = (stage_v_297 & 15);
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int sub_step_298 = (sub_step_239 + pub_r000783_11 + 11) & 127;
    int stage_v_298 = (sub_step_298 * 2 + pub_r000783_6) & 127;
    st_var_2.buffer[1] = (stage_v_298 & 15);
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int sub_step_299 = (sub_step_250 + pub_r000783_1 + 27) & 127;
    int stage_v_299 = (sub_step_299 * 2 + pub_r000783_9) & 127;
    st_var_3.buffer[2] = (stage_v_299 & 15);
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int sub_step_300 = (sub_step_161 + pub_r000783_12 + 26) & 127;
    int stage_v_300 = (sub_step_300 * 2 + pub_r000783_9) & 127;
    st_var_0.buffer[0] = (stage_v_300 & 15);
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int sub_step_301 = (stage_v_170 + pub_r000783_0 + 10) & 127;
    int stage_v_301 = (sub_step_301 * 2 + pub_r000783_3) & 127;
    st_var_1.buffer[1] = (stage_v_301 & 15);
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int sub_step_302 = (stage_v_234 + pub_r000783_12 + 8) & 127;
    int stage_v_302 = (sub_step_302 * 2 + pub_r000783_16) & 127;
    st_var_2.buffer[2] = (stage_v_302 & 15);
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int sub_step_303 = (sec_r000783_5 + pub_r000783_1 + 21) & 127;
    int stage_v_303 = (sub_step_303 * 2 + pub_r000783_9) & 127;
    st_var_3.buffer[0] = (stage_v_303 & 15);
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int sub_step_304 = (stage_v_186 + pub_r000783_5 + 22) & 127;
    int stage_v_304 = (sub_step_304 * 2 + pub_r000783_13) & 127;
    st_var_0.buffer[1] = (stage_v_304 & 15);
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int sub_step_305 = (sec_r000783_12 + pub_r000783_14 + 18) & 127;
    int stage_v_305 = (sub_step_305 * 2 + pub_r000783_8) & 127;
    st_var_1.buffer[2] = (stage_v_305 & 15);
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int sub_step_306 = (sec_r000783_6 + pub_r000783_6 + 26) & 127;
    int stage_v_306 = (sub_step_306 * 2 + pub_r000783_14) & 127;
    st_var_2.buffer[0] = (stage_v_306 & 15);
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int sub_step_307 = (stage_v_281 + pub_r000783_5 + 33) & 127;
    int stage_v_307 = (sub_step_307 * 2 + pub_r000783_11) & 127;
    st_var_3.buffer[1] = (stage_v_307 & 15);
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int sub_step_308 = (stage_v_208 + pub_r000783_9 + 12) & 127;
    int stage_v_308 = (sub_step_308 * 2 + pub_r000783_5) & 127;
    st_var_0.buffer[2] = (stage_v_308 & 15);
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int sub_step_309 = (stage_v_278 + pub_r000783_0 + 15) & 127;
    int stage_v_309 = (sub_step_309 * 2 + pub_r000783_12) & 127;
    st_var_1.buffer[0] = (stage_v_309 & 15);
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int sub_step_310 = (stage_v_126 + pub_r000783_13 + 8) & 127;
    int stage_v_310 = (sub_step_310 * 2 + pub_r000783_12) & 127;
    st_var_2.buffer[1] = (stage_v_310 & 15);
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int sub_step_311 = (sub_step_132 + pub_r000783_0 + 28) & 127;
    int stage_v_311 = (sub_step_311 * 2 + pub_r000783_2) & 127;
    st_var_3.buffer[2] = (stage_v_311 & 15);
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int sub_step_312 = (stage_v_274 + pub_r000783_7 + 28) & 127;
    int stage_v_312 = (sub_step_312 * 2 + pub_r000783_9) & 127;
    st_var_0.buffer[0] = (stage_v_312 & 15);
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int sub_step_313 = (sec_r000783_12 + pub_r000783_8 + 32) & 127;
    int stage_v_313 = (sub_step_313 * 2 + pub_r000783_11) & 127;
    st_var_1.buffer[1] = (stage_v_313 & 15);
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int sub_step_314 = (sub_step_122 + pub_r000783_8 + 26) & 127;
    int stage_v_314 = (sub_step_314 * 2 + pub_r000783_12) & 127;
    st_var_2.buffer[2] = (stage_v_314 & 15);
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int sub_step_315 = (sec_r000783_6 + pub_r000783_15 + 13) & 127;
    int stage_v_315 = (sub_step_315 * 2 + pub_r000783_10) & 127;
    st_var_3.buffer[0] = (stage_v_315 & 15);
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int sub_step_316 = (stage_v_112 + pub_r000783_16 + 14) & 127;
    int stage_v_316 = (sub_step_316 * 2 + pub_r000783_1) & 127;
    st_var_0.buffer[1] = (stage_v_316 & 15);
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int sub_step_317 = (sub_step_285 + pub_r000783_13 + 31) & 127;
    int stage_v_317 = (sub_step_317 * 2 + pub_r000783_3) & 127;
    st_var_1.buffer[2] = (stage_v_317 & 15);
    out_sink = (out_sink + stage_v_317) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
