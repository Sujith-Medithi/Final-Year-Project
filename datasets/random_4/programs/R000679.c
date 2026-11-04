/*
 * Benchmark Program: R000679
 * Family: nested_implicit_flow
 * Generator Seed: 467913
 * High Inputs: 21 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000679_7913_0 {
    unsigned char capacity;
    short tail;
    int head;
    int state;
    unsigned char checksum;
    int watermark;
    int buffer[3];
};

struct DeviceConfig_R000679_7913_1 {
    int timeout;
    short parity;
    unsigned char baud_rate;
    int stop_bits;
    int port;
    int buffer[3];
};

struct MatrixBlock_R000679_7913_2 {
    short density;
    short trace;
    int determinant;
    int buffer[3];
};

struct AudioFrame_R000679_7913_3 {
    int sample_rate;
    int gain;
    int rms;
    int buffer[3];
};

union PacketPayload_R000679_7913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000679_7913_0(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_75) & 63;
    acc ^= aux;
    int offset_92 = 0;
    for (int k = 0; k < 3; k++) {
        offset_92 = (offset_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_92) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_78 = 0;
    for (int k = 0; k < 3; k++) {
        delta_78 = (delta_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_2(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_74 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_74 = (quantum_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_25 = 0;
    for (int k = 0; k < 3; k++) {
        offset_25 = (offset_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_96 = local_arr[aux % 3];
    acc = (acc + pivot_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_42 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_42 > 38) {
        acc = (acc + vector_42 * 2 + 5) & 127;
        aux ^= (vector_42 & 15);
    } else {
        acc = (acc - vector_42 + 11) & 127;
        aux += 3;
    }
    int quantum_89 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_89 = (quantum_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_89) & 127;
    }
    int residue_71 = (aux + st.buffer[1]) & 3;
    switch (residue_71) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_6(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int scale_85 = local_arr[aux % 3];
    acc = (acc + scale_85 * 2) & 127;
    int damping_87 = 0;
    for (int k = 0; k < 2; k++) {
        damping_87 = (damping_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_87) & 127;
    }
    int offset_81 = (aux + st.buffer[1]) & 3;
    switch (offset_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quotient_52 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_52 > 32) {
        acc = (acc + quotient_52 * 2 + 5) & 127;
        aux ^= (quotient_52 & 15);
    } else {
        acc = (acc - quotient_52 + 11) & 127;
        aux += 3;
    }
    int metric_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_70 = 0;
    for (int k = 0; k < 3; k++) {
        segment_70 = (segment_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_70) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int window_39 = local_arr[aux % 3];
    acc = (acc + window_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_85 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_85 > 22) {
        acc = (acc + threshold_85 * 2 + 5) & 127;
        aux ^= (threshold_85 & 15);
    } else {
        acc = (acc - threshold_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_38 = local_arr[aux % 3];
    acc = (acc + phase_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_10(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_30 = (aux + st.buffer[1]) & 3;
    switch (damping_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_87 > 43) {
        acc = (acc + quotient_87 * 2 + 5) & 127;
        aux ^= (quotient_87 & 15);
    } else {
        acc = (acc - quotient_87 + 11) & 127;
        aux += 3;
    }
    int coefficient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000679_7913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_92 = (aux + st.buffer[1]) & 3;
    switch (residue_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_80 = 0;
    for (int k = 0; k < 3; k++) {
        segment_80 = (segment_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_80) & 127;
    }
    int damping_40 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_40 > 18) {
        acc = (acc + damping_40 * 2 + 5) & 127;
        aux ^= (damping_40 & 15);
    } else {
        acc = (acc - damping_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_12(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_81 = 0;
    for (int k = 0; k < 3; k++) {
        segment_81 = (segment_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_81) & 127;
    }
    int quantum_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000679_7913_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000679_7913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_48 = (aux + st.buffer[1]) & 3;
    switch (index_reg_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_40 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_40 = (threshold_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_73 = local_arr[aux % 3];
    acc = (acc + phase_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_77 = (aux + st.buffer[1]) & 3;
    switch (pivot_77) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_14 = 0;
    for (int k = 0; k < 3; k++) {
        segment_14 = (segment_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_14) & 127;
    }
    int pivot_75 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_75 > 37) {
        acc = (acc + pivot_75 * 2 + 5) & 127;
        aux ^= (pivot_75 & 15);
    } else {
        acc = (acc - pivot_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_81) & 63;
    acc ^= aux;
    int parity_36 = (aux + st.buffer[1]) & 3;
    switch (parity_36) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_69 > 29) {
        acc = (acc + cursor_69 * 2 + 5) & 127;
        aux ^= (cursor_69 & 15);
    } else {
        acc = (acc - cursor_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000679_7913_16(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000679_7913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_97) & 63;
    acc ^= aux;
    int vector_25 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_25 > 40) {
        acc = (acc + vector_25 * 2 + 5) & 127;
        aux ^= (vector_25 & 15);
    } else {
        acc = (acc - vector_25 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_59 = local_arr[aux % 3];
    acc = (acc + residue_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000679_7913_17(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000679_7913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_61 = (aux + st.buffer[1]) & 3;
    switch (phase_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_37 = local_arr[aux % 3];
    acc = (acc + quotient_37 * 2) & 127;
    int scale_91 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_91 > 37) {
        acc = (acc + scale_91 * 2 + 5) & 127;
        aux ^= (scale_91 & 15);
    } else {
        acc = (acc - scale_91 + 11) & 127;
        aux += 3;
    }
    int threshold_68 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_68 = (threshold_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_68) & 127;
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
    int pub_r000679_16;
    int pub_r000679_17;
    int pub_r000679_18;
    int pub_r000679_19;
    int out_sink = 0;
    int chk_sum = 0;

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
    __CPROVER_assume(pub_r000679_16 >= -100 && pub_r000679_16 <= 100);
    __CPROVER_assume(pub_r000679_17 >= -100 && pub_r000679_17 <= 100);
    __CPROVER_assume(pub_r000679_18 >= -100 && pub_r000679_18 <= 100);
    __CPROVER_assume(pub_r000679_19 >= -100 && pub_r000679_19 <= 100);
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

    struct StreamBuffer_R000679_7913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000679_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000679_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000679_0 + 7) & 15;
    struct DeviceConfig_R000679_7913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000679_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000679_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000679_0 + 9) & 15;
    struct MatrixBlock_R000679_7913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000679_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000679_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000679_0 + 11) & 15;
    struct AudioFrame_R000679_7913_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000679_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000679_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000679_0 + 13) & 15;

    union PacketPayload_R000679_7913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 11) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 26) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

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
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

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
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
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
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 15) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 30) {
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
    if (stage_v_57 > 23) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 38) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 14) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 29) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 18) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 33) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
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

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 13) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 28) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 18) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 33) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 22) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 37) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 95 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[2] * 2 + 310) & 63;
    if (stage_v_101 > 29) {
        out_sink = (out_sink + stage_v_101 - 5) & 255;
        if (stage_v_101 > 44) {
            chk_sum ^= (stage_v_101 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_101 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 31) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 46) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_3.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 28) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 43) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_3.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 32) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 47) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 35) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 50) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 32) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 47) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 118 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_3.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 27) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 42) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = table[0];
    table[0] = (table[1] + 241) & 63;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 11) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 26) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (out_sink > 100) ? (chk_sum & 31) : (128 & 31);
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= (stage_v_123 << 1) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 26) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 41) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 37) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 52) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_3.buffer[0] ^ 138) & 3;
    switch (stage_v_135) {
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

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 30) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 45) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_2.buffer[0] * 2 + 421) & 63;
    if (stage_v_138 > 15) {
        out_sink = (out_sink + stage_v_138 - 5) & 255;
        if (stage_v_138 > 30) {
            chk_sum ^= (stage_v_138 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_138 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_2.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (out_sink > 100) ? (chk_sum & 31) : (167 & 31);
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= (stage_v_162 << 1) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_3.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 15) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 30) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[0] ^ 176) & 3;
    switch (stage_v_173) {
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

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] ^ 180) & 3;
    switch (stage_v_177) {
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

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_2.buffer[0] ^ 181) & 3;
    switch (stage_v_178) {
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

    /* Execution Pipeline Stage 179 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = table[0];
    table[0] = (table[1] + 361) & 63;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (out_sink > 100) ? (chk_sum & 31) : (186 & 31);
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= (stage_v_181 << 1) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_2.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Security Information Flow: Family = nested_implicit_flow */
    if ((sec_r000679_13 & 1) != 0) {
        if ((sec_r000679_14 & 2) != 0) {
            out_sink += 35;
        } else {
            out_sink += 16;
        }
    } else {
        if ((sec_r000679_13 & 4) != 0) {
            out_sink -= 28;
        } else {
            out_sink -= 54;
        }
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
