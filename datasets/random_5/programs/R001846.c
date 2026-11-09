/*
 * Benchmark Program: R001846
 * Security Family: implicit_flow
 * Generator Seed: 684613
 * High Inputs: 18 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001846_4613_0 {
    unsigned char code;
    int signature;
    int severity;
    short seq;
    short timestamp;
    int facility;
    int buffer[3];
};

struct AudioFrame_R001846_4613_1 {
    unsigned char channels;
    short envelope;
    int gain;
    int sample_rate;
    int buffer[3];
};

union PacketPayload_R001846_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001846_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001846_4613_0(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int checksum_82 = local_arr[aux % 3];
    acc = (acc + checksum_82 * 2) & 127;
    int quantum_34 = (aux + st.buffer[1]) & 3;
    switch (quantum_34) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int coefficient_85 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_85 = (coefficient_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_85) & 127;
    }
    int accumulator_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_74) & 63;
    acc ^= aux;
    int mask_65 = (aux + st.buffer[1]) & 3;
    switch (mask_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001846_4613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_73) & 63;
    acc ^= aux;
    int sample_98 = (aux + st.buffer[1]) & 3;
    switch (sample_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001846_4613_3(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_84 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_84 = (anchor_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_84) & 127;
    }
    int quotient_72 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_72 > 42) {
        acc = (acc + quotient_72 * 2 + 5) & 127;
        aux ^= (quotient_72 & 15);
    } else {
        acc = (acc - quotient_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_22 = local_arr[aux % 3];
    acc = (acc + offset_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_88 = 0;
    for (int k = 0; k < 3; k++) {
        weight_88 = (weight_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_88) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_78 = local_arr[aux % 3];
    acc = (acc + cursor_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_5(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_46 = (st.buffer[0] * 3 + aux) & 63;
    if (window_46 > 37) {
        acc = (acc + window_46 * 2 + 5) & 127;
        aux ^= (window_46 & 15);
    } else {
        acc = (acc - window_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_47 = local_arr[aux % 3];
    acc = (acc + metric_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_15 = (aux + st.buffer[1]) & 3;
    switch (quotient_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_30 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_30 > 45) {
        acc = (acc + sample_30 * 2 + 5) & 127;
        aux ^= (sample_30 & 15);
    } else {
        acc = (acc - sample_30 + 11) & 127;
        aux += 3;
    }
    int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001846_4613_7(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_16 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_16 = (pivot_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_16) & 127;
    }
    int segment_70 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_70 > 45) {
        acc = (acc + segment_70 * 2 + 5) & 127;
        aux ^= (segment_70 & 15);
    } else {
        acc = (acc - segment_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_31 = local_arr[aux % 3];
    acc = (acc + vector_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int anchor_54 = local_arr[aux % 3];
    acc = (acc + anchor_54 * 2) & 127;
    int phase_49 = 0;
    for (int k = 0; k < 3; k++) {
        phase_49 = (phase_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_49) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int checksum_19 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_19 > 14) {
        acc = (acc + checksum_19 * 2 + 5) & 127;
        aux ^= (checksum_19 & 15);
    } else {
        acc = (acc - checksum_19 + 11) & 127;
        aux += 3;
    }
    int quantum_68 = (aux + st.buffer[1]) & 3;
    switch (quantum_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_56 = local_arr[aux % 3];
    acc = (acc + window_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_99 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_99 = (pivot_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_99) & 127;
    }
    int coefficient_22 = (aux + st.buffer[1]) & 3;
    switch (coefficient_22) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001846_4613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_19) & 63;
    acc ^= aux;
    int residue_73 = (aux + st.buffer[1]) & 3;
    switch (residue_73) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001846_4613_12(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_84 = (aux + st.buffer[1]) & 3;
    switch (quotient_84) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_31 = 0;
    for (int k = 0; k < 2; k++) {
        stride_31 = (stride_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_31) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_31 = local_arr[aux % 3];
    acc = (acc + damping_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int residue_16 = (aux + st.buffer[1]) & 3;
    switch (residue_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_47 = 0;
    for (int k = 0; k < 2; k++) {
        parity_47 = (parity_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_47) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001846_4613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_10 = (aux + st.buffer[1]) & 3;
    switch (vector_10) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_13 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_13 > 27) {
        acc = (acc + anchor_13 * 2 + 5) & 127;
        aux ^= (anchor_13 & 15);
    } else {
        acc = (acc - anchor_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001846_4613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001846_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_92 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_92 > 43) {
        acc = (acc + delta_92 * 2 + 5) & 127;
        aux ^= (delta_92 & 15);
    } else {
        acc = (acc - delta_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001846_4613_16(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_43 = 0;
    for (int k = 0; k < 3; k++) {
        tally_43 = (tally_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_43) & 127;
    }
    int parity_64 = (aux + st.buffer[1]) & 3;
    switch (parity_64) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001846_4613_17(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001846_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int parity_36 = local_arr[aux % 3];
    acc = (acc + parity_36 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_81 = (aux + st.buffer[1]) & 3;
    switch (quantum_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001846_0;
    int sec_r001846_1;
    int sec_r001846_2;
    int sec_r001846_3;
    int sec_r001846_4;
    int sec_r001846_5;
    int sec_r001846_6;
    int sec_r001846_7;
    int sec_r001846_8;
    int sec_r001846_9;
    int sec_r001846_10;
    int sec_r001846_11;
    int sec_r001846_12;
    int sec_r001846_13;
    int sec_r001846_14;
    int sec_r001846_15;
    int sec_r001846_16;
    int sec_r001846_17;
    int pub_r001846_0;
    int pub_r001846_1;
    int pub_r001846_2;
    int pub_r001846_3;
    int pub_r001846_4;
    int pub_r001846_5;
    int pub_r001846_6;
    int pub_r001846_7;
    int pub_r001846_8;
    int pub_r001846_9;
    int pub_r001846_10;
    int pub_r001846_11;
    int pub_r001846_12;
    int pub_r001846_13;
    int pub_r001846_14;
    int pub_r001846_15;
    int pub_r001846_16;
    int pub_r001846_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001846_0 >= -100 && pub_r001846_0 <= 100);
    __CPROVER_assume(pub_r001846_1 >= -100 && pub_r001846_1 <= 100);
    __CPROVER_assume(pub_r001846_2 >= -100 && pub_r001846_2 <= 100);
    __CPROVER_assume(pub_r001846_3 >= -100 && pub_r001846_3 <= 100);
    __CPROVER_assume(pub_r001846_4 >= -100 && pub_r001846_4 <= 100);
    __CPROVER_assume(pub_r001846_5 >= -100 && pub_r001846_5 <= 100);
    __CPROVER_assume(pub_r001846_6 >= -100 && pub_r001846_6 <= 100);
    __CPROVER_assume(pub_r001846_7 >= -100 && pub_r001846_7 <= 100);
    __CPROVER_assume(pub_r001846_8 >= -100 && pub_r001846_8 <= 100);
    __CPROVER_assume(pub_r001846_9 >= -100 && pub_r001846_9 <= 100);
    __CPROVER_assume(pub_r001846_10 >= -100 && pub_r001846_10 <= 100);
    __CPROVER_assume(pub_r001846_11 >= -100 && pub_r001846_11 <= 100);
    __CPROVER_assume(pub_r001846_12 >= -100 && pub_r001846_12 <= 100);
    __CPROVER_assume(pub_r001846_13 >= -100 && pub_r001846_13 <= 100);
    __CPROVER_assume(pub_r001846_14 >= -100 && pub_r001846_14 <= 100);
    __CPROVER_assume(pub_r001846_15 >= -100 && pub_r001846_15 <= 100);
    __CPROVER_assume(pub_r001846_16 >= -100 && pub_r001846_16 <= 100);
    __CPROVER_assume(pub_r001846_17 >= -100 && pub_r001846_17 <= 100);
    __CPROVER_assume(sec_r001846_0 >= 0 && sec_r001846_0 <= 255);
    __CPROVER_assume(sec_r001846_1 >= 0 && sec_r001846_1 <= 255);
    __CPROVER_assume(sec_r001846_2 >= 0 && sec_r001846_2 <= 255);
    __CPROVER_assume(sec_r001846_3 >= 0 && sec_r001846_3 <= 255);
    __CPROVER_assume(sec_r001846_4 >= 0 && sec_r001846_4 <= 255);
    __CPROVER_assume(sec_r001846_5 >= 0 && sec_r001846_5 <= 255);
    __CPROVER_assume(sec_r001846_6 >= 0 && sec_r001846_6 <= 255);
    __CPROVER_assume(sec_r001846_7 >= 0 && sec_r001846_7 <= 255);
    __CPROVER_assume(sec_r001846_8 >= 0 && sec_r001846_8 <= 255);
    __CPROVER_assume(sec_r001846_9 >= 0 && sec_r001846_9 <= 255);
    __CPROVER_assume(sec_r001846_10 >= 0 && sec_r001846_10 <= 255);
    __CPROVER_assume(sec_r001846_11 >= 0 && sec_r001846_11 <= 255);
    __CPROVER_assume(sec_r001846_12 >= 0 && sec_r001846_12 <= 255);
    __CPROVER_assume(sec_r001846_13 >= 0 && sec_r001846_13 <= 255);
    __CPROVER_assume(sec_r001846_14 >= 0 && sec_r001846_14 <= 255);
    __CPROVER_assume(sec_r001846_15 >= 0 && sec_r001846_15 <= 255);
    __CPROVER_assume(sec_r001846_16 >= 0 && sec_r001846_16 <= 255);
    __CPROVER_assume(sec_r001846_17 >= 0 && sec_r001846_17 <= 255);

    struct EventLog_R001846_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001846_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001846_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001846_0 + 7) & 15;
    struct AudioFrame_R001846_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001846_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001846_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001846_0 + 9) & 15;

    union PacketPayload_R001846_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001846_4613_0(sec_r001846_0, pub_r001846_1);
    int helper_flow_1 = fn_R001846_4613_1(sec_r001846_1, pub_r001846_2, pub_r001846_3, pub_r001846_4);
    int helper_flow_2 = fn_R001846_4613_2(sec_r001846_2, sec_r001846_3, pub_r001846_4, pub_r001846_5);
    int helper_flow_3 = fn_R001846_4613_3(sec_r001846_3, sec_r001846_4, pub_r001846_5);
    int helper_flow_4 = fn_R001846_4613_4(sec_r001846_4, sec_r001846_5, pub_r001846_6, pub_r001846_7, pub_r001846_8);
    int helper_flow_5 = fn_R001846_4613_5(sec_r001846_5, pub_r001846_6, pub_r001846_7);
    int helper_flow_6 = fn_R001846_4613_6(sec_r001846_6, pub_r001846_7, pub_r001846_8, pub_r001846_9, pub_r001846_10);
    int helper_flow_7 = fn_R001846_4613_7(sec_r001846_7, sec_r001846_8, pub_r001846_9);
    int helper_flow_8 = fn_R001846_4613_8(sec_r001846_8, sec_r001846_9, pub_r001846_10, pub_r001846_11, pub_r001846_12);
    int helper_flow_9 = fn_R001846_4613_9(sec_r001846_9, pub_r001846_10, pub_r001846_11, pub_r001846_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001846_13 + pub_r001846_10 * 2 + 5) & 127;
    if (stage_v_0 > 30) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001846_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001846_16 + pub_r001846_6 * 2 + 11) & 127;
    if (stage_v_2 > 35) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001846_1 + pub_r001846_12 * 2 + 14) & 127;
    if (stage_v_3 > 34) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001846_3 + pub_r001846_0 * 2 + 17) & 127;
    if (stage_v_4 > 47) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001846_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001846_8 + pub_r001846_3 * 2 + 23) & 127;
    if (stage_v_6 > 35) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001846_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001846_9 + pub_r001846_0 * 2 + 29) & 127;
    if (stage_v_8 > 17) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_8 + pub_r001846_17 * 2 + 32) & 127;
    if (stage_v_9 > 34) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_4 + pub_r001846_10 * 2 + 35) & 127;
    if (stage_v_10 > 29) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001846_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001846_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_9 + pub_r001846_2 * 2 + 44) & 127;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001846_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_2 + pub_r001846_10 * 2 + 50) & 127;
    if (stage_v_15 > 47) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001846_10 + pub_r001846_13 * 2 + 53) & 127;
    if (stage_v_16 > 25) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001846_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001846_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_2 + pub_r001846_13 * 2 + 62) & 127;
    if (stage_v_19 > 23) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_3 + pub_r001846_12 * 2 + 65) & 127;
    if (stage_v_20 > 17) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_0 + pub_r001846_2 * 2 + 68) & 127;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_0 + pub_r001846_3 * 2 + 71) & 127;
    if (stage_v_22 > 58) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_3 + pub_r001846_17 * 2 + 74) & 127;
    if (stage_v_23 > 52) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_1 + pub_r001846_4 * 2 + 77) & 127;
    if (stage_v_24 > 31) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001846_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001846_4 + pub_r001846_8 * 2 + 83) & 127;
    if (stage_v_26 > 58) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001846_0 + pub_r001846_12 * 2 + 86) & 127;
    if (stage_v_27 > 42) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001846_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_10 + pub_r001846_6 * 2 + 92) & 127;
    if (stage_v_29 > 60) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001846_10 + pub_r001846_17 * 2 + 95) & 127;
    if (stage_v_30 > 21) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_15 + pub_r001846_17 * 2 + 98) & 127;
    if (stage_v_31 > 39) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001846_17 + pub_r001846_17 * 2 + 101) & 127;
    if (stage_v_32 > 21) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001846_10 + pub_r001846_12 * 2 + 104) & 127;
    if (stage_v_33 > 35) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_26 + pub_r001846_0 * 2 + 107) & 127;
    if (stage_v_34 > 19) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001846_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001846_4 + pub_r001846_0 * 2 + 113) & 127;
    if (stage_v_36 > 21) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001846_2 + pub_r001846_16 * 2 + 116) & 127;
    if (stage_v_37 > 47) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001846_11 + pub_r001846_4 * 2 + 119) & 127;
    if (stage_v_38 > 37) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001846_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001846_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001846_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001846_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001846_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_33 + pub_r001846_6 * 2 + 137) & 127;
    if (stage_v_44 > 16) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001846_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_9 + pub_r001846_1 * 2 + 143) & 127;
    if (stage_v_46 > 50) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001846_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001846_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001846_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001846_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_9 + pub_r001846_7 * 2 + 158) & 127;
    if (stage_v_51 > 20) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001846_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001846_11 + pub_r001846_3 * 2 + 164) & 127;
    if (stage_v_53 > 24) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_36 + pub_r001846_5 * 2 + 167) & 127;
    if (stage_v_54 > 52) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_2 + pub_r001846_7 * 2 + 170) & 127;
    if (stage_v_55 > 41) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001846_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_4 + pub_r001846_13 * 2 + 176) & 127;
    if (stage_v_57 > 45) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_51 + pub_r001846_10 * 2 + 179) & 127;
    if (stage_v_58 > 50) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_16 + pub_r001846_11 * 2 + 182) & 127;
    if (stage_v_59 > 54) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_27 + pub_r001846_7 * 2 + 185) & 127;
    if (stage_v_60 > 58) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001846_1 + pub_r001846_15 * 2 + 188) & 127;
    if (stage_v_61 > 18) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001846_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001846_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_3 + pub_r001846_6 * 2 + 197) & 127;
    if (stage_v_64 > 21) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_31 + pub_r001846_2 * 2 + 200) & 127;
    if (stage_v_65 > 46) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_10 + pub_r001846_1 * 2 + 203) & 127;
    if (stage_v_66 > 38) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_38 + pub_r001846_11 * 2 + 206) & 127;
    if (stage_v_67 > 60) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001846_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001846_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001846_16 + pub_r001846_10 * 2 + 215) & 127;
    if (stage_v_70 > 20) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001846_6 + pub_r001846_11 * 2 + 218) & 127;
    if (stage_v_71 > 18) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_65 + pub_r001846_1 * 2 + 221) & 127;
    if (stage_v_72 > 43) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_29 + pub_r001846_11 * 2 + 224) & 127;
    if (stage_v_73 > 23) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_19 + pub_r001846_3 * 2 + 227) & 127;
    if (stage_v_74 > 60) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_33 + pub_r001846_5 * 2 + 230) & 127;
    if (stage_v_75 > 27) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_20 + pub_r001846_3 * 2 + 233) & 127;
    if (stage_v_76 > 59) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001846_10 + pub_r001846_2 * 2 + 236) & 127;
    if (stage_v_77 > 47) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_24 + pub_r001846_16 * 2 + 239) & 127;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_72 + pub_r001846_10 * 2 + 242) & 127;
    if (stage_v_79 > 39) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001846_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001846_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001846_14 + pub_r001846_15 * 2 + 251) & 127;
    if (stage_v_82 > 53) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_30 + pub_r001846_13 * 2 + 254) & 127;
    if (stage_v_83 > 32) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001846_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_82 + pub_r001846_10 * 2 + 260) & 127;
    if (stage_v_85 > 44) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001846_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001846_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_3 + pub_r001846_15 * 2 + 269) & 127;
    if (stage_v_88 > 15) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001846_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_38 + pub_r001846_15 * 2 + 275) & 127;
    if (stage_v_90 > 59) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_2 + pub_r001846_4 * 2 + 278) & 127;
    if (stage_v_91 > 23) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001846_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_82 + pub_r001846_10 * 2 + 284) & 127;
    if (stage_v_93 > 41) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_90 + pub_r001846_3 * 2 + 287) & 127;
    if (stage_v_94 > 40) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_20 + pub_r001846_14 * 2 + 290) & 127;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_24 + pub_r001846_10 * 2 + 293) & 127;
    if (stage_v_96 > 47) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_90 + pub_r001846_15 * 2 + 296) & 127;
    if (stage_v_97 > 21) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001846_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_26 + pub_r001846_17 * 2 + 302) & 127;
    if (stage_v_99 > 27) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (helper_flow_0 + pub_r001846_9 * 2 + 305) & 127;
    if (stage_v_100 > 22) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_37 + pub_r001846_12 * 2 + 308) & 127;
    if (stage_v_101 > 35) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_33 + pub_r001846_2 * 2 + 311) & 127;
    if (stage_v_102 > 58) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001846_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_44 + pub_r001846_15 * 2 + 317) & 127;
    if (stage_v_104 > 23) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (helper_flow_8 + pub_r001846_6 * 2 + 320) & 127;
    if (stage_v_105 > 44) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_96 + pub_r001846_2 * 2 + 323) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_1 + pub_r001846_16 * 2 + 326) & 127;
    if (stage_v_107 > 44) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001846_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_27 + pub_r001846_1 * 2 + 332) & 127;
    if (stage_v_109 > 38) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001846_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001846_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_19 + pub_r001846_5 * 2 + 341) & 127;
    if (stage_v_112 > 31) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001846_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001846_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_82 + pub_r001846_5 * 2 + 350) & 127;
    if (stage_v_115 > 53) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_30 + pub_r001846_10 * 2 + 353) & 127;
    if (stage_v_116 > 25) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_1 + pub_r001846_11 * 2 + 356) & 127;
    if (stage_v_117 > 16) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_37 + pub_r001846_1 * 2 + 359) & 127;
    if (stage_v_118 > 36) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_99 + pub_r001846_11 * 2 + 362) & 127;
    if (stage_v_119 > 58) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001846_15 + pub_r001846_9 * 2 + 365) & 127;
    if (stage_v_120 > 54) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001846_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_119 + pub_r001846_5 * 2 + 371) & 127;
    if (stage_v_122 > 46) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001846_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001846_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_60 + pub_r001846_15 * 2 + 380) & 127;
    if (stage_v_125 > 39) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_36 + pub_r001846_3 * 2 + 383) & 127;
    if (stage_v_126 > 25) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001846_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_0 + pub_r001846_0 * 2 + 389) & 127;
    if (stage_v_128 > 28) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001846_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001846_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_96 + pub_r001846_16 * 2 + 398) & 127;
    if (stage_v_131 > 24) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001846_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001846_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_122 + pub_r001846_7 * 2 + 407) & 127;
    if (stage_v_134 > 32) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_101 + pub_r001846_3 * 2 + 410) & 127;
    if (stage_v_135 > 28) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001846_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001846_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_27 + pub_r001846_2 * 2 + 419) & 127;
    if (stage_v_138 > 36) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001846_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_21 + pub_r001846_17 * 2 + 425) & 127;
    if (stage_v_140 > 34) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001846_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001846_17 + pub_r001846_2 * 2 + 431) & 127;
    if (stage_v_142 > 24) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_138 + pub_r001846_10 * 2 + 434) & 127;
    if (stage_v_143 > 49) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001846_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001846_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001846_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001846_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_70 + pub_r001846_2 * 2 + 449) & 127;
    if (stage_v_148 > 57) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001846_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_0 + pub_r001846_17 * 2 + 455) & 127;
    if (stage_v_150 > 38) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001846_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001846_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_24 + pub_r001846_4 * 2 + 464) & 127;
    if (stage_v_153 > 29) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001846_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001846_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_34 + pub_r001846_9 * 2 + 473) & 127;
    if (stage_v_156 > 47) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_83 + pub_r001846_0 * 2 + 476) & 127;
    if (stage_v_157 > 40) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_61 + pub_r001846_5 * 2 + 479) & 127;
    if (stage_v_158 > 25) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_107 + pub_r001846_10 * 2 + 482) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_21 + pub_r001846_7 * 2 + 485) & 127;
    if (stage_v_160 > 41) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_29 + pub_r001846_2 * 2 + 488) & 127;
    if (stage_v_161 > 58) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_77 + pub_r001846_13 * 2 + 491) & 127;
    if (stage_v_162 > 58) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_150 + pub_r001846_7 * 2 + 494) & 127;
    if (stage_v_163 > 59) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001846_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_16 + pub_r001846_7 * 2 + 500) & 127;
    if (stage_v_165 > 35) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_73 + pub_r001846_10 * 2 + 503) & 127;
    if (stage_v_166 > 18) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001846_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_118 + pub_r001846_8 * 2 + 509) & 127;
    if (stage_v_168 > 40) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r001846_14 + pub_r001846_17 * 2 + 512) & 127;
    if (stage_v_169 > 31) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001846_6 + pub_r001846_11 * 2 + 515) & 127;
    if (stage_v_170 > 56) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_101 + pub_r001846_5 * 2 + 518) & 127;
    if (stage_v_171 > 38) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001846_11 + pub_r001846_12 * 2 + 521) & 127;
    if (stage_v_172 > 47) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001846_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001846_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_29 + pub_r001846_6 * 2 + 530) & 127;
    if (stage_v_175 > 58) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_85 + pub_r001846_2 * 2 + 533) & 127;
    if (stage_v_176 > 47) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_88 + pub_r001846_17 * 2 + 536) & 127;
    if (stage_v_177 > 20) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001846_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001846_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001846_10 + pub_r001846_2 * 2 + 545) & 127;
    if (stage_v_180 > 44) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_126 + pub_r001846_17 * 2 + 548) & 127;
    if (stage_v_181 > 32) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001846_11 + pub_r001846_0 * 2 + 551) & 127;
    if (stage_v_182 > 16) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001846_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_76 + pub_r001846_15 * 2 + 557) & 127;
    if (stage_v_184 > 49) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_20 + pub_r001846_12 * 2 + 560) & 127;
    if (stage_v_185 > 47) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001846_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_118 + pub_r001846_17 * 2 + 566) & 127;
    if (stage_v_187 > 52) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_125 + pub_r001846_12 * 2 + 569) & 127;
    if (stage_v_188 > 27) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_97 + pub_r001846_11 * 2 + 572) & 127;
    if (stage_v_189 > 22) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001846_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_34 + pub_r001846_12 * 2 + 578) & 127;
    if (stage_v_191 > 39) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r001846_3 + pub_r001846_1 * 2 + 581) & 127;
    if (stage_v_192 > 51) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_143 + pub_r001846_3 * 2 + 584) & 127;
    if (stage_v_193 > 23) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_119 + pub_r001846_2 * 2 + 587) & 127;
    if (stage_v_194 > 27) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_126 + pub_r001846_9 * 2 + 590) & 127;
    if (stage_v_195 > 29) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_64 + pub_r001846_17 * 2 + 593) & 127;
    if (stage_v_196 > 33) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001846_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_117 + pub_r001846_13 * 2 + 599) & 127;
    if (stage_v_198 > 55) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_95 + pub_r001846_4 * 2 + 602) & 127;
    if (stage_v_199 > 44) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_112 + pub_r001846_1 * 2 + 605) & 127;
    if (stage_v_200 > 47) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001846_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_118 + pub_r001846_15 * 2 + 611) & 127;
    if (stage_v_202 > 28) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001846_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_157 + pub_r001846_13 * 2 + 617) & 127;
    if (stage_v_204 > 39) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_0 + pub_r001846_5 * 2 + 620) & 127;
    if (stage_v_205 > 24) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001846_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001846_15 + pub_r001846_8 * 2 + 626) & 127;
    if (stage_v_207 > 38) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001846_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_180 + pub_r001846_14 * 2 + 632) & 127;
    if (stage_v_209 > 55) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001846_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_9 + pub_r001846_9 * 2 + 638) & 127;
    if (stage_v_211 > 32) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_13 + pub_r001846_14 * 2 + 641) & 127;
    if (stage_v_212 > 56) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_31 + pub_r001846_15 * 2 + 644) & 127;
    if (stage_v_213 > 48) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_16 + pub_r001846_15 * 2 + 647) & 127;
    if (stage_v_214 > 49) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (helper_flow_4 + pub_r001846_5 * 2 + 650) & 127;
    if (stage_v_215 > 37) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_214 + pub_r001846_8 * 2 + 653) & 127;
    if (stage_v_216 > 41) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_143 + pub_r001846_5 * 2 + 656) & 127;
    if (stage_v_217 > 54) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
