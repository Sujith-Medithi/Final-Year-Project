/*
 * Benchmark Program: R001795
 * Security Family: bitwise_flow
 * Generator Seed: 679513
 * High Inputs: 17 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001795_9513_0 {
    int sample_rate;
    unsigned char envelope;
    short gain;
    short peak;
    unsigned char rms;
    int channels;
    int buffer[3];
};

struct FilterState_R001795_9513_1 {
    int prev_out;
    unsigned char gain_db;
    int mode;
    int buffer[3];
};

struct MatrixBlock_R001795_9513_2 {
    int trace;
    int stride;
    unsigned char density;
    int buffer[3];
};

struct EventLog_R001795_9513_3 {
    int seq;
    unsigned char severity;
    short timestamp;
    int code;
    int buffer[3];
};

union PacketPayload_R001795_9513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001795_9513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001795_9513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_68 = (aux + st.buffer[1]) & 3;
    switch (tally_68) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_88 = local_arr[aux % 3];
    acc = (acc + metric_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001795_9513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int parity_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_46 = local_arr[aux % 3];
    acc = (acc + pivot_46 * 2) & 127;
    int parity_72 = (aux + st.buffer[1]) & 3;
    switch (parity_72) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_44 = (aux + st.buffer[1]) & 3;
    switch (coefficient_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_85 = local_arr[aux % 3];
    acc = (acc + index_reg_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001795_9513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_63 = (aux + st.buffer[1]) & 3;
    switch (damping_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_62) & 63;
    acc ^= aux;
    int vector_42 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_42 > 15) {
        acc = (acc + vector_42 * 2 + 5) & 127;
        aux ^= (vector_42 & 15);
    } else {
        acc = (acc - vector_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int mask_74 = local_arr[aux % 3];
    acc = (acc + mask_74 * 2) & 127;
    int bound_40 = (aux + st.buffer[1]) & 3;
    switch (bound_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001795_9513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001795_9513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_80) & 63;
    acc ^= aux;
    int damping_74 = 0;
    for (int k = 0; k < 3; k++) {
        damping_74 = (damping_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_74) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_6(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_30 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_30 > 12) {
        acc = (acc + bound_30 * 2 + 5) & 127;
        aux ^= (bound_30 & 15);
    } else {
        acc = (acc - bound_30 + 11) & 127;
        aux += 3;
    }
    int margin_59 = (aux + st.buffer[1]) & 3;
    switch (margin_59) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_7(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_97 = local_arr[aux % 3];
    acc = (acc + tracker_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_8(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 41) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    int metric_50 = 0;
    for (int k = 0; k < 3; k++) {
        metric_50 = (metric_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_9(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tally_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_64 = local_arr[aux % 3];
    acc = (acc + metric_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001795_9513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_14 = local_arr[aux % 3];
    acc = (acc + cursor_14 * 2) & 127;
    int parity_29 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_29 > 13) {
        acc = (acc + parity_29 * 2 + 5) & 127;
        aux ^= (parity_29 & 15);
    } else {
        acc = (acc - parity_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_11(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_23 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_23 > 23) {
        acc = (acc + threshold_23 * 2 + 5) & 127;
        aux ^= (threshold_23 & 15);
    } else {
        acc = (acc - threshold_23 + 11) & 127;
        aux += 3;
    }
    int anchor_36 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_36 = (anchor_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001795_9513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_69 = (aux + st.buffer[1]) & 3;
    switch (offset_69) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_13(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001795_9513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int scale_70 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_70 > 29) {
        acc = (acc + scale_70 * 2 + 5) & 127;
        aux ^= (scale_70 & 15);
    } else {
        acc = (acc - scale_70 + 11) & 127;
        aux += 3;
    }
    int tally_25 = 0;
    for (int k = 0; k < 3; k++) {
        tally_25 = (tally_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_25) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_40 = local_arr[aux % 3];
    acc = (acc + phase_40 * 2) & 127;
    int sample_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001795_9513_14(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001795_9513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_89) & 63;
    acc ^= aux;
    int parity_13 = 0;
    for (int k = 0; k < 3; k++) {
        parity_13 = (parity_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_13) & 127;
    }
    int scale_66 = (aux + st.buffer[1]) & 3;
    switch (scale_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_15(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_11) & 63;
    acc ^= aux;
    int sample_46 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_46 > 41) {
        acc = (acc + sample_46 * 2 + 5) & 127;
        aux ^= (sample_46 & 15);
    } else {
        acc = (acc - sample_46 + 11) & 127;
        aux += 3;
    }
    int stride_78 = (aux + st.buffer[1]) & 3;
    switch (stride_78) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int coefficient_75 = local_arr[aux % 3];
    acc = (acc + coefficient_75 * 2) & 127;
    int cursor_89 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_89 = (cursor_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_89) & 127;
    }
    int segment_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001795_9513_17(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001795_9513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int cursor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_96 = local_arr[aux % 3];
    acc = (acc + bound_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001795_9513_18(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001795_9513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int offset_58 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_58 > 12) {
        acc = (acc + offset_58 * 2 + 5) & 127;
        aux ^= (offset_58 & 15);
    } else {
        acc = (acc - offset_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_69) & 63;
    acc ^= aux;
    int coefficient_33 = (aux + st.buffer[1]) & 3;
    switch (coefficient_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001795_9513_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001795_9513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_83 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_83 = (pivot_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001795_9513_20(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001795_9513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001795_0;
    int sec_r001795_1;
    int sec_r001795_2;
    int sec_r001795_3;
    int sec_r001795_4;
    int sec_r001795_5;
    int sec_r001795_6;
    int sec_r001795_7;
    int sec_r001795_8;
    int sec_r001795_9;
    int sec_r001795_10;
    int sec_r001795_11;
    int sec_r001795_12;
    int sec_r001795_13;
    int sec_r001795_14;
    int sec_r001795_15;
    int sec_r001795_16;
    int pub_r001795_0;
    int pub_r001795_1;
    int pub_r001795_2;
    int pub_r001795_3;
    int pub_r001795_4;
    int pub_r001795_5;
    int pub_r001795_6;
    int pub_r001795_7;
    int pub_r001795_8;
    int pub_r001795_9;
    int pub_r001795_10;
    int pub_r001795_11;
    int pub_r001795_12;
    int pub_r001795_13;
    int pub_r001795_14;
    int pub_r001795_15;
    int pub_r001795_16;
    int pub_r001795_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001795_0 >= -100 && pub_r001795_0 <= 100);
    __CPROVER_assume(pub_r001795_1 >= -100 && pub_r001795_1 <= 100);
    __CPROVER_assume(pub_r001795_2 >= -100 && pub_r001795_2 <= 100);
    __CPROVER_assume(pub_r001795_3 >= -100 && pub_r001795_3 <= 100);
    __CPROVER_assume(pub_r001795_4 >= -100 && pub_r001795_4 <= 100);
    __CPROVER_assume(pub_r001795_5 >= -100 && pub_r001795_5 <= 100);
    __CPROVER_assume(pub_r001795_6 >= -100 && pub_r001795_6 <= 100);
    __CPROVER_assume(pub_r001795_7 >= -100 && pub_r001795_7 <= 100);
    __CPROVER_assume(pub_r001795_8 >= -100 && pub_r001795_8 <= 100);
    __CPROVER_assume(pub_r001795_9 >= -100 && pub_r001795_9 <= 100);
    __CPROVER_assume(pub_r001795_10 >= -100 && pub_r001795_10 <= 100);
    __CPROVER_assume(pub_r001795_11 >= -100 && pub_r001795_11 <= 100);
    __CPROVER_assume(pub_r001795_12 >= -100 && pub_r001795_12 <= 100);
    __CPROVER_assume(pub_r001795_13 >= -100 && pub_r001795_13 <= 100);
    __CPROVER_assume(pub_r001795_14 >= -100 && pub_r001795_14 <= 100);
    __CPROVER_assume(pub_r001795_15 >= -100 && pub_r001795_15 <= 100);
    __CPROVER_assume(pub_r001795_16 >= -100 && pub_r001795_16 <= 100);
    __CPROVER_assume(pub_r001795_17 >= -100 && pub_r001795_17 <= 100);
    __CPROVER_assume(sec_r001795_0 >= 0 && sec_r001795_0 <= 255);
    __CPROVER_assume(sec_r001795_1 >= 0 && sec_r001795_1 <= 255);
    __CPROVER_assume(sec_r001795_2 >= 0 && sec_r001795_2 <= 255);
    __CPROVER_assume(sec_r001795_3 >= 0 && sec_r001795_3 <= 255);
    __CPROVER_assume(sec_r001795_4 >= 0 && sec_r001795_4 <= 255);
    __CPROVER_assume(sec_r001795_5 >= 0 && sec_r001795_5 <= 255);
    __CPROVER_assume(sec_r001795_6 >= 0 && sec_r001795_6 <= 255);
    __CPROVER_assume(sec_r001795_7 >= 0 && sec_r001795_7 <= 255);
    __CPROVER_assume(sec_r001795_8 >= 0 && sec_r001795_8 <= 255);
    __CPROVER_assume(sec_r001795_9 >= 0 && sec_r001795_9 <= 255);
    __CPROVER_assume(sec_r001795_10 >= 0 && sec_r001795_10 <= 255);
    __CPROVER_assume(sec_r001795_11 >= 0 && sec_r001795_11 <= 255);
    __CPROVER_assume(sec_r001795_12 >= 0 && sec_r001795_12 <= 255);
    __CPROVER_assume(sec_r001795_13 >= 0 && sec_r001795_13 <= 255);
    __CPROVER_assume(sec_r001795_14 >= 0 && sec_r001795_14 <= 255);
    __CPROVER_assume(sec_r001795_15 >= 0 && sec_r001795_15 <= 255);
    __CPROVER_assume(sec_r001795_16 >= 0 && sec_r001795_16 <= 255);

    struct AudioFrame_R001795_9513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001795_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001795_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001795_0 + 7) & 15;
    struct FilterState_R001795_9513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001795_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001795_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001795_0 + 9) & 15;
    struct MatrixBlock_R001795_9513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001795_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001795_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001795_0 + 11) & 15;
    struct EventLog_R001795_9513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001795_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001795_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001795_0 + 13) & 15;

    union PacketPayload_R001795_9513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001795_9513_0(sec_r001795_0, sec_r001795_1, pub_r001795_2, pub_r001795_3);
    int helper_flow_1 = fn_R001795_9513_1(sec_r001795_1, pub_r001795_2, pub_r001795_3, pub_r001795_4);
    int helper_flow_2 = fn_R001795_9513_2(sec_r001795_2, sec_r001795_3, pub_r001795_4, pub_r001795_5);
    int helper_flow_3 = fn_R001795_9513_3(sec_r001795_3, sec_r001795_4, pub_r001795_5, pub_r001795_6);
    int helper_flow_4 = fn_R001795_9513_4(sec_r001795_4, sec_r001795_5, pub_r001795_6, pub_r001795_7);
    int helper_flow_5 = fn_R001795_9513_5(sec_r001795_5, sec_r001795_6, pub_r001795_7, pub_r001795_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_1 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001795_2 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001795_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001795_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001795_14 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001795_9 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001795_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001795_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001795_2 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001795_11 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001795_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001795_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001795_7 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001795_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001795_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001795_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001795_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001795_12 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001795_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_17 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001795_3 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001795_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_5 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_0 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_22 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001795_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001795_9 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001795_4 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001795_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_1 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001795_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_27 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_22 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001795_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001795_6 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_27 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_29 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001795_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001795_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001795_14 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001795_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_24 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_9 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001795_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_27 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001795_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_26 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001795_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001795_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001795_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_2 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_27 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001795_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001795_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001795_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001795_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001795_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001795_3 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_0 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001795_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001795_2 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001795_5 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_51 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001795_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001795_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_23 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001795_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001795_7 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001795_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_4 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001795_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_60 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_50 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001795_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001795_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_41 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001795_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001795_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001795_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001795_16 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_42 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001795_0 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001795_4 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001795_5 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001795_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_24 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001795_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001795_13 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001795_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_75 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001795_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001795_6 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001795_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_9 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((helper_flow_3 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_42 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_94 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001795_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_26 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001795_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001795_3 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001795_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001795_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_96 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_60 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001795_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001795_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_46 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001795_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_24 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001795_13 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001795_8 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001795_5 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001795_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001795_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_5 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_98 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001795_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_115 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001795_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001795_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001795_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_109 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_34 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_100 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_82 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001795_6 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001795_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001795_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_72 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001795_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001795_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_104 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001795_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_20 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001795_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_134 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001795_11 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001795_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_9 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001795_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001795_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001795_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001795_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_93 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_67 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001795_14 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_34 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001795_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001795_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001795_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_125 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_107 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_94 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001795_2 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_61 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_72 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001795_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_80 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001795_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001795_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_65 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_91 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001795_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001795_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_24 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_20 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001795_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001795_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_4 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_112 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r001795_8 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001795_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_44 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001795_13 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001795_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001795_1 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001795_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_107 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_93 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_20 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001795_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_180 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001795_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001795_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001795_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_145 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_147 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_98 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001795_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001795_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_187 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_39 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001795_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_17 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001795_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001795_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001795_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001795_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_96 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001795_7 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001795_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001795_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_75 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001795_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001795_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_139 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001795_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001795_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001795_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_98 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_12 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001795_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001795_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_46 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001795_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_1 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_176 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001795_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001795_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001795_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001795_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_69 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001795_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001795_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001795_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001795_1 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_180 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_12 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_191 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((helper_flow_4 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001795_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001795_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001795_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_31 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_182 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_165 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001795_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001795_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_27 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001795_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_104 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001795_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_41 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_227 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_26 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001795_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001795_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((sec_r001795_7 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_216 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_67 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001795_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r001795_6 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_243 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001795_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_112 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_122 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_23 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_29 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r001795_13 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001795_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001795_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_214 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001795_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_139 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001795_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_98 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001795_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001795_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001795_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001795_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001795_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_255 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_41 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_61 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001795_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001795_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_123 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001795_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001795_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001795_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001795_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_191 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001795_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001795_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_136 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001795_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_156 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001795_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001795_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_272 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r001795_10 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001795_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_79 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001795_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001795_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_272 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_191 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_51 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_134 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_199 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001795_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001795_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_103 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001795_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001795_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_44 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_300 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_226 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_154 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_65 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001795_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001795_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001795_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001795_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001795_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001795_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001795_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001795_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_62 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001795_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001795_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001795_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_236 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001795_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001795_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_1 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_24 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_46 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001795_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_62 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_79 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_8 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001795_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_194 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((helper_flow_2 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001795_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_229 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001795_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001795_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001795_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_191 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_75 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001795_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001795_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001795_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_110 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001795_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001795_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_236 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_170 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_155 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_227 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_126 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_155 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001795_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((helper_flow_1 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_319 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001795_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001795_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_346 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001795_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_360 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((sec_r001795_1 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_110 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_360 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_91 << 1) ^ (pub_r001795_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_266 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((helper_flow_5 << 1) ^ (pub_r001795_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001795_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_241 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_57 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001795_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_306 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_176 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001795_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_351 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_362 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001795_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001795_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_362 << 1) ^ (pub_r001795_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_111 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_236 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001795_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001795_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001795_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_236 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_158 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_80 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_307 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_349 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_67 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001795_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_226 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001795_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_72 << 1) ^ (pub_r001795_5 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_309 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001795_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001795_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_83 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_274 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_107 << 1) ^ (pub_r001795_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001795_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_94 << 1) ^ (pub_r001795_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_171 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_377 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_61 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((helper_flow_5 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001795_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001795_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_387 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_191 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_17 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001795_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001795_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_35 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_290 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001795_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001795_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_365 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_323 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_352 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_310 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001795_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001795_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_136 << 1) ^ (pub_r001795_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_296 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_299 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001795_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001795_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_391 << 1) ^ (pub_r001795_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_103 << 1) ^ (pub_r001795_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001795_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_122 << 1) ^ (pub_r001795_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001795_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_75 << 1) ^ (pub_r001795_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001795_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001795_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001795_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001795_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001795_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001795_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001795_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_129 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_309 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001795_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_129 << 1) ^ (pub_r001795_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_144 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001795_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_274 << 1) ^ (pub_r001795_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001795_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_67 << 1) ^ (pub_r001795_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001795_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001795_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001795_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001795_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((helper_flow_0 << 1) ^ (pub_r001795_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_456 + 1) & 15;
    out_sink ^= (stage_v_456 & 63);

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001795_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001795_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_110 << 1) ^ (pub_r001795_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_146 << 1) ^ (pub_r001795_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_42 << 1) ^ (pub_r001795_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001795_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
