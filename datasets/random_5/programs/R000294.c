/*
 * Benchmark Program: R000294
 * Security Family: arithmetic_flow
 * Generator Seed: 529413
 * High Inputs: 18 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000294_9413_0 {
    short flags;
    short tag;
    short nonce;
    int counter;
    int round_key;
    int buffer[3];
};

struct StreamBuffer_R000294_9413_1 {
    unsigned char checksum;
    short tail;
    int watermark;
    int state;
    int capacity;
    int buffer[3];
};

union TelemetryField_R000294_9413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000294_9413_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_66 = local_arr[aux % 3];
    acc = (acc + mask_66 * 2) & 127;
    int weight_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000294_9413_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int segment_34 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_34 > 16) {
        acc = (acc + segment_34 * 2 + 5) & 127;
        aux ^= (segment_34 & 15);
    } else {
        acc = (acc - segment_34 + 11) & 127;
        aux += 3;
    }
    int vector_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_68) & 63;
    acc ^= aux;
    int metric_21 = (aux + st.buffer[1]) & 3;
    switch (metric_21) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_2(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_61) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_10 = local_arr[aux % 3];
    acc = (acc + delta_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_43 = (aux + st.buffer[1]) & 3;
    switch (margin_43) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_55 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_55 > 43) {
        acc = (acc + damping_55 * 2 + 5) & 127;
        aux ^= (damping_55 & 15);
    } else {
        acc = (acc - damping_55 + 11) & 127;
        aux += 3;
    }
    int damping_18 = (aux + st.buffer[1]) & 3;
    switch (damping_18) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_91 = local_arr[aux % 3];
    acc = (acc + weight_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_4(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_27 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_27 > 34) {
        acc = (acc + scale_27 * 2 + 5) & 127;
        aux ^= (scale_27 & 15);
    } else {
        acc = (acc - scale_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_39 = local_arr[aux % 3];
    acc = (acc + mask_39 * 2) & 127;
    int accumulator_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000294_9413_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_68 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_68 > 49) {
        acc = (acc + tracker_68 * 2 + 5) & 127;
        aux ^= (tracker_68 & 15);
    } else {
        acc = (acc - tracker_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_6(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_29 = local_arr[aux % 3];
    acc = (acc + anchor_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_7(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_42) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_35 = (aux + st.buffer[1]) & 3;
    switch (quantum_35) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_8(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_98 = (aux + st.buffer[1]) & 3;
    switch (metric_98) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_14 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_14 > 15) {
        acc = (acc + stride_14 * 2 + 5) & 127;
        aux ^= (stride_14 & 15);
    } else {
        acc = (acc - stride_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_42 = local_arr[aux % 3];
    acc = (acc + vector_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_9(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_28 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_28 > 42) {
        acc = (acc + mask_28 * 2 + 5) & 127;
        aux ^= (mask_28 & 15);
    } else {
        acc = (acc - mask_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_97 > 19) {
        acc = (acc + quantum_97 * 2 + 5) & 127;
        aux ^= (quantum_97 & 15);
    } else {
        acc = (acc - quantum_97 + 11) & 127;
        aux += 3;
    }
    int quotient_19 = (aux + st.buffer[1]) & 3;
    switch (quotient_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_11(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_34 = (aux + st.buffer[1]) & 3;
    switch (anchor_34) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_37 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_37 > 48) {
        acc = (acc + quotient_37 * 2 + 5) & 127;
        aux ^= (quotient_37 & 15);
    } else {
        acc = (acc - quotient_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_41 = local_arr[aux % 3];
    acc = (acc + index_reg_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int margin_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_57) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_74 = local_arr[aux % 3];
    acc = (acc + accumulator_74 * 2) & 127;
    int anchor_87 = (aux + st.buffer[1]) & 3;
    switch (anchor_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int accumulator_44 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_44 > 42) {
        acc = (acc + accumulator_44 * 2 + 5) & 127;
        aux ^= (accumulator_44 & 15);
    } else {
        acc = (acc - accumulator_44 + 11) & 127;
        aux += 3;
    }
    int damping_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000294_9413_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int offset_36 = local_arr[aux % 3];
    acc = (acc + offset_36 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_52 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_52 > 46) {
        acc = (acc + mask_52 * 2 + 5) & 127;
        aux ^= (mask_52 & 15);
    } else {
        acc = (acc - mask_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_16(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int pivot_80 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_80 > 25) {
        acc = (acc + pivot_80 * 2 + 5) & 127;
        aux ^= (pivot_80 & 15);
    } else {
        acc = (acc - pivot_80 + 11) & 127;
        aux += 3;
    }
    int offset_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_16) & 63;
    acc ^= aux;
    int index_reg_90 = (aux + st.buffer[1]) & 3;
    switch (index_reg_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000294_9413_17(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000294_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_39 = (st.buffer[0] * 3 + aux) & 63;
    if (window_39 > 18) {
        acc = (acc + window_39 * 2 + 5) & 127;
        aux ^= (window_39 & 15);
    } else {
        acc = (acc - window_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_31) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_52 = local_arr[aux % 3];
    acc = (acc + metric_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000294_9413_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000294_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int quantum_36 = local_arr[aux % 3];
    acc = (acc + quantum_36 * 2) & 127;
    int quotient_31 = (aux + st.buffer[1]) & 3;
    switch (quotient_31) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000294_0;
    int sec_r000294_1;
    int sec_r000294_2;
    int sec_r000294_3;
    int sec_r000294_4;
    int sec_r000294_5;
    int sec_r000294_6;
    int sec_r000294_7;
    int sec_r000294_8;
    int sec_r000294_9;
    int sec_r000294_10;
    int sec_r000294_11;
    int sec_r000294_12;
    int sec_r000294_13;
    int sec_r000294_14;
    int sec_r000294_15;
    int sec_r000294_16;
    int sec_r000294_17;
    int pub_r000294_0;
    int pub_r000294_1;
    int pub_r000294_2;
    int pub_r000294_3;
    int pub_r000294_4;
    int pub_r000294_5;
    int pub_r000294_6;
    int pub_r000294_7;
    int pub_r000294_8;
    int pub_r000294_9;
    int pub_r000294_10;
    int pub_r000294_11;
    int pub_r000294_12;
    int pub_r000294_13;
    int pub_r000294_14;
    int pub_r000294_15;
    int pub_r000294_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000294_0 >= -100 && pub_r000294_0 <= 100);
    __CPROVER_assume(pub_r000294_1 >= -100 && pub_r000294_1 <= 100);
    __CPROVER_assume(pub_r000294_2 >= -100 && pub_r000294_2 <= 100);
    __CPROVER_assume(pub_r000294_3 >= -100 && pub_r000294_3 <= 100);
    __CPROVER_assume(pub_r000294_4 >= -100 && pub_r000294_4 <= 100);
    __CPROVER_assume(pub_r000294_5 >= -100 && pub_r000294_5 <= 100);
    __CPROVER_assume(pub_r000294_6 >= -100 && pub_r000294_6 <= 100);
    __CPROVER_assume(pub_r000294_7 >= -100 && pub_r000294_7 <= 100);
    __CPROVER_assume(pub_r000294_8 >= -100 && pub_r000294_8 <= 100);
    __CPROVER_assume(pub_r000294_9 >= -100 && pub_r000294_9 <= 100);
    __CPROVER_assume(pub_r000294_10 >= -100 && pub_r000294_10 <= 100);
    __CPROVER_assume(pub_r000294_11 >= -100 && pub_r000294_11 <= 100);
    __CPROVER_assume(pub_r000294_12 >= -100 && pub_r000294_12 <= 100);
    __CPROVER_assume(pub_r000294_13 >= -100 && pub_r000294_13 <= 100);
    __CPROVER_assume(pub_r000294_14 >= -100 && pub_r000294_14 <= 100);
    __CPROVER_assume(pub_r000294_15 >= -100 && pub_r000294_15 <= 100);
    __CPROVER_assume(pub_r000294_16 >= -100 && pub_r000294_16 <= 100);
    __CPROVER_assume(sec_r000294_0 >= 0 && sec_r000294_0 <= 255);
    __CPROVER_assume(sec_r000294_1 >= 0 && sec_r000294_1 <= 255);
    __CPROVER_assume(sec_r000294_2 >= 0 && sec_r000294_2 <= 255);
    __CPROVER_assume(sec_r000294_3 >= 0 && sec_r000294_3 <= 255);
    __CPROVER_assume(sec_r000294_4 >= 0 && sec_r000294_4 <= 255);
    __CPROVER_assume(sec_r000294_5 >= 0 && sec_r000294_5 <= 255);
    __CPROVER_assume(sec_r000294_6 >= 0 && sec_r000294_6 <= 255);
    __CPROVER_assume(sec_r000294_7 >= 0 && sec_r000294_7 <= 255);
    __CPROVER_assume(sec_r000294_8 >= 0 && sec_r000294_8 <= 255);
    __CPROVER_assume(sec_r000294_9 >= 0 && sec_r000294_9 <= 255);
    __CPROVER_assume(sec_r000294_10 >= 0 && sec_r000294_10 <= 255);
    __CPROVER_assume(sec_r000294_11 >= 0 && sec_r000294_11 <= 255);
    __CPROVER_assume(sec_r000294_12 >= 0 && sec_r000294_12 <= 255);
    __CPROVER_assume(sec_r000294_13 >= 0 && sec_r000294_13 <= 255);
    __CPROVER_assume(sec_r000294_14 >= 0 && sec_r000294_14 <= 255);
    __CPROVER_assume(sec_r000294_15 >= 0 && sec_r000294_15 <= 255);
    __CPROVER_assume(sec_r000294_16 >= 0 && sec_r000294_16 <= 255);
    __CPROVER_assume(sec_r000294_17 >= 0 && sec_r000294_17 <= 255);

    struct CipherContext_R000294_9413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000294_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000294_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000294_0 + 7) & 15;
    struct StreamBuffer_R000294_9413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000294_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000294_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000294_0 + 9) & 15;

    union TelemetryField_R000294_9413_0 u_var;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 12) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 27) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r000294_3 * 3) + (sec_r000294_3 * 2) - pub_r000294_12 + 24) & 127;
    sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_5 * 3) + (sec_r000294_10 * 2) - pub_r000294_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_4 * 3) + (sec_r000294_7 * 2) - pub_r000294_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_5 * 3) + (sec_r000294_4 * 2) - pub_r000294_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_9 * 3) + (sec_r000294_3 * 2) - pub_r000294_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_8 * 3) + (sec_r000294_1 * 2) - pub_r000294_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_10 * 3) + (sec_r000294_5 * 2) - pub_r000294_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_18 * 3) + (sec_r000294_10 * 2) - pub_r000294_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_12 * 3) + (sec_r000294_6 * 2) - pub_r000294_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_16 * 3) + (sec_r000294_10 * 2) - pub_r000294_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_12 * 3) + (sec_r000294_3 * 2) - pub_r000294_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_12 * 3) + (sec_r000294_16 * 2) - pub_r000294_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_22 * 3) + (sec_r000294_0 * 2) - pub_r000294_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r000294_5 * 3) + (sec_r000294_5 * 2) - pub_r000294_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_6 * 3) + (sec_r000294_12 * 2) - pub_r000294_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_18 * 3) + (sec_r000294_4 * 2) - pub_r000294_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_20 * 3) + (sec_r000294_3 * 2) - pub_r000294_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_19 * 3) + (sec_r000294_11 * 2) - pub_r000294_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_22 * 3) + (sec_r000294_7 * 2) - pub_r000294_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_32 * 3) + (sec_r000294_2 * 2) - pub_r000294_5 + 4) & 127;
    sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_25 * 3) + (sec_r000294_4 * 2) - pub_r000294_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_6 * 3) + (sec_r000294_11 * 2) - pub_r000294_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_22 * 3) + (sec_r000294_2 * 2) - pub_r000294_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_20 * 3) + (sec_r000294_10 * 2) - pub_r000294_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_22 * 3) + (sec_r000294_14 * 2) - pub_r000294_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000294_17 * 3) + (sec_r000294_17 * 2) - pub_r000294_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_23 * 3) + (sec_r000294_10 * 2) - pub_r000294_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_35 * 3) + (sec_r000294_10 * 2) - pub_r000294_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_6 * 3) + (sec_r000294_5 * 2) - pub_r000294_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_41 * 3) + (sec_r000294_11 * 2) - pub_r000294_15 + 17) & 127;
    sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_7 * 3) + (sec_r000294_4 * 2) - pub_r000294_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_35 * 3) + (sec_r000294_11 * 2) - pub_r000294_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_48 * 3) + (sec_r000294_6 * 2) - pub_r000294_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_39 * 3) + (sec_r000294_2 * 2) - pub_r000294_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_33 * 3) + (sec_r000294_13 * 2) - pub_r000294_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_56 * 3) + (sec_r000294_16 * 2) - pub_r000294_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_19 * 3) + (sec_r000294_11 * 2) - pub_r000294_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_10 * 3) + (sec_r000294_9 * 2) - pub_r000294_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_6 * 3) + (sec_r000294_15 * 2) - pub_r000294_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_4 + 27) & 127;
    sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_48 * 3) + (sec_r000294_13 * 2) - pub_r000294_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_7 * 3) + (sec_r000294_12 * 2) - pub_r000294_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_4 * 3) + (sec_r000294_7 * 2) - pub_r000294_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_31 * 3) + (sec_r000294_13 * 2) - pub_r000294_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_58 * 3) + (sec_r000294_15 * 2) - pub_r000294_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_69 * 3) + (sec_r000294_17 * 2) - pub_r000294_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_24 * 3) + (sec_r000294_1 * 2) - pub_r000294_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_28 * 3) + (sec_r000294_8 * 2) - pub_r000294_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_27 * 3) + (sec_r000294_11 * 2) - pub_r000294_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_27 * 3) + (sec_r000294_8 * 2) - pub_r000294_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_6 * 3) + (sec_r000294_11 * 2) - pub_r000294_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_67 * 3) + (sec_r000294_7 * 2) - pub_r000294_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000294_15 * 3) + (sec_r000294_15 * 2) - pub_r000294_4 + 18) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_18 * 3) + (sec_r000294_17 * 2) - pub_r000294_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_35 * 3) + (sec_r000294_14 * 2) - pub_r000294_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_85 * 3) + (sec_r000294_13 * 2) - pub_r000294_9 + 5) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000294_3 * 3) + (sec_r000294_3 * 2) - pub_r000294_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_11 * 3) + (sec_r000294_16 * 2) - pub_r000294_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_48 * 3) + (sec_r000294_11 * 2) - pub_r000294_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_87 * 3) + (sec_r000294_15 * 2) - pub_r000294_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_48 * 3) + (sec_r000294_4 * 2) - pub_r000294_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_45 * 3) + (sec_r000294_2 * 2) - pub_r000294_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_53 * 3) + (sec_r000294_5 * 2) - pub_r000294_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_66 * 3) + (sec_r000294_2 * 2) - pub_r000294_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_22 * 3) + (sec_r000294_17 * 2) - pub_r000294_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_64 * 3) + (sec_r000294_13 * 2) - pub_r000294_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_52 * 3) + (sec_r000294_8 * 2) - pub_r000294_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_63 * 3) + (sec_r000294_12 * 2) - pub_r000294_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_54 * 3) + (sec_r000294_4 * 2) - pub_r000294_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_29 * 3) + (sec_r000294_9 * 2) - pub_r000294_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_101 * 3) + (sec_r000294_0 * 2) - pub_r000294_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_29 * 3) + (sec_r000294_8 * 2) - pub_r000294_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_107 * 3) + (sec_r000294_8 * 2) - pub_r000294_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_71 * 3) + (sec_r000294_1 * 2) - pub_r000294_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r000294_3 * 3) + (sec_r000294_3 * 2) - pub_r000294_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_69 * 3) + (sec_r000294_16 * 2) - pub_r000294_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_89 * 3) + (sec_r000294_17 * 2) - pub_r000294_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_73 * 3) + (sec_r000294_1 * 2) - pub_r000294_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_57 * 3) + (sec_r000294_7 * 2) - pub_r000294_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_35 * 3) + (sec_r000294_14 * 2) - pub_r000294_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r000294_15 * 3) + (sec_r000294_15 * 2) - pub_r000294_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_24 * 3) + (sec_r000294_3 * 2) - pub_r000294_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_95 * 3) + (sec_r000294_17 * 2) - pub_r000294_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_78 * 3) + (sec_r000294_16 * 2) - pub_r000294_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_76 * 3) + (sec_r000294_17 * 2) - pub_r000294_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_114 * 3) + (sec_r000294_8 * 2) - pub_r000294_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000294_3 * 3) + (sec_r000294_3 * 2) - pub_r000294_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_36 * 3) + (sec_r000294_6 * 2) - pub_r000294_5 + 24) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_113 * 3) + (sec_r000294_10 * 2) - pub_r000294_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_15 * 3) + (sec_r000294_17 * 2) - pub_r000294_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_88 * 3) + (sec_r000294_1 * 2) - pub_r000294_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_97 * 3) + (sec_r000294_13 * 2) - pub_r000294_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_91 * 3) + (sec_r000294_3 * 2) - pub_r000294_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_71 * 3) + (sec_r000294_6 * 2) - pub_r000294_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_115 * 3) + (sec_r000294_15 * 2) - pub_r000294_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_80 * 3) + (sec_r000294_12 * 2) - pub_r000294_13 + 12) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_36 * 3) + (sec_r000294_12 * 2) - pub_r000294_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_42 * 3) + (sec_r000294_14 * 2) - pub_r000294_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_78 * 3) + (sec_r000294_12 * 2) - pub_r000294_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_93 * 3) + (sec_r000294_9 * 2) - pub_r000294_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_123 * 3) + (sec_r000294_12 * 2) - pub_r000294_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_45 * 3) + (sec_r000294_0 * 2) - pub_r000294_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_81 * 3) + (sec_r000294_3 * 2) - pub_r000294_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_14 * 3) + (sec_r000294_8 * 2) - pub_r000294_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_79 * 3) + (sec_r000294_14 * 2) - pub_r000294_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_144 * 3) + (sec_r000294_14 * 2) - pub_r000294_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_153 * 3) + (sec_r000294_13 * 2) - pub_r000294_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_19 * 3) + (sec_r000294_17 * 2) - pub_r000294_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_80 * 3) + (sec_r000294_14 * 2) - pub_r000294_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_67 * 3) + (sec_r000294_5 * 2) - pub_r000294_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_36 * 3) + (sec_r000294_11 * 2) - pub_r000294_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_39 * 3) + (sec_r000294_1 * 2) - pub_r000294_3 + 20) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_42 * 3) + (sec_r000294_5 * 2) - pub_r000294_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_88 * 3) + (sec_r000294_13 * 2) - pub_r000294_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_35 * 3) + (sec_r000294_11 * 2) - pub_r000294_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_7 * 3) + (sec_r000294_9 * 2) - pub_r000294_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_11 * 3) + (sec_r000294_16 * 2) - pub_r000294_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_60 * 3) + (sec_r000294_6 * 2) - pub_r000294_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_38 * 3) + (sec_r000294_15 * 2) - pub_r000294_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_19 * 3) + (sec_r000294_7 * 2) - pub_r000294_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_78 * 3) + (sec_r000294_12 * 2) - pub_r000294_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_64 * 3) + (sec_r000294_7 * 2) - pub_r000294_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_167 * 3) + (sec_r000294_8 * 2) - pub_r000294_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_94 * 3) + (sec_r000294_2 * 2) - pub_r000294_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_132 * 3) + (sec_r000294_3 * 2) - pub_r000294_16 + 35) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_136 * 3) + (sec_r000294_14 * 2) - pub_r000294_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_124 * 3) + (sec_r000294_12 * 2) - pub_r000294_5 + 26) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_71 * 3) + (sec_r000294_10 * 2) - pub_r000294_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_75 * 3) + (sec_r000294_15 * 2) - pub_r000294_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_12 * 3) + (sec_r000294_9 * 2) - pub_r000294_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_145 * 3) + (sec_r000294_14 * 2) - pub_r000294_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_77 * 3) + (sec_r000294_9 * 2) - pub_r000294_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_45 * 3) + (sec_r000294_4 * 2) - pub_r000294_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000294_5 * 3) + (sec_r000294_5 * 2) - pub_r000294_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_66 * 3) + (sec_r000294_11 * 2) - pub_r000294_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_98 * 3) + (sec_r000294_5 * 2) - pub_r000294_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_176 * 3) + (sec_r000294_5 * 2) - pub_r000294_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_5 * 3) + (sec_r000294_12 * 2) - pub_r000294_6 + 36) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_154 * 3) + (sec_r000294_17 * 2) - pub_r000294_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_63 * 3) + (sec_r000294_7 * 2) - pub_r000294_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_63 * 3) + (sec_r000294_4 * 2) - pub_r000294_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_198 * 3) + (sec_r000294_2 * 2) - pub_r000294_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_61 * 3) + (sec_r000294_4 * 2) - pub_r000294_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_48 * 3) + (sec_r000294_13 * 2) - pub_r000294_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_186 * 3) + (sec_r000294_15 * 2) - pub_r000294_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_195 * 3) + (sec_r000294_11 * 2) - pub_r000294_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_98 * 3) + (sec_r000294_4 * 2) - pub_r000294_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_42 * 3) + (sec_r000294_12 * 2) - pub_r000294_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_116 * 3) + (sec_r000294_12 * 2) - pub_r000294_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_210 * 3) + (sec_r000294_17 * 2) - pub_r000294_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_81 * 3) + (sec_r000294_2 * 2) - pub_r000294_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_197 * 3) + (sec_r000294_9 * 2) - pub_r000294_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_53 * 3) + (sec_r000294_15 * 2) - pub_r000294_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_34 * 3) + (sec_r000294_2 * 2) - pub_r000294_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_169 * 3) + (sec_r000294_9 * 2) - pub_r000294_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_166 * 3) + (sec_r000294_13 * 2) - pub_r000294_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_58 * 3) + (sec_r000294_5 * 2) - pub_r000294_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_223 * 3) + (sec_r000294_11 * 2) - pub_r000294_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_46 * 3) + (sec_r000294_11 * 2) - pub_r000294_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_168 * 3) + (sec_r000294_6 * 2) - pub_r000294_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_107 * 3) + (sec_r000294_3 * 2) - pub_r000294_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_229 * 3) + (sec_r000294_1 * 2) - pub_r000294_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_191 * 3) + (sec_r000294_0 * 2) - pub_r000294_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_157 * 3) + (sec_r000294_4 * 2) - pub_r000294_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_220 * 3) + (sec_r000294_3 * 2) - pub_r000294_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_197 * 3) + (sec_r000294_12 * 2) - pub_r000294_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_61 * 3) + (sec_r000294_15 * 2) - pub_r000294_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_156 * 3) + (sec_r000294_6 * 2) - pub_r000294_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_203 * 3) + (sec_r000294_14 * 2) - pub_r000294_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_180 * 3) + (sec_r000294_8 * 2) - pub_r000294_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_182 * 3) + (sec_r000294_3 * 2) - pub_r000294_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_24 * 3) + (sec_r000294_6 * 2) - pub_r000294_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_222 * 3) + (sec_r000294_7 * 2) - pub_r000294_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_222 * 3) + (sec_r000294_8 * 2) - pub_r000294_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_91 * 3) + (sec_r000294_15 * 2) - pub_r000294_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_54 * 3) + (sec_r000294_6 * 2) - pub_r000294_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_122 * 3) + (sec_r000294_9 * 2) - pub_r000294_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_17 * 3) + (sec_r000294_2 * 2) - pub_r000294_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_46 * 3) + (sec_r000294_4 * 2) - pub_r000294_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_147 * 3) + (sec_r000294_8 * 2) - pub_r000294_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_78 * 3) + (sec_r000294_15 * 2) - pub_r000294_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_19 * 3) + (sec_r000294_10 * 2) - pub_r000294_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_13 + 28) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_83 * 3) + (sec_r000294_9 * 2) - pub_r000294_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_262 * 3) + (sec_r000294_8 * 2) - pub_r000294_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_100 * 3) + (sec_r000294_9 * 2) - pub_r000294_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_141 * 3) + (sec_r000294_13 * 2) - pub_r000294_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_144 * 3) + (sec_r000294_7 * 2) - pub_r000294_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_42 * 3) + (sec_r000294_17 * 2) - pub_r000294_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_96 * 3) + (sec_r000294_14 * 2) - pub_r000294_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_15 * 3) + (sec_r000294_5 * 2) - pub_r000294_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_248 * 3) + (sec_r000294_16 * 2) - pub_r000294_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r000294_14 * 3) + (sec_r000294_14 * 2) - pub_r000294_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_239 * 3) + (sec_r000294_17 * 2) - pub_r000294_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_51 * 3) + (sec_r000294_2 * 2) - pub_r000294_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_143 * 3) + (sec_r000294_0 * 2) - pub_r000294_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_266 * 3) + (sec_r000294_14 * 2) - pub_r000294_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_155 * 3) + (sec_r000294_9 * 2) - pub_r000294_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_87 * 3) + (sec_r000294_10 * 2) - pub_r000294_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_127 * 3) + (sec_r000294_14 * 2) - pub_r000294_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((sec_r000294_8 * 3) + (sec_r000294_8 * 2) - pub_r000294_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((sec_r000294_5 * 3) + (sec_r000294_5 * 2) - pub_r000294_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_60 * 3) + (sec_r000294_9 * 2) - pub_r000294_7 + 32) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_46 * 3) + (sec_r000294_2 * 2) - pub_r000294_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_189 * 3) + (sec_r000294_10 * 2) - pub_r000294_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_233 * 3) + (sec_r000294_7 * 2) - pub_r000294_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_179 * 3) + (sec_r000294_5 * 2) - pub_r000294_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r000294_5 * 3) + (sec_r000294_5 * 2) - pub_r000294_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_65 * 3) + (sec_r000294_14 * 2) - pub_r000294_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_310 * 2) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_15 * 3) + (sec_r000294_16 * 2) - pub_r000294_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_311 * 2) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_296 * 3) + (sec_r000294_7 * 2) - pub_r000294_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_312 * 2) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_97 * 3) + (sec_r000294_15 * 2) - pub_r000294_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_313 * 2) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_303 * 3) + (sec_r000294_9 * 2) - pub_r000294_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_314 * 2) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_247 * 3) + (sec_r000294_8 * 2) - pub_r000294_10 + 24) & 127;
    sec_accum = (sec_accum + stage_v_315 * 2) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_86 * 3) + (sec_r000294_4 * 2) - pub_r000294_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_316 * 2) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_243 * 3) + (sec_r000294_4 * 2) - pub_r000294_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_317 * 2) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_81 * 3) + (sec_r000294_4 * 2) - pub_r000294_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_318 * 2) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_63 * 3) + (sec_r000294_4 * 2) - pub_r000294_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_319 * 2) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_320 * 2) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((sec_r000294_3 * 3) + (sec_r000294_3 * 2) - pub_r000294_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_321 * 2) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_38 * 3) + (sec_r000294_0 * 2) - pub_r000294_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_322 * 2) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_268 * 3) + (sec_r000294_0 * 2) - pub_r000294_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_323 * 2) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((sec_r000294_4 * 3) + (sec_r000294_4 * 2) - pub_r000294_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_324 * 2) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_325 * 2) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((sec_r000294_10 * 3) + (sec_r000294_10 * 2) - pub_r000294_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_326 * 2) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r000294_9 * 3) + (sec_r000294_9 * 2) - pub_r000294_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_327 * 2) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_328 * 2) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_286 * 3) + (sec_r000294_6 * 2) - pub_r000294_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_329 * 2) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_233 * 3) + (sec_r000294_7 * 2) - pub_r000294_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_330 * 2) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((sec_r000294_17 * 3) + (sec_r000294_17 * 2) - pub_r000294_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_331 * 2) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r000294_7 * 3) + (sec_r000294_7 * 2) - pub_r000294_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_332 * 2) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_17 * 3) + (sec_r000294_13 * 2) - pub_r000294_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_333 * 2) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_171 * 3) + (sec_r000294_15 * 2) - pub_r000294_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_334 * 2) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_58 * 3) + (sec_r000294_14 * 2) - pub_r000294_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_335 * 2) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_92 * 3) + (sec_r000294_2 * 2) - pub_r000294_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_336 * 2) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((sec_r000294_6 * 3) + (sec_r000294_6 * 2) - pub_r000294_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_337 * 2) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_5 * 3) + (sec_r000294_12 * 2) - pub_r000294_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_338 * 2) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_187 * 3) + (sec_r000294_12 * 2) - pub_r000294_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_339 * 2) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_328 * 3) + (sec_r000294_8 * 2) - pub_r000294_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_340 * 2) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_341 * 2) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_23 * 3) + (sec_r000294_2 * 2) - pub_r000294_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_342 * 2) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_245 * 3) + (sec_r000294_17 * 2) - pub_r000294_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_343 * 2) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_203 * 3) + (sec_r000294_11 * 2) - pub_r000294_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_344 * 2) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_345 * 2) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r000294_15 * 3) + (sec_r000294_15 * 2) - pub_r000294_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_346 * 2) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_57 * 3) + (sec_r000294_0 * 2) - pub_r000294_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_347 * 2) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_138 * 3) + (sec_r000294_8 * 2) - pub_r000294_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_348 * 2) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_326 * 3) + (sec_r000294_0 * 2) - pub_r000294_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_349 * 2) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_110 * 3) + (sec_r000294_1 * 2) - pub_r000294_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_350 * 2) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_200 * 3) + (sec_r000294_2 * 2) - pub_r000294_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_351 * 2) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_151 * 3) + (sec_r000294_8 * 2) - pub_r000294_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_352 * 2) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_89 * 3) + (sec_r000294_15 * 2) - pub_r000294_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_353 * 2) & 255;
    out_sink = (out_sink + stage_v_353) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_336 * 3) + (sec_r000294_1 * 2) - pub_r000294_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_354 * 2) & 255;
    out_sink = (out_sink + stage_v_354) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r000294_13 * 3) + (sec_r000294_13 * 2) - pub_r000294_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_355 * 2) & 255;
    out_sink = (out_sink + stage_v_355) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((sec_r000294_1 * 3) + (sec_r000294_1 * 2) - pub_r000294_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_356 * 2) & 255;
    out_sink = (out_sink + stage_v_356) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((sec_r000294_16 * 3) + (sec_r000294_16 * 2) - pub_r000294_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_357 * 2) & 255;
    out_sink = (out_sink + stage_v_357) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_128 * 3) + (sec_r000294_4 * 2) - pub_r000294_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_358 * 2) & 255;
    out_sink = (out_sink + stage_v_358) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_315 * 3) + (sec_r000294_8 * 2) - pub_r000294_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_359 * 2) & 255;
    out_sink = (out_sink + stage_v_359) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_159 * 3) + (sec_r000294_9 * 2) - pub_r000294_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_360 * 2) & 255;
    out_sink = (out_sink + stage_v_360) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_60 * 3) + (sec_r000294_14 * 2) - pub_r000294_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_361 * 2) & 255;
    out_sink = (out_sink + stage_v_361) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_8 * 3) + (sec_r000294_17 * 2) - pub_r000294_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_362 * 2) & 255;
    out_sink = (out_sink + stage_v_362) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_315 * 3) + (sec_r000294_13 * 2) - pub_r000294_10 + 21) & 127;
    sec_accum = (sec_accum + stage_v_363 * 2) & 255;
    out_sink = (out_sink + stage_v_363) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_327 * 3) + (sec_r000294_11 * 2) - pub_r000294_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_364 * 2) & 255;
    out_sink = (out_sink + stage_v_364) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((sec_r000294_0 * 3) + (sec_r000294_0 * 2) - pub_r000294_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_365 * 2) & 255;
    out_sink = (out_sink + stage_v_365) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((sec_r000294_15 * 3) + (sec_r000294_15 * 2) - pub_r000294_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_366 * 2) & 255;
    out_sink = (out_sink + stage_v_366) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_22 * 3) + (sec_r000294_1 * 2) - pub_r000294_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_367 * 2) & 255;
    out_sink = (out_sink + stage_v_367) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_253 * 3) + (sec_r000294_7 * 2) - pub_r000294_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_368 * 2) & 255;
    out_sink = (out_sink + stage_v_368) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_86 * 3) + (sec_r000294_6 * 2) - pub_r000294_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_369 * 2) & 255;
    out_sink = (out_sink + stage_v_369) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((sec_r000294_2 * 3) + (sec_r000294_2 * 2) - pub_r000294_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_370 * 2) & 255;
    out_sink = (out_sink + stage_v_370) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_157 * 3) + (sec_r000294_3 * 2) - pub_r000294_7 + 27) & 127;
    sec_accum = (sec_accum + stage_v_371 * 2) & 255;
    out_sink = (out_sink + stage_v_371) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((sec_r000294_11 * 3) + (sec_r000294_11 * 2) - pub_r000294_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_372 * 2) & 255;
    out_sink = (out_sink + stage_v_372) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((sec_r000294_12 * 3) + (sec_r000294_12 * 2) - pub_r000294_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_373 * 2) & 255;
    out_sink = (out_sink + stage_v_373) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
