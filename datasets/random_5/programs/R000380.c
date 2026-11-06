/*
 * Benchmark Program: R000380
 * Security Family: mixed_control_data
 * Generator Seed: 538013
 * High Inputs: 18 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000380_8013_0 {
    short head;
    int checksum;
    short watermark;
    int tail;
    int buffer[3];
};

struct Vector3D_R000380_8013_1 {
    unsigned char norm_sq;
    short pitch;
    int coord_x;
    int buffer[3];
};

struct DeviceConfig_R000380_8013_2 {
    int stop_bits;
    int timeout;
    int id;
    unsigned char parity;
    int port;
    int buffer[3];
};

struct MatrixBlock_R000380_8013_3 {
    unsigned char density;
    int determinant;
    short stride;
    unsigned char scale;
    unsigned char dim;
    unsigned char trace;
    int buffer[3];
};

union ColorPixel_R000380_8013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000380_8013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000380_8013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_20 = local_arr[aux % 3];
    acc = (acc + checksum_20 * 2) & 127;
    int segment_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000380_8013_1(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000380_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int segment_31 = (aux + st.buffer[1]) & 3;
    switch (segment_31) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_26) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_87 = local_arr[aux % 3];
    acc = (acc + quotient_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_2(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000380_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tally_71 = (aux + st.buffer[1]) & 3;
    switch (tally_71) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000380_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_88 = (aux + st.buffer[1]) & 3;
    switch (sample_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_53 = local_arr[aux % 3];
    acc = (acc + stride_53 * 2) & 127;
    int pivot_37 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_37 > 45) {
        acc = (acc + pivot_37 * 2 + 5) & 127;
        aux ^= (pivot_37 & 15);
    } else {
        acc = (acc - pivot_37 + 11) & 127;
        aux += 3;
    }
    int accumulator_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000380_8013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000380_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_55) & 63;
    acc ^= aux;
    int tally_69 = (aux + st.buffer[1]) & 3;
    switch (tally_69) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_68 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_68 > 19) {
        acc = (acc + quotient_68 * 2 + 5) & 127;
        aux ^= (quotient_68 & 15);
    } else {
        acc = (acc - quotient_68 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_49 = local_arr[aux % 3];
    acc = (acc + quantum_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_5(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000380_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int margin_50 = local_arr[aux % 3];
    acc = (acc + margin_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_6(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000380_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_24 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_24 > 43) {
        acc = (acc + index_reg_24 * 2 + 5) & 127;
        aux ^= (index_reg_24 & 15);
    } else {
        acc = (acc - index_reg_24 + 11) & 127;
        aux += 3;
    }
    int tally_34 = (aux + st.buffer[1]) & 3;
    switch (tally_34) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000380_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_93 = local_arr[aux % 3];
    acc = (acc + stride_93 * 2) & 127;
    int margin_32 = (aux + st.buffer[1]) & 3;
    switch (margin_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000380_8013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000380_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_61) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_35 = local_arr[aux % 3];
    acc = (acc + tracker_35 * 2) & 127;
    int cursor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_68 > 16) {
        acc = (acc + cursor_68 * 2 + 5) & 127;
        aux ^= (cursor_68 & 15);
    } else {
        acc = (acc - cursor_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000380_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tally_86 = local_arr[aux % 3];
    acc = (acc + tally_86 * 2) & 127;
    int pivot_53 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_53 > 10) {
        acc = (acc + pivot_53 * 2 + 5) & 127;
        aux ^= (pivot_53 & 15);
    } else {
        acc = (acc - pivot_53 + 11) & 127;
        aux += 3;
    }
    int quotient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000380_8013_10(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000380_8013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_34) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_10 = local_arr[aux % 3];
    acc = (acc + cursor_10 * 2) & 127;
    int margin_34 = (aux + st.buffer[1]) & 3;
    switch (margin_34) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000380_8013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000380_8013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_64 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_64 > 42) {
        acc = (acc + margin_64 * 2 + 5) & 127;
        aux ^= (margin_64 & 15);
    } else {
        acc = (acc - margin_64 + 11) & 127;
        aux += 3;
    }
    int parity_27 = (aux + st.buffer[1]) & 3;
    switch (parity_27) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_26 = local_arr[aux % 3];
    acc = (acc + threshold_26 * 2) & 127;
    int cursor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000380_8013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000380_8013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int cursor_95 = (aux + st.buffer[1]) & 3;
    switch (cursor_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_83 = local_arr[aux % 3];
    acc = (acc + weight_83 * 2) & 127;
    int quotient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000380_8013_13(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000380_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_71) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_91 = local_arr[aux % 3];
    acc = (acc + phase_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000380_8013_14(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000380_8013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_42 = local_arr[aux % 3];
    acc = (acc + cursor_42 * 2) & 127;
    int damping_48 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_48 > 22) {
        acc = (acc + damping_48 * 2 + 5) & 127;
        aux ^= (damping_48 & 15);
    } else {
        acc = (acc - damping_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000380_0;
    int sec_r000380_1;
    int sec_r000380_2;
    int sec_r000380_3;
    int sec_r000380_4;
    int sec_r000380_5;
    int sec_r000380_6;
    int sec_r000380_7;
    int sec_r000380_8;
    int sec_r000380_9;
    int sec_r000380_10;
    int sec_r000380_11;
    int sec_r000380_12;
    int sec_r000380_13;
    int sec_r000380_14;
    int sec_r000380_15;
    int sec_r000380_16;
    int sec_r000380_17;
    int pub_r000380_0;
    int pub_r000380_1;
    int pub_r000380_2;
    int pub_r000380_3;
    int pub_r000380_4;
    int pub_r000380_5;
    int pub_r000380_6;
    int pub_r000380_7;
    int pub_r000380_8;
    int pub_r000380_9;
    int pub_r000380_10;
    int pub_r000380_11;
    int pub_r000380_12;
    int pub_r000380_13;
    int pub_r000380_14;
    int pub_r000380_15;
    int pub_r000380_16;
    int pub_r000380_17;
    int pub_r000380_18;
    int pub_r000380_19;
    int pub_r000380_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000380_0 >= -100 && pub_r000380_0 <= 100);
    __CPROVER_assume(pub_r000380_1 >= -100 && pub_r000380_1 <= 100);
    __CPROVER_assume(pub_r000380_2 >= -100 && pub_r000380_2 <= 100);
    __CPROVER_assume(pub_r000380_3 >= -100 && pub_r000380_3 <= 100);
    __CPROVER_assume(pub_r000380_4 >= -100 && pub_r000380_4 <= 100);
    __CPROVER_assume(pub_r000380_5 >= -100 && pub_r000380_5 <= 100);
    __CPROVER_assume(pub_r000380_6 >= -100 && pub_r000380_6 <= 100);
    __CPROVER_assume(pub_r000380_7 >= -100 && pub_r000380_7 <= 100);
    __CPROVER_assume(pub_r000380_8 >= -100 && pub_r000380_8 <= 100);
    __CPROVER_assume(pub_r000380_9 >= -100 && pub_r000380_9 <= 100);
    __CPROVER_assume(pub_r000380_10 >= -100 && pub_r000380_10 <= 100);
    __CPROVER_assume(pub_r000380_11 >= -100 && pub_r000380_11 <= 100);
    __CPROVER_assume(pub_r000380_12 >= -100 && pub_r000380_12 <= 100);
    __CPROVER_assume(pub_r000380_13 >= -100 && pub_r000380_13 <= 100);
    __CPROVER_assume(pub_r000380_14 >= -100 && pub_r000380_14 <= 100);
    __CPROVER_assume(pub_r000380_15 >= -100 && pub_r000380_15 <= 100);
    __CPROVER_assume(pub_r000380_16 >= -100 && pub_r000380_16 <= 100);
    __CPROVER_assume(pub_r000380_17 >= -100 && pub_r000380_17 <= 100);
    __CPROVER_assume(pub_r000380_18 >= -100 && pub_r000380_18 <= 100);
    __CPROVER_assume(pub_r000380_19 >= -100 && pub_r000380_19 <= 100);
    __CPROVER_assume(pub_r000380_20 >= -100 && pub_r000380_20 <= 100);
    __CPROVER_assume(sec_r000380_0 >= 0 && sec_r000380_0 <= 255);
    __CPROVER_assume(sec_r000380_1 >= 0 && sec_r000380_1 <= 255);
    __CPROVER_assume(sec_r000380_2 >= 0 && sec_r000380_2 <= 255);
    __CPROVER_assume(sec_r000380_3 >= 0 && sec_r000380_3 <= 255);
    __CPROVER_assume(sec_r000380_4 >= 0 && sec_r000380_4 <= 255);
    __CPROVER_assume(sec_r000380_5 >= 0 && sec_r000380_5 <= 255);
    __CPROVER_assume(sec_r000380_6 >= 0 && sec_r000380_6 <= 255);
    __CPROVER_assume(sec_r000380_7 >= 0 && sec_r000380_7 <= 255);
    __CPROVER_assume(sec_r000380_8 >= 0 && sec_r000380_8 <= 255);
    __CPROVER_assume(sec_r000380_9 >= 0 && sec_r000380_9 <= 255);
    __CPROVER_assume(sec_r000380_10 >= 0 && sec_r000380_10 <= 255);
    __CPROVER_assume(sec_r000380_11 >= 0 && sec_r000380_11 <= 255);
    __CPROVER_assume(sec_r000380_12 >= 0 && sec_r000380_12 <= 255);
    __CPROVER_assume(sec_r000380_13 >= 0 && sec_r000380_13 <= 255);
    __CPROVER_assume(sec_r000380_14 >= 0 && sec_r000380_14 <= 255);
    __CPROVER_assume(sec_r000380_15 >= 0 && sec_r000380_15 <= 255);
    __CPROVER_assume(sec_r000380_16 >= 0 && sec_r000380_16 <= 255);
    __CPROVER_assume(sec_r000380_17 >= 0 && sec_r000380_17 <= 255);

    struct StreamBuffer_R000380_8013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000380_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000380_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000380_0 + 7) & 15;
    struct Vector3D_R000380_8013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000380_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000380_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000380_0 + 9) & 15;
    struct DeviceConfig_R000380_8013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000380_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000380_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000380_0 + 11) & 15;
    struct MatrixBlock_R000380_8013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000380_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000380_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000380_0 + 13) & 15;

    union ColorPixel_R000380_8013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r000380_11 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_8 > 21) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_8 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_9 > 44) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r000380_3 ^ 0x2A) + pub_r000380_2) & 127;
    if (stage_v_10 > 40) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_8 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_11 > 44) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_12 > 35) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_11 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_13 > 47) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r000380_16 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_12 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_15 > 21) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_13 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_16 > 32) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_17 > 35) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_16 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_18 > 44) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_15 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_19 > 50) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_17 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_20 > 35) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_13 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_21 > 33) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_13 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_22 > 29) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_13 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r000380_4 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_24 > 36) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_8 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_25 > 27) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_8 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_26 > 38) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_24 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_27 > 34) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_28 > 46) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_20 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_29 > 33) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_22 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_30 > 43) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r000380_8 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_31 > 37) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_32 > 21) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000380_10 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_33 > 37) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_14 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_34 > 32) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_12 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_35 > 26) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_11 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_36 > 35) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_12 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_37 > 27) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_11 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_38 > 34) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_29 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_39 > 41) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_33 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_40 > 20) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_9 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_41 > 31) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_37 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_42 > 29) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_26 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_43 > 47) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_31 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_45 > 39) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_39 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_46 > 32) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_37 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_47 > 21) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_43 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_48 > 47) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_16 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_49 > 29) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_50 > 41) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r000380_8 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_51 > 25) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r000380_14 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_52 > 38) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r000380_0 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_53 > 37) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_40 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_54 > 20) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_45 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_55 > 40) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_43 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_56 > 32) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_37 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_57 > 43) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_36 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_58 > 31) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_45 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_59 > 22) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r000380_2 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_60 > 22) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_39 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_61 > 44) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_28 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_63 > 41) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_64 > 22) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_31 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_65 > 24) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000380_10 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_66 > 42) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_47 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_67 > 27) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_8 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_68 > 26) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_31 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_69 > 45) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_18 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_70 > 46) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_24 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_71 > 31) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_40 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_72 > 23) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_27 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_73 > 45) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_33 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_74 > 48) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_61 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_75 > 21) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_58 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_76 > 42) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_25 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_77 > 46) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_70 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_78 > 24) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_8 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_79 > 32) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_80 > 36) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r000380_13 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_81 > 40) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000380_3 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_82 > 40) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_43 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_83 > 48) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000380_12 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000380_15 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_85 > 37) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r000380_11 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_86 > 50) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000380_7 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_87 > 44) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_31 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_88 > 42) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_89 > 47) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_90 > 23) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_51 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_91 > 30) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_50 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_92 > 42) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_73 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_93 > 28) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_86 ^ 0x2A) + pub_r000380_16) & 127;
    if (stage_v_94 > 27) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_27 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_95 > 33) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_49 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_96 > 23) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_83 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_97 > 39) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_98 > 28) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_54 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_99 > 43) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_91 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_100 > 39) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_36 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_101 > 31) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000380_11 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_102 > 40) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000380_0 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_103 > 31) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_89 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_104 > 43) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_47 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_105 > 44) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_43 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_106 > 42) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_8 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_107 > 50) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_79 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_108 > 31) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_45 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_109 > 29) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_110 > 22) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000380_2 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_111 > 28) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_29 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_112 > 44) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_91 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_113 > 31) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_65 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_114 > 42) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_88 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_115 > 28) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_92 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_116 > 46) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_20 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_117 > 28) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000380_12 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_118 > 50) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_58 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_119 > 26) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r000380_13 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_120 > 27) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000380_1 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_121 > 39) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_122 > 42) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_120 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_123 > 50) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_107 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_124 > 21) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_125 > 43) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000380_14 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_126 > 26) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_113 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_127 > 34) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_80 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_128 > 29) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_70 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_129 > 42) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000380_7 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_130 > 22) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_61 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_131 > 26) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_108 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_132 > 27) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_105 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_133 > 47) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_111 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_134 > 37) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000380_4 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_135 > 32) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_13 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_136 > 44) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_119 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_137 > 47) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_138 > 42) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_72 ^ 0x2A) + pub_r000380_2) & 127;
    if (stage_v_139 > 34) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_89 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_140 > 28) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_21 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_141 > 41) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_90 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_142 > 29) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_69 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_143 > 41) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_144 > 27) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_27 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_145 > 50) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_8 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_146 > 47) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_147 > 42) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_77 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_148 > 32) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_129 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_149 > 30) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_78 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_150 > 41) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_88 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_151 > 33) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_35 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_152 > 44) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_87 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_153 > 41) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000380_3 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_154 > 31) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r000380_15 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_155 > 27) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_49 ^ 0x2A) + pub_r000380_2) & 127;
    if (stage_v_156 > 26) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_73 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_157 > 34) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_155 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_158 > 30) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_15 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_159 > 43) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r000380_1 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_160 > 46) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_110 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_161 > 22) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_99 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_162 > 41) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r000380_16 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_163 > 20) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_102 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_164 > 30) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_45 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_165 > 31) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_65 ^ 0x2A) + pub_r000380_2) & 127;
    if (stage_v_166 > 48) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_78 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_84 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_169 > 44) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_170 > 29) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000380_14 ^ 0x2A) + pub_r000380_2) & 127;
    if (stage_v_171 > 46) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000380_10 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_172 > 23) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_43 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_173 > 39) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_159 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_174 > 48) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_156 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_175 > 45) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_174 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_176 > 23) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000380_16 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_177 > 48) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_133 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_178 > 33) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_20 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_179 > 29) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_41 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_180 > 33) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_101 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_181 > 20) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000380_0 ^ 0x2A) + pub_r000380_14) & 127;
    if (stage_v_182 > 38) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000380_17 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_183 > 21) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_118 ^ 0x2A) + pub_r000380_17) & 127;
    if (stage_v_184 > 31) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r000380_16 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_185 > 20) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_172 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_186 > 29) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000380_7 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_187 > 33) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_93 ^ 0x2A) + pub_r000380_12) & 127;
    if (stage_v_188 > 48) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_189 > 26) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_36 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_190 > 24) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_37 ^ 0x2A) + pub_r000380_11) & 127;
    if (stage_v_191 > 24) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000380_5 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_192 > 20) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000380_6 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_193 > 45) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000380_8 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_194 > 39) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_168 ^ 0x2A) + pub_r000380_5) & 127;
    if (stage_v_195 > 33) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_183 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_196 > 49) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_29 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_197 > 48) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000380_14 ^ 0x2A) + pub_r000380_8) & 127;
    if (stage_v_198 > 49) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_93 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_199 > 31) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_15 ^ 0x2A) + pub_r000380_18) & 127;
    if (stage_v_200 > 48) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_165 ^ 0x2A) + pub_r000380_15) & 127;
    if (stage_v_201 > 31) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_167 ^ 0x2A) + pub_r000380_7) & 127;
    if (stage_v_202 > 49) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_182 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_203 > 46) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_49 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_204 > 27) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_157 ^ 0x2A) + pub_r000380_6) & 127;
    if (stage_v_205 > 35) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_164 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_206 > 22) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_99 ^ 0x2A) + pub_r000380_10) & 127;
    if (stage_v_207 > 37) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_155 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_208 > 35) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_108 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_209 > 29) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r000380_12 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_210 > 25) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_117 ^ 0x2A) + pub_r000380_13) & 127;
    if (stage_v_211 > 20) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_59 ^ 0x2A) + pub_r000380_3) & 127;
    if (stage_v_212 > 22) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r000380_9 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_213 > 43) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((sec_r000380_11 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_214 > 43) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000380_4 ^ 0x2A) + pub_r000380_9) & 127;
    if (stage_v_215 > 40) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_196 ^ 0x2A) + pub_r000380_19) & 127;
    if (stage_v_216 > 29) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_27 ^ 0x2A) + pub_r000380_1) & 127;
    if (stage_v_217 > 36) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_134 ^ 0x2A) + pub_r000380_20) & 127;
    if (stage_v_218 > 21) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r000380_14 ^ 0x2A) + pub_r000380_0) & 127;
    if (stage_v_219 > 40) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r000380_10 ^ 0x2A) + pub_r000380_4) & 127;
    if (stage_v_220 > 36) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
