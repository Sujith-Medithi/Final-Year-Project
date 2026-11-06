/*
 * Benchmark Program: R000047
 * Security Family: nested_implicit_flow
 * Generator Seed: 504713
 * High Inputs: 23 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000047_4713_0 {
    unsigned char coord_z;
    int norm_sq;
    unsigned char pitch;
    unsigned char coord_y;
    int heading;
    short coord_x;
    int buffer[3];
};

struct AudioFrame_R000047_4713_1 {
    short gain;
    short rms;
    int peak;
    int buffer[3];
};

struct StreamBuffer_R000047_4713_2 {
    unsigned char state;
    int head;
    int capacity;
    int checksum;
    int buffer[3];
};

struct SensorNode_R000047_4713_3 {
    int reading;
    short offset;
    int threshold;
    int calib;
    short gain;
    int buffer[3];
};

union RegisterBank_R000047_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000047_4713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int vector_33 = local_arr[aux % 3];
    acc = (acc + vector_33 * 2) & 127;
    int tracker_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_1(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_65) & 63;
    acc ^= aux;
    int margin_30 = (aux + st.buffer[1]) & 3;
    switch (margin_30) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000047_4713_2(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_64) & 63;
    acc ^= aux;
    int quantum_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_87 > 24) {
        acc = (acc + quantum_87 * 2 + 5) & 127;
        aux ^= (quantum_87 & 15);
    } else {
        acc = (acc - quantum_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000047_4713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_58 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_58 > 17) {
        acc = (acc + tally_58 * 2 + 5) & 127;
        aux ^= (tally_58 & 15);
    } else {
        acc = (acc - tally_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_42 = (aux + st.buffer[1]) & 3;
    switch (anchor_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_43 = local_arr[aux % 3];
    acc = (acc + segment_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int factor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_59 > 10) {
        acc = (acc + factor_59 * 2 + 5) & 127;
        aux ^= (factor_59 & 15);
    } else {
        acc = (acc - factor_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_56 = local_arr[aux % 3];
    acc = (acc + phase_56 * 2) & 127;
    int margin_83 = (aux + st.buffer[1]) & 3;
    switch (margin_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_5(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_51 = (st.buffer[0] * 3 + aux) & 63;
    if (window_51 > 29) {
        acc = (acc + window_51 * 2 + 5) & 127;
        aux ^= (window_51 & 15);
    } else {
        acc = (acc - window_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_96 = local_arr[aux % 3];
    acc = (acc + sample_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_6(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000047_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_59 = local_arr[aux % 3];
    acc = (acc + quotient_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_7(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_62 = (aux + st.buffer[1]) & 3;
    switch (mask_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_58 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_58 > 38) {
        acc = (acc + accumulator_58 * 2 + 5) & 127;
        aux ^= (accumulator_58 & 15);
    } else {
        acc = (acc - accumulator_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000047_4713_8(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000047_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_26 = (aux + st.buffer[1]) & 3;
    switch (index_reg_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_9(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_34 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_34 > 18) {
        acc = (acc + tracker_34 * 2 + 5) & 127;
        aux ^= (tracker_34 & 15);
    } else {
        acc = (acc - tracker_34 + 11) & 127;
        aux += 3;
    }
    int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_87 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_87 > 29) {
        acc = (acc + offset_87 * 2 + 5) & 127;
        aux ^= (offset_87 & 15);
    } else {
        acc = (acc - offset_87 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_17 = local_arr[aux % 3];
    acc = (acc + parity_17 * 2) & 127;
    int damping_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor_12 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_12 > 48) {
        acc = (acc + cursor_12 * 2 + 5) & 127;
        aux ^= (cursor_12 & 15);
    } else {
        acc = (acc - cursor_12 + 11) & 127;
        aux += 3;
    }
    int mask_98 = (aux + st.buffer[1]) & 3;
    switch (mask_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000047_4713_12(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_41 = (st.buffer[0] * 3 + aux) & 63;
    if (window_41 > 16) {
        acc = (acc + window_41 * 2 + 5) & 127;
        aux ^= (window_41 & 15);
    } else {
        acc = (acc - window_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_22 = local_arr[aux % 3];
    acc = (acc + damping_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_13(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000047_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_63) & 63;
    acc ^= aux;
    int pivot_55 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_55 > 40) {
        acc = (acc + pivot_55 * 2 + 5) & 127;
        aux ^= (pivot_55 & 15);
    } else {
        acc = (acc - pivot_55 + 11) & 127;
        aux += 3;
    }
    int parity_74 = (aux + st.buffer[1]) & 3;
    switch (parity_74) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000047_4713_14(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int stride_39 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_39 > 35) {
        acc = (acc + stride_39 * 2 + 5) & 127;
        aux ^= (stride_39 & 15);
    } else {
        acc = (acc - stride_39 + 11) & 127;
        aux += 3;
    }
    int factor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000047_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_12 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_12 > 48) {
        acc = (acc + quotient_12 * 2 + 5) & 127;
        aux ^= (quotient_12 & 15);
    } else {
        acc = (acc - quotient_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_27 = local_arr[aux % 3];
    acc = (acc + weight_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000047_4713_16(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000047_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int window_82 = local_arr[aux % 3];
    acc = (acc + window_82 * 2) & 127;
    int index_reg_65 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_65 > 18) {
        acc = (acc + index_reg_65 * 2 + 5) & 127;
        aux ^= (index_reg_65 & 15);
    } else {
        acc = (acc - index_reg_65 + 11) & 127;
        aux += 3;
    }
    int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000047_4713_17(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000047_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int stride_14 = local_arr[aux % 3];
    acc = (acc + stride_14 * 2) & 127;
    int vector_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_73) & 63;
    acc ^= aux;
    int metric_66 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_66 > 31) {
        acc = (acc + metric_66 * 2 + 5) & 127;
        aux ^= (metric_66 & 15);
    } else {
        acc = (acc - metric_66 + 11) & 127;
        aux += 3;
    }
    int quantum_40 = (aux + st.buffer[1]) & 3;
    switch (quantum_40) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000047_0;
    int sec_r000047_1;
    int sec_r000047_2;
    int sec_r000047_3;
    int sec_r000047_4;
    int sec_r000047_5;
    int sec_r000047_6;
    int sec_r000047_7;
    int sec_r000047_8;
    int sec_r000047_9;
    int sec_r000047_10;
    int sec_r000047_11;
    int sec_r000047_12;
    int sec_r000047_13;
    int sec_r000047_14;
    int sec_r000047_15;
    int sec_r000047_16;
    int sec_r000047_17;
    int sec_r000047_18;
    int sec_r000047_19;
    int sec_r000047_20;
    int sec_r000047_21;
    int sec_r000047_22;
    int pub_r000047_0;
    int pub_r000047_1;
    int pub_r000047_2;
    int pub_r000047_3;
    int pub_r000047_4;
    int pub_r000047_5;
    int pub_r000047_6;
    int pub_r000047_7;
    int pub_r000047_8;
    int pub_r000047_9;
    int pub_r000047_10;
    int pub_r000047_11;
    int pub_r000047_12;
    int pub_r000047_13;
    int pub_r000047_14;
    int pub_r000047_15;
    int pub_r000047_16;
    int pub_r000047_17;
    int pub_r000047_18;
    int pub_r000047_19;
    int pub_r000047_20;
    int pub_r000047_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000047_0 >= -100 && pub_r000047_0 <= 100);
    __CPROVER_assume(pub_r000047_1 >= -100 && pub_r000047_1 <= 100);
    __CPROVER_assume(pub_r000047_2 >= -100 && pub_r000047_2 <= 100);
    __CPROVER_assume(pub_r000047_3 >= -100 && pub_r000047_3 <= 100);
    __CPROVER_assume(pub_r000047_4 >= -100 && pub_r000047_4 <= 100);
    __CPROVER_assume(pub_r000047_5 >= -100 && pub_r000047_5 <= 100);
    __CPROVER_assume(pub_r000047_6 >= -100 && pub_r000047_6 <= 100);
    __CPROVER_assume(pub_r000047_7 >= -100 && pub_r000047_7 <= 100);
    __CPROVER_assume(pub_r000047_8 >= -100 && pub_r000047_8 <= 100);
    __CPROVER_assume(pub_r000047_9 >= -100 && pub_r000047_9 <= 100);
    __CPROVER_assume(pub_r000047_10 >= -100 && pub_r000047_10 <= 100);
    __CPROVER_assume(pub_r000047_11 >= -100 && pub_r000047_11 <= 100);
    __CPROVER_assume(pub_r000047_12 >= -100 && pub_r000047_12 <= 100);
    __CPROVER_assume(pub_r000047_13 >= -100 && pub_r000047_13 <= 100);
    __CPROVER_assume(pub_r000047_14 >= -100 && pub_r000047_14 <= 100);
    __CPROVER_assume(pub_r000047_15 >= -100 && pub_r000047_15 <= 100);
    __CPROVER_assume(pub_r000047_16 >= -100 && pub_r000047_16 <= 100);
    __CPROVER_assume(pub_r000047_17 >= -100 && pub_r000047_17 <= 100);
    __CPROVER_assume(pub_r000047_18 >= -100 && pub_r000047_18 <= 100);
    __CPROVER_assume(pub_r000047_19 >= -100 && pub_r000047_19 <= 100);
    __CPROVER_assume(pub_r000047_20 >= -100 && pub_r000047_20 <= 100);
    __CPROVER_assume(pub_r000047_21 >= -100 && pub_r000047_21 <= 100);
    __CPROVER_assume(sec_r000047_0 >= 0 && sec_r000047_0 <= 255);
    __CPROVER_assume(sec_r000047_1 >= 0 && sec_r000047_1 <= 255);
    __CPROVER_assume(sec_r000047_2 >= 0 && sec_r000047_2 <= 255);
    __CPROVER_assume(sec_r000047_3 >= 0 && sec_r000047_3 <= 255);
    __CPROVER_assume(sec_r000047_4 >= 0 && sec_r000047_4 <= 255);
    __CPROVER_assume(sec_r000047_5 >= 0 && sec_r000047_5 <= 255);
    __CPROVER_assume(sec_r000047_6 >= 0 && sec_r000047_6 <= 255);
    __CPROVER_assume(sec_r000047_7 >= 0 && sec_r000047_7 <= 255);
    __CPROVER_assume(sec_r000047_8 >= 0 && sec_r000047_8 <= 255);
    __CPROVER_assume(sec_r000047_9 >= 0 && sec_r000047_9 <= 255);
    __CPROVER_assume(sec_r000047_10 >= 0 && sec_r000047_10 <= 255);
    __CPROVER_assume(sec_r000047_11 >= 0 && sec_r000047_11 <= 255);
    __CPROVER_assume(sec_r000047_12 >= 0 && sec_r000047_12 <= 255);
    __CPROVER_assume(sec_r000047_13 >= 0 && sec_r000047_13 <= 255);
    __CPROVER_assume(sec_r000047_14 >= 0 && sec_r000047_14 <= 255);
    __CPROVER_assume(sec_r000047_15 >= 0 && sec_r000047_15 <= 255);
    __CPROVER_assume(sec_r000047_16 >= 0 && sec_r000047_16 <= 255);
    __CPROVER_assume(sec_r000047_17 >= 0 && sec_r000047_17 <= 255);
    __CPROVER_assume(sec_r000047_18 >= 0 && sec_r000047_18 <= 255);
    __CPROVER_assume(sec_r000047_19 >= 0 && sec_r000047_19 <= 255);
    __CPROVER_assume(sec_r000047_20 >= 0 && sec_r000047_20 <= 255);
    __CPROVER_assume(sec_r000047_21 >= 0 && sec_r000047_21 <= 255);
    __CPROVER_assume(sec_r000047_22 >= 0 && sec_r000047_22 <= 255);

    struct Vector3D_R000047_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000047_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000047_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000047_0 + 7) & 15;
    struct AudioFrame_R000047_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000047_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000047_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000047_0 + 9) & 15;
    struct StreamBuffer_R000047_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000047_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000047_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000047_0 + 11) & 15;
    struct SensorNode_R000047_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000047_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000047_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000047_0 + 13) & 15;

    union RegisterBank_R000047_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 15) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 30) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 28) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 43) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 36) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 51) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 51) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 15) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 30) {
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
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 32) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 47) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 33) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 48) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
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
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 24) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 39) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 14) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 29) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 40) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 55) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000047_15 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_53 = (pub_r000047_11 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000047_11 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000047_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000047_5 & 1) != 0) {
        if ((sec_r000047_19 & 2) != 0) {
            stage_v_54 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000047_19 & 2) != 0) {
            stage_v_55 = (pub_r000047_12 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000047_12 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000047_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000047_13 & 2) != 0) {
            stage_v_56 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000047_0 & 2) != 0) {
            stage_v_57 = (pub_r000047_8 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000047_8 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000047_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_58 = (pub_r000047_12 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000047_12 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000047_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000047_7 & 2) != 0) {
            stage_v_59 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_60 = (pub_r000047_7 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000047_7 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000047_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000047_11 & 2) != 0) {
            stage_v_61 = (pub_r000047_18 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000047_18 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000047_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000047_3 & 2) != 0) {
            stage_v_62 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000047_13 & 2) != 0) {
            stage_v_63 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000047_6 & 1) != 0) {
        if ((sec_r000047_8 & 2) != 0) {
            stage_v_64 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000047_1 & 2) != 0) {
            stage_v_65 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000047_17 & 1) != 0) {
        if ((sec_r000047_21 & 2) != 0) {
            stage_v_66 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_67 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000047_3 & 1) != 0) {
        if ((sec_r000047_4 & 2) != 0) {
            stage_v_68 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000047_12 & 1) != 0) {
        if ((sec_r000047_18 & 2) != 0) {
            stage_v_69 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000047_4 & 1) != 0) {
        if ((sec_r000047_22 & 2) != 0) {
            stage_v_70 = (pub_r000047_7 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000047_7 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000047_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000047_8 & 2) != 0) {
            stage_v_71 = (pub_r000047_17 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000047_17 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000047_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000047_7 & 2) != 0) {
            stage_v_72 = (pub_r000047_18 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000047_18 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000047_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000047_7 & 2) != 0) {
            stage_v_73 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000047_2 & 1) != 0) {
        if ((sec_r000047_14 & 2) != 0) {
            stage_v_74 = (pub_r000047_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000047_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000047_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_75 = (pub_r000047_18 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000047_18 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000047_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000047_5 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_76 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000047_22 & 2) != 0) {
            stage_v_77 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000047_7 & 2) != 0) {
            stage_v_78 = (pub_r000047_6 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000047_6 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000047_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000047_11 & 2) != 0) {
            stage_v_79 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000047_14 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_80 = (pub_r000047_9 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000047_9 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000047_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000047_14 & 2) != 0) {
            stage_v_81 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000047_21 & 2) != 0) {
            stage_v_82 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000047_2 & 1) != 0) {
        if ((sec_r000047_22 & 2) != 0) {
            stage_v_83 = (pub_r000047_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000047_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000047_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_84 = (pub_r000047_17 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000047_17 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000047_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000047_14 & 1) != 0) {
        if ((sec_r000047_4 & 2) != 0) {
            stage_v_85 = (pub_r000047_5 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000047_5 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000047_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000047_6 & 1) != 0) {
        if ((sec_r000047_13 & 2) != 0) {
            stage_v_86 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000047_22 & 1) != 0) {
        if ((sec_r000047_6 & 2) != 0) {
            stage_v_87 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000047_10 & 2) != 0) {
            stage_v_88 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000047_9 & 2) != 0) {
            stage_v_89 = (pub_r000047_3 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000047_3 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000047_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000047_18 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_90 = (pub_r000047_20 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000047_20 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000047_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000047_12 & 2) != 0) {
            stage_v_91 = (pub_r000047_11 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000047_11 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000047_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000047_10 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_92 = (pub_r000047_13 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000047_13 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000047_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000047_18 & 2) != 0) {
            stage_v_93 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000047_5 & 2) != 0) {
            stage_v_94 = (pub_r000047_11 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000047_11 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000047_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000047_13 & 2) != 0) {
            stage_v_95 = (pub_r000047_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000047_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000047_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000047_18 & 1) != 0) {
        if ((sec_r000047_13 & 2) != 0) {
            stage_v_96 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000047_15 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_97 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000047_6 & 1) != 0) {
        if ((sec_r000047_15 & 2) != 0) {
            stage_v_98 = (pub_r000047_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000047_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000047_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000047_9 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_99 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_100 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_101 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000047_3 & 2) != 0) {
            stage_v_102 = (pub_r000047_9 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000047_9 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000047_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000047_22 & 1) != 0) {
        if ((sec_r000047_17 & 2) != 0) {
            stage_v_103 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000047_1 & 1) != 0) {
        if ((sec_r000047_0 & 2) != 0) {
            stage_v_104 = (pub_r000047_12 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000047_12 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000047_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000047_5 & 1) != 0) {
        if ((sec_r000047_8 & 2) != 0) {
            stage_v_105 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000047_1 & 1) != 0) {
        if ((sec_r000047_10 & 2) != 0) {
            stage_v_106 = (pub_r000047_21 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000047_21 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000047_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000047_19 & 1) != 0) {
        if ((sec_r000047_21 & 2) != 0) {
            stage_v_107 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_108 = (pub_r000047_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000047_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000047_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000047_20 & 2) != 0) {
            stage_v_109 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000047_6 & 2) != 0) {
            stage_v_110 = (pub_r000047_6 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000047_6 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000047_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_111 = (pub_r000047_14 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000047_14 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000047_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000047_0 & 2) != 0) {
            stage_v_112 = (pub_r000047_19 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000047_19 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000047_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000047_12 & 2) != 0) {
            stage_v_113 = (pub_r000047_14 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000047_14 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000047_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000047_5 & 1) != 0) {
        if ((sec_r000047_8 & 2) != 0) {
            stage_v_114 = (pub_r000047_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000047_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000047_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000047_12 & 2) != 0) {
            stage_v_115 = (pub_r000047_5 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000047_5 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000047_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000047_1 & 1) != 0) {
        if ((sec_r000047_4 & 2) != 0) {
            stage_v_116 = (pub_r000047_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000047_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000047_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000047_9 & 2) != 0) {
            stage_v_117 = (pub_r000047_14 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000047_14 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000047_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000047_18 & 2) != 0) {
            stage_v_118 = (pub_r000047_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000047_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000047_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000047_12 & 1) != 0) {
        if ((sec_r000047_16 & 2) != 0) {
            stage_v_119 = (pub_r000047_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000047_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000047_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000047_22 & 1) != 0) {
        if ((sec_r000047_10 & 2) != 0) {
            stage_v_120 = (pub_r000047_16 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000047_16 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000047_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000047_5 & 2) != 0) {
            stage_v_121 = (pub_r000047_3 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000047_3 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000047_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000047_3 & 1) != 0) {
        if ((sec_r000047_10 & 2) != 0) {
            stage_v_122 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000047_20 & 1) != 0) {
        if ((sec_r000047_7 & 2) != 0) {
            stage_v_123 = (pub_r000047_18 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000047_18 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000047_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000047_21 & 2) != 0) {
            stage_v_124 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000047_4 & 2) != 0) {
            stage_v_125 = (pub_r000047_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000047_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000047_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000047_1 & 2) != 0) {
            stage_v_126 = (pub_r000047_1 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000047_1 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000047_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000047_19 & 2) != 0) {
            stage_v_127 = (pub_r000047_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000047_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000047_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000047_2 & 2) != 0) {
            stage_v_128 = (pub_r000047_3 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000047_3 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000047_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000047_11 & 1) != 0) {
        if ((sec_r000047_0 & 2) != 0) {
            stage_v_129 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000047_11 & 2) != 0) {
            stage_v_130 = (pub_r000047_13 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000047_13 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000047_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000047_7 & 1) != 0) {
        if ((sec_r000047_4 & 2) != 0) {
            stage_v_131 = (pub_r000047_10 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000047_10 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000047_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000047_1 & 2) != 0) {
            stage_v_132 = (pub_r000047_0 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000047_0 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000047_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000047_1 & 2) != 0) {
            stage_v_133 = (pub_r000047_2 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000047_2 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000047_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
