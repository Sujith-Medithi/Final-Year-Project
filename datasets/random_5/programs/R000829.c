/*
 * Benchmark Program: R000829
 * Security Family: secret_dependent_array
 * Generator Seed: 582913
 * High Inputs: 24 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000829_2913_0 {
    int envelope;
    int gain;
    unsigned char peak;
    int rms;
    int channels;
    int buffer[3];
};

struct CipherContext_R000829_2913_1 {
    int counter;
    short tag;
    unsigned char round_key;
    int iv;
    int flags;
    int buffer[3];
};

struct DeviceConfig_R000829_2913_2 {
    short stop_bits;
    int id;
    short parity;
    int timeout;
    unsigned char port;
    int baud_rate;
    int buffer[3];
};

struct EventLog_R000829_2913_3 {
    int code;
    int timestamp;
    int facility;
    unsigned char signature;
    int severity;
    unsigned char seq;
    int buffer[3];
};

union RegisterBank_R000829_2913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000829_2913_0(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000829_2913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int vector_74 = local_arr[aux % 3];
    acc = (acc + vector_74 * 2) & 127;
    int stride_62 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_62 > 25) {
        acc = (acc + stride_62 * 2 + 5) & 127;
        aux ^= (stride_62 & 15);
    } else {
        acc = (acc - stride_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000829_2913_1(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000829_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int segment_43 = local_arr[aux % 3];
    acc = (acc + segment_43 * 2) & 127;
    int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000829_2913_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000829_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_18 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_18 > 46) {
        acc = (acc + stride_18 * 2 + 5) & 127;
        aux ^= (stride_18 & 15);
    } else {
        acc = (acc - stride_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_84 = local_arr[aux % 3];
    acc = (acc + stride_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_3(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000829_2913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int tally_27 = local_arr[aux % 3];
    acc = (acc + tally_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_25 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_25 > 32) {
        acc = (acc + mask_25 * 2 + 5) & 127;
        aux ^= (mask_25 & 15);
    } else {
        acc = (acc - mask_25 + 11) & 127;
        aux += 3;
    }
    int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000829_2913_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000829_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_18) & 63;
    acc ^= aux;
    int segment_41 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_41 > 38) {
        acc = (acc + segment_41 * 2 + 5) & 127;
        aux ^= (segment_41 & 15);
    } else {
        acc = (acc - segment_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_38 = local_arr[aux % 3];
    acc = (acc + bound_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_5(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000829_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int metric_10 = local_arr[aux % 3];
    acc = (acc + metric_10 * 2) & 127;
    int threshold_67 = (aux + st.buffer[1]) & 3;
    switch (threshold_67) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000829_2913_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000829_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int window_81 = local_arr[aux % 3];
    acc = (acc + window_81 * 2) & 127;
    int quotient_69 = (aux + st.buffer[1]) & 3;
    switch (quotient_69) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_7(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000829_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_55 = (aux + st.buffer[1]) & 3;
    switch (delta_55) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_74 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_74 > 50) {
        acc = (acc + scale_74 * 2 + 5) & 127;
        aux ^= (scale_74 & 15);
    } else {
        acc = (acc - scale_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000829_2913_8(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000829_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_28 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_28 > 45) {
        acc = (acc + cursor_28 * 2 + 5) & 127;
        aux ^= (cursor_28 & 15);
    } else {
        acc = (acc - cursor_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_75) & 63;
    acc ^= aux;
    int segment_46 = (aux + st.buffer[1]) & 3;
    switch (segment_46) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000829_2913_9(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000829_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_44 = (aux + st.buffer[1]) & 3;
    switch (tracker_44) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_10(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000829_2913_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_76 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_76 > 15) {
        acc = (acc + residue_76 * 2 + 5) & 127;
        aux ^= (residue_76 & 15);
    } else {
        acc = (acc - residue_76 + 11) & 127;
        aux += 3;
    }
    int index_reg_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000829_2913_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000829_2913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int weight_46 = local_arr[aux % 3];
    acc = (acc + weight_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_12(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000829_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int parity_56 = local_arr[aux % 3];
    acc = (acc + parity_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000829_2913_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000829_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int cursor_43 = local_arr[aux % 3];
    acc = (acc + cursor_43 * 2) & 127;
    int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000829_2913_14(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000829_2913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_58) & 63;
    acc ^= aux;
    int tally_97 = (aux + st.buffer[1]) & 3;
    switch (tally_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000829_2913_15(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000829_2913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int accumulator_56 = local_arr[aux % 3];
    acc = (acc + accumulator_56 * 2) & 127;
    int cursor_79 = (aux + st.buffer[1]) & 3;
    switch (cursor_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000829_0;
    int sec_r000829_1;
    int sec_r000829_2;
    int sec_r000829_3;
    int sec_r000829_4;
    int sec_r000829_5;
    int sec_r000829_6;
    int sec_r000829_7;
    int sec_r000829_8;
    int sec_r000829_9;
    int sec_r000829_10;
    int sec_r000829_11;
    int sec_r000829_12;
    int sec_r000829_13;
    int sec_r000829_14;
    int sec_r000829_15;
    int sec_r000829_16;
    int sec_r000829_17;
    int sec_r000829_18;
    int sec_r000829_19;
    int sec_r000829_20;
    int sec_r000829_21;
    int sec_r000829_22;
    int sec_r000829_23;
    int pub_r000829_0;
    int pub_r000829_1;
    int pub_r000829_2;
    int pub_r000829_3;
    int pub_r000829_4;
    int pub_r000829_5;
    int pub_r000829_6;
    int pub_r000829_7;
    int pub_r000829_8;
    int pub_r000829_9;
    int pub_r000829_10;
    int pub_r000829_11;
    int pub_r000829_12;
    int pub_r000829_13;
    int pub_r000829_14;
    int pub_r000829_15;
    int pub_r000829_16;
    int pub_r000829_17;
    int pub_r000829_18;
    int pub_r000829_19;
    int pub_r000829_20;
    int pub_r000829_21;
    int pub_r000829_22;
    int pub_r000829_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000829_0 >= -100 && pub_r000829_0 <= 100);
    __CPROVER_assume(pub_r000829_1 >= -100 && pub_r000829_1 <= 100);
    __CPROVER_assume(pub_r000829_2 >= -100 && pub_r000829_2 <= 100);
    __CPROVER_assume(pub_r000829_3 >= -100 && pub_r000829_3 <= 100);
    __CPROVER_assume(pub_r000829_4 >= -100 && pub_r000829_4 <= 100);
    __CPROVER_assume(pub_r000829_5 >= -100 && pub_r000829_5 <= 100);
    __CPROVER_assume(pub_r000829_6 >= -100 && pub_r000829_6 <= 100);
    __CPROVER_assume(pub_r000829_7 >= -100 && pub_r000829_7 <= 100);
    __CPROVER_assume(pub_r000829_8 >= -100 && pub_r000829_8 <= 100);
    __CPROVER_assume(pub_r000829_9 >= -100 && pub_r000829_9 <= 100);
    __CPROVER_assume(pub_r000829_10 >= -100 && pub_r000829_10 <= 100);
    __CPROVER_assume(pub_r000829_11 >= -100 && pub_r000829_11 <= 100);
    __CPROVER_assume(pub_r000829_12 >= -100 && pub_r000829_12 <= 100);
    __CPROVER_assume(pub_r000829_13 >= -100 && pub_r000829_13 <= 100);
    __CPROVER_assume(pub_r000829_14 >= -100 && pub_r000829_14 <= 100);
    __CPROVER_assume(pub_r000829_15 >= -100 && pub_r000829_15 <= 100);
    __CPROVER_assume(pub_r000829_16 >= -100 && pub_r000829_16 <= 100);
    __CPROVER_assume(pub_r000829_17 >= -100 && pub_r000829_17 <= 100);
    __CPROVER_assume(pub_r000829_18 >= -100 && pub_r000829_18 <= 100);
    __CPROVER_assume(pub_r000829_19 >= -100 && pub_r000829_19 <= 100);
    __CPROVER_assume(pub_r000829_20 >= -100 && pub_r000829_20 <= 100);
    __CPROVER_assume(pub_r000829_21 >= -100 && pub_r000829_21 <= 100);
    __CPROVER_assume(pub_r000829_22 >= -100 && pub_r000829_22 <= 100);
    __CPROVER_assume(pub_r000829_23 >= -100 && pub_r000829_23 <= 100);
    __CPROVER_assume(sec_r000829_0 >= 0 && sec_r000829_0 <= 255);
    __CPROVER_assume(sec_r000829_1 >= 0 && sec_r000829_1 <= 255);
    __CPROVER_assume(sec_r000829_2 >= 0 && sec_r000829_2 <= 255);
    __CPROVER_assume(sec_r000829_3 >= 0 && sec_r000829_3 <= 255);
    __CPROVER_assume(sec_r000829_4 >= 0 && sec_r000829_4 <= 255);
    __CPROVER_assume(sec_r000829_5 >= 0 && sec_r000829_5 <= 255);
    __CPROVER_assume(sec_r000829_6 >= 0 && sec_r000829_6 <= 255);
    __CPROVER_assume(sec_r000829_7 >= 0 && sec_r000829_7 <= 255);
    __CPROVER_assume(sec_r000829_8 >= 0 && sec_r000829_8 <= 255);
    __CPROVER_assume(sec_r000829_9 >= 0 && sec_r000829_9 <= 255);
    __CPROVER_assume(sec_r000829_10 >= 0 && sec_r000829_10 <= 255);
    __CPROVER_assume(sec_r000829_11 >= 0 && sec_r000829_11 <= 255);
    __CPROVER_assume(sec_r000829_12 >= 0 && sec_r000829_12 <= 255);
    __CPROVER_assume(sec_r000829_13 >= 0 && sec_r000829_13 <= 255);
    __CPROVER_assume(sec_r000829_14 >= 0 && sec_r000829_14 <= 255);
    __CPROVER_assume(sec_r000829_15 >= 0 && sec_r000829_15 <= 255);
    __CPROVER_assume(sec_r000829_16 >= 0 && sec_r000829_16 <= 255);
    __CPROVER_assume(sec_r000829_17 >= 0 && sec_r000829_17 <= 255);
    __CPROVER_assume(sec_r000829_18 >= 0 && sec_r000829_18 <= 255);
    __CPROVER_assume(sec_r000829_19 >= 0 && sec_r000829_19 <= 255);
    __CPROVER_assume(sec_r000829_20 >= 0 && sec_r000829_20 <= 255);
    __CPROVER_assume(sec_r000829_21 >= 0 && sec_r000829_21 <= 255);
    __CPROVER_assume(sec_r000829_22 >= 0 && sec_r000829_22 <= 255);
    __CPROVER_assume(sec_r000829_23 >= 0 && sec_r000829_23 <= 255);

    struct AudioFrame_R000829_2913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000829_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000829_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000829_0 + 7) & 15;
    struct CipherContext_R000829_2913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000829_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000829_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000829_0 + 9) & 15;
    struct DeviceConfig_R000829_2913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000829_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000829_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000829_0 + 11) & 15;
    struct EventLog_R000829_2913_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000829_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000829_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000829_0 + 13) & 15;

    union RegisterBank_R000829_2913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 36) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 14) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 29) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 32) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 47) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 24) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 39) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 30) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 45) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 14) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 29) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 20) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 35) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 22) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 37) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 36) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 51) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 10) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 25) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 25) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 40) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 35) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 50) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 30) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 45) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int s_idx_84 = (sec_r000829_7 & 3);
    int stage_v_84 = (table[s_idx_84] + pub_r000829_14) & 127;
    table[s_idx_84] = (stage_v_84 + 7) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int s_idx_85 = (sec_r000829_22 & 3);
    int stage_v_85 = (table[s_idx_85] + pub_r000829_4) & 127;
    table[s_idx_85] = (stage_v_85 + 7) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int s_idx_86 = (stage_v_84 & 3);
    int stage_v_86 = (table[s_idx_86] + pub_r000829_12) & 127;
    table[s_idx_86] = (stage_v_86 + 7) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int s_idx_87 = (sec_r000829_10 & 3);
    int stage_v_87 = (table[s_idx_87] + pub_r000829_17) & 127;
    table[s_idx_87] = (stage_v_87 + 7) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int s_idx_88 = (stage_v_86 & 3);
    int stage_v_88 = (table[s_idx_88] + pub_r000829_1) & 127;
    table[s_idx_88] = (stage_v_88 + 7) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int s_idx_89 = (stage_v_84 & 3);
    int stage_v_89 = (table[s_idx_89] + pub_r000829_8) & 127;
    table[s_idx_89] = (stage_v_89 + 7) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int s_idx_90 = (stage_v_86 & 3);
    int stage_v_90 = (table[s_idx_90] + pub_r000829_5) & 127;
    table[s_idx_90] = (stage_v_90 + 7) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int s_idx_91 = (sec_r000829_7 & 3);
    int stage_v_91 = (table[s_idx_91] + pub_r000829_14) & 127;
    table[s_idx_91] = (stage_v_91 + 7) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int s_idx_92 = (sec_r000829_11 & 3);
    int stage_v_92 = (table[s_idx_92] + pub_r000829_7) & 127;
    table[s_idx_92] = (stage_v_92 + 7) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int s_idx_93 = (sec_r000829_10 & 3);
    int stage_v_93 = (table[s_idx_93] + pub_r000829_9) & 127;
    table[s_idx_93] = (stage_v_93 + 7) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int s_idx_94 = (stage_v_88 & 3);
    int stage_v_94 = (table[s_idx_94] + pub_r000829_21) & 127;
    table[s_idx_94] = (stage_v_94 + 7) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int s_idx_95 = (sec_r000829_17 & 3);
    int stage_v_95 = (table[s_idx_95] + pub_r000829_4) & 127;
    table[s_idx_95] = (stage_v_95 + 7) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int s_idx_96 = (stage_v_88 & 3);
    int stage_v_96 = (table[s_idx_96] + pub_r000829_19) & 127;
    table[s_idx_96] = (stage_v_96 + 7) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int s_idx_97 = (sec_r000829_3 & 3);
    int stage_v_97 = (table[s_idx_97] + pub_r000829_3) & 127;
    table[s_idx_97] = (stage_v_97 + 7) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int s_idx_98 = (stage_v_93 & 3);
    int stage_v_98 = (table[s_idx_98] + pub_r000829_11) & 127;
    table[s_idx_98] = (stage_v_98 + 7) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int s_idx_99 = (stage_v_93 & 3);
    int stage_v_99 = (table[s_idx_99] + pub_r000829_10) & 127;
    table[s_idx_99] = (stage_v_99 + 7) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int s_idx_100 = (stage_v_86 & 3);
    int stage_v_100 = (table[s_idx_100] + pub_r000829_19) & 127;
    table[s_idx_100] = (stage_v_100 + 7) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int s_idx_101 = (sec_r000829_23 & 3);
    int stage_v_101 = (table[s_idx_101] + pub_r000829_11) & 127;
    table[s_idx_101] = (stage_v_101 + 7) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int s_idx_102 = (stage_v_86 & 3);
    int stage_v_102 = (table[s_idx_102] + pub_r000829_9) & 127;
    table[s_idx_102] = (stage_v_102 + 7) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int s_idx_103 = (stage_v_95 & 3);
    int stage_v_103 = (table[s_idx_103] + pub_r000829_22) & 127;
    table[s_idx_103] = (stage_v_103 + 7) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int s_idx_104 = (stage_v_96 & 3);
    int stage_v_104 = (table[s_idx_104] + pub_r000829_12) & 127;
    table[s_idx_104] = (stage_v_104 + 7) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int s_idx_105 = (sec_r000829_10 & 3);
    int stage_v_105 = (table[s_idx_105] + pub_r000829_2) & 127;
    table[s_idx_105] = (stage_v_105 + 7) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int s_idx_106 = (stage_v_84 & 3);
    int stage_v_106 = (table[s_idx_106] + pub_r000829_6) & 127;
    table[s_idx_106] = (stage_v_106 + 7) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int s_idx_107 = (stage_v_101 & 3);
    int stage_v_107 = (table[s_idx_107] + pub_r000829_20) & 127;
    table[s_idx_107] = (stage_v_107 + 7) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int s_idx_108 = (stage_v_92 & 3);
    int stage_v_108 = (table[s_idx_108] + pub_r000829_3) & 127;
    table[s_idx_108] = (stage_v_108 + 7) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int s_idx_109 = (stage_v_87 & 3);
    int stage_v_109 = (table[s_idx_109] + pub_r000829_14) & 127;
    table[s_idx_109] = (stage_v_109 + 7) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int s_idx_110 = (stage_v_103 & 3);
    int stage_v_110 = (table[s_idx_110] + pub_r000829_3) & 127;
    table[s_idx_110] = (stage_v_110 + 7) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int s_idx_111 = (stage_v_84 & 3);
    int stage_v_111 = (table[s_idx_111] + pub_r000829_22) & 127;
    table[s_idx_111] = (stage_v_111 + 7) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int s_idx_112 = (stage_v_87 & 3);
    int stage_v_112 = (table[s_idx_112] + pub_r000829_0) & 127;
    table[s_idx_112] = (stage_v_112 + 7) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int s_idx_113 = (sec_r000829_14 & 3);
    int stage_v_113 = (table[s_idx_113] + pub_r000829_13) & 127;
    table[s_idx_113] = (stage_v_113 + 7) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int s_idx_114 = (stage_v_107 & 3);
    int stage_v_114 = (table[s_idx_114] + pub_r000829_1) & 127;
    table[s_idx_114] = (stage_v_114 + 7) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int s_idx_115 = (stage_v_93 & 3);
    int stage_v_115 = (table[s_idx_115] + pub_r000829_18) & 127;
    table[s_idx_115] = (stage_v_115 + 7) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int s_idx_116 = (stage_v_92 & 3);
    int stage_v_116 = (table[s_idx_116] + pub_r000829_6) & 127;
    table[s_idx_116] = (stage_v_116 + 7) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int s_idx_117 = (stage_v_99 & 3);
    int stage_v_117 = (table[s_idx_117] + pub_r000829_3) & 127;
    table[s_idx_117] = (stage_v_117 + 7) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int s_idx_118 = (sec_r000829_7 & 3);
    int stage_v_118 = (table[s_idx_118] + pub_r000829_7) & 127;
    table[s_idx_118] = (stage_v_118 + 7) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int s_idx_119 = (stage_v_110 & 3);
    int stage_v_119 = (table[s_idx_119] + pub_r000829_5) & 127;
    table[s_idx_119] = (stage_v_119 + 7) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int s_idx_120 = (stage_v_98 & 3);
    int stage_v_120 = (table[s_idx_120] + pub_r000829_12) & 127;
    table[s_idx_120] = (stage_v_120 + 7) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int s_idx_121 = (stage_v_96 & 3);
    int stage_v_121 = (table[s_idx_121] + pub_r000829_19) & 127;
    table[s_idx_121] = (stage_v_121 + 7) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int s_idx_122 = (stage_v_94 & 3);
    int stage_v_122 = (table[s_idx_122] + pub_r000829_21) & 127;
    table[s_idx_122] = (stage_v_122 + 7) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int s_idx_123 = (stage_v_91 & 3);
    int stage_v_123 = (table[s_idx_123] + pub_r000829_2) & 127;
    table[s_idx_123] = (stage_v_123 + 7) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int s_idx_124 = (sec_r000829_16 & 3);
    int stage_v_124 = (table[s_idx_124] + pub_r000829_9) & 127;
    table[s_idx_124] = (stage_v_124 + 7) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int s_idx_125 = (stage_v_105 & 3);
    int stage_v_125 = (table[s_idx_125] + pub_r000829_12) & 127;
    table[s_idx_125] = (stage_v_125 + 7) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int s_idx_126 = (sec_r000829_20 & 3);
    int stage_v_126 = (table[s_idx_126] + pub_r000829_16) & 127;
    table[s_idx_126] = (stage_v_126 + 7) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int s_idx_127 = (sec_r000829_1 & 3);
    int stage_v_127 = (table[s_idx_127] + pub_r000829_1) & 127;
    table[s_idx_127] = (stage_v_127 + 7) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int s_idx_128 = (stage_v_98 & 3);
    int stage_v_128 = (table[s_idx_128] + pub_r000829_22) & 127;
    table[s_idx_128] = (stage_v_128 + 7) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int s_idx_129 = (stage_v_113 & 3);
    int stage_v_129 = (table[s_idx_129] + pub_r000829_7) & 127;
    table[s_idx_129] = (stage_v_129 + 7) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int s_idx_130 = (stage_v_89 & 3);
    int stage_v_130 = (table[s_idx_130] + pub_r000829_23) & 127;
    table[s_idx_130] = (stage_v_130 + 7) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int s_idx_131 = (sec_r000829_2 & 3);
    int stage_v_131 = (table[s_idx_131] + pub_r000829_19) & 127;
    table[s_idx_131] = (stage_v_131 + 7) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int s_idx_132 = (sec_r000829_16 & 3);
    int stage_v_132 = (table[s_idx_132] + pub_r000829_9) & 127;
    table[s_idx_132] = (stage_v_132 + 7) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int s_idx_133 = (sec_r000829_17 & 3);
    int stage_v_133 = (table[s_idx_133] + pub_r000829_3) & 127;
    table[s_idx_133] = (stage_v_133 + 7) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int s_idx_134 = (sec_r000829_7 & 3);
    int stage_v_134 = (table[s_idx_134] + pub_r000829_20) & 127;
    table[s_idx_134] = (stage_v_134 + 7) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int s_idx_135 = (stage_v_100 & 3);
    int stage_v_135 = (table[s_idx_135] + pub_r000829_9) & 127;
    table[s_idx_135] = (stage_v_135 + 7) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int s_idx_136 = (sec_r000829_17 & 3);
    int stage_v_136 = (table[s_idx_136] + pub_r000829_0) & 127;
    table[s_idx_136] = (stage_v_136 + 7) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int s_idx_137 = (sec_r000829_1 & 3);
    int stage_v_137 = (table[s_idx_137] + pub_r000829_8) & 127;
    table[s_idx_137] = (stage_v_137 + 7) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int s_idx_138 = (sec_r000829_18 & 3);
    int stage_v_138 = (table[s_idx_138] + pub_r000829_12) & 127;
    table[s_idx_138] = (stage_v_138 + 7) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int s_idx_139 = (sec_r000829_22 & 3);
    int stage_v_139 = (table[s_idx_139] + pub_r000829_12) & 127;
    table[s_idx_139] = (stage_v_139 + 7) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int s_idx_140 = (stage_v_108 & 3);
    int stage_v_140 = (table[s_idx_140] + pub_r000829_2) & 127;
    table[s_idx_140] = (stage_v_140 + 7) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int s_idx_141 = (sec_r000829_14 & 3);
    int stage_v_141 = (table[s_idx_141] + pub_r000829_18) & 127;
    table[s_idx_141] = (stage_v_141 + 7) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int s_idx_142 = (stage_v_138 & 3);
    int stage_v_142 = (table[s_idx_142] + pub_r000829_0) & 127;
    table[s_idx_142] = (stage_v_142 + 7) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int s_idx_143 = (stage_v_123 & 3);
    int stage_v_143 = (table[s_idx_143] + pub_r000829_21) & 127;
    table[s_idx_143] = (stage_v_143 + 7) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int s_idx_144 = (stage_v_104 & 3);
    int stage_v_144 = (table[s_idx_144] + pub_r000829_16) & 127;
    table[s_idx_144] = (stage_v_144 + 7) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int s_idx_145 = (sec_r000829_1 & 3);
    int stage_v_145 = (table[s_idx_145] + pub_r000829_11) & 127;
    table[s_idx_145] = (stage_v_145 + 7) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int s_idx_146 = (stage_v_139 & 3);
    int stage_v_146 = (table[s_idx_146] + pub_r000829_0) & 127;
    table[s_idx_146] = (stage_v_146 + 7) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int s_idx_147 = (stage_v_84 & 3);
    int stage_v_147 = (table[s_idx_147] + pub_r000829_19) & 127;
    table[s_idx_147] = (stage_v_147 + 7) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int s_idx_148 = (stage_v_124 & 3);
    int stage_v_148 = (table[s_idx_148] + pub_r000829_22) & 127;
    table[s_idx_148] = (stage_v_148 + 7) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int s_idx_149 = (sec_r000829_22 & 3);
    int stage_v_149 = (table[s_idx_149] + pub_r000829_18) & 127;
    table[s_idx_149] = (stage_v_149 + 7) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int s_idx_150 = (sec_r000829_6 & 3);
    int stage_v_150 = (table[s_idx_150] + pub_r000829_10) & 127;
    table[s_idx_150] = (stage_v_150 + 7) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int s_idx_151 = (stage_v_104 & 3);
    int stage_v_151 = (table[s_idx_151] + pub_r000829_19) & 127;
    table[s_idx_151] = (stage_v_151 + 7) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int s_idx_152 = (stage_v_101 & 3);
    int stage_v_152 = (table[s_idx_152] + pub_r000829_0) & 127;
    table[s_idx_152] = (stage_v_152 + 7) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int s_idx_153 = (sec_r000829_5 & 3);
    int stage_v_153 = (table[s_idx_153] + pub_r000829_9) & 127;
    table[s_idx_153] = (stage_v_153 + 7) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int s_idx_154 = (stage_v_141 & 3);
    int stage_v_154 = (table[s_idx_154] + pub_r000829_3) & 127;
    table[s_idx_154] = (stage_v_154 + 7) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int s_idx_155 = (stage_v_105 & 3);
    int stage_v_155 = (table[s_idx_155] + pub_r000829_2) & 127;
    table[s_idx_155] = (stage_v_155 + 7) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int s_idx_156 = (stage_v_96 & 3);
    int stage_v_156 = (table[s_idx_156] + pub_r000829_6) & 127;
    table[s_idx_156] = (stage_v_156 + 7) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int s_idx_157 = (stage_v_121 & 3);
    int stage_v_157 = (table[s_idx_157] + pub_r000829_23) & 127;
    table[s_idx_157] = (stage_v_157 + 7) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int s_idx_158 = (stage_v_149 & 3);
    int stage_v_158 = (table[s_idx_158] + pub_r000829_9) & 127;
    table[s_idx_158] = (stage_v_158 + 7) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int s_idx_159 = (stage_v_92 & 3);
    int stage_v_159 = (table[s_idx_159] + pub_r000829_21) & 127;
    table[s_idx_159] = (stage_v_159 + 7) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int s_idx_160 = (stage_v_107 & 3);
    int stage_v_160 = (table[s_idx_160] + pub_r000829_22) & 127;
    table[s_idx_160] = (stage_v_160 + 7) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int s_idx_161 = (sec_r000829_7 & 3);
    int stage_v_161 = (table[s_idx_161] + pub_r000829_2) & 127;
    table[s_idx_161] = (stage_v_161 + 7) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int s_idx_162 = (sec_r000829_13 & 3);
    int stage_v_162 = (table[s_idx_162] + pub_r000829_13) & 127;
    table[s_idx_162] = (stage_v_162 + 7) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int s_idx_163 = (sec_r000829_12 & 3);
    int stage_v_163 = (table[s_idx_163] + pub_r000829_3) & 127;
    table[s_idx_163] = (stage_v_163 + 7) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int s_idx_164 = (stage_v_87 & 3);
    int stage_v_164 = (table[s_idx_164] + pub_r000829_15) & 127;
    table[s_idx_164] = (stage_v_164 + 7) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int s_idx_165 = (sec_r000829_12 & 3);
    int stage_v_165 = (table[s_idx_165] + pub_r000829_10) & 127;
    table[s_idx_165] = (stage_v_165 + 7) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int s_idx_166 = (stage_v_156 & 3);
    int stage_v_166 = (table[s_idx_166] + pub_r000829_6) & 127;
    table[s_idx_166] = (stage_v_166 + 7) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int s_idx_167 = (stage_v_117 & 3);
    int stage_v_167 = (table[s_idx_167] + pub_r000829_5) & 127;
    table[s_idx_167] = (stage_v_167 + 7) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int s_idx_168 = (stage_v_94 & 3);
    int stage_v_168 = (table[s_idx_168] + pub_r000829_12) & 127;
    table[s_idx_168] = (stage_v_168 + 7) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int s_idx_169 = (sec_r000829_20 & 3);
    int stage_v_169 = (table[s_idx_169] + pub_r000829_20) & 127;
    table[s_idx_169] = (stage_v_169 + 7) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int s_idx_170 = (stage_v_133 & 3);
    int stage_v_170 = (table[s_idx_170] + pub_r000829_11) & 127;
    table[s_idx_170] = (stage_v_170 + 7) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int s_idx_171 = (stage_v_87 & 3);
    int stage_v_171 = (table[s_idx_171] + pub_r000829_3) & 127;
    table[s_idx_171] = (stage_v_171 + 7) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int s_idx_172 = (stage_v_160 & 3);
    int stage_v_172 = (table[s_idx_172] + pub_r000829_2) & 127;
    table[s_idx_172] = (stage_v_172 + 7) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int s_idx_173 = (stage_v_128 & 3);
    int stage_v_173 = (table[s_idx_173] + pub_r000829_10) & 127;
    table[s_idx_173] = (stage_v_173 + 7) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int s_idx_174 = (sec_r000829_10 & 3);
    int stage_v_174 = (table[s_idx_174] + pub_r000829_5) & 127;
    table[s_idx_174] = (stage_v_174 + 7) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int s_idx_175 = (stage_v_130 & 3);
    int stage_v_175 = (table[s_idx_175] + pub_r000829_23) & 127;
    table[s_idx_175] = (stage_v_175 + 7) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int s_idx_176 = (sec_r000829_17 & 3);
    int stage_v_176 = (table[s_idx_176] + pub_r000829_2) & 127;
    table[s_idx_176] = (stage_v_176 + 7) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int s_idx_177 = (sec_r000829_4 & 3);
    int stage_v_177 = (table[s_idx_177] + pub_r000829_13) & 127;
    table[s_idx_177] = (stage_v_177 + 7) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int s_idx_178 = (sec_r000829_23 & 3);
    int stage_v_178 = (table[s_idx_178] + pub_r000829_7) & 127;
    table[s_idx_178] = (stage_v_178 + 7) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int s_idx_179 = (stage_v_101 & 3);
    int stage_v_179 = (table[s_idx_179] + pub_r000829_5) & 127;
    table[s_idx_179] = (stage_v_179 + 7) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int s_idx_180 = (stage_v_145 & 3);
    int stage_v_180 = (table[s_idx_180] + pub_r000829_15) & 127;
    table[s_idx_180] = (stage_v_180 + 7) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int s_idx_181 = (stage_v_95 & 3);
    int stage_v_181 = (table[s_idx_181] + pub_r000829_21) & 127;
    table[s_idx_181] = (stage_v_181 + 7) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int s_idx_182 = (stage_v_151 & 3);
    int stage_v_182 = (table[s_idx_182] + pub_r000829_21) & 127;
    table[s_idx_182] = (stage_v_182 + 7) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int s_idx_183 = (stage_v_140 & 3);
    int stage_v_183 = (table[s_idx_183] + pub_r000829_12) & 127;
    table[s_idx_183] = (stage_v_183 + 7) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int s_idx_184 = (sec_r000829_22 & 3);
    int stage_v_184 = (table[s_idx_184] + pub_r000829_23) & 127;
    table[s_idx_184] = (stage_v_184 + 7) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int s_idx_185 = (sec_r000829_2 & 3);
    int stage_v_185 = (table[s_idx_185] + pub_r000829_20) & 127;
    table[s_idx_185] = (stage_v_185 + 7) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int s_idx_186 = (stage_v_105 & 3);
    int stage_v_186 = (table[s_idx_186] + pub_r000829_5) & 127;
    table[s_idx_186] = (stage_v_186 + 7) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int s_idx_187 = (stage_v_136 & 3);
    int stage_v_187 = (table[s_idx_187] + pub_r000829_13) & 127;
    table[s_idx_187] = (stage_v_187 + 7) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int s_idx_188 = (sec_r000829_18 & 3);
    int stage_v_188 = (table[s_idx_188] + pub_r000829_0) & 127;
    table[s_idx_188] = (stage_v_188 + 7) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int s_idx_189 = (stage_v_140 & 3);
    int stage_v_189 = (table[s_idx_189] + pub_r000829_23) & 127;
    table[s_idx_189] = (stage_v_189 + 7) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int s_idx_190 = (stage_v_149 & 3);
    int stage_v_190 = (table[s_idx_190] + pub_r000829_11) & 127;
    table[s_idx_190] = (stage_v_190 + 7) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int s_idx_191 = (stage_v_150 & 3);
    int stage_v_191 = (table[s_idx_191] + pub_r000829_18) & 127;
    table[s_idx_191] = (stage_v_191 + 7) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int s_idx_192 = (stage_v_159 & 3);
    int stage_v_192 = (table[s_idx_192] + pub_r000829_15) & 127;
    table[s_idx_192] = (stage_v_192 + 7) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int s_idx_193 = (sec_r000829_3 & 3);
    int stage_v_193 = (table[s_idx_193] + pub_r000829_16) & 127;
    table[s_idx_193] = (stage_v_193 + 7) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int s_idx_194 = (stage_v_137 & 3);
    int stage_v_194 = (table[s_idx_194] + pub_r000829_22) & 127;
    table[s_idx_194] = (stage_v_194 + 7) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int s_idx_195 = (sec_r000829_8 & 3);
    int stage_v_195 = (table[s_idx_195] + pub_r000829_4) & 127;
    table[s_idx_195] = (stage_v_195 + 7) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int s_idx_196 = (stage_v_137 & 3);
    int stage_v_196 = (table[s_idx_196] + pub_r000829_18) & 127;
    table[s_idx_196] = (stage_v_196 + 7) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int s_idx_197 = (stage_v_120 & 3);
    int stage_v_197 = (table[s_idx_197] + pub_r000829_23) & 127;
    table[s_idx_197] = (stage_v_197 + 7) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int s_idx_198 = (sec_r000829_19 & 3);
    int stage_v_198 = (table[s_idx_198] + pub_r000829_11) & 127;
    table[s_idx_198] = (stage_v_198 + 7) & 63;
    out_sink = (out_sink + stage_v_198) & 255;
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int s_idx_199 = (stage_v_155 & 3);
    int stage_v_199 = (table[s_idx_199] + pub_r000829_11) & 127;
    table[s_idx_199] = (stage_v_199 + 7) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int s_idx_200 = (stage_v_127 & 3);
    int stage_v_200 = (table[s_idx_200] + pub_r000829_12) & 127;
    table[s_idx_200] = (stage_v_200 + 7) & 63;
    out_sink = (out_sink + stage_v_200) & 255;
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int s_idx_201 = (sec_r000829_7 & 3);
    int stage_v_201 = (table[s_idx_201] + pub_r000829_14) & 127;
    table[s_idx_201] = (stage_v_201 + 7) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int s_idx_202 = (sec_r000829_3 & 3);
    int stage_v_202 = (table[s_idx_202] + pub_r000829_7) & 127;
    table[s_idx_202] = (stage_v_202 + 7) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int s_idx_203 = (stage_v_106 & 3);
    int stage_v_203 = (table[s_idx_203] + pub_r000829_9) & 127;
    table[s_idx_203] = (stage_v_203 + 7) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int s_idx_204 = (stage_v_125 & 3);
    int stage_v_204 = (table[s_idx_204] + pub_r000829_9) & 127;
    table[s_idx_204] = (stage_v_204 + 7) & 63;
    out_sink = (out_sink + stage_v_204) & 255;
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int s_idx_205 = (stage_v_85 & 3);
    int stage_v_205 = (table[s_idx_205] + pub_r000829_21) & 127;
    table[s_idx_205] = (stage_v_205 + 7) & 63;
    out_sink = (out_sink + stage_v_205) & 255;
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int s_idx_206 = (sec_r000829_2 & 3);
    int stage_v_206 = (table[s_idx_206] + pub_r000829_23) & 127;
    table[s_idx_206] = (stage_v_206 + 7) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int s_idx_207 = (stage_v_137 & 3);
    int stage_v_207 = (table[s_idx_207] + pub_r000829_4) & 127;
    table[s_idx_207] = (stage_v_207 + 7) & 63;
    out_sink = (out_sink + stage_v_207) & 255;
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int s_idx_208 = (stage_v_168 & 3);
    int stage_v_208 = (table[s_idx_208] + pub_r000829_18) & 127;
    table[s_idx_208] = (stage_v_208 + 7) & 63;
    out_sink = (out_sink + stage_v_208) & 255;
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int s_idx_209 = (sec_r000829_7 & 3);
    int stage_v_209 = (table[s_idx_209] + pub_r000829_11) & 127;
    table[s_idx_209] = (stage_v_209 + 7) & 63;
    out_sink = (out_sink + stage_v_209) & 255;
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int s_idx_210 = (stage_v_86 & 3);
    int stage_v_210 = (table[s_idx_210] + pub_r000829_21) & 127;
    table[s_idx_210] = (stage_v_210 + 7) & 63;
    out_sink = (out_sink + stage_v_210) & 255;
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int s_idx_211 = (stage_v_201 & 3);
    int stage_v_211 = (table[s_idx_211] + pub_r000829_0) & 127;
    table[s_idx_211] = (stage_v_211 + 7) & 63;
    out_sink = (out_sink + stage_v_211) & 255;
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int s_idx_212 = (sec_r000829_21 & 3);
    int stage_v_212 = (table[s_idx_212] + pub_r000829_8) & 127;
    table[s_idx_212] = (stage_v_212 + 7) & 63;
    out_sink = (out_sink + stage_v_212) & 255;
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int s_idx_213 = (stage_v_130 & 3);
    int stage_v_213 = (table[s_idx_213] + pub_r000829_4) & 127;
    table[s_idx_213] = (stage_v_213 + 7) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int s_idx_214 = (stage_v_202 & 3);
    int stage_v_214 = (table[s_idx_214] + pub_r000829_5) & 127;
    table[s_idx_214] = (stage_v_214 + 7) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int s_idx_215 = (sec_r000829_21 & 3);
    int stage_v_215 = (table[s_idx_215] + pub_r000829_17) & 127;
    table[s_idx_215] = (stage_v_215 + 7) & 63;
    out_sink = (out_sink + stage_v_215) & 255;
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int s_idx_216 = (sec_r000829_15 & 3);
    int stage_v_216 = (table[s_idx_216] + pub_r000829_7) & 127;
    table[s_idx_216] = (stage_v_216 + 7) & 63;
    out_sink = (out_sink + stage_v_216) & 255;
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int s_idx_217 = (sec_r000829_11 & 3);
    int stage_v_217 = (table[s_idx_217] + pub_r000829_4) & 127;
    table[s_idx_217] = (stage_v_217 + 7) & 63;
    out_sink = (out_sink + stage_v_217) & 255;
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int s_idx_218 = (stage_v_90 & 3);
    int stage_v_218 = (table[s_idx_218] + pub_r000829_19) & 127;
    table[s_idx_218] = (stage_v_218 + 7) & 63;
    out_sink = (out_sink + stage_v_218) & 255;
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int s_idx_219 = (sec_r000829_12 & 3);
    int stage_v_219 = (table[s_idx_219] + pub_r000829_20) & 127;
    table[s_idx_219] = (stage_v_219 + 7) & 63;
    out_sink = (out_sink + stage_v_219) & 255;
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int s_idx_220 = (sec_r000829_6 & 3);
    int stage_v_220 = (table[s_idx_220] + pub_r000829_5) & 127;
    table[s_idx_220] = (stage_v_220 + 7) & 63;
    out_sink = (out_sink + stage_v_220) & 255;
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int s_idx_221 = (sec_r000829_2 & 3);
    int stage_v_221 = (table[s_idx_221] + pub_r000829_20) & 127;
    table[s_idx_221] = (stage_v_221 + 7) & 63;
    out_sink = (out_sink + stage_v_221) & 255;
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int s_idx_222 = (sec_r000829_13 & 3);
    int stage_v_222 = (table[s_idx_222] + pub_r000829_23) & 127;
    table[s_idx_222] = (stage_v_222 + 7) & 63;
    out_sink = (out_sink + stage_v_222) & 255;
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int s_idx_223 = (sec_r000829_1 & 3);
    int stage_v_223 = (table[s_idx_223] + pub_r000829_15) & 127;
    table[s_idx_223] = (stage_v_223 + 7) & 63;
    out_sink = (out_sink + stage_v_223) & 255;
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int s_idx_224 = (sec_r000829_14 & 3);
    int stage_v_224 = (table[s_idx_224] + pub_r000829_0) & 127;
    table[s_idx_224] = (stage_v_224 + 7) & 63;
    out_sink = (out_sink + stage_v_224) & 255;
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int s_idx_225 = (stage_v_221 & 3);
    int stage_v_225 = (table[s_idx_225] + pub_r000829_21) & 127;
    table[s_idx_225] = (stage_v_225 + 7) & 63;
    out_sink = (out_sink + stage_v_225) & 255;
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int s_idx_226 = (stage_v_152 & 3);
    int stage_v_226 = (table[s_idx_226] + pub_r000829_21) & 127;
    table[s_idx_226] = (stage_v_226 + 7) & 63;
    out_sink = (out_sink + stage_v_226) & 255;
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int s_idx_227 = (sec_r000829_6 & 3);
    int stage_v_227 = (table[s_idx_227] + pub_r000829_3) & 127;
    table[s_idx_227] = (stage_v_227 + 7) & 63;
    out_sink = (out_sink + stage_v_227) & 255;
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int s_idx_228 = (sec_r000829_1 & 3);
    int stage_v_228 = (table[s_idx_228] + pub_r000829_12) & 127;
    table[s_idx_228] = (stage_v_228 + 7) & 63;
    out_sink = (out_sink + stage_v_228) & 255;
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int s_idx_229 = (sec_r000829_6 & 3);
    int stage_v_229 = (table[s_idx_229] + pub_r000829_21) & 127;
    table[s_idx_229] = (stage_v_229 + 7) & 63;
    out_sink = (out_sink + stage_v_229) & 255;
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int s_idx_230 = (stage_v_186 & 3);
    int stage_v_230 = (table[s_idx_230] + pub_r000829_21) & 127;
    table[s_idx_230] = (stage_v_230 + 7) & 63;
    out_sink = (out_sink + stage_v_230) & 255;
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int s_idx_231 = (sec_r000829_17 & 3);
    int stage_v_231 = (table[s_idx_231] + pub_r000829_11) & 127;
    table[s_idx_231] = (stage_v_231 + 7) & 63;
    out_sink = (out_sink + stage_v_231) & 255;
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int s_idx_232 = (sec_r000829_7 & 3);
    int stage_v_232 = (table[s_idx_232] + pub_r000829_16) & 127;
    table[s_idx_232] = (stage_v_232 + 7) & 63;
    out_sink = (out_sink + stage_v_232) & 255;
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int s_idx_233 = (sec_r000829_2 & 3);
    int stage_v_233 = (table[s_idx_233] + pub_r000829_2) & 127;
    table[s_idx_233] = (stage_v_233 + 7) & 63;
    out_sink = (out_sink + stage_v_233) & 255;
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int s_idx_234 = (stage_v_111 & 3);
    int stage_v_234 = (table[s_idx_234] + pub_r000829_14) & 127;
    table[s_idx_234] = (stage_v_234 + 7) & 63;
    out_sink = (out_sink + stage_v_234) & 255;
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int s_idx_235 = (stage_v_217 & 3);
    int stage_v_235 = (table[s_idx_235] + pub_r000829_2) & 127;
    table[s_idx_235] = (stage_v_235 + 7) & 63;
    out_sink = (out_sink + stage_v_235) & 255;
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int s_idx_236 = (stage_v_119 & 3);
    int stage_v_236 = (table[s_idx_236] + pub_r000829_18) & 127;
    table[s_idx_236] = (stage_v_236 + 7) & 63;
    out_sink = (out_sink + stage_v_236) & 255;
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int s_idx_237 = (sec_r000829_1 & 3);
    int stage_v_237 = (table[s_idx_237] + pub_r000829_22) & 127;
    table[s_idx_237] = (stage_v_237 + 7) & 63;
    out_sink = (out_sink + stage_v_237) & 255;
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int s_idx_238 = (stage_v_172 & 3);
    int stage_v_238 = (table[s_idx_238] + pub_r000829_15) & 127;
    table[s_idx_238] = (stage_v_238 + 7) & 63;
    out_sink = (out_sink + stage_v_238) & 255;
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int s_idx_239 = (stage_v_119 & 3);
    int stage_v_239 = (table[s_idx_239] + pub_r000829_19) & 127;
    table[s_idx_239] = (stage_v_239 + 7) & 63;
    out_sink = (out_sink + stage_v_239) & 255;
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int s_idx_240 = (sec_r000829_19 & 3);
    int stage_v_240 = (table[s_idx_240] + pub_r000829_21) & 127;
    table[s_idx_240] = (stage_v_240 + 7) & 63;
    out_sink = (out_sink + stage_v_240) & 255;
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int s_idx_241 = (stage_v_173 & 3);
    int stage_v_241 = (table[s_idx_241] + pub_r000829_22) & 127;
    table[s_idx_241] = (stage_v_241 + 7) & 63;
    out_sink = (out_sink + stage_v_241) & 255;
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int s_idx_242 = (sec_r000829_9 & 3);
    int stage_v_242 = (table[s_idx_242] + pub_r000829_9) & 127;
    table[s_idx_242] = (stage_v_242 + 7) & 63;
    out_sink = (out_sink + stage_v_242) & 255;
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int s_idx_243 = (stage_v_130 & 3);
    int stage_v_243 = (table[s_idx_243] + pub_r000829_8) & 127;
    table[s_idx_243] = (stage_v_243 + 7) & 63;
    out_sink = (out_sink + stage_v_243) & 255;
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int s_idx_244 = (stage_v_209 & 3);
    int stage_v_244 = (table[s_idx_244] + pub_r000829_5) & 127;
    table[s_idx_244] = (stage_v_244 + 7) & 63;
    out_sink = (out_sink + stage_v_244) & 255;
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int s_idx_245 = (sec_r000829_3 & 3);
    int stage_v_245 = (table[s_idx_245] + pub_r000829_4) & 127;
    table[s_idx_245] = (stage_v_245 + 7) & 63;
    out_sink = (out_sink + stage_v_245) & 255;
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int s_idx_246 = (stage_v_96 & 3);
    int stage_v_246 = (table[s_idx_246] + pub_r000829_0) & 127;
    table[s_idx_246] = (stage_v_246 + 7) & 63;
    out_sink = (out_sink + stage_v_246) & 255;
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int s_idx_247 = (stage_v_215 & 3);
    int stage_v_247 = (table[s_idx_247] + pub_r000829_4) & 127;
    table[s_idx_247] = (stage_v_247 + 7) & 63;
    out_sink = (out_sink + stage_v_247) & 255;
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int s_idx_248 = (sec_r000829_0 & 3);
    int stage_v_248 = (table[s_idx_248] + pub_r000829_23) & 127;
    table[s_idx_248] = (stage_v_248 + 7) & 63;
    out_sink = (out_sink + stage_v_248) & 255;
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int s_idx_249 = (sec_r000829_0 & 3);
    int stage_v_249 = (table[s_idx_249] + pub_r000829_3) & 127;
    table[s_idx_249] = (stage_v_249 + 7) & 63;
    out_sink = (out_sink + stage_v_249) & 255;
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int s_idx_250 = (stage_v_147 & 3);
    int stage_v_250 = (table[s_idx_250] + pub_r000829_6) & 127;
    table[s_idx_250] = (stage_v_250 + 7) & 63;
    out_sink = (out_sink + stage_v_250) & 255;
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int s_idx_251 = (stage_v_212 & 3);
    int stage_v_251 = (table[s_idx_251] + pub_r000829_20) & 127;
    table[s_idx_251] = (stage_v_251 + 7) & 63;
    out_sink = (out_sink + stage_v_251) & 255;
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int s_idx_252 = (sec_r000829_17 & 3);
    int stage_v_252 = (table[s_idx_252] + pub_r000829_20) & 127;
    table[s_idx_252] = (stage_v_252 + 7) & 63;
    out_sink = (out_sink + stage_v_252) & 255;
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int s_idx_253 = (sec_r000829_12 & 3);
    int stage_v_253 = (table[s_idx_253] + pub_r000829_0) & 127;
    table[s_idx_253] = (stage_v_253 + 7) & 63;
    out_sink = (out_sink + stage_v_253) & 255;
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int s_idx_254 = (stage_v_243 & 3);
    int stage_v_254 = (table[s_idx_254] + pub_r000829_5) & 127;
    table[s_idx_254] = (stage_v_254 + 7) & 63;
    out_sink = (out_sink + stage_v_254) & 255;
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int s_idx_255 = (stage_v_161 & 3);
    int stage_v_255 = (table[s_idx_255] + pub_r000829_7) & 127;
    table[s_idx_255] = (stage_v_255 + 7) & 63;
    out_sink = (out_sink + stage_v_255) & 255;
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int s_idx_256 = (stage_v_219 & 3);
    int stage_v_256 = (table[s_idx_256] + pub_r000829_21) & 127;
    table[s_idx_256] = (stage_v_256 + 7) & 63;
    out_sink = (out_sink + stage_v_256) & 255;
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int s_idx_257 = (stage_v_91 & 3);
    int stage_v_257 = (table[s_idx_257] + pub_r000829_3) & 127;
    table[s_idx_257] = (stage_v_257 + 7) & 63;
    out_sink = (out_sink + stage_v_257) & 255;
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int s_idx_258 = (stage_v_254 & 3);
    int stage_v_258 = (table[s_idx_258] + pub_r000829_1) & 127;
    table[s_idx_258] = (stage_v_258 + 7) & 63;
    out_sink = (out_sink + stage_v_258) & 255;
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int s_idx_259 = (stage_v_219 & 3);
    int stage_v_259 = (table[s_idx_259] + pub_r000829_12) & 127;
    table[s_idx_259] = (stage_v_259 + 7) & 63;
    out_sink = (out_sink + stage_v_259) & 255;
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int s_idx_260 = (stage_v_110 & 3);
    int stage_v_260 = (table[s_idx_260] + pub_r000829_21) & 127;
    table[s_idx_260] = (stage_v_260 + 7) & 63;
    out_sink = (out_sink + stage_v_260) & 255;
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int s_idx_261 = (stage_v_182 & 3);
    int stage_v_261 = (table[s_idx_261] + pub_r000829_17) & 127;
    table[s_idx_261] = (stage_v_261 + 7) & 63;
    out_sink = (out_sink + stage_v_261) & 255;
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int s_idx_262 = (stage_v_167 & 3);
    int stage_v_262 = (table[s_idx_262] + pub_r000829_10) & 127;
    table[s_idx_262] = (stage_v_262 + 7) & 63;
    out_sink = (out_sink + stage_v_262) & 255;
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int s_idx_263 = (sec_r000829_21 & 3);
    int stage_v_263 = (table[s_idx_263] + pub_r000829_2) & 127;
    table[s_idx_263] = (stage_v_263 + 7) & 63;
    out_sink = (out_sink + stage_v_263) & 255;
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int s_idx_264 = (stage_v_133 & 3);
    int stage_v_264 = (table[s_idx_264] + pub_r000829_16) & 127;
    table[s_idx_264] = (stage_v_264 + 7) & 63;
    out_sink = (out_sink + stage_v_264) & 255;
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int s_idx_265 = (stage_v_194 & 3);
    int stage_v_265 = (table[s_idx_265] + pub_r000829_7) & 127;
    table[s_idx_265] = (stage_v_265 + 7) & 63;
    out_sink = (out_sink + stage_v_265) & 255;
    sec_accum = (sec_accum + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int s_idx_266 = (stage_v_129 & 3);
    int stage_v_266 = (table[s_idx_266] + pub_r000829_7) & 127;
    table[s_idx_266] = (stage_v_266 + 7) & 63;
    out_sink = (out_sink + stage_v_266) & 255;
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int s_idx_267 = (stage_v_84 & 3);
    int stage_v_267 = (table[s_idx_267] + pub_r000829_10) & 127;
    table[s_idx_267] = (stage_v_267 + 7) & 63;
    out_sink = (out_sink + stage_v_267) & 255;
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int s_idx_268 = (stage_v_229 & 3);
    int stage_v_268 = (table[s_idx_268] + pub_r000829_17) & 127;
    table[s_idx_268] = (stage_v_268 + 7) & 63;
    out_sink = (out_sink + stage_v_268) & 255;
    sec_accum = (sec_accum + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int s_idx_269 = (sec_r000829_10 & 3);
    int stage_v_269 = (table[s_idx_269] + pub_r000829_20) & 127;
    table[s_idx_269] = (stage_v_269 + 7) & 63;
    out_sink = (out_sink + stage_v_269) & 255;
    sec_accum = (sec_accum + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int s_idx_270 = (sec_r000829_19 & 3);
    int stage_v_270 = (table[s_idx_270] + pub_r000829_22) & 127;
    table[s_idx_270] = (stage_v_270 + 7) & 63;
    out_sink = (out_sink + stage_v_270) & 255;
    sec_accum = (sec_accum + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int s_idx_271 = (stage_v_122 & 3);
    int stage_v_271 = (table[s_idx_271] + pub_r000829_19) & 127;
    table[s_idx_271] = (stage_v_271 + 7) & 63;
    out_sink = (out_sink + stage_v_271) & 255;
    sec_accum = (sec_accum + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int s_idx_272 = (stage_v_256 & 3);
    int stage_v_272 = (table[s_idx_272] + pub_r000829_17) & 127;
    table[s_idx_272] = (stage_v_272 + 7) & 63;
    out_sink = (out_sink + stage_v_272) & 255;
    sec_accum = (sec_accum + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int s_idx_273 = (stage_v_103 & 3);
    int stage_v_273 = (table[s_idx_273] + pub_r000829_14) & 127;
    table[s_idx_273] = (stage_v_273 + 7) & 63;
    out_sink = (out_sink + stage_v_273) & 255;
    sec_accum = (sec_accum + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int s_idx_274 = (sec_r000829_18 & 3);
    int stage_v_274 = (table[s_idx_274] + pub_r000829_5) & 127;
    table[s_idx_274] = (stage_v_274 + 7) & 63;
    out_sink = (out_sink + stage_v_274) & 255;
    sec_accum = (sec_accum + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int s_idx_275 = (stage_v_147 & 3);
    int stage_v_275 = (table[s_idx_275] + pub_r000829_12) & 127;
    table[s_idx_275] = (stage_v_275 + 7) & 63;
    out_sink = (out_sink + stage_v_275) & 255;
    sec_accum = (sec_accum + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int s_idx_276 = (stage_v_124 & 3);
    int stage_v_276 = (table[s_idx_276] + pub_r000829_14) & 127;
    table[s_idx_276] = (stage_v_276 + 7) & 63;
    out_sink = (out_sink + stage_v_276) & 255;
    sec_accum = (sec_accum + stage_v_276) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
