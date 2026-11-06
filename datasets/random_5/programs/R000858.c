/*
 * Benchmark Program: R000858
 * Security Family: secret_dependent_loops
 * Generator Seed: 585813
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000858_5813_0 {
    int sample_rate;
    int envelope;
    short channels;
    int peak;
    int rms;
    int buffer[3];
};

struct SensorNode_R000858_5813_1 {
    unsigned char offset;
    int reading;
    unsigned char gain;
    int buffer[3];
};

struct Transaction_R000858_5813_2 {
    short fee;
    unsigned char status;
    int balance;
    int rate;
    int auth_code;
    int buffer[3];
};

struct EventLog_R000858_5813_3 {
    short timestamp;
    unsigned char facility;
    int code;
    int signature;
    int severity;
    int buffer[3];
};

union TelemetryField_R000858_5813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000858_5813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000858_5813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000858_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_70) & 63;
    acc ^= aux;
    int segment_79 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_79 > 14) {
        acc = (acc + segment_79 * 2 + 5) & 127;
        aux ^= (segment_79 & 15);
    } else {
        acc = (acc - segment_79 + 11) & 127;
        aux += 3;
    }
    int delta_31 = (aux + st.buffer[1]) & 3;
    switch (delta_31) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_1(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000858_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int checksum_93 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_93 > 29) {
        acc = (acc + checksum_93 * 2 + 5) & 127;
        aux ^= (checksum_93 & 15);
    } else {
        acc = (acc - checksum_93 + 11) & 127;
        aux += 3;
    }
    int tracker_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_17 = local_arr[aux % 3];
    acc = (acc + window_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quotient_51 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_51 > 36) {
        acc = (acc + quotient_51 * 2 + 5) & 127;
        aux ^= (quotient_51 & 15);
    } else {
        acc = (acc - quotient_51 + 11) & 127;
        aux += 3;
    }
    int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000858_5813_3(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000858_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int quotient_90 = local_arr[aux % 3];
    acc = (acc + quotient_90 * 2) & 127;
    int phase_95 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_95 > 44) {
        acc = (acc + phase_95 * 2 + 5) & 127;
        aux ^= (phase_95 & 15);
    } else {
        acc = (acc - phase_95 + 11) & 127;
        aux += 3;
    }
    int quantum_23 = (aux + st.buffer[1]) & 3;
    switch (quantum_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000858_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_58 = (aux + st.buffer[1]) & 3;
    switch (quotient_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_65 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_65 > 28) {
        acc = (acc + stride_65 * 2 + 5) & 127;
        aux ^= (stride_65 & 15);
    } else {
        acc = (acc - stride_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_12 = local_arr[aux % 3];
    acc = (acc + coefficient_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_5(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int checksum_71 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_71 > 48) {
        acc = (acc + checksum_71 * 2 + 5) & 127;
        aux ^= (checksum_71 & 15);
    } else {
        acc = (acc - checksum_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_89 = local_arr[aux % 3];
    acc = (acc + metric_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_6(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_53 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_53 > 13) {
        acc = (acc + sample_53 * 2 + 5) & 127;
        aux ^= (sample_53 & 15);
    } else {
        acc = (acc - sample_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000858_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int delta_17 = local_arr[aux % 3];
    acc = (acc + delta_17 * 2) & 127;
    int scale_46 = (aux + st.buffer[1]) & 3;
    switch (scale_46) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_37) & 63;
    acc ^= aux;
    int metric_56 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_56 > 23) {
        acc = (acc + metric_56 * 2 + 5) & 127;
        aux ^= (metric_56 & 15);
    } else {
        acc = (acc - metric_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000858_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int damping_55 = (aux + st.buffer[1]) & 3;
    switch (damping_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_20 > 30) {
        acc = (acc + cursor_20 * 2 + 5) & 127;
        aux ^= (cursor_20 & 15);
    } else {
        acc = (acc - cursor_20 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_9(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int sample_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000858_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_20 = (st.buffer[0] * 3 + aux) & 63;
    if (window_20 > 30) {
        acc = (acc + window_20 * 2 + 5) & 127;
        aux ^= (window_20 & 15);
    } else {
        acc = (acc - window_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_11(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000858_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_15 = (aux + st.buffer[1]) & 3;
    switch (pivot_15) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_41 = local_arr[aux % 3];
    acc = (acc + window_41 * 2) & 127;
    int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000858_5813_12(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000858_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_88 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_88 > 50) {
        acc = (acc + tally_88 * 2 + 5) & 127;
        aux ^= (tally_88 & 15);
    } else {
        acc = (acc - tally_88 + 11) & 127;
        aux += 3;
    }
    int phase_93 = (aux + st.buffer[1]) & 3;
    switch (phase_93) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000858_5813_13(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000858_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int scale_45 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_45 > 14) {
        acc = (acc + scale_45 * 2 + 5) & 127;
        aux ^= (scale_45 & 15);
    } else {
        acc = (acc - scale_45 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_20 = local_arr[aux % 3];
    acc = (acc + tally_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_26 = (aux + st.buffer[1]) & 3;
    switch (sample_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_45) & 63;
    acc ^= aux;
    int delta_78 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_78 > 10) {
        acc = (acc + delta_78 * 2 + 5) & 127;
        aux ^= (delta_78 & 15);
    } else {
        acc = (acc - delta_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000858_5813_15(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000858_5813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_13 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_13 > 41) {
        acc = (acc + vector_13 * 2 + 5) & 127;
        aux ^= (vector_13 & 15);
    } else {
        acc = (acc - vector_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_13 = local_arr[aux % 3];
    acc = (acc + sample_13 * 2) & 127;
    int threshold_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_15) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000858_5813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000858_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_32 = (aux + st.buffer[1]) & 3;
    switch (bound_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_70 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_70 > 47) {
        acc = (acc + mask_70 * 2 + 5) & 127;
        aux ^= (mask_70 & 15);
    } else {
        acc = (acc - mask_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000858_5813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000858_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_97 = local_arr[aux % 3];
    acc = (acc + tally_97 * 2) & 127;
    int mask_52 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_52 > 44) {
        acc = (acc + mask_52 * 2 + 5) & 127;
        aux ^= (mask_52 & 15);
    } else {
        acc = (acc - mask_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000858_0;
    int sec_r000858_1;
    int sec_r000858_2;
    int sec_r000858_3;
    int sec_r000858_4;
    int sec_r000858_5;
    int sec_r000858_6;
    int sec_r000858_7;
    int sec_r000858_8;
    int sec_r000858_9;
    int sec_r000858_10;
    int sec_r000858_11;
    int sec_r000858_12;
    int sec_r000858_13;
    int sec_r000858_14;
    int sec_r000858_15;
    int sec_r000858_16;
    int sec_r000858_17;
    int sec_r000858_18;
    int pub_r000858_0;
    int pub_r000858_1;
    int pub_r000858_2;
    int pub_r000858_3;
    int pub_r000858_4;
    int pub_r000858_5;
    int pub_r000858_6;
    int pub_r000858_7;
    int pub_r000858_8;
    int pub_r000858_9;
    int pub_r000858_10;
    int pub_r000858_11;
    int pub_r000858_12;
    int pub_r000858_13;
    int pub_r000858_14;
    int pub_r000858_15;
    int pub_r000858_16;
    int pub_r000858_17;
    int pub_r000858_18;
    int pub_r000858_19;
    int pub_r000858_20;
    int pub_r000858_21;
    int pub_r000858_22;
    int pub_r000858_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000858_0 >= -100 && pub_r000858_0 <= 100);
    __CPROVER_assume(pub_r000858_1 >= -100 && pub_r000858_1 <= 100);
    __CPROVER_assume(pub_r000858_2 >= -100 && pub_r000858_2 <= 100);
    __CPROVER_assume(pub_r000858_3 >= -100 && pub_r000858_3 <= 100);
    __CPROVER_assume(pub_r000858_4 >= -100 && pub_r000858_4 <= 100);
    __CPROVER_assume(pub_r000858_5 >= -100 && pub_r000858_5 <= 100);
    __CPROVER_assume(pub_r000858_6 >= -100 && pub_r000858_6 <= 100);
    __CPROVER_assume(pub_r000858_7 >= -100 && pub_r000858_7 <= 100);
    __CPROVER_assume(pub_r000858_8 >= -100 && pub_r000858_8 <= 100);
    __CPROVER_assume(pub_r000858_9 >= -100 && pub_r000858_9 <= 100);
    __CPROVER_assume(pub_r000858_10 >= -100 && pub_r000858_10 <= 100);
    __CPROVER_assume(pub_r000858_11 >= -100 && pub_r000858_11 <= 100);
    __CPROVER_assume(pub_r000858_12 >= -100 && pub_r000858_12 <= 100);
    __CPROVER_assume(pub_r000858_13 >= -100 && pub_r000858_13 <= 100);
    __CPROVER_assume(pub_r000858_14 >= -100 && pub_r000858_14 <= 100);
    __CPROVER_assume(pub_r000858_15 >= -100 && pub_r000858_15 <= 100);
    __CPROVER_assume(pub_r000858_16 >= -100 && pub_r000858_16 <= 100);
    __CPROVER_assume(pub_r000858_17 >= -100 && pub_r000858_17 <= 100);
    __CPROVER_assume(pub_r000858_18 >= -100 && pub_r000858_18 <= 100);
    __CPROVER_assume(pub_r000858_19 >= -100 && pub_r000858_19 <= 100);
    __CPROVER_assume(pub_r000858_20 >= -100 && pub_r000858_20 <= 100);
    __CPROVER_assume(pub_r000858_21 >= -100 && pub_r000858_21 <= 100);
    __CPROVER_assume(pub_r000858_22 >= -100 && pub_r000858_22 <= 100);
    __CPROVER_assume(pub_r000858_23 >= -100 && pub_r000858_23 <= 100);
    __CPROVER_assume(sec_r000858_0 >= 0 && sec_r000858_0 <= 255);
    __CPROVER_assume(sec_r000858_1 >= 0 && sec_r000858_1 <= 255);
    __CPROVER_assume(sec_r000858_2 >= 0 && sec_r000858_2 <= 255);
    __CPROVER_assume(sec_r000858_3 >= 0 && sec_r000858_3 <= 255);
    __CPROVER_assume(sec_r000858_4 >= 0 && sec_r000858_4 <= 255);
    __CPROVER_assume(sec_r000858_5 >= 0 && sec_r000858_5 <= 255);
    __CPROVER_assume(sec_r000858_6 >= 0 && sec_r000858_6 <= 255);
    __CPROVER_assume(sec_r000858_7 >= 0 && sec_r000858_7 <= 255);
    __CPROVER_assume(sec_r000858_8 >= 0 && sec_r000858_8 <= 255);
    __CPROVER_assume(sec_r000858_9 >= 0 && sec_r000858_9 <= 255);
    __CPROVER_assume(sec_r000858_10 >= 0 && sec_r000858_10 <= 255);
    __CPROVER_assume(sec_r000858_11 >= 0 && sec_r000858_11 <= 255);
    __CPROVER_assume(sec_r000858_12 >= 0 && sec_r000858_12 <= 255);
    __CPROVER_assume(sec_r000858_13 >= 0 && sec_r000858_13 <= 255);
    __CPROVER_assume(sec_r000858_14 >= 0 && sec_r000858_14 <= 255);
    __CPROVER_assume(sec_r000858_15 >= 0 && sec_r000858_15 <= 255);
    __CPROVER_assume(sec_r000858_16 >= 0 && sec_r000858_16 <= 255);
    __CPROVER_assume(sec_r000858_17 >= 0 && sec_r000858_17 <= 255);
    __CPROVER_assume(sec_r000858_18 >= 0 && sec_r000858_18 <= 255);

    struct AudioFrame_R000858_5813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000858_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000858_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000858_0 + 7) & 15;
    struct SensorNode_R000858_5813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000858_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000858_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000858_0 + 9) & 15;
    struct Transaction_R000858_5813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000858_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000858_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000858_0 + 11) & 15;
    struct EventLog_R000858_5813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000858_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000858_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000858_0 + 13) & 15;

    union TelemetryField_R000858_5813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 39) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 16) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 31) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 36) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 51) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 26) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 41) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 30) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 45) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 27) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 42) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 12) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 27) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 24) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 39) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 13) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 28) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 15) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 30) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 25) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 40) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 13) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 28) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 18) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 33) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 11) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 26) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 21) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 36) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 19) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 34) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 22) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 37) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 26) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 41) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 25) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 40) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 33) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 48) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_5 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000858_0) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000858_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_3 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000858_19) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000858_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_10 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000858_5) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000858_22) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000858_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000858_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_4 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000858_9) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000858_17) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000858_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000858_13) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000858_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_18 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000858_6) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000858_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_7 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000858_1) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000858_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000858_23) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000858_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000858_23) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000858_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_5 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000858_0) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000858_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_3 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000858_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_0 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000858_20) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000858_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_14 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000858_12) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000858_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000858_13) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000858_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000858_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000858_14) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000858_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000858_17) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000858_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_0 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000858_23) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000858_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000858_12) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000858_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_1 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000858_0) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000858_16) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000858_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000858_6) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000858_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000858_9) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000858_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000858_6) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000858_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_10 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000858_13) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000858_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000858_4) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000858_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000858_20) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000858_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_10 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000858_22) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000858_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000858_14) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000858_23) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000858_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000858_8) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000858_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000858_4) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000858_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_3 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000858_10) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000858_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000858_3) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000858_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000858_9) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_8 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000858_5) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000858_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000858_5) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_14 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000858_14) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000858_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000858_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000858_13) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000858_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000858_7) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000858_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000858_5) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000858_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_12 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000858_20) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000858_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_9 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000858_1) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000858_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000858_6) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000858_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000858_16) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000858_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_9 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000858_4) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000858_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_7 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000858_15) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000858_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000858_5) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000858_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000858_10) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000858_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000858_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000858_4) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000858_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000858_22) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000858_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000858_2) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000858_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000858_23) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_17 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000858_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000858_10) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000858_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_3 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000858_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000858_14) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000858_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_17 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000858_14) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000858_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000858_21) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000858_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_6 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000858_15) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000858_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_9 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000858_10) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000858_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000858_1) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000858_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000858_1) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000858_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000858_11) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000858_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_16 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000858_20) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000858_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000858_2) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000858_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_14 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000858_2) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000858_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000858_9) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000858_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_13 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000858_12) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000858_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_2 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000858_2) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000858_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_13 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000858_7) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000858_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_3 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000858_0) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000858_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_107 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000858_1) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000858_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000858_16) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000858_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_14 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000858_18) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000858_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_0 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000858_4) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000858_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000858_8) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000858_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000858_16) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000858_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_147 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000858_13) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000858_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_7 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000858_15) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000858_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000858_9) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000858_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000858_15 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000858_15) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000858_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
