/*
 * Benchmark Program: R000327
 * Security Family: nested_implicit_flow
 * Generator Seed: 532713
 * High Inputs: 20 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000327_2713_0 {
    short tag;
    unsigned char iv;
    int round_key;
    int buffer[3];
};

struct EventLog_R000327_2713_1 {
    int code;
    int facility;
    short signature;
    int buffer[3];
};

struct StreamBuffer_R000327_2713_2 {
    short capacity;
    int state;
    int head;
    unsigned char watermark;
    short tail;
    unsigned char checksum;
    int buffer[3];
};

union ColorPixel_R000327_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000327_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000327_2713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int window_64 = local_arr[aux % 3];
    acc = (acc + window_64 * 2) & 127;
    int scale_86 = (aux + st.buffer[1]) & 3;
    switch (scale_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000327_2713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_41 > 27) {
        acc = (acc + cursor_41 * 2 + 5) & 127;
        aux ^= (cursor_41 & 15);
    } else {
        acc = (acc - cursor_41 + 11) & 127;
        aux += 3;
    }
    int weight_33 = (aux + st.buffer[1]) & 3;
    switch (weight_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_46 = local_arr[aux % 3];
    acc = (acc + vector_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_30 = (aux + st.buffer[1]) & 3;
    switch (bound_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_43 = local_arr[aux % 3];
    acc = (acc + cursor_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_84 = (st.buffer[0] * 3 + aux) & 63;
    if (window_84 > 34) {
        acc = (acc + window_84 * 2 + 5) & 127;
        aux ^= (window_84 & 15);
    } else {
        acc = (acc - window_84 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_61 = (aux + st.buffer[1]) & 3;
    switch (tracker_61) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_78) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_47 = local_arr[aux % 3];
    acc = (acc + offset_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_5(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_98) & 63;
    acc ^= aux;
    int factor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_75 > 39) {
        acc = (acc + factor_75 * 2 + 5) & 127;
        aux ^= (factor_75 & 15);
    } else {
        acc = (acc - factor_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_34 = local_arr[aux % 3];
    acc = (acc + quotient_34 * 2) & 127;
    int accumulator_28 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_28 > 15) {
        acc = (acc + accumulator_28 * 2 + 5) & 127;
        aux ^= (accumulator_28 & 15);
    } else {
        acc = (acc - accumulator_28 + 11) & 127;
        aux += 3;
    }
    int tally_93 = (aux + st.buffer[1]) & 3;
    switch (tally_93) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_7(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_72 = local_arr[aux % 3];
    acc = (acc + damping_72 * 2) & 127;
    int metric_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_46) & 63;
    acc ^= aux;
    int accumulator_45 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_45 > 20) {
        acc = (acc + accumulator_45 * 2 + 5) & 127;
        aux ^= (accumulator_45 & 15);
    } else {
        acc = (acc - accumulator_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_37 = (aux + st.buffer[1]) & 3;
    switch (cursor_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000327_2713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_98 = (st.buffer[0] * 3 + aux) & 63;
    if (window_98 > 31) {
        acc = (acc + window_98 * 2 + 5) & 127;
        aux ^= (window_98 & 15);
    } else {
        acc = (acc - window_98 + 11) & 127;
        aux += 3;
    }
    int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_46) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int quantum_62 = local_arr[aux % 3];
    acc = (acc + quantum_62 * 2) & 127;
    int checksum_89 = (aux + st.buffer[1]) & 3;
    switch (checksum_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_90 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_90 > 14) {
        acc = (acc + threshold_90 * 2 + 5) & 127;
        aux ^= (threshold_90 & 15);
    } else {
        acc = (acc - threshold_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int window_72 = local_arr[aux % 3];
    acc = (acc + window_72 * 2) & 127;
    int tally_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000327_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int margin_33 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_33 > 49) {
        acc = (acc + margin_33 * 2 + 5) & 127;
        aux ^= (margin_33 & 15);
    } else {
        acc = (acc - margin_33 + 11) & 127;
        aux += 3;
    }
    int index_reg_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_35 = local_arr[aux % 3];
    acc = (acc + accumulator_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000327_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_53 = local_arr[aux % 3];
    acc = (acc + margin_53 * 2) & 127;
    int offset_78 = (aux + st.buffer[1]) & 3;
    switch (offset_78) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int accumulator_36 = local_arr[aux % 3];
    acc = (acc + accumulator_36 * 2) & 127;
    int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_44) & 63;
    acc ^= aux;
    int metric_48 = (aux + st.buffer[1]) & 3;
    switch (metric_48) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_16(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_83 = local_arr[aux % 3];
    acc = (acc + stride_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_17(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int quantum_83 = local_arr[aux % 3];
    acc = (acc + quantum_83 * 2) & 127;
    int checksum_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000327_2713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_32) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_52 = local_arr[aux % 3];
    acc = (acc + metric_52 * 2) & 127;
    int bound_55 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_55 > 17) {
        acc = (acc + bound_55 * 2 + 5) & 127;
        aux ^= (bound_55 & 15);
    } else {
        acc = (acc - bound_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000327_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_11) & 63;
    acc ^= aux;
    int tracker_18 = (aux + st.buffer[1]) & 3;
    switch (tracker_18) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_98 = local_arr[aux % 3];
    acc = (acc + checksum_98 * 2) & 127;
    int tracker_58 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_58 > 49) {
        acc = (acc + tracker_58 * 2 + 5) & 127;
        aux ^= (tracker_58 & 15);
    } else {
        acc = (acc - tracker_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000327_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_95) & 63;
    acc ^= aux;
    int residue_29 = (aux + st.buffer[1]) & 3;
    switch (residue_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_57 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_57 > 37) {
        acc = (acc + factor_57 * 2 + 5) & 127;
        aux ^= (factor_57 & 15);
    } else {
        acc = (acc - factor_57 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_92 = local_arr[aux % 3];
    acc = (acc + segment_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_21(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_47) & 63;
    acc ^= aux;
    int delta_83 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_83 > 15) {
        acc = (acc + delta_83 * 2 + 5) & 127;
        aux ^= (delta_83 & 15);
    } else {
        acc = (acc - delta_83 + 11) & 127;
        aux += 3;
    }
    int window_35 = (aux + st.buffer[1]) & 3;
    switch (window_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_22(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_85 = (aux + st.buffer[1]) & 3;
    switch (tracker_85) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_37 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_37 > 28) {
        acc = (acc + sample_37 * 2 + 5) & 127;
        aux ^= (sample_37 & 15);
    } else {
        acc = (acc - sample_37 + 11) & 127;
        aux += 3;
    }
    int accumulator_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_31) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_40 = local_arr[aux % 3];
    acc = (acc + vector_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000327_2713_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000327_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int threshold_46 = local_arr[aux % 3];
    acc = (acc + threshold_46 * 2) & 127;
    int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_26 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_26 > 23) {
        acc = (acc + pivot_26 * 2 + 5) & 127;
        aux ^= (pivot_26 & 15);
    } else {
        acc = (acc - pivot_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000327_0;
    int sec_r000327_1;
    int sec_r000327_2;
    int sec_r000327_3;
    int sec_r000327_4;
    int sec_r000327_5;
    int sec_r000327_6;
    int sec_r000327_7;
    int sec_r000327_8;
    int sec_r000327_9;
    int sec_r000327_10;
    int sec_r000327_11;
    int sec_r000327_12;
    int sec_r000327_13;
    int sec_r000327_14;
    int sec_r000327_15;
    int sec_r000327_16;
    int sec_r000327_17;
    int sec_r000327_18;
    int sec_r000327_19;
    int pub_r000327_0;
    int pub_r000327_1;
    int pub_r000327_2;
    int pub_r000327_3;
    int pub_r000327_4;
    int pub_r000327_5;
    int pub_r000327_6;
    int pub_r000327_7;
    int pub_r000327_8;
    int pub_r000327_9;
    int pub_r000327_10;
    int pub_r000327_11;
    int pub_r000327_12;
    int pub_r000327_13;
    int pub_r000327_14;
    int pub_r000327_15;
    int pub_r000327_16;
    int pub_r000327_17;
    int pub_r000327_18;
    int pub_r000327_19;
    int pub_r000327_20;
    int pub_r000327_21;
    int pub_r000327_22;
    int pub_r000327_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000327_0 >= -100 && pub_r000327_0 <= 100);
    __CPROVER_assume(pub_r000327_1 >= -100 && pub_r000327_1 <= 100);
    __CPROVER_assume(pub_r000327_2 >= -100 && pub_r000327_2 <= 100);
    __CPROVER_assume(pub_r000327_3 >= -100 && pub_r000327_3 <= 100);
    __CPROVER_assume(pub_r000327_4 >= -100 && pub_r000327_4 <= 100);
    __CPROVER_assume(pub_r000327_5 >= -100 && pub_r000327_5 <= 100);
    __CPROVER_assume(pub_r000327_6 >= -100 && pub_r000327_6 <= 100);
    __CPROVER_assume(pub_r000327_7 >= -100 && pub_r000327_7 <= 100);
    __CPROVER_assume(pub_r000327_8 >= -100 && pub_r000327_8 <= 100);
    __CPROVER_assume(pub_r000327_9 >= -100 && pub_r000327_9 <= 100);
    __CPROVER_assume(pub_r000327_10 >= -100 && pub_r000327_10 <= 100);
    __CPROVER_assume(pub_r000327_11 >= -100 && pub_r000327_11 <= 100);
    __CPROVER_assume(pub_r000327_12 >= -100 && pub_r000327_12 <= 100);
    __CPROVER_assume(pub_r000327_13 >= -100 && pub_r000327_13 <= 100);
    __CPROVER_assume(pub_r000327_14 >= -100 && pub_r000327_14 <= 100);
    __CPROVER_assume(pub_r000327_15 >= -100 && pub_r000327_15 <= 100);
    __CPROVER_assume(pub_r000327_16 >= -100 && pub_r000327_16 <= 100);
    __CPROVER_assume(pub_r000327_17 >= -100 && pub_r000327_17 <= 100);
    __CPROVER_assume(pub_r000327_18 >= -100 && pub_r000327_18 <= 100);
    __CPROVER_assume(pub_r000327_19 >= -100 && pub_r000327_19 <= 100);
    __CPROVER_assume(pub_r000327_20 >= -100 && pub_r000327_20 <= 100);
    __CPROVER_assume(pub_r000327_21 >= -100 && pub_r000327_21 <= 100);
    __CPROVER_assume(pub_r000327_22 >= -100 && pub_r000327_22 <= 100);
    __CPROVER_assume(pub_r000327_23 >= -100 && pub_r000327_23 <= 100);
    __CPROVER_assume(sec_r000327_0 >= 0 && sec_r000327_0 <= 255);
    __CPROVER_assume(sec_r000327_1 >= 0 && sec_r000327_1 <= 255);
    __CPROVER_assume(sec_r000327_2 >= 0 && sec_r000327_2 <= 255);
    __CPROVER_assume(sec_r000327_3 >= 0 && sec_r000327_3 <= 255);
    __CPROVER_assume(sec_r000327_4 >= 0 && sec_r000327_4 <= 255);
    __CPROVER_assume(sec_r000327_5 >= 0 && sec_r000327_5 <= 255);
    __CPROVER_assume(sec_r000327_6 >= 0 && sec_r000327_6 <= 255);
    __CPROVER_assume(sec_r000327_7 >= 0 && sec_r000327_7 <= 255);
    __CPROVER_assume(sec_r000327_8 >= 0 && sec_r000327_8 <= 255);
    __CPROVER_assume(sec_r000327_9 >= 0 && sec_r000327_9 <= 255);
    __CPROVER_assume(sec_r000327_10 >= 0 && sec_r000327_10 <= 255);
    __CPROVER_assume(sec_r000327_11 >= 0 && sec_r000327_11 <= 255);
    __CPROVER_assume(sec_r000327_12 >= 0 && sec_r000327_12 <= 255);
    __CPROVER_assume(sec_r000327_13 >= 0 && sec_r000327_13 <= 255);
    __CPROVER_assume(sec_r000327_14 >= 0 && sec_r000327_14 <= 255);
    __CPROVER_assume(sec_r000327_15 >= 0 && sec_r000327_15 <= 255);
    __CPROVER_assume(sec_r000327_16 >= 0 && sec_r000327_16 <= 255);
    __CPROVER_assume(sec_r000327_17 >= 0 && sec_r000327_17 <= 255);
    __CPROVER_assume(sec_r000327_18 >= 0 && sec_r000327_18 <= 255);
    __CPROVER_assume(sec_r000327_19 >= 0 && sec_r000327_19 <= 255);

    struct CipherContext_R000327_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000327_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000327_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000327_0 + 7) & 15;
    struct EventLog_R000327_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000327_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000327_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000327_0 + 9) & 15;
    struct StreamBuffer_R000327_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000327_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000327_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000327_0 + 11) & 15;

    union ColorPixel_R000327_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 19) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 34) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 36) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 51) {
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
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 12) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 27) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

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
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((sec_r000327_1 & 1) != 0) {
        if ((sec_r000327_14 & 2) != 0) {
            stage_v_28 = (pub_r000327_6 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000327_6 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000327_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((sec_r000327_4 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_29 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_30 = (pub_r000327_10 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000327_10 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000327_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000327_15 & 2) != 0) {
            stage_v_31 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_32 = (pub_r000327_15 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000327_15 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000327_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((sec_r000327_7 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_33 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000327_14 & 1) != 0) {
        if ((sec_r000327_12 & 2) != 0) {
            stage_v_34 = (pub_r000327_19 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000327_19 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000327_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_35 = (pub_r000327_6 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000327_6 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000327_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_36 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000327_1 & 2) != 0) {
            stage_v_37 = (pub_r000327_7 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000327_7 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000327_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000327_7 & 2) != 0) {
            stage_v_38 = (pub_r000327_23 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000327_23 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000327_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000327_7 & 1) != 0) {
        if ((sec_r000327_9 & 2) != 0) {
            stage_v_39 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000327_15 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_40 = (pub_r000327_21 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000327_21 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000327_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000327_9 & 1) != 0) {
        if ((sec_r000327_16 & 2) != 0) {
            stage_v_41 = (pub_r000327_12 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000327_12 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000327_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_42 = (pub_r000327_19 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000327_19 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000327_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_43 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000327_0 & 2) != 0) {
            stage_v_44 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_45 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_46 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_47 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000327_19 & 2) != 0) {
            stage_v_48 = (pub_r000327_12 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000327_12 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000327_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000327_4 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_49 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000327_2 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_50 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_51 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000327_0 & 2) != 0) {
            stage_v_52 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000327_13 & 2) != 0) {
            stage_v_53 = (pub_r000327_7 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000327_7 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000327_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000327_15 & 1) != 0) {
        if ((sec_r000327_9 & 2) != 0) {
            stage_v_54 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000327_12 & 2) != 0) {
            stage_v_55 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000327_1 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_56 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000327_0 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_57 = (pub_r000327_21 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000327_21 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000327_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000327_6 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_58 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000327_0 & 2) != 0) {
            stage_v_59 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000327_6 & 1) != 0) {
        if ((sec_r000327_11 & 2) != 0) {
            stage_v_60 = (pub_r000327_12 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000327_12 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000327_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000327_11 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_61 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000327_7 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_62 = (pub_r000327_21 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000327_21 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000327_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_63 = (pub_r000327_17 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000327_17 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000327_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_64 = (pub_r000327_21 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000327_21 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000327_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_65 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000327_0 & 1) != 0) {
        if ((sec_r000327_0 & 2) != 0) {
            stage_v_66 = (pub_r000327_23 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000327_23 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000327_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000327_12 & 2) != 0) {
            stage_v_67 = (pub_r000327_9 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000327_9 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000327_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000327_18 & 2) != 0) {
            stage_v_68 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000327_7 & 2) != 0) {
            stage_v_69 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000327_0 & 2) != 0) {
            stage_v_70 = (pub_r000327_8 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000327_8 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000327_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000327_16 & 2) != 0) {
            stage_v_71 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_72 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000327_3 & 1) != 0) {
        if ((sec_r000327_13 & 2) != 0) {
            stage_v_73 = (pub_r000327_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000327_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000327_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000327_14 & 2) != 0) {
            stage_v_74 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000327_15 & 1) != 0) {
        if ((sec_r000327_7 & 2) != 0) {
            stage_v_75 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000327_1 & 2) != 0) {
            stage_v_76 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000327_18 & 1) != 0) {
        if ((sec_r000327_1 & 2) != 0) {
            stage_v_77 = (pub_r000327_7 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000327_7 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000327_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000327_19 & 1) != 0) {
        if ((sec_r000327_15 & 2) != 0) {
            stage_v_78 = (pub_r000327_0 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000327_0 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000327_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000327_7 & 2) != 0) {
            stage_v_79 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_80 = (pub_r000327_7 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000327_7 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000327_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000327_11 & 1) != 0) {
        if ((sec_r000327_18 & 2) != 0) {
            stage_v_81 = (pub_r000327_3 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000327_3 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000327_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_82 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000327_14 & 1) != 0) {
        if ((sec_r000327_14 & 2) != 0) {
            stage_v_83 = (pub_r000327_11 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000327_11 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000327_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000327_17 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_84 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_85 = (pub_r000327_19 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000327_19 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000327_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000327_13 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_86 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_87 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_88 = (pub_r000327_19 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000327_19 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000327_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000327_2 & 2) != 0) {
            stage_v_89 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000327_9 & 1) != 0) {
        if ((sec_r000327_15 & 2) != 0) {
            stage_v_90 = (pub_r000327_1 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000327_1 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000327_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000327_7 & 1) != 0) {
        if ((sec_r000327_11 & 2) != 0) {
            stage_v_91 = (pub_r000327_3 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000327_3 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000327_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000327_11 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_92 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000327_15 & 2) != 0) {
            stage_v_93 = (pub_r000327_19 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000327_19 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000327_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000327_18 & 2) != 0) {
            stage_v_94 = (pub_r000327_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000327_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000327_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000327_0 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_95 = (pub_r000327_0 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000327_0 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000327_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000327_13 & 2) != 0) {
            stage_v_96 = (pub_r000327_10 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000327_10 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000327_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000327_16 & 2) != 0) {
            stage_v_97 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_98 = (pub_r000327_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000327_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000327_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_99 = (pub_r000327_14 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000327_14 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000327_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000327_2 & 1) != 0) {
        if ((sec_r000327_19 & 2) != 0) {
            stage_v_100 = (pub_r000327_23 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000327_23 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000327_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000327_17 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_101 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000327_12 & 2) != 0) {
            stage_v_102 = (pub_r000327_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000327_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000327_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_103 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000327_17 & 2) != 0) {
            stage_v_104 = (pub_r000327_20 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000327_20 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000327_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000327_16 & 2) != 0) {
            stage_v_105 = (pub_r000327_3 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000327_3 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000327_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_106 = (pub_r000327_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000327_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000327_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000327_19 & 2) != 0) {
            stage_v_107 = (pub_r000327_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000327_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000327_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000327_5 & 2) != 0) {
            stage_v_108 = (pub_r000327_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000327_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000327_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000327_16 & 1) != 0) {
        if ((sec_r000327_19 & 2) != 0) {
            stage_v_109 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_110 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000327_11 & 2) != 0) {
            stage_v_111 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000327_1 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_112 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000327_9 & 2) != 0) {
            stage_v_113 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000327_19 & 1) != 0) {
        if ((sec_r000327_12 & 2) != 0) {
            stage_v_114 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000327_12 & 1) != 0) {
        if ((sec_r000327_10 & 2) != 0) {
            stage_v_115 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000327_1 & 2) != 0) {
            stage_v_116 = (pub_r000327_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000327_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000327_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000327_11 & 1) != 0) {
        if ((sec_r000327_19 & 2) != 0) {
            stage_v_117 = (pub_r000327_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000327_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000327_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000327_6 & 2) != 0) {
            stage_v_118 = (pub_r000327_18 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000327_18 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000327_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000327_14 & 1) != 0) {
        if ((sec_r000327_3 & 2) != 0) {
            stage_v_119 = (pub_r000327_16 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000327_16 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000327_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000327_8 & 2) != 0) {
            stage_v_120 = (pub_r000327_4 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000327_4 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000327_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000327_5 & 1) != 0) {
        if ((sec_r000327_16 & 2) != 0) {
            stage_v_121 = (pub_r000327_22 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000327_22 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000327_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000327_4 & 2) != 0) {
            stage_v_122 = (pub_r000327_13 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000327_13 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000327_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
