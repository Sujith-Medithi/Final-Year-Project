/*
 * Benchmark Program: R000798
 * Security Family: secret_dependent_loops
 * Generator Seed: 579813
 * High Inputs: 24 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000798_9813_0 {
    int trace;
    unsigned char stride;
    int scale;
    short determinant;
    int dim;
    int density;
    int buffer[3];
};

struct Transaction_R000798_9813_1 {
    short account_id;
    int status;
    int rate;
    int fee;
    int buffer[3];
};

struct AudioFrame_R000798_9813_2 {
    int sample_rate;
    int peak;
    unsigned char rms;
    int buffer[3];
};

union RegisterBank_R000798_9813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000798_9813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int coefficient_23 = (aux + st.buffer[1]) & 3;
    switch (coefficient_23) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_72) & 63;
    acc ^= aux;
    int delta_33 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_33 > 37) {
        acc = (acc + delta_33 * 2 + 5) & 127;
        aux ^= (delta_33 & 15);
    } else {
        acc = (acc - delta_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_39 = local_arr[aux % 3];
    acc = (acc + checksum_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000798_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int parity_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_2(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_92 = (aux + st.buffer[1]) & 3;
    switch (weight_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_61 = local_arr[aux % 3];
    acc = (acc + index_reg_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_85 = (aux + st.buffer[1]) & 3;
    switch (metric_85) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000798_9813_4(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000798_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int pivot_47 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_47 > 38) {
        acc = (acc + pivot_47 * 2 + 5) & 127;
        aux ^= (pivot_47 & 15);
    } else {
        acc = (acc - pivot_47 + 11) & 127;
        aux += 3;
    }
    int index_reg_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000798_9813_5(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_83) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_30 = local_arr[aux % 3];
    acc = (acc + weight_30 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_72 = (aux + st.buffer[1]) & 3;
    switch (quotient_72) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000798_9813_6(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_30 = local_arr[aux % 3];
    acc = (acc + threshold_30 * 2) & 127;
    int quotient_27 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_27 > 49) {
        acc = (acc + quotient_27 * 2 + 5) & 127;
        aux ^= (quotient_27 & 15);
    } else {
        acc = (acc - quotient_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000798_9813_7(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int window_19 = (aux + st.buffer[1]) & 3;
    switch (window_19) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_33 > 17) {
        acc = (acc + cursor_33 * 2 + 5) & 127;
        aux ^= (cursor_33 & 15);
    } else {
        acc = (acc - cursor_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_14 = (aux + st.buffer[1]) & 3;
    switch (mask_14) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_92 = local_arr[aux % 3];
    acc = (acc + weight_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_9(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_46 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_46 > 35) {
        acc = (acc + coefficient_46 * 2 + 5) & 127;
        aux ^= (coefficient_46 & 15);
    } else {
        acc = (acc - coefficient_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_81 = local_arr[aux % 3];
    acc = (acc + segment_81 * 2) & 127;
    int quantum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000798_9813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000798_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_87 = (aux + st.buffer[1]) & 3;
    switch (window_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_77 = local_arr[aux % 3];
    acc = (acc + scale_77 * 2) & 127;
    int scale_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_11(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_40 = (aux + st.buffer[1]) & 3;
    switch (delta_40) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_60 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_60 > 40) {
        acc = (acc + quotient_60 * 2 + 5) & 127;
        aux ^= (quotient_60 & 15);
    } else {
        acc = (acc - quotient_60 + 11) & 127;
        aux += 3;
    }
    int tally_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_30 = local_arr[aux % 3];
    acc = (acc + segment_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_84 = local_arr[aux % 3];
    acc = (acc + tracker_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000798_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int quotient_57 = local_arr[aux % 3];
    acc = (acc + quotient_57 * 2) & 127;
    int quantum_58 = (aux + st.buffer[1]) & 3;
    switch (quantum_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_14(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_44 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_44 > 30) {
        acc = (acc + mask_44 * 2 + 5) & 127;
        aux ^= (mask_44 & 15);
    } else {
        acc = (acc - mask_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_91 = local_arr[aux % 3];
    acc = (acc + checksum_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_93 = (aux + st.buffer[1]) & 3;
    switch (vector_93) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_64 = (st.buffer[0] * 3 + aux) & 63;
    if (window_64 > 38) {
        acc = (acc + window_64 * 2 + 5) & 127;
        aux ^= (window_64 & 15);
    } else {
        acc = (acc - window_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_61 = local_arr[aux % 3];
    acc = (acc + mask_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_16(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_89 = local_arr[aux % 3];
    acc = (acc + accumulator_89 * 2) & 127;
    int metric_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_78) & 63;
    acc ^= aux;
    int tally_87 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_87 > 39) {
        acc = (acc + tally_87 * 2 + 5) & 127;
        aux ^= (tally_87 & 15);
    } else {
        acc = (acc - tally_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000798_9813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_74 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_74 > 13) {
        acc = (acc + offset_74 * 2 + 5) & 127;
        aux ^= (offset_74 & 15);
    } else {
        acc = (acc - offset_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_74 = local_arr[aux % 3];
    acc = (acc + delta_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_18(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000798_9813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int parity_34 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_34 > 29) {
        acc = (acc + parity_34 * 2 + 5) & 127;
        aux ^= (parity_34 & 15);
    } else {
        acc = (acc - parity_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_81 = local_arr[aux % 3];
    acc = (acc + tally_81 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000798_9813_19(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000798_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_78 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_78 > 24) {
        acc = (acc + index_reg_78 * 2 + 5) & 127;
        aux ^= (index_reg_78 & 15);
    } else {
        acc = (acc - index_reg_78 + 11) & 127;
        aux += 3;
    }
    int residue_39 = (aux + st.buffer[1]) & 3;
    switch (residue_39) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000798_0;
    int sec_r000798_1;
    int sec_r000798_2;
    int sec_r000798_3;
    int sec_r000798_4;
    int sec_r000798_5;
    int sec_r000798_6;
    int sec_r000798_7;
    int sec_r000798_8;
    int sec_r000798_9;
    int sec_r000798_10;
    int sec_r000798_11;
    int sec_r000798_12;
    int sec_r000798_13;
    int sec_r000798_14;
    int sec_r000798_15;
    int sec_r000798_16;
    int sec_r000798_17;
    int sec_r000798_18;
    int sec_r000798_19;
    int sec_r000798_20;
    int sec_r000798_21;
    int sec_r000798_22;
    int sec_r000798_23;
    int pub_r000798_0;
    int pub_r000798_1;
    int pub_r000798_2;
    int pub_r000798_3;
    int pub_r000798_4;
    int pub_r000798_5;
    int pub_r000798_6;
    int pub_r000798_7;
    int pub_r000798_8;
    int pub_r000798_9;
    int pub_r000798_10;
    int pub_r000798_11;
    int pub_r000798_12;
    int pub_r000798_13;
    int pub_r000798_14;
    int pub_r000798_15;
    int pub_r000798_16;
    int pub_r000798_17;
    int pub_r000798_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000798_0 >= -100 && pub_r000798_0 <= 100);
    __CPROVER_assume(pub_r000798_1 >= -100 && pub_r000798_1 <= 100);
    __CPROVER_assume(pub_r000798_2 >= -100 && pub_r000798_2 <= 100);
    __CPROVER_assume(pub_r000798_3 >= -100 && pub_r000798_3 <= 100);
    __CPROVER_assume(pub_r000798_4 >= -100 && pub_r000798_4 <= 100);
    __CPROVER_assume(pub_r000798_5 >= -100 && pub_r000798_5 <= 100);
    __CPROVER_assume(pub_r000798_6 >= -100 && pub_r000798_6 <= 100);
    __CPROVER_assume(pub_r000798_7 >= -100 && pub_r000798_7 <= 100);
    __CPROVER_assume(pub_r000798_8 >= -100 && pub_r000798_8 <= 100);
    __CPROVER_assume(pub_r000798_9 >= -100 && pub_r000798_9 <= 100);
    __CPROVER_assume(pub_r000798_10 >= -100 && pub_r000798_10 <= 100);
    __CPROVER_assume(pub_r000798_11 >= -100 && pub_r000798_11 <= 100);
    __CPROVER_assume(pub_r000798_12 >= -100 && pub_r000798_12 <= 100);
    __CPROVER_assume(pub_r000798_13 >= -100 && pub_r000798_13 <= 100);
    __CPROVER_assume(pub_r000798_14 >= -100 && pub_r000798_14 <= 100);
    __CPROVER_assume(pub_r000798_15 >= -100 && pub_r000798_15 <= 100);
    __CPROVER_assume(pub_r000798_16 >= -100 && pub_r000798_16 <= 100);
    __CPROVER_assume(pub_r000798_17 >= -100 && pub_r000798_17 <= 100);
    __CPROVER_assume(pub_r000798_18 >= -100 && pub_r000798_18 <= 100);
    __CPROVER_assume(sec_r000798_0 >= 0 && sec_r000798_0 <= 255);
    __CPROVER_assume(sec_r000798_1 >= 0 && sec_r000798_1 <= 255);
    __CPROVER_assume(sec_r000798_2 >= 0 && sec_r000798_2 <= 255);
    __CPROVER_assume(sec_r000798_3 >= 0 && sec_r000798_3 <= 255);
    __CPROVER_assume(sec_r000798_4 >= 0 && sec_r000798_4 <= 255);
    __CPROVER_assume(sec_r000798_5 >= 0 && sec_r000798_5 <= 255);
    __CPROVER_assume(sec_r000798_6 >= 0 && sec_r000798_6 <= 255);
    __CPROVER_assume(sec_r000798_7 >= 0 && sec_r000798_7 <= 255);
    __CPROVER_assume(sec_r000798_8 >= 0 && sec_r000798_8 <= 255);
    __CPROVER_assume(sec_r000798_9 >= 0 && sec_r000798_9 <= 255);
    __CPROVER_assume(sec_r000798_10 >= 0 && sec_r000798_10 <= 255);
    __CPROVER_assume(sec_r000798_11 >= 0 && sec_r000798_11 <= 255);
    __CPROVER_assume(sec_r000798_12 >= 0 && sec_r000798_12 <= 255);
    __CPROVER_assume(sec_r000798_13 >= 0 && sec_r000798_13 <= 255);
    __CPROVER_assume(sec_r000798_14 >= 0 && sec_r000798_14 <= 255);
    __CPROVER_assume(sec_r000798_15 >= 0 && sec_r000798_15 <= 255);
    __CPROVER_assume(sec_r000798_16 >= 0 && sec_r000798_16 <= 255);
    __CPROVER_assume(sec_r000798_17 >= 0 && sec_r000798_17 <= 255);
    __CPROVER_assume(sec_r000798_18 >= 0 && sec_r000798_18 <= 255);
    __CPROVER_assume(sec_r000798_19 >= 0 && sec_r000798_19 <= 255);
    __CPROVER_assume(sec_r000798_20 >= 0 && sec_r000798_20 <= 255);
    __CPROVER_assume(sec_r000798_21 >= 0 && sec_r000798_21 <= 255);
    __CPROVER_assume(sec_r000798_22 >= 0 && sec_r000798_22 <= 255);
    __CPROVER_assume(sec_r000798_23 >= 0 && sec_r000798_23 <= 255);

    struct MatrixBlock_R000798_9813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000798_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000798_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000798_0 + 7) & 15;
    struct Transaction_R000798_9813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000798_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000798_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000798_0 + 9) & 15;
    struct AudioFrame_R000798_9813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000798_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000798_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000798_0 + 11) & 15;

    union RegisterBank_R000798_9813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 16) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 31) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 21) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 36) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 20) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 35) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 27) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 42) {
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
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 12) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 27) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 12) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 27) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 38) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 53) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_13 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_9 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000798_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000798_0) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000798_8) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000798_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000798_2) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_3 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000798_11) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000798_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_0 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_18 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_7 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_23 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_10 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000798_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000798_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000798_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_5 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000798_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_10 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000798_11) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000798_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_4 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000798_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_21 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000798_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_1 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_5 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000798_7) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000798_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_20 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000798_2) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000798_9) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000798_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_13 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000798_9) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_8 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000798_9) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000798_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000798_2) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000798_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_12 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000798_7) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_10 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000798_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_2 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000798_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_107 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000798_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_15 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000798_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_16 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000798_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000798_8) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_5 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000798_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_6 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000798_18) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000798_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_2 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000798_18) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000798_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_7 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000798_2) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000798_13) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000798_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_5 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000798_17) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000798_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_129 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_8 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000798_7) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000798_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_12 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000798_0) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_0 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000798_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_4 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000798_15) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000798_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_132 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000798_11) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000798_2) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000798_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_131 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_140 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_135 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000798_17) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000798_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000798_3) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000798_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_127 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_5 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_18 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000798_11) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_6 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000798_13) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_11 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000798_16) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000798_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_7 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_3 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000798_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000798_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_148 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000798_6) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000798_7) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000798_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_164 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000798_12) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000798_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_6 & 1) == step) {
            stage_v_168 = (stage_v_168 + step * 4 + pub_r000798_5) & 63;
        } else {
            stage_v_168 = (stage_v_168 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_169 = (stage_v_169 + step * 4 + pub_r000798_7) & 63;
        } else {
            stage_v_169 = (stage_v_169 + pub_r000798_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_10 & 1) == step) {
            stage_v_170 = (stage_v_170 + step * 4 + pub_r000798_10) & 63;
        } else {
            stage_v_170 = (stage_v_170 + pub_r000798_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_171 = (stage_v_171 + step * 4 + pub_r000798_4) & 63;
        } else {
            stage_v_171 = (stage_v_171 + pub_r000798_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_14 & 1) == step) {
            stage_v_172 = (stage_v_172 + step * 4 + pub_r000798_13) & 63;
        } else {
            stage_v_172 = (stage_v_172 + pub_r000798_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_156 & 1) == step) {
            stage_v_173 = (stage_v_173 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_173 = (stage_v_173 + pub_r000798_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_18 & 1) == step) {
            stage_v_174 = (stage_v_174 + step * 4 + pub_r000798_14) & 63;
        } else {
            stage_v_174 = (stage_v_174 + pub_r000798_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000798_7 & 1) == step) {
            stage_v_175 = (stage_v_175 + step * 4 + pub_r000798_8) & 63;
        } else {
            stage_v_175 = (stage_v_175 + pub_r000798_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_176 = (stage_v_176 + step * 4 + pub_r000798_17) & 63;
        } else {
            stage_v_176 = (stage_v_176 + pub_r000798_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_164 & 1) == step) {
            stage_v_177 = (stage_v_177 + step * 4 + pub_r000798_9) & 63;
        } else {
            stage_v_177 = (stage_v_177 + pub_r000798_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_178 = (stage_v_178 + step * 4 + pub_r000798_1) & 63;
        } else {
            stage_v_178 = (stage_v_178 + pub_r000798_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_179 = (stage_v_179 + step * 4 + pub_r000798_18) & 63;
        } else {
            stage_v_179 = (stage_v_179 + pub_r000798_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
