/*
 * Benchmark Program: R000387
 * Security Family: nested_implicit_flow
 * Generator Seed: 538713
 * High Inputs: 22 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000387_8713_0 {
    unsigned char timeout;
    unsigned char parity;
    int baud_rate;
    int id;
    int buffer[3];
};

struct CipherContext_R000387_8713_1 {
    int counter;
    unsigned char flags;
    int iv;
    int round_key;
    unsigned char tag;
    int buffer[3];
};

struct AudioFrame_R000387_8713_2 {
    int envelope;
    short sample_rate;
    unsigned char rms;
    int gain;
    int buffer[3];
};

struct StreamBuffer_R000387_8713_3 {
    unsigned char capacity;
    unsigned char watermark;
    int state;
    int tail;
    unsigned char head;
    int buffer[3];
};

union PacketPayload_R000387_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000387_8713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000387_8713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int pivot_30 = local_arr[aux % 3];
    acc = (acc + pivot_30 * 2) & 127;
    int pivot_79 = (aux + st.buffer[1]) & 3;
    switch (pivot_79) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int sample_12 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_12 > 44) {
        acc = (acc + sample_12 * 2 + 5) & 127;
        aux ^= (sample_12 & 15);
    } else {
        acc = (acc - sample_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_20 = (aux + st.buffer[1]) & 3;
    switch (parity_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_76) & 63;
    acc ^= aux;
    int tally_19 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_19 > 22) {
        acc = (acc + tally_19 * 2 + 5) & 127;
        aux ^= (tally_19 & 15);
    } else {
        acc = (acc - tally_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_99 = (aux + st.buffer[1]) & 3;
    switch (tracker_99) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_46 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_46 > 40) {
        acc = (acc + damping_46 * 2 + 5) & 127;
        aux ^= (damping_46 & 15);
    } else {
        acc = (acc - damping_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_73 = local_arr[aux % 3];
    acc = (acc + delta_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_63 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_63 > 14) {
        acc = (acc + residue_63 * 2 + 5) & 127;
        aux ^= (residue_63 & 15);
    } else {
        acc = (acc - residue_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000387_8713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_18 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_18 > 20) {
        acc = (acc + weight_18 * 2 + 5) & 127;
        aux ^= (weight_18 & 15);
    } else {
        acc = (acc - weight_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_94) & 63;
    acc ^= aux;
    int delta_47 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_47 > 40) {
        acc = (acc + delta_47 * 2 + 5) & 127;
        aux ^= (delta_47 & 15);
    } else {
        acc = (acc - delta_47 + 11) & 127;
        aux += 3;
    }
    int vector_18 = (aux + st.buffer[1]) & 3;
    switch (vector_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_9(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000387_8713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_53 = (aux + st.buffer[1]) & 3;
    switch (vector_53) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000387_8713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int checksum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_20) & 63;
    acc ^= aux;
    int factor_15 = (aux + st.buffer[1]) & 3;
    switch (factor_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_52 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_52 > 24) {
        acc = (acc + anchor_52 * 2 + 5) & 127;
        aux ^= (anchor_52 & 15);
    } else {
        acc = (acc - anchor_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_83 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_83 > 42) {
        acc = (acc + offset_83 * 2 + 5) & 127;
        aux ^= (offset_83 & 15);
    } else {
        acc = (acc - offset_83 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_93 = local_arr[aux % 3];
    acc = (acc + accumulator_93 * 2) & 127;
    int tally_57 = (aux + st.buffer[1]) & 3;
    switch (tally_57) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_77) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_46 = (aux + st.buffer[1]) & 3;
    switch (segment_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tally_71 = local_arr[aux % 3];
    acc = (acc + tally_71 * 2) & 127;
    int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_71 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_71 > 43) {
        acc = (acc + weight_71 * 2 + 5) & 127;
        aux ^= (weight_71 & 15);
    } else {
        acc = (acc - weight_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_15(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int sample_68 = local_arr[aux % 3];
    acc = (acc + sample_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_16(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_45 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_45 > 22) {
        acc = (acc + cursor_45 * 2 + 5) & 127;
        aux ^= (cursor_45 & 15);
    } else {
        acc = (acc - cursor_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_28 = (aux + st.buffer[1]) & 3;
    switch (index_reg_28) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_32 = (aux + st.buffer[1]) & 3;
    switch (coefficient_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_72 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_72 > 15) {
        acc = (acc + pivot_72 * 2 + 5) & 127;
        aux ^= (pivot_72 & 15);
    } else {
        acc = (acc - pivot_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_50) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000387_8713_19(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_13 = (aux + st.buffer[1]) & 3;
    switch (coefficient_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_20(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000387_8713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_34) & 63;
    acc ^= aux;
    int margin_96 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_96 > 28) {
        acc = (acc + margin_96 * 2 + 5) & 127;
        aux ^= (margin_96 & 15);
    } else {
        acc = (acc - margin_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_21(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_50) & 63;
    acc ^= aux;
    int index_reg_94 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_94 > 27) {
        acc = (acc + index_reg_94 * 2 + 5) & 127;
        aux ^= (index_reg_94 & 15);
    } else {
        acc = (acc - index_reg_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_33 = local_arr[aux % 3];
    acc = (acc + checksum_33 * 2) & 127;
    int vector_97 = (aux + st.buffer[1]) & 3;
    switch (vector_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000387_8713_22(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000387_8713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_51 = (aux + st.buffer[1]) & 3;
    switch (segment_51) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000387_0;
    int sec_r000387_1;
    int sec_r000387_2;
    int sec_r000387_3;
    int sec_r000387_4;
    int sec_r000387_5;
    int sec_r000387_6;
    int sec_r000387_7;
    int sec_r000387_8;
    int sec_r000387_9;
    int sec_r000387_10;
    int sec_r000387_11;
    int sec_r000387_12;
    int sec_r000387_13;
    int sec_r000387_14;
    int sec_r000387_15;
    int sec_r000387_16;
    int sec_r000387_17;
    int sec_r000387_18;
    int sec_r000387_19;
    int sec_r000387_20;
    int sec_r000387_21;
    int pub_r000387_0;
    int pub_r000387_1;
    int pub_r000387_2;
    int pub_r000387_3;
    int pub_r000387_4;
    int pub_r000387_5;
    int pub_r000387_6;
    int pub_r000387_7;
    int pub_r000387_8;
    int pub_r000387_9;
    int pub_r000387_10;
    int pub_r000387_11;
    int pub_r000387_12;
    int pub_r000387_13;
    int pub_r000387_14;
    int pub_r000387_15;
    int pub_r000387_16;
    int pub_r000387_17;
    int pub_r000387_18;
    int pub_r000387_19;
    int pub_r000387_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000387_0 >= -100 && pub_r000387_0 <= 100);
    __CPROVER_assume(pub_r000387_1 >= -100 && pub_r000387_1 <= 100);
    __CPROVER_assume(pub_r000387_2 >= -100 && pub_r000387_2 <= 100);
    __CPROVER_assume(pub_r000387_3 >= -100 && pub_r000387_3 <= 100);
    __CPROVER_assume(pub_r000387_4 >= -100 && pub_r000387_4 <= 100);
    __CPROVER_assume(pub_r000387_5 >= -100 && pub_r000387_5 <= 100);
    __CPROVER_assume(pub_r000387_6 >= -100 && pub_r000387_6 <= 100);
    __CPROVER_assume(pub_r000387_7 >= -100 && pub_r000387_7 <= 100);
    __CPROVER_assume(pub_r000387_8 >= -100 && pub_r000387_8 <= 100);
    __CPROVER_assume(pub_r000387_9 >= -100 && pub_r000387_9 <= 100);
    __CPROVER_assume(pub_r000387_10 >= -100 && pub_r000387_10 <= 100);
    __CPROVER_assume(pub_r000387_11 >= -100 && pub_r000387_11 <= 100);
    __CPROVER_assume(pub_r000387_12 >= -100 && pub_r000387_12 <= 100);
    __CPROVER_assume(pub_r000387_13 >= -100 && pub_r000387_13 <= 100);
    __CPROVER_assume(pub_r000387_14 >= -100 && pub_r000387_14 <= 100);
    __CPROVER_assume(pub_r000387_15 >= -100 && pub_r000387_15 <= 100);
    __CPROVER_assume(pub_r000387_16 >= -100 && pub_r000387_16 <= 100);
    __CPROVER_assume(pub_r000387_17 >= -100 && pub_r000387_17 <= 100);
    __CPROVER_assume(pub_r000387_18 >= -100 && pub_r000387_18 <= 100);
    __CPROVER_assume(pub_r000387_19 >= -100 && pub_r000387_19 <= 100);
    __CPROVER_assume(pub_r000387_20 >= -100 && pub_r000387_20 <= 100);
    __CPROVER_assume(sec_r000387_0 >= 0 && sec_r000387_0 <= 255);
    __CPROVER_assume(sec_r000387_1 >= 0 && sec_r000387_1 <= 255);
    __CPROVER_assume(sec_r000387_2 >= 0 && sec_r000387_2 <= 255);
    __CPROVER_assume(sec_r000387_3 >= 0 && sec_r000387_3 <= 255);
    __CPROVER_assume(sec_r000387_4 >= 0 && sec_r000387_4 <= 255);
    __CPROVER_assume(sec_r000387_5 >= 0 && sec_r000387_5 <= 255);
    __CPROVER_assume(sec_r000387_6 >= 0 && sec_r000387_6 <= 255);
    __CPROVER_assume(sec_r000387_7 >= 0 && sec_r000387_7 <= 255);
    __CPROVER_assume(sec_r000387_8 >= 0 && sec_r000387_8 <= 255);
    __CPROVER_assume(sec_r000387_9 >= 0 && sec_r000387_9 <= 255);
    __CPROVER_assume(sec_r000387_10 >= 0 && sec_r000387_10 <= 255);
    __CPROVER_assume(sec_r000387_11 >= 0 && sec_r000387_11 <= 255);
    __CPROVER_assume(sec_r000387_12 >= 0 && sec_r000387_12 <= 255);
    __CPROVER_assume(sec_r000387_13 >= 0 && sec_r000387_13 <= 255);
    __CPROVER_assume(sec_r000387_14 >= 0 && sec_r000387_14 <= 255);
    __CPROVER_assume(sec_r000387_15 >= 0 && sec_r000387_15 <= 255);
    __CPROVER_assume(sec_r000387_16 >= 0 && sec_r000387_16 <= 255);
    __CPROVER_assume(sec_r000387_17 >= 0 && sec_r000387_17 <= 255);
    __CPROVER_assume(sec_r000387_18 >= 0 && sec_r000387_18 <= 255);
    __CPROVER_assume(sec_r000387_19 >= 0 && sec_r000387_19 <= 255);
    __CPROVER_assume(sec_r000387_20 >= 0 && sec_r000387_20 <= 255);
    __CPROVER_assume(sec_r000387_21 >= 0 && sec_r000387_21 <= 255);

    struct DeviceConfig_R000387_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000387_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000387_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000387_0 + 7) & 15;
    struct CipherContext_R000387_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000387_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000387_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000387_0 + 9) & 15;
    struct AudioFrame_R000387_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000387_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000387_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000387_0 + 11) & 15;
    struct StreamBuffer_R000387_8713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000387_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000387_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000387_0 + 13) & 15;

    union PacketPayload_R000387_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

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
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 24) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 39) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 32) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 47) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 44) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 35) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 50) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 15) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 30) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 27) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 42) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

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
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 39) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 54) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 22) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 37) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

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
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000387_15 & 1) != 0) {
        if ((sec_r000387_3 & 2) != 0) {
            stage_v_71 = (pub_r000387_7 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000387_7 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000387_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000387_4 & 2) != 0) {
            stage_v_72 = (pub_r000387_17 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000387_17 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000387_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000387_7 & 1) != 0) {
        if ((sec_r000387_19 & 2) != 0) {
            stage_v_73 = (pub_r000387_10 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000387_10 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000387_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000387_5 & 2) != 0) {
            stage_v_74 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000387_15 & 1) != 0) {
        if ((sec_r000387_8 & 2) != 0) {
            stage_v_75 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000387_7 & 2) != 0) {
            stage_v_76 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000387_21 & 1) != 0) {
        if ((sec_r000387_3 & 2) != 0) {
            stage_v_77 = (pub_r000387_10 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000387_10 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000387_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000387_5 & 2) != 0) {
            stage_v_78 = (pub_r000387_17 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000387_17 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000387_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000387_11 & 1) != 0) {
        if ((sec_r000387_0 & 2) != 0) {
            stage_v_79 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000387_0 & 2) != 0) {
            stage_v_80 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000387_7 & 2) != 0) {
            stage_v_81 = (pub_r000387_17 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000387_17 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000387_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000387_3 & 2) != 0) {
            stage_v_82 = (pub_r000387_20 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000387_20 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000387_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000387_1 & 2) != 0) {
            stage_v_83 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000387_17 & 2) != 0) {
            stage_v_84 = (pub_r000387_15 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000387_15 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000387_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000387_6 & 2) != 0) {
            stage_v_85 = (pub_r000387_8 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000387_8 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000387_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_86 = (pub_r000387_0 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000387_0 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000387_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000387_21 & 2) != 0) {
            stage_v_87 = (pub_r000387_19 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000387_19 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000387_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000387_19 & 2) != 0) {
            stage_v_88 = (pub_r000387_9 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000387_9 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000387_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000387_9 & 2) != 0) {
            stage_v_89 = (pub_r000387_2 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000387_2 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000387_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000387_8 & 1) != 0) {
        if ((sec_r000387_17 & 2) != 0) {
            stage_v_90 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000387_3 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_91 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000387_4 & 1) != 0) {
        if ((sec_r000387_18 & 2) != 0) {
            stage_v_92 = (pub_r000387_19 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000387_19 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000387_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000387_2 & 2) != 0) {
            stage_v_93 = (pub_r000387_3 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000387_3 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000387_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000387_14 & 2) != 0) {
            stage_v_94 = (pub_r000387_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000387_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000387_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000387_14 & 2) != 0) {
            stage_v_95 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000387_7 & 2) != 0) {
            stage_v_96 = (pub_r000387_20 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000387_20 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000387_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000387_18 & 2) != 0) {
            stage_v_97 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000387_11 & 2) != 0) {
            stage_v_98 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000387_19 & 1) != 0) {
        if ((sec_r000387_21 & 2) != 0) {
            stage_v_99 = (pub_r000387_1 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000387_1 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000387_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000387_18 & 2) != 0) {
            stage_v_100 = (pub_r000387_0 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000387_0 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000387_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000387_18 & 1) != 0) {
        if ((sec_r000387_9 & 2) != 0) {
            stage_v_101 = (pub_r000387_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000387_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000387_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000387_9 & 2) != 0) {
            stage_v_102 = (pub_r000387_2 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000387_2 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000387_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000387_6 & 2) != 0) {
            stage_v_103 = (pub_r000387_2 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000387_2 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000387_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000387_4 & 2) != 0) {
            stage_v_104 = (pub_r000387_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000387_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000387_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000387_21 & 1) != 0) {
        if ((sec_r000387_0 & 2) != 0) {
            stage_v_105 = (pub_r000387_16 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000387_16 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000387_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000387_18 & 2) != 0) {
            stage_v_106 = (pub_r000387_5 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000387_5 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000387_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_107 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000387_9 & 2) != 0) {
            stage_v_108 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000387_20 & 2) != 0) {
            stage_v_109 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000387_12 & 2) != 0) {
            stage_v_110 = (pub_r000387_9 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000387_9 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000387_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000387_14 & 2) != 0) {
            stage_v_111 = (pub_r000387_14 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000387_14 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000387_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_112 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000387_9 & 1) != 0) {
        if ((sec_r000387_20 & 2) != 0) {
            stage_v_113 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000387_4 & 2) != 0) {
            stage_v_114 = (pub_r000387_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000387_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000387_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000387_6 & 1) != 0) {
        if ((sec_r000387_9 & 2) != 0) {
            stage_v_115 = (pub_r000387_1 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000387_1 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000387_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000387_5 & 2) != 0) {
            stage_v_116 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000387_2 & 2) != 0) {
            stage_v_117 = (pub_r000387_2 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000387_2 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000387_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000387_14 & 1) != 0) {
        if ((sec_r000387_3 & 2) != 0) {
            stage_v_118 = (pub_r000387_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000387_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000387_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000387_14 & 2) != 0) {
            stage_v_119 = (pub_r000387_12 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000387_12 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000387_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000387_2 & 2) != 0) {
            stage_v_120 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000387_4 & 2) != 0) {
            stage_v_121 = (pub_r000387_9 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000387_9 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000387_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000387_3 & 2) != 0) {
            stage_v_122 = (pub_r000387_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000387_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000387_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_123 = (pub_r000387_5 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000387_5 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000387_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000387_2 & 2) != 0) {
            stage_v_124 = (pub_r000387_12 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000387_12 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000387_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000387_21 & 1) != 0) {
        if ((sec_r000387_6 & 2) != 0) {
            stage_v_125 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000387_11 & 2) != 0) {
            stage_v_126 = (pub_r000387_19 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000387_19 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000387_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000387_6 & 2) != 0) {
            stage_v_127 = (pub_r000387_20 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000387_20 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000387_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000387_18 & 1) != 0) {
        if ((sec_r000387_16 & 2) != 0) {
            stage_v_128 = (pub_r000387_10 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000387_10 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000387_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000387_2 & 2) != 0) {
            stage_v_129 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000387_21 & 2) != 0) {
            stage_v_130 = (pub_r000387_12 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000387_12 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000387_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000387_21 & 2) != 0) {
            stage_v_131 = (pub_r000387_2 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000387_2 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000387_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000387_4 & 2) != 0) {
            stage_v_132 = (pub_r000387_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000387_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000387_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000387_5 & 1) != 0) {
        if ((sec_r000387_12 & 2) != 0) {
            stage_v_133 = (pub_r000387_1 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000387_1 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000387_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000387_14 & 2) != 0) {
            stage_v_134 = (pub_r000387_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000387_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000387_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000387_2 & 1) != 0) {
        if ((sec_r000387_1 & 2) != 0) {
            stage_v_135 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000387_1 & 2) != 0) {
            stage_v_136 = (pub_r000387_10 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000387_10 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000387_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000387_19 & 2) != 0) {
            stage_v_137 = (pub_r000387_13 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000387_13 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000387_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000387_0 & 2) != 0) {
            stage_v_138 = (pub_r000387_8 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000387_8 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000387_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000387_5 & 2) != 0) {
            stage_v_139 = (pub_r000387_8 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000387_8 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000387_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000387_3 & 1) != 0) {
        if ((sec_r000387_11 & 2) != 0) {
            stage_v_140 = (pub_r000387_11 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000387_11 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000387_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000387_6 & 2) != 0) {
            stage_v_141 = (pub_r000387_14 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000387_14 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000387_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000387_17 & 2) != 0) {
            stage_v_142 = (pub_r000387_8 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000387_8 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000387_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000387_8 & 2) != 0) {
            stage_v_143 = (pub_r000387_18 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000387_18 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000387_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000387_19 & 2) != 0) {
            stage_v_144 = (pub_r000387_6 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000387_6 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000387_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
