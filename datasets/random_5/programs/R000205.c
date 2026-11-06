/*
 * Benchmark Program: R000205
 * Security Family: bitwise_flow
 * Generator Seed: 520513
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000205_513_0 {
    int tag;
    short nonce;
    int round_key;
    int flags;
    int counter;
    int buffer[3];
};

struct MatrixBlock_R000205_513_1 {
    int determinant;
    short density;
    int stride;
    int trace;
    int buffer[3];
};

union RegisterBank_R000205_513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000205_513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000205_513_0(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_20) & 63;
    acc ^= aux;
    int tally_71 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_71 > 25) {
        acc = (acc + tally_71 * 2 + 5) & 127;
        aux ^= (tally_71 & 15);
    } else {
        acc = (acc - tally_71 + 11) & 127;
        aux += 3;
    }
    int anchor_26 = (aux + st.buffer[1]) & 3;
    switch (anchor_26) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_43 = (aux + st.buffer[1]) & 3;
    switch (parity_43) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int delta_85 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_85 > 44) {
        acc = (acc + delta_85 * 2 + 5) & 127;
        aux ^= (delta_85 & 15);
    } else {
        acc = (acc - delta_85 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_96 = local_arr[aux % 3];
    acc = (acc + cursor_96 * 2) & 127;
    int phase_20 = (aux + st.buffer[1]) & 3;
    switch (phase_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_3(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_78 = local_arr[aux % 3];
    acc = (acc + anchor_78 * 2) & 127;
    int quotient_51 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_51 > 10) {
        acc = (acc + quotient_51 * 2 + 5) & 127;
        aux ^= (quotient_51 & 15);
    } else {
        acc = (acc - quotient_51 + 11) & 127;
        aux += 3;
    }
    int vector_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_31) & 63;
    acc ^= aux;
    int factor_21 = (aux + st.buffer[1]) & 3;
    switch (factor_21) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_59) & 63;
    acc ^= aux;
    int delta_36 = (aux + st.buffer[1]) & 3;
    switch (delta_36) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_71 = local_arr[aux % 3];
    acc = (acc + tracker_71 * 2) & 127;
    int scale_98 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_98 > 25) {
        acc = (acc + scale_98 * 2 + 5) & 127;
        aux ^= (scale_98 & 15);
    } else {
        acc = (acc - scale_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_59 = (aux + st.buffer[1]) & 3;
    switch (damping_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_35 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_35 > 34) {
        acc = (acc + margin_35 * 2 + 5) & 127;
        aux ^= (margin_35 & 15);
    } else {
        acc = (acc - margin_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_87 = local_arr[aux % 3];
    acc = (acc + mask_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_7(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int index_reg_50 = local_arr[aux % 3];
    acc = (acc + index_reg_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_47 = (st.buffer[0] * 3 + aux) & 63;
    if (window_47 > 15) {
        acc = (acc + window_47 * 2 + 5) & 127;
        aux ^= (window_47 & 15);
    } else {
        acc = (acc - window_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_8(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int delta_17 = local_arr[aux % 3];
    acc = (acc + delta_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_41) & 63;
    acc ^= aux;
    int metric_10 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_10 > 35) {
        acc = (acc + metric_10 * 2 + 5) & 127;
        aux ^= (metric_10 & 15);
    } else {
        acc = (acc - metric_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tracker_62 = (aux + st.buffer[1]) & 3;
    switch (tracker_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_20 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_20 > 26) {
        acc = (acc + pivot_20 * 2 + 5) & 127;
        aux ^= (pivot_20 & 15);
    } else {
        acc = (acc - pivot_20 + 11) & 127;
        aux += 3;
    }
    int tracker_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int checksum_86 = local_arr[aux % 3];
    acc = (acc + checksum_86 * 2) & 127;
    int stride_97 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_97 > 24) {
        acc = (acc + stride_97 * 2 + 5) & 127;
        aux ^= (stride_97 & 15);
    } else {
        acc = (acc - stride_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_37) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_36 = local_arr[aux % 3];
    acc = (acc + scale_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int residue_29 = local_arr[aux % 3];
    acc = (acc + residue_29 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int segment_91 = (aux + st.buffer[1]) & 3;
    switch (segment_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_46 = local_arr[aux % 3];
    acc = (acc + segment_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_14(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_56) & 63;
    acc ^= aux;
    int coefficient_55 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_55 > 38) {
        acc = (acc + coefficient_55 * 2 + 5) & 127;
        aux ^= (coefficient_55 & 15);
    } else {
        acc = (acc - coefficient_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int checksum_89 = local_arr[aux % 3];
    acc = (acc + checksum_89 * 2) & 127;
    int accumulator_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_65 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_65 > 45) {
        acc = (acc + quotient_65 * 2 + 5) & 127;
        aux ^= (quotient_65 & 15);
    } else {
        acc = (acc - quotient_65 + 11) & 127;
        aux += 3;
    }
    int factor_53 = (aux + st.buffer[1]) & 3;
    switch (factor_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000205_513_17(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_25) & 63;
    acc ^= aux;
    int tracker_52 = (aux + st.buffer[1]) & 3;
    switch (tracker_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_20 = local_arr[aux % 3];
    acc = (acc + accumulator_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_24 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_24 > 27) {
        acc = (acc + parity_24 * 2 + 5) & 127;
        aux ^= (parity_24 & 15);
    } else {
        acc = (acc - parity_24 + 11) & 127;
        aux += 3;
    }
    int stride_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_27 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_27 > 27) {
        acc = (acc + stride_27 * 2 + 5) & 127;
        aux ^= (stride_27 & 15);
    } else {
        acc = (acc - stride_27 + 11) & 127;
        aux += 3;
    }
    int damping_17 = (aux + st.buffer[1]) & 3;
    switch (damping_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_20(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_17 = (aux + st.buffer[1]) & 3;
    switch (coefficient_17) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000205_513_21(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000205_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quantum_15 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_15 > 32) {
        acc = (acc + quantum_15 * 2 + 5) & 127;
        aux ^= (quantum_15 & 15);
    } else {
        acc = (acc - quantum_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_98 = local_arr[aux % 3];
    acc = (acc + threshold_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000205_513_22(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000205_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_74 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_74 > 28) {
        acc = (acc + threshold_74 * 2 + 5) & 127;
        aux ^= (threshold_74 & 15);
    } else {
        acc = (acc - threshold_74 + 11) & 127;
        aux += 3;
    }
    int metric_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_10) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_52 = local_arr[aux % 3];
    acc = (acc + tally_52 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000205_0;
    int sec_r000205_1;
    int sec_r000205_2;
    int sec_r000205_3;
    int sec_r000205_4;
    int sec_r000205_5;
    int sec_r000205_6;
    int sec_r000205_7;
    int sec_r000205_8;
    int sec_r000205_9;
    int sec_r000205_10;
    int sec_r000205_11;
    int sec_r000205_12;
    int sec_r000205_13;
    int sec_r000205_14;
    int sec_r000205_15;
    int sec_r000205_16;
    int sec_r000205_17;
    int sec_r000205_18;
    int sec_r000205_19;
    int sec_r000205_20;
    int sec_r000205_21;
    int sec_r000205_22;
    int sec_r000205_23;
    int pub_r000205_0;
    int pub_r000205_1;
    int pub_r000205_2;
    int pub_r000205_3;
    int pub_r000205_4;
    int pub_r000205_5;
    int pub_r000205_6;
    int pub_r000205_7;
    int pub_r000205_8;
    int pub_r000205_9;
    int pub_r000205_10;
    int pub_r000205_11;
    int pub_r000205_12;
    int pub_r000205_13;
    int pub_r000205_14;
    int pub_r000205_15;
    int pub_r000205_16;
    int pub_r000205_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000205_0 >= -100 && pub_r000205_0 <= 100);
    __CPROVER_assume(pub_r000205_1 >= -100 && pub_r000205_1 <= 100);
    __CPROVER_assume(pub_r000205_2 >= -100 && pub_r000205_2 <= 100);
    __CPROVER_assume(pub_r000205_3 >= -100 && pub_r000205_3 <= 100);
    __CPROVER_assume(pub_r000205_4 >= -100 && pub_r000205_4 <= 100);
    __CPROVER_assume(pub_r000205_5 >= -100 && pub_r000205_5 <= 100);
    __CPROVER_assume(pub_r000205_6 >= -100 && pub_r000205_6 <= 100);
    __CPROVER_assume(pub_r000205_7 >= -100 && pub_r000205_7 <= 100);
    __CPROVER_assume(pub_r000205_8 >= -100 && pub_r000205_8 <= 100);
    __CPROVER_assume(pub_r000205_9 >= -100 && pub_r000205_9 <= 100);
    __CPROVER_assume(pub_r000205_10 >= -100 && pub_r000205_10 <= 100);
    __CPROVER_assume(pub_r000205_11 >= -100 && pub_r000205_11 <= 100);
    __CPROVER_assume(pub_r000205_12 >= -100 && pub_r000205_12 <= 100);
    __CPROVER_assume(pub_r000205_13 >= -100 && pub_r000205_13 <= 100);
    __CPROVER_assume(pub_r000205_14 >= -100 && pub_r000205_14 <= 100);
    __CPROVER_assume(pub_r000205_15 >= -100 && pub_r000205_15 <= 100);
    __CPROVER_assume(pub_r000205_16 >= -100 && pub_r000205_16 <= 100);
    __CPROVER_assume(pub_r000205_17 >= -100 && pub_r000205_17 <= 100);
    __CPROVER_assume(sec_r000205_0 >= 0 && sec_r000205_0 <= 255);
    __CPROVER_assume(sec_r000205_1 >= 0 && sec_r000205_1 <= 255);
    __CPROVER_assume(sec_r000205_2 >= 0 && sec_r000205_2 <= 255);
    __CPROVER_assume(sec_r000205_3 >= 0 && sec_r000205_3 <= 255);
    __CPROVER_assume(sec_r000205_4 >= 0 && sec_r000205_4 <= 255);
    __CPROVER_assume(sec_r000205_5 >= 0 && sec_r000205_5 <= 255);
    __CPROVER_assume(sec_r000205_6 >= 0 && sec_r000205_6 <= 255);
    __CPROVER_assume(sec_r000205_7 >= 0 && sec_r000205_7 <= 255);
    __CPROVER_assume(sec_r000205_8 >= 0 && sec_r000205_8 <= 255);
    __CPROVER_assume(sec_r000205_9 >= 0 && sec_r000205_9 <= 255);
    __CPROVER_assume(sec_r000205_10 >= 0 && sec_r000205_10 <= 255);
    __CPROVER_assume(sec_r000205_11 >= 0 && sec_r000205_11 <= 255);
    __CPROVER_assume(sec_r000205_12 >= 0 && sec_r000205_12 <= 255);
    __CPROVER_assume(sec_r000205_13 >= 0 && sec_r000205_13 <= 255);
    __CPROVER_assume(sec_r000205_14 >= 0 && sec_r000205_14 <= 255);
    __CPROVER_assume(sec_r000205_15 >= 0 && sec_r000205_15 <= 255);
    __CPROVER_assume(sec_r000205_16 >= 0 && sec_r000205_16 <= 255);
    __CPROVER_assume(sec_r000205_17 >= 0 && sec_r000205_17 <= 255);
    __CPROVER_assume(sec_r000205_18 >= 0 && sec_r000205_18 <= 255);
    __CPROVER_assume(sec_r000205_19 >= 0 && sec_r000205_19 <= 255);
    __CPROVER_assume(sec_r000205_20 >= 0 && sec_r000205_20 <= 255);
    __CPROVER_assume(sec_r000205_21 >= 0 && sec_r000205_21 <= 255);
    __CPROVER_assume(sec_r000205_22 >= 0 && sec_r000205_22 <= 255);
    __CPROVER_assume(sec_r000205_23 >= 0 && sec_r000205_23 <= 255);

    struct CipherContext_R000205_513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000205_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000205_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000205_0 + 7) & 15;
    struct MatrixBlock_R000205_513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000205_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000205_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000205_0 + 9) & 15;

    union RegisterBank_R000205_513_0 u_var;
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
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 37) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 52) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 10) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 25) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 26) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 41) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 20) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 35) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 16) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 31) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 29) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 44) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 27) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 42) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 16) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 31) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 10) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 25) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 28) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 43) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000205_4 << 2) ^ (sec_r000205_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_61 << 2) ^ (sec_r000205_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_62 << 1) ^ (sec_r000205_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_62 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_62 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_65 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r000205_18 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000205_0 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_64 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_65 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r000205_21 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_71 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_72 << 1) ^ (sec_r000205_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000205_15 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r000205_12 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_70 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_68 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_75 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_61 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000205_15 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_80 << 2) ^ (sec_r000205_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_63 << 2) ^ (sec_r000205_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_75 << 1) ^ (sec_r000205_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_75 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_75 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_62 << 2) ^ (sec_r000205_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_76 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_87 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_76 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000205_21 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_69 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000205_11 << 2) ^ (sec_r000205_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000205_3 << 2) ^ (sec_r000205_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000205_8 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r000205_3 << 2) ^ (sec_r000205_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000205_8 << 2) ^ (sec_r000205_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_86 << 1) ^ (sec_r000205_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_91 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_77 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000205_5 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_67 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000205_7 << 2) ^ (sec_r000205_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_71 << 2) ^ (sec_r000205_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_63 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r000205_11 << 1) ^ (sec_r000205_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_97 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r000205_5 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000205_18 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_63 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_109 << 2) ^ (sec_r000205_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000205_20 << 1) ^ (sec_r000205_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r000205_2 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_110 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_67 << 1) ^ (sec_r000205_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_100 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r000205_21 << 1) ^ (sec_r000205_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_101 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000205_1 << 2) ^ (sec_r000205_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_78 << 1) ^ (sec_r000205_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000205_20 << 1) ^ (sec_r000205_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_102 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_92 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_92 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000205_10 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_80 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_110 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_79 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000205_20 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_125 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000205_23 << 1) ^ (sec_r000205_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_122 << 1) ^ (sec_r000205_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_72 << 1) ^ (sec_r000205_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_76 << 1) ^ (sec_r000205_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_82 << 2) ^ (sec_r000205_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_109 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000205_7 << 1) ^ (sec_r000205_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_98 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_77 << 2) ^ (sec_r000205_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000205_21 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_137 << 1) ^ (sec_r000205_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_76 << 2) ^ (sec_r000205_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000205_4 << 2) ^ (sec_r000205_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_135 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_87 << 1) ^ (sec_r000205_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000205_11 << 2) ^ (sec_r000205_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_112 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_109 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000205_2 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_124 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_69 << 1) ^ (sec_r000205_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r000205_13 << 2) ^ (sec_r000205_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000205_13 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_140 << 1) ^ (sec_r000205_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000205_22 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_142 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_135 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_153 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_90 << 1) ^ (sec_r000205_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_99 << 1) ^ (sec_r000205_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_71 << 1) ^ (sec_r000205_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r000205_3 << 2) ^ (sec_r000205_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000205_1 << 2) ^ (sec_r000205_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_63 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000205_13 << 2) ^ (sec_r000205_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_63 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_124 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_159 << 2) ^ (sec_r000205_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000205_16 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000205_22 << 2) ^ (sec_r000205_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_170 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_111 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000205_4 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r000205_3 << 2) ^ (sec_r000205_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000205_20 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_122 << 1) ^ (sec_r000205_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_96 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000205_8 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r000205_2 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_76 << 1) ^ (sec_r000205_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_132 << 2) ^ (sec_r000205_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_131 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000205_10 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000205_1 << 1) ^ (sec_r000205_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_99 << 2) ^ (sec_r000205_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_101 << 1) ^ (sec_r000205_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000205_10 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r000205_22 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_132 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_159 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000205_12 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000205_0 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_175 << 2) ^ (sec_r000205_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_196 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000205_10 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r000205_20 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_64 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r000205_17 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_201 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_126 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_202 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r000205_5 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_203 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_136 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_61 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r000205_0 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r000205_5 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_101 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_83 << 2) ^ (sec_r000205_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_204 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r000205_2 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_211 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000205_4 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_110 << 1) ^ (sec_r000205_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_213 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_199 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_156 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_173 << 2) ^ (sec_r000205_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_61 << 2) ^ (sec_r000205_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_120 << 1) ^ (sec_r000205_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_218 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_75 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r000205_5 << 1) ^ (sec_r000205_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_120 << 1) ^ (sec_r000205_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_221 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_186 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r000205_0 << 1) ^ (sec_r000205_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_223 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_182 << 1) ^ (sec_r000205_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_167 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_225 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r000205_18 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_226 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000205_8 << 2) ^ (sec_r000205_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_227 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r000205_7 << 1) ^ (sec_r000205_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_228 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_120 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_229 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000205_13 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_123 << 2) ^ (sec_r000205_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_231 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_228 << 2) ^ (sec_r000205_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_232 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000205_4 << 2) ^ (sec_r000205_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_233 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((sec_r000205_2 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_234 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_77 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_235 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_187 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_236 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_157 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_237 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r000205_1 << 2) ^ (sec_r000205_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_238 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_168 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_239 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000205_4 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_240 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r000205_18 << 1) ^ (sec_r000205_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_241 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000205_1 << 1) ^ (sec_r000205_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_242 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_141 << 1) ^ (sec_r000205_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_243 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_194 << 2) ^ (sec_r000205_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_244 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_141 << 1) ^ (sec_r000205_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_245 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((sec_r000205_22 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_246 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_124 << 2) ^ (sec_r000205_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_247 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_156 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_248 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_189 << 1) ^ (sec_r000205_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_249 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_178 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_250 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000205_0 << 2) ^ (sec_r000205_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_251 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_129 << 2) ^ (sec_r000205_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_252 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_80 << 1) ^ (sec_r000205_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_253 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r000205_4 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_254 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_218 << 2) ^ (sec_r000205_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_255 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r000205_3 << 1) ^ (sec_r000205_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_256 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r000205_14 << 1) ^ (sec_r000205_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_257 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_245 << 1) ^ (sec_r000205_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_258 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r000205_2 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_259 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r000205_21 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_260 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((sec_r000205_4 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_261 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r000205_19 << 2) ^ (sec_r000205_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_262 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((sec_r000205_20 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_263 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((sec_r000205_4 << 2) ^ (sec_r000205_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_264 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r000205_22 << 2) ^ (sec_r000205_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_265 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((sec_r000205_18 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_266 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_257 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_267 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_111 << 1) ^ (sec_r000205_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_268 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_204 << 1) ^ (sec_r000205_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_269 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_193 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_270 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_177 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_271 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_191 << 1) ^ (sec_r000205_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_272 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_162 << 1) ^ (sec_r000205_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_273 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_157 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_274 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_105 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_275 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_223 << 1) ^ (sec_r000205_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_276 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_114 << 1) ^ (sec_r000205_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_277 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_190 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_278 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((sec_r000205_6 << 2) ^ (sec_r000205_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_279 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_262 << 1) ^ (sec_r000205_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_280 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_155 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_281 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r000205_16 << 1) ^ (sec_r000205_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_282 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r000205_5 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_283 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_152 << 2) ^ (sec_r000205_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_284 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_244 << 2) ^ (sec_r000205_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_285 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r000205_13 << 1) ^ (sec_r000205_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_286 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((sec_r000205_10 << 2) ^ (sec_r000205_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_287 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000205_2 << 2) ^ (sec_r000205_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_288 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_256 << 2) ^ (sec_r000205_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_289 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_134 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_290 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_176 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_291 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r000205_11 << 1) ^ (sec_r000205_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_292 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_250 << 1) ^ (sec_r000205_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_293 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r000205_7 << 2) ^ (sec_r000205_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_294 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_95 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_295 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r000205_21 << 1) ^ (sec_r000205_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_296 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_104 << 1) ^ (sec_r000205_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_297 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((sec_r000205_15 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_298 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_62 << 1) ^ (sec_r000205_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_299 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_237 << 2) ^ (sec_r000205_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_300 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_69 << 1) ^ (sec_r000205_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_301 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((sec_r000205_14 << 2) ^ (sec_r000205_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_302 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_140 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_303 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_127 << 2) ^ (sec_r000205_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_304 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_106 << 2) ^ (sec_r000205_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_305 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_176 << 1) ^ (sec_r000205_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_306 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r000205_18 << 2) ^ (sec_r000205_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_307 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((sec_r000205_20 << 2) ^ (sec_r000205_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_308 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_270 << 1) ^ (sec_r000205_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_309 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r000205_5 << 1) ^ (sec_r000205_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_310 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_175 << 1) ^ (sec_r000205_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_311 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_213 << 2) ^ (sec_r000205_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_312 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r000205_22 << 2) ^ (sec_r000205_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_313 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_271 << 1) ^ (sec_r000205_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_314 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_82 << 1) ^ (sec_r000205_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_315 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_315 << 1) ^ (sec_r000205_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_316 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_316 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
