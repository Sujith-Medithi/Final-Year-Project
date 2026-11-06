/*
 * Benchmark Program: R000647
 * Security Family: nested_implicit_flow
 * Generator Seed: 564713
 * High Inputs: 22 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000647_4713_0 {
    unsigned char dim;
    int trace;
    unsigned char determinant;
    int scale;
    int stride;
    unsigned char density;
    int buffer[3];
};

struct StreamBuffer_R000647_4713_1 {
    short head;
    int watermark;
    unsigned char state;
    short checksum;
    int buffer[3];
};

struct SensorNode_R000647_4713_2 {
    short reading;
    int status;
    short threshold;
    int calib;
    int buffer[3];
};

struct FilterState_R000647_4713_3 {
    int cutoff;
    int prev_out;
    unsigned char damping;
    unsigned char gain_db;
    int mode;
    short prev_in;
    int buffer[3];
};

union PacketPayload_R000647_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000647_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000647_4713_0(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_97 > 21) {
        acc = (acc + quotient_97 * 2 + 5) & 127;
        aux ^= (quotient_97 & 15);
    } else {
        acc = (acc - quotient_97 + 11) & 127;
        aux += 3;
    }
    int segment_61 = (aux + st.buffer[1]) & 3;
    switch (segment_61) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_51) & 63;
    acc ^= aux;
    int sample_14 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_14 > 49) {
        acc = (acc + sample_14 * 2 + 5) & 127;
        aux ^= (sample_14 & 15);
    } else {
        acc = (acc - sample_14 + 11) & 127;
        aux += 3;
    }
    int vector_48 = (aux + st.buffer[1]) & 3;
    switch (vector_48) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_73 = local_arr[aux % 3];
    acc = (acc + sample_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000647_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tracker_59 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_59 > 35) {
        acc = (acc + tracker_59 * 2 + 5) & 127;
        aux ^= (tracker_59 & 15);
    } else {
        acc = (acc - tracker_59 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_73 = local_arr[aux % 3];
    acc = (acc + weight_73 * 2) & 127;
    int residue_51 = (aux + st.buffer[1]) & 3;
    switch (residue_51) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000647_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int sample_62 = (aux + st.buffer[1]) & 3;
    switch (sample_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_77 = local_arr[aux % 3];
    acc = (acc + cursor_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_4(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000647_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_49 = local_arr[aux % 3];
    acc = (acc + checksum_49 * 2) & 127;
    int stride_37 = (aux + st.buffer[1]) & 3;
    switch (stride_37) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_90 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_90 > 29) {
        acc = (acc + threshold_90 * 2 + 5) & 127;
        aux ^= (threshold_90 & 15);
    } else {
        acc = (acc - threshold_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000647_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_73) & 63;
    acc ^= aux;
    int delta_46 = (aux + st.buffer[1]) & 3;
    switch (delta_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int tally_17 = local_arr[aux % 3];
    acc = (acc + tally_17 * 2) & 127;
    int coefficient_12 = (aux + st.buffer[1]) & 3;
    switch (coefficient_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_14) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_7(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000647_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_74) & 63;
    acc ^= aux;
    int sample_60 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_60 > 25) {
        acc = (acc + sample_60 * 2 + 5) & 127;
        aux ^= (sample_60 & 15);
    } else {
        acc = (acc - sample_60 + 11) & 127;
        aux += 3;
    }
    int weight_16 = (aux + st.buffer[1]) & 3;
    switch (weight_16) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_8(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000647_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_19 = local_arr[aux % 3];
    acc = (acc + checksum_19 * 2) & 127;
    int tracker_84 = (aux + st.buffer[1]) & 3;
    switch (tracker_84) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000647_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000647_4713_10(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_64 = (aux + st.buffer[1]) & 3;
    switch (accumulator_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_11(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000647_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_99 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_99 > 10) {
        acc = (acc + weight_99 * 2 + 5) & 127;
        aux ^= (weight_99 & 15);
    } else {
        acc = (acc - weight_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_88 = local_arr[aux % 3];
    acc = (acc + margin_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000647_4713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_25 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_25 > 23) {
        acc = (acc + offset_25 * 2 + 5) & 127;
        aux ^= (offset_25 & 15);
    } else {
        acc = (acc - offset_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_13(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int index_reg_16 = local_arr[aux % 3];
    acc = (acc + index_reg_16 * 2) & 127;
    int tracker_35 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_35 > 10) {
        acc = (acc + tracker_35 * 2 + 5) & 127;
        aux ^= (tracker_35 & 15);
    } else {
        acc = (acc - tracker_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_14(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000647_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_42 = (aux + st.buffer[1]) & 3;
    switch (phase_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_74 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_74 > 19) {
        acc = (acc + pivot_74 * 2 + 5) & 127;
        aux ^= (pivot_74 & 15);
    } else {
        acc = (acc - pivot_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_15(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000647_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int stride_41 = local_arr[aux % 3];
    acc = (acc + stride_41 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000647_4713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000647_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_61 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_61 > 31) {
        acc = (acc + scale_61 * 2 + 5) & 127;
        aux ^= (scale_61 & 15);
    } else {
        acc = (acc - scale_61 + 11) & 127;
        aux += 3;
    }
    int weight_80 = (aux + st.buffer[1]) & 3;
    switch (weight_80) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_63 = (aux + st.buffer[1]) & 3;
    switch (checksum_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000647_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int accumulator_56 = local_arr[aux % 3];
    acc = (acc + accumulator_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_64 = (aux + st.buffer[1]) & 3;
    switch (coefficient_64) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_97 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_97 > 22) {
        acc = (acc + bound_97 * 2 + 5) & 127;
        aux ^= (bound_97 & 15);
    } else {
        acc = (acc - bound_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000647_4713_19(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000647_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tally_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_23) & 63;
    acc ^= aux;
    int tracker_64 = (aux + st.buffer[1]) & 3;
    switch (tracker_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_27 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_27 > 19) {
        acc = (acc + cursor_27 * 2 + 5) & 127;
        aux ^= (cursor_27 & 15);
    } else {
        acc = (acc - cursor_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000647_0;
    int sec_r000647_1;
    int sec_r000647_2;
    int sec_r000647_3;
    int sec_r000647_4;
    int sec_r000647_5;
    int sec_r000647_6;
    int sec_r000647_7;
    int sec_r000647_8;
    int sec_r000647_9;
    int sec_r000647_10;
    int sec_r000647_11;
    int sec_r000647_12;
    int sec_r000647_13;
    int sec_r000647_14;
    int sec_r000647_15;
    int sec_r000647_16;
    int sec_r000647_17;
    int sec_r000647_18;
    int sec_r000647_19;
    int sec_r000647_20;
    int sec_r000647_21;
    int pub_r000647_0;
    int pub_r000647_1;
    int pub_r000647_2;
    int pub_r000647_3;
    int pub_r000647_4;
    int pub_r000647_5;
    int pub_r000647_6;
    int pub_r000647_7;
    int pub_r000647_8;
    int pub_r000647_9;
    int pub_r000647_10;
    int pub_r000647_11;
    int pub_r000647_12;
    int pub_r000647_13;
    int pub_r000647_14;
    int pub_r000647_15;
    int pub_r000647_16;
    int pub_r000647_17;
    int pub_r000647_18;
    int pub_r000647_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000647_0 >= -100 && pub_r000647_0 <= 100);
    __CPROVER_assume(pub_r000647_1 >= -100 && pub_r000647_1 <= 100);
    __CPROVER_assume(pub_r000647_2 >= -100 && pub_r000647_2 <= 100);
    __CPROVER_assume(pub_r000647_3 >= -100 && pub_r000647_3 <= 100);
    __CPROVER_assume(pub_r000647_4 >= -100 && pub_r000647_4 <= 100);
    __CPROVER_assume(pub_r000647_5 >= -100 && pub_r000647_5 <= 100);
    __CPROVER_assume(pub_r000647_6 >= -100 && pub_r000647_6 <= 100);
    __CPROVER_assume(pub_r000647_7 >= -100 && pub_r000647_7 <= 100);
    __CPROVER_assume(pub_r000647_8 >= -100 && pub_r000647_8 <= 100);
    __CPROVER_assume(pub_r000647_9 >= -100 && pub_r000647_9 <= 100);
    __CPROVER_assume(pub_r000647_10 >= -100 && pub_r000647_10 <= 100);
    __CPROVER_assume(pub_r000647_11 >= -100 && pub_r000647_11 <= 100);
    __CPROVER_assume(pub_r000647_12 >= -100 && pub_r000647_12 <= 100);
    __CPROVER_assume(pub_r000647_13 >= -100 && pub_r000647_13 <= 100);
    __CPROVER_assume(pub_r000647_14 >= -100 && pub_r000647_14 <= 100);
    __CPROVER_assume(pub_r000647_15 >= -100 && pub_r000647_15 <= 100);
    __CPROVER_assume(pub_r000647_16 >= -100 && pub_r000647_16 <= 100);
    __CPROVER_assume(pub_r000647_17 >= -100 && pub_r000647_17 <= 100);
    __CPROVER_assume(pub_r000647_18 >= -100 && pub_r000647_18 <= 100);
    __CPROVER_assume(pub_r000647_19 >= -100 && pub_r000647_19 <= 100);
    __CPROVER_assume(sec_r000647_0 >= 0 && sec_r000647_0 <= 255);
    __CPROVER_assume(sec_r000647_1 >= 0 && sec_r000647_1 <= 255);
    __CPROVER_assume(sec_r000647_2 >= 0 && sec_r000647_2 <= 255);
    __CPROVER_assume(sec_r000647_3 >= 0 && sec_r000647_3 <= 255);
    __CPROVER_assume(sec_r000647_4 >= 0 && sec_r000647_4 <= 255);
    __CPROVER_assume(sec_r000647_5 >= 0 && sec_r000647_5 <= 255);
    __CPROVER_assume(sec_r000647_6 >= 0 && sec_r000647_6 <= 255);
    __CPROVER_assume(sec_r000647_7 >= 0 && sec_r000647_7 <= 255);
    __CPROVER_assume(sec_r000647_8 >= 0 && sec_r000647_8 <= 255);
    __CPROVER_assume(sec_r000647_9 >= 0 && sec_r000647_9 <= 255);
    __CPROVER_assume(sec_r000647_10 >= 0 && sec_r000647_10 <= 255);
    __CPROVER_assume(sec_r000647_11 >= 0 && sec_r000647_11 <= 255);
    __CPROVER_assume(sec_r000647_12 >= 0 && sec_r000647_12 <= 255);
    __CPROVER_assume(sec_r000647_13 >= 0 && sec_r000647_13 <= 255);
    __CPROVER_assume(sec_r000647_14 >= 0 && sec_r000647_14 <= 255);
    __CPROVER_assume(sec_r000647_15 >= 0 && sec_r000647_15 <= 255);
    __CPROVER_assume(sec_r000647_16 >= 0 && sec_r000647_16 <= 255);
    __CPROVER_assume(sec_r000647_17 >= 0 && sec_r000647_17 <= 255);
    __CPROVER_assume(sec_r000647_18 >= 0 && sec_r000647_18 <= 255);
    __CPROVER_assume(sec_r000647_19 >= 0 && sec_r000647_19 <= 255);
    __CPROVER_assume(sec_r000647_20 >= 0 && sec_r000647_20 <= 255);
    __CPROVER_assume(sec_r000647_21 >= 0 && sec_r000647_21 <= 255);

    struct MatrixBlock_R000647_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000647_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000647_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000647_0 + 7) & 15;
    struct StreamBuffer_R000647_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000647_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000647_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000647_0 + 9) & 15;
    struct SensorNode_R000647_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000647_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000647_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000647_0 + 11) & 15;
    struct FilterState_R000647_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000647_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000647_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000647_0 + 13) & 15;

    union PacketPayload_R000647_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
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
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

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
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 11) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 26) {
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
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 10) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 25) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 28) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 43) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 37) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 52) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 17) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 32) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 15) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 30) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 14) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 29) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 11) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 26) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 32) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 47) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 20) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 35) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000647_10 & 1) != 0) {
        if ((sec_r000647_11 & 2) != 0) {
            stage_v_74 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000647_2 & 2) != 0) {
            stage_v_75 = (pub_r000647_19 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000647_19 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000647_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000647_0 & 1) != 0) {
        if ((sec_r000647_17 & 2) != 0) {
            stage_v_76 = (pub_r000647_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000647_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000647_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000647_9 & 2) != 0) {
            stage_v_77 = (pub_r000647_17 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000647_17 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000647_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_78 = (pub_r000647_16 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000647_16 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000647_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000647_9 & 1) != 0) {
        if ((sec_r000647_21 & 2) != 0) {
            stage_v_79 = (pub_r000647_11 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000647_11 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000647_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_80 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000647_7 & 2) != 0) {
            stage_v_81 = (pub_r000647_17 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000647_17 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000647_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_82 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000647_4 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_83 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000647_14 & 2) != 0) {
            stage_v_84 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000647_5 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_85 = (pub_r000647_15 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000647_15 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000647_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000647_15 & 1) != 0) {
        if ((sec_r000647_0 & 2) != 0) {
            stage_v_86 = (pub_r000647_12 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000647_12 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000647_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000647_10 & 2) != 0) {
            stage_v_87 = (pub_r000647_16 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000647_16 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000647_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000647_7 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_88 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000647_7 & 2) != 0) {
            stage_v_89 = (pub_r000647_16 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000647_16 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000647_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000647_5 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_90 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000647_9 & 2) != 0) {
            stage_v_91 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_92 = (pub_r000647_10 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000647_10 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000647_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000647_17 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_93 = (pub_r000647_11 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000647_11 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000647_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000647_9 & 1) != 0) {
        if ((sec_r000647_2 & 2) != 0) {
            stage_v_94 = (pub_r000647_6 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000647_6 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000647_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_95 = (pub_r000647_2 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000647_2 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000647_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000647_2 & 2) != 0) {
            stage_v_96 = (pub_r000647_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000647_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000647_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000647_5 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_97 = (pub_r000647_3 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000647_3 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000647_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000647_10 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_98 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000647_0 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_99 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000647_6 & 2) != 0) {
            stage_v_100 = (pub_r000647_8 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000647_8 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000647_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000647_3 & 2) != 0) {
            stage_v_101 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000647_1 & 1) != 0) {
        if ((sec_r000647_12 & 2) != 0) {
            stage_v_102 = (pub_r000647_19 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000647_19 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000647_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000647_4 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_103 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_104 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_105 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000647_21 & 2) != 0) {
            stage_v_106 = (pub_r000647_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000647_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000647_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000647_14 & 2) != 0) {
            stage_v_107 = (pub_r000647_6 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000647_6 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000647_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000647_20 & 1) != 0) {
        if ((sec_r000647_8 & 2) != 0) {
            stage_v_108 = (pub_r000647_3 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000647_3 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000647_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_109 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000647_3 & 2) != 0) {
            stage_v_110 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000647_19 & 2) != 0) {
            stage_v_111 = (pub_r000647_11 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000647_11 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000647_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_112 = (pub_r000647_6 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000647_6 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000647_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000647_18 & 1) != 0) {
        if ((sec_r000647_17 & 2) != 0) {
            stage_v_113 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000647_11 & 2) != 0) {
            stage_v_114 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000647_11 & 1) != 0) {
        if ((sec_r000647_21 & 2) != 0) {
            stage_v_115 = (pub_r000647_15 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000647_15 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000647_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_116 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000647_19 & 1) != 0) {
        if ((sec_r000647_2 & 2) != 0) {
            stage_v_117 = (pub_r000647_8 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000647_8 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000647_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000647_7 & 2) != 0) {
            stage_v_118 = (pub_r000647_15 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000647_15 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000647_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_119 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_120 = (pub_r000647_3 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000647_3 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000647_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000647_6 & 2) != 0) {
            stage_v_121 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000647_0 & 2) != 0) {
            stage_v_122 = (pub_r000647_6 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000647_6 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000647_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000647_0 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_123 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000647_10 & 2) != 0) {
            stage_v_124 = (pub_r000647_6 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000647_6 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000647_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000647_21 & 1) != 0) {
        if ((sec_r000647_17 & 2) != 0) {
            stage_v_125 = (pub_r000647_19 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000647_19 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000647_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_126 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000647_10 & 2) != 0) {
            stage_v_127 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000647_11 & 2) != 0) {
            stage_v_128 = (pub_r000647_13 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000647_13 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000647_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000647_10 & 2) != 0) {
            stage_v_129 = (pub_r000647_12 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000647_12 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000647_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000647_10 & 1) != 0) {
        if ((sec_r000647_13 & 2) != 0) {
            stage_v_130 = (pub_r000647_8 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000647_8 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000647_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000647_20 & 1) != 0) {
        if ((sec_r000647_12 & 2) != 0) {
            stage_v_131 = (pub_r000647_10 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000647_10 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000647_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000647_0 & 2) != 0) {
            stage_v_132 = (pub_r000647_19 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000647_19 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000647_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000647_4 & 2) != 0) {
            stage_v_133 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000647_12 & 2) != 0) {
            stage_v_134 = (pub_r000647_2 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000647_2 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000647_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000647_13 & 2) != 0) {
            stage_v_135 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_136 = (pub_r000647_11 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000647_11 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000647_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000647_21 & 1) != 0) {
        if ((sec_r000647_9 & 2) != 0) {
            stage_v_137 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000647_19 & 2) != 0) {
            stage_v_138 = (pub_r000647_15 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000647_15 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000647_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000647_11 & 2) != 0) {
            stage_v_139 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000647_12 & 1) != 0) {
        if ((sec_r000647_12 & 2) != 0) {
            stage_v_140 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000647_10 & 1) != 0) {
        if ((sec_r000647_3 & 2) != 0) {
            stage_v_141 = (pub_r000647_18 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000647_18 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000647_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000647_0 & 2) != 0) {
            stage_v_142 = (pub_r000647_16 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000647_16 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000647_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_143 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000647_13 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_144 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000647_17 & 1) != 0) {
        if ((sec_r000647_18 & 2) != 0) {
            stage_v_145 = (pub_r000647_14 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000647_14 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000647_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000647_10 & 1) != 0) {
        if ((sec_r000647_18 & 2) != 0) {
            stage_v_146 = (pub_r000647_10 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000647_10 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000647_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000647_3 & 2) != 0) {
            stage_v_147 = (pub_r000647_5 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000647_5 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000647_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000647_20 & 2) != 0) {
            stage_v_148 = (pub_r000647_4 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000647_4 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000647_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000647_11 & 1) != 0) {
        if ((sec_r000647_1 & 2) != 0) {
            stage_v_149 = (pub_r000647_17 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000647_17 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000647_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000647_18 & 1) != 0) {
        if ((sec_r000647_15 & 2) != 0) {
            stage_v_150 = (pub_r000647_8 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000647_8 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000647_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_151 = (pub_r000647_9 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000647_9 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000647_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000647_1 & 2) != 0) {
            stage_v_152 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000647_18 & 2) != 0) {
            stage_v_153 = (pub_r000647_8 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000647_8 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000647_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000647_17 & 2) != 0) {
            stage_v_154 = (pub_r000647_14 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000647_14 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000647_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000647_14 & 2) != 0) {
            stage_v_155 = (pub_r000647_1 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000647_1 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000647_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000647_20 & 1) != 0) {
        if ((sec_r000647_20 & 2) != 0) {
            stage_v_156 = (pub_r000647_10 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000647_10 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000647_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000647_16 & 2) != 0) {
            stage_v_157 = (pub_r000647_1 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000647_1 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000647_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000647_13 & 2) != 0) {
            stage_v_158 = (pub_r000647_12 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000647_12 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000647_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000647_6 & 1) != 0) {
        if ((sec_r000647_5 & 2) != 0) {
            stage_v_159 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000647_11 & 1) != 0) {
        if ((sec_r000647_21 & 2) != 0) {
            stage_v_160 = (pub_r000647_1 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000647_1 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000647_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000647_1 & 2) != 0) {
            stage_v_161 = (pub_r000647_11 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000647_11 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000647_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000647_4 & 1) != 0) {
        if ((sec_r000647_14 & 2) != 0) {
            stage_v_162 = (pub_r000647_15 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000647_15 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000647_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000647_14 & 2) != 0) {
            stage_v_163 = (pub_r000647_3 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000647_3 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000647_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000647_18 & 2) != 0) {
            stage_v_164 = (pub_r000647_0 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000647_0 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000647_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000647_1 & 2) != 0) {
            stage_v_165 = (pub_r000647_7 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000647_7 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000647_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r000647_12 & 2) != 0) {
            stage_v_166 = (pub_r000647_1 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000647_1 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000647_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
