/*
 * Benchmark Program: R000857
 * Security Family: nested_implicit_flow
 * Generator Seed: 585713
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000857_5713_0 {
    int counter;
    int round_key;
    unsigned char flags;
    int buffer[3];
};

struct SensorNode_R000857_5713_1 {
    int calib;
    unsigned char gain;
    int reading;
    int status;
    unsigned char offset;
    int buffer[3];
};

struct DeviceConfig_R000857_5713_2 {
    short timeout;
    unsigned char parity;
    int id;
    short port;
    unsigned char baud_rate;
    int buffer[3];
};

struct MatrixBlock_R000857_5713_3 {
    int determinant;
    short density;
    unsigned char scale;
    int buffer[3];
};

union ColorPixel_R000857_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000857_5713_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000857_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int accumulator_71 = (aux + st.buffer[1]) & 3;
    switch (accumulator_71) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000857_5713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_59 = local_arr[aux % 3];
    acc = (acc + threshold_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000857_5713_2(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_78 = (aux + st.buffer[1]) & 3;
    switch (parity_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_21 = local_arr[aux % 3];
    acc = (acc + parity_21 * 2) & 127;
    int quotient_39 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_39 > 48) {
        acc = (acc + quotient_39 * 2 + 5) & 127;
        aux ^= (quotient_39 & 15);
    } else {
        acc = (acc - quotient_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_3(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000857_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_44 = (aux + st.buffer[1]) & 3;
    switch (factor_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000857_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_28 = local_arr[aux % 3];
    acc = (acc + residue_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000857_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000857_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_64 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_64 > 20) {
        acc = (acc + threshold_64 * 2 + 5) & 127;
        aux ^= (threshold_64 & 15);
    } else {
        acc = (acc - threshold_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_42 = (aux + st.buffer[1]) & 3;
    switch (offset_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_6(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000857_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_66 = (aux + st.buffer[1]) & 3;
    switch (factor_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_31) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000857_5713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_98 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_98 > 18) {
        acc = (acc + mask_98 * 2 + 5) & 127;
        aux ^= (mask_98 & 15);
    } else {
        acc = (acc - mask_98 + 11) & 127;
        aux += 3;
    }
    int checksum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000857_5713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_40 = (aux + st.buffer[1]) & 3;
    switch (vector_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_42 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_42 > 50) {
        acc = (acc + tracker_42 * 2 + 5) & 127;
        aux ^= (tracker_42 & 15);
    } else {
        acc = (acc - tracker_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_9(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_93) & 63;
    acc ^= aux;
    int index_reg_57 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_57 > 23) {
        acc = (acc + index_reg_57 * 2 + 5) & 127;
        aux ^= (index_reg_57 & 15);
    } else {
        acc = (acc - index_reg_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000857_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_51 = local_arr[aux % 3];
    acc = (acc + tracker_51 * 2) & 127;
    int stride_22 = (aux + st.buffer[1]) & 3;
    switch (stride_22) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_11(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int factor_69 = local_arr[aux % 3];
    acc = (acc + factor_69 * 2) & 127;
    int accumulator_70 = (aux + st.buffer[1]) & 3;
    switch (accumulator_70) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_83 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_83 > 43) {
        acc = (acc + index_reg_83 * 2 + 5) & 127;
        aux ^= (index_reg_83 & 15);
    } else {
        acc = (acc - index_reg_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_35 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_35 > 19) {
        acc = (acc + scale_35 * 2 + 5) & 127;
        aux ^= (scale_35 & 15);
    } else {
        acc = (acc - scale_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000857_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int residue_64 = local_arr[aux % 3];
    acc = (acc + residue_64 * 2) & 127;
    int margin_21 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_21 > 49) {
        acc = (acc + margin_21 * 2 + 5) & 127;
        aux ^= (margin_21 & 15);
    } else {
        acc = (acc - margin_21 + 11) & 127;
        aux += 3;
    }
    int offset_93 = (aux + st.buffer[1]) & 3;
    switch (offset_93) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000857_5713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_56) & 63;
    acc ^= aux;
    int window_87 = (st.buffer[0] * 3 + aux) & 63;
    if (window_87 > 26) {
        acc = (acc + window_87 * 2 + 5) & 127;
        aux ^= (window_87 & 15);
    } else {
        acc = (acc - window_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000857_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_15 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_15 > 20) {
        acc = (acc + tally_15 * 2 + 5) & 127;
        aux ^= (tally_15 & 15);
    } else {
        acc = (acc - tally_15 + 11) & 127;
        aux += 3;
    }
    int segment_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000857_5713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_44 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_44 > 34) {
        acc = (acc + sample_44 * 2 + 5) & 127;
        aux ^= (sample_44 & 15);
    } else {
        acc = (acc - sample_44 + 11) & 127;
        aux += 3;
    }
    int factor_32 = (aux + st.buffer[1]) & 3;
    switch (factor_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_59) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_45 = local_arr[aux % 3];
    acc = (acc + window_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000857_5713_17(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_92) & 63;
    acc ^= aux;
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 49) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_45 = (aux + st.buffer[1]) & 3;
    switch (damping_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000857_5713_18(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000857_0;
    int sec_r000857_1;
    int sec_r000857_2;
    int sec_r000857_3;
    int sec_r000857_4;
    int sec_r000857_5;
    int sec_r000857_6;
    int sec_r000857_7;
    int sec_r000857_8;
    int sec_r000857_9;
    int sec_r000857_10;
    int sec_r000857_11;
    int sec_r000857_12;
    int sec_r000857_13;
    int sec_r000857_14;
    int sec_r000857_15;
    int sec_r000857_16;
    int sec_r000857_17;
    int sec_r000857_18;
    int sec_r000857_19;
    int sec_r000857_20;
    int sec_r000857_21;
    int sec_r000857_22;
    int sec_r000857_23;
    int pub_r000857_0;
    int pub_r000857_1;
    int pub_r000857_2;
    int pub_r000857_3;
    int pub_r000857_4;
    int pub_r000857_5;
    int pub_r000857_6;
    int pub_r000857_7;
    int pub_r000857_8;
    int pub_r000857_9;
    int pub_r000857_10;
    int pub_r000857_11;
    int pub_r000857_12;
    int pub_r000857_13;
    int pub_r000857_14;
    int pub_r000857_15;
    int pub_r000857_16;
    int pub_r000857_17;
    int pub_r000857_18;
    int pub_r000857_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000857_0 >= -100 && pub_r000857_0 <= 100);
    __CPROVER_assume(pub_r000857_1 >= -100 && pub_r000857_1 <= 100);
    __CPROVER_assume(pub_r000857_2 >= -100 && pub_r000857_2 <= 100);
    __CPROVER_assume(pub_r000857_3 >= -100 && pub_r000857_3 <= 100);
    __CPROVER_assume(pub_r000857_4 >= -100 && pub_r000857_4 <= 100);
    __CPROVER_assume(pub_r000857_5 >= -100 && pub_r000857_5 <= 100);
    __CPROVER_assume(pub_r000857_6 >= -100 && pub_r000857_6 <= 100);
    __CPROVER_assume(pub_r000857_7 >= -100 && pub_r000857_7 <= 100);
    __CPROVER_assume(pub_r000857_8 >= -100 && pub_r000857_8 <= 100);
    __CPROVER_assume(pub_r000857_9 >= -100 && pub_r000857_9 <= 100);
    __CPROVER_assume(pub_r000857_10 >= -100 && pub_r000857_10 <= 100);
    __CPROVER_assume(pub_r000857_11 >= -100 && pub_r000857_11 <= 100);
    __CPROVER_assume(pub_r000857_12 >= -100 && pub_r000857_12 <= 100);
    __CPROVER_assume(pub_r000857_13 >= -100 && pub_r000857_13 <= 100);
    __CPROVER_assume(pub_r000857_14 >= -100 && pub_r000857_14 <= 100);
    __CPROVER_assume(pub_r000857_15 >= -100 && pub_r000857_15 <= 100);
    __CPROVER_assume(pub_r000857_16 >= -100 && pub_r000857_16 <= 100);
    __CPROVER_assume(pub_r000857_17 >= -100 && pub_r000857_17 <= 100);
    __CPROVER_assume(pub_r000857_18 >= -100 && pub_r000857_18 <= 100);
    __CPROVER_assume(pub_r000857_19 >= -100 && pub_r000857_19 <= 100);
    __CPROVER_assume(sec_r000857_0 >= 0 && sec_r000857_0 <= 255);
    __CPROVER_assume(sec_r000857_1 >= 0 && sec_r000857_1 <= 255);
    __CPROVER_assume(sec_r000857_2 >= 0 && sec_r000857_2 <= 255);
    __CPROVER_assume(sec_r000857_3 >= 0 && sec_r000857_3 <= 255);
    __CPROVER_assume(sec_r000857_4 >= 0 && sec_r000857_4 <= 255);
    __CPROVER_assume(sec_r000857_5 >= 0 && sec_r000857_5 <= 255);
    __CPROVER_assume(sec_r000857_6 >= 0 && sec_r000857_6 <= 255);
    __CPROVER_assume(sec_r000857_7 >= 0 && sec_r000857_7 <= 255);
    __CPROVER_assume(sec_r000857_8 >= 0 && sec_r000857_8 <= 255);
    __CPROVER_assume(sec_r000857_9 >= 0 && sec_r000857_9 <= 255);
    __CPROVER_assume(sec_r000857_10 >= 0 && sec_r000857_10 <= 255);
    __CPROVER_assume(sec_r000857_11 >= 0 && sec_r000857_11 <= 255);
    __CPROVER_assume(sec_r000857_12 >= 0 && sec_r000857_12 <= 255);
    __CPROVER_assume(sec_r000857_13 >= 0 && sec_r000857_13 <= 255);
    __CPROVER_assume(sec_r000857_14 >= 0 && sec_r000857_14 <= 255);
    __CPROVER_assume(sec_r000857_15 >= 0 && sec_r000857_15 <= 255);
    __CPROVER_assume(sec_r000857_16 >= 0 && sec_r000857_16 <= 255);
    __CPROVER_assume(sec_r000857_17 >= 0 && sec_r000857_17 <= 255);
    __CPROVER_assume(sec_r000857_18 >= 0 && sec_r000857_18 <= 255);
    __CPROVER_assume(sec_r000857_19 >= 0 && sec_r000857_19 <= 255);
    __CPROVER_assume(sec_r000857_20 >= 0 && sec_r000857_20 <= 255);
    __CPROVER_assume(sec_r000857_21 >= 0 && sec_r000857_21 <= 255);
    __CPROVER_assume(sec_r000857_22 >= 0 && sec_r000857_22 <= 255);
    __CPROVER_assume(sec_r000857_23 >= 0 && sec_r000857_23 <= 255);

    struct CipherContext_R000857_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000857_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000857_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000857_0 + 7) & 15;
    struct SensorNode_R000857_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000857_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000857_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000857_0 + 9) & 15;
    struct DeviceConfig_R000857_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000857_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000857_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000857_0 + 11) & 15;
    struct MatrixBlock_R000857_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000857_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000857_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000857_0 + 13) & 15;

    union ColorPixel_R000857_5713_0 u_var;
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
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 19) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 34) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 12) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 27) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 49) {
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
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 10) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 25) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 28) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 43) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 13) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 28) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 19) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 34) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 26) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 41) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 33) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 48) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 24) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 39) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000857_4 & 1) != 0) {
        if ((sec_r000857_8 & 2) != 0) {
            stage_v_64 = (pub_r000857_5 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000857_5 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000857_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_65 = (pub_r000857_6 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000857_6 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000857_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000857_19 & 2) != 0) {
            stage_v_66 = (pub_r000857_11 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000857_11 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000857_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000857_5 & 2) != 0) {
            stage_v_67 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000857_3 & 1) != 0) {
        if ((sec_r000857_15 & 2) != 0) {
            stage_v_68 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000857_7 & 2) != 0) {
            stage_v_69 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000857_9 & 2) != 0) {
            stage_v_70 = (pub_r000857_5 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000857_5 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000857_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000857_1 & 2) != 0) {
            stage_v_71 = (pub_r000857_16 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000857_16 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000857_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000857_17 & 1) != 0) {
        if ((sec_r000857_23 & 2) != 0) {
            stage_v_72 = (pub_r000857_13 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000857_13 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000857_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_73 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_74 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000857_19 & 2) != 0) {
            stage_v_75 = (pub_r000857_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000857_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000857_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000857_5 & 1) != 0) {
        if ((sec_r000857_3 & 2) != 0) {
            stage_v_76 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000857_18 & 1) != 0) {
        if ((sec_r000857_9 & 2) != 0) {
            stage_v_77 = (pub_r000857_5 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000857_5 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000857_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000857_12 & 2) != 0) {
            stage_v_78 = (pub_r000857_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000857_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000857_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000857_11 & 1) != 0) {
        if ((sec_r000857_3 & 2) != 0) {
            stage_v_79 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000857_4 & 2) != 0) {
            stage_v_80 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000857_12 & 1) != 0) {
        if ((sec_r000857_5 & 2) != 0) {
            stage_v_81 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000857_2 & 2) != 0) {
            stage_v_82 = (pub_r000857_13 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000857_13 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000857_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000857_18 & 1) != 0) {
        if ((sec_r000857_5 & 2) != 0) {
            stage_v_83 = (pub_r000857_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000857_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000857_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000857_12 & 2) != 0) {
            stage_v_84 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000857_3 & 2) != 0) {
            stage_v_85 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000857_1 & 2) != 0) {
            stage_v_86 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_87 = (pub_r000857_6 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000857_6 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000857_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000857_23 & 2) != 0) {
            stage_v_88 = (pub_r000857_8 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000857_8 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000857_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000857_8 & 2) != 0) {
            stage_v_89 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000857_10 & 1) != 0) {
        if ((sec_r000857_0 & 2) != 0) {
            stage_v_90 = (pub_r000857_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000857_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000857_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_91 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000857_6 & 2) != 0) {
            stage_v_92 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000857_0 & 2) != 0) {
            stage_v_93 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000857_4 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_94 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000857_14 & 2) != 0) {
            stage_v_95 = (pub_r000857_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000857_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000857_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000857_11 & 2) != 0) {
            stage_v_96 = (pub_r000857_11 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000857_11 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000857_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000857_0 & 2) != 0) {
            stage_v_97 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000857_14 & 1) != 0) {
        if ((sec_r000857_16 & 2) != 0) {
            stage_v_98 = (pub_r000857_7 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000857_7 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000857_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000857_14 & 1) != 0) {
        if ((sec_r000857_3 & 2) != 0) {
            stage_v_99 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000857_14 & 2) != 0) {
            stage_v_100 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000857_6 & 2) != 0) {
            stage_v_101 = (pub_r000857_17 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000857_17 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000857_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000857_17 & 2) != 0) {
            stage_v_102 = (pub_r000857_7 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000857_7 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000857_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_103 = (pub_r000857_7 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000857_7 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000857_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000857_6 & 2) != 0) {
            stage_v_104 = (pub_r000857_8 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000857_8 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000857_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000857_19 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_105 = (pub_r000857_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000857_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000857_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_106 = (pub_r000857_6 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000857_6 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000857_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000857_9 & 1) != 0) {
        if ((sec_r000857_11 & 2) != 0) {
            stage_v_107 = (pub_r000857_16 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000857_16 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000857_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000857_14 & 1) != 0) {
        if ((sec_r000857_16 & 2) != 0) {
            stage_v_108 = (pub_r000857_17 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000857_17 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000857_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000857_19 & 2) != 0) {
            stage_v_109 = (pub_r000857_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000857_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000857_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000857_1 & 1) != 0) {
        if ((sec_r000857_23 & 2) != 0) {
            stage_v_110 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000857_22 & 2) != 0) {
            stage_v_111 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000857_20 & 1) != 0) {
        if ((sec_r000857_7 & 2) != 0) {
            stage_v_112 = (pub_r000857_16 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000857_16 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000857_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000857_18 & 2) != 0) {
            stage_v_113 = (pub_r000857_17 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000857_17 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000857_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_114 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_115 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000857_3 & 1) != 0) {
        if ((sec_r000857_17 & 2) != 0) {
            stage_v_116 = (pub_r000857_10 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000857_10 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000857_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000857_12 & 2) != 0) {
            stage_v_117 = (pub_r000857_13 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000857_13 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000857_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000857_7 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_118 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000857_14 & 2) != 0) {
            stage_v_119 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000857_4 & 2) != 0) {
            stage_v_120 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000857_18 & 1) != 0) {
        if ((sec_r000857_9 & 2) != 0) {
            stage_v_121 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000857_13 & 1) != 0) {
        if ((sec_r000857_18 & 2) != 0) {
            stage_v_122 = (pub_r000857_16 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000857_16 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000857_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000857_0 & 2) != 0) {
            stage_v_123 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000857_17 & 1) != 0) {
        if ((sec_r000857_12 & 2) != 0) {
            stage_v_124 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000857_22 & 2) != 0) {
            stage_v_125 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000857_14 & 2) != 0) {
            stage_v_126 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000857_5 & 1) != 0) {
        if ((sec_r000857_22 & 2) != 0) {
            stage_v_127 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000857_18 & 2) != 0) {
            stage_v_128 = (pub_r000857_8 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000857_8 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000857_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000857_9 & 2) != 0) {
            stage_v_129 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000857_3 & 1) != 0) {
        if ((sec_r000857_4 & 2) != 0) {
            stage_v_130 = (pub_r000857_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000857_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000857_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000857_8 & 2) != 0) {
            stage_v_131 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000857_23 & 2) != 0) {
            stage_v_132 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000857_6 & 2) != 0) {
            stage_v_133 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000857_8 & 2) != 0) {
            stage_v_134 = (pub_r000857_6 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000857_6 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000857_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000857_19 & 2) != 0) {
            stage_v_135 = (pub_r000857_3 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000857_3 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000857_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000857_18 & 2) != 0) {
            stage_v_136 = (pub_r000857_17 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000857_17 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000857_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000857_8 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_137 = (pub_r000857_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000857_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000857_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_138 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000857_2 & 2) != 0) {
            stage_v_139 = (pub_r000857_11 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000857_11 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000857_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000857_8 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_140 = (pub_r000857_8 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000857_8 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000857_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_141 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000857_2 & 2) != 0) {
            stage_v_142 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000857_14 & 2) != 0) {
            stage_v_143 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000857_2 & 2) != 0) {
            stage_v_144 = (pub_r000857_2 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000857_2 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000857_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_145 = (pub_r000857_7 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000857_7 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000857_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000857_0 & 1) != 0) {
        if ((sec_r000857_1 & 2) != 0) {
            stage_v_146 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000857_15 & 2) != 0) {
            stage_v_147 = (pub_r000857_14 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000857_14 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000857_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000857_20 & 1) != 0) {
        if ((sec_r000857_8 & 2) != 0) {
            stage_v_148 = (pub_r000857_0 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000857_0 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000857_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000857_19 & 2) != 0) {
            stage_v_149 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000857_11 & 2) != 0) {
            stage_v_150 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000857_16 & 2) != 0) {
            stage_v_151 = (pub_r000857_18 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000857_18 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000857_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000857_11 & 2) != 0) {
            stage_v_152 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000857_7 & 2) != 0) {
            stage_v_153 = (pub_r000857_12 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000857_12 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000857_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000857_20 & 2) != 0) {
            stage_v_154 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000857_2 & 2) != 0) {
            stage_v_155 = (pub_r000857_4 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000857_4 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000857_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000857_9 & 2) != 0) {
            stage_v_156 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000857_14 & 1) != 0) {
        if ((sec_r000857_0 & 2) != 0) {
            stage_v_157 = (pub_r000857_15 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000857_15 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000857_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000857_6 & 2) != 0) {
            stage_v_158 = (pub_r000857_14 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000857_14 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000857_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000857_1 & 1) != 0) {
        if ((sec_r000857_10 & 2) != 0) {
            stage_v_159 = (pub_r000857_9 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000857_9 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000857_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000857_18 & 1) != 0) {
        if ((sec_r000857_17 & 2) != 0) {
            stage_v_160 = (pub_r000857_0 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000857_0 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000857_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000857_19 & 1) != 0) {
        if ((sec_r000857_23 & 2) != 0) {
            stage_v_161 = (pub_r000857_1 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000857_1 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000857_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000857_21 & 2) != 0) {
            stage_v_162 = (pub_r000857_19 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000857_19 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000857_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
