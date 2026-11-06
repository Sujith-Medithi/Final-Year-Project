/*
 * Benchmark Program: R000538
 * Security Family: secret_dependent_loops
 * Generator Seed: 553813
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000538_3813_0 {
    unsigned char auth_code;
    int account_id;
    short balance;
    int status;
    int buffer[3];
};

struct SensorNode_R000538_3813_1 {
    short reading;
    unsigned char calib;
    short gain;
    int buffer[3];
};

struct MatrixBlock_R000538_3813_2 {
    short trace;
    unsigned char determinant;
    int scale;
    int density;
    int stride;
    short dim;
    int buffer[3];
};

struct EventLog_R000538_3813_3 {
    unsigned char timestamp;
    int code;
    int severity;
    short facility;
    int buffer[3];
};

union PacketPayload_R000538_3813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000538_3813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000538_3813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_76 = local_arr[aux % 3];
    acc = (acc + pivot_76 * 2) & 127;
    int checksum_97 = (aux + st.buffer[1]) & 3;
    switch (checksum_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_98 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_98 > 49) {
        acc = (acc + parity_98 * 2 + 5) & 127;
        aux ^= (parity_98 & 15);
    } else {
        acc = (acc - parity_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000538_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_74 = (aux + st.buffer[1]) & 3;
    switch (sample_74) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000538_3813_2(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_43 = local_arr[aux % 3];
    acc = (acc + anchor_43 * 2) & 127;
    int weight_41 = (aux + st.buffer[1]) & 3;
    switch (weight_41) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_46 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_46 > 48) {
        acc = (acc + mask_46 * 2 + 5) & 127;
        aux ^= (mask_46 & 15);
    } else {
        acc = (acc - mask_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000538_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_95) & 63;
    acc ^= aux;
    int stride_10 = (aux + st.buffer[1]) & 3;
    switch (stride_10) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000538_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int coefficient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_78 > 36) {
        acc = (acc + coefficient_78 * 2 + 5) & 127;
        aux ^= (coefficient_78 & 15);
    } else {
        acc = (acc - coefficient_78 + 11) & 127;
        aux += 3;
    }
    int index_reg_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_64) & 63;
    acc ^= aux;
    int segment_98 = (aux + st.buffer[1]) & 3;
    switch (segment_98) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_94 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_94 > 26) {
        acc = (acc + metric_94 * 2 + 5) & 127;
        aux ^= (metric_94 & 15);
    } else {
        acc = (acc - metric_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_6(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000538_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int stride_18 = local_arr[aux % 3];
    acc = (acc + stride_18 * 2) & 127;
    int quantum_91 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_91 > 42) {
        acc = (acc + quantum_91 * 2 + 5) & 127;
        aux ^= (quantum_91 & 15);
    } else {
        acc = (acc - quantum_91 + 11) & 127;
        aux += 3;
    }
    int segment_10 = (aux + st.buffer[1]) & 3;
    switch (segment_10) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000538_3813_7(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_66 = local_arr[aux % 3];
    acc = (acc + offset_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_8(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000538_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int phase_63 = local_arr[aux % 3];
    acc = (acc + phase_63 * 2) & 127;
    int damping_57 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_57 > 31) {
        acc = (acc + damping_57 * 2 + 5) & 127;
        aux ^= (damping_57 & 15);
    } else {
        acc = (acc - damping_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000538_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_48) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_21 = local_arr[aux % 3];
    acc = (acc + stride_21 * 2) & 127;
    int mask_51 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_51 > 50) {
        acc = (acc + mask_51 * 2 + 5) & 127;
        aux ^= (mask_51 & 15);
    } else {
        acc = (acc - mask_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000538_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int scale_38 = local_arr[aux % 3];
    acc = (acc + scale_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_43 = (aux + st.buffer[1]) & 3;
    switch (coefficient_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000538_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_36 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_36 > 12) {
        acc = (acc + scale_36 * 2 + 5) & 127;
        aux ^= (scale_36 & 15);
    } else {
        acc = (acc - scale_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_22 = local_arr[aux % 3];
    acc = (acc + phase_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_12(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000538_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_95 = local_arr[aux % 3];
    acc = (acc + cursor_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000538_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_48 = (aux + st.buffer[1]) & 3;
    switch (cursor_48) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_95 = local_arr[aux % 3];
    acc = (acc + metric_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_14(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int checksum_63 = local_arr[aux % 3];
    acc = (acc + checksum_63 * 2) & 127;
    int stride_67 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_67 > 30) {
        acc = (acc + stride_67 * 2 + 5) & 127;
        aux ^= (stride_67 & 15);
    } else {
        acc = (acc - stride_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000538_3813_15(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int pivot_24 = local_arr[aux % 3];
    acc = (acc + pivot_24 * 2) & 127;
    int tracker_97 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_97 > 47) {
        acc = (acc + tracker_97 * 2 + 5) & 127;
        aux ^= (tracker_97 & 15);
    } else {
        acc = (acc - tracker_97 + 11) & 127;
        aux += 3;
    }
    int scale_52 = (aux + st.buffer[1]) & 3;
    switch (scale_52) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000538_3813_16(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000538_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_48 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_48 > 38) {
        acc = (acc + segment_48 * 2 + 5) & 127;
        aux ^= (segment_48 & 15);
    } else {
        acc = (acc - segment_48 + 11) & 127;
        aux += 3;
    }
    int residue_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000538_3813_17(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000538_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_89) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_72 = local_arr[aux % 3];
    acc = (acc + scale_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000538_3813_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000538_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_72) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000538_0;
    int sec_r000538_1;
    int sec_r000538_2;
    int sec_r000538_3;
    int sec_r000538_4;
    int sec_r000538_5;
    int sec_r000538_6;
    int sec_r000538_7;
    int sec_r000538_8;
    int sec_r000538_9;
    int sec_r000538_10;
    int sec_r000538_11;
    int sec_r000538_12;
    int sec_r000538_13;
    int sec_r000538_14;
    int sec_r000538_15;
    int pub_r000538_0;
    int pub_r000538_1;
    int pub_r000538_2;
    int pub_r000538_3;
    int pub_r000538_4;
    int pub_r000538_5;
    int pub_r000538_6;
    int pub_r000538_7;
    int pub_r000538_8;
    int pub_r000538_9;
    int pub_r000538_10;
    int pub_r000538_11;
    int pub_r000538_12;
    int pub_r000538_13;
    int pub_r000538_14;
    int pub_r000538_15;
    int pub_r000538_16;
    int pub_r000538_17;
    int pub_r000538_18;
    int pub_r000538_19;
    int pub_r000538_20;
    int pub_r000538_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000538_0 >= -100 && pub_r000538_0 <= 100);
    __CPROVER_assume(pub_r000538_1 >= -100 && pub_r000538_1 <= 100);
    __CPROVER_assume(pub_r000538_2 >= -100 && pub_r000538_2 <= 100);
    __CPROVER_assume(pub_r000538_3 >= -100 && pub_r000538_3 <= 100);
    __CPROVER_assume(pub_r000538_4 >= -100 && pub_r000538_4 <= 100);
    __CPROVER_assume(pub_r000538_5 >= -100 && pub_r000538_5 <= 100);
    __CPROVER_assume(pub_r000538_6 >= -100 && pub_r000538_6 <= 100);
    __CPROVER_assume(pub_r000538_7 >= -100 && pub_r000538_7 <= 100);
    __CPROVER_assume(pub_r000538_8 >= -100 && pub_r000538_8 <= 100);
    __CPROVER_assume(pub_r000538_9 >= -100 && pub_r000538_9 <= 100);
    __CPROVER_assume(pub_r000538_10 >= -100 && pub_r000538_10 <= 100);
    __CPROVER_assume(pub_r000538_11 >= -100 && pub_r000538_11 <= 100);
    __CPROVER_assume(pub_r000538_12 >= -100 && pub_r000538_12 <= 100);
    __CPROVER_assume(pub_r000538_13 >= -100 && pub_r000538_13 <= 100);
    __CPROVER_assume(pub_r000538_14 >= -100 && pub_r000538_14 <= 100);
    __CPROVER_assume(pub_r000538_15 >= -100 && pub_r000538_15 <= 100);
    __CPROVER_assume(pub_r000538_16 >= -100 && pub_r000538_16 <= 100);
    __CPROVER_assume(pub_r000538_17 >= -100 && pub_r000538_17 <= 100);
    __CPROVER_assume(pub_r000538_18 >= -100 && pub_r000538_18 <= 100);
    __CPROVER_assume(pub_r000538_19 >= -100 && pub_r000538_19 <= 100);
    __CPROVER_assume(pub_r000538_20 >= -100 && pub_r000538_20 <= 100);
    __CPROVER_assume(pub_r000538_21 >= -100 && pub_r000538_21 <= 100);
    __CPROVER_assume(sec_r000538_0 >= 0 && sec_r000538_0 <= 255);
    __CPROVER_assume(sec_r000538_1 >= 0 && sec_r000538_1 <= 255);
    __CPROVER_assume(sec_r000538_2 >= 0 && sec_r000538_2 <= 255);
    __CPROVER_assume(sec_r000538_3 >= 0 && sec_r000538_3 <= 255);
    __CPROVER_assume(sec_r000538_4 >= 0 && sec_r000538_4 <= 255);
    __CPROVER_assume(sec_r000538_5 >= 0 && sec_r000538_5 <= 255);
    __CPROVER_assume(sec_r000538_6 >= 0 && sec_r000538_6 <= 255);
    __CPROVER_assume(sec_r000538_7 >= 0 && sec_r000538_7 <= 255);
    __CPROVER_assume(sec_r000538_8 >= 0 && sec_r000538_8 <= 255);
    __CPROVER_assume(sec_r000538_9 >= 0 && sec_r000538_9 <= 255);
    __CPROVER_assume(sec_r000538_10 >= 0 && sec_r000538_10 <= 255);
    __CPROVER_assume(sec_r000538_11 >= 0 && sec_r000538_11 <= 255);
    __CPROVER_assume(sec_r000538_12 >= 0 && sec_r000538_12 <= 255);
    __CPROVER_assume(sec_r000538_13 >= 0 && sec_r000538_13 <= 255);
    __CPROVER_assume(sec_r000538_14 >= 0 && sec_r000538_14 <= 255);
    __CPROVER_assume(sec_r000538_15 >= 0 && sec_r000538_15 <= 255);

    struct Transaction_R000538_3813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000538_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000538_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000538_0 + 7) & 15;
    struct SensorNode_R000538_3813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000538_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000538_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000538_0 + 9) & 15;
    struct MatrixBlock_R000538_3813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000538_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000538_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000538_0 + 11) & 15;
    struct EventLog_R000538_3813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000538_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000538_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000538_0 + 13) & 15;

    union PacketPayload_R000538_3813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 21) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 36) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_33 = (stage_v_33 + step * 4 + pub_r000538_0) & 63;
        } else {
            stage_v_33 = (stage_v_33 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_15 & 1) == step) {
            stage_v_34 = (stage_v_34 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_34 = (stage_v_34 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_35 = (stage_v_35 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_35 = (stage_v_35 + pub_r000538_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_35 & 1) == step) {
            stage_v_36 = (stage_v_36 + step * 4 + pub_r000538_11) & 63;
        } else {
            stage_v_36 = (stage_v_36 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_37 = (stage_v_37 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_37 = (stage_v_37 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_13 & 1) == step) {
            stage_v_38 = (stage_v_38 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_38 = (stage_v_38 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_39 = (stage_v_39 + step * 4 + pub_r000538_13) & 63;
        } else {
            stage_v_39 = (stage_v_39 + pub_r000538_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_8 & 1) == step) {
            stage_v_40 = (stage_v_40 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_40 = (stage_v_40 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_37 & 1) == step) {
            stage_v_41 = (stage_v_41 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_41 = (stage_v_41 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_42 = (stage_v_42 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_42 = (stage_v_42 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_35 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000538_6) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000538_5) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000538_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000538_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_7 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_11 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_35 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000538_0) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_36 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000538_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000538_11) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_15 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000538_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_4 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_2 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000538_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000538_0) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000538_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000538_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000538_3) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000538_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_48 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000538_10) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000538_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000538_3) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000538_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000538_0) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000538_13) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000538_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000538_12) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_37 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000538_5) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000538_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000538_21) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000538_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_7 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000538_3) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000538_13) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_13 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000538_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000538_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_2 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_38 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_4 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_8 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000538_21) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000538_15) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000538_1) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000538_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_11 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000538_10) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000538_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_12 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000538_6) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000538_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_6 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000538_13) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000538_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000538_12) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000538_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_0 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000538_18) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000538_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_13 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000538_1) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000538_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000538_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_10 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000538_20) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000538_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_13 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000538_6) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000538_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_107 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000538_6) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000538_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_8 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000538_1) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000538_16) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000538_11) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_7 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000538_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_10 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_0 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000538_15) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000538_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000538_11) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_9 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_2 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000538_3) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_9 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000538_3) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000538_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000538_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000538_6) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000538_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000538_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000538_10) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_11 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000538_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000538_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000538_18) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000538_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_13 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000538_1) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000538_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_8 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000538_18) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000538_19) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000538_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000538_12) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000538_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_1 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000538_0) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000538_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_4 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000538_10) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000538_21) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000538_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000538_18) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000538_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000538_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000538_1) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000538_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000538_8) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000538_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000538_15) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000538_14) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000538_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_14 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000538_9) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000538_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000538_12 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000538_4) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000538_7) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000538_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000538_21) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000538_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000538_2) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000538_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000538_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000538_17) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000538_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
