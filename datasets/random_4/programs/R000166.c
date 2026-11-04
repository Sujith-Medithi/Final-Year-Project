/*
 * Benchmark Program: R000166
 * Family: direct_leakage
 * Generator Seed: 416613
 * High Inputs: 18 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000166_6613_0 {
    unsigned char fee;
    unsigned char balance;
    int rate;
    int auth_code;
    int buffer[3];
};

struct AudioFrame_R000166_6613_1 {
    int channels;
    int envelope;
    int sample_rate;
    int rms;
    int buffer[3];
};

struct EventLog_R000166_6613_2 {
    short timestamp;
    short facility;
    int severity;
    int signature;
    int code;
    int buffer[3];
};

union TelemetryField_R000166_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000166_6613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000166_6613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_18) & 63;
    acc ^= aux;
    int cursor_23 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_23 = (cursor_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_1(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000166_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int damping_29 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_29 > 48) {
        acc = (acc + damping_29 * 2 + 5) & 127;
        aux ^= (damping_29 & 15);
    } else {
        acc = (acc - damping_29 + 11) & 127;
        aux += 3;
    }
    int window_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000166_6613_2(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_84 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_84 > 11) {
        acc = (acc + factor_84 * 2 + 5) & 127;
        aux ^= (factor_84 & 15);
    } else {
        acc = (acc - factor_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_49 = local_arr[aux % 3];
    acc = (acc + bound_49 * 2) & 127;
    int mask_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000166_6613_3(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000166_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000166_6613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000166_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int mask_52 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_52 > 33) {
        acc = (acc + mask_52 * 2 + 5) & 127;
        aux ^= (mask_52 & 15);
    } else {
        acc = (acc - mask_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_32) & 63;
    acc ^= aux;
    int segment_72 = 0;
    for (int k = 0; k < 3; k++) {
        segment_72 = (segment_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_5(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_67 = local_arr[aux % 3];
    acc = (acc + cursor_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000166_6613_6(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000166_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_10 = local_arr[aux % 3];
    acc = (acc + metric_10 * 2) & 127;
    int factor_93 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_93 > 41) {
        acc = (acc + factor_93 * 2 + 5) & 127;
        aux ^= (factor_93 & 15);
    } else {
        acc = (acc - factor_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_7(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int scale_36 = local_arr[aux % 3];
    acc = (acc + scale_36 * 2) & 127;
    int vector_46 = 0;
    for (int k = 0; k < 2; k++) {
        vector_46 = (vector_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_46) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000166_6613_8(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000166_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_50 = 0;
    for (int k = 0; k < 3; k++) {
        weight_50 = (weight_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_76 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_76 > 50) {
        acc = (acc + index_reg_76 * 2 + 5) & 127;
        aux ^= (index_reg_76 & 15);
    } else {
        acc = (acc - index_reg_76 + 11) & 127;
        aux += 3;
    }
    int weight_72 = (aux + st.buffer[1]) & 3;
    switch (weight_72) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_90 = (aux + st.buffer[1]) & 3;
    switch (index_reg_90) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_90 = 0;
    for (int k = 0; k < 3; k++) {
        delta_90 = (delta_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_85 = local_arr[aux % 3];
    acc = (acc + residue_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000166_6613_10(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quotient_79 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_79 > 37) {
        acc = (acc + quotient_79 * 2 + 5) & 127;
        aux ^= (quotient_79 & 15);
    } else {
        acc = (acc - quotient_79 + 11) & 127;
        aux += 3;
    }
    int vector_99 = (aux + st.buffer[1]) & 3;
    switch (vector_99) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000166_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_65) & 63;
    acc ^= aux;
    int delta_94 = 0;
    for (int k = 0; k < 2; k++) {
        delta_94 = (delta_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_94) & 127;
    }
    int quantum_90 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_90 > 34) {
        acc = (acc + quantum_90 * 2 + 5) & 127;
        aux ^= (quantum_90 & 15);
    } else {
        acc = (acc - quantum_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_12(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000166_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int window_33 = (st.buffer[0] * 3 + aux) & 63;
    if (window_33 > 43) {
        acc = (acc + window_33 * 2 + 5) & 127;
        aux ^= (window_33 & 15);
    } else {
        acc = (acc - window_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_98 = local_arr[aux % 3];
    acc = (acc + anchor_98 * 2) & 127;
    int accumulator_32 = (aux + st.buffer[1]) & 3;
    switch (accumulator_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000166_6613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000166_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int checksum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_42) & 63;
    acc ^= aux;
    int segment_93 = 0;
    for (int k = 0; k < 3; k++) {
        segment_93 = (segment_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_93) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000166_6613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000166_6613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_72) & 63;
    acc ^= aux;
    int scale_30 = 0;
    for (int k = 0; k < 3; k++) {
        scale_30 = (scale_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_30) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000166_0;
    int sec_r000166_1;
    int sec_r000166_2;
    int sec_r000166_3;
    int sec_r000166_4;
    int sec_r000166_5;
    int sec_r000166_6;
    int sec_r000166_7;
    int sec_r000166_8;
    int sec_r000166_9;
    int sec_r000166_10;
    int sec_r000166_11;
    int sec_r000166_12;
    int sec_r000166_13;
    int sec_r000166_14;
    int sec_r000166_15;
    int sec_r000166_16;
    int sec_r000166_17;
    int pub_r000166_0;
    int pub_r000166_1;
    int pub_r000166_2;
    int pub_r000166_3;
    int pub_r000166_4;
    int pub_r000166_5;
    int pub_r000166_6;
    int pub_r000166_7;
    int pub_r000166_8;
    int pub_r000166_9;
    int pub_r000166_10;
    int pub_r000166_11;
    int pub_r000166_12;
    int pub_r000166_13;
    int pub_r000166_14;
    int pub_r000166_15;
    int pub_r000166_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000166_0 >= -100 && pub_r000166_0 <= 100);
    __CPROVER_assume(pub_r000166_1 >= -100 && pub_r000166_1 <= 100);
    __CPROVER_assume(pub_r000166_2 >= -100 && pub_r000166_2 <= 100);
    __CPROVER_assume(pub_r000166_3 >= -100 && pub_r000166_3 <= 100);
    __CPROVER_assume(pub_r000166_4 >= -100 && pub_r000166_4 <= 100);
    __CPROVER_assume(pub_r000166_5 >= -100 && pub_r000166_5 <= 100);
    __CPROVER_assume(pub_r000166_6 >= -100 && pub_r000166_6 <= 100);
    __CPROVER_assume(pub_r000166_7 >= -100 && pub_r000166_7 <= 100);
    __CPROVER_assume(pub_r000166_8 >= -100 && pub_r000166_8 <= 100);
    __CPROVER_assume(pub_r000166_9 >= -100 && pub_r000166_9 <= 100);
    __CPROVER_assume(pub_r000166_10 >= -100 && pub_r000166_10 <= 100);
    __CPROVER_assume(pub_r000166_11 >= -100 && pub_r000166_11 <= 100);
    __CPROVER_assume(pub_r000166_12 >= -100 && pub_r000166_12 <= 100);
    __CPROVER_assume(pub_r000166_13 >= -100 && pub_r000166_13 <= 100);
    __CPROVER_assume(pub_r000166_14 >= -100 && pub_r000166_14 <= 100);
    __CPROVER_assume(pub_r000166_15 >= -100 && pub_r000166_15 <= 100);
    __CPROVER_assume(pub_r000166_16 >= -100 && pub_r000166_16 <= 100);
    __CPROVER_assume(sec_r000166_0 >= 0 && sec_r000166_0 <= 255);
    __CPROVER_assume(sec_r000166_1 >= 0 && sec_r000166_1 <= 255);
    __CPROVER_assume(sec_r000166_2 >= 0 && sec_r000166_2 <= 255);
    __CPROVER_assume(sec_r000166_3 >= 0 && sec_r000166_3 <= 255);
    __CPROVER_assume(sec_r000166_4 >= 0 && sec_r000166_4 <= 255);
    __CPROVER_assume(sec_r000166_5 >= 0 && sec_r000166_5 <= 255);
    __CPROVER_assume(sec_r000166_6 >= 0 && sec_r000166_6 <= 255);
    __CPROVER_assume(sec_r000166_7 >= 0 && sec_r000166_7 <= 255);
    __CPROVER_assume(sec_r000166_8 >= 0 && sec_r000166_8 <= 255);
    __CPROVER_assume(sec_r000166_9 >= 0 && sec_r000166_9 <= 255);
    __CPROVER_assume(sec_r000166_10 >= 0 && sec_r000166_10 <= 255);
    __CPROVER_assume(sec_r000166_11 >= 0 && sec_r000166_11 <= 255);
    __CPROVER_assume(sec_r000166_12 >= 0 && sec_r000166_12 <= 255);
    __CPROVER_assume(sec_r000166_13 >= 0 && sec_r000166_13 <= 255);
    __CPROVER_assume(sec_r000166_14 >= 0 && sec_r000166_14 <= 255);
    __CPROVER_assume(sec_r000166_15 >= 0 && sec_r000166_15 <= 255);
    __CPROVER_assume(sec_r000166_16 >= 0 && sec_r000166_16 <= 255);
    __CPROVER_assume(sec_r000166_17 >= 0 && sec_r000166_17 <= 255);

    struct Transaction_R000166_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000166_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000166_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000166_0 + 7) & 15;
    struct AudioFrame_R000166_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000166_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000166_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000166_0 + 9) & 15;
    struct EventLog_R000166_6613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000166_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000166_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000166_0 + 11) & 15;

    union TelemetryField_R000166_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 19) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 34) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 21) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 36) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 26) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 41) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 35) {
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
    if (stage_v_19 > 18) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 33) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 12) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 27) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 36) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 51) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 40) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 55) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 30) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 45) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 13) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 28) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 12) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 27) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 23) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 38) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 23) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 38) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 29) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 44) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 11) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 26) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 34) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 49) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 13) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 28) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 48) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 39) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 54) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 15) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 30) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 13) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 28) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 23) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 38) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 12) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 27) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_2.buffer[2] * 2 + 283) & 63;
    if (stage_v_92 > 25) {
        out_sink = (out_sink + stage_v_92 - 5) & 255;
        if (stage_v_92 > 40) {
            chk_sum ^= (stage_v_92 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_92 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_1.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 18) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 33) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = table[0];
    table[0] = (table[1] + 193) & 63;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
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

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 13) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 28) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 36) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 51) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[0] ^ 118) & 3;
    switch (stage_v_115) {
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

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 15) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 30) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_128 = (stage_v_128 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 12) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 27) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 16) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 31) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 21) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 36) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_141 = (stage_v_141 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 33) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 48) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[2] * 2 + 445) & 63;
    if (stage_v_146 > 23) {
        out_sink = (out_sink + stage_v_146 - 5) & 255;
        if (stage_v_146 > 38) {
            chk_sum ^= (stage_v_146 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_146 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = table[3];
    table[3] = (table[0] + 295) & 63;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_1.buffer[0] ^ 151) & 3;
    switch (stage_v_148) {
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

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[0] ^ 155) & 3;
    switch (stage_v_152) {
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

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_1.buffer[1] * 2 + 469) & 63;
    if (stage_v_154 > 13) {
        out_sink = (out_sink + stage_v_154 - 5) & 255;
        if (stage_v_154 > 28) {
            chk_sum ^= (stage_v_154 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_154 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_2.buffer[0] ^ 158) & 3;
    switch (stage_v_155) {
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

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 37) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 52) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (out_sink > 100) ? (chk_sum & 31) : (163 & 31);
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= (stage_v_158 << 1) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = table[3];
    table[3] = (table[0] + 319) & 63;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_1.buffer[1] * 2 + 487) & 63;
    if (stage_v_160 > 12) {
        out_sink = (out_sink + stage_v_160 - 5) & 255;
        if (stage_v_160 > 27) {
            chk_sum ^= (stage_v_160 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_160 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_164 = (stage_v_164 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;

    /* Security Information Flow: Family = direct_leakage */
    out_sink += ((sec_r000166_1 * 2) + (sec_r000166_17 * 3)) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
