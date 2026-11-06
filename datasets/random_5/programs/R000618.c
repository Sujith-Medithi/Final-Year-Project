/*
 * Benchmark Program: R000618
 * Security Family: secret_dependent_loops
 * Generator Seed: 561813
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000618_1813_0 {
    unsigned char facility;
    int seq;
    short code;
    int signature;
    unsigned char timestamp;
    short severity;
    int buffer[3];
};

struct FilterState_R000618_1813_1 {
    unsigned char gain_db;
    int prev_in;
    int cutoff;
    int mode;
    int buffer[3];
};

struct CipherContext_R000618_1813_2 {
    int iv;
    int nonce;
    short counter;
    int buffer[3];
};

union PacketPayload_R000618_1813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000618_1813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int offset_42 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_42 > 23) {
        acc = (acc + offset_42 * 2 + 5) & 127;
        aux ^= (offset_42 & 15);
    } else {
        acc = (acc - offset_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_44 = local_arr[aux % 3];
    acc = (acc + cursor_44 * 2) & 127;
    int stride_20 = (aux + st.buffer[1]) & 3;
    switch (stride_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_22 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_22 > 46) {
        acc = (acc + quotient_22 * 2 + 5) & 127;
        aux ^= (quotient_22 & 15);
    } else {
        acc = (acc - quotient_22 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_83 = (aux + st.buffer[1]) & 3;
    switch (scale_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_30 = local_arr[aux % 3];
    acc = (acc + threshold_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_2(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_26 = local_arr[aux % 3];
    acc = (acc + index_reg_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_3(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_77 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_77 > 32) {
        acc = (acc + quantum_77 * 2 + 5) & 127;
        aux ^= (quantum_77 & 15);
    } else {
        acc = (acc - quantum_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_13 = local_arr[aux % 3];
    acc = (acc + segment_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_78 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_78 > 35) {
        acc = (acc + cursor_78 * 2 + 5) & 127;
        aux ^= (cursor_78 & 15);
    } else {
        acc = (acc - cursor_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_64 = local_arr[aux % 3];
    acc = (acc + phase_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_5(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_32 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_32 > 37) {
        acc = (acc + segment_32 * 2 + 5) & 127;
        aux ^= (segment_32 & 15);
    } else {
        acc = (acc - segment_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_75 = local_arr[aux % 3];
    acc = (acc + delta_75 * 2) & 127;
    int coefficient_80 = (aux + st.buffer[1]) & 3;
    switch (coefficient_80) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000618_1813_6(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_73 = (aux + st.buffer[1]) & 3;
    switch (factor_73) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_76 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_76 > 20) {
        acc = (acc + scale_76 * 2 + 5) & 127;
        aux ^= (scale_76 & 15);
    } else {
        acc = (acc - scale_76 + 11) & 127;
        aux += 3;
    }
    int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_28 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_28 > 20) {
        acc = (acc + anchor_28 * 2 + 5) & 127;
        aux ^= (anchor_28 & 15);
    } else {
        acc = (acc - anchor_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_24 > 50) {
        acc = (acc + cursor_24 * 2 + 5) & 127;
        aux ^= (cursor_24 & 15);
    } else {
        acc = (acc - cursor_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_75 = local_arr[aux % 3];
    acc = (acc + tally_75 * 2) & 127;
    int cursor_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_52 = (aux + st.buffer[1]) & 3;
    switch (delta_52) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_14) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_11(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_12(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_13) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_74 = local_arr[aux % 3];
    acc = (acc + quantum_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_13(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_33 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_33 > 36) {
        acc = (acc + delta_33 * 2 + 5) & 127;
        aux ^= (delta_33 & 15);
    } else {
        acc = (acc - delta_33 + 11) & 127;
        aux += 3;
    }
    int index_reg_12 = (aux + st.buffer[1]) & 3;
    switch (index_reg_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_90 = local_arr[aux % 3];
    acc = (acc + quotient_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_25 = (aux + st.buffer[1]) & 3;
    switch (damping_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_17 = local_arr[aux % 3];
    acc = (acc + cursor_17 * 2) & 127;
    int tally_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000618_1813_15(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int anchor_95 = local_arr[aux % 3];
    acc = (acc + anchor_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_74) & 63;
    acc ^= aux;
    int margin_61 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_61 > 37) {
        acc = (acc + margin_61 * 2 + 5) & 127;
        aux ^= (margin_61 & 15);
    } else {
        acc = (acc - margin_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000618_1813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int parity_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_15) & 63;
    acc ^= aux;
    int metric_17 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_17 > 29) {
        acc = (acc + metric_17 * 2 + 5) & 127;
        aux ^= (metric_17 & 15);
    } else {
        acc = (acc - metric_17 + 11) & 127;
        aux += 3;
    }
    int tally_60 = (aux + st.buffer[1]) & 3;
    switch (tally_60) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000618_1813_17(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000618_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_38 = (aux + st.buffer[1]) & 3;
    switch (threshold_38) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_48 = local_arr[aux % 3];
    acc = (acc + quantum_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_18(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int tracker_17 = local_arr[aux % 3];
    acc = (acc + tracker_17 * 2) & 127;
    int cursor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_68 > 21) {
        acc = (acc + cursor_68 * 2 + 5) & 127;
        aux ^= (cursor_68 & 15);
    } else {
        acc = (acc - cursor_68 + 11) & 127;
        aux += 3;
    }
    int residue_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_72) & 63;
    acc ^= aux;
    int margin_74 = (aux + st.buffer[1]) & 3;
    switch (margin_74) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000618_1813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_17 = local_arr[aux % 3];
    acc = (acc + factor_17 * 2) & 127;
    int residue_44 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_44 > 41) {
        acc = (acc + residue_44 * 2 + 5) & 127;
        aux ^= (residue_44 & 15);
    } else {
        acc = (acc - residue_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_53 = (aux + st.buffer[1]) & 3;
    switch (parity_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000618_1813_20(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_47 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_47 > 15) {
        acc = (acc + bound_47 * 2 + 5) & 127;
        aux ^= (bound_47 & 15);
    } else {
        acc = (acc - bound_47 + 11) & 127;
        aux += 3;
    }
    int mask_19 = (aux + st.buffer[1]) & 3;
    switch (mask_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000618_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int margin_30 = local_arr[aux % 3];
    acc = (acc + margin_30 * 2) & 127;
    int window_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000618_1813_22(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000618_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_42 = (aux + st.buffer[1]) & 3;
    switch (delta_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000618_0;
    int sec_r000618_1;
    int sec_r000618_2;
    int sec_r000618_3;
    int sec_r000618_4;
    int sec_r000618_5;
    int sec_r000618_6;
    int sec_r000618_7;
    int sec_r000618_8;
    int sec_r000618_9;
    int sec_r000618_10;
    int sec_r000618_11;
    int sec_r000618_12;
    int sec_r000618_13;
    int sec_r000618_14;
    int sec_r000618_15;
    int sec_r000618_16;
    int sec_r000618_17;
    int sec_r000618_18;
    int pub_r000618_0;
    int pub_r000618_1;
    int pub_r000618_2;
    int pub_r000618_3;
    int pub_r000618_4;
    int pub_r000618_5;
    int pub_r000618_6;
    int pub_r000618_7;
    int pub_r000618_8;
    int pub_r000618_9;
    int pub_r000618_10;
    int pub_r000618_11;
    int pub_r000618_12;
    int pub_r000618_13;
    int pub_r000618_14;
    int pub_r000618_15;
    int pub_r000618_16;
    int pub_r000618_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000618_0 >= -100 && pub_r000618_0 <= 100);
    __CPROVER_assume(pub_r000618_1 >= -100 && pub_r000618_1 <= 100);
    __CPROVER_assume(pub_r000618_2 >= -100 && pub_r000618_2 <= 100);
    __CPROVER_assume(pub_r000618_3 >= -100 && pub_r000618_3 <= 100);
    __CPROVER_assume(pub_r000618_4 >= -100 && pub_r000618_4 <= 100);
    __CPROVER_assume(pub_r000618_5 >= -100 && pub_r000618_5 <= 100);
    __CPROVER_assume(pub_r000618_6 >= -100 && pub_r000618_6 <= 100);
    __CPROVER_assume(pub_r000618_7 >= -100 && pub_r000618_7 <= 100);
    __CPROVER_assume(pub_r000618_8 >= -100 && pub_r000618_8 <= 100);
    __CPROVER_assume(pub_r000618_9 >= -100 && pub_r000618_9 <= 100);
    __CPROVER_assume(pub_r000618_10 >= -100 && pub_r000618_10 <= 100);
    __CPROVER_assume(pub_r000618_11 >= -100 && pub_r000618_11 <= 100);
    __CPROVER_assume(pub_r000618_12 >= -100 && pub_r000618_12 <= 100);
    __CPROVER_assume(pub_r000618_13 >= -100 && pub_r000618_13 <= 100);
    __CPROVER_assume(pub_r000618_14 >= -100 && pub_r000618_14 <= 100);
    __CPROVER_assume(pub_r000618_15 >= -100 && pub_r000618_15 <= 100);
    __CPROVER_assume(pub_r000618_16 >= -100 && pub_r000618_16 <= 100);
    __CPROVER_assume(pub_r000618_17 >= -100 && pub_r000618_17 <= 100);
    __CPROVER_assume(sec_r000618_0 >= 0 && sec_r000618_0 <= 255);
    __CPROVER_assume(sec_r000618_1 >= 0 && sec_r000618_1 <= 255);
    __CPROVER_assume(sec_r000618_2 >= 0 && sec_r000618_2 <= 255);
    __CPROVER_assume(sec_r000618_3 >= 0 && sec_r000618_3 <= 255);
    __CPROVER_assume(sec_r000618_4 >= 0 && sec_r000618_4 <= 255);
    __CPROVER_assume(sec_r000618_5 >= 0 && sec_r000618_5 <= 255);
    __CPROVER_assume(sec_r000618_6 >= 0 && sec_r000618_6 <= 255);
    __CPROVER_assume(sec_r000618_7 >= 0 && sec_r000618_7 <= 255);
    __CPROVER_assume(sec_r000618_8 >= 0 && sec_r000618_8 <= 255);
    __CPROVER_assume(sec_r000618_9 >= 0 && sec_r000618_9 <= 255);
    __CPROVER_assume(sec_r000618_10 >= 0 && sec_r000618_10 <= 255);
    __CPROVER_assume(sec_r000618_11 >= 0 && sec_r000618_11 <= 255);
    __CPROVER_assume(sec_r000618_12 >= 0 && sec_r000618_12 <= 255);
    __CPROVER_assume(sec_r000618_13 >= 0 && sec_r000618_13 <= 255);
    __CPROVER_assume(sec_r000618_14 >= 0 && sec_r000618_14 <= 255);
    __CPROVER_assume(sec_r000618_15 >= 0 && sec_r000618_15 <= 255);
    __CPROVER_assume(sec_r000618_16 >= 0 && sec_r000618_16 <= 255);
    __CPROVER_assume(sec_r000618_17 >= 0 && sec_r000618_17 <= 255);
    __CPROVER_assume(sec_r000618_18 >= 0 && sec_r000618_18 <= 255);

    struct EventLog_R000618_1813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000618_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000618_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000618_0 + 7) & 15;
    struct FilterState_R000618_1813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000618_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000618_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000618_0 + 9) & 15;
    struct CipherContext_R000618_1813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000618_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000618_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000618_0 + 11) & 15;

    union PacketPayload_R000618_1813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 19) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 34) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_7 & 1) == step) {
            stage_v_4 = (stage_v_4 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_4 = (stage_v_4 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_2 & 1) == step) {
            stage_v_5 = (stage_v_5 + step * 4 + pub_r000618_11) & 63;
        } else {
            stage_v_5 = (stage_v_5 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_8 & 1) == step) {
            stage_v_6 = (stage_v_6 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_6 = (stage_v_6 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_7 = (stage_v_7 + step * 4 + pub_r000618_3) & 63;
        } else {
            stage_v_7 = (stage_v_7 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_14 & 1) == step) {
            stage_v_8 = (stage_v_8 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_8 = (stage_v_8 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_9 = (stage_v_9 + step * 4 + pub_r000618_11) & 63;
        } else {
            stage_v_9 = (stage_v_9 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_7 & 1) == step) {
            stage_v_10 = (stage_v_10 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_10 = (stage_v_10 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_8 & 1) == step) {
            stage_v_11 = (stage_v_11 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_11 = (stage_v_11 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_5 & 1) == step) {
            stage_v_12 = (stage_v_12 + step * 4 + pub_r000618_11) & 63;
        } else {
            stage_v_12 = (stage_v_12 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_13 = (stage_v_13 + step * 4 + pub_r000618_8) & 63;
        } else {
            stage_v_13 = (stage_v_13 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_7 & 1) == step) {
            stage_v_14 = (stage_v_14 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_14 = (stage_v_14 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_4 & 1) == step) {
            stage_v_15 = (stage_v_15 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_15 = (stage_v_15 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_13 & 1) == step) {
            stage_v_16 = (stage_v_16 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_16 = (stage_v_16 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_15 & 1) == step) {
            stage_v_17 = (stage_v_17 + step * 4 + pub_r000618_6) & 63;
        } else {
            stage_v_17 = (stage_v_17 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_11 & 1) == step) {
            stage_v_18 = (stage_v_18 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_18 = (stage_v_18 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_3 & 1) == step) {
            stage_v_19 = (stage_v_19 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_19 = (stage_v_19 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_20 = (stage_v_20 + step * 4 + pub_r000618_5) & 63;
        } else {
            stage_v_20 = (stage_v_20 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_8 & 1) == step) {
            stage_v_21 = (stage_v_21 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_21 = (stage_v_21 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_12 & 1) == step) {
            stage_v_22 = (stage_v_22 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_22 = (stage_v_22 + pub_r000618_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_23 = (stage_v_23 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_23 = (stage_v_23 + pub_r000618_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_24 = (stage_v_24 + step * 4 + pub_r000618_6) & 63;
        } else {
            stage_v_24 = (stage_v_24 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_25 = (stage_v_25 + step * 4 + pub_r000618_13) & 63;
        } else {
            stage_v_25 = (stage_v_25 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_16 & 1) == step) {
            stage_v_26 = (stage_v_26 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_26 = (stage_v_26 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_27 = (stage_v_27 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_27 = (stage_v_27 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_28 = (stage_v_28 + step * 4 + pub_r000618_6) & 63;
        } else {
            stage_v_28 = (stage_v_28 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_1 & 1) == step) {
            stage_v_29 = (stage_v_29 + step * 4 + pub_r000618_11) & 63;
        } else {
            stage_v_29 = (stage_v_29 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_13 & 1) == step) {
            stage_v_30 = (stage_v_30 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_30 = (stage_v_30 + pub_r000618_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_31 = (stage_v_31 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_31 = (stage_v_31 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_12 & 1) == step) {
            stage_v_32 = (stage_v_32 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_32 = (stage_v_32 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_33 = (stage_v_33 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_33 = (stage_v_33 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_30 & 1) == step) {
            stage_v_34 = (stage_v_34 + step * 4 + pub_r000618_3) & 63;
        } else {
            stage_v_34 = (stage_v_34 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_25 & 1) == step) {
            stage_v_35 = (stage_v_35 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_35 = (stage_v_35 + pub_r000618_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_36 = (stage_v_36 + step * 4 + pub_r000618_13) & 63;
        } else {
            stage_v_36 = (stage_v_36 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_30 & 1) == step) {
            stage_v_37 = (stage_v_37 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_37 = (stage_v_37 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_16 & 1) == step) {
            stage_v_38 = (stage_v_38 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_38 = (stage_v_38 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_5 & 1) == step) {
            stage_v_39 = (stage_v_39 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_39 = (stage_v_39 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_32 & 1) == step) {
            stage_v_40 = (stage_v_40 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_40 = (stage_v_40 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_41 = (stage_v_41 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_41 = (stage_v_41 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_15 & 1) == step) {
            stage_v_42 = (stage_v_42 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_42 = (stage_v_42 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_36 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_27 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000618_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_20 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_11 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_18 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000618_8) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_19 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_42 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_17 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_38 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_3 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000618_16) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_13 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_1 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000618_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_13 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_4 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000618_3) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_30 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_36 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000618_16) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_9 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000618_14) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000618_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_4 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_15 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_21 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_0 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000618_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_5 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_18 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_13 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000618_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000618_3) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000618_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_17 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000618_16) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_1 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000618_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_9 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000618_6) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_1 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000618_17) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_9 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_15 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000618_13) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_8 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000618_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_30 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_11 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000618_0) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_3 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000618_6) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000618_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000618_8) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000618_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000618_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000618_5) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000618_13) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000618_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000618_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_11 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000618_15) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_8 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000618_5) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000618_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000618_7) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_7 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000618_12) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000618_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000618_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_15 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000618_9) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000618_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000618_4) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000618_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_0 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000618_2) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000618_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000618_9 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000618_10) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000618_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_35 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000618_16) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000618_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000618_1) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000618_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
