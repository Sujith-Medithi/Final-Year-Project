/*
 * Benchmark Program: R000943
 * Security Family: multi_step_explicit
 * Generator Seed: 594313
 * High Inputs: 16 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000943_4313_0 {
    int account_id;
    unsigned char balance;
    unsigned char rate;
    unsigned char status;
    int buffer[3];
};

struct SensorNode_R000943_4313_1 {
    int status;
    int offset;
    int gain;
    short reading;
    int calib;
    int buffer[3];
};

struct Vector3D_R000943_4313_2 {
    unsigned char coord_x;
    int heading;
    unsigned char norm_sq;
    unsigned char coord_z;
    int buffer[3];
};

union TelemetryField_R000943_4313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000943_4313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000943_4313_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int delta_14 = local_arr[aux % 3];
    acc = (acc + delta_14 * 2) & 127;
    int pivot_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_74) & 63;
    acc ^= aux;
    int quantum_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_87 > 38) {
        acc = (acc + quantum_87 * 2 + 5) & 127;
        aux ^= (quantum_87 & 15);
    } else {
        acc = (acc - quantum_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000943_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int bound_61 = local_arr[aux % 3];
    acc = (acc + bound_61 * 2) & 127;
    int window_50 = (aux + st.buffer[1]) & 3;
    switch (window_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_90) & 63;
    acc ^= aux;
    int scale_43 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_43 > 37) {
        acc = (acc + scale_43 * 2 + 5) & 127;
        aux ^= (scale_43 & 15);
    } else {
        acc = (acc - scale_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_53 = local_arr[aux % 3];
    acc = (acc + residue_53 * 2) & 127;
    int window_57 = (aux + st.buffer[1]) & 3;
    switch (window_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_69 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_69 > 40) {
        acc = (acc + mask_69 * 2 + 5) & 127;
        aux ^= (mask_69 & 15);
    } else {
        acc = (acc - mask_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_20 = (aux + st.buffer[1]) & 3;
    switch (window_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000943_4313_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000943_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_28) & 63;
    acc ^= aux;
    int threshold_29 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_29 > 46) {
        acc = (acc + threshold_29 * 2 + 5) & 127;
        aux ^= (threshold_29 & 15);
    } else {
        acc = (acc - threshold_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000943_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_79 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_79 > 23) {
        acc = (acc + scale_79 * 2 + 5) & 127;
        aux ^= (scale_79 & 15);
    } else {
        acc = (acc - scale_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_61 = local_arr[aux % 3];
    acc = (acc + quantum_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_6(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000943_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_45 = (aux + st.buffer[1]) & 3;
    switch (damping_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_58 = local_arr[aux % 3];
    acc = (acc + coefficient_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_7(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_18 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_18 > 48) {
        acc = (acc + accumulator_18 * 2 + 5) & 127;
        aux ^= (accumulator_18 & 15);
    } else {
        acc = (acc - accumulator_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_57 = local_arr[aux % 3];
    acc = (acc + coefficient_57 * 2) & 127;
    int metric_32 = (aux + st.buffer[1]) & 3;
    switch (metric_32) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int margin_22 = (aux + st.buffer[1]) & 3;
    switch (margin_22) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_31 = local_arr[aux % 3];
    acc = (acc + damping_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_9(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_30 = local_arr[aux % 3];
    acc = (acc + bound_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_10(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int vector_18 = local_arr[aux % 3];
    acc = (acc + vector_18 * 2) & 127;
    int scale_39 = (aux + st.buffer[1]) & 3;
    switch (scale_39) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_11(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_88 = (aux + st.buffer[1]) & 3;
    switch (anchor_88) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_10 = local_arr[aux % 3];
    acc = (acc + threshold_10 * 2) & 127;
    int tally_65 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_65 > 50) {
        acc = (acc + tally_65 * 2 + 5) & 127;
        aux ^= (tally_65 & 15);
    } else {
        acc = (acc - tally_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_12(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int phase_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_84) & 63;
    acc ^= aux;
    int stride_92 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_92 > 19) {
        acc = (acc + stride_92 * 2 + 5) & 127;
        aux ^= (stride_92 & 15);
    } else {
        acc = (acc - stride_92 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_81 = local_arr[aux % 3];
    acc = (acc + metric_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_13(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_54 = local_arr[aux % 3];
    acc = (acc + coefficient_54 * 2) & 127;
    int anchor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_30 > 49) {
        acc = (acc + anchor_30 * 2 + 5) & 127;
        aux ^= (anchor_30 & 15);
    } else {
        acc = (acc - anchor_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000943_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int parity_38 = local_arr[aux % 3];
    acc = (acc + parity_38 * 2) & 127;
    int delta_36 = (aux + st.buffer[1]) & 3;
    switch (delta_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int metric_92 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_92 > 33) {
        acc = (acc + metric_92 * 2 + 5) & 127;
        aux ^= (metric_92 & 15);
    } else {
        acc = (acc - metric_92 + 11) & 127;
        aux += 3;
    }
    int parity_69 = (aux + st.buffer[1]) & 3;
    switch (parity_69) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000943_4313_16(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000943_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int accumulator_72 = local_arr[aux % 3];
    acc = (acc + accumulator_72 * 2) & 127;
    int coefficient_86 = (aux + st.buffer[1]) & 3;
    switch (coefficient_86) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_93 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_93 > 27) {
        acc = (acc + factor_93 * 2 + 5) & 127;
        aux ^= (factor_93 & 15);
    } else {
        acc = (acc - factor_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000943_4313_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000943_4313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_83 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_83 > 50) {
        acc = (acc + threshold_83 * 2 + 5) & 127;
        aux ^= (threshold_83 & 15);
    } else {
        acc = (acc - threshold_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_44 = local_arr[aux % 3];
    acc = (acc + index_reg_44 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000943_0;
    int sec_r000943_1;
    int sec_r000943_2;
    int sec_r000943_3;
    int sec_r000943_4;
    int sec_r000943_5;
    int sec_r000943_6;
    int sec_r000943_7;
    int sec_r000943_8;
    int sec_r000943_9;
    int sec_r000943_10;
    int sec_r000943_11;
    int sec_r000943_12;
    int sec_r000943_13;
    int sec_r000943_14;
    int sec_r000943_15;
    int pub_r000943_0;
    int pub_r000943_1;
    int pub_r000943_2;
    int pub_r000943_3;
    int pub_r000943_4;
    int pub_r000943_5;
    int pub_r000943_6;
    int pub_r000943_7;
    int pub_r000943_8;
    int pub_r000943_9;
    int pub_r000943_10;
    int pub_r000943_11;
    int pub_r000943_12;
    int pub_r000943_13;
    int pub_r000943_14;
    int pub_r000943_15;
    int pub_r000943_16;
    int pub_r000943_17;
    int pub_r000943_18;
    int pub_r000943_19;
    int pub_r000943_20;
    int pub_r000943_21;
    int pub_r000943_22;
    int pub_r000943_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000943_0 >= -100 && pub_r000943_0 <= 100);
    __CPROVER_assume(pub_r000943_1 >= -100 && pub_r000943_1 <= 100);
    __CPROVER_assume(pub_r000943_2 >= -100 && pub_r000943_2 <= 100);
    __CPROVER_assume(pub_r000943_3 >= -100 && pub_r000943_3 <= 100);
    __CPROVER_assume(pub_r000943_4 >= -100 && pub_r000943_4 <= 100);
    __CPROVER_assume(pub_r000943_5 >= -100 && pub_r000943_5 <= 100);
    __CPROVER_assume(pub_r000943_6 >= -100 && pub_r000943_6 <= 100);
    __CPROVER_assume(pub_r000943_7 >= -100 && pub_r000943_7 <= 100);
    __CPROVER_assume(pub_r000943_8 >= -100 && pub_r000943_8 <= 100);
    __CPROVER_assume(pub_r000943_9 >= -100 && pub_r000943_9 <= 100);
    __CPROVER_assume(pub_r000943_10 >= -100 && pub_r000943_10 <= 100);
    __CPROVER_assume(pub_r000943_11 >= -100 && pub_r000943_11 <= 100);
    __CPROVER_assume(pub_r000943_12 >= -100 && pub_r000943_12 <= 100);
    __CPROVER_assume(pub_r000943_13 >= -100 && pub_r000943_13 <= 100);
    __CPROVER_assume(pub_r000943_14 >= -100 && pub_r000943_14 <= 100);
    __CPROVER_assume(pub_r000943_15 >= -100 && pub_r000943_15 <= 100);
    __CPROVER_assume(pub_r000943_16 >= -100 && pub_r000943_16 <= 100);
    __CPROVER_assume(pub_r000943_17 >= -100 && pub_r000943_17 <= 100);
    __CPROVER_assume(pub_r000943_18 >= -100 && pub_r000943_18 <= 100);
    __CPROVER_assume(pub_r000943_19 >= -100 && pub_r000943_19 <= 100);
    __CPROVER_assume(pub_r000943_20 >= -100 && pub_r000943_20 <= 100);
    __CPROVER_assume(pub_r000943_21 >= -100 && pub_r000943_21 <= 100);
    __CPROVER_assume(pub_r000943_22 >= -100 && pub_r000943_22 <= 100);
    __CPROVER_assume(pub_r000943_23 >= -100 && pub_r000943_23 <= 100);
    __CPROVER_assume(sec_r000943_0 >= 0 && sec_r000943_0 <= 255);
    __CPROVER_assume(sec_r000943_1 >= 0 && sec_r000943_1 <= 255);
    __CPROVER_assume(sec_r000943_2 >= 0 && sec_r000943_2 <= 255);
    __CPROVER_assume(sec_r000943_3 >= 0 && sec_r000943_3 <= 255);
    __CPROVER_assume(sec_r000943_4 >= 0 && sec_r000943_4 <= 255);
    __CPROVER_assume(sec_r000943_5 >= 0 && sec_r000943_5 <= 255);
    __CPROVER_assume(sec_r000943_6 >= 0 && sec_r000943_6 <= 255);
    __CPROVER_assume(sec_r000943_7 >= 0 && sec_r000943_7 <= 255);
    __CPROVER_assume(sec_r000943_8 >= 0 && sec_r000943_8 <= 255);
    __CPROVER_assume(sec_r000943_9 >= 0 && sec_r000943_9 <= 255);
    __CPROVER_assume(sec_r000943_10 >= 0 && sec_r000943_10 <= 255);
    __CPROVER_assume(sec_r000943_11 >= 0 && sec_r000943_11 <= 255);
    __CPROVER_assume(sec_r000943_12 >= 0 && sec_r000943_12 <= 255);
    __CPROVER_assume(sec_r000943_13 >= 0 && sec_r000943_13 <= 255);
    __CPROVER_assume(sec_r000943_14 >= 0 && sec_r000943_14 <= 255);
    __CPROVER_assume(sec_r000943_15 >= 0 && sec_r000943_15 <= 255);

    struct Transaction_R000943_4313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000943_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000943_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000943_0 + 7) & 15;
    struct SensorNode_R000943_4313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000943_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000943_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000943_0 + 9) & 15;
    struct Vector3D_R000943_4313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000943_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000943_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000943_0 + 11) & 15;

    union TelemetryField_R000943_4313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 11) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 26) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 17) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 32) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 30) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 45) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 38) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 53) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 35) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 50) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

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
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 15) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 30) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 13) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 28) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (sec_r000943_11 + pub_r000943_19 + 19) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (stage_v_72 + pub_r000943_10 + 26) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000943_3) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (stage_v_73 + pub_r000943_23 + 18) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000943_22) & 127;
    st_var_2.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (sec_r000943_10 + pub_r000943_0 + 21) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (stage_v_75 + pub_r000943_8 + 28) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000943_2) & 127;
    st_var_1.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (stage_v_76 + pub_r000943_3 + 8) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000943_18) & 127;
    st_var_2.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (sec_r000943_6 + pub_r000943_17 + 30) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sub_step_73 + pub_r000943_12 + 30) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000943_23) & 127;
    st_var_1.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (stage_v_74 + pub_r000943_4 + 11) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000943_12) & 127;
    st_var_2.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sub_step_72 + pub_r000943_7 + 16) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (stage_v_79 + pub_r000943_1 + 18) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000943_0) & 127;
    st_var_1.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (sub_step_78 + pub_r000943_1 + 23) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000943_23) & 127;
    st_var_2.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sec_r000943_3 + pub_r000943_11 + 18) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000943_20) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sub_step_83 + pub_r000943_23 + 26) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sub_step_72 + pub_r000943_7 + 8) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000943_22) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (stage_v_75 + pub_r000943_22 + 24) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000943_12) & 127;
    st_var_0.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (stage_v_72 + pub_r000943_12 + 8) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000943_3) & 127;
    st_var_1.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sec_r000943_2 + pub_r000943_22 + 23) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000943_13) & 127;
    st_var_2.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (stage_v_72 + pub_r000943_15 + 8) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000943_10) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (stage_v_76 + pub_r000943_12 + 20) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000943_11) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sec_r000943_7 + pub_r000943_20 + 26) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000943_2) & 127;
    st_var_2.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sec_r000943_0 + pub_r000943_22 + 31) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000943_7) & 127;
    st_var_0.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000943_1 + pub_r000943_9 + 20) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (stage_v_79 + pub_r000943_16 + 23) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000943_3) & 127;
    st_var_2.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000943_13 + pub_r000943_6 + 26) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000943_15) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sub_step_89 + pub_r000943_7 + 14) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sec_r000943_14 + pub_r000943_5 + 14) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000943_16) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sub_step_76 + pub_r000943_16 + 17) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sub_step_92 + pub_r000943_0 + 8) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000943_22) & 127;
    st_var_1.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (stage_v_95 + pub_r000943_13 + 12) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000943_1) & 127;
    st_var_2.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000943_1 + pub_r000943_7 + 28) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000943_9) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000943_14 + pub_r000943_20 + 5) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sec_r000943_12 + pub_r000943_8 + 16) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000943_3) & 127;
    st_var_2.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (stage_v_75 + pub_r000943_20 + 22) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000943_5) & 127;
    st_var_0.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_96 + pub_r000943_1 + 35) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000943_2) & 127;
    st_var_1.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sub_step_84 + pub_r000943_21 + 34) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000943_8) & 127;
    st_var_2.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sec_r000943_10 + pub_r000943_19 + 17) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000943_14) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sub_step_95 + pub_r000943_11 + 32) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_99 + pub_r000943_12 + 16) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000943_6) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sub_step_105 + pub_r000943_17 + 24) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000943_11) & 127;
    st_var_0.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000943_0 + pub_r000943_7 + 17) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000943_0) & 127;
    st_var_1.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000943_2 + pub_r000943_10 + 14) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000943_12) & 127;
    st_var_2.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sec_r000943_10 + pub_r000943_15 + 9) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000943_4) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_114 + pub_r000943_6 + 8) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000943_3) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sub_step_97 + pub_r000943_15 + 35) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000943_1) & 127;
    st_var_2.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_80 + pub_r000943_0 + 17) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000943_20) & 127;
    st_var_0.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_90 + pub_r000943_13 + 23) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000943_21) & 127;
    st_var_1.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sub_step_108 + pub_r000943_0 + 19) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000943_6) & 127;
    st_var_2.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (stage_v_116 + pub_r000943_9 + 7) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000943_2) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sub_step_99 + pub_r000943_6 + 9) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000943_19) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (stage_v_102 + pub_r000943_7 + 14) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000943_13) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000943_14 + pub_r000943_17 + 23) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000943_22) & 127;
    st_var_0.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sec_r000943_13 + pub_r000943_19 + 28) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sub_step_109 + pub_r000943_11 + 24) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000943_5) & 127;
    st_var_2.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_75 + pub_r000943_16 + 30) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000943_6) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sec_r000943_10 + pub_r000943_13 + 27) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000943_1) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (sub_step_105 + pub_r000943_18 + 5) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000943_16) & 127;
    st_var_2.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sub_step_108 + pub_r000943_23 + 11) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000943_4) & 127;
    st_var_0.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sec_r000943_15 + pub_r000943_23 + 29) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000943_21) & 127;
    st_var_1.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sub_step_118 + pub_r000943_22 + 7) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000943_2) & 127;
    st_var_2.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_99 + pub_r000943_18 + 19) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000943_9) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sec_r000943_10 + pub_r000943_20 + 16) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000943_3) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sec_r000943_8 + pub_r000943_0 + 22) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000943_23) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sec_r000943_13 + pub_r000943_5 + 13) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000943_4) & 127;
    st_var_0.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (stage_v_101 + pub_r000943_7 + 33) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000943_5) & 127;
    st_var_1.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (stage_v_85 + pub_r000943_7 + 17) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000943_15) & 127;
    st_var_2.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sec_r000943_15 + pub_r000943_6 + 20) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sec_r000943_8 + pub_r000943_22 + 19) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000943_17) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sec_r000943_3 + pub_r000943_10 + 32) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000943_19) & 127;
    st_var_2.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sub_step_118 + pub_r000943_15 + 26) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000943_12) & 127;
    st_var_0.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sec_r000943_0 + pub_r000943_19 + 22) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000943_6) & 127;
    st_var_1.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (stage_v_80 + pub_r000943_18 + 28) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000943_18) & 127;
    st_var_2.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_136 + pub_r000943_19 + 16) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_79 + pub_r000943_5 + 32) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000943_23) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sec_r000943_3 + pub_r000943_5 + 34) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000943_1) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sec_r000943_7 + pub_r000943_10 + 16) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000943_5 + pub_r000943_22 + 28) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000943_11) & 127;
    st_var_1.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_79 + pub_r000943_23 + 30) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000943_16) & 127;
    st_var_2.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sec_r000943_2 + pub_r000943_5 + 22) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000943_18) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000943_12 + pub_r000943_15 + 34) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000943_21) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sub_step_145 + pub_r000943_5 + 22) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000943_5) & 127;
    st_var_2.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_117 + pub_r000943_17 + 26) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000943_2) & 127;
    st_var_0.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sub_step_85 + pub_r000943_12 + 29) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sub_step_126 + pub_r000943_8 + 31) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000943_14) & 127;
    st_var_2.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sub_step_105 + pub_r000943_18 + 22) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000943_5) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sec_r000943_6 + pub_r000943_5 + 15) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000943_17) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_148 + pub_r000943_12 + 28) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000943_14) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sub_step_110 + pub_r000943_16 + 29) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000943_16) & 127;
    st_var_0.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sec_r000943_9 + pub_r000943_14 + 15) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000943_22) & 127;
    st_var_1.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sec_r000943_11 + pub_r000943_5 + 29) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000943_15) & 127;
    st_var_2.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sec_r000943_4 + pub_r000943_3 + 28) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000943_9) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (stage_v_145 + pub_r000943_3 + 18) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000943_11 + pub_r000943_1 + 8) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000943_19) & 127;
    st_var_2.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sec_r000943_7 + pub_r000943_6 + 34) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000943_18) & 127;
    st_var_0.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (stage_v_107 + pub_r000943_8 + 31) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000943_1) & 127;
    st_var_1.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sub_step_154 + pub_r000943_6 + 23) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000943_23) & 127;
    st_var_2.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sec_r000943_8 + pub_r000943_19 + 26) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000943_12) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sec_r000943_15 + pub_r000943_17 + 14) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000943_19) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sec_r000943_15 + pub_r000943_0 + 14) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000943_19) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (stage_v_119 + pub_r000943_19 + 7) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000943_5) & 127;
    st_var_0.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sub_step_171 + pub_r000943_6 + 16) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000943_13) & 127;
    st_var_1.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (stage_v_92 + pub_r000943_12 + 16) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000943_22) & 127;
    st_var_2.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (stage_v_116 + pub_r000943_20 + 15) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000943_9) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_99 + pub_r000943_20 + 14) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000943_20) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (stage_v_173 + pub_r000943_15 + 22) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000943_18) & 127;
    st_var_2.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sec_r000943_8 + pub_r000943_21 + 28) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000943_4) & 127;
    st_var_0.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sec_r000943_14 + pub_r000943_12 + 27) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000943_6) & 127;
    st_var_1.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000943_14 + pub_r000943_3 + 19) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000943_8) & 127;
    st_var_2.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sub_step_168 + pub_r000943_11 + 26) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000943_20) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sub_step_141 + pub_r000943_4 + 30) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000943_0) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (stage_v_142 + pub_r000943_4 + 21) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000943_17) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000943_8 + pub_r000943_8 + 19) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (stage_v_129 + pub_r000943_20 + 14) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000943_2) & 127;
    st_var_1.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000943_13 + pub_r000943_17 + 15) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000943_21) & 127;
    st_var_2.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000943_3 + pub_r000943_22 + 19) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000943_11) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (stage_v_102 + pub_r000943_20 + 32) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000943_13) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (stage_v_124 + pub_r000943_2 + 34) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000943_0) & 127;
    st_var_2.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (stage_v_161 + pub_r000943_19 + 31) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000943_12) & 127;
    st_var_0.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sec_r000943_10 + pub_r000943_1 + 35) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000943_4) & 127;
    st_var_1.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_163 + pub_r000943_19 + 26) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000943_9) & 127;
    st_var_2.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sec_r000943_4 + pub_r000943_23 + 24) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000943_14) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000943_1 + pub_r000943_13 + 32) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000943_10) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_86 + pub_r000943_7 + 9) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000943_16) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000943_7 + pub_r000943_20 + 20) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000943_13) & 127;
    st_var_0.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_110 + pub_r000943_10 + 18) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000943_10) & 127;
    st_var_1.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sub_step_95 + pub_r000943_12 + 26) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000943_10) & 127;
    st_var_2.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sec_r000943_11 + pub_r000943_9 + 17) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000943_3) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_72 + pub_r000943_0 + 15) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000943_8) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_185 + pub_r000943_18 + 21) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000943_10) & 127;
    st_var_2.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (stage_v_93 + pub_r000943_4 + 17) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000943_7) & 127;
    st_var_0.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sec_r000943_12 + pub_r000943_5 + 33) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sec_r000943_7 + pub_r000943_16 + 16) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000943_22) & 127;
    st_var_2.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000943_1 + pub_r000943_12 + 29) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000943_11) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (stage_v_182 + pub_r000943_11 + 12) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sub_step_92 + pub_r000943_6 + 14) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000943_10) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (stage_v_127 + pub_r000943_0 + 30) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000943_15) & 127;
    st_var_0.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000943_8 + pub_r000943_14 + 14) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000943_22) & 127;
    st_var_1.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sub_step_138 + pub_r000943_8 + 10) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000943_19) & 127;
    st_var_2.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (stage_v_108 + pub_r000943_23 + 9) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000943_1) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (stage_v_169 + pub_r000943_6 + 14) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000943_7) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sec_r000943_10 + pub_r000943_2 + 35) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000943_3) & 127;
    st_var_2.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sub_step_167 + pub_r000943_18 + 21) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000943_0) & 127;
    st_var_0.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_199 + pub_r000943_4 + 11) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000943_15) & 127;
    st_var_1.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (stage_v_115 + pub_r000943_22 + 35) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000943_13) & 127;
    st_var_2.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000943_7 + pub_r000943_9 + 21) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000943_13) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sec_r000943_3 + pub_r000943_2 + 13) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000943_21) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_94 + pub_r000943_8 + 31) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000943_14) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sub_step_214 + pub_r000943_7 + 30) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_130 + pub_r000943_13 + 5) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000943_23) & 127;
    st_var_1.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (stage_v_119 + pub_r000943_11 + 21) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000943_22) & 127;
    st_var_2.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sec_r000943_6 + pub_r000943_7 + 21) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000943_18) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000943_0 + pub_r000943_12 + 31) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000943_13) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sub_step_80 + pub_r000943_15 + 14) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000943_16) & 127;
    st_var_2.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (stage_v_113 + pub_r000943_14 + 20) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000943_2) & 127;
    st_var_0.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sub_step_225 + pub_r000943_8 + 5) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000943_1) & 127;
    st_var_1.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sec_r000943_11 + pub_r000943_7 + 11) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000943_3) & 127;
    st_var_2.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (sub_step_179 + pub_r000943_20 + 30) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000943_15) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (stage_v_90 + pub_r000943_7 + 20) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000943_13) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sub_step_173 + pub_r000943_3 + 13) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000943_7) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sub_step_140 + pub_r000943_3 + 33) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000943_23) & 127;
    st_var_0.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sec_r000943_1 + pub_r000943_22 + 30) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000943_8) & 127;
    st_var_1.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sec_r000943_13 + pub_r000943_5 + 8) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000943_17) & 127;
    st_var_2.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sec_r000943_14 + pub_r000943_8 + 6) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000943_1) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_137 + pub_r000943_2 + 5) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000943_14) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_223 + pub_r000943_20 + 6) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000943_15) & 127;
    st_var_2.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (sub_step_156 + pub_r000943_12 + 9) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000943_11) & 127;
    st_var_0.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (stage_v_91 + pub_r000943_22 + 15) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000943_7) & 127;
    st_var_1.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (stage_v_231 + pub_r000943_21 + 24) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000943_12) & 127;
    st_var_2.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sub_step_116 + pub_r000943_2 + 35) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000943_22) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_99 + pub_r000943_10 + 32) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000943_16) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000943_4 + pub_r000943_19 + 13) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000943_19) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (stage_v_105 + pub_r000943_11 + 8) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000943_9) & 127;
    st_var_0.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (stage_v_88 + pub_r000943_2 + 31) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000943_0) & 127;
    st_var_1.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000943_0 + pub_r000943_3 + 10) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000943_0) & 127;
    st_var_2.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (stage_v_146 + pub_r000943_2 + 25) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000943_21) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (sub_step_120 + pub_r000943_21 + 25) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000943_4) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sub_step_141 + pub_r000943_1 + 23) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000943_2) & 127;
    st_var_2.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (stage_v_168 + pub_r000943_2 + 14) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000943_7) & 127;
    st_var_0.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (stage_v_89 + pub_r000943_22 + 30) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000943_13) & 127;
    st_var_1.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (stage_v_190 + pub_r000943_0 + 20) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000943_14) & 127;
    st_var_2.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sub_step_247 + pub_r000943_18 + 19) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000943_5) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (sec_r000943_15 + pub_r000943_16 + 5) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000943_6) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sub_step_185 + pub_r000943_6 + 23) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000943_2) & 127;
    st_var_2.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sub_step_86 + pub_r000943_20 + 10) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000943_8) & 127;
    st_var_0.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sec_r000943_12 + pub_r000943_12 + 24) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000943_18) & 127;
    st_var_1.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (stage_v_173 + pub_r000943_11 + 13) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000943_1) & 127;
    st_var_2.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (sub_step_75 + pub_r000943_12 + 19) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000943_5) & 127;
    st_var_0.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (sec_r000943_5 + pub_r000943_11 + 28) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000943_0) & 127;
    st_var_1.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
