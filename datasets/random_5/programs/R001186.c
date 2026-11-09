/*
 * Benchmark Program: R001186
 * Security Family: implicit_flow
 * Generator Seed: 618613
 * High Inputs: 18 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001186_8613_0 {
    unsigned char density;
    int scale;
    unsigned char trace;
    int buffer[3];
};

struct EventLog_R001186_8613_1 {
    int signature;
    int severity;
    int seq;
    int buffer[3];
};

struct SensorNode_R001186_8613_2 {
    int offset;
    int calib;
    unsigned char gain;
    short threshold;
    int buffer[3];
};

struct Transaction_R001186_8613_3 {
    unsigned char rate;
    int balance;
    int fee;
    int auth_code;
    int status;
    short account_id;
    int buffer[3];
};

union ColorPixel_R001186_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001186_8613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001186_8613_0(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int damping_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_49 = local_arr[aux % 3];
    acc = (acc + quantum_49 * 2) & 127;
    int factor_87 = 0;
    for (int k = 0; k < 3; k++) {
        factor_87 = (factor_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_87) & 127;
    }
    int coefficient_62 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_62 > 11) {
        acc = (acc + coefficient_62 * 2 + 5) & 127;
        aux ^= (coefficient_62 & 15);
    } else {
        acc = (acc - coefficient_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_1(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_93 = (aux + st.buffer[1]) & 3;
    switch (residue_93) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_2(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001186_8613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_37) & 63;
    acc ^= aux;
    int damping_57 = 0;
    for (int k = 0; k < 3; k++) {
        damping_57 = (damping_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_3(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int pivot_54 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_54 > 42) {
        acc = (acc + pivot_54 * 2 + 5) & 127;
        aux ^= (pivot_54 & 15);
    } else {
        acc = (acc - pivot_54 + 11) & 127;
        aux += 3;
    }
    int tracker_87 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_87 = (tracker_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_87) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_24 = local_arr[aux % 3];
    acc = (acc + delta_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_37 = (aux + st.buffer[1]) & 3;
    switch (index_reg_37) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001186_8613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_97 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_97 > 35) {
        acc = (acc + metric_97 * 2 + 5) & 127;
        aux ^= (metric_97 & 15);
    } else {
        acc = (acc - metric_97 + 11) & 127;
        aux += 3;
    }
    int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_93) & 63;
    acc ^= aux;
    int bound_96 = (aux + st.buffer[1]) & 3;
    switch (bound_96) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_21 = local_arr[aux % 3];
    acc = (acc + offset_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001186_8613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_38 = 0;
    for (int k = 0; k < 3; k++) {
        margin_38 = (margin_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_35 = (aux + st.buffer[1]) & 3;
    switch (quotient_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_17 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_17 > 30) {
        acc = (acc + cursor_17 * 2 + 5) & 127;
        aux ^= (cursor_17 & 15);
    } else {
        acc = (acc - cursor_17 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_8(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001186_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_50 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_50 = (anchor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_50) & 127;
    }
    int parity_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_37) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_29 = local_arr[aux % 3];
    acc = (acc + delta_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001186_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int threshold_31 = local_arr[aux % 3];
    acc = (acc + threshold_31 * 2) & 127;
    int segment_37 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_37 > 30) {
        acc = (acc + segment_37 * 2 + 5) & 127;
        aux ^= (segment_37 & 15);
    } else {
        acc = (acc - segment_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_10(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001186_8613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int cursor_89 = local_arr[aux % 3];
    acc = (acc + cursor_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_44 = (aux + st.buffer[1]) & 3;
    switch (margin_44) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_18 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_18 > 25) {
        acc = (acc + vector_18 * 2 + 5) & 127;
        aux ^= (vector_18 & 15);
    } else {
        acc = (acc - vector_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_12(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001186_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_33 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_33 > 25) {
        acc = (acc + metric_33 * 2 + 5) & 127;
        aux ^= (metric_33 & 15);
    } else {
        acc = (acc - metric_33 + 11) & 127;
        aux += 3;
    }
    int vector_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_62) & 63;
    acc ^= aux;
    int offset_29 = (aux + st.buffer[1]) & 3;
    switch (offset_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_98 = local_arr[aux % 3];
    acc = (acc + mask_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_13(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001186_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_12) & 63;
    acc ^= aux;
    int damping_28 = (aux + st.buffer[1]) & 3;
    switch (damping_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_88 = 0;
    for (int k = 0; k < 2; k++) {
        weight_88 = (weight_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_88) & 127;
    }
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 36) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_14(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_78 > 10) {
        acc = (acc + quotient_78 * 2 + 5) & 127;
        aux ^= (quotient_78 & 15);
    } else {
        acc = (acc - quotient_78 + 11) & 127;
        aux += 3;
    }
    int window_30 = (aux + st.buffer[1]) & 3;
    switch (window_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_55 = local_arr[aux % 3];
    acc = (acc + damping_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_15(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_76 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_76 > 43) {
        acc = (acc + weight_76 * 2 + 5) & 127;
        aux ^= (weight_76 & 15);
    } else {
        acc = (acc - weight_76 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_13 = local_arr[aux % 3];
    acc = (acc + mask_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001186_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int margin_41 = (aux + st.buffer[1]) & 3;
    switch (margin_41) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001186_8613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_82 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_82 = (quantum_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_82) & 127;
    }
    int mask_55 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_55 > 47) {
        acc = (acc + mask_55 * 2 + 5) & 127;
        aux ^= (mask_55 & 15);
    } else {
        acc = (acc - mask_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001186_8613_18(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001186_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_68 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_68 = (tracker_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_68) & 127;
    }
    int tally_78 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_78 > 38) {
        acc = (acc + tally_78 * 2 + 5) & 127;
        aux ^= (tally_78 & 15);
    } else {
        acc = (acc - tally_78 + 11) & 127;
        aux += 3;
    }
    int sample_20 = (aux + st.buffer[1]) & 3;
    switch (sample_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_41 = local_arr[aux % 3];
    acc = (acc + sample_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001186_8613_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001186_8613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int window_27 = local_arr[aux % 3];
    acc = (acc + window_27 * 2) & 127;
    int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_92 = (aux + st.buffer[1]) & 3;
    switch (phase_92) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001186_0;
    int sec_r001186_1;
    int sec_r001186_2;
    int sec_r001186_3;
    int sec_r001186_4;
    int sec_r001186_5;
    int sec_r001186_6;
    int sec_r001186_7;
    int sec_r001186_8;
    int sec_r001186_9;
    int sec_r001186_10;
    int sec_r001186_11;
    int sec_r001186_12;
    int sec_r001186_13;
    int sec_r001186_14;
    int sec_r001186_15;
    int sec_r001186_16;
    int sec_r001186_17;
    int pub_r001186_0;
    int pub_r001186_1;
    int pub_r001186_2;
    int pub_r001186_3;
    int pub_r001186_4;
    int pub_r001186_5;
    int pub_r001186_6;
    int pub_r001186_7;
    int pub_r001186_8;
    int pub_r001186_9;
    int pub_r001186_10;
    int pub_r001186_11;
    int pub_r001186_12;
    int pub_r001186_13;
    int pub_r001186_14;
    int pub_r001186_15;
    int pub_r001186_16;
    int pub_r001186_17;
    int pub_r001186_18;
    int pub_r001186_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001186_0 >= -100 && pub_r001186_0 <= 100);
    __CPROVER_assume(pub_r001186_1 >= -100 && pub_r001186_1 <= 100);
    __CPROVER_assume(pub_r001186_2 >= -100 && pub_r001186_2 <= 100);
    __CPROVER_assume(pub_r001186_3 >= -100 && pub_r001186_3 <= 100);
    __CPROVER_assume(pub_r001186_4 >= -100 && pub_r001186_4 <= 100);
    __CPROVER_assume(pub_r001186_5 >= -100 && pub_r001186_5 <= 100);
    __CPROVER_assume(pub_r001186_6 >= -100 && pub_r001186_6 <= 100);
    __CPROVER_assume(pub_r001186_7 >= -100 && pub_r001186_7 <= 100);
    __CPROVER_assume(pub_r001186_8 >= -100 && pub_r001186_8 <= 100);
    __CPROVER_assume(pub_r001186_9 >= -100 && pub_r001186_9 <= 100);
    __CPROVER_assume(pub_r001186_10 >= -100 && pub_r001186_10 <= 100);
    __CPROVER_assume(pub_r001186_11 >= -100 && pub_r001186_11 <= 100);
    __CPROVER_assume(pub_r001186_12 >= -100 && pub_r001186_12 <= 100);
    __CPROVER_assume(pub_r001186_13 >= -100 && pub_r001186_13 <= 100);
    __CPROVER_assume(pub_r001186_14 >= -100 && pub_r001186_14 <= 100);
    __CPROVER_assume(pub_r001186_15 >= -100 && pub_r001186_15 <= 100);
    __CPROVER_assume(pub_r001186_16 >= -100 && pub_r001186_16 <= 100);
    __CPROVER_assume(pub_r001186_17 >= -100 && pub_r001186_17 <= 100);
    __CPROVER_assume(pub_r001186_18 >= -100 && pub_r001186_18 <= 100);
    __CPROVER_assume(pub_r001186_19 >= -100 && pub_r001186_19 <= 100);
    __CPROVER_assume(sec_r001186_0 >= 0 && sec_r001186_0 <= 255);
    __CPROVER_assume(sec_r001186_1 >= 0 && sec_r001186_1 <= 255);
    __CPROVER_assume(sec_r001186_2 >= 0 && sec_r001186_2 <= 255);
    __CPROVER_assume(sec_r001186_3 >= 0 && sec_r001186_3 <= 255);
    __CPROVER_assume(sec_r001186_4 >= 0 && sec_r001186_4 <= 255);
    __CPROVER_assume(sec_r001186_5 >= 0 && sec_r001186_5 <= 255);
    __CPROVER_assume(sec_r001186_6 >= 0 && sec_r001186_6 <= 255);
    __CPROVER_assume(sec_r001186_7 >= 0 && sec_r001186_7 <= 255);
    __CPROVER_assume(sec_r001186_8 >= 0 && sec_r001186_8 <= 255);
    __CPROVER_assume(sec_r001186_9 >= 0 && sec_r001186_9 <= 255);
    __CPROVER_assume(sec_r001186_10 >= 0 && sec_r001186_10 <= 255);
    __CPROVER_assume(sec_r001186_11 >= 0 && sec_r001186_11 <= 255);
    __CPROVER_assume(sec_r001186_12 >= 0 && sec_r001186_12 <= 255);
    __CPROVER_assume(sec_r001186_13 >= 0 && sec_r001186_13 <= 255);
    __CPROVER_assume(sec_r001186_14 >= 0 && sec_r001186_14 <= 255);
    __CPROVER_assume(sec_r001186_15 >= 0 && sec_r001186_15 <= 255);
    __CPROVER_assume(sec_r001186_16 >= 0 && sec_r001186_16 <= 255);
    __CPROVER_assume(sec_r001186_17 >= 0 && sec_r001186_17 <= 255);

    struct MatrixBlock_R001186_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001186_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001186_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001186_0 + 7) & 15;
    struct EventLog_R001186_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001186_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001186_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001186_0 + 9) & 15;
    struct SensorNode_R001186_8613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001186_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001186_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001186_0 + 11) & 15;
    struct Transaction_R001186_8613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001186_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001186_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001186_0 + 13) & 15;

    union ColorPixel_R001186_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001186_8613_0(sec_r001186_0, sec_r001186_1);
    int helper_flow_1 = fn_R001186_8613_1(sec_r001186_1, sec_r001186_2);
    int helper_flow_2 = fn_R001186_8613_2(sec_r001186_2, sec_r001186_3);
    int helper_flow_3 = fn_R001186_8613_3(sec_r001186_3, sec_r001186_4);
    int helper_flow_4 = fn_R001186_8613_4(sec_r001186_4, pub_r001186_5, pub_r001186_6, pub_r001186_7);
    int helper_flow_5 = fn_R001186_8613_5(sec_r001186_5, sec_r001186_6, pub_r001186_7, pub_r001186_8, pub_r001186_9);
    int helper_flow_6 = fn_R001186_8613_6(sec_r001186_6, pub_r001186_7, pub_r001186_8, pub_r001186_9);
    int helper_flow_7 = fn_R001186_8613_7(sec_r001186_7, pub_r001186_8, pub_r001186_9, pub_r001186_10);
    int helper_flow_8 = fn_R001186_8613_8(sec_r001186_8, pub_r001186_9, pub_r001186_10);
    int helper_flow_9 = fn_R001186_8613_9(sec_r001186_9, sec_r001186_10, pub_r001186_11, pub_r001186_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_4 + pub_r001186_3 * 2 + 5) & 127;
    if (stage_v_0 > 38) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_3 + pub_r001186_5 * 2 + 8) & 127;
    if (stage_v_1 > 43) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001186_0 + pub_r001186_6 * 2 + 11) & 127;
    if (stage_v_2 > 28) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001186_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001186_11 + pub_r001186_3 * 2 + 17) & 127;
    if (stage_v_4 > 37) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001186_1 + pub_r001186_16 * 2 + 20) & 127;
    if (stage_v_5 > 20) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001186_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_1 + pub_r001186_9 * 2 + 26) & 127;
    if (stage_v_7 > 43) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001186_6 + pub_r001186_13 * 2 + 29) & 127;
    if (stage_v_8 > 58) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001186_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001186_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001186_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (stage_v_7 + pub_r001186_6 * 2 + 41) & 127;
    if (stage_v_12 > 15) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001186_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001186_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001186_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001186_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_5 + pub_r001186_9 * 2 + 56) & 127;
    if (stage_v_17 > 40) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001186_16 + pub_r001186_19 * 2 + 59) & 127;
    if (stage_v_18 > 23) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001186_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_12 + pub_r001186_16 * 2 + 65) & 127;
    if (stage_v_20 > 43) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_5 + pub_r001186_8 * 2 + 68) & 127;
    if (stage_v_21 > 28) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_4 + pub_r001186_16 * 2 + 71) & 127;
    if (stage_v_22 > 55) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_0 + pub_r001186_11 * 2 + 74) & 127;
    if (stage_v_23 > 58) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_21 + pub_r001186_6 * 2 + 77) & 127;
    if (stage_v_24 > 28) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001186_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001186_13 + pub_r001186_10 * 2 + 83) & 127;
    if (stage_v_26 > 46) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001186_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001186_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001186_14 + pub_r001186_0 * 2 + 92) & 127;
    if (stage_v_29 > 48) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_4 + pub_r001186_2 * 2 + 95) & 127;
    if (stage_v_30 > 18) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001186_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001186_10 + pub_r001186_12 * 2 + 101) & 127;
    if (stage_v_32 > 57) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_12 + pub_r001186_2 * 2 + 104) & 127;
    if (stage_v_33 > 16) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001186_4 + pub_r001186_11 * 2 + 107) & 127;
    if (stage_v_34 > 54) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001186_16 + pub_r001186_19 * 2 + 110) & 127;
    if (stage_v_35 > 46) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_29 + pub_r001186_2 * 2 + 113) & 127;
    if (stage_v_36 > 46) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_3 + pub_r001186_18 * 2 + 116) & 127;
    if (stage_v_37 > 33) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001186_3 + pub_r001186_6 * 2 + 119) & 127;
    if (stage_v_38 > 46) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001186_4 + pub_r001186_0 * 2 + 122) & 127;
    if (stage_v_39 > 54) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_6 + pub_r001186_0 * 2 + 125) & 127;
    if (stage_v_40 > 18) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001186_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_18 + pub_r001186_10 * 2 + 131) & 127;
    if (stage_v_42 > 27) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_2 + pub_r001186_4 * 2 + 134) & 127;
    if (stage_v_43 > 53) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001186_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001186_16 + pub_r001186_8 * 2 + 140) & 127;
    if (stage_v_45 > 36) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_8 + pub_r001186_19 * 2 + 143) & 127;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_7 + pub_r001186_6 * 2 + 146) & 127;
    if (stage_v_47 > 51) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_7 + pub_r001186_7 * 2 + 149) & 127;
    if (stage_v_48 > 19) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_1 + pub_r001186_7 * 2 + 152) & 127;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_12 + pub_r001186_17 * 2 + 155) & 127;
    if (stage_v_50 > 24) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001186_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001186_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_2 + pub_r001186_15 * 2 + 164) & 127;
    if (stage_v_53 > 42) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001186_4 + pub_r001186_5 * 2 + 167) & 127;
    if (stage_v_54 > 54) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_8 + pub_r001186_7 * 2 + 170) & 127;
    if (stage_v_55 > 32) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001186_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_0 + pub_r001186_8 * 2 + 176) & 127;
    if (stage_v_57 > 16) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001186_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001186_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_18 + pub_r001186_3 * 2 + 185) & 127;
    if (stage_v_60 > 56) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001186_7 + pub_r001186_8 * 2 + 188) & 127;
    if (stage_v_61 > 34) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_39 + pub_r001186_18 * 2 + 191) & 127;
    if (stage_v_62 > 20) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_12 + pub_r001186_13 * 2 + 194) & 127;
    if (stage_v_63 > 20) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_33 + pub_r001186_1 * 2 + 197) & 127;
    if (stage_v_64 > 56) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_54 + pub_r001186_12 * 2 + 200) & 127;
    if (stage_v_65 > 59) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_50 + pub_r001186_5 * 2 + 203) & 127;
    if (stage_v_66 > 28) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001186_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_30 + pub_r001186_13 * 2 + 209) & 127;
    if (stage_v_68 > 42) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_18 + pub_r001186_2 * 2 + 212) & 127;
    if (stage_v_69 > 48) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001186_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001186_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001186_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001186_13 + pub_r001186_4 * 2 + 224) & 127;
    if (stage_v_73 > 30) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_47 + pub_r001186_7 * 2 + 227) & 127;
    if (stage_v_74 > 31) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_17 + pub_r001186_4 * 2 + 230) & 127;
    if (stage_v_75 > 57) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001186_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001186_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001186_12 + pub_r001186_19 * 2 + 239) & 127;
    if (stage_v_78 > 60) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_34 + pub_r001186_1 * 2 + 242) & 127;
    if (stage_v_79 > 40) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_1 + pub_r001186_0 * 2 + 245) & 127;
    if (stage_v_80 > 36) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_65 + pub_r001186_9 * 2 + 248) & 127;
    if (stage_v_81 > 17) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_69 + pub_r001186_2 * 2 + 251) & 127;
    if (stage_v_82 > 17) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001186_8 + pub_r001186_19 * 2 + 254) & 127;
    if (stage_v_83 > 51) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_0 + pub_r001186_17 * 2 + 257) & 127;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001186_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_0 + pub_r001186_9 * 2 + 263) & 127;
    if (stage_v_86 > 33) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_46 + pub_r001186_14 * 2 + 266) & 127;
    if (stage_v_87 > 24) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_83 + pub_r001186_3 * 2 + 269) & 127;
    if (stage_v_88 > 25) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001186_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001186_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001186_10 + pub_r001186_18 * 2 + 278) & 127;
    if (stage_v_91 > 43) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_12 + pub_r001186_12 * 2 + 281) & 127;
    if (stage_v_92 > 16) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001186_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001186_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001186_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_92 + pub_r001186_13 * 2 + 293) & 127;
    if (stage_v_96 > 29) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (helper_flow_6 + pub_r001186_19 * 2 + 296) & 127;
    if (stage_v_97 > 54) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_35 + pub_r001186_13 * 2 + 299) & 127;
    if (stage_v_98 > 48) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_86 + pub_r001186_3 * 2 + 302) & 127;
    if (stage_v_99 > 56) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_48 + pub_r001186_19 * 2 + 305) & 127;
    if (stage_v_100 > 54) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_6 + pub_r001186_11 * 2 + 308) & 127;
    if (stage_v_101 > 36) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001186_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001186_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001186_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_34 + pub_r001186_19 * 2 + 320) & 127;
    if (stage_v_105 > 42) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001186_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_92 + pub_r001186_17 * 2 + 326) & 127;
    if (stage_v_107 > 22) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_43 + pub_r001186_13 * 2 + 329) & 127;
    if (stage_v_108 > 17) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001186_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001186_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001186_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001186_3 + pub_r001186_17 * 2 + 341) & 127;
    if (stage_v_112 > 20) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_40 + pub_r001186_17 * 2 + 344) & 127;
    if (stage_v_113 > 56) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_34 + pub_r001186_1 * 2 + 347) & 127;
    if (stage_v_114 > 43) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001186_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001186_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (sec_r001186_7 + pub_r001186_13 * 2 + 356) & 127;
    if (stage_v_117 > 34) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_100 + pub_r001186_18 * 2 + 359) & 127;
    if (stage_v_118 > 28) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001186_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_88 + pub_r001186_14 * 2 + 365) & 127;
    if (stage_v_120 > 60) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001186_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001186_14 + pub_r001186_2 * 2 + 371) & 127;
    if (stage_v_122 > 60) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001186_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_0 + pub_r001186_8 * 2 + 377) & 127;
    if (stage_v_124 > 53) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_53 + pub_r001186_10 * 2 + 380) & 127;
    if (stage_v_125 > 16) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001186_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_64 + pub_r001186_1 * 2 + 386) & 127;
    if (stage_v_127 > 34) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001186_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001186_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (helper_flow_3 + pub_r001186_6 * 2 + 395) & 127;
    if (stage_v_130 > 56) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001186_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_81 + pub_r001186_3 * 2 + 401) & 127;
    if (stage_v_132 > 28) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001186_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_91 + pub_r001186_16 * 2 + 407) & 127;
    if (stage_v_134 > 24) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_46 + pub_r001186_16 * 2 + 410) & 127;
    if (stage_v_135 > 54) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001186_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001186_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_5 + pub_r001186_17 * 2 + 419) & 127;
    if (stage_v_138 > 57) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (helper_flow_0 + pub_r001186_0 * 2 + 422) & 127;
    if (stage_v_139 > 31) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_50 + pub_r001186_9 * 2 + 425) & 127;
    if (stage_v_140 > 25) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001186_9 + pub_r001186_9 * 2 + 428) & 127;
    if (stage_v_141 > 37) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001186_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_63 + pub_r001186_11 * 2 + 434) & 127;
    if (stage_v_143 > 38) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001186_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001186_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001186_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001186_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_40 + pub_r001186_6 * 2 + 449) & 127;
    if (stage_v_148 > 28) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_64 + pub_r001186_12 * 2 + 452) & 127;
    if (stage_v_149 > 44) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001186_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_99 + pub_r001186_0 * 2 + 458) & 127;
    if (stage_v_151 > 50) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_48 + pub_r001186_18 * 2 + 461) & 127;
    if (stage_v_152 > 47) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001186_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001186_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_29 + pub_r001186_3 * 2 + 470) & 127;
    if (stage_v_155 > 60) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001186_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001186_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_48 + pub_r001186_4 * 2 + 479) & 127;
    if (stage_v_158 > 22) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_100 + pub_r001186_2 * 2 + 482) & 127;
    if (stage_v_159 > 45) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_3 + pub_r001186_16 * 2 + 485) & 127;
    if (stage_v_160 > 45) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001186_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_63 + pub_r001186_9 * 2 + 491) & 127;
    if (stage_v_162 > 34) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001186_6 + pub_r001186_6 * 2 + 494) & 127;
    if (stage_v_163 > 48) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_158 + pub_r001186_3 * 2 + 497) & 127;
    if (stage_v_164 > 32) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001186_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001186_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_63 + pub_r001186_18 * 2 + 506) & 127;
    if (stage_v_167 > 52) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_42 + pub_r001186_9 * 2 + 509) & 127;
    if (stage_v_168 > 46) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001186_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_98 + pub_r001186_10 * 2 + 515) & 127;
    if (stage_v_170 > 52) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001186_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_148 + pub_r001186_14 * 2 + 521) & 127;
    if (stage_v_172 > 58) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_73 + pub_r001186_18 * 2 + 524) & 127;
    if (stage_v_173 > 46) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001186_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_134 + pub_r001186_9 * 2 + 530) & 127;
    if (stage_v_175 > 34) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001186_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_29 + pub_r001186_2 * 2 + 536) & 127;
    if (stage_v_177 > 51) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001186_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001186_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001186_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_152 + pub_r001186_13 * 2 + 548) & 127;
    if (stage_v_181 > 24) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001186_7 + pub_r001186_18 * 2 + 551) & 127;
    if (stage_v_182 > 40) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_8 + pub_r001186_0 * 2 + 554) & 127;
    if (stage_v_183 > 23) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_42 + pub_r001186_5 * 2 + 557) & 127;
    if (stage_v_184 > 39) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001186_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_98 + pub_r001186_15 * 2 + 563) & 127;
    if (stage_v_186 > 49) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_114 + pub_r001186_16 * 2 + 566) & 127;
    if (stage_v_187 > 21) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_170 + pub_r001186_17 * 2 + 569) & 127;
    if (stage_v_188 > 49) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001186_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001186_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001186_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_162 + pub_r001186_2 * 2 + 581) & 127;
    if (stage_v_192 > 40) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001186_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_177 + pub_r001186_11 * 2 + 587) & 127;
    if (stage_v_194 > 20) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001186_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_138 + pub_r001186_12 * 2 + 593) & 127;
    if (stage_v_196 > 24) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r001186_5 + pub_r001186_18 * 2 + 596) & 127;
    if (stage_v_197 > 17) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_50 + pub_r001186_19 * 2 + 599) & 127;
    if (stage_v_198 > 25) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (helper_flow_9 + pub_r001186_15 * 2 + 602) & 127;
    if (stage_v_199 > 29) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001186_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_164 + pub_r001186_19 * 2 + 608) & 127;
    if (stage_v_201 > 41) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001186_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_78 + pub_r001186_0 * 2 + 614) & 127;
    if (stage_v_203 > 27) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001186_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001186_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001186_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (helper_flow_9 + pub_r001186_0 * 2 + 626) & 127;
    if (stage_v_207 > 46) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (sec_r001186_4 + pub_r001186_19 * 2 + 629) & 127;
    if (stage_v_208 > 54) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_188 + pub_r001186_15 * 2 + 632) & 127;
    if (stage_v_209 > 50) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001186_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001186_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_120 + pub_r001186_12 * 2 + 641) & 127;
    if (stage_v_212 > 22) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001186_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_30 + pub_r001186_2 * 2 + 647) & 127;
    if (stage_v_214 > 60) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001186_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_192 + pub_r001186_10 * 2 + 653) & 127;
    if (stage_v_216 > 59) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_158 + pub_r001186_13 * 2 + 656) & 127;
    if (stage_v_217 > 19) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_184 + pub_r001186_14 * 2 + 659) & 127;
    if (stage_v_218 > 42) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001186_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001186_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r001186_6 + pub_r001186_11 * 2 + 668) & 127;
    if (stage_v_221 > 33) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_199 + pub_r001186_7 * 2 + 671) & 127;
    if (stage_v_222 > 43) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_170 + pub_r001186_8 * 2 + 674) & 127;
    if (stage_v_223 > 47) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001186_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001186_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_173 + pub_r001186_16 * 2 + 683) & 127;
    if (stage_v_226 > 40) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_196 + pub_r001186_14 * 2 + 686) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_68 + pub_r001186_16 * 2 + 689) & 127;
    if (stage_v_228 > 50) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_42 + pub_r001186_18 * 2 + 692) & 127;
    if (stage_v_229 > 42) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_78 + pub_r001186_17 * 2 + 695) & 127;
    if (stage_v_230 > 28) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_86 + pub_r001186_15 * 2 + 698) & 127;
    if (stage_v_231 > 53) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001186_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_160 + pub_r001186_9 * 2 + 704) & 127;
    if (stage_v_233 > 17) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001186_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r001186_2 + pub_r001186_16 * 2 + 710) & 127;
    if (stage_v_235 > 39) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_83 + pub_r001186_8 * 2 + 713) & 127;
    if (stage_v_236 > 38) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_236 + pub_r001186_17 * 2 + 716) & 127;
    if (stage_v_237 > 43) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001186_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_100 + pub_r001186_6 * 2 + 722) & 127;
    if (stage_v_239 > 58) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_105 + pub_r001186_15 * 2 + 725) & 127;
    if (stage_v_240 > 20) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (sec_r001186_4 + pub_r001186_19 * 2 + 728) & 127;
    if (stage_v_241 > 23) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_75 + pub_r001186_9 * 2 + 731) & 127;
    if (stage_v_242 > 38) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001186_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_184 + pub_r001186_0 * 2 + 737) & 127;
    if (stage_v_244 > 28) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (sec_r001186_13 + pub_r001186_2 * 2 + 740) & 127;
    if (stage_v_245 > 27) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_201 + pub_r001186_19 * 2 + 743) & 127;
    if (stage_v_246 > 50) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_54 + pub_r001186_17 * 2 + 746) & 127;
    if (stage_v_247 > 43) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
