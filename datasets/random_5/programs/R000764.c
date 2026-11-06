/*
 * Benchmark Program: R000764
 * Security Family: arithmetic_flow
 * Generator Seed: 578424
 * High Inputs: 17 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000764_8424_0 {
    int mode;
    unsigned char prev_out;
    short cutoff;
    int buffer[3];
};

struct DeviceConfig_R000764_8424_1 {
    int port;
    unsigned char id;
    int parity;
    unsigned char timeout;
    int buffer[3];
};

struct StreamBuffer_R000764_8424_2 {
    int state;
    unsigned char tail;
    unsigned char checksum;
    unsigned char head;
    int buffer[3];
};

struct SensorNode_R000764_8424_3 {
    int gain;
    short threshold;
    int reading;
    int buffer[3];
};

union RegisterBank_R000764_8424_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000764_8424_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_51 = (aux + st.buffer[1]) & 3;
    switch (margin_51) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_27 = local_arr[aux % 3];
    acc = (acc + phase_27 * 2) & 127;
    int accumulator_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000764_8424_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int threshold_21 = local_arr[aux % 3];
    acc = (acc + threshold_21 * 2) & 127;
    int window_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_54 = (aux + st.buffer[1]) & 3;
    switch (anchor_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000764_8424_2(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000764_8424_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_71) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_62 = local_arr[aux % 3];
    acc = (acc + quantum_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int cursor_44 = local_arr[aux % 3];
    acc = (acc + cursor_44 * 2) & 127;
    int delta_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000764_8424_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_70 = (aux + st.buffer[1]) & 3;
    switch (coefficient_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000764_8424_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_39) & 63;
    acc ^= aux;
    int index_reg_74 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_74 > 13) {
        acc = (acc + index_reg_74 * 2 + 5) & 127;
        aux ^= (index_reg_74 & 15);
    } else {
        acc = (acc - index_reg_74 + 11) & 127;
        aux += 3;
    }
    int tracker_89 = (aux + st.buffer[1]) & 3;
    switch (tracker_89) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000764_8424_6(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_37 = (aux + st.buffer[1]) & 3;
    switch (anchor_37) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_90 = local_arr[aux % 3];
    acc = (acc + stride_90 * 2) & 127;
    int bound_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000764_8424_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_38 = (aux + st.buffer[1]) & 3;
    switch (quotient_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_8(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int sample_61 = local_arr[aux % 3];
    acc = (acc + sample_61 * 2) & 127;
    int damping_42 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_42 > 13) {
        acc = (acc + damping_42 * 2 + 5) & 127;
        aux ^= (damping_42 & 15);
    } else {
        acc = (acc - damping_42 + 11) & 127;
        aux += 3;
    }
    int checksum_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_21) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_48 = local_arr[aux % 3];
    acc = (acc + sample_48 * 2) & 127;
    int checksum_16 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_16 > 45) {
        acc = (acc + checksum_16 * 2 + 5) & 127;
        aux ^= (checksum_16 & 15);
    } else {
        acc = (acc - checksum_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000764_8424_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int metric_15 = local_arr[aux % 3];
    acc = (acc + metric_15 * 2) & 127;
    int mask_78 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_78 > 10) {
        acc = (acc + mask_78 * 2 + 5) & 127;
        aux ^= (mask_78 & 15);
    } else {
        acc = (acc - mask_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000764_8424_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int factor_17 = local_arr[aux % 3];
    acc = (acc + factor_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000764_8424_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_62 = (st.buffer[0] * 3 + aux) & 63;
    if (window_62 > 23) {
        acc = (acc + window_62 * 2 + 5) & 127;
        aux ^= (window_62 & 15);
    } else {
        acc = (acc - window_62 + 11) & 127;
        aux += 3;
    }
    int parity_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_13) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_76 = local_arr[aux % 3];
    acc = (acc + window_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000764_8424_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000764_8424_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_12 = (aux + st.buffer[1]) & 3;
    switch (delta_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000764_0;
    int sec_r000764_1;
    int sec_r000764_2;
    int sec_r000764_3;
    int sec_r000764_4;
    int sec_r000764_5;
    int sec_r000764_6;
    int sec_r000764_7;
    int sec_r000764_8;
    int sec_r000764_9;
    int sec_r000764_10;
    int sec_r000764_11;
    int sec_r000764_12;
    int sec_r000764_13;
    int sec_r000764_14;
    int sec_r000764_15;
    int sec_r000764_16;
    int pub_r000764_0;
    int pub_r000764_1;
    int pub_r000764_2;
    int pub_r000764_3;
    int pub_r000764_4;
    int pub_r000764_5;
    int pub_r000764_6;
    int pub_r000764_7;
    int pub_r000764_8;
    int pub_r000764_9;
    int pub_r000764_10;
    int pub_r000764_11;
    int pub_r000764_12;
    int pub_r000764_13;
    int pub_r000764_14;
    int pub_r000764_15;
    int pub_r000764_16;
    int pub_r000764_17;
    int pub_r000764_18;
    int pub_r000764_19;
    int pub_r000764_20;
    int pub_r000764_21;
    int pub_r000764_22;
    int pub_r000764_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000764_0 >= -100 && pub_r000764_0 <= 100);
    __CPROVER_assume(pub_r000764_1 >= -100 && pub_r000764_1 <= 100);
    __CPROVER_assume(pub_r000764_2 >= -100 && pub_r000764_2 <= 100);
    __CPROVER_assume(pub_r000764_3 >= -100 && pub_r000764_3 <= 100);
    __CPROVER_assume(pub_r000764_4 >= -100 && pub_r000764_4 <= 100);
    __CPROVER_assume(pub_r000764_5 >= -100 && pub_r000764_5 <= 100);
    __CPROVER_assume(pub_r000764_6 >= -100 && pub_r000764_6 <= 100);
    __CPROVER_assume(pub_r000764_7 >= -100 && pub_r000764_7 <= 100);
    __CPROVER_assume(pub_r000764_8 >= -100 && pub_r000764_8 <= 100);
    __CPROVER_assume(pub_r000764_9 >= -100 && pub_r000764_9 <= 100);
    __CPROVER_assume(pub_r000764_10 >= -100 && pub_r000764_10 <= 100);
    __CPROVER_assume(pub_r000764_11 >= -100 && pub_r000764_11 <= 100);
    __CPROVER_assume(pub_r000764_12 >= -100 && pub_r000764_12 <= 100);
    __CPROVER_assume(pub_r000764_13 >= -100 && pub_r000764_13 <= 100);
    __CPROVER_assume(pub_r000764_14 >= -100 && pub_r000764_14 <= 100);
    __CPROVER_assume(pub_r000764_15 >= -100 && pub_r000764_15 <= 100);
    __CPROVER_assume(pub_r000764_16 >= -100 && pub_r000764_16 <= 100);
    __CPROVER_assume(pub_r000764_17 >= -100 && pub_r000764_17 <= 100);
    __CPROVER_assume(pub_r000764_18 >= -100 && pub_r000764_18 <= 100);
    __CPROVER_assume(pub_r000764_19 >= -100 && pub_r000764_19 <= 100);
    __CPROVER_assume(pub_r000764_20 >= -100 && pub_r000764_20 <= 100);
    __CPROVER_assume(pub_r000764_21 >= -100 && pub_r000764_21 <= 100);
    __CPROVER_assume(pub_r000764_22 >= -100 && pub_r000764_22 <= 100);
    __CPROVER_assume(pub_r000764_23 >= -100 && pub_r000764_23 <= 100);
    __CPROVER_assume(sec_r000764_0 >= 0 && sec_r000764_0 <= 255);
    __CPROVER_assume(sec_r000764_1 >= 0 && sec_r000764_1 <= 255);
    __CPROVER_assume(sec_r000764_2 >= 0 && sec_r000764_2 <= 255);
    __CPROVER_assume(sec_r000764_3 >= 0 && sec_r000764_3 <= 255);
    __CPROVER_assume(sec_r000764_4 >= 0 && sec_r000764_4 <= 255);
    __CPROVER_assume(sec_r000764_5 >= 0 && sec_r000764_5 <= 255);
    __CPROVER_assume(sec_r000764_6 >= 0 && sec_r000764_6 <= 255);
    __CPROVER_assume(sec_r000764_7 >= 0 && sec_r000764_7 <= 255);
    __CPROVER_assume(sec_r000764_8 >= 0 && sec_r000764_8 <= 255);
    __CPROVER_assume(sec_r000764_9 >= 0 && sec_r000764_9 <= 255);
    __CPROVER_assume(sec_r000764_10 >= 0 && sec_r000764_10 <= 255);
    __CPROVER_assume(sec_r000764_11 >= 0 && sec_r000764_11 <= 255);
    __CPROVER_assume(sec_r000764_12 >= 0 && sec_r000764_12 <= 255);
    __CPROVER_assume(sec_r000764_13 >= 0 && sec_r000764_13 <= 255);
    __CPROVER_assume(sec_r000764_14 >= 0 && sec_r000764_14 <= 255);
    __CPROVER_assume(sec_r000764_15 >= 0 && sec_r000764_15 <= 255);
    __CPROVER_assume(sec_r000764_16 >= 0 && sec_r000764_16 <= 255);

    struct FilterState_R000764_8424_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000764_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000764_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000764_0 + 7) & 15;
    struct DeviceConfig_R000764_8424_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000764_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000764_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000764_0 + 9) & 15;
    struct StreamBuffer_R000764_8424_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000764_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000764_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000764_0 + 11) & 15;
    struct SensorNode_R000764_8424_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000764_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000764_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000764_0 + 13) & 15;

    union RegisterBank_R000764_8424_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 12) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 27) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 23) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 38) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 12) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 27) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 18) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 33) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 14) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 29) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 16) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 31) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
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
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_48 * 3) + (sec_r000764_5 * 2) - pub_r000764_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_49 * 3) + (sec_r000764_4 * 2) - pub_r000764_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_49 * 3) + (sec_r000764_15 * 2) - pub_r000764_18 + 9) & 127;
    sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_48 * 3) + (sec_r000764_8 * 2) - pub_r000764_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_49 * 3) + (sec_r000764_10 * 2) - pub_r000764_20 + 10) & 127;
    sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_56 * 3) + (sec_r000764_12 * 2) - pub_r000764_21 + 7) & 127;
    sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_55 * 3) + (sec_r000764_0 * 2) - pub_r000764_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_52 * 3) + (sec_r000764_11 * 2) - pub_r000764_18 + 15) & 127;
    sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_54 * 3) + (sec_r000764_13 * 2) - pub_r000764_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_53 * 3) + (sec_r000764_11 * 2) - pub_r000764_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000764_5 * 3) + (sec_r000764_5 * 2) - pub_r000764_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_52 * 3) + (sec_r000764_5 * 2) - pub_r000764_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000764_2 * 3) + (sec_r000764_2 * 2) - pub_r000764_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_51 * 3) + (sec_r000764_3 * 2) - pub_r000764_20 + 30) & 127;
    sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_60 * 3) + (sec_r000764_16 * 2) - pub_r000764_22 + 37) & 127;
    sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r000764_12 * 3) + (sec_r000764_12 * 2) - pub_r000764_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_56 * 3) + (sec_r000764_14 * 2) - pub_r000764_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_59 * 3) + (sec_r000764_1 * 2) - pub_r000764_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_13 + 18) & 127;
    sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_61 * 3) + (sec_r000764_4 * 2) - pub_r000764_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_59 * 3) + (sec_r000764_11 * 2) - pub_r000764_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_73 * 3) + (sec_r000764_10 * 2) - pub_r000764_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_69 * 3) + (sec_r000764_14 * 2) - pub_r000764_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_49 * 3) + (sec_r000764_5 * 2) - pub_r000764_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_73 * 3) + (sec_r000764_12 * 2) - pub_r000764_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_21 + 25) & 127;
    sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_48 * 3) + (sec_r000764_0 * 2) - pub_r000764_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_80 * 3) + (sec_r000764_9 * 2) - pub_r000764_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_67 * 3) + (sec_r000764_4 * 2) - pub_r000764_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_55 * 3) + (sec_r000764_0 * 2) - pub_r000764_14 + 24) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_81 * 3) + (sec_r000764_5 * 2) - pub_r000764_23 + 32) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_56 * 3) + (sec_r000764_5 * 2) - pub_r000764_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_61 * 3) + (sec_r000764_7 * 2) - pub_r000764_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_51 * 3) + (sec_r000764_5 * 2) - pub_r000764_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_67 * 3) + (sec_r000764_11 * 2) - pub_r000764_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000764_15 * 3) + (sec_r000764_15 * 2) - pub_r000764_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_57 * 3) + (sec_r000764_11 * 2) - pub_r000764_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_91 * 3) + (sec_r000764_7 * 2) - pub_r000764_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_79 * 3) + (sec_r000764_9 * 2) - pub_r000764_12 + 9) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_60 * 3) + (sec_r000764_10 * 2) - pub_r000764_18 + 28) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r000764_10 * 3) + (sec_r000764_10 * 2) - pub_r000764_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_50 * 3) + (sec_r000764_16 * 2) - pub_r000764_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_64 * 3) + (sec_r000764_3 * 2) - pub_r000764_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_80 * 3) + (sec_r000764_10 * 2) - pub_r000764_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_80 * 3) + (sec_r000764_2 * 2) - pub_r000764_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000764_12 * 3) + (sec_r000764_12 * 2) - pub_r000764_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_49 * 3) + (sec_r000764_4 * 2) - pub_r000764_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_70 * 3) + (sec_r000764_3 * 2) - pub_r000764_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_76 * 3) + (sec_r000764_5 * 2) - pub_r000764_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_92 * 3) + (sec_r000764_5 * 2) - pub_r000764_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_49 * 3) + (sec_r000764_16 * 2) - pub_r000764_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_80 * 3) + (sec_r000764_12 * 2) - pub_r000764_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_89 * 3) + (sec_r000764_10 * 2) - pub_r000764_16 + 4) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000764_3 * 3) + (sec_r000764_3 * 2) - pub_r000764_21 + 33) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_82 * 3) + (sec_r000764_6 * 2) - pub_r000764_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_85 * 3) + (sec_r000764_16 * 2) - pub_r000764_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_93 * 3) + (sec_r000764_14 * 2) - pub_r000764_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_80 * 3) + (sec_r000764_9 * 2) - pub_r000764_18 + 15) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_106 * 3) + (sec_r000764_4 * 2) - pub_r000764_19 + 34) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_22 + 19) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_116 * 3) + (sec_r000764_14 * 2) - pub_r000764_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000764_15 * 3) + (sec_r000764_15 * 2) - pub_r000764_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_56 * 3) + (sec_r000764_10 * 2) - pub_r000764_18 + 26) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_73 * 3) + (sec_r000764_1 * 2) - pub_r000764_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_55 * 3) + (sec_r000764_16 * 2) - pub_r000764_23 + 10) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_52 * 3) + (sec_r000764_3 * 2) - pub_r000764_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_55 * 3) + (sec_r000764_2 * 2) - pub_r000764_20 + 29) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_88 * 3) + (sec_r000764_12 * 2) - pub_r000764_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_109 * 3) + (sec_r000764_9 * 2) - pub_r000764_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_63 * 3) + (sec_r000764_5 * 2) - pub_r000764_23 + 19) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_59 * 3) + (sec_r000764_1 * 2) - pub_r000764_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_71 * 3) + (sec_r000764_10 * 2) - pub_r000764_20 + 18) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000764_12 * 3) + (sec_r000764_12 * 2) - pub_r000764_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000764_3 * 3) + (sec_r000764_3 * 2) - pub_r000764_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_10 + 10) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_77 * 3) + (sec_r000764_2 * 2) - pub_r000764_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_86 * 3) + (sec_r000764_10 * 2) - pub_r000764_22 + 22) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000764_13 * 3) + (sec_r000764_13 * 2) - pub_r000764_21 + 24) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_106 * 3) + (sec_r000764_3 * 2) - pub_r000764_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_71 * 3) + (sec_r000764_0 * 2) - pub_r000764_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_119 * 3) + (sec_r000764_5 * 2) - pub_r000764_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000764_8 * 3) + (sec_r000764_8 * 2) - pub_r000764_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_129 * 3) + (sec_r000764_16 * 2) - pub_r000764_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_62 * 3) + (sec_r000764_2 * 2) - pub_r000764_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_67 * 3) + (sec_r000764_15 * 2) - pub_r000764_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_139 * 3) + (sec_r000764_12 * 2) - pub_r000764_1 + 18) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000764_15 * 3) + (sec_r000764_15 * 2) - pub_r000764_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_51 * 3) + (sec_r000764_16 * 2) - pub_r000764_18 + 25) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000764_15 * 3) + (sec_r000764_15 * 2) - pub_r000764_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000764_5 * 3) + (sec_r000764_5 * 2) - pub_r000764_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r000764_10 * 3) + (sec_r000764_10 * 2) - pub_r000764_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_135 * 3) + (sec_r000764_12 * 2) - pub_r000764_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_76 * 3) + (sec_r000764_0 * 2) - pub_r000764_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_82 * 3) + (sec_r000764_16 * 2) - pub_r000764_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_87 * 3) + (sec_r000764_11 * 2) - pub_r000764_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_20 + 13) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_66 * 3) + (sec_r000764_8 * 2) - pub_r000764_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_134 * 3) + (sec_r000764_9 * 2) - pub_r000764_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_127 * 3) + (sec_r000764_13 * 2) - pub_r000764_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_139 * 3) + (sec_r000764_4 * 2) - pub_r000764_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_57 * 3) + (sec_r000764_1 * 2) - pub_r000764_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_129 * 3) + (sec_r000764_3 * 2) - pub_r000764_21 + 24) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_75 * 3) + (sec_r000764_9 * 2) - pub_r000764_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_122 * 3) + (sec_r000764_4 * 2) - pub_r000764_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_86 * 3) + (sec_r000764_10 * 2) - pub_r000764_21 + 35) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_89 * 3) + (sec_r000764_3 * 2) - pub_r000764_23 + 11) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_20 + 12) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_165 * 3) + (sec_r000764_16 * 2) - pub_r000764_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_158 * 3) + (sec_r000764_7 * 2) - pub_r000764_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_131 * 3) + (sec_r000764_8 * 2) - pub_r000764_18 + 8) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_66 * 3) + (sec_r000764_8 * 2) - pub_r000764_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_62 * 3) + (sec_r000764_16 * 2) - pub_r000764_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000764_12 * 3) + (sec_r000764_12 * 2) - pub_r000764_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_61 * 3) + (sec_r000764_14 * 2) - pub_r000764_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_98 * 3) + (sec_r000764_5 * 2) - pub_r000764_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_178 * 3) + (sec_r000764_12 * 2) - pub_r000764_23 + 11) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_77 * 3) + (sec_r000764_15 * 2) - pub_r000764_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_130 * 3) + (sec_r000764_5 * 2) - pub_r000764_20 + 15) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_174 * 3) + (sec_r000764_7 * 2) - pub_r000764_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_91 * 3) + (sec_r000764_5 * 2) - pub_r000764_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r000764_10 * 3) + (sec_r000764_10 * 2) - pub_r000764_20 + 20) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_184 * 3) + (sec_r000764_10 * 2) - pub_r000764_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_192 * 3) + (sec_r000764_2 * 2) - pub_r000764_21 + 17) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_165 * 3) + (sec_r000764_5 * 2) - pub_r000764_15 + 33) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_22 + 7) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_71 * 3) + (sec_r000764_1 * 2) - pub_r000764_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_99 * 3) + (sec_r000764_13 * 2) - pub_r000764_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_186 * 3) + (sec_r000764_13 * 2) - pub_r000764_20 + 31) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_96 * 3) + (sec_r000764_16 * 2) - pub_r000764_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_75 * 3) + (sec_r000764_10 * 2) - pub_r000764_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_197 * 3) + (sec_r000764_11 * 2) - pub_r000764_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_51 * 3) + (sec_r000764_5 * 2) - pub_r000764_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_73 * 3) + (sec_r000764_9 * 2) - pub_r000764_20 + 28) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_23 + 10) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_190 * 3) + (sec_r000764_3 * 2) - pub_r000764_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_56 * 3) + (sec_r000764_13 * 2) - pub_r000764_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_67 * 3) + (sec_r000764_1 * 2) - pub_r000764_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_65 * 3) + (sec_r000764_9 * 2) - pub_r000764_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000764_2 * 3) + (sec_r000764_2 * 2) - pub_r000764_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_153 * 3) + (sec_r000764_5 * 2) - pub_r000764_23 + 17) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_100 * 3) + (sec_r000764_8 * 2) - pub_r000764_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_173 * 3) + (sec_r000764_2 * 2) - pub_r000764_22 + 24) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_68 * 3) + (sec_r000764_11 * 2) - pub_r000764_18 + 5) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_198 * 3) + (sec_r000764_3 * 2) - pub_r000764_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_22 + 32) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_127 * 3) + (sec_r000764_15 * 2) - pub_r000764_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_207 * 3) + (sec_r000764_9 * 2) - pub_r000764_20 + 25) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_139 * 3) + (sec_r000764_5 * 2) - pub_r000764_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_131 * 3) + (sec_r000764_8 * 2) - pub_r000764_23 + 6) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_150 * 3) + (sec_r000764_1 * 2) - pub_r000764_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_67 * 3) + (sec_r000764_11 * 2) - pub_r000764_21 + 18) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_100 * 3) + (sec_r000764_10 * 2) - pub_r000764_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000764_13 * 3) + (sec_r000764_13 * 2) - pub_r000764_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r000764_2 * 3) + (sec_r000764_2 * 2) - pub_r000764_21 + 10) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_60 * 3) + (sec_r000764_7 * 2) - pub_r000764_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_218 * 3) + (sec_r000764_10 * 2) - pub_r000764_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_170 * 3) + (sec_r000764_3 * 2) - pub_r000764_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_202 * 3) + (sec_r000764_7 * 2) - pub_r000764_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_209 * 3) + (sec_r000764_9 * 2) - pub_r000764_23 + 23) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_200 * 3) + (sec_r000764_11 * 2) - pub_r000764_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_122 * 3) + (sec_r000764_5 * 2) - pub_r000764_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000764_13 * 3) + (sec_r000764_13 * 2) - pub_r000764_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_67 * 3) + (sec_r000764_15 * 2) - pub_r000764_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_103 * 3) + (sec_r000764_2 * 2) - pub_r000764_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_130 * 3) + (sec_r000764_8 * 2) - pub_r000764_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_66 * 3) + (sec_r000764_13 * 2) - pub_r000764_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_177 * 3) + (sec_r000764_13 * 2) - pub_r000764_21 + 34) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_76 * 3) + (sec_r000764_14 * 2) - pub_r000764_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_54 * 3) + (sec_r000764_6 * 2) - pub_r000764_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_120 * 3) + (sec_r000764_12 * 2) - pub_r000764_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_215 * 3) + (sec_r000764_4 * 2) - pub_r000764_21 + 25) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_195 * 3) + (sec_r000764_4 * 2) - pub_r000764_22 + 16) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_21 + 26) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_19 + 15) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_244 * 3) + (sec_r000764_4 * 2) - pub_r000764_23 + 25) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_211 * 3) + (sec_r000764_0 * 2) - pub_r000764_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_165 * 3) + (sec_r000764_10 * 2) - pub_r000764_21 + 9) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_22 + 19) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_22 + 21) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_187 * 3) + (sec_r000764_4 * 2) - pub_r000764_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_67 * 3) + (sec_r000764_1 * 2) - pub_r000764_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_129 * 3) + (sec_r000764_1 * 2) - pub_r000764_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_244 * 3) + (sec_r000764_7 * 2) - pub_r000764_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((sec_r000764_5 * 3) + (sec_r000764_5 * 2) - pub_r000764_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_165 * 3) + (sec_r000764_4 * 2) - pub_r000764_19 + 17) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((sec_r000764_1 * 3) + (sec_r000764_1 * 2) - pub_r000764_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_255 * 3) + (sec_r000764_4 * 2) - pub_r000764_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((sec_r000764_8 * 3) + (sec_r000764_8 * 2) - pub_r000764_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_122 * 3) + (sec_r000764_6 * 2) - pub_r000764_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_21 + 15) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((sec_r000764_8 * 3) + (sec_r000764_8 * 2) - pub_r000764_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r000764_5 * 3) + (sec_r000764_5 * 2) - pub_r000764_20 + 29) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_231 * 3) + (sec_r000764_14 * 2) - pub_r000764_20 + 8) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_223 * 3) + (sec_r000764_12 * 2) - pub_r000764_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_73 * 3) + (sec_r000764_15 * 2) - pub_r000764_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r000764_8 * 3) + (sec_r000764_8 * 2) - pub_r000764_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r000764_2 * 3) + (sec_r000764_2 * 2) - pub_r000764_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_170 * 3) + (sec_r000764_0 * 2) - pub_r000764_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_62 * 3) + (sec_r000764_4 * 2) - pub_r000764_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_62 * 3) + (sec_r000764_10 * 2) - pub_r000764_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_165 * 3) + (sec_r000764_5 * 2) - pub_r000764_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_191 * 3) + (sec_r000764_1 * 2) - pub_r000764_17 + 20) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r000764_3 * 3) + (sec_r000764_3 * 2) - pub_r000764_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r000764_2 * 3) + (sec_r000764_2 * 2) - pub_r000764_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r000764_0 * 3) + (sec_r000764_0 * 2) - pub_r000764_18 + 18) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((sec_r000764_16 * 3) + (sec_r000764_16 * 2) - pub_r000764_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_73 * 3) + (sec_r000764_16 * 2) - pub_r000764_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_296 * 3) + (sec_r000764_7 * 2) - pub_r000764_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_96 * 3) + (sec_r000764_5 * 2) - pub_r000764_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_225 * 3) + (sec_r000764_9 * 2) - pub_r000764_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_182 * 3) + (sec_r000764_6 * 2) - pub_r000764_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_241 * 3) + (sec_r000764_7 * 2) - pub_r000764_23 + 15) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_191 * 3) + (sec_r000764_7 * 2) - pub_r000764_21 + 28) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((sec_r000764_5 * 3) + (sec_r000764_5 * 2) - pub_r000764_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_80 * 3) + (sec_r000764_13 * 2) - pub_r000764_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_282 * 3) + (sec_r000764_12 * 2) - pub_r000764_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_121 * 3) + (sec_r000764_0 * 2) - pub_r000764_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_219 * 3) + (sec_r000764_1 * 2) - pub_r000764_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_215 * 3) + (sec_r000764_6 * 2) - pub_r000764_20 + 33) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_310 * 2) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_190 * 3) + (sec_r000764_16 * 2) - pub_r000764_22 + 10) & 127;
    sec_accum = (sec_accum + stage_v_311 * 2) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r000764_3 * 3) + (sec_r000764_3 * 2) - pub_r000764_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_312 * 2) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_313 * 2) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((sec_r000764_14 * 3) + (sec_r000764_14 * 2) - pub_r000764_23 + 33) & 127;
    sec_accum = (sec_accum + stage_v_314 * 2) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_223 * 3) + (sec_r000764_1 * 2) - pub_r000764_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_315 * 2) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_68 * 3) + (sec_r000764_10 * 2) - pub_r000764_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_316 * 2) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((sec_r000764_10 * 3) + (sec_r000764_10 * 2) - pub_r000764_23 + 29) & 127;
    sec_accum = (sec_accum + stage_v_317 * 2) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_211 * 3) + (sec_r000764_14 * 2) - pub_r000764_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_318 * 2) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_295 * 3) + (sec_r000764_1 * 2) - pub_r000764_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_319 * 2) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r000764_6 * 3) + (sec_r000764_6 * 2) - pub_r000764_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_320 * 2) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_57 * 3) + (sec_r000764_13 * 2) - pub_r000764_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_321 * 2) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_19 + 5) & 127;
    sec_accum = (sec_accum + stage_v_322 * 2) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_323 * 2) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_290 * 3) + (sec_r000764_8 * 2) - pub_r000764_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_324 * 2) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_219 * 3) + (sec_r000764_13 * 2) - pub_r000764_22 + 16) & 127;
    sec_accum = (sec_accum + stage_v_325 * 2) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_326 * 2) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_155 * 3) + (sec_r000764_10 * 2) - pub_r000764_21 + 14) & 127;
    sec_accum = (sec_accum + stage_v_327 * 2) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_264 * 3) + (sec_r000764_14 * 2) - pub_r000764_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_328 * 2) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_168 * 3) + (sec_r000764_2 * 2) - pub_r000764_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_329 * 2) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_147 * 3) + (sec_r000764_12 * 2) - pub_r000764_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_330 * 2) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_308 * 3) + (sec_r000764_9 * 2) - pub_r000764_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_331 * 2) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_323 * 3) + (sec_r000764_0 * 2) - pub_r000764_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_332 * 2) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_22 + 9) & 127;
    sec_accum = (sec_accum + stage_v_333 * 2) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r000764_4 * 3) + (sec_r000764_4 * 2) - pub_r000764_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_334 * 2) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((sec_r000764_10 * 3) + (sec_r000764_10 * 2) - pub_r000764_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_335 * 2) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_20 + 35) & 127;
    sec_accum = (sec_accum + stage_v_336 * 2) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_217 * 3) + (sec_r000764_14 * 2) - pub_r000764_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_337 * 2) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_76 * 3) + (sec_r000764_5 * 2) - pub_r000764_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_338 * 2) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_59 * 3) + (sec_r000764_6 * 2) - pub_r000764_23 + 25) & 127;
    sec_accum = (sec_accum + stage_v_339 * 2) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_195 * 3) + (sec_r000764_11 * 2) - pub_r000764_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_340 * 2) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r000764_9 * 3) + (sec_r000764_9 * 2) - pub_r000764_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_341 * 2) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r000764_15 * 3) + (sec_r000764_15 * 2) - pub_r000764_23 + 3) & 127;
    sec_accum = (sec_accum + stage_v_342 * 2) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_202 * 3) + (sec_r000764_5 * 2) - pub_r000764_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_343 * 2) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_149 * 3) + (sec_r000764_0 * 2) - pub_r000764_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_344 * 2) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((sec_r000764_7 * 3) + (sec_r000764_7 * 2) - pub_r000764_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_345 * 2) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r000764_11 * 3) + (sec_r000764_11 * 2) - pub_r000764_21 + 26) & 127;
    sec_accum = (sec_accum + stage_v_346 * 2) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_250 * 3) + (sec_r000764_12 * 2) - pub_r000764_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_347 * 2) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_235 * 3) + (sec_r000764_9 * 2) - pub_r000764_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_348 * 2) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r000764_8 * 3) + (sec_r000764_8 * 2) - pub_r000764_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_349 * 2) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_75 * 3) + (sec_r000764_16 * 2) - pub_r000764_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_350 * 2) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_271 * 3) + (sec_r000764_12 * 2) - pub_r000764_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_351 * 2) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_325 * 3) + (sec_r000764_12 * 2) - pub_r000764_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_352 * 2) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
