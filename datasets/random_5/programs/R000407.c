/*
 * Benchmark Program: R000407
 * Security Family: nested_implicit_flow
 * Generator Seed: 540713
 * High Inputs: 23 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000407_713_0 {
    short prev_in;
    unsigned char mode;
    int cutoff;
    short prev_out;
    int damping;
    int buffer[3];
};

struct EventLog_R000407_713_1 {
    unsigned char facility;
    short signature;
    short code;
    short severity;
    short seq;
    short timestamp;
    int buffer[3];
};

struct Transaction_R000407_713_2 {
    short rate;
    unsigned char balance;
    unsigned char account_id;
    unsigned char status;
    short fee;
    unsigned char auth_code;
    int buffer[3];
};

struct AudioFrame_R000407_713_3 {
    short gain;
    int envelope;
    int sample_rate;
    int buffer[3];
};

union RegisterBank_R000407_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000407_713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000407_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int threshold_12 = local_arr[aux % 3];
    acc = (acc + threshold_12 * 2) & 127;
    int window_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_19) & 63;
    acc ^= aux;
    int accumulator_22 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_22 > 19) {
        acc = (acc + accumulator_22 * 2 + 5) & 127;
        aux ^= (accumulator_22 & 15);
    } else {
        acc = (acc - accumulator_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000407_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_19) & 63;
    acc ^= aux;
    int mask_71 = (aux + st.buffer[1]) & 3;
    switch (mask_71) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_2(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000407_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_76 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_76 > 18) {
        acc = (acc + bound_76 * 2 + 5) & 127;
        aux ^= (bound_76 & 15);
    } else {
        acc = (acc - bound_76 + 11) & 127;
        aux += 3;
    }
    int mask_69 = (aux + st.buffer[1]) & 3;
    switch (mask_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_43 = local_arr[aux % 3];
    acc = (acc + tally_43 * 2) & 127;
    int residue_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000407_713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000407_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_89 = local_arr[aux % 3];
    acc = (acc + factor_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000407_713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000407_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_64) & 63;
    acc ^= aux;
    int delta_54 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_54 > 36) {
        acc = (acc + delta_54 * 2 + 5) & 127;
        aux ^= (delta_54 & 15);
    } else {
        acc = (acc - delta_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000407_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_81 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_81 > 16) {
        acc = (acc + margin_81 * 2 + 5) & 127;
        aux ^= (margin_81 & 15);
    } else {
        acc = (acc - margin_81 + 11) & 127;
        aux += 3;
    }
    int stride_39 = (aux + st.buffer[1]) & 3;
    switch (stride_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000407_713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000407_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_57 = (aux + st.buffer[1]) & 3;
    switch (threshold_57) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_40 = local_arr[aux % 3];
    acc = (acc + parity_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000407_713_7(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000407_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_27 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_27 > 10) {
        acc = (acc + parity_27 * 2 + 5) & 127;
        aux ^= (parity_27 & 15);
    } else {
        acc = (acc - parity_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_57 = local_arr[aux % 3];
    acc = (acc + damping_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000407_713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000407_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_42) & 63;
    acc ^= aux;
    int weight_30 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_30 > 17) {
        acc = (acc + weight_30 * 2 + 5) & 127;
        aux ^= (weight_30 & 15);
    } else {
        acc = (acc - weight_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_9(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000407_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_14 = local_arr[aux % 3];
    acc = (acc + damping_14 * 2) & 127;
    int sample_13 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_13 > 30) {
        acc = (acc + sample_13 * 2 + 5) & 127;
        aux ^= (sample_13 & 15);
    } else {
        acc = (acc - sample_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000407_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000407_713_11(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000407_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int anchor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_69) & 63;
    acc ^= aux;
    int quotient_65 = (aux + st.buffer[1]) & 3;
    switch (quotient_65) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000407_713_12(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000407_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int index_reg_71 = local_arr[aux % 3];
    acc = (acc + index_reg_71 * 2) & 127;
    int threshold_68 = (aux + st.buffer[1]) & 3;
    switch (threshold_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000407_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_63 = local_arr[aux % 3];
    acc = (acc + sample_63 * 2) & 127;
    int factor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_41 > 46) {
        acc = (acc + factor_41 * 2 + 5) & 127;
        aux ^= (factor_41 & 15);
    } else {
        acc = (acc - factor_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000407_713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000407_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int segment_12 = local_arr[aux % 3];
    acc = (acc + segment_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000407_0;
    int sec_r000407_1;
    int sec_r000407_2;
    int sec_r000407_3;
    int sec_r000407_4;
    int sec_r000407_5;
    int sec_r000407_6;
    int sec_r000407_7;
    int sec_r000407_8;
    int sec_r000407_9;
    int sec_r000407_10;
    int sec_r000407_11;
    int sec_r000407_12;
    int sec_r000407_13;
    int sec_r000407_14;
    int sec_r000407_15;
    int sec_r000407_16;
    int sec_r000407_17;
    int sec_r000407_18;
    int sec_r000407_19;
    int sec_r000407_20;
    int sec_r000407_21;
    int sec_r000407_22;
    int pub_r000407_0;
    int pub_r000407_1;
    int pub_r000407_2;
    int pub_r000407_3;
    int pub_r000407_4;
    int pub_r000407_5;
    int pub_r000407_6;
    int pub_r000407_7;
    int pub_r000407_8;
    int pub_r000407_9;
    int pub_r000407_10;
    int pub_r000407_11;
    int pub_r000407_12;
    int pub_r000407_13;
    int pub_r000407_14;
    int pub_r000407_15;
    int pub_r000407_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000407_0 >= -100 && pub_r000407_0 <= 100);
    __CPROVER_assume(pub_r000407_1 >= -100 && pub_r000407_1 <= 100);
    __CPROVER_assume(pub_r000407_2 >= -100 && pub_r000407_2 <= 100);
    __CPROVER_assume(pub_r000407_3 >= -100 && pub_r000407_3 <= 100);
    __CPROVER_assume(pub_r000407_4 >= -100 && pub_r000407_4 <= 100);
    __CPROVER_assume(pub_r000407_5 >= -100 && pub_r000407_5 <= 100);
    __CPROVER_assume(pub_r000407_6 >= -100 && pub_r000407_6 <= 100);
    __CPROVER_assume(pub_r000407_7 >= -100 && pub_r000407_7 <= 100);
    __CPROVER_assume(pub_r000407_8 >= -100 && pub_r000407_8 <= 100);
    __CPROVER_assume(pub_r000407_9 >= -100 && pub_r000407_9 <= 100);
    __CPROVER_assume(pub_r000407_10 >= -100 && pub_r000407_10 <= 100);
    __CPROVER_assume(pub_r000407_11 >= -100 && pub_r000407_11 <= 100);
    __CPROVER_assume(pub_r000407_12 >= -100 && pub_r000407_12 <= 100);
    __CPROVER_assume(pub_r000407_13 >= -100 && pub_r000407_13 <= 100);
    __CPROVER_assume(pub_r000407_14 >= -100 && pub_r000407_14 <= 100);
    __CPROVER_assume(pub_r000407_15 >= -100 && pub_r000407_15 <= 100);
    __CPROVER_assume(pub_r000407_16 >= -100 && pub_r000407_16 <= 100);
    __CPROVER_assume(sec_r000407_0 >= 0 && sec_r000407_0 <= 255);
    __CPROVER_assume(sec_r000407_1 >= 0 && sec_r000407_1 <= 255);
    __CPROVER_assume(sec_r000407_2 >= 0 && sec_r000407_2 <= 255);
    __CPROVER_assume(sec_r000407_3 >= 0 && sec_r000407_3 <= 255);
    __CPROVER_assume(sec_r000407_4 >= 0 && sec_r000407_4 <= 255);
    __CPROVER_assume(sec_r000407_5 >= 0 && sec_r000407_5 <= 255);
    __CPROVER_assume(sec_r000407_6 >= 0 && sec_r000407_6 <= 255);
    __CPROVER_assume(sec_r000407_7 >= 0 && sec_r000407_7 <= 255);
    __CPROVER_assume(sec_r000407_8 >= 0 && sec_r000407_8 <= 255);
    __CPROVER_assume(sec_r000407_9 >= 0 && sec_r000407_9 <= 255);
    __CPROVER_assume(sec_r000407_10 >= 0 && sec_r000407_10 <= 255);
    __CPROVER_assume(sec_r000407_11 >= 0 && sec_r000407_11 <= 255);
    __CPROVER_assume(sec_r000407_12 >= 0 && sec_r000407_12 <= 255);
    __CPROVER_assume(sec_r000407_13 >= 0 && sec_r000407_13 <= 255);
    __CPROVER_assume(sec_r000407_14 >= 0 && sec_r000407_14 <= 255);
    __CPROVER_assume(sec_r000407_15 >= 0 && sec_r000407_15 <= 255);
    __CPROVER_assume(sec_r000407_16 >= 0 && sec_r000407_16 <= 255);
    __CPROVER_assume(sec_r000407_17 >= 0 && sec_r000407_17 <= 255);
    __CPROVER_assume(sec_r000407_18 >= 0 && sec_r000407_18 <= 255);
    __CPROVER_assume(sec_r000407_19 >= 0 && sec_r000407_19 <= 255);
    __CPROVER_assume(sec_r000407_20 >= 0 && sec_r000407_20 <= 255);
    __CPROVER_assume(sec_r000407_21 >= 0 && sec_r000407_21 <= 255);
    __CPROVER_assume(sec_r000407_22 >= 0 && sec_r000407_22 <= 255);

    struct FilterState_R000407_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000407_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000407_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000407_0 + 7) & 15;
    struct EventLog_R000407_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000407_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000407_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000407_0 + 9) & 15;
    struct Transaction_R000407_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000407_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000407_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000407_0 + 11) & 15;
    struct AudioFrame_R000407_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000407_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000407_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000407_0 + 13) & 15;

    union RegisterBank_R000407_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 14) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 29) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 18) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 33) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 26) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 41) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 35) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 50) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 39) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 54) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
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
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

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
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 29) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 44) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000407_8 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_49 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000407_18 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_50 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_51 = (pub_r000407_11 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000407_11 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000407_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000407_11 & 1) != 0) {
        if ((sec_r000407_18 & 2) != 0) {
            stage_v_52 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_10 & 2) != 0) {
            stage_v_53 = (pub_r000407_11 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000407_11 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000407_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000407_16 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_54 = (pub_r000407_9 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000407_9 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000407_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_18 & 2) != 0) {
            stage_v_55 = (pub_r000407_4 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000407_4 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000407_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_56 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_57 = (pub_r000407_4 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000407_4 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000407_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000407_16 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_58 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000407_10 & 2) != 0) {
            stage_v_59 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000407_15 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_60 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000407_18 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_61 = (pub_r000407_9 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000407_9 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000407_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000407_0 & 2) != 0) {
            stage_v_62 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_63 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_64 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_65 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_66 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000407_8 & 2) != 0) {
            stage_v_67 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000407_20 & 1) != 0) {
        if ((sec_r000407_3 & 2) != 0) {
            stage_v_68 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_69 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000407_14 & 2) != 0) {
            stage_v_70 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_71 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000407_10 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_72 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000407_9 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_73 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000407_10 & 1) != 0) {
        if ((sec_r000407_1 & 2) != 0) {
            stage_v_74 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_75 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_76 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_77 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_78 = (pub_r000407_3 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000407_3 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000407_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_79 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000407_9 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_80 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000407_10 & 2) != 0) {
            stage_v_81 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_82 = (pub_r000407_13 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000407_13 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000407_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_83 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_22 & 2) != 0) {
            stage_v_84 = (pub_r000407_11 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000407_11 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000407_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000407_11 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_85 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000407_7 & 2) != 0) {
            stage_v_86 = (pub_r000407_11 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000407_11 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000407_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_87 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000407_1 & 2) != 0) {
            stage_v_88 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_89 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_90 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000407_20 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_91 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000407_5 & 1) != 0) {
        if ((sec_r000407_17 & 2) != 0) {
            stage_v_92 = (pub_r000407_13 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000407_13 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000407_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000407_6 & 1) != 0) {
        if ((sec_r000407_14 & 2) != 0) {
            stage_v_93 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000407_22 & 1) != 0) {
        if ((sec_r000407_5 & 2) != 0) {
            stage_v_94 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000407_10 & 1) != 0) {
        if ((sec_r000407_0 & 2) != 0) {
            stage_v_95 = (pub_r000407_12 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000407_12 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000407_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_96 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000407_7 & 2) != 0) {
            stage_v_97 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_2 & 2) != 0) {
            stage_v_98 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000407_17 & 2) != 0) {
            stage_v_99 = (pub_r000407_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000407_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000407_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000407_10 & 2) != 0) {
            stage_v_100 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000407_17 & 2) != 0) {
            stage_v_101 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_102 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000407_11 & 1) != 0) {
        if ((sec_r000407_9 & 2) != 0) {
            stage_v_103 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000407_17 & 2) != 0) {
            stage_v_104 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_105 = (pub_r000407_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000407_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000407_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000407_5 & 2) != 0) {
            stage_v_106 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000407_18 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_107 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000407_17 & 2) != 0) {
            stage_v_108 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000407_15 & 1) != 0) {
        if ((sec_r000407_18 & 2) != 0) {
            stage_v_109 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_110 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_111 = (pub_r000407_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000407_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000407_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_112 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000407_12 & 2) != 0) {
            stage_v_113 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_114 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000407_22 & 2) != 0) {
            stage_v_115 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000407_9 & 2) != 0) {
            stage_v_116 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000407_5 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_117 = (pub_r000407_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000407_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000407_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000407_18 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_118 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000407_6 & 1) != 0) {
        if ((sec_r000407_5 & 2) != 0) {
            stage_v_119 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000407_2 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_120 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_121 = (pub_r000407_4 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000407_4 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000407_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_122 = (pub_r000407_5 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000407_5 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000407_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000407_22 & 2) != 0) {
            stage_v_123 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000407_14 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_124 = (pub_r000407_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000407_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000407_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_125 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_126 = (pub_r000407_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000407_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000407_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_127 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000407_16 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_128 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_129 = (pub_r000407_11 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000407_11 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000407_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000407_8 & 2) != 0) {
            stage_v_130 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000407_9 & 2) != 0) {
            stage_v_131 = (pub_r000407_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000407_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000407_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000407_5 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_132 = (pub_r000407_9 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000407_9 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000407_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_133 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000407_22 & 1) != 0) {
        if ((sec_r000407_4 & 2) != 0) {
            stage_v_134 = (pub_r000407_3 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000407_3 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000407_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000407_17 & 1) != 0) {
        if ((sec_r000407_5 & 2) != 0) {
            stage_v_135 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000407_19 & 1) != 0) {
        if ((sec_r000407_18 & 2) != 0) {
            stage_v_136 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_137 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000407_7 & 2) != 0) {
            stage_v_138 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000407_15 & 2) != 0) {
            stage_v_139 = (pub_r000407_14 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000407_14 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000407_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000407_7 & 2) != 0) {
            stage_v_140 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000407_14 & 2) != 0) {
            stage_v_141 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_142 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000407_0 & 2) != 0) {
            stage_v_143 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000407_2 & 1) != 0) {
        if ((sec_r000407_21 & 2) != 0) {
            stage_v_144 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_145 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000407_2 & 2) != 0) {
            stage_v_146 = (pub_r000407_7 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000407_7 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000407_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000407_15 & 1) != 0) {
        if ((sec_r000407_16 & 2) != 0) {
            stage_v_147 = (pub_r000407_4 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000407_4 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000407_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_148 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000407_14 & 2) != 0) {
            stage_v_149 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000407_6 & 2) != 0) {
            stage_v_150 = (pub_r000407_0 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000407_0 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000407_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000407_21 & 1) != 0) {
        if ((sec_r000407_22 & 2) != 0) {
            stage_v_151 = (pub_r000407_3 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000407_3 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000407_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000407_17 & 1) != 0) {
        if ((sec_r000407_0 & 2) != 0) {
            stage_v_152 = (pub_r000407_2 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000407_2 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000407_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000407_8 & 2) != 0) {
            stage_v_153 = (pub_r000407_16 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000407_16 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000407_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000407_20 & 2) != 0) {
            stage_v_154 = (pub_r000407_1 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000407_1 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000407_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000407_19 & 2) != 0) {
            stage_v_155 = (pub_r000407_15 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000407_15 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000407_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000407_13 & 2) != 0) {
            stage_v_156 = (pub_r000407_8 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000407_8 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000407_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000407_11 & 2) != 0) {
            stage_v_157 = (pub_r000407_6 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000407_6 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000407_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000407_3 & 2) != 0) {
            stage_v_158 = (pub_r000407_10 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000407_10 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000407_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
