/*
 * Benchmark Program: R000187
 * Security Family: nested_implicit_flow
 * Generator Seed: 518713
 * High Inputs: 19 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000187_8713_0 {
    int coord_y;
    short pitch;
    int norm_sq;
    unsigned char heading;
    short coord_z;
    int coord_x;
    int buffer[3];
};

struct CipherContext_R000187_8713_1 {
    unsigned char nonce;
    int counter;
    int iv;
    int tag;
    unsigned char round_key;
    int flags;
    int buffer[3];
};

union PacketPayload_R000187_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000187_8713_0(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_52) & 63;
    acc ^= aux;
    int factor_43 = (aux + st.buffer[1]) & 3;
    switch (factor_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_69 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_69 > 17) {
        acc = (acc + quotient_69 * 2 + 5) & 127;
        aux ^= (quotient_69 & 15);
    } else {
        acc = (acc - quotient_69 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_73 = local_arr[aux % 3];
    acc = (acc + damping_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_1(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_54 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_54 > 28) {
        acc = (acc + accumulator_54 * 2 + 5) & 127;
        aux ^= (accumulator_54 & 15);
    } else {
        acc = (acc - accumulator_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000187_8713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_42 = (aux + st.buffer[1]) & 3;
    switch (margin_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_55 = local_arr[aux % 3];
    acc = (acc + pivot_55 * 2) & 127;
    int tally_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000187_8713_3(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_50) & 63;
    acc ^= aux;
    int segment_72 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_72 > 26) {
        acc = (acc + segment_72 * 2 + 5) & 127;
        aux ^= (segment_72 & 15);
    } else {
        acc = (acc - segment_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_22 = local_arr[aux % 3];
    acc = (acc + pivot_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_4(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_39 = (aux + st.buffer[1]) & 3;
    switch (residue_39) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_84 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_84 > 49) {
        acc = (acc + cursor_84 * 2 + 5) & 127;
        aux ^= (cursor_84 & 15);
    } else {
        acc = (acc - cursor_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_80 = local_arr[aux % 3];
    acc = (acc + pivot_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_5(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_47 = (aux + st.buffer[1]) & 3;
    switch (metric_47) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_95 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_95 > 19) {
        acc = (acc + coefficient_95 * 2 + 5) & 127;
        aux ^= (coefficient_95 & 15);
    } else {
        acc = (acc - coefficient_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000187_8713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int bound_53 = local_arr[aux % 3];
    acc = (acc + bound_53 * 2) & 127;
    int pivot_33 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_33 > 24) {
        acc = (acc + pivot_33 * 2 + 5) & 127;
        aux ^= (pivot_33 & 15);
    } else {
        acc = (acc - pivot_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000187_8713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_42 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_42 > 43) {
        acc = (acc + stride_42 * 2 + 5) & 127;
        aux ^= (stride_42 & 15);
    } else {
        acc = (acc - stride_42 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_8(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_34) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_95 = local_arr[aux % 3];
    acc = (acc + vector_95 * 2) & 127;
    int factor_18 = (aux + st.buffer[1]) & 3;
    switch (factor_18) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_80) & 63;
    acc ^= aux;
    int delta_82 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_82 > 14) {
        acc = (acc + delta_82 * 2 + 5) & 127;
        aux ^= (delta_82 & 15);
    } else {
        acc = (acc - delta_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_47 = local_arr[aux % 3];
    acc = (acc + damping_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_10(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_53) & 63;
    acc ^= aux;
    int weight_72 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_72 > 22) {
        acc = (acc + weight_72 * 2 + 5) & 127;
        aux ^= (weight_72 & 15);
    } else {
        acc = (acc - weight_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000187_8713_11(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int threshold_70 = local_arr[aux % 3];
    acc = (acc + threshold_70 * 2) & 127;
    int parity_39 = (aux + st.buffer[1]) & 3;
    switch (parity_39) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000187_8713_12(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_19 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_19 > 20) {
        acc = (acc + bound_19 * 2 + 5) & 127;
        aux ^= (bound_19 & 15);
    } else {
        acc = (acc - bound_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_49 = local_arr[aux % 3];
    acc = (acc + window_49 * 2) & 127;
    int scale_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000187_8713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int phase_75 = (aux + st.buffer[1]) & 3;
    switch (phase_75) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_67 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_67 > 39) {
        acc = (acc + index_reg_67 * 2 + 5) & 127;
        aux ^= (index_reg_67 & 15);
    } else {
        acc = (acc - index_reg_67 + 11) & 127;
        aux += 3;
    }
    int tracker_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000187_8713_14(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int bound_92 = local_arr[aux % 3];
    acc = (acc + bound_92 * 2) & 127;
    int sample_33 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_33 > 41) {
        acc = (acc + sample_33 * 2 + 5) & 127;
        aux ^= (sample_33 & 15);
    } else {
        acc = (acc - sample_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_17 = (aux + st.buffer[1]) & 3;
    switch (quotient_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000187_8713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000187_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int damping_57 = local_arr[aux % 3];
    acc = (acc + damping_57 * 2) & 127;
    int tally_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000187_8713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_38 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_38 > 30) {
        acc = (acc + parity_38 * 2 + 5) & 127;
        aux ^= (parity_38 & 15);
    } else {
        acc = (acc - parity_38 + 11) & 127;
        aux += 3;
    }
    int checksum_72 = (aux + st.buffer[1]) & 3;
    switch (checksum_72) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_45 = local_arr[aux % 3];
    acc = (acc + metric_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000187_8713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000187_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_26 = local_arr[aux % 3];
    acc = (acc + sample_26 * 2) & 127;
    int tally_14 = (aux + st.buffer[1]) & 3;
    switch (tally_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000187_0;
    int sec_r000187_1;
    int sec_r000187_2;
    int sec_r000187_3;
    int sec_r000187_4;
    int sec_r000187_5;
    int sec_r000187_6;
    int sec_r000187_7;
    int sec_r000187_8;
    int sec_r000187_9;
    int sec_r000187_10;
    int sec_r000187_11;
    int sec_r000187_12;
    int sec_r000187_13;
    int sec_r000187_14;
    int sec_r000187_15;
    int sec_r000187_16;
    int sec_r000187_17;
    int sec_r000187_18;
    int pub_r000187_0;
    int pub_r000187_1;
    int pub_r000187_2;
    int pub_r000187_3;
    int pub_r000187_4;
    int pub_r000187_5;
    int pub_r000187_6;
    int pub_r000187_7;
    int pub_r000187_8;
    int pub_r000187_9;
    int pub_r000187_10;
    int pub_r000187_11;
    int pub_r000187_12;
    int pub_r000187_13;
    int pub_r000187_14;
    int pub_r000187_15;
    int pub_r000187_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000187_0 >= -100 && pub_r000187_0 <= 100);
    __CPROVER_assume(pub_r000187_1 >= -100 && pub_r000187_1 <= 100);
    __CPROVER_assume(pub_r000187_2 >= -100 && pub_r000187_2 <= 100);
    __CPROVER_assume(pub_r000187_3 >= -100 && pub_r000187_3 <= 100);
    __CPROVER_assume(pub_r000187_4 >= -100 && pub_r000187_4 <= 100);
    __CPROVER_assume(pub_r000187_5 >= -100 && pub_r000187_5 <= 100);
    __CPROVER_assume(pub_r000187_6 >= -100 && pub_r000187_6 <= 100);
    __CPROVER_assume(pub_r000187_7 >= -100 && pub_r000187_7 <= 100);
    __CPROVER_assume(pub_r000187_8 >= -100 && pub_r000187_8 <= 100);
    __CPROVER_assume(pub_r000187_9 >= -100 && pub_r000187_9 <= 100);
    __CPROVER_assume(pub_r000187_10 >= -100 && pub_r000187_10 <= 100);
    __CPROVER_assume(pub_r000187_11 >= -100 && pub_r000187_11 <= 100);
    __CPROVER_assume(pub_r000187_12 >= -100 && pub_r000187_12 <= 100);
    __CPROVER_assume(pub_r000187_13 >= -100 && pub_r000187_13 <= 100);
    __CPROVER_assume(pub_r000187_14 >= -100 && pub_r000187_14 <= 100);
    __CPROVER_assume(pub_r000187_15 >= -100 && pub_r000187_15 <= 100);
    __CPROVER_assume(pub_r000187_16 >= -100 && pub_r000187_16 <= 100);
    __CPROVER_assume(sec_r000187_0 >= 0 && sec_r000187_0 <= 255);
    __CPROVER_assume(sec_r000187_1 >= 0 && sec_r000187_1 <= 255);
    __CPROVER_assume(sec_r000187_2 >= 0 && sec_r000187_2 <= 255);
    __CPROVER_assume(sec_r000187_3 >= 0 && sec_r000187_3 <= 255);
    __CPROVER_assume(sec_r000187_4 >= 0 && sec_r000187_4 <= 255);
    __CPROVER_assume(sec_r000187_5 >= 0 && sec_r000187_5 <= 255);
    __CPROVER_assume(sec_r000187_6 >= 0 && sec_r000187_6 <= 255);
    __CPROVER_assume(sec_r000187_7 >= 0 && sec_r000187_7 <= 255);
    __CPROVER_assume(sec_r000187_8 >= 0 && sec_r000187_8 <= 255);
    __CPROVER_assume(sec_r000187_9 >= 0 && sec_r000187_9 <= 255);
    __CPROVER_assume(sec_r000187_10 >= 0 && sec_r000187_10 <= 255);
    __CPROVER_assume(sec_r000187_11 >= 0 && sec_r000187_11 <= 255);
    __CPROVER_assume(sec_r000187_12 >= 0 && sec_r000187_12 <= 255);
    __CPROVER_assume(sec_r000187_13 >= 0 && sec_r000187_13 <= 255);
    __CPROVER_assume(sec_r000187_14 >= 0 && sec_r000187_14 <= 255);
    __CPROVER_assume(sec_r000187_15 >= 0 && sec_r000187_15 <= 255);
    __CPROVER_assume(sec_r000187_16 >= 0 && sec_r000187_16 <= 255);
    __CPROVER_assume(sec_r000187_17 >= 0 && sec_r000187_17 <= 255);
    __CPROVER_assume(sec_r000187_18 >= 0 && sec_r000187_18 <= 255);

    struct Vector3D_R000187_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000187_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000187_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000187_0 + 7) & 15;
    struct CipherContext_R000187_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000187_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000187_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000187_0 + 9) & 15;

    union PacketPayload_R000187_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 14) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 29) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 16) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 31) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 18) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 33) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 35) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 50) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 29) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 44) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 35) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 50) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000187_5 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_48 = (pub_r000187_8 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000187_8 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000187_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000187_5 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_49 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000187_10 & 2) != 0) {
            stage_v_50 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000187_11 & 1) != 0) {
        if ((sec_r000187_13 & 2) != 0) {
            stage_v_51 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000187_13 & 2) != 0) {
            stage_v_52 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_12 & 2) != 0) {
            stage_v_53 = (pub_r000187_0 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000187_0 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000187_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000187_0 & 2) != 0) {
            stage_v_54 = (pub_r000187_14 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000187_14 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000187_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000187_15 & 2) != 0) {
            stage_v_55 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000187_15 & 1) != 0) {
        if ((sec_r000187_18 & 2) != 0) {
            stage_v_56 = (pub_r000187_4 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000187_4 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000187_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000187_7 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_57 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000187_12 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_58 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000187_0 & 2) != 0) {
            stage_v_59 = (pub_r000187_14 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000187_14 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000187_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000187_14 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_60 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000187_18 & 1) != 0) {
        if ((sec_r000187_1 & 2) != 0) {
            stage_v_61 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_62 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000187_12 & 2) != 0) {
            stage_v_63 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_64 = (pub_r000187_2 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000187_2 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000187_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000187_6 & 2) != 0) {
            stage_v_65 = (pub_r000187_13 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000187_13 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000187_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_66 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_16 & 2) != 0) {
            stage_v_67 = (pub_r000187_7 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000187_7 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000187_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_68 = (pub_r000187_7 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000187_7 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000187_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_69 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000187_12 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_70 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000187_9 & 1) != 0) {
        if ((sec_r000187_16 & 2) != 0) {
            stage_v_71 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000187_12 & 2) != 0) {
            stage_v_72 = (pub_r000187_7 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000187_7 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000187_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000187_5 & 1) != 0) {
        if ((sec_r000187_1 & 2) != 0) {
            stage_v_73 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000187_2 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_74 = (pub_r000187_3 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000187_3 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000187_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_75 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000187_14 & 1) != 0) {
        if ((sec_r000187_11 & 2) != 0) {
            stage_v_76 = (pub_r000187_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000187_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000187_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_77 = (pub_r000187_13 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000187_13 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000187_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_78 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_79 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_80 = (pub_r000187_14 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000187_14 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000187_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_81 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_82 = (pub_r000187_8 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000187_8 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000187_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000187_15 & 2) != 0) {
            stage_v_83 = (pub_r000187_4 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000187_4 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000187_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_84 = (pub_r000187_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000187_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000187_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000187_0 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_85 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_86 = (pub_r000187_4 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000187_4 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000187_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000187_16 & 2) != 0) {
            stage_v_87 = (pub_r000187_13 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000187_13 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000187_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_88 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000187_6 & 2) != 0) {
            stage_v_89 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_90 = (pub_r000187_4 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000187_4 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000187_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000187_4 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_91 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_92 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000187_9 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_93 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000187_4 & 1) != 0) {
        if ((sec_r000187_2 & 2) != 0) {
            stage_v_94 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000187_4 & 1) != 0) {
        if ((sec_r000187_6 & 2) != 0) {
            stage_v_95 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000187_15 & 2) != 0) {
            stage_v_96 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000187_18 & 2) != 0) {
            stage_v_97 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_98 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000187_1 & 2) != 0) {
            stage_v_99 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000187_0 & 1) != 0) {
        if ((sec_r000187_1 & 2) != 0) {
            stage_v_100 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000187_18 & 2) != 0) {
            stage_v_101 = (pub_r000187_4 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000187_4 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000187_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_102 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000187_8 & 1) != 0) {
        if ((sec_r000187_2 & 2) != 0) {
            stage_v_103 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000187_2 & 2) != 0) {
            stage_v_104 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000187_11 & 2) != 0) {
            stage_v_105 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_106 = (pub_r000187_2 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000187_2 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000187_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_107 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000187_6 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_108 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000187_15 & 2) != 0) {
            stage_v_109 = (pub_r000187_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000187_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000187_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000187_14 & 2) != 0) {
            stage_v_110 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000187_9 & 1) != 0) {
        if ((sec_r000187_12 & 2) != 0) {
            stage_v_111 = (pub_r000187_3 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000187_3 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000187_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000187_2 & 2) != 0) {
            stage_v_112 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_113 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_114 = (pub_r000187_2 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000187_2 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000187_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_115 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_116 = (pub_r000187_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000187_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000187_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_117 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000187_11 & 1) != 0) {
        if ((sec_r000187_9 & 2) != 0) {
            stage_v_118 = (pub_r000187_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000187_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000187_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000187_16 & 1) != 0) {
        if ((sec_r000187_17 & 2) != 0) {
            stage_v_119 = (pub_r000187_1 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000187_1 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000187_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000187_15 & 2) != 0) {
            stage_v_120 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000187_0 & 2) != 0) {
            stage_v_121 = (pub_r000187_13 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000187_13 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000187_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_122 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000187_1 & 1) != 0) {
        if ((sec_r000187_14 & 2) != 0) {
            stage_v_123 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000187_13 & 2) != 0) {
            stage_v_124 = (pub_r000187_8 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000187_8 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000187_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000187_18 & 2) != 0) {
            stage_v_125 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_126 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000187_4 & 2) != 0) {
            stage_v_127 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000187_10 & 2) != 0) {
            stage_v_128 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000187_10 & 2) != 0) {
            stage_v_129 = (pub_r000187_11 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000187_11 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000187_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000187_10 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_130 = (pub_r000187_8 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000187_8 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000187_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000187_8 & 2) != 0) {
            stage_v_131 = (pub_r000187_7 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000187_7 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000187_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_132 = (pub_r000187_3 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000187_3 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000187_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000187_4 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_133 = (pub_r000187_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000187_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000187_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000187_16 & 1) != 0) {
        if ((sec_r000187_14 & 2) != 0) {
            stage_v_134 = (pub_r000187_15 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000187_15 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000187_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000187_7 & 2) != 0) {
            stage_v_135 = (pub_r000187_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000187_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000187_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000187_13 & 2) != 0) {
            stage_v_136 = (pub_r000187_10 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000187_10 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000187_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000187_3 & 2) != 0) {
            stage_v_137 = (pub_r000187_5 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000187_5 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000187_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000187_11 & 2) != 0) {
            stage_v_138 = (pub_r000187_2 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000187_2 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000187_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000187_1 & 2) != 0) {
            stage_v_139 = (pub_r000187_16 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000187_16 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000187_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000187_1 & 1) != 0) {
        if ((sec_r000187_5 & 2) != 0) {
            stage_v_140 = (pub_r000187_9 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000187_9 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000187_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
