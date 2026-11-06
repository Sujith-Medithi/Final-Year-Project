/*
 * Benchmark Program: R000607
 * Security Family: nested_implicit_flow
 * Generator Seed: 560713
 * High Inputs: 19 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000607_713_0 {
    short gain;
    unsigned char sample_rate;
    int rms;
    unsigned char peak;
    int channels;
    int envelope;
    int buffer[3];
};

struct MatrixBlock_R000607_713_1 {
    int dim;
    int trace;
    int scale;
    unsigned char stride;
    int buffer[3];
};

struct EventLog_R000607_713_2 {
    short code;
    int seq;
    int timestamp;
    int signature;
    unsigned char severity;
    unsigned char facility;
    int buffer[3];
};

union ColorPixel_R000607_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000607_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000607_713_0(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000607_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int mask_76 = local_arr[aux % 3];
    acc = (acc + mask_76 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int stride_53 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_53 > 17) {
        acc = (acc + stride_53 * 2 + 5) & 127;
        aux ^= (stride_53 & 15);
    } else {
        acc = (acc - stride_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_35 = local_arr[aux % 3];
    acc = (acc + threshold_35 * 2) & 127;
    int pivot_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000607_713_2(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_97) & 63;
    acc ^= aux;
    int mask_24 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_24 > 47) {
        acc = (acc + mask_24 * 2 + 5) & 127;
        aux ^= (mask_24 & 15);
    } else {
        acc = (acc - mask_24 + 11) & 127;
        aux += 3;
    }
    int index_reg_48 = (aux + st.buffer[1]) & 3;
    switch (index_reg_48) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000607_713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_94 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_94 > 48) {
        acc = (acc + vector_94 * 2 + 5) & 127;
        aux ^= (vector_94 & 15);
    } else {
        acc = (acc - vector_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_43 = local_arr[aux % 3];
    acc = (acc + segment_43 * 2) & 127;
    int parity_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_70) & 63;
    acc ^= aux;
    int tracker_10 = (aux + st.buffer[1]) & 3;
    switch (tracker_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000607_713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000607_713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_75) & 63;
    acc ^= aux;
    int offset_94 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_94 > 25) {
        acc = (acc + offset_94 * 2 + 5) & 127;
        aux ^= (offset_94 & 15);
    } else {
        acc = (acc - offset_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_56 = local_arr[aux % 3];
    acc = (acc + residue_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_6(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int damping_74 = (aux + st.buffer[1]) & 3;
    switch (damping_74) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_86 = local_arr[aux % 3];
    acc = (acc + metric_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_7(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000607_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_47 = (aux + st.buffer[1]) & 3;
    switch (sample_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000607_713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_37 = local_arr[aux % 3];
    acc = (acc + residue_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_10(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000607_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_87 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_87 > 27) {
        acc = (acc + tracker_87 * 2 + 5) & 127;
        aux ^= (tracker_87 & 15);
    } else {
        acc = (acc - tracker_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_88 = (aux + st.buffer[1]) & 3;
    switch (metric_88) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_34 = local_arr[aux % 3];
    acc = (acc + offset_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_11(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_61 = (aux + st.buffer[1]) & 3;
    switch (residue_61) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_47 = local_arr[aux % 3];
    acc = (acc + quotient_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000607_713_12(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000607_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_85 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_85 > 47) {
        acc = (acc + residue_85 * 2 + 5) & 127;
        aux ^= (residue_85 & 15);
    } else {
        acc = (acc - residue_85 + 11) & 127;
        aux += 3;
    }
    int mask_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_19) & 63;
    acc ^= aux;
    int tally_82 = (aux + st.buffer[1]) & 3;
    switch (tally_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000607_713_13(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int delta_36 = local_arr[aux % 3];
    acc = (acc + delta_36 * 2) & 127;
    int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_96) & 63;
    acc ^= aux;
    int cursor_23 = (aux + st.buffer[1]) & 3;
    switch (cursor_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000607_713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int delta_35 = local_arr[aux % 3];
    acc = (acc + delta_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_38 = (aux + st.buffer[1]) & 3;
    switch (weight_38) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000607_713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000607_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_95 > 33) {
        acc = (acc + quantum_95 * 2 + 5) & 127;
        aux ^= (quantum_95 & 15);
    } else {
        acc = (acc - quantum_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_50 = local_arr[aux % 3];
    acc = (acc + offset_50 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000607_0;
    int sec_r000607_1;
    int sec_r000607_2;
    int sec_r000607_3;
    int sec_r000607_4;
    int sec_r000607_5;
    int sec_r000607_6;
    int sec_r000607_7;
    int sec_r000607_8;
    int sec_r000607_9;
    int sec_r000607_10;
    int sec_r000607_11;
    int sec_r000607_12;
    int sec_r000607_13;
    int sec_r000607_14;
    int sec_r000607_15;
    int sec_r000607_16;
    int sec_r000607_17;
    int sec_r000607_18;
    int pub_r000607_0;
    int pub_r000607_1;
    int pub_r000607_2;
    int pub_r000607_3;
    int pub_r000607_4;
    int pub_r000607_5;
    int pub_r000607_6;
    int pub_r000607_7;
    int pub_r000607_8;
    int pub_r000607_9;
    int pub_r000607_10;
    int pub_r000607_11;
    int pub_r000607_12;
    int pub_r000607_13;
    int pub_r000607_14;
    int pub_r000607_15;
    int pub_r000607_16;
    int pub_r000607_17;
    int pub_r000607_18;
    int pub_r000607_19;
    int pub_r000607_20;
    int pub_r000607_21;
    int pub_r000607_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000607_0 >= -100 && pub_r000607_0 <= 100);
    __CPROVER_assume(pub_r000607_1 >= -100 && pub_r000607_1 <= 100);
    __CPROVER_assume(pub_r000607_2 >= -100 && pub_r000607_2 <= 100);
    __CPROVER_assume(pub_r000607_3 >= -100 && pub_r000607_3 <= 100);
    __CPROVER_assume(pub_r000607_4 >= -100 && pub_r000607_4 <= 100);
    __CPROVER_assume(pub_r000607_5 >= -100 && pub_r000607_5 <= 100);
    __CPROVER_assume(pub_r000607_6 >= -100 && pub_r000607_6 <= 100);
    __CPROVER_assume(pub_r000607_7 >= -100 && pub_r000607_7 <= 100);
    __CPROVER_assume(pub_r000607_8 >= -100 && pub_r000607_8 <= 100);
    __CPROVER_assume(pub_r000607_9 >= -100 && pub_r000607_9 <= 100);
    __CPROVER_assume(pub_r000607_10 >= -100 && pub_r000607_10 <= 100);
    __CPROVER_assume(pub_r000607_11 >= -100 && pub_r000607_11 <= 100);
    __CPROVER_assume(pub_r000607_12 >= -100 && pub_r000607_12 <= 100);
    __CPROVER_assume(pub_r000607_13 >= -100 && pub_r000607_13 <= 100);
    __CPROVER_assume(pub_r000607_14 >= -100 && pub_r000607_14 <= 100);
    __CPROVER_assume(pub_r000607_15 >= -100 && pub_r000607_15 <= 100);
    __CPROVER_assume(pub_r000607_16 >= -100 && pub_r000607_16 <= 100);
    __CPROVER_assume(pub_r000607_17 >= -100 && pub_r000607_17 <= 100);
    __CPROVER_assume(pub_r000607_18 >= -100 && pub_r000607_18 <= 100);
    __CPROVER_assume(pub_r000607_19 >= -100 && pub_r000607_19 <= 100);
    __CPROVER_assume(pub_r000607_20 >= -100 && pub_r000607_20 <= 100);
    __CPROVER_assume(pub_r000607_21 >= -100 && pub_r000607_21 <= 100);
    __CPROVER_assume(pub_r000607_22 >= -100 && pub_r000607_22 <= 100);
    __CPROVER_assume(sec_r000607_0 >= 0 && sec_r000607_0 <= 255);
    __CPROVER_assume(sec_r000607_1 >= 0 && sec_r000607_1 <= 255);
    __CPROVER_assume(sec_r000607_2 >= 0 && sec_r000607_2 <= 255);
    __CPROVER_assume(sec_r000607_3 >= 0 && sec_r000607_3 <= 255);
    __CPROVER_assume(sec_r000607_4 >= 0 && sec_r000607_4 <= 255);
    __CPROVER_assume(sec_r000607_5 >= 0 && sec_r000607_5 <= 255);
    __CPROVER_assume(sec_r000607_6 >= 0 && sec_r000607_6 <= 255);
    __CPROVER_assume(sec_r000607_7 >= 0 && sec_r000607_7 <= 255);
    __CPROVER_assume(sec_r000607_8 >= 0 && sec_r000607_8 <= 255);
    __CPROVER_assume(sec_r000607_9 >= 0 && sec_r000607_9 <= 255);
    __CPROVER_assume(sec_r000607_10 >= 0 && sec_r000607_10 <= 255);
    __CPROVER_assume(sec_r000607_11 >= 0 && sec_r000607_11 <= 255);
    __CPROVER_assume(sec_r000607_12 >= 0 && sec_r000607_12 <= 255);
    __CPROVER_assume(sec_r000607_13 >= 0 && sec_r000607_13 <= 255);
    __CPROVER_assume(sec_r000607_14 >= 0 && sec_r000607_14 <= 255);
    __CPROVER_assume(sec_r000607_15 >= 0 && sec_r000607_15 <= 255);
    __CPROVER_assume(sec_r000607_16 >= 0 && sec_r000607_16 <= 255);
    __CPROVER_assume(sec_r000607_17 >= 0 && sec_r000607_17 <= 255);
    __CPROVER_assume(sec_r000607_18 >= 0 && sec_r000607_18 <= 255);

    struct AudioFrame_R000607_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000607_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000607_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000607_0 + 7) & 15;
    struct MatrixBlock_R000607_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000607_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000607_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000607_0 + 9) & 15;
    struct EventLog_R000607_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000607_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000607_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000607_0 + 11) & 15;

    union ColorPixel_R000607_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 39) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 54) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 14) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 29) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 37) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 52) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 39) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 54) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 20) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 35) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 12) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 27) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000607_18 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_64 = (pub_r000607_16 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000607_16 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000607_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_65 = (pub_r000607_20 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000607_20 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000607_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000607_14 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_66 = (pub_r000607_1 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000607_1 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000607_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000607_13 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_67 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000607_3 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_68 = (pub_r000607_3 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000607_3 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000607_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000607_0 & 2) != 0) {
            stage_v_69 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_70 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_71 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_72 = (pub_r000607_5 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000607_5 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000607_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_73 = (pub_r000607_19 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000607_19 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000607_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000607_9 & 1) != 0) {
        if ((sec_r000607_5 & 2) != 0) {
            stage_v_74 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000607_7 & 2) != 0) {
            stage_v_75 = (pub_r000607_20 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000607_20 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000607_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000607_2 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_76 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000607_5 & 2) != 0) {
            stage_v_77 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000607_6 & 2) != 0) {
            stage_v_78 = (pub_r000607_17 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000607_17 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000607_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_79 = (pub_r000607_19 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000607_19 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000607_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_80 = (pub_r000607_2 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000607_2 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000607_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_81 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_82 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000607_4 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_83 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000607_8 & 2) != 0) {
            stage_v_84 = (pub_r000607_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000607_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000607_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_85 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_86 = (pub_r000607_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000607_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000607_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_87 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_88 = (pub_r000607_12 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000607_12 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000607_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000607_13 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_89 = (pub_r000607_6 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000607_6 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000607_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000607_0 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_90 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_91 = (pub_r000607_8 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000607_8 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000607_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000607_12 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_92 = (pub_r000607_12 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000607_12 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000607_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_93 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_94 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000607_14 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_95 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000607_0 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_96 = (pub_r000607_2 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000607_2 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000607_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_97 = (pub_r000607_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000607_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000607_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000607_18 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_98 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000607_17 & 1) != 0) {
        if ((sec_r000607_6 & 2) != 0) {
            stage_v_99 = (pub_r000607_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000607_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000607_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000607_16 & 1) != 0) {
        if ((sec_r000607_5 & 2) != 0) {
            stage_v_100 = (pub_r000607_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000607_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000607_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000607_15 & 2) != 0) {
            stage_v_101 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000607_7 & 2) != 0) {
            stage_v_102 = (pub_r000607_8 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000607_8 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000607_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000607_13 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_103 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000607_14 & 2) != 0) {
            stage_v_104 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000607_15 & 2) != 0) {
            stage_v_105 = (pub_r000607_14 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000607_14 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000607_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000607_4 & 2) != 0) {
            stage_v_106 = (pub_r000607_16 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000607_16 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000607_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_107 = (pub_r000607_13 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000607_13 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000607_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_108 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000607_12 & 1) != 0) {
        if ((sec_r000607_6 & 2) != 0) {
            stage_v_109 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000607_8 & 2) != 0) {
            stage_v_110 = (pub_r000607_8 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000607_8 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000607_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000607_16 & 1) != 0) {
        if ((sec_r000607_0 & 2) != 0) {
            stage_v_111 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000607_14 & 2) != 0) {
            stage_v_112 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_113 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_114 = (pub_r000607_13 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000607_13 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000607_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000607_2 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_115 = (pub_r000607_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000607_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000607_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_116 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_117 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000607_5 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_118 = (pub_r000607_21 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000607_21 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000607_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000607_16 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_119 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_120 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_121 = (pub_r000607_1 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000607_1 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000607_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000607_14 & 2) != 0) {
            stage_v_122 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000607_17 & 1) != 0) {
        if ((sec_r000607_6 & 2) != 0) {
            stage_v_123 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000607_5 & 2) != 0) {
            stage_v_124 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_125 = (pub_r000607_12 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000607_12 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000607_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_126 = (pub_r000607_17 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000607_17 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000607_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_127 = (pub_r000607_1 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000607_1 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000607_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_128 = (pub_r000607_20 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000607_20 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000607_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000607_9 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_129 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000607_7 & 2) != 0) {
            stage_v_130 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_131 = (pub_r000607_2 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000607_2 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000607_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_132 = (pub_r000607_19 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000607_19 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000607_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_133 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_134 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000607_8 & 2) != 0) {
            stage_v_135 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_136 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_137 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000607_11 & 1) != 0) {
        if ((sec_r000607_15 & 2) != 0) {
            stage_v_138 = (pub_r000607_18 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000607_18 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000607_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_139 = (pub_r000607_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000607_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000607_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_140 = (pub_r000607_12 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000607_12 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000607_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000607_13 & 1) != 0) {
        if ((sec_r000607_15 & 2) != 0) {
            stage_v_141 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000607_5 & 2) != 0) {
            stage_v_142 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000607_14 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_143 = (pub_r000607_8 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000607_8 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000607_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000607_2 & 1) != 0) {
        if ((sec_r000607_6 & 2) != 0) {
            stage_v_144 = (pub_r000607_3 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000607_3 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000607_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_145 = (pub_r000607_5 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000607_5 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000607_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_146 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000607_7 & 2) != 0) {
            stage_v_147 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000607_11 & 2) != 0) {
            stage_v_148 = (pub_r000607_3 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000607_3 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000607_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000607_11 & 1) != 0) {
        if ((sec_r000607_16 & 2) != 0) {
            stage_v_149 = (pub_r000607_6 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000607_6 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000607_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000607_1 & 1) != 0) {
        if ((sec_r000607_7 & 2) != 0) {
            stage_v_150 = (pub_r000607_20 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000607_20 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000607_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000607_5 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_151 = (pub_r000607_1 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000607_1 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000607_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000607_4 & 2) != 0) {
            stage_v_152 = (pub_r000607_15 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000607_15 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000607_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000607_3 & 1) != 0) {
        if ((sec_r000607_13 & 2) != 0) {
            stage_v_153 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_154 = (pub_r000607_6 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000607_6 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000607_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000607_17 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_155 = (pub_r000607_8 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000607_8 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000607_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r000607_9 & 2) != 0) {
            stage_v_156 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000607_12 & 2) != 0) {
            stage_v_157 = (pub_r000607_14 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000607_14 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000607_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000607_10 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_158 = (pub_r000607_22 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000607_22 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000607_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_159 = (pub_r000607_13 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000607_13 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000607_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000607_2 & 2) != 0) {
            stage_v_160 = (pub_r000607_1 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000607_1 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000607_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000607_14 & 2) != 0) {
            stage_v_161 = (pub_r000607_4 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000607_4 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000607_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000607_10 & 2) != 0) {
            stage_v_162 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000607_0 & 2) != 0) {
            stage_v_163 = (pub_r000607_2 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000607_2 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000607_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_164 = (pub_r000607_7 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000607_7 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000607_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000607_17 & 2) != 0) {
            stage_v_165 = (pub_r000607_11 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000607_11 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000607_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_166 = (pub_r000607_9 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000607_9 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000607_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_167 = (pub_r000607_14 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000607_14 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000607_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_168 = (pub_r000607_17 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000607_17 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000607_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((sec_r000607_15 & 1) != 0) {
        if ((sec_r000607_18 & 2) != 0) {
            stage_v_169 = (pub_r000607_0 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000607_0 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000607_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000607_3 & 2) != 0) {
            stage_v_170 = (pub_r000607_18 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000607_18 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000607_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((sec_r000607_11 & 1) != 0) {
        if ((sec_r000607_1 & 2) != 0) {
            stage_v_171 = (pub_r000607_12 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000607_12 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000607_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
