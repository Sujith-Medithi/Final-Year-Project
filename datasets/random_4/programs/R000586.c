/*
 * Benchmark Program: R000586
 * Family: implicit_flow
 * Generator Seed: 458613
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000586_8613_0 {
    short fee;
    int status;
    short account_id;
    int auth_code;
    int buffer[3];
};

struct MatrixBlock_R000586_8613_1 {
    int density;
    int dim;
    int scale;
    unsigned char stride;
    short trace;
    int determinant;
    int buffer[3];
};

union PacketPayload_R000586_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000586_8613_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_99) & 63;
    acc ^= aux;
    int mask_47 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_47 > 21) {
        acc = (acc + mask_47 * 2 + 5) & 127;
        aux ^= (mask_47 & 15);
    } else {
        acc = (acc - mask_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int damping_40 = local_arr[aux % 3];
    acc = (acc + damping_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_40 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_40 > 13) {
        acc = (acc + parity_40 * 2 + 5) & 127;
        aux ^= (parity_40 & 15);
    } else {
        acc = (acc - parity_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_2(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_77) & 63;
    acc ^= aux;
    int quantum_80 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_80 > 24) {
        acc = (acc + quantum_80 * 2 + 5) & 127;
        aux ^= (quantum_80 & 15);
    } else {
        acc = (acc - quantum_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_48 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_48 > 50) {
        acc = (acc + factor_48 * 2 + 5) & 127;
        aux ^= (factor_48 & 15);
    } else {
        acc = (acc - factor_48 + 11) & 127;
        aux += 3;
    }
    int stride_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000586_8613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_26 = (aux + st.buffer[1]) & 3;
    switch (offset_26) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_78 = 0;
    for (int k = 0; k < 3; k++) {
        factor_78 = (factor_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_78) & 127;
    }
    int factor_67 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_67 > 33) {
        acc = (acc + factor_67 * 2 + 5) & 127;
        aux ^= (factor_67 & 15);
    } else {
        acc = (acc - factor_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_51) & 63;
    acc ^= aux;
    int phase_79 = 0;
    for (int k = 0; k < 2; k++) {
        phase_79 = (phase_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_79) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_6(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int anchor_32 = local_arr[aux % 3];
    acc = (acc + anchor_32 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_57 = (aux + st.buffer[1]) & 3;
    switch (cursor_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_67 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_67 > 43) {
        acc = (acc + bound_67 * 2 + 5) & 127;
        aux ^= (bound_67 & 15);
    } else {
        acc = (acc - bound_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_20) & 63;
    acc ^= aux;
    int tracker_70 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_70 > 45) {
        acc = (acc + tracker_70 * 2 + 5) & 127;
        aux ^= (tracker_70 & 15);
    } else {
        acc = (acc - tracker_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int residue_80 = (aux + st.buffer[1]) & 3;
    switch (residue_80) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000586_8613_9(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int threshold_15 = local_arr[aux % 3];
    acc = (acc + threshold_15 * 2) & 127;
    int tracker_99 = (aux + st.buffer[1]) & 3;
    switch (tracker_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_89 = (aux + st.buffer[1]) & 3;
    switch (bound_89) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_21 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_21 = (pivot_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_21) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_26 = local_arr[aux % 3];
    acc = (acc + factor_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000586_8613_11(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int metric_83 = (aux + st.buffer[1]) & 3;
    switch (metric_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000586_8613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int parity_28 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_28 > 37) {
        acc = (acc + parity_28 * 2 + 5) & 127;
        aux ^= (parity_28 & 15);
    } else {
        acc = (acc - parity_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_99 = local_arr[aux % 3];
    acc = (acc + window_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000586_8613_13(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int index_reg_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_48) & 63;
    acc ^= aux;
    int quotient_98 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_98 = (quotient_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_98) & 127;
    }
    int scale_86 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_86 > 43) {
        acc = (acc + scale_86 * 2 + 5) & 127;
        aux ^= (scale_86 & 15);
    } else {
        acc = (acc - scale_86 + 11) & 127;
        aux += 3;
    }
    int anchor_70 = (aux + st.buffer[1]) & 3;
    switch (anchor_70) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_69 = 0;
    for (int k = 0; k < 3; k++) {
        bound_69 = (bound_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_69) & 127;
    }
    int sample_28 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_28 > 32) {
        acc = (acc + sample_28 * 2 + 5) & 127;
        aux ^= (sample_28 & 15);
    } else {
        acc = (acc - sample_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000586_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int offset_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_24) & 63;
    acc ^= aux;
    int phase_47 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_47 > 50) {
        acc = (acc + phase_47 * 2 + 5) & 127;
        aux ^= (phase_47 & 15);
    } else {
        acc = (acc - phase_47 + 11) & 127;
        aux += 3;
    }
    int quotient_68 = (aux + st.buffer[1]) & 3;
    switch (quotient_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_33 = local_arr[aux % 3];
    acc = (acc + mask_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000586_8613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_18 = 0;
    for (int k = 0; k < 2; k++) {
        phase_18 = (phase_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_18) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_19 = (aux + st.buffer[1]) & 3;
    switch (tracker_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000586_8613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_75 = (aux + st.buffer[1]) & 3;
    switch (tally_75) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_12 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_12 = (threshold_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_12) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_37 = local_arr[aux % 3];
    acc = (acc + mask_37 * 2) & 127;
    int damping_68 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_68 > 16) {
        acc = (acc + damping_68 * 2 + 5) & 127;
        aux ^= (damping_68 & 15);
    } else {
        acc = (acc - damping_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000586_8613_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000586_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_23 = (aux + st.buffer[1]) & 3;
    switch (margin_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_94 = local_arr[aux % 3];
    acc = (acc + bound_94 * 2) & 127;
    int factor_22 = 0;
    for (int k = 0; k < 2; k++) {
        factor_22 = (factor_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_22) & 127;
    }
    int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000586_0;
    int sec_r000586_1;
    int sec_r000586_2;
    int sec_r000586_3;
    int sec_r000586_4;
    int sec_r000586_5;
    int sec_r000586_6;
    int sec_r000586_7;
    int sec_r000586_8;
    int sec_r000586_9;
    int sec_r000586_10;
    int sec_r000586_11;
    int sec_r000586_12;
    int sec_r000586_13;
    int sec_r000586_14;
    int sec_r000586_15;
    int pub_r000586_0;
    int pub_r000586_1;
    int pub_r000586_2;
    int pub_r000586_3;
    int pub_r000586_4;
    int pub_r000586_5;
    int pub_r000586_6;
    int pub_r000586_7;
    int pub_r000586_8;
    int pub_r000586_9;
    int pub_r000586_10;
    int pub_r000586_11;
    int pub_r000586_12;
    int pub_r000586_13;
    int pub_r000586_14;
    int pub_r000586_15;
    int pub_r000586_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000586_0 >= -100 && pub_r000586_0 <= 100);
    __CPROVER_assume(pub_r000586_1 >= -100 && pub_r000586_1 <= 100);
    __CPROVER_assume(pub_r000586_2 >= -100 && pub_r000586_2 <= 100);
    __CPROVER_assume(pub_r000586_3 >= -100 && pub_r000586_3 <= 100);
    __CPROVER_assume(pub_r000586_4 >= -100 && pub_r000586_4 <= 100);
    __CPROVER_assume(pub_r000586_5 >= -100 && pub_r000586_5 <= 100);
    __CPROVER_assume(pub_r000586_6 >= -100 && pub_r000586_6 <= 100);
    __CPROVER_assume(pub_r000586_7 >= -100 && pub_r000586_7 <= 100);
    __CPROVER_assume(pub_r000586_8 >= -100 && pub_r000586_8 <= 100);
    __CPROVER_assume(pub_r000586_9 >= -100 && pub_r000586_9 <= 100);
    __CPROVER_assume(pub_r000586_10 >= -100 && pub_r000586_10 <= 100);
    __CPROVER_assume(pub_r000586_11 >= -100 && pub_r000586_11 <= 100);
    __CPROVER_assume(pub_r000586_12 >= -100 && pub_r000586_12 <= 100);
    __CPROVER_assume(pub_r000586_13 >= -100 && pub_r000586_13 <= 100);
    __CPROVER_assume(pub_r000586_14 >= -100 && pub_r000586_14 <= 100);
    __CPROVER_assume(pub_r000586_15 >= -100 && pub_r000586_15 <= 100);
    __CPROVER_assume(pub_r000586_16 >= -100 && pub_r000586_16 <= 100);
    __CPROVER_assume(sec_r000586_0 >= 0 && sec_r000586_0 <= 255);
    __CPROVER_assume(sec_r000586_1 >= 0 && sec_r000586_1 <= 255);
    __CPROVER_assume(sec_r000586_2 >= 0 && sec_r000586_2 <= 255);
    __CPROVER_assume(sec_r000586_3 >= 0 && sec_r000586_3 <= 255);
    __CPROVER_assume(sec_r000586_4 >= 0 && sec_r000586_4 <= 255);
    __CPROVER_assume(sec_r000586_5 >= 0 && sec_r000586_5 <= 255);
    __CPROVER_assume(sec_r000586_6 >= 0 && sec_r000586_6 <= 255);
    __CPROVER_assume(sec_r000586_7 >= 0 && sec_r000586_7 <= 255);
    __CPROVER_assume(sec_r000586_8 >= 0 && sec_r000586_8 <= 255);
    __CPROVER_assume(sec_r000586_9 >= 0 && sec_r000586_9 <= 255);
    __CPROVER_assume(sec_r000586_10 >= 0 && sec_r000586_10 <= 255);
    __CPROVER_assume(sec_r000586_11 >= 0 && sec_r000586_11 <= 255);
    __CPROVER_assume(sec_r000586_12 >= 0 && sec_r000586_12 <= 255);
    __CPROVER_assume(sec_r000586_13 >= 0 && sec_r000586_13 <= 255);
    __CPROVER_assume(sec_r000586_14 >= 0 && sec_r000586_14 <= 255);
    __CPROVER_assume(sec_r000586_15 >= 0 && sec_r000586_15 <= 255);

    struct Transaction_R000586_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000586_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000586_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000586_0 + 7) & 15;
    struct MatrixBlock_R000586_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000586_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000586_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000586_0 + 9) & 15;

    union PacketPayload_R000586_8613_0 u_var;
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
    if (stage_v_1 > 40) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 55) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 40) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 55) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 27) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 42) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 16) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 31) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 29) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 44) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 22) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 37) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 26) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 41) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 23) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 38) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

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
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 37) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 52) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 10) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 25) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = table[2];
    table[2] = (table[3] + 157) & 63;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 37) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 52) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 16) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 31) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_91 = (stage_v_91 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_0.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 11) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 26) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (out_sink > 100) ? (chk_sum & 31) : (102 & 31);
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= (stage_v_97 << 1) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_101 = (stage_v_101 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 35) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 50) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_1.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 14) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 29) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 17) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 32) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[0] ^ 112) & 3;
    switch (stage_v_109) {
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

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 111 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 30) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 45) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[1] * 2 + 370) & 63;
    if (stage_v_121 > 39) {
        out_sink = (out_sink + stage_v_121 - 5) & 255;
        if (stage_v_121 > 54) {
            chk_sum ^= (stage_v_121 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_121 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_0.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
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

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[0] ^ 127) & 3;
    switch (stage_v_124) {
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

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] ^ 135) & 3;
    switch (stage_v_132) {
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

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_0.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 18) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 33) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_1.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 36) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] ^ 147) & 3;
    switch (stage_v_144) {
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

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 27) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 42) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] ^ 159) & 3;
    switch (stage_v_156) {
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

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 27) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 42) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 162) & 15;
    int stage_v_161 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= stage_v_161;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 25) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 40) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 37) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 52) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_0.buffer[0] ^ 169) & 3;
    switch (stage_v_166) {
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

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 15) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 30) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_1.buffer[0] ^ 174) & 3;
    switch (stage_v_171) {
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

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = table[2];
    table[2] = (table[3] + 349) & 63;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_180 = (stage_v_180 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_180) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_0.buffer[2] * 2 + 553) & 63;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 - 5) & 255;
        if (stage_v_182 > 46) {
            chk_sum ^= (stage_v_182 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_182 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_184 = (stage_v_184 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (out_sink > 100) ? (chk_sum & 31) : (190 & 31);
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= (stage_v_185 << 1) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_186 = (stage_v_186 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_0.buffer[0] ^ 193) & 3;
    switch (stage_v_190) {
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

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_1.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Security Information Flow: Family = implicit_flow */
    if ((sec_r000586_7 & 63) > 29) {
        out_sink += 24;
    } else {
        out_sink -= 51;
    }
    if ((sec_r000586_2 & 63) > 6) {
        out_sink += 18;
    } else {
        out_sink -= 17;
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
