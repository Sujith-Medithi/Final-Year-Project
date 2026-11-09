/*
 * Benchmark Program: R001530
 * Security Family: mixed_control_data
 * Generator Seed: 653013
 * High Inputs: 24 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001530_3013_0 {
    unsigned char timestamp;
    int code;
    unsigned char signature;
    int buffer[3];
};

struct AudioFrame_R001530_3013_1 {
    short envelope;
    int peak;
    int rms;
    int buffer[3];
};

struct Vector3D_R001530_3013_2 {
    short coord_z;
    unsigned char pitch;
    int heading;
    int coord_x;
    int coord_y;
    int norm_sq;
    int buffer[3];
};

struct SensorNode_R001530_3013_3 {
    short threshold;
    int gain;
    unsigned char offset;
    int buffer[3];
};

union PacketPayload_R001530_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001530_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001530_3013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001530_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quantum_62 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_62 = (quantum_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_62) & 127;
    }
    int weight_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_21) & 63;
    acc ^= aux;
    int phase_78 = (aux + st.buffer[1]) & 3;
    switch (phase_78) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_1(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_64 = (aux + st.buffer[1]) & 3;
    switch (parity_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_46) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_93 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_93 = (quotient_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_2(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001530_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_16 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_16 > 49) {
        acc = (acc + parity_16 * 2 + 5) & 127;
        aux ^= (parity_16 & 15);
    } else {
        acc = (acc - parity_16 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_98 = 0;
    for (int k = 0; k < 3; k++) {
        delta_98 = (delta_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_98) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_82 = local_arr[aux % 3];
    acc = (acc + pivot_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001530_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int margin_58 = local_arr[aux % 3];
    acc = (acc + margin_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int vector_72 = 0;
    for (int k = 0; k < 3; k++) {
        vector_72 = (vector_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_72) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_43 = local_arr[aux % 3];
    acc = (acc + mask_43 * 2) & 127;
    int residue_12 = (aux + st.buffer[1]) & 3;
    switch (residue_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001530_3013_5(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int scale_12 = local_arr[aux % 3];
    acc = (acc + scale_12 * 2) & 127;
    int segment_87 = (aux + st.buffer[1]) & 3;
    switch (segment_87) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_6(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_86 = local_arr[aux % 3];
    acc = (acc + metric_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001530_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int window_82 = local_arr[aux % 3];
    acc = (acc + window_82 * 2) & 127;
    int mask_22 = (aux + st.buffer[1]) & 3;
    switch (mask_22) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_54 > 24) {
        acc = (acc + anchor_54 * 2 + 5) & 127;
        aux ^= (anchor_54 & 15);
    } else {
        acc = (acc - anchor_54 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001530_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_74) & 63;
    acc ^= aux;
    int sample_55 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_55 > 42) {
        acc = (acc + sample_55 * 2 + 5) & 127;
        aux ^= (sample_55 & 15);
    } else {
        acc = (acc - sample_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_80 = (aux + st.buffer[1]) & 3;
    switch (metric_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_9(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001530_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_67 = 0;
    for (int k = 0; k < 3; k++) {
        damping_67 = (damping_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_67) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_73 = local_arr[aux % 3];
    acc = (acc + parity_73 * 2) & 127;
    int tracker_21 = (aux + st.buffer[1]) & 3;
    switch (tracker_21) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_58 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_58 > 43) {
        acc = (acc + vector_58 * 2 + 5) & 127;
        aux ^= (vector_58 & 15);
    } else {
        acc = (acc - vector_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_11(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001530_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_31) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_37 = local_arr[aux % 3];
    acc = (acc + parity_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_12(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_96) & 63;
    acc ^= aux;
    int offset_26 = 0;
    for (int k = 0; k < 3; k++) {
        offset_26 = (offset_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001530_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int vector_42 = local_arr[aux % 3];
    acc = (acc + vector_42 * 2) & 127;
    int residue_88 = 0;
    for (int k = 0; k < 2; k++) {
        residue_88 = (residue_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int checksum_76 = local_arr[aux % 3];
    acc = (acc + checksum_76 * 2) & 127;
    int margin_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_10) & 63;
    acc ^= aux;
    int metric_52 = 0;
    for (int k = 0; k < 2; k++) {
        metric_52 = (metric_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001530_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_90 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_90 > 19) {
        acc = (acc + factor_90 * 2 + 5) & 127;
        aux ^= (factor_90 & 15);
    } else {
        acc = (acc - factor_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001530_3013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001530_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_64 = (aux + st.buffer[1]) & 3;
    switch (damping_64) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_73 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_73 > 15) {
        acc = (acc + vector_73 * 2 + 5) & 127;
        aux ^= (vector_73 & 15);
    } else {
        acc = (acc - vector_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001530_3013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001530_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_80 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_80 > 50) {
        acc = (acc + residue_80 * 2 + 5) & 127;
        aux ^= (residue_80 & 15);
    } else {
        acc = (acc - residue_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_39 = local_arr[aux % 3];
    acc = (acc + margin_39 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001530_0;
    int sec_r001530_1;
    int sec_r001530_2;
    int sec_r001530_3;
    int sec_r001530_4;
    int sec_r001530_5;
    int sec_r001530_6;
    int sec_r001530_7;
    int sec_r001530_8;
    int sec_r001530_9;
    int sec_r001530_10;
    int sec_r001530_11;
    int sec_r001530_12;
    int sec_r001530_13;
    int sec_r001530_14;
    int sec_r001530_15;
    int sec_r001530_16;
    int sec_r001530_17;
    int sec_r001530_18;
    int sec_r001530_19;
    int sec_r001530_20;
    int sec_r001530_21;
    int sec_r001530_22;
    int sec_r001530_23;
    int pub_r001530_0;
    int pub_r001530_1;
    int pub_r001530_2;
    int pub_r001530_3;
    int pub_r001530_4;
    int pub_r001530_5;
    int pub_r001530_6;
    int pub_r001530_7;
    int pub_r001530_8;
    int pub_r001530_9;
    int pub_r001530_10;
    int pub_r001530_11;
    int pub_r001530_12;
    int pub_r001530_13;
    int pub_r001530_14;
    int pub_r001530_15;
    int pub_r001530_16;
    int pub_r001530_17;
    int pub_r001530_18;
    int pub_r001530_19;
    int pub_r001530_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001530_0 >= -100 && pub_r001530_0 <= 100);
    __CPROVER_assume(pub_r001530_1 >= -100 && pub_r001530_1 <= 100);
    __CPROVER_assume(pub_r001530_2 >= -100 && pub_r001530_2 <= 100);
    __CPROVER_assume(pub_r001530_3 >= -100 && pub_r001530_3 <= 100);
    __CPROVER_assume(pub_r001530_4 >= -100 && pub_r001530_4 <= 100);
    __CPROVER_assume(pub_r001530_5 >= -100 && pub_r001530_5 <= 100);
    __CPROVER_assume(pub_r001530_6 >= -100 && pub_r001530_6 <= 100);
    __CPROVER_assume(pub_r001530_7 >= -100 && pub_r001530_7 <= 100);
    __CPROVER_assume(pub_r001530_8 >= -100 && pub_r001530_8 <= 100);
    __CPROVER_assume(pub_r001530_9 >= -100 && pub_r001530_9 <= 100);
    __CPROVER_assume(pub_r001530_10 >= -100 && pub_r001530_10 <= 100);
    __CPROVER_assume(pub_r001530_11 >= -100 && pub_r001530_11 <= 100);
    __CPROVER_assume(pub_r001530_12 >= -100 && pub_r001530_12 <= 100);
    __CPROVER_assume(pub_r001530_13 >= -100 && pub_r001530_13 <= 100);
    __CPROVER_assume(pub_r001530_14 >= -100 && pub_r001530_14 <= 100);
    __CPROVER_assume(pub_r001530_15 >= -100 && pub_r001530_15 <= 100);
    __CPROVER_assume(pub_r001530_16 >= -100 && pub_r001530_16 <= 100);
    __CPROVER_assume(pub_r001530_17 >= -100 && pub_r001530_17 <= 100);
    __CPROVER_assume(pub_r001530_18 >= -100 && pub_r001530_18 <= 100);
    __CPROVER_assume(pub_r001530_19 >= -100 && pub_r001530_19 <= 100);
    __CPROVER_assume(pub_r001530_20 >= -100 && pub_r001530_20 <= 100);
    __CPROVER_assume(sec_r001530_0 >= 0 && sec_r001530_0 <= 255);
    __CPROVER_assume(sec_r001530_1 >= 0 && sec_r001530_1 <= 255);
    __CPROVER_assume(sec_r001530_2 >= 0 && sec_r001530_2 <= 255);
    __CPROVER_assume(sec_r001530_3 >= 0 && sec_r001530_3 <= 255);
    __CPROVER_assume(sec_r001530_4 >= 0 && sec_r001530_4 <= 255);
    __CPROVER_assume(sec_r001530_5 >= 0 && sec_r001530_5 <= 255);
    __CPROVER_assume(sec_r001530_6 >= 0 && sec_r001530_6 <= 255);
    __CPROVER_assume(sec_r001530_7 >= 0 && sec_r001530_7 <= 255);
    __CPROVER_assume(sec_r001530_8 >= 0 && sec_r001530_8 <= 255);
    __CPROVER_assume(sec_r001530_9 >= 0 && sec_r001530_9 <= 255);
    __CPROVER_assume(sec_r001530_10 >= 0 && sec_r001530_10 <= 255);
    __CPROVER_assume(sec_r001530_11 >= 0 && sec_r001530_11 <= 255);
    __CPROVER_assume(sec_r001530_12 >= 0 && sec_r001530_12 <= 255);
    __CPROVER_assume(sec_r001530_13 >= 0 && sec_r001530_13 <= 255);
    __CPROVER_assume(sec_r001530_14 >= 0 && sec_r001530_14 <= 255);
    __CPROVER_assume(sec_r001530_15 >= 0 && sec_r001530_15 <= 255);
    __CPROVER_assume(sec_r001530_16 >= 0 && sec_r001530_16 <= 255);
    __CPROVER_assume(sec_r001530_17 >= 0 && sec_r001530_17 <= 255);
    __CPROVER_assume(sec_r001530_18 >= 0 && sec_r001530_18 <= 255);
    __CPROVER_assume(sec_r001530_19 >= 0 && sec_r001530_19 <= 255);
    __CPROVER_assume(sec_r001530_20 >= 0 && sec_r001530_20 <= 255);
    __CPROVER_assume(sec_r001530_21 >= 0 && sec_r001530_21 <= 255);
    __CPROVER_assume(sec_r001530_22 >= 0 && sec_r001530_22 <= 255);
    __CPROVER_assume(sec_r001530_23 >= 0 && sec_r001530_23 <= 255);

    struct EventLog_R001530_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001530_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001530_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001530_0 + 7) & 15;
    struct AudioFrame_R001530_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001530_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001530_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001530_0 + 9) & 15;
    struct Vector3D_R001530_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001530_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001530_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001530_0 + 11) & 15;
    struct SensorNode_R001530_3013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001530_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001530_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001530_0 + 13) & 15;

    union PacketPayload_R001530_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001530_3013_0(sec_r001530_0, pub_r001530_1, pub_r001530_2, pub_r001530_3, pub_r001530_4);
    int helper_flow_1 = fn_R001530_3013_1(sec_r001530_1, pub_r001530_2, pub_r001530_3);
    int helper_flow_2 = fn_R001530_3013_2(sec_r001530_2, sec_r001530_3);
    int helper_flow_3 = fn_R001530_3013_3(sec_r001530_3, pub_r001530_4, pub_r001530_5, pub_r001530_6, pub_r001530_7);
    int helper_flow_4 = fn_R001530_3013_4(sec_r001530_4, sec_r001530_5, pub_r001530_6, pub_r001530_7);
    int helper_flow_5 = fn_R001530_3013_5(sec_r001530_5, pub_r001530_6);
    int helper_flow_6 = fn_R001530_3013_6(sec_r001530_6, sec_r001530_7, pub_r001530_8);
    int helper_flow_7 = fn_R001530_3013_7(sec_r001530_7, sec_r001530_8, pub_r001530_9, pub_r001530_10, pub_r001530_11);
    int helper_flow_8 = fn_R001530_3013_8(sec_r001530_8, pub_r001530_9, pub_r001530_10, pub_r001530_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001530_9 ^ 0x2A) * 2 + pub_r001530_17) & 127;
    if (stage_v_0 > 26) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001530_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_2 > 50) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001530_22 ^ 0x2A) * 2 + pub_r001530_5) & 127;
    if (stage_v_3 > 32) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001530_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001530_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_6 > 36) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001530_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001530_2 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_8 > 24) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001530_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001530_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001530_23 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_11 > 25) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001530_10 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_12 > 30) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_13 > 29) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001530_6 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_14 > 23) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_15 > 39) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001530_14 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_16 > 20) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_17 > 25) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001530_17) & 127;
    if (stage_v_18 > 45) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001530_9) & 127;
    if (stage_v_19 > 27) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001530_10) & 127;
    if (stage_v_20 > 24) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001530_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001530_1 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_22 > 39) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001530_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001530_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_25 > 32) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001530_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001530_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_28 > 28) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001530_9 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_29 > 40) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_30 > 28) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001530_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001530_18) & 127;
    if (stage_v_32 > 38) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_33 > 50) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001530_18 ^ 0x2A) * 2 + pub_r001530_9) & 127;
    if (stage_v_34 > 46) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_35 > 31) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001530_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001530_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_38 > 50) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001530_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001530_0 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_40 > 40) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001530_20 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_41 > 36) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_42 > 33) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_43 > 20) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001530_22 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_44 > 26) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_45 > 46) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_46 > 38) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_47 > 32) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001530_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_49 > 46) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_50 > 27) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001530_2 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_51 > 21) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001530_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_53 > 40) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001530_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_55 > 44) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001530_8) & 127;
    if (stage_v_56 > 31) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001530_5 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_57 > 49) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_58 > 38) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001530_10) & 127;
    if (stage_v_59 > 33) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001530_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001530_13 ^ 0x2A) * 2 + pub_r001530_8) & 127;
    if (stage_v_61 > 50) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001530_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_63 > 48) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_64 > 42) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001530_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_66 > 47) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_67 > 33) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_68 > 45) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001530_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_71 > 23) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001530_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_73 > 33) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_74 > 23) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_75 > 43) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_76 > 39) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001530_1 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_77 > 23) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001530_19 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_78 > 49) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001530_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_80 > 34) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001530_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001530_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001530_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001530_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001530_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_86 > 27) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_87 > 29) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_88 > 39) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001530_10) & 127;
    if (stage_v_89 > 43) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_90 > 46) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_91 > 21) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001530_20 ^ 0x2A) * 2 + pub_r001530_8) & 127;
    if (stage_v_92 > 42) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_93 > 33) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_94 > 40) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_95 > 30) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_96 > 38) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001530_18) & 127;
    if (stage_v_97 > 29) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001530_17) & 127;
    if (stage_v_98 > 20) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001530_13 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_99 > 36) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_100 > 20) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001530_11 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_101 > 40) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001530_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_103 > 44) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_104 > 26) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001530_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_106 > 39) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001530_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_108 > 21) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001530_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001530_9) & 127;
    if (stage_v_110 > 46) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_111 > 36) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_112 > 48) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_113 > 39) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001530_5) & 127;
    if (stage_v_114 > 46) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_115 > 28) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001530_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_117 > 34) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001530_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_119 > 43) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001530_11 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_120 > 45) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001530_21 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_121 > 21) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001530_8) & 127;
    if (stage_v_122 > 43) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001530_5 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_123 > 41) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001530_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_125 > 36) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_126 > 48) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001530_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_128 > 28) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_129 > 27) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001530_5) & 127;
    if (stage_v_130 > 21) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001530_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001530_7 ^ 0x2A) * 2 + pub_r001530_17) & 127;
    if (stage_v_132 > 49) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001530_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_134 > 46) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001530_20 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_135 > 24) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001530_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001530_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001530_17 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_138 > 49) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001530_4 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001530_22 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_140 > 22) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001530_9 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_141 > 41) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_142 > 33) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_143 > 26) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_144 > 34) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001530_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_146 > 36) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001530_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_148 > 40) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001530_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001530_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_151 > 42) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_152 > 41) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_153 > 21) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_154 > 43) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_155 > 35) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001530_7 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_156 > 41) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_157 > 43) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_158 > 38) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001530_5) & 127;
    if (stage_v_159 > 23) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001530_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_161 > 24) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_162 > 35) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_163 > 23) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_164 > 31) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001530_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001530_11 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_166 > 41) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001530_5 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_167 > 24) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001530_8) & 127;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_169 > 31) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001530_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_171 > 21) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_172 > 46) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001530_18) & 127;
    if (stage_v_173 > 38) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001530_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001530_10) & 127;
    if (stage_v_175 > 43) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_176 > 26) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_177 > 31) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_178 > 33) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_179 > 23) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001530_12 ^ 0x2A) * 2 + pub_r001530_9) & 127;
    if (stage_v_180 > 20) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_181 > 24) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_182 > 32) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_183 > 39) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_184 > 26) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001530_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001530_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_187 > 27) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001530_7 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_188 > 38) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_189 > 46) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_190 > 23) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001530_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001530_0) & 127;
    if (stage_v_192 > 47) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_193 > 20) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_194 > 41) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_195 > 24) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_196 > 30) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_197 > 33) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_198 > 33) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_199 > 43) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001530_16) & 127;
    if (stage_v_200 > 49) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001530_14) & 127;
    if (stage_v_201 > 30) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_202 > 21) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001530_17) & 127;
    if (stage_v_203 > 36) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_204 > 27) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_205 > 34) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001530_5) & 127;
    if (stage_v_206 > 23) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_207 > 26) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_208 > 44) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_209 > 30) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_210 > 47) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001530_15) & 127;
    if (stage_v_211 > 46) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001530_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_213 > 26) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001530_13) & 127;
    if (stage_v_214 > 27) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001530_1) & 127;
    if (stage_v_215 > 26) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_216 > 43) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001530_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001530_9) & 127;
    if (stage_v_218 > 45) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001530_18) & 127;
    if (stage_v_219 > 50) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_220 > 21) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001530_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_222 > 50) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001530_8 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_223 > 45) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001530_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001530_20) & 127;
    if (stage_v_225 > 43) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001530_6) & 127;
    if (stage_v_226 > 35) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001530_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r001530_1 ^ 0x2A) * 2 + pub_r001530_2) & 127;
    if (stage_v_228 > 41) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001530_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001530_21 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_230 > 32) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001530_14 ^ 0x2A) * 2 + pub_r001530_11) & 127;
    if (stage_v_231 > 20) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001530_3) & 127;
    if (stage_v_232 > 34) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001530_19) & 127;
    if (stage_v_233 > 34) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001530_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001530_10) & 127;
    if (stage_v_235 > 44) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001530_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_216 ^ 0x2A) * 2 + pub_r001530_12) & 127;
    if (stage_v_237 > 40) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_238 > 45) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001530_7) & 127;
    if (stage_v_239 > 32) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001530_4) & 127;
    if (stage_v_240 > 49) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
