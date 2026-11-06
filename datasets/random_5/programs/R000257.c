/*
 * Benchmark Program: R000257
 * Security Family: nested_implicit_flow
 * Generator Seed: 525713
 * High Inputs: 17 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000257_5713_0 {
    short scale;
    short stride;
    short trace;
    int buffer[3];
};

struct EventLog_R000257_5713_1 {
    unsigned char timestamp;
    int seq;
    int code;
    int buffer[3];
};

struct Transaction_R000257_5713_2 {
    int status;
    short account_id;
    short balance;
    int fee;
    unsigned char auth_code;
    int buffer[3];
};

struct StreamBuffer_R000257_5713_3 {
    int state;
    int tail;
    int head;
    unsigned char checksum;
    unsigned char capacity;
    int buffer[3];
};

union PacketPayload_R000257_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000257_5713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_14 = (aux + st.buffer[1]) & 3;
    switch (stride_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_83 = local_arr[aux % 3];
    acc = (acc + pivot_83 * 2) & 127;
    int phase_16 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_16 > 40) {
        acc = (acc + phase_16 * 2 + 5) & 127;
        aux ^= (phase_16 & 15);
    } else {
        acc = (acc - phase_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000257_5713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int index_reg_77 = (aux + st.buffer[1]) & 3;
    switch (index_reg_77) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_60) & 63;
    acc ^= aux;
    int quotient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_78 > 38) {
        acc = (acc + quotient_78 * 2 + 5) & 127;
        aux ^= (quotient_78 & 15);
    } else {
        acc = (acc - quotient_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_33 = local_arr[aux % 3];
    acc = (acc + index_reg_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_2(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_51 = (aux + st.buffer[1]) & 3;
    switch (phase_51) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_14 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_14 > 10) {
        acc = (acc + tally_14 * 2 + 5) & 127;
        aux ^= (tally_14 & 15);
    } else {
        acc = (acc - tally_14 + 11) & 127;
        aux += 3;
    }
    int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_63 = local_arr[aux % 3];
    acc = (acc + parity_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int weight_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_63) & 63;
    acc ^= aux;
    int cursor_69 = (aux + st.buffer[1]) & 3;
    switch (cursor_69) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_52 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_52 > 17) {
        acc = (acc + phase_52 * 2 + 5) & 127;
        aux ^= (phase_52 & 15);
    } else {
        acc = (acc - phase_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_45 = local_arr[aux % 3];
    acc = (acc + index_reg_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_4(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_87) & 63;
    acc ^= aux;
    int quantum_31 = (aux + st.buffer[1]) & 3;
    switch (quantum_31) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int window_48 = local_arr[aux % 3];
    acc = (acc + window_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_45 = (aux + st.buffer[1]) & 3;
    switch (delta_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_6(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int quotient_79 = local_arr[aux % 3];
    acc = (acc + quotient_79 * 2) & 127;
    int tracker_90 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_90 > 45) {
        acc = (acc + tracker_90 * 2 + 5) & 127;
        aux ^= (tracker_90 & 15);
    } else {
        acc = (acc - tracker_90 + 11) & 127;
        aux += 3;
    }
    int bound_33 = (aux + st.buffer[1]) & 3;
    switch (bound_33) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int mask_33 = local_arr[aux % 3];
    acc = (acc + mask_33 * 2) & 127;
    int segment_43 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_43 > 14) {
        acc = (acc + segment_43 * 2 + 5) & 127;
        aux ^= (segment_43 & 15);
    } else {
        acc = (acc - segment_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_8(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000257_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int phase_74 = (aux + st.buffer[1]) & 3;
    switch (phase_74) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_50 = local_arr[aux % 3];
    acc = (acc + parity_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_9(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000257_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_91 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_91 > 24) {
        acc = (acc + sample_91 * 2 + 5) & 127;
        aux ^= (sample_91 & 15);
    } else {
        acc = (acc - sample_91 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_43 = (aux + st.buffer[1]) & 3;
    switch (sample_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_10(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_31 = local_arr[aux % 3];
    acc = (acc + stride_31 * 2) & 127;
    int mask_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_30) & 63;
    acc ^= aux;
    int metric_32 = (aux + st.buffer[1]) & 3;
    switch (metric_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000257_5713_11(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int metric_77 = local_arr[aux % 3];
    acc = (acc + metric_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int pivot_28 = (aux + st.buffer[1]) & 3;
    switch (pivot_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_46 = local_arr[aux % 3];
    acc = (acc + accumulator_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_13(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_18 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_18 > 39) {
        acc = (acc + segment_18 * 2 + 5) & 127;
        aux ^= (segment_18 & 15);
    } else {
        acc = (acc - segment_18 + 11) & 127;
        aux += 3;
    }
    int mask_70 = (aux + st.buffer[1]) & 3;
    switch (mask_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_76 = local_arr[aux % 3];
    acc = (acc + threshold_76 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_14(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_32 = (aux + st.buffer[1]) & 3;
    switch (metric_32) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_47 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_47 > 25) {
        acc = (acc + metric_47 * 2 + 5) & 127;
        aux ^= (metric_47 & 15);
    } else {
        acc = (acc - metric_47 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_53 = local_arr[aux % 3];
    acc = (acc + mask_53 * 2) & 127;
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_43 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_43 > 31) {
        acc = (acc + margin_43 * 2 + 5) & 127;
        aux ^= (margin_43 & 15);
    } else {
        acc = (acc - margin_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_40 = local_arr[aux % 3];
    acc = (acc + residue_40 * 2) & 127;
    int parity_87 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_87 > 30) {
        acc = (acc + parity_87 * 2 + 5) & 127;
        aux ^= (parity_87 & 15);
    } else {
        acc = (acc - parity_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000257_5713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000257_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_38 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_38 > 43) {
        acc = (acc + scale_38 * 2 + 5) & 127;
        aux ^= (scale_38 & 15);
    } else {
        acc = (acc - scale_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_27 = local_arr[aux % 3];
    acc = (acc + segment_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000257_5713_18(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000257_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_29 = local_arr[aux % 3];
    acc = (acc + metric_29 * 2) & 127;
    int pivot_52 = (aux + st.buffer[1]) & 3;
    switch (pivot_52) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000257_5713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000257_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_32 = (aux + st.buffer[1]) & 3;
    switch (damping_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_79 = local_arr[aux % 3];
    acc = (acc + anchor_79 * 2) & 127;
    int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000257_5713_20(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000257_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_95 = local_arr[aux % 3];
    acc = (acc + phase_95 * 2) & 127;
    int residue_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_89) & 63;
    acc ^= aux;
    int checksum_97 = (aux + st.buffer[1]) & 3;
    switch (checksum_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000257_0;
    int sec_r000257_1;
    int sec_r000257_2;
    int sec_r000257_3;
    int sec_r000257_4;
    int sec_r000257_5;
    int sec_r000257_6;
    int sec_r000257_7;
    int sec_r000257_8;
    int sec_r000257_9;
    int sec_r000257_10;
    int sec_r000257_11;
    int sec_r000257_12;
    int sec_r000257_13;
    int sec_r000257_14;
    int sec_r000257_15;
    int sec_r000257_16;
    int pub_r000257_0;
    int pub_r000257_1;
    int pub_r000257_2;
    int pub_r000257_3;
    int pub_r000257_4;
    int pub_r000257_5;
    int pub_r000257_6;
    int pub_r000257_7;
    int pub_r000257_8;
    int pub_r000257_9;
    int pub_r000257_10;
    int pub_r000257_11;
    int pub_r000257_12;
    int pub_r000257_13;
    int pub_r000257_14;
    int pub_r000257_15;
    int pub_r000257_16;
    int pub_r000257_17;
    int pub_r000257_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000257_0 >= -100 && pub_r000257_0 <= 100);
    __CPROVER_assume(pub_r000257_1 >= -100 && pub_r000257_1 <= 100);
    __CPROVER_assume(pub_r000257_2 >= -100 && pub_r000257_2 <= 100);
    __CPROVER_assume(pub_r000257_3 >= -100 && pub_r000257_3 <= 100);
    __CPROVER_assume(pub_r000257_4 >= -100 && pub_r000257_4 <= 100);
    __CPROVER_assume(pub_r000257_5 >= -100 && pub_r000257_5 <= 100);
    __CPROVER_assume(pub_r000257_6 >= -100 && pub_r000257_6 <= 100);
    __CPROVER_assume(pub_r000257_7 >= -100 && pub_r000257_7 <= 100);
    __CPROVER_assume(pub_r000257_8 >= -100 && pub_r000257_8 <= 100);
    __CPROVER_assume(pub_r000257_9 >= -100 && pub_r000257_9 <= 100);
    __CPROVER_assume(pub_r000257_10 >= -100 && pub_r000257_10 <= 100);
    __CPROVER_assume(pub_r000257_11 >= -100 && pub_r000257_11 <= 100);
    __CPROVER_assume(pub_r000257_12 >= -100 && pub_r000257_12 <= 100);
    __CPROVER_assume(pub_r000257_13 >= -100 && pub_r000257_13 <= 100);
    __CPROVER_assume(pub_r000257_14 >= -100 && pub_r000257_14 <= 100);
    __CPROVER_assume(pub_r000257_15 >= -100 && pub_r000257_15 <= 100);
    __CPROVER_assume(pub_r000257_16 >= -100 && pub_r000257_16 <= 100);
    __CPROVER_assume(pub_r000257_17 >= -100 && pub_r000257_17 <= 100);
    __CPROVER_assume(pub_r000257_18 >= -100 && pub_r000257_18 <= 100);
    __CPROVER_assume(sec_r000257_0 >= 0 && sec_r000257_0 <= 255);
    __CPROVER_assume(sec_r000257_1 >= 0 && sec_r000257_1 <= 255);
    __CPROVER_assume(sec_r000257_2 >= 0 && sec_r000257_2 <= 255);
    __CPROVER_assume(sec_r000257_3 >= 0 && sec_r000257_3 <= 255);
    __CPROVER_assume(sec_r000257_4 >= 0 && sec_r000257_4 <= 255);
    __CPROVER_assume(sec_r000257_5 >= 0 && sec_r000257_5 <= 255);
    __CPROVER_assume(sec_r000257_6 >= 0 && sec_r000257_6 <= 255);
    __CPROVER_assume(sec_r000257_7 >= 0 && sec_r000257_7 <= 255);
    __CPROVER_assume(sec_r000257_8 >= 0 && sec_r000257_8 <= 255);
    __CPROVER_assume(sec_r000257_9 >= 0 && sec_r000257_9 <= 255);
    __CPROVER_assume(sec_r000257_10 >= 0 && sec_r000257_10 <= 255);
    __CPROVER_assume(sec_r000257_11 >= 0 && sec_r000257_11 <= 255);
    __CPROVER_assume(sec_r000257_12 >= 0 && sec_r000257_12 <= 255);
    __CPROVER_assume(sec_r000257_13 >= 0 && sec_r000257_13 <= 255);
    __CPROVER_assume(sec_r000257_14 >= 0 && sec_r000257_14 <= 255);
    __CPROVER_assume(sec_r000257_15 >= 0 && sec_r000257_15 <= 255);
    __CPROVER_assume(sec_r000257_16 >= 0 && sec_r000257_16 <= 255);

    struct MatrixBlock_R000257_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000257_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000257_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000257_0 + 7) & 15;
    struct EventLog_R000257_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000257_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000257_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000257_0 + 9) & 15;
    struct Transaction_R000257_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000257_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000257_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000257_0 + 11) & 15;
    struct StreamBuffer_R000257_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000257_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000257_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000257_0 + 13) & 15;

    union PacketPayload_R000257_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 15) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 30) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
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
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 22) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 37) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 24) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 39) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
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
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 37) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 52) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 14) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 29) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 47) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 34) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 49) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 21) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 36) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 17) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 32) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 16) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 31) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 16) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 31) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000257_6 & 1) != 0) {
        if ((sec_r000257_12 & 2) != 0) {
            stage_v_89 = (pub_r000257_2 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000257_2 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000257_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_5 & 2) != 0) {
            stage_v_90 = (pub_r000257_1 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000257_1 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000257_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_2 & 2) != 0) {
            stage_v_91 = (pub_r000257_16 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000257_16 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000257_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000257_9 & 2) != 0) {
            stage_v_92 = (pub_r000257_11 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000257_11 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000257_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000257_15 & 1) != 0) {
        if ((sec_r000257_0 & 2) != 0) {
            stage_v_93 = (pub_r000257_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000257_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000257_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000257_9 & 1) != 0) {
        if ((sec_r000257_7 & 2) != 0) {
            stage_v_94 = (pub_r000257_16 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000257_16 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000257_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_6 & 2) != 0) {
            stage_v_95 = (pub_r000257_18 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000257_18 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000257_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_96 = (pub_r000257_2 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000257_2 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000257_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000257_3 & 2) != 0) {
            stage_v_97 = (pub_r000257_10 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000257_10 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000257_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000257_4 & 1) != 0) {
        if ((sec_r000257_10 & 2) != 0) {
            stage_v_98 = (pub_r000257_16 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000257_16 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000257_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000257_4 & 1) != 0) {
        if ((sec_r000257_9 & 2) != 0) {
            stage_v_99 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000257_14 & 2) != 0) {
            stage_v_100 = (pub_r000257_13 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000257_13 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000257_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000257_1 & 2) != 0) {
            stage_v_101 = (pub_r000257_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000257_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000257_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000257_4 & 1) != 0) {
        if ((sec_r000257_3 & 2) != 0) {
            stage_v_102 = (pub_r000257_2 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000257_2 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000257_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000257_9 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_103 = (pub_r000257_7 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000257_7 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000257_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000257_13 & 2) != 0) {
            stage_v_104 = (pub_r000257_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000257_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000257_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_105 = (pub_r000257_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000257_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000257_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000257_1 & 1) != 0) {
        if ((sec_r000257_13 & 2) != 0) {
            stage_v_106 = (pub_r000257_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000257_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000257_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000257_13 & 1) != 0) {
        if ((sec_r000257_10 & 2) != 0) {
            stage_v_107 = (pub_r000257_16 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000257_16 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000257_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_10 & 2) != 0) {
            stage_v_108 = (pub_r000257_12 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000257_12 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000257_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000257_9 & 2) != 0) {
            stage_v_109 = (pub_r000257_4 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000257_4 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000257_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000257_15 & 1) != 0) {
        if ((sec_r000257_11 & 2) != 0) {
            stage_v_110 = (pub_r000257_16 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000257_16 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000257_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000257_6 & 2) != 0) {
            stage_v_111 = (pub_r000257_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000257_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000257_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000257_5 & 2) != 0) {
            stage_v_112 = (pub_r000257_11 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000257_11 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000257_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000257_15 & 1) != 0) {
        if ((sec_r000257_6 & 2) != 0) {
            stage_v_113 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000257_4 & 2) != 0) {
            stage_v_114 = (pub_r000257_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000257_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000257_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000257_10 & 2) != 0) {
            stage_v_115 = (pub_r000257_3 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000257_3 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000257_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000257_9 & 2) != 0) {
            stage_v_116 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000257_11 & 2) != 0) {
            stage_v_117 = (pub_r000257_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000257_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000257_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_118 = (pub_r000257_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000257_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000257_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000257_16 & 1) != 0) {
        if ((sec_r000257_14 & 2) != 0) {
            stage_v_119 = (pub_r000257_10 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000257_10 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000257_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000257_12 & 2) != 0) {
            stage_v_120 = (pub_r000257_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000257_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000257_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000257_15 & 2) != 0) {
            stage_v_121 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000257_4 & 2) != 0) {
            stage_v_122 = (pub_r000257_17 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000257_17 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000257_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_4 & 2) != 0) {
            stage_v_123 = (pub_r000257_8 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000257_8 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000257_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000257_14 & 2) != 0) {
            stage_v_124 = (pub_r000257_9 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000257_9 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000257_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000257_11 & 1) != 0) {
        if ((sec_r000257_9 & 2) != 0) {
            stage_v_125 = (pub_r000257_15 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000257_15 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000257_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000257_3 & 2) != 0) {
            stage_v_126 = (pub_r000257_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000257_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000257_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000257_14 & 2) != 0) {
            stage_v_127 = (pub_r000257_17 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000257_17 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000257_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000257_9 & 1) != 0) {
        if ((sec_r000257_13 & 2) != 0) {
            stage_v_128 = (pub_r000257_2 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000257_2 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000257_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000257_3 & 2) != 0) {
            stage_v_129 = (pub_r000257_14 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000257_14 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000257_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000257_7 & 2) != 0) {
            stage_v_130 = (pub_r000257_11 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000257_11 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000257_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000257_3 & 1) != 0) {
        if ((sec_r000257_1 & 2) != 0) {
            stage_v_131 = (pub_r000257_7 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000257_7 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000257_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000257_9 & 1) != 0) {
        if ((sec_r000257_0 & 2) != 0) {
            stage_v_132 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_133 = (pub_r000257_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000257_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000257_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000257_1 & 2) != 0) {
            stage_v_134 = (pub_r000257_9 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000257_9 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000257_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000257_0 & 1) != 0) {
        if ((sec_r000257_4 & 2) != 0) {
            stage_v_135 = (pub_r000257_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000257_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000257_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000257_0 & 1) != 0) {
        if ((sec_r000257_8 & 2) != 0) {
            stage_v_136 = (pub_r000257_1 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000257_1 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000257_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
