/*
 * Benchmark Program: R000968
 * Security Family: secret_dependent_loops
 * Generator Seed: 596813
 * High Inputs: 19 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000968_6813_0 {
    unsigned char flags;
    int nonce;
    int round_key;
    int buffer[3];
};

struct AudioFrame_R000968_6813_1 {
    int envelope;
    int gain;
    int rms;
    unsigned char channels;
    int sample_rate;
    int peak;
    int buffer[3];
};

struct EventLog_R000968_6813_2 {
    short facility;
    int code;
    int severity;
    short seq;
    int buffer[3];
};

union PacketPayload_R000968_6813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000968_6813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000968_6813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000968_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_75 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_75 > 37) {
        acc = (acc + mask_75 * 2 + 5) & 127;
        aux ^= (mask_75 & 15);
    } else {
        acc = (acc - mask_75 + 11) & 127;
        aux += 3;
    }
    int pivot_20 = (aux + st.buffer[1]) & 3;
    switch (pivot_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000968_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int index_reg_84 = local_arr[aux % 3];
    acc = (acc + index_reg_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_36 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_36 > 35) {
        acc = (acc + pivot_36 * 2 + 5) & 127;
        aux ^= (pivot_36 & 15);
    } else {
        acc = (acc - pivot_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_2(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_50 = (aux + st.buffer[1]) & 3;
    switch (metric_50) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_18 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_18 > 25) {
        acc = (acc + parity_18 * 2 + 5) & 127;
        aux ^= (parity_18 & 15);
    } else {
        acc = (acc - parity_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000968_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000968_6813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000968_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int anchor_45 = (aux + st.buffer[1]) & 3;
    switch (anchor_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_64 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_64 > 39) {
        acc = (acc + bound_64 * 2 + 5) & 127;
        aux ^= (bound_64 & 15);
    } else {
        acc = (acc - bound_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_5(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int parity_17 = local_arr[aux % 3];
    acc = (acc + parity_17 * 2) & 127;
    int accumulator_82 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_82 > 44) {
        acc = (acc + accumulator_82 * 2 + 5) & 127;
        aux ^= (accumulator_82 & 15);
    } else {
        acc = (acc - accumulator_82 + 11) & 127;
        aux += 3;
    }
    int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_31) & 63;
    acc ^= aux;
    int tracker_22 = (aux + st.buffer[1]) & 3;
    switch (tracker_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_36 = local_arr[aux % 3];
    acc = (acc + quantum_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000968_6813_7(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000968_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_41 = local_arr[aux % 3];
    acc = (acc + cursor_41 * 2) & 127;
    int parity_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_50) & 63;
    acc ^= aux;
    int segment_63 = (aux + st.buffer[1]) & 3;
    switch (segment_63) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_8(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quotient_53 = (aux + st.buffer[1]) & 3;
    switch (quotient_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_94 = local_arr[aux % 3];
    acc = (acc + cursor_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000968_6813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_68 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_68 > 44) {
        acc = (acc + vector_68 * 2 + 5) & 127;
        aux ^= (vector_68 & 15);
    } else {
        acc = (acc - vector_68 + 11) & 127;
        aux += 3;
    }
    int metric_55 = (aux + st.buffer[1]) & 3;
    switch (metric_55) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_41 = local_arr[aux % 3];
    acc = (acc + segment_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000968_6813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_34 = local_arr[aux % 3];
    acc = (acc + margin_34 * 2) & 127;
    int quantum_27 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_27 > 47) {
        acc = (acc + quantum_27 * 2 + 5) & 127;
        aux ^= (quantum_27 & 15);
    } else {
        acc = (acc - quantum_27 + 11) & 127;
        aux += 3;
    }
    int stride_76 = (aux + st.buffer[1]) & 3;
    switch (stride_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_11(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int checksum_54 = (aux + st.buffer[1]) & 3;
    switch (checksum_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_95 = local_arr[aux % 3];
    acc = (acc + vector_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_36 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_36 > 32) {
        acc = (acc + threshold_36 * 2 + 5) & 127;
        aux ^= (threshold_36 & 15);
    } else {
        acc = (acc - threshold_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000968_6813_12(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000968_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_64 = (aux + st.buffer[1]) & 3;
    switch (sample_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_39 = local_arr[aux % 3];
    acc = (acc + tracker_39 * 2) & 127;
    int parity_43 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_43 > 17) {
        acc = (acc + parity_43 * 2 + 5) & 127;
        aux ^= (parity_43 & 15);
    } else {
        acc = (acc - parity_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000968_6813_13(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000968_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_79 = (aux + st.buffer[1]) & 3;
    switch (tally_79) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000968_0;
    int sec_r000968_1;
    int sec_r000968_2;
    int sec_r000968_3;
    int sec_r000968_4;
    int sec_r000968_5;
    int sec_r000968_6;
    int sec_r000968_7;
    int sec_r000968_8;
    int sec_r000968_9;
    int sec_r000968_10;
    int sec_r000968_11;
    int sec_r000968_12;
    int sec_r000968_13;
    int sec_r000968_14;
    int sec_r000968_15;
    int sec_r000968_16;
    int sec_r000968_17;
    int sec_r000968_18;
    int pub_r000968_0;
    int pub_r000968_1;
    int pub_r000968_2;
    int pub_r000968_3;
    int pub_r000968_4;
    int pub_r000968_5;
    int pub_r000968_6;
    int pub_r000968_7;
    int pub_r000968_8;
    int pub_r000968_9;
    int pub_r000968_10;
    int pub_r000968_11;
    int pub_r000968_12;
    int pub_r000968_13;
    int pub_r000968_14;
    int pub_r000968_15;
    int pub_r000968_16;
    int pub_r000968_17;
    int pub_r000968_18;
    int pub_r000968_19;
    int pub_r000968_20;
    int pub_r000968_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000968_0 >= -100 && pub_r000968_0 <= 100);
    __CPROVER_assume(pub_r000968_1 >= -100 && pub_r000968_1 <= 100);
    __CPROVER_assume(pub_r000968_2 >= -100 && pub_r000968_2 <= 100);
    __CPROVER_assume(pub_r000968_3 >= -100 && pub_r000968_3 <= 100);
    __CPROVER_assume(pub_r000968_4 >= -100 && pub_r000968_4 <= 100);
    __CPROVER_assume(pub_r000968_5 >= -100 && pub_r000968_5 <= 100);
    __CPROVER_assume(pub_r000968_6 >= -100 && pub_r000968_6 <= 100);
    __CPROVER_assume(pub_r000968_7 >= -100 && pub_r000968_7 <= 100);
    __CPROVER_assume(pub_r000968_8 >= -100 && pub_r000968_8 <= 100);
    __CPROVER_assume(pub_r000968_9 >= -100 && pub_r000968_9 <= 100);
    __CPROVER_assume(pub_r000968_10 >= -100 && pub_r000968_10 <= 100);
    __CPROVER_assume(pub_r000968_11 >= -100 && pub_r000968_11 <= 100);
    __CPROVER_assume(pub_r000968_12 >= -100 && pub_r000968_12 <= 100);
    __CPROVER_assume(pub_r000968_13 >= -100 && pub_r000968_13 <= 100);
    __CPROVER_assume(pub_r000968_14 >= -100 && pub_r000968_14 <= 100);
    __CPROVER_assume(pub_r000968_15 >= -100 && pub_r000968_15 <= 100);
    __CPROVER_assume(pub_r000968_16 >= -100 && pub_r000968_16 <= 100);
    __CPROVER_assume(pub_r000968_17 >= -100 && pub_r000968_17 <= 100);
    __CPROVER_assume(pub_r000968_18 >= -100 && pub_r000968_18 <= 100);
    __CPROVER_assume(pub_r000968_19 >= -100 && pub_r000968_19 <= 100);
    __CPROVER_assume(pub_r000968_20 >= -100 && pub_r000968_20 <= 100);
    __CPROVER_assume(pub_r000968_21 >= -100 && pub_r000968_21 <= 100);
    __CPROVER_assume(sec_r000968_0 >= 0 && sec_r000968_0 <= 255);
    __CPROVER_assume(sec_r000968_1 >= 0 && sec_r000968_1 <= 255);
    __CPROVER_assume(sec_r000968_2 >= 0 && sec_r000968_2 <= 255);
    __CPROVER_assume(sec_r000968_3 >= 0 && sec_r000968_3 <= 255);
    __CPROVER_assume(sec_r000968_4 >= 0 && sec_r000968_4 <= 255);
    __CPROVER_assume(sec_r000968_5 >= 0 && sec_r000968_5 <= 255);
    __CPROVER_assume(sec_r000968_6 >= 0 && sec_r000968_6 <= 255);
    __CPROVER_assume(sec_r000968_7 >= 0 && sec_r000968_7 <= 255);
    __CPROVER_assume(sec_r000968_8 >= 0 && sec_r000968_8 <= 255);
    __CPROVER_assume(sec_r000968_9 >= 0 && sec_r000968_9 <= 255);
    __CPROVER_assume(sec_r000968_10 >= 0 && sec_r000968_10 <= 255);
    __CPROVER_assume(sec_r000968_11 >= 0 && sec_r000968_11 <= 255);
    __CPROVER_assume(sec_r000968_12 >= 0 && sec_r000968_12 <= 255);
    __CPROVER_assume(sec_r000968_13 >= 0 && sec_r000968_13 <= 255);
    __CPROVER_assume(sec_r000968_14 >= 0 && sec_r000968_14 <= 255);
    __CPROVER_assume(sec_r000968_15 >= 0 && sec_r000968_15 <= 255);
    __CPROVER_assume(sec_r000968_16 >= 0 && sec_r000968_16 <= 255);
    __CPROVER_assume(sec_r000968_17 >= 0 && sec_r000968_17 <= 255);
    __CPROVER_assume(sec_r000968_18 >= 0 && sec_r000968_18 <= 255);

    struct CipherContext_R000968_6813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000968_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000968_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000968_0 + 7) & 15;
    struct AudioFrame_R000968_6813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000968_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000968_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000968_0 + 9) & 15;
    struct EventLog_R000968_6813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000968_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000968_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000968_0 + 11) & 15;

    union PacketPayload_R000968_6813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 19) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 34) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 16) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 31) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 26) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 41) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 20) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 35) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 17) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 32) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 19) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 34) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 33) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 48) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 19) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 34) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_12 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000968_5) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000968_21) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_0 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000968_19) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_7 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000968_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000968_5) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_6 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000968_8) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_2 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000968_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000968_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_15 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000968_20) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000968_15) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000968_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000968_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_0 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000968_11) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000968_20) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000968_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000968_20) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_14 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000968_7) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000968_15) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000968_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000968_7) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000968_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000968_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000968_0) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000968_1) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000968_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_2 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000968_15) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000968_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000968_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000968_1) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000968_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_15 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000968_21) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_2 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000968_19) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000968_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000968_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000968_0) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000968_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_16 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000968_7) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000968_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_7 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000968_11) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000968_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000968_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_16 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000968_3) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000968_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_13 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000968_14) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000968_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_12 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000968_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000968_8) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000968_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_6 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000968_2) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_16 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000968_21) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000968_21) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000968_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_6 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000968_3) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000968_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_16 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000968_7) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000968_8) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000968_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000968_15) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000968_13) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000968_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_13 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000968_20) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000968_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000968_7) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000968_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000968_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_3 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000968_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000968_6) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000968_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_0 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000968_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_1 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000968_9) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000968_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000968_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000968_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_13 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000968_11) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000968_5) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000968_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000968_8) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000968_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000968_4) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000968_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_5 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000968_5) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000968_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000968_15) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000968_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000968_1) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000968_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_142 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000968_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000968_16) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000968_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_139 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000968_18) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000968_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000968_5) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000968_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000968_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_0 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000968_6) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000968_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000968_10) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000968_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000968_6) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000968_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_10 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000968_12) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000968_19) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000968_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000968_3) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000968_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_136 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000968_13) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000968_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000968_17) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000968_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000968_14 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000968_1) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000968_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000968_20) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000968_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
