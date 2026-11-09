/*
 * Benchmark Program: R001316
 * Security Family: implicit_flow
 * Generator Seed: 631613
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001316_1613_0 {
    short calib;
    unsigned char reading;
    int gain;
    unsigned char status;
    int offset;
    int buffer[3];
};

struct Vector3D_R001316_1613_1 {
    int norm_sq;
    int coord_x;
    short coord_z;
    int heading;
    int buffer[3];
};

union PacketPayload_R001316_1613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001316_1613_0(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int segment_93 = 0;
    for (int k = 0; k < 3; k++) {
        segment_93 = (segment_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_93) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    int index_reg_89 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_89 > 11) {
        acc = (acc + index_reg_89 * 2 + 5) & 127;
        aux ^= (index_reg_89 & 15);
    } else {
        acc = (acc - index_reg_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int damping_79 = local_arr[aux % 3];
    acc = (acc + damping_79 * 2) & 127;
    int metric_98 = (aux + st.buffer[1]) & 3;
    switch (metric_98) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_95 = 0;
    for (int k = 0; k < 2; k++) {
        margin_95 = (margin_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_95) & 127;
    }
    int segment_54 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_54 > 14) {
        acc = (acc + segment_54 * 2 + 5) & 127;
        aux ^= (segment_54 & 15);
    } else {
        acc = (acc - segment_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int sample_65 = local_arr[aux % 3];
    acc = (acc + sample_65 * 2) & 127;
    int quotient_25 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_25 > 15) {
        acc = (acc + quotient_25 * 2 + 5) & 127;
        aux ^= (quotient_25 & 15);
    } else {
        acc = (acc - quotient_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_35 = 0;
    for (int k = 0; k < 3; k++) {
        tally_35 = (tally_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_35) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_47 = local_arr[aux % 3];
    acc = (acc + damping_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001316_1613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int factor_49 = 0;
    for (int k = 0; k < 2; k++) {
        factor_49 = (factor_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_49) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_50 = local_arr[aux % 3];
    acc = (acc + stride_50 * 2) & 127;
    int damping_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001316_1613_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_58 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_58 > 10) {
        acc = (acc + delta_58 * 2 + 5) & 127;
        aux ^= (delta_58 & 15);
    } else {
        acc = (acc - delta_58 + 11) & 127;
        aux += 3;
    }
    int phase_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001316_1613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_40 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_40 > 47) {
        acc = (acc + margin_40 * 2 + 5) & 127;
        aux ^= (margin_40 & 15);
    } else {
        acc = (acc - margin_40 + 11) & 127;
        aux += 3;
    }
    int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001316_1613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_58) & 63;
    acc ^= aux;
    int tally_88 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_88 > 38) {
        acc = (acc + tally_88 * 2 + 5) & 127;
        aux ^= (tally_88 & 15);
    } else {
        acc = (acc - tally_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_12 = (aux + st.buffer[1]) & 3;
    switch (window_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_8(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_34 = (aux + st.buffer[1]) & 3;
    switch (quotient_34) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_87 = local_arr[aux % 3];
    acc = (acc + checksum_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001316_1613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int quantum_68 = local_arr[aux % 3];
    acc = (acc + quantum_68 * 2) & 127;
    int stride_58 = 0;
    for (int k = 0; k < 2; k++) {
        stride_58 = (stride_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_58) & 127;
    }
    int bound_89 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_89 > 42) {
        acc = (acc + bound_89 * 2 + 5) & 127;
        aux ^= (bound_89 & 15);
    } else {
        acc = (acc - bound_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001316_1613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int vector_66 = local_arr[aux % 3];
    acc = (acc + vector_66 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_47 = (aux + st.buffer[1]) & 3;
    switch (phase_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_45 = 0;
    for (int k = 0; k < 3; k++) {
        metric_45 = (metric_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_45) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_54 = local_arr[aux % 3];
    acc = (acc + tally_54 * 2) & 127;
    int residue_17 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_17 > 39) {
        acc = (acc + residue_17 * 2 + 5) & 127;
        aux ^= (residue_17 & 15);
    } else {
        acc = (acc - residue_17 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001316_1613_12(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_69) & 63;
    acc ^= aux;
    int tracker_11 = (aux + st.buffer[1]) & 3;
    switch (tracker_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_82 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_82 > 32) {
        acc = (acc + tally_82 * 2 + 5) & 127;
        aux ^= (tally_82 & 15);
    } else {
        acc = (acc - tally_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_68) & 63;
    acc ^= aux;
    int parity_52 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_52 > 41) {
        acc = (acc + parity_52 * 2 + 5) & 127;
        aux ^= (parity_52 & 15);
    } else {
        acc = (acc - parity_52 + 11) & 127;
        aux += 3;
    }
    int index_reg_79 = (aux + st.buffer[1]) & 3;
    switch (index_reg_79) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int parity_64 = local_arr[aux % 3];
    acc = (acc + parity_64 * 2) & 127;
    int threshold_99 = (aux + st.buffer[1]) & 3;
    switch (threshold_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_15(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_91 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_91 = (pivot_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_91) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_78 = (aux + st.buffer[1]) & 3;
    switch (damping_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001316_1613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001316_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int segment_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_38) & 63;
    acc ^= aux;
    int bound_37 = (aux + st.buffer[1]) & 3;
    switch (bound_37) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001316_1613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001316_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_76 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_76 > 25) {
        acc = (acc + offset_76 * 2 + 5) & 127;
        aux ^= (offset_76 & 15);
    } else {
        acc = (acc - offset_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001316_0;
    int sec_r001316_1;
    int sec_r001316_2;
    int sec_r001316_3;
    int sec_r001316_4;
    int sec_r001316_5;
    int sec_r001316_6;
    int sec_r001316_7;
    int sec_r001316_8;
    int sec_r001316_9;
    int sec_r001316_10;
    int sec_r001316_11;
    int sec_r001316_12;
    int sec_r001316_13;
    int sec_r001316_14;
    int sec_r001316_15;
    int sec_r001316_16;
    int sec_r001316_17;
    int sec_r001316_18;
    int sec_r001316_19;
    int pub_r001316_0;
    int pub_r001316_1;
    int pub_r001316_2;
    int pub_r001316_3;
    int pub_r001316_4;
    int pub_r001316_5;
    int pub_r001316_6;
    int pub_r001316_7;
    int pub_r001316_8;
    int pub_r001316_9;
    int pub_r001316_10;
    int pub_r001316_11;
    int pub_r001316_12;
    int pub_r001316_13;
    int pub_r001316_14;
    int pub_r001316_15;
    int pub_r001316_16;
    int pub_r001316_17;
    int pub_r001316_18;
    int pub_r001316_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001316_0 >= -100 && pub_r001316_0 <= 100);
    __CPROVER_assume(pub_r001316_1 >= -100 && pub_r001316_1 <= 100);
    __CPROVER_assume(pub_r001316_2 >= -100 && pub_r001316_2 <= 100);
    __CPROVER_assume(pub_r001316_3 >= -100 && pub_r001316_3 <= 100);
    __CPROVER_assume(pub_r001316_4 >= -100 && pub_r001316_4 <= 100);
    __CPROVER_assume(pub_r001316_5 >= -100 && pub_r001316_5 <= 100);
    __CPROVER_assume(pub_r001316_6 >= -100 && pub_r001316_6 <= 100);
    __CPROVER_assume(pub_r001316_7 >= -100 && pub_r001316_7 <= 100);
    __CPROVER_assume(pub_r001316_8 >= -100 && pub_r001316_8 <= 100);
    __CPROVER_assume(pub_r001316_9 >= -100 && pub_r001316_9 <= 100);
    __CPROVER_assume(pub_r001316_10 >= -100 && pub_r001316_10 <= 100);
    __CPROVER_assume(pub_r001316_11 >= -100 && pub_r001316_11 <= 100);
    __CPROVER_assume(pub_r001316_12 >= -100 && pub_r001316_12 <= 100);
    __CPROVER_assume(pub_r001316_13 >= -100 && pub_r001316_13 <= 100);
    __CPROVER_assume(pub_r001316_14 >= -100 && pub_r001316_14 <= 100);
    __CPROVER_assume(pub_r001316_15 >= -100 && pub_r001316_15 <= 100);
    __CPROVER_assume(pub_r001316_16 >= -100 && pub_r001316_16 <= 100);
    __CPROVER_assume(pub_r001316_17 >= -100 && pub_r001316_17 <= 100);
    __CPROVER_assume(pub_r001316_18 >= -100 && pub_r001316_18 <= 100);
    __CPROVER_assume(pub_r001316_19 >= -100 && pub_r001316_19 <= 100);
    __CPROVER_assume(sec_r001316_0 >= 0 && sec_r001316_0 <= 255);
    __CPROVER_assume(sec_r001316_1 >= 0 && sec_r001316_1 <= 255);
    __CPROVER_assume(sec_r001316_2 >= 0 && sec_r001316_2 <= 255);
    __CPROVER_assume(sec_r001316_3 >= 0 && sec_r001316_3 <= 255);
    __CPROVER_assume(sec_r001316_4 >= 0 && sec_r001316_4 <= 255);
    __CPROVER_assume(sec_r001316_5 >= 0 && sec_r001316_5 <= 255);
    __CPROVER_assume(sec_r001316_6 >= 0 && sec_r001316_6 <= 255);
    __CPROVER_assume(sec_r001316_7 >= 0 && sec_r001316_7 <= 255);
    __CPROVER_assume(sec_r001316_8 >= 0 && sec_r001316_8 <= 255);
    __CPROVER_assume(sec_r001316_9 >= 0 && sec_r001316_9 <= 255);
    __CPROVER_assume(sec_r001316_10 >= 0 && sec_r001316_10 <= 255);
    __CPROVER_assume(sec_r001316_11 >= 0 && sec_r001316_11 <= 255);
    __CPROVER_assume(sec_r001316_12 >= 0 && sec_r001316_12 <= 255);
    __CPROVER_assume(sec_r001316_13 >= 0 && sec_r001316_13 <= 255);
    __CPROVER_assume(sec_r001316_14 >= 0 && sec_r001316_14 <= 255);
    __CPROVER_assume(sec_r001316_15 >= 0 && sec_r001316_15 <= 255);
    __CPROVER_assume(sec_r001316_16 >= 0 && sec_r001316_16 <= 255);
    __CPROVER_assume(sec_r001316_17 >= 0 && sec_r001316_17 <= 255);
    __CPROVER_assume(sec_r001316_18 >= 0 && sec_r001316_18 <= 255);
    __CPROVER_assume(sec_r001316_19 >= 0 && sec_r001316_19 <= 255);

    struct SensorNode_R001316_1613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001316_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001316_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001316_0 + 7) & 15;
    struct Vector3D_R001316_1613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001316_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001316_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001316_0 + 9) & 15;

    union PacketPayload_R001316_1613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001316_1613_0(sec_r001316_0, pub_r001316_1);
    int helper_flow_1 = fn_R001316_1613_1(sec_r001316_1, pub_r001316_2, pub_r001316_3, pub_r001316_4);
    int helper_flow_2 = fn_R001316_1613_2(sec_r001316_2, sec_r001316_3, pub_r001316_4, pub_r001316_5);
    int helper_flow_3 = fn_R001316_1613_3(sec_r001316_3, sec_r001316_4, pub_r001316_5, pub_r001316_6, pub_r001316_7);
    int helper_flow_4 = fn_R001316_1613_4(sec_r001316_4, sec_r001316_5, pub_r001316_6, pub_r001316_7);
    int helper_flow_5 = fn_R001316_1613_5(sec_r001316_5, sec_r001316_6, pub_r001316_7);
    int helper_flow_6 = fn_R001316_1613_6(sec_r001316_6, pub_r001316_7, pub_r001316_8, pub_r001316_9);
    int helper_flow_7 = fn_R001316_1613_7(sec_r001316_7, sec_r001316_8, pub_r001316_9, pub_r001316_10, pub_r001316_11);
    int helper_flow_8 = fn_R001316_1613_8(sec_r001316_8, sec_r001316_9);
    int helper_flow_9 = fn_R001316_1613_9(sec_r001316_9, sec_r001316_10, pub_r001316_11, pub_r001316_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_2 + pub_r001316_1 * 2 + 5) & 127;
    if (stage_v_0 > 43) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001316_17 + pub_r001316_3 * 2 + 8) & 127;
    if (stage_v_1 > 24) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001316_8 + pub_r001316_18 * 2 + 11) & 127;
    if (stage_v_2 > 38) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001316_7 + pub_r001316_1 * 2 + 14) & 127;
    if (stage_v_3 > 34) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001316_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001316_15 + pub_r001316_1 * 2 + 20) & 127;
    if (stage_v_5 > 47) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001316_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_6 + pub_r001316_19 * 2 + 26) & 127;
    if (stage_v_7 > 43) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001316_2 + pub_r001316_5 * 2 + 29) & 127;
    if (stage_v_8 > 27) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001316_13 + pub_r001316_19 * 2 + 32) & 127;
    if (stage_v_9 > 45) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001316_18 + pub_r001316_0 * 2 + 35) & 127;
    if (stage_v_10 > 60) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_5 + pub_r001316_11 * 2 + 38) & 127;
    if (stage_v_11 > 19) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001316_7 + pub_r001316_0 * 2 + 41) & 127;
    if (stage_v_12 > 31) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001316_19 + pub_r001316_5 * 2 + 44) & 127;
    if (stage_v_13 > 42) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001316_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001316_13 + pub_r001316_16 * 2 + 50) & 127;
    if (stage_v_15 > 46) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_12 + pub_r001316_3 * 2 + 53) & 127;
    if (stage_v_16 > 26) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_4 + pub_r001316_9 * 2 + 56) & 127;
    if (stage_v_17 > 20) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001316_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_0 + pub_r001316_19 * 2 + 62) & 127;
    if (stage_v_19 > 21) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001316_4 + pub_r001316_10 * 2 + 65) & 127;
    if (stage_v_20 > 21) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001316_7 + pub_r001316_1 * 2 + 68) & 127;
    if (stage_v_21 > 15) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001316_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001316_14 + pub_r001316_19 * 2 + 74) & 127;
    if (stage_v_23 > 19) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001316_17 + pub_r001316_9 * 2 + 77) & 127;
    if (stage_v_24 > 40) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_11 + pub_r001316_5 * 2 + 80) & 127;
    if (stage_v_25 > 23) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_25 + pub_r001316_13 * 2 + 83) & 127;
    if (stage_v_26 > 31) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001316_16 + pub_r001316_13 * 2 + 86) & 127;
    if (stage_v_27 > 32) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_12 + pub_r001316_16 * 2 + 89) & 127;
    if (stage_v_28 > 51) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001316_0 + pub_r001316_13 * 2 + 92) & 127;
    if (stage_v_29 > 34) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001316_18 + pub_r001316_9 * 2 + 95) & 127;
    if (stage_v_30 > 29) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_4 + pub_r001316_10 * 2 + 98) & 127;
    if (stage_v_31 > 32) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001316_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001316_9 + pub_r001316_7 * 2 + 104) & 127;
    if (stage_v_33 > 24) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001316_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_0 + pub_r001316_12 * 2 + 110) & 127;
    if (stage_v_35 > 49) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_5 + pub_r001316_3 * 2 + 113) & 127;
    if (stage_v_36 > 26) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001316_11 + pub_r001316_14 * 2 + 116) & 127;
    if (stage_v_37 > 35) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001316_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_36 + pub_r001316_2 * 2 + 122) & 127;
    if (stage_v_39 > 59) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_16 + pub_r001316_18 * 2 + 125) & 127;
    if (stage_v_40 > 57) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001316_2 + pub_r001316_0 * 2 + 128) & 127;
    if (stage_v_41 > 47) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001316_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001316_10 + pub_r001316_2 * 2 + 134) & 127;
    if (stage_v_43 > 50) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001316_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001316_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_21 + pub_r001316_1 * 2 + 143) & 127;
    if (stage_v_46 > 32) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001316_3 + pub_r001316_10 * 2 + 146) & 127;
    if (stage_v_47 > 18) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001316_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_41 + pub_r001316_12 * 2 + 152) & 127;
    if (stage_v_49 > 52) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001316_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_41 + pub_r001316_8 * 2 + 158) & 127;
    if (stage_v_51 > 49) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001316_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001316_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001316_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001316_12 + pub_r001316_14 * 2 + 170) & 127;
    if (stage_v_55 > 52) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_1 + pub_r001316_1 * 2 + 173) & 127;
    if (stage_v_56 > 28) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001316_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001316_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001316_15 + pub_r001316_3 * 2 + 182) & 127;
    if (stage_v_59 > 34) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_47 + pub_r001316_9 * 2 + 185) & 127;
    if (stage_v_60 > 50) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001316_12 + pub_r001316_10 * 2 + 188) & 127;
    if (stage_v_61 > 52) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_59 + pub_r001316_3 * 2 + 191) & 127;
    if (stage_v_62 > 21) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_35 + pub_r001316_3 * 2 + 194) & 127;
    if (stage_v_63 > 47) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_30 + pub_r001316_16 * 2 + 197) & 127;
    if (stage_v_64 > 27) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001316_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001316_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001316_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_60 + pub_r001316_10 * 2 + 209) & 127;
    if (stage_v_68 > 21) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (helper_flow_1 + pub_r001316_13 * 2 + 212) & 127;
    if (stage_v_69 > 48) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_51 + pub_r001316_4 * 2 + 215) & 127;
    if (stage_v_70 > 25) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001316_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001316_15 + pub_r001316_8 * 2 + 221) & 127;
    if (stage_v_72 > 21) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001316_17 + pub_r001316_5 * 2 + 224) & 127;
    if (stage_v_73 > 55) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001316_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_30 + pub_r001316_18 * 2 + 230) & 127;
    if (stage_v_75 > 15) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_8 + pub_r001316_7 * 2 + 233) & 127;
    if (stage_v_76 > 16) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_40 + pub_r001316_13 * 2 + 236) & 127;
    if (stage_v_77 > 21) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001316_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001316_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001316_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001316_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001316_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001316_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_31 + pub_r001316_18 * 2 + 257) & 127;
    if (stage_v_84 > 33) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001316_0 + pub_r001316_14 * 2 + 260) & 127;
    if (stage_v_85 > 25) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_31 + pub_r001316_16 * 2 + 263) & 127;
    if (stage_v_86 > 24) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001316_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_68 + pub_r001316_5 * 2 + 269) & 127;
    if (stage_v_88 > 47) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001316_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001316_3 + pub_r001316_12 * 2 + 275) & 127;
    if (stage_v_90 > 42) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_51 + pub_r001316_13 * 2 + 278) & 127;
    if (stage_v_91 > 60) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001316_5 + pub_r001316_9 * 2 + 281) & 127;
    if (stage_v_92 > 47) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001316_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001316_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_64 + pub_r001316_5 * 2 + 290) & 127;
    if (stage_v_95 > 44) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001316_15 + pub_r001316_1 * 2 + 293) & 127;
    if (stage_v_96 > 24) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001316_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001316_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_68 + pub_r001316_18 * 2 + 302) & 127;
    if (stage_v_99 > 38) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001316_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001316_11 + pub_r001316_19 * 2 + 308) & 127;
    if (stage_v_101 > 36) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_12 + pub_r001316_7 * 2 + 311) & 127;
    if (stage_v_102 > 21) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001316_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001316_5 + pub_r001316_18 * 2 + 317) & 127;
    if (stage_v_104 > 18) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_69 + pub_r001316_16 * 2 + 320) & 127;
    if (stage_v_105 > 46) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (helper_flow_0 + pub_r001316_13 * 2 + 323) & 127;
    if (stage_v_106 > 39) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_77 + pub_r001316_4 * 2 + 326) & 127;
    if (stage_v_107 > 50) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_104 + pub_r001316_6 * 2 + 329) & 127;
    if (stage_v_108 > 37) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001316_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (helper_flow_7 + pub_r001316_13 * 2 + 335) & 127;
    if (stage_v_110 > 31) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001316_2 + pub_r001316_2 * 2 + 338) & 127;
    if (stage_v_111 > 26) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_30 + pub_r001316_0 * 2 + 341) & 127;
    if (stage_v_112 > 57) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_111 + pub_r001316_14 * 2 + 344) & 127;
    if (stage_v_113 > 19) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001316_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001316_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001316_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_30 + pub_r001316_9 * 2 + 356) & 127;
    if (stage_v_117 > 19) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_30 + pub_r001316_0 * 2 + 359) & 127;
    if (stage_v_118 > 43) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001316_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (helper_flow_1 + pub_r001316_14 * 2 + 365) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_35 + pub_r001316_8 * 2 + 368) & 127;
    if (stage_v_121 > 53) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001316_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_16 + pub_r001316_5 * 2 + 374) & 127;
    if (stage_v_123 > 48) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001316_3 + pub_r001316_15 * 2 + 377) & 127;
    if (stage_v_124 > 37) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_91 + pub_r001316_9 * 2 + 380) & 127;
    if (stage_v_125 > 46) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_96 + pub_r001316_7 * 2 + 383) & 127;
    if (stage_v_126 > 32) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001316_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_64 + pub_r001316_5 * 2 + 389) & 127;
    if (stage_v_128 > 18) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001316_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001316_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_92 + pub_r001316_17 * 2 + 398) & 127;
    if (stage_v_131 > 46) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_2 + pub_r001316_15 * 2 + 401) & 127;
    if (stage_v_132 > 20) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001316_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (helper_flow_1 + pub_r001316_12 * 2 + 407) & 127;
    if (stage_v_134 > 49) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001316_16 + pub_r001316_10 * 2 + 410) & 127;
    if (stage_v_135 > 58) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001316_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_72 + pub_r001316_3 * 2 + 416) & 127;
    if (stage_v_137 > 51) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001316_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_28 + pub_r001316_13 * 2 + 422) & 127;
    if (stage_v_139 > 60) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (helper_flow_7 + pub_r001316_6 * 2 + 425) & 127;
    if (stage_v_140 > 21) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001316_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001316_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_0 + pub_r001316_0 * 2 + 434) & 127;
    if (stage_v_143 > 22) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_121 + pub_r001316_14 * 2 + 437) & 127;
    if (stage_v_144 > 26) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001316_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_72 + pub_r001316_4 * 2 + 443) & 127;
    if (stage_v_146 > 57) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001316_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001316_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_46 + pub_r001316_13 * 2 + 452) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_36 + pub_r001316_2 * 2 + 455) & 127;
    if (stage_v_150 > 18) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_31 + pub_r001316_19 * 2 + 458) & 127;
    if (stage_v_151 > 57) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001316_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (helper_flow_0 + pub_r001316_13 * 2 + 464) & 127;
    if (stage_v_153 > 53) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_6 + pub_r001316_19 * 2 + 467) & 127;
    if (stage_v_154 > 21) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_134 + pub_r001316_17 * 2 + 470) & 127;
    if (stage_v_155 > 41) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_91 + pub_r001316_11 * 2 + 473) & 127;
    if (stage_v_156 > 32) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_31 + pub_r001316_1 * 2 + 476) & 127;
    if (stage_v_157 > 44) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_20 + pub_r001316_14 * 2 + 479) & 127;
    if (stage_v_158 > 43) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001316_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_157 + pub_r001316_13 * 2 + 485) & 127;
    if (stage_v_160 > 46) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_51 + pub_r001316_6 * 2 + 488) & 127;
    if (stage_v_161 > 19) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_15 + pub_r001316_16 * 2 + 491) & 127;
    if (stage_v_162 > 27) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_104 + pub_r001316_15 * 2 + 494) & 127;
    if (stage_v_163 > 15) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_76 + pub_r001316_15 * 2 + 497) & 127;
    if (stage_v_164 > 23) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001316_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001316_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001316_3 + pub_r001316_8 * 2 + 506) & 127;
    if (stage_v_167 > 46) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_3 + pub_r001316_18 * 2 + 509) & 127;
    if (stage_v_168 > 17) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_8 + pub_r001316_11 * 2 + 512) & 127;
    if (stage_v_169 > 38) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_88 + pub_r001316_4 * 2 + 515) & 127;
    if (stage_v_170 > 35) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001316_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_23 + pub_r001316_10 * 2 + 521) & 127;
    if (stage_v_172 > 47) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_13 + pub_r001316_10 * 2 + 524) & 127;
    if (stage_v_173 > 44) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_21 + pub_r001316_19 * 2 + 527) & 127;
    if (stage_v_174 > 51) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001316_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (sec_r001316_6 + pub_r001316_19 * 2 + 533) & 127;
    if (stage_v_176 > 60) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_112 + pub_r001316_0 * 2 + 536) & 127;
    if (stage_v_177 > 46) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_49 + pub_r001316_16 * 2 + 539) & 127;
    if (stage_v_178 > 15) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001316_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001316_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001316_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001316_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001316_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_35 + pub_r001316_10 * 2 + 557) & 127;
    if (stage_v_184 > 30) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_107 + pub_r001316_10 * 2 + 560) & 127;
    if (stage_v_185 > 30) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_11 + pub_r001316_1 * 2 + 563) & 127;
    if (stage_v_186 > 16) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001316_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_69 + pub_r001316_2 * 2 + 569) & 127;
    if (stage_v_188 > 49) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001316_19 + pub_r001316_10 * 2 + 572) & 127;
    if (stage_v_189 > 18) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (helper_flow_3 + pub_r001316_14 * 2 + 575) & 127;
    if (stage_v_190 > 28) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001316_2 + pub_r001316_13 * 2 + 578) & 127;
    if (stage_v_191 > 59) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_77 + pub_r001316_4 * 2 + 581) & 127;
    if (stage_v_192 > 17) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_132 + pub_r001316_14 * 2 + 584) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_120 + pub_r001316_12 * 2 + 587) & 127;
    if (stage_v_194 > 44) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001316_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_120 + pub_r001316_6 * 2 + 593) & 127;
    if (stage_v_196 > 53) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_92 + pub_r001316_13 * 2 + 596) & 127;
    if (stage_v_197 > 52) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_12 + pub_r001316_6 * 2 + 599) & 127;
    if (stage_v_198 > 30) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_118 + pub_r001316_13 * 2 + 602) & 127;
    if (stage_v_199 > 41) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001316_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001316_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001316_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (sec_r001316_18 + pub_r001316_2 * 2 + 614) & 127;
    if (stage_v_203 > 33) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_203 + pub_r001316_0 * 2 + 617) & 127;
    if (stage_v_204 > 60) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (helper_flow_0 + pub_r001316_2 * 2 + 620) & 127;
    if (stage_v_205 > 48) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001316_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001316_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_60 + pub_r001316_18 * 2 + 629) & 127;
    if (stage_v_208 > 28) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001316_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001316_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (sec_r001316_13 + pub_r001316_0 * 2 + 638) & 127;
    if (stage_v_211 > 31) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_197 + pub_r001316_14 * 2 + 641) & 127;
    if (stage_v_212 > 18) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001316_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_47 + pub_r001316_16 * 2 + 647) & 127;
    if (stage_v_214 > 51) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_184 + pub_r001316_3 * 2 + 650) & 127;
    if (stage_v_215 > 51) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_70 + pub_r001316_14 * 2 + 653) & 127;
    if (stage_v_216 > 53) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_19 + pub_r001316_2 * 2 + 656) & 127;
    if (stage_v_217 > 39) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001316_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_37 + pub_r001316_16 * 2 + 662) & 127;
    if (stage_v_219 > 33) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_43 + pub_r001316_7 * 2 + 665) & 127;
    if (stage_v_220 > 54) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r001316_12 + pub_r001316_6 * 2 + 668) & 127;
    if (stage_v_221 > 43) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_60 + pub_r001316_13 * 2 + 671) & 127;
    if (stage_v_222 > 38) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_40 + pub_r001316_1 * 2 + 674) & 127;
    if (stage_v_223 > 29) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_124 + pub_r001316_14 * 2 + 677) & 127;
    if (stage_v_224 > 31) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (sec_r001316_13 + pub_r001316_17 * 2 + 680) & 127;
    if (stage_v_225 > 18) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_16 + pub_r001316_1 * 2 + 683) & 127;
    if (stage_v_226 > 17) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r001316_18 + pub_r001316_4 * 2 + 686) & 127;
    if (stage_v_227 > 38) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_146 + pub_r001316_3 * 2 + 689) & 127;
    if (stage_v_228 > 44) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
