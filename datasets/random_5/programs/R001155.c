/*
 * Benchmark Program: R001155
 * Security Family: bitwise_flow
 * Generator Seed: 615513
 * High Inputs: 23 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001155_5513_0 {
    unsigned char rate;
    unsigned char balance;
    unsigned char auth_code;
    int buffer[3];
};

struct MatrixBlock_R001155_5513_1 {
    short scale;
    int determinant;
    short trace;
    unsigned char stride;
    int buffer[3];
};

struct FilterState_R001155_5513_2 {
    int mode;
    int cutoff;
    int prev_out;
    int prev_in;
    int buffer[3];
};

union TelemetryField_R001155_5513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001155_5513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_27 = 0;
    for (int k = 0; k < 2; k++) {
        scale_27 = (scale_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_10 = (aux + st.buffer[1]) & 3;
    switch (scale_10) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_24 = 0;
    for (int k = 0; k < 2; k++) {
        metric_24 = (metric_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_24) & 127;
    }
    int anchor_70 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_70 > 45) {
        acc = (acc + anchor_70 * 2 + 5) & 127;
        aux ^= (anchor_70 & 15);
    } else {
        acc = (acc - anchor_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_2(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001155_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int cursor_23 = local_arr[aux % 3];
    acc = (acc + cursor_23 * 2) & 127;
    int anchor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001155_5513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int segment_67 = (aux + st.buffer[1]) & 3;
    switch (segment_67) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_95 = local_arr[aux % 3];
    acc = (acc + offset_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_14 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_14 > 18) {
        acc = (acc + parity_14 * 2 + 5) & 127;
        aux ^= (parity_14 & 15);
    } else {
        acc = (acc - parity_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_97 = local_arr[aux % 3];
    acc = (acc + factor_97 * 2) & 127;
    int index_reg_35 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_35 = (index_reg_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_35) & 127;
    }
    int mask_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001155_5513_5(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_22 = (aux + st.buffer[1]) & 3;
    switch (damping_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_27 = local_arr[aux % 3];
    acc = (acc + tally_27 * 2) & 127;
    int quantum_87 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_87 = (quantum_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_6(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_95 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_95 > 21) {
        acc = (acc + anchor_95 * 2 + 5) & 127;
        aux ^= (anchor_95 & 15);
    } else {
        acc = (acc - anchor_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int metric_39 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_39 > 35) {
        acc = (acc + metric_39 * 2 + 5) & 127;
        aux ^= (metric_39 & 15);
    } else {
        acc = (acc - metric_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_8(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_99 = local_arr[aux % 3];
    acc = (acc + tracker_99 * 2) & 127;
    int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001155_5513_9(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int threshold_29 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_29 > 17) {
        acc = (acc + threshold_29 * 2 + 5) & 127;
        aux ^= (threshold_29 & 15);
    } else {
        acc = (acc - threshold_29 + 11) & 127;
        aux += 3;
    }
    int segment_84 = 0;
    for (int k = 0; k < 3; k++) {
        segment_84 = (segment_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_84) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_10(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001155_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_66) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_12(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_80 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_80 = (quantum_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_80) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_53 = local_arr[aux % 3];
    acc = (acc + stride_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_13(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001155_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int phase_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_76) & 63;
    acc ^= aux;
    int tracker_51 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_51 = (tracker_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_51) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_14(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int parity_40 = local_arr[aux % 3];
    acc = (acc + parity_40 * 2) & 127;
    int quantum_91 = (aux + st.buffer[1]) & 3;
    switch (quantum_91) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_52 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_52 > 21) {
        acc = (acc + index_reg_52 * 2 + 5) & 127;
        aux ^= (index_reg_52 & 15);
    } else {
        acc = (acc - index_reg_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_73 = (aux + st.buffer[1]) & 3;
    switch (tracker_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_23 = local_arr[aux % 3];
    acc = (acc + quantum_23 * 2) & 127;
    int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001155_5513_16(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_13 = local_arr[aux % 3];
    acc = (acc + damping_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_17(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001155_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_57) & 63;
    acc ^= aux;
    int tracker_33 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_33 = (tracker_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_33) & 127;
    }
    int quantum_34 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_34 > 36) {
        acc = (acc + quantum_34 * 2 + 5) & 127;
        aux ^= (quantum_34 & 15);
    } else {
        acc = (acc - quantum_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001155_5513_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001155_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_91 = 0;
    for (int k = 0; k < 3; k++) {
        phase_91 = (phase_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_91) & 127;
    }
    int checksum_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001155_5513_19(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001155_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_75 = 0;
    for (int k = 0; k < 3; k++) {
        segment_75 = (segment_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_75) & 127;
    }
    int metric_73 = (aux + st.buffer[1]) & 3;
    switch (metric_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001155_5513_20(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001155_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_61 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_61 > 47) {
        acc = (acc + tally_61 * 2 + 5) & 127;
        aux ^= (tally_61 & 15);
    } else {
        acc = (acc - tally_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_60 = local_arr[aux % 3];
    acc = (acc + stride_60 * 2) & 127;
    int metric_76 = (aux + st.buffer[1]) & 3;
    switch (metric_76) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001155_0;
    int sec_r001155_1;
    int sec_r001155_2;
    int sec_r001155_3;
    int sec_r001155_4;
    int sec_r001155_5;
    int sec_r001155_6;
    int sec_r001155_7;
    int sec_r001155_8;
    int sec_r001155_9;
    int sec_r001155_10;
    int sec_r001155_11;
    int sec_r001155_12;
    int sec_r001155_13;
    int sec_r001155_14;
    int sec_r001155_15;
    int sec_r001155_16;
    int sec_r001155_17;
    int sec_r001155_18;
    int sec_r001155_19;
    int sec_r001155_20;
    int sec_r001155_21;
    int sec_r001155_22;
    int pub_r001155_0;
    int pub_r001155_1;
    int pub_r001155_2;
    int pub_r001155_3;
    int pub_r001155_4;
    int pub_r001155_5;
    int pub_r001155_6;
    int pub_r001155_7;
    int pub_r001155_8;
    int pub_r001155_9;
    int pub_r001155_10;
    int pub_r001155_11;
    int pub_r001155_12;
    int pub_r001155_13;
    int pub_r001155_14;
    int pub_r001155_15;
    int pub_r001155_16;
    int pub_r001155_17;
    int pub_r001155_18;
    int pub_r001155_19;
    int pub_r001155_20;
    int pub_r001155_21;
    int pub_r001155_22;
    int pub_r001155_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001155_0 >= -100 && pub_r001155_0 <= 100);
    __CPROVER_assume(pub_r001155_1 >= -100 && pub_r001155_1 <= 100);
    __CPROVER_assume(pub_r001155_2 >= -100 && pub_r001155_2 <= 100);
    __CPROVER_assume(pub_r001155_3 >= -100 && pub_r001155_3 <= 100);
    __CPROVER_assume(pub_r001155_4 >= -100 && pub_r001155_4 <= 100);
    __CPROVER_assume(pub_r001155_5 >= -100 && pub_r001155_5 <= 100);
    __CPROVER_assume(pub_r001155_6 >= -100 && pub_r001155_6 <= 100);
    __CPROVER_assume(pub_r001155_7 >= -100 && pub_r001155_7 <= 100);
    __CPROVER_assume(pub_r001155_8 >= -100 && pub_r001155_8 <= 100);
    __CPROVER_assume(pub_r001155_9 >= -100 && pub_r001155_9 <= 100);
    __CPROVER_assume(pub_r001155_10 >= -100 && pub_r001155_10 <= 100);
    __CPROVER_assume(pub_r001155_11 >= -100 && pub_r001155_11 <= 100);
    __CPROVER_assume(pub_r001155_12 >= -100 && pub_r001155_12 <= 100);
    __CPROVER_assume(pub_r001155_13 >= -100 && pub_r001155_13 <= 100);
    __CPROVER_assume(pub_r001155_14 >= -100 && pub_r001155_14 <= 100);
    __CPROVER_assume(pub_r001155_15 >= -100 && pub_r001155_15 <= 100);
    __CPROVER_assume(pub_r001155_16 >= -100 && pub_r001155_16 <= 100);
    __CPROVER_assume(pub_r001155_17 >= -100 && pub_r001155_17 <= 100);
    __CPROVER_assume(pub_r001155_18 >= -100 && pub_r001155_18 <= 100);
    __CPROVER_assume(pub_r001155_19 >= -100 && pub_r001155_19 <= 100);
    __CPROVER_assume(pub_r001155_20 >= -100 && pub_r001155_20 <= 100);
    __CPROVER_assume(pub_r001155_21 >= -100 && pub_r001155_21 <= 100);
    __CPROVER_assume(pub_r001155_22 >= -100 && pub_r001155_22 <= 100);
    __CPROVER_assume(pub_r001155_23 >= -100 && pub_r001155_23 <= 100);
    __CPROVER_assume(sec_r001155_0 >= 0 && sec_r001155_0 <= 255);
    __CPROVER_assume(sec_r001155_1 >= 0 && sec_r001155_1 <= 255);
    __CPROVER_assume(sec_r001155_2 >= 0 && sec_r001155_2 <= 255);
    __CPROVER_assume(sec_r001155_3 >= 0 && sec_r001155_3 <= 255);
    __CPROVER_assume(sec_r001155_4 >= 0 && sec_r001155_4 <= 255);
    __CPROVER_assume(sec_r001155_5 >= 0 && sec_r001155_5 <= 255);
    __CPROVER_assume(sec_r001155_6 >= 0 && sec_r001155_6 <= 255);
    __CPROVER_assume(sec_r001155_7 >= 0 && sec_r001155_7 <= 255);
    __CPROVER_assume(sec_r001155_8 >= 0 && sec_r001155_8 <= 255);
    __CPROVER_assume(sec_r001155_9 >= 0 && sec_r001155_9 <= 255);
    __CPROVER_assume(sec_r001155_10 >= 0 && sec_r001155_10 <= 255);
    __CPROVER_assume(sec_r001155_11 >= 0 && sec_r001155_11 <= 255);
    __CPROVER_assume(sec_r001155_12 >= 0 && sec_r001155_12 <= 255);
    __CPROVER_assume(sec_r001155_13 >= 0 && sec_r001155_13 <= 255);
    __CPROVER_assume(sec_r001155_14 >= 0 && sec_r001155_14 <= 255);
    __CPROVER_assume(sec_r001155_15 >= 0 && sec_r001155_15 <= 255);
    __CPROVER_assume(sec_r001155_16 >= 0 && sec_r001155_16 <= 255);
    __CPROVER_assume(sec_r001155_17 >= 0 && sec_r001155_17 <= 255);
    __CPROVER_assume(sec_r001155_18 >= 0 && sec_r001155_18 <= 255);
    __CPROVER_assume(sec_r001155_19 >= 0 && sec_r001155_19 <= 255);
    __CPROVER_assume(sec_r001155_20 >= 0 && sec_r001155_20 <= 255);
    __CPROVER_assume(sec_r001155_21 >= 0 && sec_r001155_21 <= 255);
    __CPROVER_assume(sec_r001155_22 >= 0 && sec_r001155_22 <= 255);

    struct Transaction_R001155_5513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001155_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001155_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001155_0 + 7) & 15;
    struct MatrixBlock_R001155_5513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001155_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001155_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001155_0 + 9) & 15;
    struct FilterState_R001155_5513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001155_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001155_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001155_0 + 11) & 15;

    union TelemetryField_R001155_5513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001155_5513_0(sec_r001155_0, sec_r001155_1, pub_r001155_2, pub_r001155_3, pub_r001155_4);
    int helper_flow_1 = fn_R001155_5513_1(sec_r001155_1, pub_r001155_2, pub_r001155_3, pub_r001155_4, pub_r001155_5);
    int helper_flow_2 = fn_R001155_5513_2(sec_r001155_2, pub_r001155_3, pub_r001155_4);
    int helper_flow_3 = fn_R001155_5513_3(sec_r001155_3, pub_r001155_4, pub_r001155_5, pub_r001155_6, pub_r001155_7);
    int helper_flow_4 = fn_R001155_5513_4(sec_r001155_4, pub_r001155_5, pub_r001155_6, pub_r001155_7);
    int helper_flow_5 = fn_R001155_5513_5(sec_r001155_5, pub_r001155_6, pub_r001155_7);
    int helper_flow_6 = fn_R001155_5513_6(sec_r001155_6, pub_r001155_7, pub_r001155_8);
    int helper_flow_7 = fn_R001155_5513_7(sec_r001155_7, pub_r001155_8, pub_r001155_9, pub_r001155_10);
    int helper_flow_8 = fn_R001155_5513_8(sec_r001155_8, sec_r001155_9, pub_r001155_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001155_17 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001155_16 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001155_22 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001155_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_6 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001155_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_8 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001155_6 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001155_16 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001155_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001155_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001155_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_4 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001155_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001155_4 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001155_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001155_9 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001155_12 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001155_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001155_21 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001155_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001155_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001155_17 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001155_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001155_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_7 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001155_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_2 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_25 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001155_14 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001155_11 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001155_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_0 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001155_0 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_30 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001155_0 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001155_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_2 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_3 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_5 << 1) ^ (pub_r001155_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001155_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001155_17 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001155_18 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001155_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_0 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_28 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_3 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001155_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001155_3 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001155_22 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_16 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001155_20 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001155_22 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001155_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001155_6 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_33 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001155_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001155_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001155_17 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001155_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001155_20 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_2 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001155_11 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001155_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001155_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001155_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001155_3 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001155_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001155_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001155_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_6 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_2 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001155_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001155_21 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001155_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_71 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001155_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001155_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_37 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_42 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001155_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_38 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001155_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001155_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001155_6 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001155_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001155_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001155_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001155_13 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_61 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001155_3 << 1) ^ (pub_r001155_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001155_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001155_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001155_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_46 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_28 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_4 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_35 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_81 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_29 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_35 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001155_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001155_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_90 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001155_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_0 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001155_16 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_99 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_89 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_70 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_55 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001155_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001155_23 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_17 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001155_23 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001155_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001155_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001155_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_8 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001155_7 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_37 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001155_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001155_14 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001155_22 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_75 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_52 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001155_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001155_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_46 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001155_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((helper_flow_5 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001155_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001155_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_22 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_97 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001155_9 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001155_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001155_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_4 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001155_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_2 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001155_23 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_78 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001155_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001155_5 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001155_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001155_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r001155_13 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_30 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_44 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_32 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001155_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001155_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_125 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001155_23 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001155_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_75 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_8 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_109 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001155_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001155_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_158 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_46 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001155_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_158 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001155_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_158 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001155_21 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001155_21 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001155_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_48 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001155_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001155_23 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001155_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001155_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_164 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_147 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_30 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_170 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_70 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001155_21 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001155_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001155_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001155_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_108 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_41 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001155_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001155_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001155_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_88 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_153 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_7 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001155_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_81 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_44 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_61 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001155_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001155_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_161 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001155_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_17 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001155_2 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_130 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001155_20 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001155_20 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_55 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001155_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_33 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_118 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001155_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001155_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((helper_flow_2 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_97 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_177 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001155_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001155_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001155_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_94 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001155_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001155_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001155_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_157 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001155_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001155_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_89 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_33 << 1) ^ (pub_r001155_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001155_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_224 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_58 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001155_17 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001155_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_138 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_66 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001155_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_189 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001155_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_8 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001155_20 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r001155_11 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001155_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_170 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_32 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001155_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001155_22 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((helper_flow_7 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001155_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001155_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001155_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_39 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001155_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_110 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((helper_flow_4 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001155_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_120 << 1) ^ (pub_r001155_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001155_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_32 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_90 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_198 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001155_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001155_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r001155_4 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_229 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r001155_16 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_231 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001155_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001155_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001155_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_150 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001155_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001155_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001155_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001155_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_153 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001155_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_189 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_12 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_232 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001155_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r001155_11 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_130 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001155_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_153 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001155_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_175 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001155_23 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_2 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_178 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001155_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001155_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_285 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_144 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_94 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_251 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_189 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_281 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_166 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_281 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_103 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001155_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_108 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001155_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_42 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001155_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_261 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001155_23 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001155_23 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001155_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_278 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_71 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001155_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001155_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r001155_11 << 1) ^ (pub_r001155_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001155_22 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001155_23 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_89 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001155_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001155_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((helper_flow_8 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001155_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001155_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001155_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((sec_r001155_1 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001155_22 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001155_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001155_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_283 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_263 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_225 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_35 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001155_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_283 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_208 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_255 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001155_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001155_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001155_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001155_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001155_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001155_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001155_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_149 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_164 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_45 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001155_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_50 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001155_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001155_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_27 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_211 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((helper_flow_2 << 1) ^ (pub_r001155_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001155_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001155_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001155_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_7 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((sec_r001155_4 << 1) ^ (pub_r001155_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_201 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001155_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001155_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001155_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001155_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001155_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001155_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((helper_flow_1 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001155_21 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_211 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_232 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_274 << 1) ^ (pub_r001155_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_290 << 1) ^ (pub_r001155_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001155_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001155_20 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((helper_flow_6 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_4 << 1) ^ (pub_r001155_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001155_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001155_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((sec_r001155_10 << 1) ^ (pub_r001155_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_248 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_240 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001155_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((sec_r001155_22 << 1) ^ (pub_r001155_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_224 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_194 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_12 << 1) ^ (pub_r001155_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001155_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_158 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_138 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001155_23 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001155_23 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_347 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001155_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001155_23 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_118 << 1) ^ (pub_r001155_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_124 << 1) ^ (pub_r001155_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_19 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001155_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001155_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001155_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001155_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_110 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_29 << 1) ^ (pub_r001155_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_314 << 1) ^ (pub_r001155_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_62 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001155_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001155_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001155_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001155_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_240 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001155_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((sec_r001155_21 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001155_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001155_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_178 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001155_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_96 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((helper_flow_6 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_2 << 1) ^ (pub_r001155_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_162 << 1) ^ (pub_r001155_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_353 << 1) ^ (pub_r001155_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_376 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001155_23 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001155_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_250 << 1) ^ (pub_r001155_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001155_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_341 << 1) ^ (pub_r001155_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001155_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_379 << 1) ^ (pub_r001155_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_25 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_128 << 1) ^ (pub_r001155_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001155_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((sec_r001155_0 << 1) ^ (pub_r001155_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001155_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_52 << 1) ^ (pub_r001155_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_1 << 1) ^ (pub_r001155_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((sec_r001155_10 << 1) ^ (pub_r001155_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((helper_flow_0 << 1) ^ (pub_r001155_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001155_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001155_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
