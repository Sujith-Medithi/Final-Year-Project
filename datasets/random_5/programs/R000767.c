/*
 * Benchmark Program: R000767
 * Security Family: nested_implicit_flow
 * Generator Seed: 576713
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000767_6713_0 {
    unsigned char signature;
    unsigned char facility;
    unsigned char severity;
    int buffer[3];
};

struct StreamBuffer_R000767_6713_1 {
    short capacity;
    unsigned char watermark;
    unsigned char state;
    int buffer[3];
};

struct FilterState_R000767_6713_2 {
    short prev_in;
    int damping;
    int mode;
    int cutoff;
    int buffer[3];
};

struct CipherContext_R000767_6713_3 {
    int flags;
    unsigned char tag;
    int iv;
    short round_key;
    int buffer[3];
};

union RegisterBank_R000767_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000767_6713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000767_6713_0(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000767_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_60 = (aux + st.buffer[1]) & 3;
    switch (margin_60) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_37) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_48 = local_arr[aux % 3];
    acc = (acc + offset_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000767_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_25 = local_arr[aux % 3];
    acc = (acc + coefficient_25 * 2) & 127;
    int parity_58 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_58 > 34) {
        acc = (acc + parity_58 * 2 + 5) & 127;
        aux ^= (parity_58 & 15);
    } else {
        acc = (acc - parity_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000767_6713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000767_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_13 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_13 > 38) {
        acc = (acc + accumulator_13 * 2 + 5) & 127;
        aux ^= (accumulator_13 & 15);
    } else {
        acc = (acc - accumulator_13 + 11) & 127;
        aux += 3;
    }
    int coefficient_17 = (aux + st.buffer[1]) & 3;
    switch (coefficient_17) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000767_6713_3(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_69) & 63;
    acc ^= aux;
    int window_59 = (aux + st.buffer[1]) & 3;
    switch (window_59) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_61 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_61 > 19) {
        acc = (acc + segment_61 * 2 + 5) & 127;
        aux ^= (segment_61 & 15);
    } else {
        acc = (acc - segment_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000767_6713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int segment_60 = (aux + st.buffer[1]) & 3;
    switch (segment_60) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_33 = local_arr[aux % 3];
    acc = (acc + sample_33 * 2) & 127;
    int window_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_5(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_20) & 63;
    acc ^= aux;
    int window_36 = (aux + st.buffer[1]) & 3;
    switch (window_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_59 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_59 > 20) {
        acc = (acc + index_reg_59 * 2 + 5) & 127;
        aux ^= (index_reg_59 & 15);
    } else {
        acc = (acc - index_reg_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000767_6713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_7(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_58 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_58 > 27) {
        acc = (acc + residue_58 * 2 + 5) & 127;
        aux ^= (residue_58 & 15);
    } else {
        acc = (acc - residue_58 + 11) & 127;
        aux += 3;
    }
    int index_reg_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_8(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int stride_47 = (aux + st.buffer[1]) & 3;
    switch (stride_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_17 = local_arr[aux % 3];
    acc = (acc + weight_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_97 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_97 > 16) {
        acc = (acc + delta_97 * 2 + 5) & 127;
        aux ^= (delta_97 & 15);
    } else {
        acc = (acc - delta_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_10(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000767_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_44 = (aux + st.buffer[1]) & 3;
    switch (weight_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_42 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_42 > 39) {
        acc = (acc + checksum_42 * 2 + 5) & 127;
        aux ^= (checksum_42 & 15);
    } else {
        acc = (acc - checksum_42 + 11) & 127;
        aux += 3;
    }
    int factor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_11(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int margin_45 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_45 > 33) {
        acc = (acc + margin_45 * 2 + 5) & 127;
        aux ^= (margin_45 & 15);
    } else {
        acc = (acc - margin_45 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_50 = local_arr[aux % 3];
    acc = (acc + mask_50 * 2) & 127;
    int sample_59 = (aux + st.buffer[1]) & 3;
    switch (sample_59) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_12(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000767_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_23) & 63;
    acc ^= aux;
    int threshold_85 = (aux + st.buffer[1]) & 3;
    switch (threshold_85) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_10 = local_arr[aux % 3];
    acc = (acc + mask_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_13(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_86) & 63;
    acc ^= aux;
    int damping_87 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_87 > 46) {
        acc = (acc + damping_87 * 2 + 5) & 127;
        aux ^= (damping_87 & 15);
    } else {
        acc = (acc - damping_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_70 = local_arr[aux % 3];
    acc = (acc + checksum_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000767_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_38 > 21) {
        acc = (acc + checksum_38 * 2 + 5) & 127;
        aux ^= (checksum_38 & 15);
    } else {
        acc = (acc - checksum_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_42 = local_arr[aux % 3];
    acc = (acc + quantum_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000767_6713_15(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int damping_10 = (aux + st.buffer[1]) & 3;
    switch (damping_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_24 > 38) {
        acc = (acc + cursor_24 * 2 + 5) & 127;
        aux ^= (cursor_24 & 15);
    } else {
        acc = (acc - cursor_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000767_6713_16(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_79 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_79 > 21) {
        acc = (acc + sample_79 * 2 + 5) & 127;
        aux ^= (sample_79 & 15);
    } else {
        acc = (acc - sample_79 + 11) & 127;
        aux += 3;
    }
    int anchor_61 = (aux + st.buffer[1]) & 3;
    switch (anchor_61) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_17(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000767_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000767_6713_18(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000767_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_53 = local_arr[aux % 3];
    acc = (acc + accumulator_53 * 2) & 127;
    int segment_32 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_32 > 29) {
        acc = (acc + segment_32 * 2 + 5) & 127;
        aux ^= (segment_32 & 15);
    } else {
        acc = (acc - segment_32 + 11) & 127;
        aux += 3;
    }
    int quantum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000767_0;
    int sec_r000767_1;
    int sec_r000767_2;
    int sec_r000767_3;
    int sec_r000767_4;
    int sec_r000767_5;
    int sec_r000767_6;
    int sec_r000767_7;
    int sec_r000767_8;
    int sec_r000767_9;
    int sec_r000767_10;
    int sec_r000767_11;
    int sec_r000767_12;
    int sec_r000767_13;
    int sec_r000767_14;
    int sec_r000767_15;
    int sec_r000767_16;
    int pub_r000767_0;
    int pub_r000767_1;
    int pub_r000767_2;
    int pub_r000767_3;
    int pub_r000767_4;
    int pub_r000767_5;
    int pub_r000767_6;
    int pub_r000767_7;
    int pub_r000767_8;
    int pub_r000767_9;
    int pub_r000767_10;
    int pub_r000767_11;
    int pub_r000767_12;
    int pub_r000767_13;
    int pub_r000767_14;
    int pub_r000767_15;
    int pub_r000767_16;
    int pub_r000767_17;
    int pub_r000767_18;
    int pub_r000767_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000767_0 >= -100 && pub_r000767_0 <= 100);
    __CPROVER_assume(pub_r000767_1 >= -100 && pub_r000767_1 <= 100);
    __CPROVER_assume(pub_r000767_2 >= -100 && pub_r000767_2 <= 100);
    __CPROVER_assume(pub_r000767_3 >= -100 && pub_r000767_3 <= 100);
    __CPROVER_assume(pub_r000767_4 >= -100 && pub_r000767_4 <= 100);
    __CPROVER_assume(pub_r000767_5 >= -100 && pub_r000767_5 <= 100);
    __CPROVER_assume(pub_r000767_6 >= -100 && pub_r000767_6 <= 100);
    __CPROVER_assume(pub_r000767_7 >= -100 && pub_r000767_7 <= 100);
    __CPROVER_assume(pub_r000767_8 >= -100 && pub_r000767_8 <= 100);
    __CPROVER_assume(pub_r000767_9 >= -100 && pub_r000767_9 <= 100);
    __CPROVER_assume(pub_r000767_10 >= -100 && pub_r000767_10 <= 100);
    __CPROVER_assume(pub_r000767_11 >= -100 && pub_r000767_11 <= 100);
    __CPROVER_assume(pub_r000767_12 >= -100 && pub_r000767_12 <= 100);
    __CPROVER_assume(pub_r000767_13 >= -100 && pub_r000767_13 <= 100);
    __CPROVER_assume(pub_r000767_14 >= -100 && pub_r000767_14 <= 100);
    __CPROVER_assume(pub_r000767_15 >= -100 && pub_r000767_15 <= 100);
    __CPROVER_assume(pub_r000767_16 >= -100 && pub_r000767_16 <= 100);
    __CPROVER_assume(pub_r000767_17 >= -100 && pub_r000767_17 <= 100);
    __CPROVER_assume(pub_r000767_18 >= -100 && pub_r000767_18 <= 100);
    __CPROVER_assume(pub_r000767_19 >= -100 && pub_r000767_19 <= 100);
    __CPROVER_assume(sec_r000767_0 >= 0 && sec_r000767_0 <= 255);
    __CPROVER_assume(sec_r000767_1 >= 0 && sec_r000767_1 <= 255);
    __CPROVER_assume(sec_r000767_2 >= 0 && sec_r000767_2 <= 255);
    __CPROVER_assume(sec_r000767_3 >= 0 && sec_r000767_3 <= 255);
    __CPROVER_assume(sec_r000767_4 >= 0 && sec_r000767_4 <= 255);
    __CPROVER_assume(sec_r000767_5 >= 0 && sec_r000767_5 <= 255);
    __CPROVER_assume(sec_r000767_6 >= 0 && sec_r000767_6 <= 255);
    __CPROVER_assume(sec_r000767_7 >= 0 && sec_r000767_7 <= 255);
    __CPROVER_assume(sec_r000767_8 >= 0 && sec_r000767_8 <= 255);
    __CPROVER_assume(sec_r000767_9 >= 0 && sec_r000767_9 <= 255);
    __CPROVER_assume(sec_r000767_10 >= 0 && sec_r000767_10 <= 255);
    __CPROVER_assume(sec_r000767_11 >= 0 && sec_r000767_11 <= 255);
    __CPROVER_assume(sec_r000767_12 >= 0 && sec_r000767_12 <= 255);
    __CPROVER_assume(sec_r000767_13 >= 0 && sec_r000767_13 <= 255);
    __CPROVER_assume(sec_r000767_14 >= 0 && sec_r000767_14 <= 255);
    __CPROVER_assume(sec_r000767_15 >= 0 && sec_r000767_15 <= 255);
    __CPROVER_assume(sec_r000767_16 >= 0 && sec_r000767_16 <= 255);

    struct EventLog_R000767_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000767_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000767_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000767_0 + 7) & 15;
    struct StreamBuffer_R000767_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000767_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000767_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000767_0 + 9) & 15;
    struct FilterState_R000767_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000767_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000767_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000767_0 + 11) & 15;
    struct CipherContext_R000767_6713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000767_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000767_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000767_0 + 13) & 15;

    union RegisterBank_R000767_6713_0 u_var;
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
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 34) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 49) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 17) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 32) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 24) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 39) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
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
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((sec_r000767_7 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_33 = (pub_r000767_4 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000767_4 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000767_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000767_3 & 2) != 0) {
            stage_v_34 = (pub_r000767_12 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000767_12 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000767_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_35 = (pub_r000767_6 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000767_6 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000767_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_36 = (pub_r000767_2 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000767_2 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000767_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_37 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_38 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000767_4 & 2) != 0) {
            stage_v_39 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_40 = (pub_r000767_12 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000767_12 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000767_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_41 = (pub_r000767_1 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000767_1 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000767_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_42 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000767_6 & 2) != 0) {
            stage_v_43 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_44 = (pub_r000767_8 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000767_8 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000767_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_45 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_46 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000767_13 & 2) != 0) {
            stage_v_47 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_48 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000767_13 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_49 = (pub_r000767_1 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000767_1 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000767_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_50 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_51 = (pub_r000767_1 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000767_1 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000767_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_52 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000767_12 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_53 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000767_3 & 2) != 0) {
            stage_v_54 = (pub_r000767_16 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000767_16 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000767_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000767_16 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_55 = (pub_r000767_17 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000767_17 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000767_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_56 = (pub_r000767_6 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000767_6 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000767_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000767_4 & 1) != 0) {
        if ((sec_r000767_14 & 2) != 0) {
            stage_v_57 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_58 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_59 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_60 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_61 = (pub_r000767_4 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000767_4 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000767_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_62 = (pub_r000767_18 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000767_18 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000767_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_63 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000767_13 & 2) != 0) {
            stage_v_64 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_65 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_66 = (pub_r000767_3 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000767_3 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000767_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000767_8 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_67 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_68 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_69 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_70 = (pub_r000767_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000767_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000767_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000767_3 & 2) != 0) {
            stage_v_71 = (pub_r000767_10 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000767_10 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000767_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000767_4 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_72 = (pub_r000767_1 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000767_1 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000767_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_73 = (pub_r000767_14 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000767_14 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000767_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_5 & 2) != 0) {
            stage_v_74 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_75 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_76 = (pub_r000767_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000767_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000767_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000767_5 & 2) != 0) {
            stage_v_77 = (pub_r000767_5 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000767_5 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000767_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000767_3 & 1) != 0) {
        if ((sec_r000767_4 & 2) != 0) {
            stage_v_78 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_79 = (pub_r000767_14 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000767_14 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000767_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_80 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_81 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000767_5 & 2) != 0) {
            stage_v_82 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000767_5 & 2) != 0) {
            stage_v_83 = (pub_r000767_12 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000767_12 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000767_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000767_3 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_84 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_85 = (pub_r000767_17 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000767_17 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000767_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000767_2 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_86 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000767_6 & 2) != 0) {
            stage_v_87 = (pub_r000767_4 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000767_4 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000767_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000767_9 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_88 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_89 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000767_6 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_90 = (pub_r000767_17 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000767_17 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000767_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_91 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_92 = (pub_r000767_18 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000767_18 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000767_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000767_13 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_93 = (pub_r000767_18 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000767_18 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000767_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_94 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000767_16 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_95 = (pub_r000767_16 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000767_16 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000767_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_96 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000767_13 & 2) != 0) {
            stage_v_97 = (pub_r000767_12 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000767_12 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000767_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_98 = (pub_r000767_16 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000767_16 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000767_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000767_14 & 2) != 0) {
            stage_v_99 = (pub_r000767_18 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000767_18 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000767_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000767_8 & 2) != 0) {
            stage_v_100 = (pub_r000767_6 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000767_6 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000767_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000767_14 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_101 = (pub_r000767_4 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000767_4 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000767_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000767_2 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_102 = (pub_r000767_6 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000767_6 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000767_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000767_13 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_103 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000767_16 & 2) != 0) {
            stage_v_104 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_13 & 2) != 0) {
            stage_v_105 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000767_7 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_106 = (pub_r000767_4 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000767_4 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000767_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000767_3 & 2) != 0) {
            stage_v_107 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_108 = (pub_r000767_2 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000767_2 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000767_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000767_7 & 2) != 0) {
            stage_v_109 = (pub_r000767_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000767_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000767_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_110 = (pub_r000767_8 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000767_8 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000767_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000767_0 & 1) != 0) {
        if ((sec_r000767_15 & 2) != 0) {
            stage_v_111 = (pub_r000767_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000767_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000767_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000767_9 & 2) != 0) {
            stage_v_112 = (pub_r000767_0 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000767_0 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000767_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000767_7 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_113 = (pub_r000767_1 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000767_1 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000767_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000767_14 & 2) != 0) {
            stage_v_114 = (pub_r000767_18 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000767_18 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000767_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000767_3 & 1) != 0) {
        if ((sec_r000767_0 & 2) != 0) {
            stage_v_115 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000767_12 & 2) != 0) {
            stage_v_116 = (pub_r000767_13 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000767_13 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000767_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000767_10 & 2) != 0) {
            stage_v_117 = (pub_r000767_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000767_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000767_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000767_5 & 1) != 0) {
        if ((sec_r000767_13 & 2) != 0) {
            stage_v_118 = (pub_r000767_15 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000767_15 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000767_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000767_2 & 2) != 0) {
            stage_v_119 = (pub_r000767_16 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000767_16 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000767_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000767_6 & 2) != 0) {
            stage_v_120 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000767_1 & 1) != 0) {
        if ((sec_r000767_14 & 2) != 0) {
            stage_v_121 = (pub_r000767_17 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000767_17 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000767_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000767_1 & 2) != 0) {
            stage_v_122 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000767_11 & 2) != 0) {
            stage_v_123 = (pub_r000767_9 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000767_9 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000767_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000767_11 & 1) != 0) {
        if ((sec_r000767_5 & 2) != 0) {
            stage_v_124 = (pub_r000767_19 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000767_19 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000767_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000767_4 & 2) != 0) {
            stage_v_125 = (pub_r000767_10 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000767_10 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000767_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
