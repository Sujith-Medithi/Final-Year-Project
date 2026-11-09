/*
 * Benchmark Program: R001700
 * Security Family: mixed_control_data
 * Generator Seed: 670013
 * High Inputs: 18 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001700_13_0 {
    int stop_bits;
    int id;
    int baud_rate;
    int buffer[3];
};

struct Transaction_R001700_13_1 {
    unsigned char status;
    int auth_code;
    int rate;
    unsigned char balance;
    int buffer[3];
};

struct StreamBuffer_R001700_13_2 {
    int tail;
    short state;
    short capacity;
    short checksum;
    int buffer[3];
};

struct Vector3D_R001700_13_3 {
    int pitch;
    int heading;
    unsigned char coord_x;
    unsigned char norm_sq;
    unsigned char coord_y;
    int buffer[3];
};

union RegisterBank_R001700_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001700_13_0(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_82 > 13) {
        acc = (acc + anchor_82 * 2 + 5) & 127;
        aux ^= (anchor_82 & 15);
    } else {
        acc = (acc - anchor_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_77 = local_arr[aux % 3];
    acc = (acc + threshold_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001700_13_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001700_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int index_reg_96 = local_arr[aux % 3];
    acc = (acc + index_reg_96 * 2) & 127;
    int tracker_76 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_76 = (tracker_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_76) & 127;
    }
    int index_reg_43 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_43 > 41) {
        acc = (acc + index_reg_43 * 2 + 5) & 127;
        aux ^= (index_reg_43 & 15);
    } else {
        acc = (acc - index_reg_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int window_83 = local_arr[aux % 3];
    acc = (acc + window_83 * 2) & 127;
    int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_80) & 63;
    acc ^= aux;
    int stride_92 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_92 > 41) {
        acc = (acc + stride_92 * 2 + 5) & 127;
        aux ^= (stride_92 & 15);
    } else {
        acc = (acc - stride_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_3(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001700_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_55 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_55 > 38) {
        acc = (acc + index_reg_55 * 2 + 5) & 127;
        aux ^= (index_reg_55 & 15);
    } else {
        acc = (acc - index_reg_55 + 11) & 127;
        aux += 3;
    }
    int segment_36 = 0;
    for (int k = 0; k < 2; k++) {
        segment_36 = (segment_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_29) & 63;
    acc ^= aux;
    int residue_26 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_26 > 36) {
        acc = (acc + residue_26 * 2 + 5) & 127;
        aux ^= (residue_26 & 15);
    } else {
        acc = (acc - residue_26 + 11) & 127;
        aux += 3;
    }
    int phase_29 = (aux + st.buffer[1]) & 3;
    switch (phase_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_61 = 0;
    for (int k = 0; k < 3; k++) {
        window_61 = (window_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001700_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int delta_21 = local_arr[aux % 3];
    acc = (acc + delta_21 * 2) & 127;
    int vector_72 = 0;
    for (int k = 0; k < 3; k++) {
        vector_72 = (vector_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_72) & 127;
    }
    int tracker_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_40 > 43) {
        acc = (acc + tracker_40 * 2 + 5) & 127;
        aux ^= (tracker_40 & 15);
    } else {
        acc = (acc - tracker_40 + 11) & 127;
        aux += 3;
    }
    int bound_54 = (aux + st.buffer[1]) & 3;
    switch (bound_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int tally_56 = local_arr[aux % 3];
    acc = (acc + tally_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001700_13_7(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_99 = (aux + st.buffer[1]) & 3;
    switch (metric_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_99 = 0;
    for (int k = 0; k < 3; k++) {
        scale_99 = (scale_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_54 > 28) {
        acc = (acc + cursor_54 * 2 + 5) & 127;
        aux ^= (cursor_54 & 15);
    } else {
        acc = (acc - cursor_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_8(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001700_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int accumulator_16 = local_arr[aux % 3];
    acc = (acc + accumulator_16 * 2) & 127;
    int pivot_80 = (aux + st.buffer[1]) & 3;
    switch (pivot_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001700_13_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001700_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_21 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_21 > 18) {
        acc = (acc + cursor_21 * 2 + 5) & 127;
        aux ^= (cursor_21 & 15);
    } else {
        acc = (acc - cursor_21 + 11) & 127;
        aux += 3;
    }
    int window_14 = 0;
    for (int k = 0; k < 3; k++) {
        window_14 = (window_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_14) & 127;
    }
    int metric_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_27) & 63;
    acc ^= aux;
    int offset_39 = (aux + st.buffer[1]) & 3;
    switch (offset_39) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_10(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001700_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int damping_39 = (aux + st.buffer[1]) & 3;
    switch (damping_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001700_13_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001700_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    int vector_41 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_41 > 45) {
        acc = (acc + vector_41 * 2 + 5) & 127;
        aux ^= (vector_41 & 15);
    } else {
        acc = (acc - vector_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_12(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001700_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int residue_24 = local_arr[aux % 3];
    acc = (acc + residue_24 * 2) & 127;
    int damping_75 = 0;
    for (int k = 0; k < 3; k++) {
        damping_75 = (damping_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_75) & 127;
    }
    int factor_26 = (aux + st.buffer[1]) & 3;
    switch (factor_26) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_56 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_56 > 35) {
        acc = (acc + stride_56 * 2 + 5) & 127;
        aux ^= (stride_56 & 15);
    } else {
        acc = (acc - stride_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_13(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001700_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_11 = 0;
    for (int k = 0; k < 2; k++) {
        segment_11 = (segment_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_11) & 127;
    }
    int damping_78 = (aux + st.buffer[1]) & 3;
    switch (damping_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_23 = local_arr[aux % 3];
    acc = (acc + vector_23 * 2) & 127;
    int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001700_13_14(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001700_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int factor_66 = local_arr[aux % 3];
    acc = (acc + factor_66 * 2) & 127;
    int quantum_40 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_40 = (quantum_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_40) & 127;
    }
    int cursor_42 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_42 > 30) {
        acc = (acc + cursor_42 * 2 + 5) & 127;
        aux ^= (cursor_42 & 15);
    } else {
        acc = (acc - cursor_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_23 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_23 = (threshold_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_16(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001700_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_48) & 63;
    acc ^= aux;
    int index_reg_39 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_39 = (index_reg_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001700_13_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001700_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_58 = 0;
    for (int k = 0; k < 3; k++) {
        tally_58 = (tally_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_58) & 127;
    }
    int index_reg_79 = (aux + st.buffer[1]) & 3;
    switch (index_reg_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_33 = local_arr[aux % 3];
    acc = (acc + mask_33 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001700_0;
    int sec_r001700_1;
    int sec_r001700_2;
    int sec_r001700_3;
    int sec_r001700_4;
    int sec_r001700_5;
    int sec_r001700_6;
    int sec_r001700_7;
    int sec_r001700_8;
    int sec_r001700_9;
    int sec_r001700_10;
    int sec_r001700_11;
    int sec_r001700_12;
    int sec_r001700_13;
    int sec_r001700_14;
    int sec_r001700_15;
    int sec_r001700_16;
    int sec_r001700_17;
    int pub_r001700_0;
    int pub_r001700_1;
    int pub_r001700_2;
    int pub_r001700_3;
    int pub_r001700_4;
    int pub_r001700_5;
    int pub_r001700_6;
    int pub_r001700_7;
    int pub_r001700_8;
    int pub_r001700_9;
    int pub_r001700_10;
    int pub_r001700_11;
    int pub_r001700_12;
    int pub_r001700_13;
    int pub_r001700_14;
    int pub_r001700_15;
    int pub_r001700_16;
    int pub_r001700_17;
    int pub_r001700_18;
    int pub_r001700_19;
    int pub_r001700_20;
    int pub_r001700_21;
    int pub_r001700_22;
    int pub_r001700_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001700_0 >= -100 && pub_r001700_0 <= 100);
    __CPROVER_assume(pub_r001700_1 >= -100 && pub_r001700_1 <= 100);
    __CPROVER_assume(pub_r001700_2 >= -100 && pub_r001700_2 <= 100);
    __CPROVER_assume(pub_r001700_3 >= -100 && pub_r001700_3 <= 100);
    __CPROVER_assume(pub_r001700_4 >= -100 && pub_r001700_4 <= 100);
    __CPROVER_assume(pub_r001700_5 >= -100 && pub_r001700_5 <= 100);
    __CPROVER_assume(pub_r001700_6 >= -100 && pub_r001700_6 <= 100);
    __CPROVER_assume(pub_r001700_7 >= -100 && pub_r001700_7 <= 100);
    __CPROVER_assume(pub_r001700_8 >= -100 && pub_r001700_8 <= 100);
    __CPROVER_assume(pub_r001700_9 >= -100 && pub_r001700_9 <= 100);
    __CPROVER_assume(pub_r001700_10 >= -100 && pub_r001700_10 <= 100);
    __CPROVER_assume(pub_r001700_11 >= -100 && pub_r001700_11 <= 100);
    __CPROVER_assume(pub_r001700_12 >= -100 && pub_r001700_12 <= 100);
    __CPROVER_assume(pub_r001700_13 >= -100 && pub_r001700_13 <= 100);
    __CPROVER_assume(pub_r001700_14 >= -100 && pub_r001700_14 <= 100);
    __CPROVER_assume(pub_r001700_15 >= -100 && pub_r001700_15 <= 100);
    __CPROVER_assume(pub_r001700_16 >= -100 && pub_r001700_16 <= 100);
    __CPROVER_assume(pub_r001700_17 >= -100 && pub_r001700_17 <= 100);
    __CPROVER_assume(pub_r001700_18 >= -100 && pub_r001700_18 <= 100);
    __CPROVER_assume(pub_r001700_19 >= -100 && pub_r001700_19 <= 100);
    __CPROVER_assume(pub_r001700_20 >= -100 && pub_r001700_20 <= 100);
    __CPROVER_assume(pub_r001700_21 >= -100 && pub_r001700_21 <= 100);
    __CPROVER_assume(pub_r001700_22 >= -100 && pub_r001700_22 <= 100);
    __CPROVER_assume(pub_r001700_23 >= -100 && pub_r001700_23 <= 100);
    __CPROVER_assume(sec_r001700_0 >= 0 && sec_r001700_0 <= 255);
    __CPROVER_assume(sec_r001700_1 >= 0 && sec_r001700_1 <= 255);
    __CPROVER_assume(sec_r001700_2 >= 0 && sec_r001700_2 <= 255);
    __CPROVER_assume(sec_r001700_3 >= 0 && sec_r001700_3 <= 255);
    __CPROVER_assume(sec_r001700_4 >= 0 && sec_r001700_4 <= 255);
    __CPROVER_assume(sec_r001700_5 >= 0 && sec_r001700_5 <= 255);
    __CPROVER_assume(sec_r001700_6 >= 0 && sec_r001700_6 <= 255);
    __CPROVER_assume(sec_r001700_7 >= 0 && sec_r001700_7 <= 255);
    __CPROVER_assume(sec_r001700_8 >= 0 && sec_r001700_8 <= 255);
    __CPROVER_assume(sec_r001700_9 >= 0 && sec_r001700_9 <= 255);
    __CPROVER_assume(sec_r001700_10 >= 0 && sec_r001700_10 <= 255);
    __CPROVER_assume(sec_r001700_11 >= 0 && sec_r001700_11 <= 255);
    __CPROVER_assume(sec_r001700_12 >= 0 && sec_r001700_12 <= 255);
    __CPROVER_assume(sec_r001700_13 >= 0 && sec_r001700_13 <= 255);
    __CPROVER_assume(sec_r001700_14 >= 0 && sec_r001700_14 <= 255);
    __CPROVER_assume(sec_r001700_15 >= 0 && sec_r001700_15 <= 255);
    __CPROVER_assume(sec_r001700_16 >= 0 && sec_r001700_16 <= 255);
    __CPROVER_assume(sec_r001700_17 >= 0 && sec_r001700_17 <= 255);

    struct DeviceConfig_R001700_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001700_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001700_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001700_0 + 7) & 15;
    struct Transaction_R001700_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001700_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001700_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001700_0 + 9) & 15;
    struct StreamBuffer_R001700_13_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001700_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001700_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001700_0 + 11) & 15;
    struct Vector3D_R001700_13_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001700_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001700_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001700_0 + 13) & 15;

    union RegisterBank_R001700_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001700_13_0(sec_r001700_0, pub_r001700_1);
    int helper_flow_1 = fn_R001700_13_1(sec_r001700_1, pub_r001700_2, pub_r001700_3, pub_r001700_4);
    int helper_flow_2 = fn_R001700_13_2(sec_r001700_2, pub_r001700_3, pub_r001700_4, pub_r001700_5, pub_r001700_6);
    int helper_flow_3 = fn_R001700_13_3(sec_r001700_3, sec_r001700_4);
    int helper_flow_4 = fn_R001700_13_4(sec_r001700_4, sec_r001700_5, pub_r001700_6, pub_r001700_7, pub_r001700_8);
    int helper_flow_5 = fn_R001700_13_5(sec_r001700_5, sec_r001700_6, pub_r001700_7, pub_r001700_8);
    int helper_flow_6 = fn_R001700_13_6(sec_r001700_6, pub_r001700_7, pub_r001700_8, pub_r001700_9, pub_r001700_10);
    int helper_flow_7 = fn_R001700_13_7(sec_r001700_7, sec_r001700_8);
    int helper_flow_8 = fn_R001700_13_8(sec_r001700_8, sec_r001700_9, pub_r001700_10);
    int helper_flow_9 = fn_R001700_13_9(sec_r001700_9, pub_r001700_10, pub_r001700_11, pub_r001700_12);
    int helper_flow_10 = fn_R001700_13_10(sec_r001700_10, sec_r001700_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001700_10 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_0 > 43) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001700_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_2 > 44) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001700_10 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_4 > 38) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001700_12) & 127;
    if (stage_v_5 > 38) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_6 > 43) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001700_15 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_7 > 24) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001700_11 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_8 > 22) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001700_13 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_9 > 46) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_10 > 41) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001700_23 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001700_15 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_12 > 45) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001700_4 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001700_3 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_15 > 38) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_16 > 33) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001700_8 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_17 > 38) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_18 > 33) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001700_12 ^ 0x2A) * 2 + pub_r001700_17) & 127;
    if (stage_v_20 > 34) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001700_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001700_2 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_23 > 47) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_24 > 42) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001700_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001700_15 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_26 > 35) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_27 > 24) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001700_1 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_28 > 47) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001700_0 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_29 > 27) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_30 > 41) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_31 > 40) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001700_0 ^ 0x2A) * 2 + pub_r001700_23) & 127;
    if (stage_v_32 > 43) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_33 > 50) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_34 > 47) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_35 > 42) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001700_7 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001700_3 ^ 0x2A) * 2 + pub_r001700_12) & 127;
    if (stage_v_37 > 33) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001700_15 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_38 > 25) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_39 > 43) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_40 > 35) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_41 > 27) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_42 > 35) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_43 > 45) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001700_23 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_45 > 21) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_46 > 42) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001700_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001700_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001700_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_50 > 41) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001700_16 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_51 > 27) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_52 > 22) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_53 > 33) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001700_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001700_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_56 > 27) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001700_22 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001700_5 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_59 > 43) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001700_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001700_12) & 127;
    if (stage_v_61 > 29) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001700_22 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_63 > 50) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_64 > 32) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_65 > 43) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_66 > 41) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_67 > 23) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_68 > 35) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_69 > 37) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001700_5) & 127;
    if (stage_v_70 > 31) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_71 > 28) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_72 > 47) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_73 > 48) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_74 > 50) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001700_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_76 > 50) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001700_4 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_77 > 35) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001700_5) & 127;
    if (stage_v_79 > 43) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_80 > 24) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_81 > 33) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_82 > 41) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_83 > 50) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_84 > 28) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001700_17 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_85 > 46) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_87 > 30) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001700_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_89 > 40) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001700_22 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001700_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_92 > 45) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_93 > 49) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001700_2 ^ 0x2A) * 2 + pub_r001700_17) & 127;
    if (stage_v_94 > 41) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001700_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001700_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001700_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_98 > 41) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_99 > 43) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_100 > 36) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_101 > 31) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001700_23 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001700_9 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_103 > 32) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_104 > 23) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_105 > 41) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001700_10 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_106 > 26) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001700_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001700_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_109 > 38) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_110 > 49) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_111 > 37) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001700_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_113 > 23) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_114 > 26) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_115 > 43) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001700_5 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_116 > 29) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001700_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_118 > 28) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001700_10 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_119 > 25) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001700_9 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_121 > 29) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001700_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001700_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_124 > 28) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001700_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_126 > 22) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_127 > 40) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_128 > 40) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001700_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_130 > 25) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_131 > 40) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001700_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001700_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001700_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_135 > 20) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_136 > 35) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_137 > 35) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001700_12 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_138 > 38) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_139 > 50) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_140 > 26) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001700_1 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_142 > 48) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_143 > 22) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_144 > 38) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001700_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001700_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001700_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001700_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001700_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001700_7 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_150 > 31) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_151 > 20) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001700_5) & 127;
    if (stage_v_152 > 33) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_153 > 23) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_154 > 49) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001700_20 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_156 > 32) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001700_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_158 > 39) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_159 > 45) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001700_23) & 127;
    if (stage_v_160 > 46) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001700_4) & 127;
    if (stage_v_161 > 44) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001700_23) & 127;
    if (stage_v_162 > 34) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001700_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001700_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_165 > 42) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001700_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001700_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001700_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001700_23) & 127;
    if (stage_v_169 > 24) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_170 > 49) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_171 > 36) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_172 > 46) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001700_23) & 127;
    if (stage_v_173 > 23) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_174 > 24) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001700_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_176 > 34) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001700_2 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_177 > 34) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001700_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001700_12) & 127;
    if (stage_v_180 > 46) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001700_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_183 > 20) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001700_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_185 > 25) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001700_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001700_22 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001700_16 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_189 > 38) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_190 > 30) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001700_12) & 127;
    if (stage_v_191 > 44) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001700_16) & 127;
    if (stage_v_192 > 29) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_193 > 24) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001700_18) & 127;
    if (stage_v_194 > 43) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001700_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001700_15 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_196 > 26) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001700_17) & 127;
    if (stage_v_197 > 37) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001700_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_199 > 49) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_200 > 25) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_201 > 24) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_202 > 28) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_203 > 39) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001700_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_205 > 29) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001700_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_207 > 38) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001700_17) & 127;
    if (stage_v_208 > 36) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001700_6) & 127;
    if (stage_v_209 > 22) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001700_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001700_17) & 127;
    if (stage_v_211 > 25) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001700_5) & 127;
    if (stage_v_212 > 37) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001700_1 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_213 > 37) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_214 > 20) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001700_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001700_13) & 127;
    if (stage_v_216 > 40) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_217 > 20) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001700_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001700_0) & 127;
    if (stage_v_219 > 30) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001700_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001700_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_222 > 43) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001700_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001700_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001700_20) & 127;
    if (stage_v_225 > 40) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001700_14) & 127;
    if (stage_v_226 > 40) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_227 > 43) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_228 > 35) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_229 > 30) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001700_7) & 127;
    if (stage_v_230 > 28) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001700_11 ^ 0x2A) * 2 + pub_r001700_21) & 127;
    if (stage_v_231 > 36) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_222 ^ 0x2A) * 2 + pub_r001700_3) & 127;
    if (stage_v_232 > 21) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001700_22) & 127;
    if (stage_v_233 > 36) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001700_10) & 127;
    if (stage_v_234 > 26) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001700_1) & 127;
    if (stage_v_235 > 40) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001700_2) & 127;
    if (stage_v_236 > 34) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_216 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_237 > 45) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001700_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r001700_2 ^ 0x2A) * 2 + pub_r001700_8) & 127;
    if (stage_v_239 > 26) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001700_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001700_19) & 127;
    if (stage_v_241 > 41) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001700_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001700_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001700_4 ^ 0x2A) * 2 + pub_r001700_11) & 127;
    if (stage_v_244 > 20) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001700_15) & 127;
    if (stage_v_245 > 46) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001700_9) & 127;
    if (stage_v_246 > 48) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
