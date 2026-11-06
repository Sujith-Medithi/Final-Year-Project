/*
 * Benchmark Program: R000977
 * Security Family: nested_implicit_flow
 * Generator Seed: 597713
 * High Inputs: 22 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000977_7713_0 {
    short channels;
    unsigned char gain;
    int peak;
    int buffer[3];
};

struct FilterState_R000977_7713_1 {
    unsigned char mode;
    short damping;
    unsigned char gain_db;
    int prev_out;
    int prev_in;
    short cutoff;
    int buffer[3];
};

union PacketPayload_R000977_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000977_7713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000977_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int sample_78 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_78 > 14) {
        acc = (acc + sample_78 * 2 + 5) & 127;
        aux ^= (sample_78 & 15);
    } else {
        acc = (acc - sample_78 + 11) & 127;
        aux += 3;
    }
    int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_80 = (aux + st.buffer[1]) & 3;
    switch (parity_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000977_7713_1(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_90 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_90 > 44) {
        acc = (acc + damping_90 * 2 + 5) & 127;
        aux ^= (damping_90 & 15);
    } else {
        acc = (acc - damping_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000977_7713_2(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int segment_41 = local_arr[aux % 3];
    acc = (acc + segment_41 * 2) & 127;
    int vector_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_90 = (aux + st.buffer[1]) & 3;
    switch (threshold_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000977_7713_3(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int stride_90 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_90 > 24) {
        acc = (acc + stride_90 * 2 + 5) & 127;
        aux ^= (stride_90 & 15);
    } else {
        acc = (acc - stride_90 + 11) & 127;
        aux += 3;
    }
    int quantum_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_69) & 63;
    acc ^= aux;
    int segment_32 = (aux + st.buffer[1]) & 3;
    switch (segment_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_86 = local_arr[aux % 3];
    acc = (acc + bound_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_89 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_89 > 42) {
        acc = (acc + pivot_89 * 2 + 5) & 127;
        aux ^= (pivot_89 & 15);
    } else {
        acc = (acc - pivot_89 + 11) & 127;
        aux += 3;
    }
    int factor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int tally_16 = local_arr[aux % 3];
    acc = (acc + tally_16 * 2) & 127;
    int threshold_24 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_24 > 35) {
        acc = (acc + threshold_24 * 2 + 5) & 127;
        aux ^= (threshold_24 & 15);
    } else {
        acc = (acc - threshold_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000977_7713_7(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int quotient_41 = local_arr[aux % 3];
    acc = (acc + quotient_41 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int index_reg_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_99 = local_arr[aux % 3];
    acc = (acc + tally_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_80) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_48 = local_arr[aux % 3];
    acc = (acc + factor_48 * 2) & 127;
    int parity_96 = (aux + st.buffer[1]) & 3;
    switch (parity_96) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_11(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int parity_41 = local_arr[aux % 3];
    acc = (acc + parity_41 * 2) & 127;
    int quantum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_12(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int factor_51 = (aux + st.buffer[1]) & 3;
    switch (factor_51) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_18 = local_arr[aux % 3];
    acc = (acc + checksum_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int coefficient_87 = local_arr[aux % 3];
    acc = (acc + coefficient_87 * 2) & 127;
    int delta_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_23) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_98 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_98 > 29) {
        acc = (acc + sample_98 * 2 + 5) & 127;
        aux ^= (sample_98 & 15);
    } else {
        acc = (acc - sample_98 + 11) & 127;
        aux += 3;
    }
    int accumulator_25 = (aux + st.buffer[1]) & 3;
    switch (accumulator_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int pivot_66 = (aux + st.buffer[1]) & 3;
    switch (pivot_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_12 = local_arr[aux % 3];
    acc = (acc + tracker_12 * 2) & 127;
    int mask_64 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_64 > 46) {
        acc = (acc + mask_64 * 2 + 5) & 127;
        aux ^= (mask_64 & 15);
    } else {
        acc = (acc - mask_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000977_7713_16(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000977_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int scale_12 = local_arr[aux % 3];
    acc = (acc + scale_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = (aux + st.buffer[1]) & 3;
    switch (tally_80) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_17(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_73 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_73 > 10) {
        acc = (acc + phase_73 * 2 + 5) & 127;
        aux ^= (phase_73 & 15);
    } else {
        acc = (acc - phase_73 + 11) & 127;
        aux += 3;
    }
    int anchor_23 = (aux + st.buffer[1]) & 3;
    switch (anchor_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000977_7713_18(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000977_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int scale_10 = (aux + st.buffer[1]) & 3;
    switch (scale_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_73 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_73 > 28) {
        acc = (acc + quantum_73 * 2 + 5) & 127;
        aux ^= (quantum_73 & 15);
    } else {
        acc = (acc - quantum_73 + 11) & 127;
        aux += 3;
    }
    int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_56) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000977_0;
    int sec_r000977_1;
    int sec_r000977_2;
    int sec_r000977_3;
    int sec_r000977_4;
    int sec_r000977_5;
    int sec_r000977_6;
    int sec_r000977_7;
    int sec_r000977_8;
    int sec_r000977_9;
    int sec_r000977_10;
    int sec_r000977_11;
    int sec_r000977_12;
    int sec_r000977_13;
    int sec_r000977_14;
    int sec_r000977_15;
    int sec_r000977_16;
    int sec_r000977_17;
    int sec_r000977_18;
    int sec_r000977_19;
    int sec_r000977_20;
    int sec_r000977_21;
    int pub_r000977_0;
    int pub_r000977_1;
    int pub_r000977_2;
    int pub_r000977_3;
    int pub_r000977_4;
    int pub_r000977_5;
    int pub_r000977_6;
    int pub_r000977_7;
    int pub_r000977_8;
    int pub_r000977_9;
    int pub_r000977_10;
    int pub_r000977_11;
    int pub_r000977_12;
    int pub_r000977_13;
    int pub_r000977_14;
    int pub_r000977_15;
    int pub_r000977_16;
    int pub_r000977_17;
    int pub_r000977_18;
    int pub_r000977_19;
    int pub_r000977_20;
    int pub_r000977_21;
    int pub_r000977_22;
    int pub_r000977_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000977_0 >= -100 && pub_r000977_0 <= 100);
    __CPROVER_assume(pub_r000977_1 >= -100 && pub_r000977_1 <= 100);
    __CPROVER_assume(pub_r000977_2 >= -100 && pub_r000977_2 <= 100);
    __CPROVER_assume(pub_r000977_3 >= -100 && pub_r000977_3 <= 100);
    __CPROVER_assume(pub_r000977_4 >= -100 && pub_r000977_4 <= 100);
    __CPROVER_assume(pub_r000977_5 >= -100 && pub_r000977_5 <= 100);
    __CPROVER_assume(pub_r000977_6 >= -100 && pub_r000977_6 <= 100);
    __CPROVER_assume(pub_r000977_7 >= -100 && pub_r000977_7 <= 100);
    __CPROVER_assume(pub_r000977_8 >= -100 && pub_r000977_8 <= 100);
    __CPROVER_assume(pub_r000977_9 >= -100 && pub_r000977_9 <= 100);
    __CPROVER_assume(pub_r000977_10 >= -100 && pub_r000977_10 <= 100);
    __CPROVER_assume(pub_r000977_11 >= -100 && pub_r000977_11 <= 100);
    __CPROVER_assume(pub_r000977_12 >= -100 && pub_r000977_12 <= 100);
    __CPROVER_assume(pub_r000977_13 >= -100 && pub_r000977_13 <= 100);
    __CPROVER_assume(pub_r000977_14 >= -100 && pub_r000977_14 <= 100);
    __CPROVER_assume(pub_r000977_15 >= -100 && pub_r000977_15 <= 100);
    __CPROVER_assume(pub_r000977_16 >= -100 && pub_r000977_16 <= 100);
    __CPROVER_assume(pub_r000977_17 >= -100 && pub_r000977_17 <= 100);
    __CPROVER_assume(pub_r000977_18 >= -100 && pub_r000977_18 <= 100);
    __CPROVER_assume(pub_r000977_19 >= -100 && pub_r000977_19 <= 100);
    __CPROVER_assume(pub_r000977_20 >= -100 && pub_r000977_20 <= 100);
    __CPROVER_assume(pub_r000977_21 >= -100 && pub_r000977_21 <= 100);
    __CPROVER_assume(pub_r000977_22 >= -100 && pub_r000977_22 <= 100);
    __CPROVER_assume(pub_r000977_23 >= -100 && pub_r000977_23 <= 100);
    __CPROVER_assume(sec_r000977_0 >= 0 && sec_r000977_0 <= 255);
    __CPROVER_assume(sec_r000977_1 >= 0 && sec_r000977_1 <= 255);
    __CPROVER_assume(sec_r000977_2 >= 0 && sec_r000977_2 <= 255);
    __CPROVER_assume(sec_r000977_3 >= 0 && sec_r000977_3 <= 255);
    __CPROVER_assume(sec_r000977_4 >= 0 && sec_r000977_4 <= 255);
    __CPROVER_assume(sec_r000977_5 >= 0 && sec_r000977_5 <= 255);
    __CPROVER_assume(sec_r000977_6 >= 0 && sec_r000977_6 <= 255);
    __CPROVER_assume(sec_r000977_7 >= 0 && sec_r000977_7 <= 255);
    __CPROVER_assume(sec_r000977_8 >= 0 && sec_r000977_8 <= 255);
    __CPROVER_assume(sec_r000977_9 >= 0 && sec_r000977_9 <= 255);
    __CPROVER_assume(sec_r000977_10 >= 0 && sec_r000977_10 <= 255);
    __CPROVER_assume(sec_r000977_11 >= 0 && sec_r000977_11 <= 255);
    __CPROVER_assume(sec_r000977_12 >= 0 && sec_r000977_12 <= 255);
    __CPROVER_assume(sec_r000977_13 >= 0 && sec_r000977_13 <= 255);
    __CPROVER_assume(sec_r000977_14 >= 0 && sec_r000977_14 <= 255);
    __CPROVER_assume(sec_r000977_15 >= 0 && sec_r000977_15 <= 255);
    __CPROVER_assume(sec_r000977_16 >= 0 && sec_r000977_16 <= 255);
    __CPROVER_assume(sec_r000977_17 >= 0 && sec_r000977_17 <= 255);
    __CPROVER_assume(sec_r000977_18 >= 0 && sec_r000977_18 <= 255);
    __CPROVER_assume(sec_r000977_19 >= 0 && sec_r000977_19 <= 255);
    __CPROVER_assume(sec_r000977_20 >= 0 && sec_r000977_20 <= 255);
    __CPROVER_assume(sec_r000977_21 >= 0 && sec_r000977_21 <= 255);

    struct AudioFrame_R000977_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000977_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000977_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000977_0 + 7) & 15;
    struct FilterState_R000977_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000977_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000977_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000977_0 + 9) & 15;

    union PacketPayload_R000977_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 51) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 30) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 45) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 10) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 25) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

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
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 39) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 54) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 28) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 43) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((sec_r000977_14 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_33 = (pub_r000977_21 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000977_21 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000977_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_12 & 2) != 0) {
            stage_v_34 = (pub_r000977_7 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000977_7 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000977_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_1 & 2) != 0) {
            stage_v_35 = (pub_r000977_3 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000977_3 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000977_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((sec_r000977_2 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_36 = (pub_r000977_20 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000977_20 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000977_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000977_18 & 2) != 0) {
            stage_v_37 = (pub_r000977_3 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000977_3 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000977_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000977_0 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_38 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_39 = (pub_r000977_7 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000977_7 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000977_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000977_5 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_40 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000977_13 & 1) != 0) {
        if ((sec_r000977_4 & 2) != 0) {
            stage_v_41 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_42 = (pub_r000977_19 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000977_19 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000977_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000977_3 & 2) != 0) {
            stage_v_43 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000977_18 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_44 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000977_12 & 2) != 0) {
            stage_v_45 = (pub_r000977_6 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000977_6 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000977_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000977_9 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_46 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000977_1 & 2) != 0) {
            stage_v_47 = (pub_r000977_22 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000977_22 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000977_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000977_1 & 2) != 0) {
            stage_v_48 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000977_16 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_49 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000977_10 & 1) != 0) {
        if ((sec_r000977_0 & 2) != 0) {
            stage_v_50 = (pub_r000977_1 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000977_1 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000977_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_51 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000977_20 & 1) != 0) {
        if ((sec_r000977_18 & 2) != 0) {
            stage_v_52 = (pub_r000977_1 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000977_1 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000977_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000977_12 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_53 = (pub_r000977_3 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000977_3 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000977_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_54 = (pub_r000977_8 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000977_8 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000977_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000977_4 & 2) != 0) {
            stage_v_55 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000977_18 & 1) != 0) {
        if ((sec_r000977_17 & 2) != 0) {
            stage_v_56 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000977_3 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_57 = (pub_r000977_8 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000977_8 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000977_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000977_11 & 2) != 0) {
            stage_v_58 = (pub_r000977_3 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000977_3 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000977_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_59 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000977_10 & 1) != 0) {
        if ((sec_r000977_17 & 2) != 0) {
            stage_v_60 = (pub_r000977_7 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000977_7 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000977_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000977_12 & 1) != 0) {
        if ((sec_r000977_12 & 2) != 0) {
            stage_v_61 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_62 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000977_5 & 2) != 0) {
            stage_v_63 = (pub_r000977_1 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000977_1 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000977_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000977_7 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_64 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000977_17 & 2) != 0) {
            stage_v_65 = (pub_r000977_3 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000977_3 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000977_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000977_18 & 1) != 0) {
        if ((sec_r000977_11 & 2) != 0) {
            stage_v_66 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000977_3 & 2) != 0) {
            stage_v_67 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_68 = (pub_r000977_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000977_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000977_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_17 & 2) != 0) {
            stage_v_69 = (pub_r000977_0 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000977_0 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000977_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_70 = (pub_r000977_21 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000977_21 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000977_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000977_2 & 2) != 0) {
            stage_v_71 = (pub_r000977_13 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000977_13 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000977_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_72 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000977_0 & 2) != 0) {
            stage_v_73 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000977_16 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_74 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_75 = (pub_r000977_9 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000977_9 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000977_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000977_9 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_76 = (pub_r000977_9 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000977_9 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000977_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000977_2 & 2) != 0) {
            stage_v_77 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000977_14 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_78 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000977_2 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_79 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_80 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000977_16 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_81 = (pub_r000977_19 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000977_19 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000977_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000977_10 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_82 = (pub_r000977_21 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000977_21 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000977_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_83 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000977_5 & 2) != 0) {
            stage_v_84 = (pub_r000977_19 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000977_19 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000977_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000977_1 & 2) != 0) {
            stage_v_85 = (pub_r000977_13 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000977_13 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000977_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000977_21 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_86 = (pub_r000977_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000977_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000977_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000977_9 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_87 = (pub_r000977_22 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000977_22 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000977_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_88 = (pub_r000977_7 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000977_7 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000977_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_89 = (pub_r000977_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000977_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000977_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000977_14 & 1) != 0) {
        if ((sec_r000977_4 & 2) != 0) {
            stage_v_90 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_91 = (pub_r000977_7 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000977_7 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000977_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000977_12 & 2) != 0) {
            stage_v_92 = (pub_r000977_22 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000977_22 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000977_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_93 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_94 = (pub_r000977_12 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000977_12 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000977_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000977_15 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_95 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000977_16 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_96 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_97 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_98 = (pub_r000977_0 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000977_0 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000977_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_99 = (pub_r000977_20 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000977_20 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000977_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_100 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000977_18 & 2) != 0) {
            stage_v_101 = (pub_r000977_20 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000977_20 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000977_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000977_5 & 1) != 0) {
        if ((sec_r000977_17 & 2) != 0) {
            stage_v_102 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000977_0 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_103 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_104 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000977_2 & 1) != 0) {
        if ((sec_r000977_4 & 2) != 0) {
            stage_v_105 = (pub_r000977_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000977_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000977_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000977_2 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_106 = (pub_r000977_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000977_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000977_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_107 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_108 = (pub_r000977_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000977_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000977_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_109 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000977_5 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_110 = (pub_r000977_12 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000977_12 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000977_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000977_4 & 2) != 0) {
            stage_v_111 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000977_6 & 2) != 0) {
            stage_v_112 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_113 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_114 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000977_11 & 2) != 0) {
            stage_v_115 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_116 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000977_9 & 2) != 0) {
            stage_v_117 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_118 = (pub_r000977_19 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000977_19 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000977_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000977_2 & 1) != 0) {
        if ((sec_r000977_5 & 2) != 0) {
            stage_v_119 = (pub_r000977_10 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000977_10 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000977_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000977_0 & 2) != 0) {
            stage_v_120 = (pub_r000977_8 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000977_8 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000977_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000977_12 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_121 = (pub_r000977_10 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000977_10 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000977_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_122 = (pub_r000977_14 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000977_14 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000977_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000977_11 & 2) != 0) {
            stage_v_123 = (pub_r000977_0 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000977_0 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000977_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000977_21 & 2) != 0) {
            stage_v_124 = (pub_r000977_10 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000977_10 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000977_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_125 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000977_16 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_126 = (pub_r000977_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000977_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000977_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_127 = (pub_r000977_9 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000977_9 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000977_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000977_21 & 1) != 0) {
        if ((sec_r000977_7 & 2) != 0) {
            stage_v_128 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000977_5 & 2) != 0) {
            stage_v_129 = (pub_r000977_22 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000977_22 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000977_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000977_8 & 1) != 0) {
        if ((sec_r000977_18 & 2) != 0) {
            stage_v_130 = (pub_r000977_9 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000977_9 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000977_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000977_9 & 1) != 0) {
        if ((sec_r000977_16 & 2) != 0) {
            stage_v_131 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000977_13 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_132 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000977_3 & 2) != 0) {
            stage_v_133 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000977_11 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_134 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000977_11 & 1) != 0) {
        if ((sec_r000977_15 & 2) != 0) {
            stage_v_135 = (pub_r000977_16 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000977_16 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000977_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000977_9 & 1) != 0) {
        if ((sec_r000977_2 & 2) != 0) {
            stage_v_136 = (pub_r000977_12 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000977_12 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000977_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_137 = (pub_r000977_4 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000977_4 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000977_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000977_20 & 1) != 0) {
        if ((sec_r000977_20 & 2) != 0) {
            stage_v_138 = (pub_r000977_1 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000977_1 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000977_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000977_7 & 2) != 0) {
            stage_v_139 = (pub_r000977_12 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000977_12 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000977_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_139 & 1) != 0) {
        if ((sec_r000977_1 & 2) != 0) {
            stage_v_140 = (pub_r000977_5 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000977_5 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000977_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000977_0 & 2) != 0) {
            stage_v_141 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000977_7 & 2) != 0) {
            stage_v_142 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000977_21 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_143 = (pub_r000977_19 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000977_19 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000977_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000977_12 & 2) != 0) {
            stage_v_144 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000977_5 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_145 = (pub_r000977_18 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000977_18 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000977_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000977_13 & 2) != 0) {
            stage_v_146 = (pub_r000977_21 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000977_21 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000977_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000977_8 & 2) != 0) {
            stage_v_147 = (pub_r000977_17 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000977_17 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000977_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000977_10 & 1) != 0) {
        if ((sec_r000977_14 & 2) != 0) {
            stage_v_148 = (pub_r000977_23 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000977_23 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000977_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r000977_19 & 2) != 0) {
            stage_v_149 = (pub_r000977_13 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000977_13 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000977_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000977_5 & 2) != 0) {
            stage_v_150 = (pub_r000977_2 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000977_2 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000977_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
