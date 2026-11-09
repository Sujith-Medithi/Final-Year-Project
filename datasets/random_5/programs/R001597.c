/*
 * Benchmark Program: R001597
 * Security Family: nested_implicit_flow
 * Generator Seed: 659713
 * High Inputs: 23 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001597_9713_0 {
    int pitch;
    int heading;
    int coord_x;
    short norm_sq;
    int buffer[3];
};

struct SensorNode_R001597_9713_1 {
    short reading;
    unsigned char calib;
    unsigned char threshold;
    int offset;
    int gain;
    int status;
    int buffer[3];
};

struct MatrixBlock_R001597_9713_2 {
    unsigned char stride;
    int trace;
    short determinant;
    int density;
    short scale;
    int buffer[3];
};

struct StreamBuffer_R001597_9713_3 {
    int head;
    short capacity;
    int tail;
    int buffer[3];
};

union ColorPixel_R001597_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001597_9713_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_75) & 63;
    acc ^= aux;
    int parity_70 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_70 > 42) {
        acc = (acc + parity_70 * 2 + 5) & 127;
        aux ^= (parity_70 & 15);
    } else {
        acc = (acc - parity_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_14 = local_arr[aux % 3];
    acc = (acc + segment_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int index_reg_54 = local_arr[aux % 3];
    acc = (acc + index_reg_54 * 2) & 127;
    int accumulator_55 = (aux + st.buffer[1]) & 3;
    switch (accumulator_55) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_2(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int stride_51 = 0;
    for (int k = 0; k < 3; k++) {
        stride_51 = (stride_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_51) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001597_9713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_73) & 63;
    acc ^= aux;
    int segment_54 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_54 > 36) {
        acc = (acc + segment_54 * 2 + 5) & 127;
        aux ^= (segment_54 & 15);
    } else {
        acc = (acc - segment_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_94 = local_arr[aux % 3];
    acc = (acc + checksum_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001597_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_56 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_56 = (quantum_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_56) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_54 = local_arr[aux % 3];
    acc = (acc + quantum_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_5(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int bound_96 = local_arr[aux % 3];
    acc = (acc + bound_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_57 = (aux + st.buffer[1]) & 3;
    switch (tally_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int accumulator_44 = local_arr[aux % 3];
    acc = (acc + accumulator_44 * 2) & 127;
    int damping_47 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_47 > 46) {
        acc = (acc + damping_47 * 2 + 5) & 127;
        aux ^= (damping_47 & 15);
    } else {
        acc = (acc - damping_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_7(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int parity_31 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_31 > 48) {
        acc = (acc + parity_31 * 2 + 5) & 127;
        aux ^= (parity_31 & 15);
    } else {
        acc = (acc - parity_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_46) & 63;
    acc ^= aux;
    int margin_61 = 0;
    for (int k = 0; k < 2; k++) {
        margin_61 = (margin_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_99 = 0;
    for (int k = 0; k < 3; k++) {
        delta_99 = (delta_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001597_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int threshold_58 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_58 > 13) {
        acc = (acc + threshold_58 * 2 + 5) & 127;
        aux ^= (threshold_58 & 15);
    } else {
        acc = (acc - threshold_58 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_51 = local_arr[aux % 3];
    acc = (acc + accumulator_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_10(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001597_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_46) & 63;
    acc ^= aux;
    int stride_15 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_15 > 29) {
        acc = (acc + stride_15 * 2 + 5) & 127;
        aux ^= (stride_15 & 15);
    } else {
        acc = (acc - stride_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_27 = (aux + st.buffer[1]) & 3;
    switch (segment_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_20 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_20 = (checksum_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_20) & 127;
    }
    int quantum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001597_9713_12(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001597_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int metric_23 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_23 > 31) {
        acc = (acc + metric_23 * 2 + 5) & 127;
        aux ^= (metric_23 & 15);
    } else {
        acc = (acc - metric_23 + 11) & 127;
        aux += 3;
    }
    int weight_38 = (aux + st.buffer[1]) & 3;
    switch (weight_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int weight_30 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_30 > 14) {
        acc = (acc + weight_30 * 2 + 5) & 127;
        aux ^= (weight_30 & 15);
    } else {
        acc = (acc - weight_30 + 11) & 127;
        aux += 3;
    }
    int checksum_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001597_9713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_68 = (aux + st.buffer[1]) & 3;
    switch (quantum_68) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001597_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int stride_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_59) & 63;
    acc ^= aux;
    int mask_98 = 0;
    for (int k = 0; k < 2; k++) {
        mask_98 = (mask_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_98) & 127;
    }
    int tracker_35 = (aux + st.buffer[1]) & 3;
    switch (tracker_35) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001597_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_87) & 63;
    acc ^= aux;
    int sample_85 = (aux + st.buffer[1]) & 3;
    switch (sample_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_17(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_36) & 63;
    acc ^= aux;
    int weight_30 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_30 > 15) {
        acc = (acc + weight_30 * 2 + 5) & 127;
        aux ^= (weight_30 & 15);
    } else {
        acc = (acc - weight_30 + 11) & 127;
        aux += 3;
    }
    int margin_41 = 0;
    for (int k = 0; k < 2; k++) {
        margin_41 = (margin_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001597_9713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_42 = 0;
    for (int k = 0; k < 2; k++) {
        weight_42 = (weight_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_42) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_52 = local_arr[aux % 3];
    acc = (acc + sample_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001597_9713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001597_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_78) & 63;
    acc ^= aux;
    int tally_19 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_19 > 20) {
        acc = (acc + tally_19 * 2 + 5) & 127;
        aux ^= (tally_19 & 15);
    } else {
        acc = (acc - tally_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_78 = local_arr[aux % 3];
    acc = (acc + index_reg_78 * 2) & 127;
    int tracker_51 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_51 = (tracker_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_51) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001597_0;
    int sec_r001597_1;
    int sec_r001597_2;
    int sec_r001597_3;
    int sec_r001597_4;
    int sec_r001597_5;
    int sec_r001597_6;
    int sec_r001597_7;
    int sec_r001597_8;
    int sec_r001597_9;
    int sec_r001597_10;
    int sec_r001597_11;
    int sec_r001597_12;
    int sec_r001597_13;
    int sec_r001597_14;
    int sec_r001597_15;
    int sec_r001597_16;
    int sec_r001597_17;
    int sec_r001597_18;
    int sec_r001597_19;
    int sec_r001597_20;
    int sec_r001597_21;
    int sec_r001597_22;
    int pub_r001597_0;
    int pub_r001597_1;
    int pub_r001597_2;
    int pub_r001597_3;
    int pub_r001597_4;
    int pub_r001597_5;
    int pub_r001597_6;
    int pub_r001597_7;
    int pub_r001597_8;
    int pub_r001597_9;
    int pub_r001597_10;
    int pub_r001597_11;
    int pub_r001597_12;
    int pub_r001597_13;
    int pub_r001597_14;
    int pub_r001597_15;
    int pub_r001597_16;
    int pub_r001597_17;
    int pub_r001597_18;
    int pub_r001597_19;
    int pub_r001597_20;
    int pub_r001597_21;
    int pub_r001597_22;
    int pub_r001597_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001597_0 >= -100 && pub_r001597_0 <= 100);
    __CPROVER_assume(pub_r001597_1 >= -100 && pub_r001597_1 <= 100);
    __CPROVER_assume(pub_r001597_2 >= -100 && pub_r001597_2 <= 100);
    __CPROVER_assume(pub_r001597_3 >= -100 && pub_r001597_3 <= 100);
    __CPROVER_assume(pub_r001597_4 >= -100 && pub_r001597_4 <= 100);
    __CPROVER_assume(pub_r001597_5 >= -100 && pub_r001597_5 <= 100);
    __CPROVER_assume(pub_r001597_6 >= -100 && pub_r001597_6 <= 100);
    __CPROVER_assume(pub_r001597_7 >= -100 && pub_r001597_7 <= 100);
    __CPROVER_assume(pub_r001597_8 >= -100 && pub_r001597_8 <= 100);
    __CPROVER_assume(pub_r001597_9 >= -100 && pub_r001597_9 <= 100);
    __CPROVER_assume(pub_r001597_10 >= -100 && pub_r001597_10 <= 100);
    __CPROVER_assume(pub_r001597_11 >= -100 && pub_r001597_11 <= 100);
    __CPROVER_assume(pub_r001597_12 >= -100 && pub_r001597_12 <= 100);
    __CPROVER_assume(pub_r001597_13 >= -100 && pub_r001597_13 <= 100);
    __CPROVER_assume(pub_r001597_14 >= -100 && pub_r001597_14 <= 100);
    __CPROVER_assume(pub_r001597_15 >= -100 && pub_r001597_15 <= 100);
    __CPROVER_assume(pub_r001597_16 >= -100 && pub_r001597_16 <= 100);
    __CPROVER_assume(pub_r001597_17 >= -100 && pub_r001597_17 <= 100);
    __CPROVER_assume(pub_r001597_18 >= -100 && pub_r001597_18 <= 100);
    __CPROVER_assume(pub_r001597_19 >= -100 && pub_r001597_19 <= 100);
    __CPROVER_assume(pub_r001597_20 >= -100 && pub_r001597_20 <= 100);
    __CPROVER_assume(pub_r001597_21 >= -100 && pub_r001597_21 <= 100);
    __CPROVER_assume(pub_r001597_22 >= -100 && pub_r001597_22 <= 100);
    __CPROVER_assume(pub_r001597_23 >= -100 && pub_r001597_23 <= 100);
    __CPROVER_assume(sec_r001597_0 >= 0 && sec_r001597_0 <= 255);
    __CPROVER_assume(sec_r001597_1 >= 0 && sec_r001597_1 <= 255);
    __CPROVER_assume(sec_r001597_2 >= 0 && sec_r001597_2 <= 255);
    __CPROVER_assume(sec_r001597_3 >= 0 && sec_r001597_3 <= 255);
    __CPROVER_assume(sec_r001597_4 >= 0 && sec_r001597_4 <= 255);
    __CPROVER_assume(sec_r001597_5 >= 0 && sec_r001597_5 <= 255);
    __CPROVER_assume(sec_r001597_6 >= 0 && sec_r001597_6 <= 255);
    __CPROVER_assume(sec_r001597_7 >= 0 && sec_r001597_7 <= 255);
    __CPROVER_assume(sec_r001597_8 >= 0 && sec_r001597_8 <= 255);
    __CPROVER_assume(sec_r001597_9 >= 0 && sec_r001597_9 <= 255);
    __CPROVER_assume(sec_r001597_10 >= 0 && sec_r001597_10 <= 255);
    __CPROVER_assume(sec_r001597_11 >= 0 && sec_r001597_11 <= 255);
    __CPROVER_assume(sec_r001597_12 >= 0 && sec_r001597_12 <= 255);
    __CPROVER_assume(sec_r001597_13 >= 0 && sec_r001597_13 <= 255);
    __CPROVER_assume(sec_r001597_14 >= 0 && sec_r001597_14 <= 255);
    __CPROVER_assume(sec_r001597_15 >= 0 && sec_r001597_15 <= 255);
    __CPROVER_assume(sec_r001597_16 >= 0 && sec_r001597_16 <= 255);
    __CPROVER_assume(sec_r001597_17 >= 0 && sec_r001597_17 <= 255);
    __CPROVER_assume(sec_r001597_18 >= 0 && sec_r001597_18 <= 255);
    __CPROVER_assume(sec_r001597_19 >= 0 && sec_r001597_19 <= 255);
    __CPROVER_assume(sec_r001597_20 >= 0 && sec_r001597_20 <= 255);
    __CPROVER_assume(sec_r001597_21 >= 0 && sec_r001597_21 <= 255);
    __CPROVER_assume(sec_r001597_22 >= 0 && sec_r001597_22 <= 255);

    struct Vector3D_R001597_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001597_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001597_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001597_0 + 7) & 15;
    struct SensorNode_R001597_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001597_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001597_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001597_0 + 9) & 15;
    struct MatrixBlock_R001597_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001597_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001597_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001597_0 + 11) & 15;
    struct StreamBuffer_R001597_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001597_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001597_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001597_0 + 13) & 15;

    union ColorPixel_R001597_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001597_9713_0(sec_r001597_0, sec_r001597_1);
    int helper_flow_1 = fn_R001597_9713_1(sec_r001597_1, pub_r001597_2, pub_r001597_3, pub_r001597_4);
    int helper_flow_2 = fn_R001597_9713_2(sec_r001597_2, pub_r001597_3, pub_r001597_4);
    int helper_flow_3 = fn_R001597_9713_3(sec_r001597_3, sec_r001597_4, pub_r001597_5, pub_r001597_6);
    int helper_flow_4 = fn_R001597_9713_4(sec_r001597_4, pub_r001597_5, pub_r001597_6, pub_r001597_7);
    int helper_flow_5 = fn_R001597_9713_5(sec_r001597_5, pub_r001597_6, pub_r001597_7);
    int helper_flow_6 = fn_R001597_9713_6(sec_r001597_6, pub_r001597_7, pub_r001597_8, pub_r001597_9);
    int helper_flow_7 = fn_R001597_9713_7(sec_r001597_7, sec_r001597_8, pub_r001597_9);
    int helper_flow_8 = fn_R001597_9713_8(sec_r001597_8, pub_r001597_9, pub_r001597_10, pub_r001597_11);
    int helper_flow_9 = fn_R001597_9713_9(sec_r001597_9, sec_r001597_10, pub_r001597_11, pub_r001597_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001597_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001597_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001597_17 ^ pub_r001597_20) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001597_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001597_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001597_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001597_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001597_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001597_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001597_10 ^ pub_r001597_7) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001597_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001597_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_2 ^ pub_r001597_0) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001597_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_9 ^ pub_r001597_5) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001597_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001597_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001597_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001597_21 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_2 ^ pub_r001597_18) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001597_9 ^ pub_r001597_23) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001597_10 ^ pub_r001597_12) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001597_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_2 ^ pub_r001597_1) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001597_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_1 ^ pub_r001597_14) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_10 ^ pub_r001597_0) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_8 ^ pub_r001597_14) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001597_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001597_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001597_2 ^ pub_r001597_11) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001597_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_9 ^ pub_r001597_1) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001597_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001597_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_20 ^ pub_r001597_20) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001597_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_19 ^ pub_r001597_4) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r001597_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001597_17 ^ pub_r001597_22) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001597_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_8 ^ pub_r001597_18) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_8 ^ pub_r001597_10) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001597_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_20 ^ pub_r001597_5) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001597_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001597_3 ^ pub_r001597_8) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001597_13 ^ pub_r001597_3) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001597_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_2 ^ pub_r001597_5) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001597_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_1 ^ pub_r001597_22) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001597_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_34 ^ pub_r001597_22) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r001597_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001597_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_15 ^ pub_r001597_3) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_23 ^ pub_r001597_21) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001597_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_43 ^ pub_r001597_16) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001597_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_16 ^ pub_r001597_15) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001597_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_25 ^ pub_r001597_5) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001597_1 ^ pub_r001597_21) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_49 ^ pub_r001597_0) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_44 ^ pub_r001597_21) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_6 ^ pub_r001597_21) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_51 ^ pub_r001597_20) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001597_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_18 ^ pub_r001597_16) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001597_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001597_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001597_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001597_1 ^ pub_r001597_18) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_39 ^ pub_r001597_8) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001597_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (helper_flow_0 ^ pub_r001597_19) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_50 ^ pub_r001597_16) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001597_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_37 ^ pub_r001597_3) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_3 ^ pub_r001597_20) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001597_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001597_22 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001597_7 ^ pub_r001597_10) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_52 ^ pub_r001597_14) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001597_13 ^ pub_r001597_20) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_8 ^ pub_r001597_8) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001597_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001597_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_62 ^ pub_r001597_13) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001597_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001597_14 ^ pub_r001597_9) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001597_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001597_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001597_15 ^ pub_r001597_23) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r001597_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_3 ^ pub_r001597_12) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_7 ^ pub_r001597_13) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001597_2 ^ pub_r001597_18) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_32 ^ pub_r001597_10) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_34 ^ pub_r001597_9) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001597_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001597_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001597_11 ^ pub_r001597_1) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_68 ^ pub_r001597_10) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001597_5 ^ pub_r001597_9) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_2 ^ pub_r001597_1) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001597_22 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_35 ^ pub_r001597_11) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001597_16 ^ pub_r001597_20) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001597_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_1 ^ pub_r001597_17) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001597_18 ^ pub_r001597_17) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001597_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001597_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001597_5 ^ pub_r001597_4) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r001597_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_39 ^ pub_r001597_9) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_67 ^ pub_r001597_13) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_77 ^ pub_r001597_3) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_54 ^ pub_r001597_10) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001597_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001597_21 ^ pub_r001597_23) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001597_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001597_22 ^ pub_r001597_18) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_99 ^ pub_r001597_4) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001597_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_42 ^ pub_r001597_12) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001597_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001597_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001597_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (sec_r001597_11 ^ pub_r001597_21) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_21 ^ pub_r001597_6) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_33 ^ pub_r001597_8) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001597_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_51 ^ pub_r001597_7) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r001597_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_85 ^ pub_r001597_20) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r001597_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001597_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_112 ^ pub_r001597_12) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_23 ^ pub_r001597_6) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001597_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001597_20 ^ pub_r001597_7) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001597_5 ^ pub_r001597_12) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001597_11 ^ pub_r001597_17) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r001597_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_120 ^ pub_r001597_19) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001597_10 ^ pub_r001597_19) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_76 ^ pub_r001597_13) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_121 ^ pub_r001597_8) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_120 ^ pub_r001597_23) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_76 ^ pub_r001597_8) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r001597_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001597_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_95 ^ pub_r001597_11) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001597_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001597_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001597_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001597_11 ^ pub_r001597_4) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (helper_flow_5 ^ pub_r001597_6) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_130 ^ pub_r001597_4) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001597_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001597_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001597_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001597_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001597_23 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_97 ^ pub_r001597_8) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001597_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_32 ^ pub_r001597_14) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_43 ^ pub_r001597_21) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001597_9 ^ pub_r001597_15) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (helper_flow_1 ^ pub_r001597_21) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001597_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001597_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_115 ^ pub_r001597_7) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r001597_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001597_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_127 ^ pub_r001597_9) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (helper_flow_0 ^ pub_r001597_21) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001597_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_111 ^ pub_r001597_12) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_122 ^ pub_r001597_3) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((sec_r001597_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001597_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_44 ^ pub_r001597_14) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001597_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_49 ^ pub_r001597_9) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001597_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_62 ^ pub_r001597_16) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_150 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001597_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_80 ^ pub_r001597_21) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001597_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001597_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_121 ^ pub_r001597_3) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001597_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_2 ^ pub_r001597_4) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((sec_r001597_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (helper_flow_4 ^ pub_r001597_6) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_104 ^ pub_r001597_23) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_124 ^ pub_r001597_4) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (helper_flow_2 ^ pub_r001597_4) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_15 ^ pub_r001597_12) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (helper_flow_0 ^ pub_r001597_1) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((sec_r001597_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_44 ^ pub_r001597_7) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_156 ^ pub_r001597_8) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_51 ^ pub_r001597_10) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
