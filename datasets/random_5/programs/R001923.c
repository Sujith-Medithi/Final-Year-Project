/*
 * Benchmark Program: R001923
 * Security Family: multi_step_explicit
 * Generator Seed: 692313
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001923_2313_0 {
    int sample_rate;
    short gain;
    int channels;
    int envelope;
    int buffer[3];
};

struct EventLog_R001923_2313_1 {
    short code;
    int signature;
    int facility;
    short severity;
    unsigned char seq;
    int buffer[3];
};

struct StreamBuffer_R001923_2313_2 {
    int head;
    unsigned char checksum;
    short state;
    int buffer[3];
};

struct Vector3D_R001923_2313_3 {
    unsigned char coord_x;
    int pitch;
    unsigned char norm_sq;
    int heading;
    short coord_z;
    int coord_y;
    int buffer[3];
};

union ColorPixel_R001923_2313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001923_2313_0(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_62 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_62 = (coefficient_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001923_2313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_18 = 0;
    for (int k = 0; k < 2; k++) {
        weight_18 = (weight_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_18) & 127;
    }
    int quantum_35 = (aux + st.buffer[1]) & 3;
    switch (quantum_35) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001923_2313_2(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int stride_47 = local_arr[aux % 3];
    acc = (acc + stride_47 * 2) & 127;
    int metric_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_12) & 63;
    acc ^= aux;
    int tally_64 = 0;
    for (int k = 0; k < 3; k++) {
        tally_64 = (tally_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_64) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001923_2313_3(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001923_2313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_85 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_85 = (quantum_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_85) & 127;
    }
    int tracker_81 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_81 > 30) {
        acc = (acc + tracker_81 * 2 + 5) & 127;
        aux ^= (tracker_81 & 15);
    } else {
        acc = (acc - tracker_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_4(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001923_2313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_58 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_58 > 34) {
        acc = (acc + factor_58 * 2 + 5) & 127;
        aux ^= (factor_58 & 15);
    } else {
        acc = (acc - factor_58 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_21 = local_arr[aux % 3];
    acc = (acc + index_reg_21 * 2) & 127;
    int factor_35 = (aux + st.buffer[1]) & 3;
    switch (factor_35) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_44 = 0;
    for (int k = 0; k < 2; k++) {
        factor_44 = (factor_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_5(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_38 = (aux + st.buffer[1]) & 3;
    switch (damping_38) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001923_2313_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001923_2313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int vector_84 = local_arr[aux % 3];
    acc = (acc + vector_84 * 2) & 127;
    int bound_15 = (aux + st.buffer[1]) & 3;
    switch (bound_15) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_21 = 0;
    for (int k = 0; k < 2; k++) {
        scale_21 = (scale_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001923_2313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int metric_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_63) & 63;
    acc ^= aux;
    int delta_25 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_25 > 27) {
        acc = (acc + delta_25 * 2 + 5) & 127;
        aux ^= (delta_25 & 15);
    } else {
        acc = (acc - delta_25 + 11) & 127;
        aux += 3;
    }
    int scale_25 = 0;
    for (int k = 0; k < 3; k++) {
        scale_25 = (scale_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_25) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_8(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001923_2313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int weight_75 = 0;
    for (int k = 0; k < 2; k++) {
        weight_75 = (weight_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_75) & 127;
    }
    int stride_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001923_2313_9(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_85 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_85 > 41) {
        acc = (acc + accumulator_85 * 2 + 5) & 127;
        aux ^= (accumulator_85 & 15);
    } else {
        acc = (acc - accumulator_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_47 = local_arr[aux % 3];
    acc = (acc + weight_47 * 2) & 127;
    int accumulator_35 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_35 = (accumulator_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_35) & 127;
    }
    int phase_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001923_2313_10(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001923_2313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int vector_49 = local_arr[aux % 3];
    acc = (acc + vector_49 * 2) & 127;
    int segment_55 = 0;
    for (int k = 0; k < 3; k++) {
        segment_55 = (segment_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001923_2313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_12) & 63;
    acc ^= aux;
    int margin_91 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_91 > 34) {
        acc = (acc + margin_91 * 2 + 5) & 127;
        aux ^= (margin_91 & 15);
    } else {
        acc = (acc - margin_91 + 11) & 127;
        aux += 3;
    }
    int phase_21 = 0;
    for (int k = 0; k < 3; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_12(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001923_2313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_28 = (st.buffer[0] * 3 + aux) & 63;
    if (window_28 > 39) {
        acc = (acc + window_28 * 2 + 5) & 127;
        aux ^= (window_28 & 15);
    } else {
        acc = (acc - window_28 + 11) & 127;
        aux += 3;
    }
    int tracker_11 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_11 = (tracker_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_13(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_82) & 63;
    acc ^= aux;
    int parity_60 = 0;
    for (int k = 0; k < 3; k++) {
        parity_60 = (parity_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_60) & 127;
    }
    int delta_11 = (aux + st.buffer[1]) & 3;
    switch (delta_11) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_62 = local_arr[aux % 3];
    acc = (acc + sample_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001923_2313_14(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001923_2313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_93 = (aux + st.buffer[1]) & 3;
    switch (window_93) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_15 = local_arr[aux % 3];
    acc = (acc + sample_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001923_2313_15(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int stride_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_97) & 63;
    acc ^= aux;
    int phase_79 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_79 > 25) {
        acc = (acc + phase_79 * 2 + 5) & 127;
        aux ^= (phase_79 & 15);
    } else {
        acc = (acc - phase_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001923_2313_16(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int vector_85 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_85 > 16) {
        acc = (acc + vector_85 * 2 + 5) & 127;
        aux ^= (vector_85 & 15);
    } else {
        acc = (acc - vector_85 + 11) & 127;
        aux += 3;
    }
    int metric_36 = 0;
    for (int k = 0; k < 2; k++) {
        metric_36 = (metric_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_36) & 127;
    }
    int bound_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001923_2313_17(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001923_2313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_83 = local_arr[aux % 3];
    acc = (acc + checksum_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001923_2313_18(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001923_2313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int checksum_97 = local_arr[aux % 3];
    acc = (acc + checksum_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001923_0;
    int sec_r001923_1;
    int sec_r001923_2;
    int sec_r001923_3;
    int sec_r001923_4;
    int sec_r001923_5;
    int sec_r001923_6;
    int sec_r001923_7;
    int sec_r001923_8;
    int sec_r001923_9;
    int sec_r001923_10;
    int sec_r001923_11;
    int sec_r001923_12;
    int sec_r001923_13;
    int sec_r001923_14;
    int sec_r001923_15;
    int sec_r001923_16;
    int sec_r001923_17;
    int sec_r001923_18;
    int sec_r001923_19;
    int sec_r001923_20;
    int sec_r001923_21;
    int sec_r001923_22;
    int sec_r001923_23;
    int pub_r001923_0;
    int pub_r001923_1;
    int pub_r001923_2;
    int pub_r001923_3;
    int pub_r001923_4;
    int pub_r001923_5;
    int pub_r001923_6;
    int pub_r001923_7;
    int pub_r001923_8;
    int pub_r001923_9;
    int pub_r001923_10;
    int pub_r001923_11;
    int pub_r001923_12;
    int pub_r001923_13;
    int pub_r001923_14;
    int pub_r001923_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001923_0 >= -100 && pub_r001923_0 <= 100);
    __CPROVER_assume(pub_r001923_1 >= -100 && pub_r001923_1 <= 100);
    __CPROVER_assume(pub_r001923_2 >= -100 && pub_r001923_2 <= 100);
    __CPROVER_assume(pub_r001923_3 >= -100 && pub_r001923_3 <= 100);
    __CPROVER_assume(pub_r001923_4 >= -100 && pub_r001923_4 <= 100);
    __CPROVER_assume(pub_r001923_5 >= -100 && pub_r001923_5 <= 100);
    __CPROVER_assume(pub_r001923_6 >= -100 && pub_r001923_6 <= 100);
    __CPROVER_assume(pub_r001923_7 >= -100 && pub_r001923_7 <= 100);
    __CPROVER_assume(pub_r001923_8 >= -100 && pub_r001923_8 <= 100);
    __CPROVER_assume(pub_r001923_9 >= -100 && pub_r001923_9 <= 100);
    __CPROVER_assume(pub_r001923_10 >= -100 && pub_r001923_10 <= 100);
    __CPROVER_assume(pub_r001923_11 >= -100 && pub_r001923_11 <= 100);
    __CPROVER_assume(pub_r001923_12 >= -100 && pub_r001923_12 <= 100);
    __CPROVER_assume(pub_r001923_13 >= -100 && pub_r001923_13 <= 100);
    __CPROVER_assume(pub_r001923_14 >= -100 && pub_r001923_14 <= 100);
    __CPROVER_assume(pub_r001923_15 >= -100 && pub_r001923_15 <= 100);
    __CPROVER_assume(sec_r001923_0 >= 0 && sec_r001923_0 <= 255);
    __CPROVER_assume(sec_r001923_1 >= 0 && sec_r001923_1 <= 255);
    __CPROVER_assume(sec_r001923_2 >= 0 && sec_r001923_2 <= 255);
    __CPROVER_assume(sec_r001923_3 >= 0 && sec_r001923_3 <= 255);
    __CPROVER_assume(sec_r001923_4 >= 0 && sec_r001923_4 <= 255);
    __CPROVER_assume(sec_r001923_5 >= 0 && sec_r001923_5 <= 255);
    __CPROVER_assume(sec_r001923_6 >= 0 && sec_r001923_6 <= 255);
    __CPROVER_assume(sec_r001923_7 >= 0 && sec_r001923_7 <= 255);
    __CPROVER_assume(sec_r001923_8 >= 0 && sec_r001923_8 <= 255);
    __CPROVER_assume(sec_r001923_9 >= 0 && sec_r001923_9 <= 255);
    __CPROVER_assume(sec_r001923_10 >= 0 && sec_r001923_10 <= 255);
    __CPROVER_assume(sec_r001923_11 >= 0 && sec_r001923_11 <= 255);
    __CPROVER_assume(sec_r001923_12 >= 0 && sec_r001923_12 <= 255);
    __CPROVER_assume(sec_r001923_13 >= 0 && sec_r001923_13 <= 255);
    __CPROVER_assume(sec_r001923_14 >= 0 && sec_r001923_14 <= 255);
    __CPROVER_assume(sec_r001923_15 >= 0 && sec_r001923_15 <= 255);
    __CPROVER_assume(sec_r001923_16 >= 0 && sec_r001923_16 <= 255);
    __CPROVER_assume(sec_r001923_17 >= 0 && sec_r001923_17 <= 255);
    __CPROVER_assume(sec_r001923_18 >= 0 && sec_r001923_18 <= 255);
    __CPROVER_assume(sec_r001923_19 >= 0 && sec_r001923_19 <= 255);
    __CPROVER_assume(sec_r001923_20 >= 0 && sec_r001923_20 <= 255);
    __CPROVER_assume(sec_r001923_21 >= 0 && sec_r001923_21 <= 255);
    __CPROVER_assume(sec_r001923_22 >= 0 && sec_r001923_22 <= 255);
    __CPROVER_assume(sec_r001923_23 >= 0 && sec_r001923_23 <= 255);

    struct AudioFrame_R001923_2313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001923_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001923_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001923_0 + 7) & 15;
    struct EventLog_R001923_2313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001923_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001923_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001923_0 + 9) & 15;
    struct StreamBuffer_R001923_2313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001923_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001923_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001923_0 + 11) & 15;
    struct Vector3D_R001923_2313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001923_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001923_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001923_0 + 13) & 15;

    union ColorPixel_R001923_2313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001923_2313_0(sec_r001923_0, pub_r001923_1, pub_r001923_2);
    int helper_flow_1 = fn_R001923_2313_1(sec_r001923_1, sec_r001923_2, pub_r001923_3, pub_r001923_4, pub_r001923_5);
    int helper_flow_2 = fn_R001923_2313_2(sec_r001923_2, pub_r001923_3);
    int helper_flow_3 = fn_R001923_2313_3(sec_r001923_3, sec_r001923_4, pub_r001923_5);
    int helper_flow_4 = fn_R001923_2313_4(sec_r001923_4, pub_r001923_5);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001923_2 * 3) + pub_r001923_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001923_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001923_22 * 3) + pub_r001923_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001923_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001923_14 * 3) + pub_r001923_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001923_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001923_13 * 3) + pub_r001923_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001923_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001923_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001923_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001923_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001923_20 * 3) + pub_r001923_10 + 40) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11 * 2) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_4 * 3) + pub_r001923_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001923_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001923_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001923_4 * 3) + pub_r001923_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001923_12 * 3) + pub_r001923_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_12 * 3) + pub_r001923_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001923_6 * 3) + pub_r001923_12 + 42) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_4 * 3) + pub_r001923_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001923_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001923_3 * 3) + pub_r001923_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001923_1 * 3) + pub_r001923_2 + 10) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_15 * 3) + pub_r001923_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001923_9 * 3) + pub_r001923_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24 * 2) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001923_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001923_13 * 3) + pub_r001923_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_19 * 3) + pub_r001923_14 + 45) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_15 * 3) + pub_r001923_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001923_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001923_4 * 3) + pub_r001923_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001923_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001923_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001923_2 * 3) + pub_r001923_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001923_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_0 * 3) + pub_r001923_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001923_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001923_19 * 3) + pub_r001923_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37 * 2) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001923_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001923_15 * 3) + pub_r001923_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001923_6 * 3) + pub_r001923_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001923_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_3 * 3) + pub_r001923_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42 * 2) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_3 * 3) + pub_r001923_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001923_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001923_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001923_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001923_12 * 3) + pub_r001923_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_24 * 3) + pub_r001923_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001923_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001923_15 * 3) + pub_r001923_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001923_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_0 * 3) + pub_r001923_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001923_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_48 * 3) + pub_r001923_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001923_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001923_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001923_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_16 * 3) + pub_r001923_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_42 * 3) + pub_r001923_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59 * 2) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001923_13 * 3) + pub_r001923_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001923_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001923_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001923_9 * 3) + pub_r001923_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001923_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001923_21 * 3) + pub_r001923_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_63 * 3) + pub_r001923_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001923_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001923_3 * 3) + pub_r001923_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001923_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001923_0 * 3) + pub_r001923_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001923_11 * 3) + pub_r001923_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001923_9 * 3) + pub_r001923_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001923_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_52 * 3) + pub_r001923_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74 * 2) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001923_1 * 3) + pub_r001923_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001923_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_54 * 3) + pub_r001923_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001923_17 * 3) + pub_r001923_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001923_2 * 3) + pub_r001923_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_71 * 3) + pub_r001923_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001923_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_40 * 3) + pub_r001923_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001923_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001923_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001923_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001923_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001923_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001923_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001923_20 * 3) + pub_r001923_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001923_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001923_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001923_7 * 3) + pub_r001923_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_82 * 3) + pub_r001923_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001923_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001923_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001923_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001923_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001923_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001923_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_60 * 3) + pub_r001923_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_100 * 3) + pub_r001923_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001923_19 * 3) + pub_r001923_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001923_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_18 * 3) + pub_r001923_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001923_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_80 * 3) + pub_r001923_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_0 * 3) + pub_r001923_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001923_7 * 3) + pub_r001923_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001923_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001923_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_12 * 3) + pub_r001923_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_30 * 3) + pub_r001923_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r001923_0 * 3) + pub_r001923_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001923_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001923_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_63 * 3) + pub_r001923_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_59 * 3) + pub_r001923_10 + 12) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_74 * 3) + pub_r001923_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001923_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001923_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_48 * 3) + pub_r001923_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_112 * 3) + pub_r001923_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001923_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_48 * 3) + pub_r001923_6 + 38) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001923_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001923_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001923_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_42 * 3) + pub_r001923_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_118 * 3) + pub_r001923_7 + 12) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_52 * 3) + pub_r001923_4 + 39) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_4 * 3) + pub_r001923_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001923_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001923_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001923_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_112 * 3) + pub_r001923_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001923_11 * 3) + pub_r001923_1 + 41) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001923_9 * 3) + pub_r001923_2 + 43) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_18 * 3) + pub_r001923_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_107 * 3) + pub_r001923_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001923_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_68 * 3) + pub_r001923_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001923_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_71 * 3) + pub_r001923_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001923_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001923_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001923_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001923_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001923_2 * 3) + pub_r001923_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001923_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_30 * 3) + pub_r001923_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_106 * 3) + pub_r001923_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001923_19 * 3) + pub_r001923_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_118 * 3) + pub_r001923_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153 * 2) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001923_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001923_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001923_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001923_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001923_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001923_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001923_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001923_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001923_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001923_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_39 * 3) + pub_r001923_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_136 * 3) + pub_r001923_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001923_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001923_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001923_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001923_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001923_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001923_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001923_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001923_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_16 * 3) + pub_r001923_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001923_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001923_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001923_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001923_23 * 3) + pub_r001923_12 + 15) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001923_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_165 * 3) + pub_r001923_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_39 * 3) + pub_r001923_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181 * 2) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_58 * 3) + pub_r001923_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001923_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001923_8 * 3) + pub_r001923_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_106 * 3) + pub_r001923_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_75 * 3) + pub_r001923_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001923_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001923_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_80 * 3) + pub_r001923_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_148 * 3) + pub_r001923_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_129 * 3) + pub_r001923_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001923_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_27 * 3) + pub_r001923_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001923_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001923_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_174 * 3) + pub_r001923_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_193 * 3) + pub_r001923_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_131 * 3) + pub_r001923_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001923_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_196 * 3) + pub_r001923_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_104 * 3) + pub_r001923_15 + 33) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((helper_flow_2 * 3) + pub_r001923_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001923_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001923_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001923_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001923_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001923_2 * 3) + pub_r001923_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001923_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r001923_11 * 3) + pub_r001923_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209 * 2) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_111 * 3) + pub_r001923_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_190 * 3) + pub_r001923_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_39 * 3) + pub_r001923_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001923_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001923_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001923_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001923_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001923_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_12 * 3) + pub_r001923_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_202 * 3) + pub_r001923_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001923_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_30 * 3) + pub_r001923_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001923_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001923_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001923_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001923_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_24 * 3) + pub_r001923_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r001923_14 * 3) + pub_r001923_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_4 * 3) + pub_r001923_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228 * 2) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001923_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001923_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_100 * 3) + pub_r001923_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001923_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_23 * 3) + pub_r001923_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001923_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001923_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001923_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_228 * 3) + pub_r001923_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001923_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_108 * 3) + pub_r001923_13 + 41) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001923_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001923_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001923_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001923_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001923_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_35 * 3) + pub_r001923_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245 * 2) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_22 * 3) + pub_r001923_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001923_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001923_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001923_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r001923_19 * 3) + pub_r001923_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_59 * 3) + pub_r001923_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001923_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001923_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_17 * 3) + pub_r001923_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001923_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_118 * 3) + pub_r001923_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001923_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001923_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r001923_22 * 3) + pub_r001923_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((helper_flow_4 * 3) + pub_r001923_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_209 * 3) + pub_r001923_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_54 * 3) + pub_r001923_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001923_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001923_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_221 * 3) + pub_r001923_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001923_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001923_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_143 * 3) + pub_r001923_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((helper_flow_0 * 3) + pub_r001923_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_39 * 3) + pub_r001923_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_78 * 3) + pub_r001923_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_4 * 3) + pub_r001923_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272 * 2) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_259 * 3) + pub_r001923_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_11 * 3) + pub_r001923_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001923_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_128 * 3) + pub_r001923_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_185 * 3) + pub_r001923_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_200 * 3) + pub_r001923_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_201 * 3) + pub_r001923_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001923_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001923_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_122 * 3) + pub_r001923_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001923_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_207 * 3) + pub_r001923_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001923_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001923_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_21 * 3) + pub_r001923_10 + 16) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001923_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r001923_4 * 3) + pub_r001923_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_237 * 3) + pub_r001923_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r001923_5 * 3) + pub_r001923_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001923_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_106 * 3) + pub_r001923_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r001923_3 * 3) + pub_r001923_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_152 * 3) + pub_r001923_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_50 * 3) + pub_r001923_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001923_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_282 * 3) + pub_r001923_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298 * 2) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001923_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_48 * 3) + pub_r001923_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((sec_r001923_21 * 3) + pub_r001923_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_33 * 3) + pub_r001923_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_276 * 3) + pub_r001923_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001923_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_130 * 3) + pub_r001923_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001923_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_261 * 3) + pub_r001923_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001923_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001923_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001923_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r001923_16 * 3) + pub_r001923_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001923_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001923_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_293 * 3) + pub_r001923_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001923_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r001923_17 * 3) + pub_r001923_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_294 * 3) + pub_r001923_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((helper_flow_3 * 3) + pub_r001923_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001923_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001923_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001923_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001923_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_78 * 3) + pub_r001923_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001923_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_174 * 3) + pub_r001923_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001923_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_174 * 3) + pub_r001923_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_54 * 3) + pub_r001923_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_131 * 3) + pub_r001923_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001923_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_15 * 3) + pub_r001923_3 + 45) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001923_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_265 * 3) + pub_r001923_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001923_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_59 * 3) + pub_r001923_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_294 * 3) + pub_r001923_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((sec_r001923_20 * 3) + pub_r001923_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_271 * 3) + pub_r001923_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_39 * 3) + pub_r001923_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001923_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_191 * 3) + pub_r001923_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_130 * 3) + pub_r001923_15 + 26) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001923_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_279 * 3) + pub_r001923_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344 * 2) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_18 * 3) + pub_r001923_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001923_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_153 * 3) + pub_r001923_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001923_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001923_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001923_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_130 * 3) + pub_r001923_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_289 * 3) + pub_r001923_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_112 * 3) + pub_r001923_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((sec_r001923_16 * 3) + pub_r001923_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_82 * 3) + pub_r001923_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_70 * 3) + pub_r001923_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_211 * 3) + pub_r001923_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_294 * 3) + pub_r001923_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_107 * 3) + pub_r001923_6 + 33) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_268 * 3) + pub_r001923_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001923_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001923_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_207 * 3) + pub_r001923_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001923_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_141 * 3) + pub_r001923_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001923_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_360 * 3) + pub_r001923_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_165 * 3) + pub_r001923_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001923_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_40 * 3) + pub_r001923_4 + 34) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_226 * 3) + pub_r001923_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_21 * 3) + pub_r001923_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001923_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_17 * 3) + pub_r001923_5 + 22) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001923_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_356 * 3) + pub_r001923_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((helper_flow_0 * 3) + pub_r001923_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377 * 2) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((sec_r001923_15 * 3) + pub_r001923_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001923_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001923_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((sec_r001923_5 * 3) + pub_r001923_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001923_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_276 * 3) + pub_r001923_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001923_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001923_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_77 * 3) + pub_r001923_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_207 * 3) + pub_r001923_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_387) & 255;
    out_sink = (out_sink + stage_v_387 * 2) & 255;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001923_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_250 * 3) + pub_r001923_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001923_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001923_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((sec_r001923_4 * 3) + pub_r001923_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001923_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_335 * 3) + pub_r001923_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_227 * 3) + pub_r001923_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001923_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001923_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_37 * 3) + pub_r001923_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001923_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_211 * 3) + pub_r001923_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_33 * 3) + pub_r001923_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_269 * 3) + pub_r001923_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001923_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((sec_r001923_2 * 3) + pub_r001923_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_82 * 3) + pub_r001923_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((sec_r001923_11 * 3) + pub_r001923_8 + 34) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_122 * 3) + pub_r001923_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_15 * 3) + pub_r001923_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_408) & 255;
    out_sink = (out_sink + stage_v_408 * 2) & 255;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001923_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_193 * 3) + pub_r001923_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001923_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_92 * 3) + pub_r001923_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001923_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001923_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_406 * 3) + pub_r001923_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001923_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_400 * 3) + pub_r001923_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001923_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001923_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001923_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_358 * 3) + pub_r001923_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_117 * 3) + pub_r001923_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_303 * 3) + pub_r001923_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_47 * 3) + pub_r001923_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_21 * 3) + pub_r001923_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001923_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001923_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001923_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_112 * 3) + pub_r001923_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_164 * 3) + pub_r001923_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001923_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001923_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001923_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_300 * 3) + pub_r001923_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_40 * 3) + pub_r001923_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_435) & 255;
    out_sink = (out_sink + stage_v_435 * 2) & 255;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_273 * 3) + pub_r001923_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_269 * 3) + pub_r001923_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_437) & 255;
    out_sink = (out_sink + stage_v_437 * 2) & 255;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_300 * 3) + pub_r001923_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((helper_flow_2 * 3) + pub_r001923_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_410 * 3) + pub_r001923_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001923_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001923_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001923_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001923_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001923_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001923_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_124 * 3) + pub_r001923_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001923_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_269 * 3) + pub_r001923_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_74 * 3) + pub_r001923_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((sec_r001923_22 * 3) + pub_r001923_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001923_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001923_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001923_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((helper_flow_4 * 3) + pub_r001923_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001923_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001923_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001923_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001923_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_429 * 3) + pub_r001923_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((sec_r001923_12 * 3) + pub_r001923_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001923_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_78 * 3) + pub_r001923_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001923_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_59 * 3) + pub_r001923_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_465) & 255;
    out_sink = (out_sink + stage_v_465 * 2) & 255;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_182 * 3) + pub_r001923_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_466) & 255;
    out_sink = (out_sink + stage_v_466 * 2) & 255;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_394 * 3) + pub_r001923_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_383 * 3) + pub_r001923_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_468) & 255;
    out_sink = (out_sink + stage_v_468 * 2) & 255;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001923_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001923_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_417 * 3) + pub_r001923_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((sec_r001923_10 * 3) + pub_r001923_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_415 * 3) + pub_r001923_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001923_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
