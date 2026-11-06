/*
 * Benchmark Program: R000679
 * Security Family: secret_dependent_array
 * Generator Seed: 567913
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000679_7913_0 {
    int signature;
    int timestamp;
    int severity;
    unsigned char code;
    int facility;
    int seq;
    int buffer[3];
};

struct FilterState_R000679_7913_1 {
    int cutoff;
    unsigned char mode;
    unsigned char gain_db;
    int prev_out;
    int prev_in;
    int buffer[3];
};

struct Transaction_R000679_7913_2 {
    unsigned char balance;
    int fee;
    short status;
    int rate;
    unsigned char account_id;
    int buffer[3];
};

struct MatrixBlock_R000679_7913_3 {
    int dim;
    short trace;
    unsigned char stride;
    int buffer[3];
};

union ColorPixel_R000679_7913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000679_7913_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_56 = local_arr[aux % 3];
    acc = (acc + anchor_56 * 2) & 127;
    int tracker_41 = (aux + st.buffer[1]) & 3;
    switch (tracker_41) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_1(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int mask_91 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_91 > 28) {
        acc = (acc + mask_91 * 2 + 5) & 127;
        aux ^= (mask_91 & 15);
    } else {
        acc = (acc - mask_91 + 11) & 127;
        aux += 3;
    }
    int scale_75 = (aux + st.buffer[1]) & 3;
    switch (scale_75) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_88 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_88 > 50) {
        acc = (acc + scale_88 * 2 + 5) & 127;
        aux ^= (scale_88 & 15);
    } else {
        acc = (acc - scale_88 + 11) & 127;
        aux += 3;
    }
    int vector_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int offset_83 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_83 > 34) {
        acc = (acc + offset_83 * 2 + 5) & 127;
        aux ^= (offset_83 & 15);
    } else {
        acc = (acc - offset_83 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_98 = local_arr[aux % 3];
    acc = (acc + quantum_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_74) & 63;
    acc ^= aux;
    int index_reg_35 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_35 > 48) {
        acc = (acc + index_reg_35 * 2 + 5) & 127;
        aux ^= (index_reg_35 & 15);
    } else {
        acc = (acc - index_reg_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_5(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_18 = local_arr[aux % 3];
    acc = (acc + sample_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_6(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_20 = (aux + st.buffer[1]) & 3;
    switch (checksum_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_54 = (aux + st.buffer[1]) & 3;
    switch (mask_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_60 = local_arr[aux % 3];
    acc = (acc + index_reg_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_8(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_24 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_24 > 22) {
        acc = (acc + tracker_24 * 2 + 5) & 127;
        aux ^= (tracker_24 & 15);
    } else {
        acc = (acc - tracker_24 + 11) & 127;
        aux += 3;
    }
    int sample_66 = (aux + st.buffer[1]) & 3;
    switch (sample_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_9(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_15 = (aux + st.buffer[1]) & 3;
    switch (mask_15) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_52) & 63;
    acc ^= aux;
    int parity_19 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_19 > 25) {
        acc = (acc + parity_19 * 2 + 5) & 127;
        aux ^= (parity_19 & 15);
    } else {
        acc = (acc - parity_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_73 = local_arr[aux % 3];
    acc = (acc + factor_73 * 2) & 127;
    int quotient_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_70) & 63;
    acc ^= aux;
    int phase_31 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_31 > 47) {
        acc = (acc + phase_31 * 2 + 5) & 127;
        aux ^= (phase_31 & 15);
    } else {
        acc = (acc - phase_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_11(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int metric_10 = local_arr[aux % 3];
    acc = (acc + metric_10 * 2) & 127;
    int pivot_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_13(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_58 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_58 > 30) {
        acc = (acc + margin_58 * 2 + 5) & 127;
        aux ^= (margin_58 & 15);
    } else {
        acc = (acc - margin_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_64 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_64 > 27) {
        acc = (acc + mask_64 * 2 + 5) & 127;
        aux ^= (mask_64 & 15);
    } else {
        acc = (acc - mask_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_33 = local_arr[aux % 3];
    acc = (acc + pivot_33 * 2) & 127;
    int factor_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_53) & 63;
    acc ^= aux;
    int offset_30 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_30 > 39) {
        acc = (acc + offset_30 * 2 + 5) & 127;
        aux ^= (offset_30 & 15);
    } else {
        acc = (acc - offset_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int quantum_10 = local_arr[aux % 3];
    acc = (acc + quantum_10 * 2) & 127;
    int parity_25 = (aux + st.buffer[1]) & 3;
    switch (parity_25) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_17(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    int residue_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int mask_66 = (aux + st.buffer[1]) & 3;
    switch (mask_66) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_16 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_16 > 38) {
        acc = (acc + parity_16 * 2 + 5) & 127;
        aux ^= (parity_16 & 15);
    } else {
        acc = (acc - parity_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int residue_15 = local_arr[aux % 3];
    acc = (acc + residue_15 * 2) & 127;
    int residue_45 = (aux + st.buffer[1]) & 3;
    switch (residue_45) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_96 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_96 > 15) {
        acc = (acc + factor_96 * 2 + 5) & 127;
        aux ^= (factor_96 & 15);
    } else {
        acc = (acc - factor_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int window_93 = (st.buffer[0] * 3 + aux) & 63;
    if (window_93 > 28) {
        acc = (acc + window_93 * 2 + 5) & 127;
        aux ^= (window_93 & 15);
    } else {
        acc = (acc - window_93 + 11) & 127;
        aux += 3;
    }
    int accumulator_42 = (aux + st.buffer[1]) & 3;
    switch (accumulator_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_43 = local_arr[aux % 3];
    acc = (acc + factor_43 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_79 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_79 > 47) {
        acc = (acc + phase_79 * 2 + 5) & 127;
        aux ^= (phase_79 & 15);
    } else {
        acc = (acc - phase_79 + 11) & 127;
        aux += 3;
    }
    int offset_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_44) & 63;
    acc ^= aux;
    int stride_90 = (aux + st.buffer[1]) & 3;
    switch (stride_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_22(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 18) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000679_0;
    int sec_r000679_1;
    int sec_r000679_2;
    int sec_r000679_3;
    int sec_r000679_4;
    int sec_r000679_5;
    int sec_r000679_6;
    int sec_r000679_7;
    int sec_r000679_8;
    int sec_r000679_9;
    int sec_r000679_10;
    int sec_r000679_11;
    int sec_r000679_12;
    int sec_r000679_13;
    int sec_r000679_14;
    int sec_r000679_15;
    int sec_r000679_16;
    int sec_r000679_17;
    int sec_r000679_18;
    int sec_r000679_19;
    int sec_r000679_20;
    int sec_r000679_21;
    int pub_r000679_0;
    int pub_r000679_1;
    int pub_r000679_2;
    int pub_r000679_3;
    int pub_r000679_4;
    int pub_r000679_5;
    int pub_r000679_6;
    int pub_r000679_7;
    int pub_r000679_8;
    int pub_r000679_9;
    int pub_r000679_10;
    int pub_r000679_11;
    int pub_r000679_12;
    int pub_r000679_13;
    int pub_r000679_14;
    int pub_r000679_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000679_0 >= -100 && pub_r000679_0 <= 100);
    __CPROVER_assume(pub_r000679_1 >= -100 && pub_r000679_1 <= 100);
    __CPROVER_assume(pub_r000679_2 >= -100 && pub_r000679_2 <= 100);
    __CPROVER_assume(pub_r000679_3 >= -100 && pub_r000679_3 <= 100);
    __CPROVER_assume(pub_r000679_4 >= -100 && pub_r000679_4 <= 100);
    __CPROVER_assume(pub_r000679_5 >= -100 && pub_r000679_5 <= 100);
    __CPROVER_assume(pub_r000679_6 >= -100 && pub_r000679_6 <= 100);
    __CPROVER_assume(pub_r000679_7 >= -100 && pub_r000679_7 <= 100);
    __CPROVER_assume(pub_r000679_8 >= -100 && pub_r000679_8 <= 100);
    __CPROVER_assume(pub_r000679_9 >= -100 && pub_r000679_9 <= 100);
    __CPROVER_assume(pub_r000679_10 >= -100 && pub_r000679_10 <= 100);
    __CPROVER_assume(pub_r000679_11 >= -100 && pub_r000679_11 <= 100);
    __CPROVER_assume(pub_r000679_12 >= -100 && pub_r000679_12 <= 100);
    __CPROVER_assume(pub_r000679_13 >= -100 && pub_r000679_13 <= 100);
    __CPROVER_assume(pub_r000679_14 >= -100 && pub_r000679_14 <= 100);
    __CPROVER_assume(pub_r000679_15 >= -100 && pub_r000679_15 <= 100);
    __CPROVER_assume(sec_r000679_0 >= 0 && sec_r000679_0 <= 255);
    __CPROVER_assume(sec_r000679_1 >= 0 && sec_r000679_1 <= 255);
    __CPROVER_assume(sec_r000679_2 >= 0 && sec_r000679_2 <= 255);
    __CPROVER_assume(sec_r000679_3 >= 0 && sec_r000679_3 <= 255);
    __CPROVER_assume(sec_r000679_4 >= 0 && sec_r000679_4 <= 255);
    __CPROVER_assume(sec_r000679_5 >= 0 && sec_r000679_5 <= 255);
    __CPROVER_assume(sec_r000679_6 >= 0 && sec_r000679_6 <= 255);
    __CPROVER_assume(sec_r000679_7 >= 0 && sec_r000679_7 <= 255);
    __CPROVER_assume(sec_r000679_8 >= 0 && sec_r000679_8 <= 255);
    __CPROVER_assume(sec_r000679_9 >= 0 && sec_r000679_9 <= 255);
    __CPROVER_assume(sec_r000679_10 >= 0 && sec_r000679_10 <= 255);
    __CPROVER_assume(sec_r000679_11 >= 0 && sec_r000679_11 <= 255);
    __CPROVER_assume(sec_r000679_12 >= 0 && sec_r000679_12 <= 255);
    __CPROVER_assume(sec_r000679_13 >= 0 && sec_r000679_13 <= 255);
    __CPROVER_assume(sec_r000679_14 >= 0 && sec_r000679_14 <= 255);
    __CPROVER_assume(sec_r000679_15 >= 0 && sec_r000679_15 <= 255);
    __CPROVER_assume(sec_r000679_16 >= 0 && sec_r000679_16 <= 255);
    __CPROVER_assume(sec_r000679_17 >= 0 && sec_r000679_17 <= 255);
    __CPROVER_assume(sec_r000679_18 >= 0 && sec_r000679_18 <= 255);
    __CPROVER_assume(sec_r000679_19 >= 0 && sec_r000679_19 <= 255);
    __CPROVER_assume(sec_r000679_20 >= 0 && sec_r000679_20 <= 255);
    __CPROVER_assume(sec_r000679_21 >= 0 && sec_r000679_21 <= 255);

    struct EventLog_R000679_7913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000679_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000679_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000679_0 + 7) & 15;
    struct FilterState_R000679_7913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000679_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000679_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000679_0 + 9) & 15;
    struct Transaction_R000679_7913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000679_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000679_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000679_0 + 11) & 15;
    struct MatrixBlock_R000679_7913_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000679_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000679_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000679_0 + 13) & 15;

    union ColorPixel_R000679_7913_0 u_var;
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
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

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
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 32) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 47) {
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
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 39) {
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
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
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
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 24) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 39) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 33) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 48) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 33) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 48) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 11) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 26) {
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
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 42) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 20) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 35) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 34) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 49) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 30) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 45) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 28) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 43) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 10) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 25) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 41) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int s_idx_94 = (sec_r000679_6 & 3);
    int stage_v_94 = (table[s_idx_94] + pub_r000679_2) & 127;
    table[s_idx_94] = (stage_v_94 + 7) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int s_idx_95 = (stage_v_94 & 3);
    int stage_v_95 = (table[s_idx_95] + pub_r000679_7) & 127;
    table[s_idx_95] = (stage_v_95 + 7) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int s_idx_96 = (stage_v_95 & 3);
    int stage_v_96 = (table[s_idx_96] + pub_r000679_2) & 127;
    table[s_idx_96] = (stage_v_96 + 7) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int s_idx_97 = (sec_r000679_1 & 3);
    int stage_v_97 = (table[s_idx_97] + pub_r000679_3) & 127;
    table[s_idx_97] = (stage_v_97 + 7) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int s_idx_98 = (stage_v_96 & 3);
    int stage_v_98 = (table[s_idx_98] + pub_r000679_1) & 127;
    table[s_idx_98] = (stage_v_98 + 7) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int s_idx_99 = (stage_v_96 & 3);
    int stage_v_99 = (table[s_idx_99] + pub_r000679_12) & 127;
    table[s_idx_99] = (stage_v_99 + 7) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int s_idx_100 = (sec_r000679_12 & 3);
    int stage_v_100 = (table[s_idx_100] + pub_r000679_11) & 127;
    table[s_idx_100] = (stage_v_100 + 7) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int s_idx_101 = (stage_v_97 & 3);
    int stage_v_101 = (table[s_idx_101] + pub_r000679_0) & 127;
    table[s_idx_101] = (stage_v_101 + 7) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int s_idx_102 = (sec_r000679_13 & 3);
    int stage_v_102 = (table[s_idx_102] + pub_r000679_2) & 127;
    table[s_idx_102] = (stage_v_102 + 7) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int s_idx_103 = (sec_r000679_21 & 3);
    int stage_v_103 = (table[s_idx_103] + pub_r000679_8) & 127;
    table[s_idx_103] = (stage_v_103 + 7) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int s_idx_104 = (stage_v_101 & 3);
    int stage_v_104 = (table[s_idx_104] + pub_r000679_4) & 127;
    table[s_idx_104] = (stage_v_104 + 7) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int s_idx_105 = (stage_v_95 & 3);
    int stage_v_105 = (table[s_idx_105] + pub_r000679_5) & 127;
    table[s_idx_105] = (stage_v_105 + 7) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int s_idx_106 = (stage_v_101 & 3);
    int stage_v_106 = (table[s_idx_106] + pub_r000679_13) & 127;
    table[s_idx_106] = (stage_v_106 + 7) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int s_idx_107 = (stage_v_94 & 3);
    int stage_v_107 = (table[s_idx_107] + pub_r000679_6) & 127;
    table[s_idx_107] = (stage_v_107 + 7) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int s_idx_108 = (stage_v_106 & 3);
    int stage_v_108 = (table[s_idx_108] + pub_r000679_9) & 127;
    table[s_idx_108] = (stage_v_108 + 7) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int s_idx_109 = (sec_r000679_13 & 3);
    int stage_v_109 = (table[s_idx_109] + pub_r000679_9) & 127;
    table[s_idx_109] = (stage_v_109 + 7) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int s_idx_110 = (stage_v_95 & 3);
    int stage_v_110 = (table[s_idx_110] + pub_r000679_9) & 127;
    table[s_idx_110] = (stage_v_110 + 7) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int s_idx_111 = (stage_v_100 & 3);
    int stage_v_111 = (table[s_idx_111] + pub_r000679_6) & 127;
    table[s_idx_111] = (stage_v_111 + 7) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int s_idx_112 = (stage_v_109 & 3);
    int stage_v_112 = (table[s_idx_112] + pub_r000679_15) & 127;
    table[s_idx_112] = (stage_v_112 + 7) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int s_idx_113 = (sec_r000679_7 & 3);
    int stage_v_113 = (table[s_idx_113] + pub_r000679_12) & 127;
    table[s_idx_113] = (stage_v_113 + 7) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int s_idx_114 = (stage_v_101 & 3);
    int stage_v_114 = (table[s_idx_114] + pub_r000679_8) & 127;
    table[s_idx_114] = (stage_v_114 + 7) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int s_idx_115 = (stage_v_100 & 3);
    int stage_v_115 = (table[s_idx_115] + pub_r000679_8) & 127;
    table[s_idx_115] = (stage_v_115 + 7) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int s_idx_116 = (stage_v_98 & 3);
    int stage_v_116 = (table[s_idx_116] + pub_r000679_6) & 127;
    table[s_idx_116] = (stage_v_116 + 7) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int s_idx_117 = (stage_v_105 & 3);
    int stage_v_117 = (table[s_idx_117] + pub_r000679_15) & 127;
    table[s_idx_117] = (stage_v_117 + 7) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int s_idx_118 = (sec_r000679_4 & 3);
    int stage_v_118 = (table[s_idx_118] + pub_r000679_6) & 127;
    table[s_idx_118] = (stage_v_118 + 7) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int s_idx_119 = (stage_v_111 & 3);
    int stage_v_119 = (table[s_idx_119] + pub_r000679_8) & 127;
    table[s_idx_119] = (stage_v_119 + 7) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int s_idx_120 = (stage_v_116 & 3);
    int stage_v_120 = (table[s_idx_120] + pub_r000679_12) & 127;
    table[s_idx_120] = (stage_v_120 + 7) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int s_idx_121 = (stage_v_102 & 3);
    int stage_v_121 = (table[s_idx_121] + pub_r000679_11) & 127;
    table[s_idx_121] = (stage_v_121 + 7) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int s_idx_122 = (stage_v_95 & 3);
    int stage_v_122 = (table[s_idx_122] + pub_r000679_14) & 127;
    table[s_idx_122] = (stage_v_122 + 7) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int s_idx_123 = (stage_v_105 & 3);
    int stage_v_123 = (table[s_idx_123] + pub_r000679_13) & 127;
    table[s_idx_123] = (stage_v_123 + 7) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int s_idx_124 = (stage_v_104 & 3);
    int stage_v_124 = (table[s_idx_124] + pub_r000679_11) & 127;
    table[s_idx_124] = (stage_v_124 + 7) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int s_idx_125 = (stage_v_96 & 3);
    int stage_v_125 = (table[s_idx_125] + pub_r000679_14) & 127;
    table[s_idx_125] = (stage_v_125 + 7) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int s_idx_126 = (sec_r000679_4 & 3);
    int stage_v_126 = (table[s_idx_126] + pub_r000679_3) & 127;
    table[s_idx_126] = (stage_v_126 + 7) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int s_idx_127 = (sec_r000679_8 & 3);
    int stage_v_127 = (table[s_idx_127] + pub_r000679_3) & 127;
    table[s_idx_127] = (stage_v_127 + 7) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int s_idx_128 = (stage_v_119 & 3);
    int stage_v_128 = (table[s_idx_128] + pub_r000679_7) & 127;
    table[s_idx_128] = (stage_v_128 + 7) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int s_idx_129 = (stage_v_99 & 3);
    int stage_v_129 = (table[s_idx_129] + pub_r000679_11) & 127;
    table[s_idx_129] = (stage_v_129 + 7) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int s_idx_130 = (sec_r000679_18 & 3);
    int stage_v_130 = (table[s_idx_130] + pub_r000679_1) & 127;
    table[s_idx_130] = (stage_v_130 + 7) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int s_idx_131 = (stage_v_130 & 3);
    int stage_v_131 = (table[s_idx_131] + pub_r000679_5) & 127;
    table[s_idx_131] = (stage_v_131 + 7) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int s_idx_132 = (stage_v_120 & 3);
    int stage_v_132 = (table[s_idx_132] + pub_r000679_11) & 127;
    table[s_idx_132] = (stage_v_132 + 7) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int s_idx_133 = (stage_v_132 & 3);
    int stage_v_133 = (table[s_idx_133] + pub_r000679_15) & 127;
    table[s_idx_133] = (stage_v_133 + 7) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int s_idx_134 = (sec_r000679_18 & 3);
    int stage_v_134 = (table[s_idx_134] + pub_r000679_2) & 127;
    table[s_idx_134] = (stage_v_134 + 7) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int s_idx_135 = (stage_v_119 & 3);
    int stage_v_135 = (table[s_idx_135] + pub_r000679_9) & 127;
    table[s_idx_135] = (stage_v_135 + 7) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int s_idx_136 = (sec_r000679_21 & 3);
    int stage_v_136 = (table[s_idx_136] + pub_r000679_2) & 127;
    table[s_idx_136] = (stage_v_136 + 7) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int s_idx_137 = (stage_v_97 & 3);
    int stage_v_137 = (table[s_idx_137] + pub_r000679_14) & 127;
    table[s_idx_137] = (stage_v_137 + 7) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int s_idx_138 = (stage_v_121 & 3);
    int stage_v_138 = (table[s_idx_138] + pub_r000679_9) & 127;
    table[s_idx_138] = (stage_v_138 + 7) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int s_idx_139 = (sec_r000679_19 & 3);
    int stage_v_139 = (table[s_idx_139] + pub_r000679_1) & 127;
    table[s_idx_139] = (stage_v_139 + 7) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int s_idx_140 = (stage_v_110 & 3);
    int stage_v_140 = (table[s_idx_140] + pub_r000679_11) & 127;
    table[s_idx_140] = (stage_v_140 + 7) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int s_idx_141 = (stage_v_122 & 3);
    int stage_v_141 = (table[s_idx_141] + pub_r000679_11) & 127;
    table[s_idx_141] = (stage_v_141 + 7) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int s_idx_142 = (stage_v_136 & 3);
    int stage_v_142 = (table[s_idx_142] + pub_r000679_1) & 127;
    table[s_idx_142] = (stage_v_142 + 7) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int s_idx_143 = (stage_v_108 & 3);
    int stage_v_143 = (table[s_idx_143] + pub_r000679_4) & 127;
    table[s_idx_143] = (stage_v_143 + 7) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int s_idx_144 = (stage_v_114 & 3);
    int stage_v_144 = (table[s_idx_144] + pub_r000679_7) & 127;
    table[s_idx_144] = (stage_v_144 + 7) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int s_idx_145 = (stage_v_111 & 3);
    int stage_v_145 = (table[s_idx_145] + pub_r000679_11) & 127;
    table[s_idx_145] = (stage_v_145 + 7) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int s_idx_146 = (sec_r000679_19 & 3);
    int stage_v_146 = (table[s_idx_146] + pub_r000679_3) & 127;
    table[s_idx_146] = (stage_v_146 + 7) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int s_idx_147 = (stage_v_119 & 3);
    int stage_v_147 = (table[s_idx_147] + pub_r000679_8) & 127;
    table[s_idx_147] = (stage_v_147 + 7) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int s_idx_148 = (sec_r000679_8 & 3);
    int stage_v_148 = (table[s_idx_148] + pub_r000679_15) & 127;
    table[s_idx_148] = (stage_v_148 + 7) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int s_idx_149 = (sec_r000679_9 & 3);
    int stage_v_149 = (table[s_idx_149] + pub_r000679_4) & 127;
    table[s_idx_149] = (stage_v_149 + 7) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int s_idx_150 = (sec_r000679_13 & 3);
    int stage_v_150 = (table[s_idx_150] + pub_r000679_12) & 127;
    table[s_idx_150] = (stage_v_150 + 7) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int s_idx_151 = (stage_v_133 & 3);
    int stage_v_151 = (table[s_idx_151] + pub_r000679_11) & 127;
    table[s_idx_151] = (stage_v_151 + 7) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int s_idx_152 = (stage_v_138 & 3);
    int stage_v_152 = (table[s_idx_152] + pub_r000679_3) & 127;
    table[s_idx_152] = (stage_v_152 + 7) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int s_idx_153 = (stage_v_108 & 3);
    int stage_v_153 = (table[s_idx_153] + pub_r000679_6) & 127;
    table[s_idx_153] = (stage_v_153 + 7) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int s_idx_154 = (stage_v_116 & 3);
    int stage_v_154 = (table[s_idx_154] + pub_r000679_9) & 127;
    table[s_idx_154] = (stage_v_154 + 7) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int s_idx_155 = (stage_v_103 & 3);
    int stage_v_155 = (table[s_idx_155] + pub_r000679_11) & 127;
    table[s_idx_155] = (stage_v_155 + 7) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int s_idx_156 = (stage_v_150 & 3);
    int stage_v_156 = (table[s_idx_156] + pub_r000679_7) & 127;
    table[s_idx_156] = (stage_v_156 + 7) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int s_idx_157 = (sec_r000679_16 & 3);
    int stage_v_157 = (table[s_idx_157] + pub_r000679_15) & 127;
    table[s_idx_157] = (stage_v_157 + 7) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int s_idx_158 = (sec_r000679_4 & 3);
    int stage_v_158 = (table[s_idx_158] + pub_r000679_12) & 127;
    table[s_idx_158] = (stage_v_158 + 7) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int s_idx_159 = (sec_r000679_12 & 3);
    int stage_v_159 = (table[s_idx_159] + pub_r000679_4) & 127;
    table[s_idx_159] = (stage_v_159 + 7) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int s_idx_160 = (stage_v_151 & 3);
    int stage_v_160 = (table[s_idx_160] + pub_r000679_10) & 127;
    table[s_idx_160] = (stage_v_160 + 7) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int s_idx_161 = (stage_v_159 & 3);
    int stage_v_161 = (table[s_idx_161] + pub_r000679_10) & 127;
    table[s_idx_161] = (stage_v_161 + 7) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int s_idx_162 = (stage_v_134 & 3);
    int stage_v_162 = (table[s_idx_162] + pub_r000679_6) & 127;
    table[s_idx_162] = (stage_v_162 + 7) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int s_idx_163 = (sec_r000679_4 & 3);
    int stage_v_163 = (table[s_idx_163] + pub_r000679_1) & 127;
    table[s_idx_163] = (stage_v_163 + 7) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int s_idx_164 = (sec_r000679_2 & 3);
    int stage_v_164 = (table[s_idx_164] + pub_r000679_11) & 127;
    table[s_idx_164] = (stage_v_164 + 7) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int s_idx_165 = (stage_v_114 & 3);
    int stage_v_165 = (table[s_idx_165] + pub_r000679_11) & 127;
    table[s_idx_165] = (stage_v_165 + 7) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int s_idx_166 = (sec_r000679_17 & 3);
    int stage_v_166 = (table[s_idx_166] + pub_r000679_7) & 127;
    table[s_idx_166] = (stage_v_166 + 7) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int s_idx_167 = (stage_v_159 & 3);
    int stage_v_167 = (table[s_idx_167] + pub_r000679_12) & 127;
    table[s_idx_167] = (stage_v_167 + 7) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int s_idx_168 = (stage_v_143 & 3);
    int stage_v_168 = (table[s_idx_168] + pub_r000679_6) & 127;
    table[s_idx_168] = (stage_v_168 + 7) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int s_idx_169 = (stage_v_160 & 3);
    int stage_v_169 = (table[s_idx_169] + pub_r000679_7) & 127;
    table[s_idx_169] = (stage_v_169 + 7) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int s_idx_170 = (sec_r000679_13 & 3);
    int stage_v_170 = (table[s_idx_170] + pub_r000679_1) & 127;
    table[s_idx_170] = (stage_v_170 + 7) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int s_idx_171 = (stage_v_155 & 3);
    int stage_v_171 = (table[s_idx_171] + pub_r000679_10) & 127;
    table[s_idx_171] = (stage_v_171 + 7) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int s_idx_172 = (stage_v_117 & 3);
    int stage_v_172 = (table[s_idx_172] + pub_r000679_7) & 127;
    table[s_idx_172] = (stage_v_172 + 7) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int s_idx_173 = (stage_v_122 & 3);
    int stage_v_173 = (table[s_idx_173] + pub_r000679_13) & 127;
    table[s_idx_173] = (stage_v_173 + 7) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int s_idx_174 = (stage_v_122 & 3);
    int stage_v_174 = (table[s_idx_174] + pub_r000679_11) & 127;
    table[s_idx_174] = (stage_v_174 + 7) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int s_idx_175 = (stage_v_161 & 3);
    int stage_v_175 = (table[s_idx_175] + pub_r000679_13) & 127;
    table[s_idx_175] = (stage_v_175 + 7) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int s_idx_176 = (stage_v_133 & 3);
    int stage_v_176 = (table[s_idx_176] + pub_r000679_6) & 127;
    table[s_idx_176] = (stage_v_176 + 7) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int s_idx_177 = (stage_v_127 & 3);
    int stage_v_177 = (table[s_idx_177] + pub_r000679_2) & 127;
    table[s_idx_177] = (stage_v_177 + 7) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int s_idx_178 = (stage_v_107 & 3);
    int stage_v_178 = (table[s_idx_178] + pub_r000679_2) & 127;
    table[s_idx_178] = (stage_v_178 + 7) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int s_idx_179 = (stage_v_107 & 3);
    int stage_v_179 = (table[s_idx_179] + pub_r000679_3) & 127;
    table[s_idx_179] = (stage_v_179 + 7) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int s_idx_180 = (sec_r000679_5 & 3);
    int stage_v_180 = (table[s_idx_180] + pub_r000679_12) & 127;
    table[s_idx_180] = (stage_v_180 + 7) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int s_idx_181 = (stage_v_110 & 3);
    int stage_v_181 = (table[s_idx_181] + pub_r000679_15) & 127;
    table[s_idx_181] = (stage_v_181 + 7) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int s_idx_182 = (stage_v_95 & 3);
    int stage_v_182 = (table[s_idx_182] + pub_r000679_3) & 127;
    table[s_idx_182] = (stage_v_182 + 7) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int s_idx_183 = (stage_v_104 & 3);
    int stage_v_183 = (table[s_idx_183] + pub_r000679_14) & 127;
    table[s_idx_183] = (stage_v_183 + 7) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int s_idx_184 = (stage_v_128 & 3);
    int stage_v_184 = (table[s_idx_184] + pub_r000679_14) & 127;
    table[s_idx_184] = (stage_v_184 + 7) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int s_idx_185 = (sec_r000679_18 & 3);
    int stage_v_185 = (table[s_idx_185] + pub_r000679_5) & 127;
    table[s_idx_185] = (stage_v_185 + 7) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int s_idx_186 = (stage_v_132 & 3);
    int stage_v_186 = (table[s_idx_186] + pub_r000679_11) & 127;
    table[s_idx_186] = (stage_v_186 + 7) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int s_idx_187 = (sec_r000679_21 & 3);
    int stage_v_187 = (table[s_idx_187] + pub_r000679_13) & 127;
    table[s_idx_187] = (stage_v_187 + 7) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int s_idx_188 = (stage_v_168 & 3);
    int stage_v_188 = (table[s_idx_188] + pub_r000679_8) & 127;
    table[s_idx_188] = (stage_v_188 + 7) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int s_idx_189 = (stage_v_171 & 3);
    int stage_v_189 = (table[s_idx_189] + pub_r000679_11) & 127;
    table[s_idx_189] = (stage_v_189 + 7) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int s_idx_190 = (stage_v_99 & 3);
    int stage_v_190 = (table[s_idx_190] + pub_r000679_1) & 127;
    table[s_idx_190] = (stage_v_190 + 7) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int s_idx_191 = (stage_v_184 & 3);
    int stage_v_191 = (table[s_idx_191] + pub_r000679_0) & 127;
    table[s_idx_191] = (stage_v_191 + 7) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int s_idx_192 = (stage_v_145 & 3);
    int stage_v_192 = (table[s_idx_192] + pub_r000679_3) & 127;
    table[s_idx_192] = (stage_v_192 + 7) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int s_idx_193 = (stage_v_132 & 3);
    int stage_v_193 = (table[s_idx_193] + pub_r000679_0) & 127;
    table[s_idx_193] = (stage_v_193 + 7) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int s_idx_194 = (stage_v_143 & 3);
    int stage_v_194 = (table[s_idx_194] + pub_r000679_7) & 127;
    table[s_idx_194] = (stage_v_194 + 7) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int s_idx_195 = (stage_v_189 & 3);
    int stage_v_195 = (table[s_idx_195] + pub_r000679_0) & 127;
    table[s_idx_195] = (stage_v_195 + 7) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int s_idx_196 = (sec_r000679_3 & 3);
    int stage_v_196 = (table[s_idx_196] + pub_r000679_1) & 127;
    table[s_idx_196] = (stage_v_196 + 7) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int s_idx_197 = (sec_r000679_8 & 3);
    int stage_v_197 = (table[s_idx_197] + pub_r000679_1) & 127;
    table[s_idx_197] = (stage_v_197 + 7) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int s_idx_198 = (stage_v_99 & 3);
    int stage_v_198 = (table[s_idx_198] + pub_r000679_7) & 127;
    table[s_idx_198] = (stage_v_198 + 7) & 63;
    out_sink = (out_sink + stage_v_198) & 255;
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int s_idx_199 = (stage_v_114 & 3);
    int stage_v_199 = (table[s_idx_199] + pub_r000679_5) & 127;
    table[s_idx_199] = (stage_v_199 + 7) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int s_idx_200 = (stage_v_169 & 3);
    int stage_v_200 = (table[s_idx_200] + pub_r000679_0) & 127;
    table[s_idx_200] = (stage_v_200 + 7) & 63;
    out_sink = (out_sink + stage_v_200) & 255;
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int s_idx_201 = (sec_r000679_17 & 3);
    int stage_v_201 = (table[s_idx_201] + pub_r000679_10) & 127;
    table[s_idx_201] = (stage_v_201 + 7) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int s_idx_202 = (stage_v_110 & 3);
    int stage_v_202 = (table[s_idx_202] + pub_r000679_8) & 127;
    table[s_idx_202] = (stage_v_202 + 7) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int s_idx_203 = (sec_r000679_8 & 3);
    int stage_v_203 = (table[s_idx_203] + pub_r000679_13) & 127;
    table[s_idx_203] = (stage_v_203 + 7) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int s_idx_204 = (stage_v_180 & 3);
    int stage_v_204 = (table[s_idx_204] + pub_r000679_12) & 127;
    table[s_idx_204] = (stage_v_204 + 7) & 63;
    out_sink = (out_sink + stage_v_204) & 255;
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int s_idx_205 = (sec_r000679_6 & 3);
    int stage_v_205 = (table[s_idx_205] + pub_r000679_10) & 127;
    table[s_idx_205] = (stage_v_205 + 7) & 63;
    out_sink = (out_sink + stage_v_205) & 255;
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int s_idx_206 = (stage_v_162 & 3);
    int stage_v_206 = (table[s_idx_206] + pub_r000679_12) & 127;
    table[s_idx_206] = (stage_v_206 + 7) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int s_idx_207 = (stage_v_141 & 3);
    int stage_v_207 = (table[s_idx_207] + pub_r000679_6) & 127;
    table[s_idx_207] = (stage_v_207 + 7) & 63;
    out_sink = (out_sink + stage_v_207) & 255;
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int s_idx_208 = (sec_r000679_18 & 3);
    int stage_v_208 = (table[s_idx_208] + pub_r000679_1) & 127;
    table[s_idx_208] = (stage_v_208 + 7) & 63;
    out_sink = (out_sink + stage_v_208) & 255;
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int s_idx_209 = (stage_v_148 & 3);
    int stage_v_209 = (table[s_idx_209] + pub_r000679_0) & 127;
    table[s_idx_209] = (stage_v_209 + 7) & 63;
    out_sink = (out_sink + stage_v_209) & 255;
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int s_idx_210 = (stage_v_138 & 3);
    int stage_v_210 = (table[s_idx_210] + pub_r000679_10) & 127;
    table[s_idx_210] = (stage_v_210 + 7) & 63;
    out_sink = (out_sink + stage_v_210) & 255;
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int s_idx_211 = (stage_v_167 & 3);
    int stage_v_211 = (table[s_idx_211] + pub_r000679_10) & 127;
    table[s_idx_211] = (stage_v_211 + 7) & 63;
    out_sink = (out_sink + stage_v_211) & 255;
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int s_idx_212 = (sec_r000679_13 & 3);
    int stage_v_212 = (table[s_idx_212] + pub_r000679_10) & 127;
    table[s_idx_212] = (stage_v_212 + 7) & 63;
    out_sink = (out_sink + stage_v_212) & 255;
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int s_idx_213 = (stage_v_167 & 3);
    int stage_v_213 = (table[s_idx_213] + pub_r000679_10) & 127;
    table[s_idx_213] = (stage_v_213 + 7) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int s_idx_214 = (sec_r000679_3 & 3);
    int stage_v_214 = (table[s_idx_214] + pub_r000679_3) & 127;
    table[s_idx_214] = (stage_v_214 + 7) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int s_idx_215 = (stage_v_142 & 3);
    int stage_v_215 = (table[s_idx_215] + pub_r000679_14) & 127;
    table[s_idx_215] = (stage_v_215 + 7) & 63;
    out_sink = (out_sink + stage_v_215) & 255;
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int s_idx_216 = (stage_v_107 & 3);
    int stage_v_216 = (table[s_idx_216] + pub_r000679_11) & 127;
    table[s_idx_216] = (stage_v_216 + 7) & 63;
    out_sink = (out_sink + stage_v_216) & 255;
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int s_idx_217 = (stage_v_121 & 3);
    int stage_v_217 = (table[s_idx_217] + pub_r000679_3) & 127;
    table[s_idx_217] = (stage_v_217 + 7) & 63;
    out_sink = (out_sink + stage_v_217) & 255;
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int s_idx_218 = (stage_v_130 & 3);
    int stage_v_218 = (table[s_idx_218] + pub_r000679_1) & 127;
    table[s_idx_218] = (stage_v_218 + 7) & 63;
    out_sink = (out_sink + stage_v_218) & 255;
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int s_idx_219 = (stage_v_218 & 3);
    int stage_v_219 = (table[s_idx_219] + pub_r000679_8) & 127;
    table[s_idx_219] = (stage_v_219 + 7) & 63;
    out_sink = (out_sink + stage_v_219) & 255;
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int s_idx_220 = (stage_v_160 & 3);
    int stage_v_220 = (table[s_idx_220] + pub_r000679_9) & 127;
    table[s_idx_220] = (stage_v_220 + 7) & 63;
    out_sink = (out_sink + stage_v_220) & 255;
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int s_idx_221 = (stage_v_117 & 3);
    int stage_v_221 = (table[s_idx_221] + pub_r000679_8) & 127;
    table[s_idx_221] = (stage_v_221 + 7) & 63;
    out_sink = (out_sink + stage_v_221) & 255;
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int s_idx_222 = (sec_r000679_3 & 3);
    int stage_v_222 = (table[s_idx_222] + pub_r000679_7) & 127;
    table[s_idx_222] = (stage_v_222 + 7) & 63;
    out_sink = (out_sink + stage_v_222) & 255;
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int s_idx_223 = (sec_r000679_13 & 3);
    int stage_v_223 = (table[s_idx_223] + pub_r000679_4) & 127;
    table[s_idx_223] = (stage_v_223 + 7) & 63;
    out_sink = (out_sink + stage_v_223) & 255;
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int s_idx_224 = (stage_v_106 & 3);
    int stage_v_224 = (table[s_idx_224] + pub_r000679_4) & 127;
    table[s_idx_224] = (stage_v_224 + 7) & 63;
    out_sink = (out_sink + stage_v_224) & 255;
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int s_idx_225 = (stage_v_105 & 3);
    int stage_v_225 = (table[s_idx_225] + pub_r000679_4) & 127;
    table[s_idx_225] = (stage_v_225 + 7) & 63;
    out_sink = (out_sink + stage_v_225) & 255;
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int s_idx_226 = (sec_r000679_12 & 3);
    int stage_v_226 = (table[s_idx_226] + pub_r000679_1) & 127;
    table[s_idx_226] = (stage_v_226 + 7) & 63;
    out_sink = (out_sink + stage_v_226) & 255;
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int s_idx_227 = (stage_v_101 & 3);
    int stage_v_227 = (table[s_idx_227] + pub_r000679_11) & 127;
    table[s_idx_227] = (stage_v_227 + 7) & 63;
    out_sink = (out_sink + stage_v_227) & 255;
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int s_idx_228 = (stage_v_216 & 3);
    int stage_v_228 = (table[s_idx_228] + pub_r000679_3) & 127;
    table[s_idx_228] = (stage_v_228 + 7) & 63;
    out_sink = (out_sink + stage_v_228) & 255;
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int s_idx_229 = (sec_r000679_10 & 3);
    int stage_v_229 = (table[s_idx_229] + pub_r000679_4) & 127;
    table[s_idx_229] = (stage_v_229 + 7) & 63;
    out_sink = (out_sink + stage_v_229) & 255;
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int s_idx_230 = (stage_v_168 & 3);
    int stage_v_230 = (table[s_idx_230] + pub_r000679_9) & 127;
    table[s_idx_230] = (stage_v_230 + 7) & 63;
    out_sink = (out_sink + stage_v_230) & 255;
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int s_idx_231 = (sec_r000679_17 & 3);
    int stage_v_231 = (table[s_idx_231] + pub_r000679_4) & 127;
    table[s_idx_231] = (stage_v_231 + 7) & 63;
    out_sink = (out_sink + stage_v_231) & 255;
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int s_idx_232 = (sec_r000679_8 & 3);
    int stage_v_232 = (table[s_idx_232] + pub_r000679_6) & 127;
    table[s_idx_232] = (stage_v_232 + 7) & 63;
    out_sink = (out_sink + stage_v_232) & 255;
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int s_idx_233 = (stage_v_172 & 3);
    int stage_v_233 = (table[s_idx_233] + pub_r000679_10) & 127;
    table[s_idx_233] = (stage_v_233 + 7) & 63;
    out_sink = (out_sink + stage_v_233) & 255;
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int s_idx_234 = (stage_v_176 & 3);
    int stage_v_234 = (table[s_idx_234] + pub_r000679_5) & 127;
    table[s_idx_234] = (stage_v_234 + 7) & 63;
    out_sink = (out_sink + stage_v_234) & 255;
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int s_idx_235 = (stage_v_107 & 3);
    int stage_v_235 = (table[s_idx_235] + pub_r000679_13) & 127;
    table[s_idx_235] = (stage_v_235 + 7) & 63;
    out_sink = (out_sink + stage_v_235) & 255;
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int s_idx_236 = (sec_r000679_12 & 3);
    int stage_v_236 = (table[s_idx_236] + pub_r000679_7) & 127;
    table[s_idx_236] = (stage_v_236 + 7) & 63;
    out_sink = (out_sink + stage_v_236) & 255;
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int s_idx_237 = (stage_v_120 & 3);
    int stage_v_237 = (table[s_idx_237] + pub_r000679_8) & 127;
    table[s_idx_237] = (stage_v_237 + 7) & 63;
    out_sink = (out_sink + stage_v_237) & 255;
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int s_idx_238 = (stage_v_144 & 3);
    int stage_v_238 = (table[s_idx_238] + pub_r000679_13) & 127;
    table[s_idx_238] = (stage_v_238 + 7) & 63;
    out_sink = (out_sink + stage_v_238) & 255;
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int s_idx_239 = (stage_v_197 & 3);
    int stage_v_239 = (table[s_idx_239] + pub_r000679_5) & 127;
    table[s_idx_239] = (stage_v_239 + 7) & 63;
    out_sink = (out_sink + stage_v_239) & 255;
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int s_idx_240 = (sec_r000679_0 & 3);
    int stage_v_240 = (table[s_idx_240] + pub_r000679_0) & 127;
    table[s_idx_240] = (stage_v_240 + 7) & 63;
    out_sink = (out_sink + stage_v_240) & 255;
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int s_idx_241 = (sec_r000679_2 & 3);
    int stage_v_241 = (table[s_idx_241] + pub_r000679_6) & 127;
    table[s_idx_241] = (stage_v_241 + 7) & 63;
    out_sink = (out_sink + stage_v_241) & 255;
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int s_idx_242 = (sec_r000679_13 & 3);
    int stage_v_242 = (table[s_idx_242] + pub_r000679_6) & 127;
    table[s_idx_242] = (stage_v_242 + 7) & 63;
    out_sink = (out_sink + stage_v_242) & 255;
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int s_idx_243 = (sec_r000679_6 & 3);
    int stage_v_243 = (table[s_idx_243] + pub_r000679_11) & 127;
    table[s_idx_243] = (stage_v_243 + 7) & 63;
    out_sink = (out_sink + stage_v_243) & 255;
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int s_idx_244 = (stage_v_195 & 3);
    int stage_v_244 = (table[s_idx_244] + pub_r000679_4) & 127;
    table[s_idx_244] = (stage_v_244 + 7) & 63;
    out_sink = (out_sink + stage_v_244) & 255;
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int s_idx_245 = (stage_v_133 & 3);
    int stage_v_245 = (table[s_idx_245] + pub_r000679_8) & 127;
    table[s_idx_245] = (stage_v_245 + 7) & 63;
    out_sink = (out_sink + stage_v_245) & 255;
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int s_idx_246 = (sec_r000679_21 & 3);
    int stage_v_246 = (table[s_idx_246] + pub_r000679_1) & 127;
    table[s_idx_246] = (stage_v_246 + 7) & 63;
    out_sink = (out_sink + stage_v_246) & 255;
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int s_idx_247 = (sec_r000679_4 & 3);
    int stage_v_247 = (table[s_idx_247] + pub_r000679_9) & 127;
    table[s_idx_247] = (stage_v_247 + 7) & 63;
    out_sink = (out_sink + stage_v_247) & 255;
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int s_idx_248 = (sec_r000679_14 & 3);
    int stage_v_248 = (table[s_idx_248] + pub_r000679_5) & 127;
    table[s_idx_248] = (stage_v_248 + 7) & 63;
    out_sink = (out_sink + stage_v_248) & 255;
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int s_idx_249 = (stage_v_105 & 3);
    int stage_v_249 = (table[s_idx_249] + pub_r000679_3) & 127;
    table[s_idx_249] = (stage_v_249 + 7) & 63;
    out_sink = (out_sink + stage_v_249) & 255;
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int s_idx_250 = (stage_v_231 & 3);
    int stage_v_250 = (table[s_idx_250] + pub_r000679_12) & 127;
    table[s_idx_250] = (stage_v_250 + 7) & 63;
    out_sink = (out_sink + stage_v_250) & 255;
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int s_idx_251 = (stage_v_245 & 3);
    int stage_v_251 = (table[s_idx_251] + pub_r000679_10) & 127;
    table[s_idx_251] = (stage_v_251 + 7) & 63;
    out_sink = (out_sink + stage_v_251) & 255;
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
