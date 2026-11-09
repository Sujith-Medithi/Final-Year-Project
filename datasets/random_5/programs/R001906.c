/*
 * Benchmark Program: R001906
 * Security Family: implicit_flow
 * Generator Seed: 690613
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001906_613_0 {
    int prev_in;
    unsigned char damping;
    int mode;
    int cutoff;
    int buffer[3];
};

struct MatrixBlock_R001906_613_1 {
    int determinant;
    int trace;
    int stride;
    int density;
    int buffer[3];
};

struct EventLog_R001906_613_2 {
    unsigned char facility;
    int code;
    int severity;
    int buffer[3];
};

struct AudioFrame_R001906_613_3 {
    int peak;
    unsigned char rms;
    int gain;
    int sample_rate;
    int buffer[3];
};

union PacketPayload_R001906_613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001906_613_0(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_99 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_99 > 48) {
        acc = (acc + bound_99 * 2 + 5) & 127;
        aux ^= (bound_99 & 15);
    } else {
        acc = (acc - bound_99 + 11) & 127;
        aux += 3;
    }
    int segment_71 = (aux + st.buffer[1]) & 3;
    switch (segment_71) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001906_613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_54 = 0;
    for (int k = 0; k < 3; k++) {
        margin_54 = (margin_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_54) & 127;
    }
    int bound_47 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_47 > 25) {
        acc = (acc + bound_47 * 2 + 5) & 127;
        aux ^= (bound_47 & 15);
    } else {
        acc = (acc - bound_47 + 11) & 127;
        aux += 3;
    }
    int offset_37 = (aux + st.buffer[1]) & 3;
    switch (offset_37) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001906_613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int parity_74 = local_arr[aux % 3];
    acc = (acc + parity_74 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_72 = 0;
    for (int k = 0; k < 2; k++) {
        weight_72 = (weight_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001906_613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_24 = (aux + st.buffer[1]) & 3;
    switch (segment_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_36 = local_arr[aux % 3];
    acc = (acc + pivot_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001906_613_4(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_95 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_95 > 27) {
        acc = (acc + delta_95 * 2 + 5) & 127;
        aux ^= (delta_95 & 15);
    } else {
        acc = (acc - delta_95 + 11) & 127;
        aux += 3;
    }
    int index_reg_87 = (aux + st.buffer[1]) & 3;
    switch (index_reg_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_26 = 0;
    for (int k = 0; k < 3; k++) {
        factor_26 = (factor_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_5(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001906_613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_74 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_74 > 38) {
        acc = (acc + tracker_74 * 2 + 5) & 127;
        aux ^= (tracker_74 & 15);
    } else {
        acc = (acc - tracker_74 + 11) & 127;
        aux += 3;
    }
    int damping_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001906_613_6(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int segment_53 = local_arr[aux % 3];
    acc = (acc + segment_53 * 2) & 127;
    int damping_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_58) & 63;
    acc ^= aux;
    int quotient_83 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_83 = (quotient_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001906_613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_16 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_16 > 43) {
        acc = (acc + metric_16 * 2 + 5) & 127;
        aux ^= (metric_16 & 15);
    } else {
        acc = (acc - metric_16 + 11) & 127;
        aux += 3;
    }
    int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_88) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_79 = local_arr[aux % 3];
    acc = (acc + bound_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001906_613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tracker_83 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_83 > 17) {
        acc = (acc + tracker_83 * 2 + 5) & 127;
        aux ^= (tracker_83 & 15);
    } else {
        acc = (acc - tracker_83 + 11) & 127;
        aux += 3;
    }
    int phase_63 = 0;
    for (int k = 0; k < 3; k++) {
        phase_63 = (phase_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001906_613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_97 = (aux + st.buffer[1]) & 3;
    switch (bound_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_59 = local_arr[aux % 3];
    acc = (acc + tracker_59 * 2) & 127;
    int segment_83 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_83 > 20) {
        acc = (acc + segment_83 * 2 + 5) & 127;
        aux ^= (segment_83 & 15);
    } else {
        acc = (acc - segment_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001906_613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001906_613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_37 = local_arr[aux % 3];
    acc = (acc + index_reg_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001906_613_11(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001906_613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_69 = local_arr[aux % 3];
    acc = (acc + cursor_69 * 2) & 127;
    int checksum_16 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_16 > 22) {
        acc = (acc + checksum_16 * 2 + 5) & 127;
        aux ^= (checksum_16 & 15);
    } else {
        acc = (acc - checksum_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_12(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001906_613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001906_613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001906_613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int accumulator_59 = local_arr[aux % 3];
    acc = (acc + accumulator_59 * 2) & 127;
    int factor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001906_613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_50 = 0;
    for (int k = 0; k < 3; k++) {
        factor_50 = (factor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_50) & 127;
    }
    int sample_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_54) & 63;
    acc ^= aux;
    int tally_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_11 > 41) {
        acc = (acc + tally_11 * 2 + 5) & 127;
        aux ^= (tally_11 & 15);
    } else {
        acc = (acc - tally_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_15(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001906_613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_63 = (aux + st.buffer[1]) & 3;
    switch (anchor_63) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_73 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_73 = (cursor_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_73) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int window_84 = local_arr[aux % 3];
    acc = (acc + window_84 * 2) & 127;
    int scale_68 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_68 > 44) {
        acc = (acc + scale_68 * 2 + 5) & 127;
        aux ^= (scale_68 & 15);
    } else {
        acc = (acc - scale_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001906_613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001906_613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int accumulator_99 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_99 = (accumulator_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_88 = local_arr[aux % 3];
    acc = (acc + window_88 * 2) & 127;
    int residue_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001906_613_17(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001906_613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int scale_58 = 0;
    for (int k = 0; k < 3; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_24 = local_arr[aux % 3];
    acc = (acc + quotient_24 * 2) & 127;
    int sample_43 = (aux + st.buffer[1]) & 3;
    switch (sample_43) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001906_0;
    int sec_r001906_1;
    int sec_r001906_2;
    int sec_r001906_3;
    int sec_r001906_4;
    int sec_r001906_5;
    int sec_r001906_6;
    int sec_r001906_7;
    int sec_r001906_8;
    int sec_r001906_9;
    int sec_r001906_10;
    int sec_r001906_11;
    int sec_r001906_12;
    int sec_r001906_13;
    int sec_r001906_14;
    int sec_r001906_15;
    int sec_r001906_16;
    int sec_r001906_17;
    int sec_r001906_18;
    int sec_r001906_19;
    int sec_r001906_20;
    int pub_r001906_0;
    int pub_r001906_1;
    int pub_r001906_2;
    int pub_r001906_3;
    int pub_r001906_4;
    int pub_r001906_5;
    int pub_r001906_6;
    int pub_r001906_7;
    int pub_r001906_8;
    int pub_r001906_9;
    int pub_r001906_10;
    int pub_r001906_11;
    int pub_r001906_12;
    int pub_r001906_13;
    int pub_r001906_14;
    int pub_r001906_15;
    int pub_r001906_16;
    int pub_r001906_17;
    int pub_r001906_18;
    int pub_r001906_19;
    int pub_r001906_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001906_0 >= -100 && pub_r001906_0 <= 100);
    __CPROVER_assume(pub_r001906_1 >= -100 && pub_r001906_1 <= 100);
    __CPROVER_assume(pub_r001906_2 >= -100 && pub_r001906_2 <= 100);
    __CPROVER_assume(pub_r001906_3 >= -100 && pub_r001906_3 <= 100);
    __CPROVER_assume(pub_r001906_4 >= -100 && pub_r001906_4 <= 100);
    __CPROVER_assume(pub_r001906_5 >= -100 && pub_r001906_5 <= 100);
    __CPROVER_assume(pub_r001906_6 >= -100 && pub_r001906_6 <= 100);
    __CPROVER_assume(pub_r001906_7 >= -100 && pub_r001906_7 <= 100);
    __CPROVER_assume(pub_r001906_8 >= -100 && pub_r001906_8 <= 100);
    __CPROVER_assume(pub_r001906_9 >= -100 && pub_r001906_9 <= 100);
    __CPROVER_assume(pub_r001906_10 >= -100 && pub_r001906_10 <= 100);
    __CPROVER_assume(pub_r001906_11 >= -100 && pub_r001906_11 <= 100);
    __CPROVER_assume(pub_r001906_12 >= -100 && pub_r001906_12 <= 100);
    __CPROVER_assume(pub_r001906_13 >= -100 && pub_r001906_13 <= 100);
    __CPROVER_assume(pub_r001906_14 >= -100 && pub_r001906_14 <= 100);
    __CPROVER_assume(pub_r001906_15 >= -100 && pub_r001906_15 <= 100);
    __CPROVER_assume(pub_r001906_16 >= -100 && pub_r001906_16 <= 100);
    __CPROVER_assume(pub_r001906_17 >= -100 && pub_r001906_17 <= 100);
    __CPROVER_assume(pub_r001906_18 >= -100 && pub_r001906_18 <= 100);
    __CPROVER_assume(pub_r001906_19 >= -100 && pub_r001906_19 <= 100);
    __CPROVER_assume(pub_r001906_20 >= -100 && pub_r001906_20 <= 100);
    __CPROVER_assume(sec_r001906_0 >= 0 && sec_r001906_0 <= 255);
    __CPROVER_assume(sec_r001906_1 >= 0 && sec_r001906_1 <= 255);
    __CPROVER_assume(sec_r001906_2 >= 0 && sec_r001906_2 <= 255);
    __CPROVER_assume(sec_r001906_3 >= 0 && sec_r001906_3 <= 255);
    __CPROVER_assume(sec_r001906_4 >= 0 && sec_r001906_4 <= 255);
    __CPROVER_assume(sec_r001906_5 >= 0 && sec_r001906_5 <= 255);
    __CPROVER_assume(sec_r001906_6 >= 0 && sec_r001906_6 <= 255);
    __CPROVER_assume(sec_r001906_7 >= 0 && sec_r001906_7 <= 255);
    __CPROVER_assume(sec_r001906_8 >= 0 && sec_r001906_8 <= 255);
    __CPROVER_assume(sec_r001906_9 >= 0 && sec_r001906_9 <= 255);
    __CPROVER_assume(sec_r001906_10 >= 0 && sec_r001906_10 <= 255);
    __CPROVER_assume(sec_r001906_11 >= 0 && sec_r001906_11 <= 255);
    __CPROVER_assume(sec_r001906_12 >= 0 && sec_r001906_12 <= 255);
    __CPROVER_assume(sec_r001906_13 >= 0 && sec_r001906_13 <= 255);
    __CPROVER_assume(sec_r001906_14 >= 0 && sec_r001906_14 <= 255);
    __CPROVER_assume(sec_r001906_15 >= 0 && sec_r001906_15 <= 255);
    __CPROVER_assume(sec_r001906_16 >= 0 && sec_r001906_16 <= 255);
    __CPROVER_assume(sec_r001906_17 >= 0 && sec_r001906_17 <= 255);
    __CPROVER_assume(sec_r001906_18 >= 0 && sec_r001906_18 <= 255);
    __CPROVER_assume(sec_r001906_19 >= 0 && sec_r001906_19 <= 255);
    __CPROVER_assume(sec_r001906_20 >= 0 && sec_r001906_20 <= 255);

    struct FilterState_R001906_613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001906_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001906_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001906_0 + 7) & 15;
    struct MatrixBlock_R001906_613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001906_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001906_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001906_0 + 9) & 15;
    struct EventLog_R001906_613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001906_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001906_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001906_0 + 11) & 15;
    struct AudioFrame_R001906_613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001906_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001906_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001906_0 + 13) & 15;

    union PacketPayload_R001906_613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001906_613_0(sec_r001906_0, pub_r001906_1, pub_r001906_2);
    int helper_flow_1 = fn_R001906_613_1(sec_r001906_1, sec_r001906_2, pub_r001906_3, pub_r001906_4, pub_r001906_5);
    int helper_flow_2 = fn_R001906_613_2(sec_r001906_2, pub_r001906_3, pub_r001906_4, pub_r001906_5, pub_r001906_6);
    int helper_flow_3 = fn_R001906_613_3(sec_r001906_3, sec_r001906_4, pub_r001906_5, pub_r001906_6);
    int helper_flow_4 = fn_R001906_613_4(sec_r001906_4, pub_r001906_5);
    int helper_flow_5 = fn_R001906_613_5(sec_r001906_5, sec_r001906_6);
    int helper_flow_6 = fn_R001906_613_6(sec_r001906_6, sec_r001906_7, pub_r001906_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001906_13 + pub_r001906_7 * 2 + 5) & 127;
    if (stage_v_0 > 48) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001906_20 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001906_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_1 + pub_r001906_14 * 2 + 14) & 127;
    if (stage_v_3 > 43) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001906_2 + pub_r001906_6 * 2 + 17) & 127;
    if (stage_v_4 > 28) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001906_18 + pub_r001906_18 * 2 + 20) & 127;
    if (stage_v_5 > 23) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001906_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001906_9 + pub_r001906_12 * 2 + 26) & 127;
    if (stage_v_7 > 29) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001906_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001906_11 + pub_r001906_5 * 2 + 32) & 127;
    if (stage_v_9 > 50) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001906_15 + pub_r001906_7 * 2 + 35) & 127;
    if (stage_v_10 > 37) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_10 + pub_r001906_20 * 2 + 38) & 127;
    if (stage_v_11 > 34) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001906_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_2 + pub_r001906_10 * 2 + 44) & 127;
    if (stage_v_13 > 36) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001906_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_4 + pub_r001906_8 * 2 + 50) & 127;
    if (stage_v_15 > 31) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001906_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_10 + pub_r001906_9 * 2 + 56) & 127;
    if (stage_v_17 > 60) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001906_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_1 + pub_r001906_20 * 2 + 62) & 127;
    if (stage_v_19 > 52) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001906_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_5 + pub_r001906_17 * 2 + 68) & 127;
    if (stage_v_21 > 58) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001906_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001906_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_15 + pub_r001906_14 * 2 + 77) & 127;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001906_9 + pub_r001906_8 * 2 + 80) & 127;
    if (stage_v_25 > 55) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001906_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001906_17 + pub_r001906_10 * 2 + 86) & 127;
    if (stage_v_27 > 57) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_5 + pub_r001906_15 * 2 + 89) & 127;
    if (stage_v_28 > 44) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001906_12 + pub_r001906_10 * 2 + 92) & 127;
    if (stage_v_29 > 16) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_3 + pub_r001906_11 * 2 + 95) & 127;
    if (stage_v_30 > 34) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001906_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_24 + pub_r001906_19 * 2 + 101) & 127;
    if (stage_v_32 > 16) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_25 + pub_r001906_2 * 2 + 104) & 127;
    if (stage_v_33 > 52) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_33 + pub_r001906_16 * 2 + 107) & 127;
    if (stage_v_34 > 42) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001906_10 + pub_r001906_11 * 2 + 110) & 127;
    if (stage_v_35 > 43) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001906_19 + pub_r001906_1 * 2 + 113) & 127;
    if (stage_v_36 > 17) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001906_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_30 + pub_r001906_4 * 2 + 119) & 127;
    if (stage_v_38 > 49) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001906_10 + pub_r001906_2 * 2 + 122) & 127;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001906_18 + pub_r001906_5 * 2 + 125) & 127;
    if (stage_v_40 > 34) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_40 + pub_r001906_8 * 2 + 128) & 127;
    if (stage_v_41 > 37) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001906_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001906_5 + pub_r001906_6 * 2 + 134) & 127;
    if (stage_v_43 > 56) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_5 + pub_r001906_8 * 2 + 137) & 127;
    if (stage_v_44 > 15) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001906_14 + pub_r001906_19 * 2 + 140) & 127;
    if (stage_v_45 > 45) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_40 + pub_r001906_17 * 2 + 143) & 127;
    if (stage_v_46 > 34) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001906_14 + pub_r001906_14 * 2 + 146) & 127;
    if (stage_v_47 > 47) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001906_16 + pub_r001906_5 * 2 + 149) & 127;
    if (stage_v_48 > 45) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001906_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_40 + pub_r001906_0 * 2 + 155) & 127;
    if (stage_v_50 > 54) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_40 + pub_r001906_19 * 2 + 158) & 127;
    if (stage_v_51 > 32) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001906_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_4 + pub_r001906_3 * 2 + 164) & 127;
    if (stage_v_53 > 28) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001906_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001906_10 + pub_r001906_2 * 2 + 170) & 127;
    if (stage_v_55 > 35) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_30 + pub_r001906_1 * 2 + 173) & 127;
    if (stage_v_56 > 39) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001906_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001906_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_28 + pub_r001906_17 * 2 + 182) & 127;
    if (stage_v_59 > 32) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001906_2 + pub_r001906_14 * 2 + 185) & 127;
    if (stage_v_60 > 17) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001906_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001906_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_33 + pub_r001906_9 * 2 + 194) & 127;
    if (stage_v_63 > 23) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_24 + pub_r001906_0 * 2 + 197) & 127;
    if (stage_v_64 > 34) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001906_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001906_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_63 + pub_r001906_9 * 2 + 206) & 127;
    if (stage_v_67 > 28) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_1 + pub_r001906_11 * 2 + 209) & 127;
    if (stage_v_68 > 27) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_47 + pub_r001906_8 * 2 + 212) & 127;
    if (stage_v_69 > 15) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_11 + pub_r001906_3 * 2 + 215) & 127;
    if (stage_v_70 > 31) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001906_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001906_0 + pub_r001906_6 * 2 + 221) & 127;
    if (stage_v_72 > 21) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001906_20 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001906_6 + pub_r001906_14 * 2 + 227) & 127;
    if (stage_v_74 > 48) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001906_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001906_15 + pub_r001906_6 * 2 + 233) & 127;
    if (stage_v_76 > 40) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001906_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001906_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001906_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001906_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001906_4 + pub_r001906_18 * 2 + 248) & 127;
    if (stage_v_81 > 29) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001906_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_40 + pub_r001906_8 * 2 + 254) & 127;
    if (stage_v_83 > 39) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001906_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_17 + pub_r001906_0 * 2 + 260) & 127;
    if (stage_v_85 > 32) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_19 + pub_r001906_13 * 2 + 263) & 127;
    if (stage_v_86 > 49) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_43 + pub_r001906_2 * 2 + 266) & 127;
    if (stage_v_87 > 34) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_10 + pub_r001906_13 * 2 + 269) & 127;
    if (stage_v_88 > 55) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001906_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001906_19 + pub_r001906_6 * 2 + 275) & 127;
    if (stage_v_90 > 17) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_9 + pub_r001906_4 * 2 + 278) & 127;
    if (stage_v_91 > 32) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001906_20 + pub_r001906_20 * 2 + 281) & 127;
    if (stage_v_92 > 30) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001906_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_90 + pub_r001906_4 * 2 + 287) & 127;
    if (stage_v_94 > 42) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_0 + pub_r001906_14 * 2 + 290) & 127;
    if (stage_v_95 > 43) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001906_6 + pub_r001906_7 * 2 + 293) & 127;
    if (stage_v_96 > 31) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001906_17 + pub_r001906_6 * 2 + 296) & 127;
    if (stage_v_97 > 50) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_36 + pub_r001906_2 * 2 + 299) & 127;
    if (stage_v_98 > 33) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001906_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001906_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001906_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001906_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001906_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001906_9 + pub_r001906_16 * 2 + 317) & 127;
    if (stage_v_104 > 33) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001906_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (sec_r001906_18 + pub_r001906_10 * 2 + 323) & 127;
    if (stage_v_106 > 23) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001906_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_15 + pub_r001906_19 * 2 + 329) & 127;
    if (stage_v_108 > 46) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_24 + pub_r001906_16 * 2 + 332) & 127;
    if (stage_v_109 > 44) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001906_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_88 + pub_r001906_12 * 2 + 338) & 127;
    if (stage_v_111 > 18) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_81 + pub_r001906_6 * 2 + 341) & 127;
    if (stage_v_112 > 15) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_88 + pub_r001906_10 * 2 + 344) & 127;
    if (stage_v_113 > 49) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001906_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_13 + pub_r001906_10 * 2 + 350) & 127;
    if (stage_v_115 > 16) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001906_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_4 + pub_r001906_12 * 2 + 356) & 127;
    if (stage_v_117 > 39) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_83 + pub_r001906_14 * 2 + 359) & 127;
    if (stage_v_118 > 36) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001906_3 + pub_r001906_12 * 2 + 362) & 127;
    if (stage_v_119 > 15) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001906_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_98 + pub_r001906_14 * 2 + 368) & 127;
    if (stage_v_121 > 20) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_76 + pub_r001906_1 * 2 + 371) & 127;
    if (stage_v_122 > 44) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (helper_flow_0 + pub_r001906_2 * 2 + 374) & 127;
    if (stage_v_123 > 45) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001906_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_83 + pub_r001906_13 * 2 + 380) & 127;
    if (stage_v_125 > 22) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001906_8 + pub_r001906_2 * 2 + 383) & 127;
    if (stage_v_126 > 23) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001906_20 + pub_r001906_1 * 2 + 386) & 127;
    if (stage_v_127 > 25) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_7 + pub_r001906_15 * 2 + 389) & 127;
    if (stage_v_128 > 24) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001906_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_24 + pub_r001906_17 * 2 + 395) & 127;
    if (stage_v_130 > 24) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_48 + pub_r001906_11 * 2 + 398) & 127;
    if (stage_v_131 > 58) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_121 + pub_r001906_5 * 2 + 401) & 127;
    if (stage_v_132 > 58) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_95 + pub_r001906_17 * 2 + 404) & 127;
    if (stage_v_133 > 60) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001906_1 + pub_r001906_20 * 2 + 407) & 127;
    if (stage_v_134 > 60) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001906_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_40 + pub_r001906_9 * 2 + 413) & 127;
    if (stage_v_136 > 26) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001906_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_51 + pub_r001906_3 * 2 + 419) & 127;
    if (stage_v_138 > 59) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_118 + pub_r001906_6 * 2 + 422) & 127;
    if (stage_v_139 > 55) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001906_13 + pub_r001906_20 * 2 + 425) & 127;
    if (stage_v_140 > 19) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001906_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001906_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001906_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_28 + pub_r001906_18 * 2 + 437) & 127;
    if (stage_v_144 > 17) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_121 + pub_r001906_3 * 2 + 440) & 127;
    if (stage_v_145 > 30) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_4 + pub_r001906_5 * 2 + 443) & 127;
    if (stage_v_146 > 58) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001906_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001906_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001906_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001906_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001906_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (helper_flow_2 + pub_r001906_9 * 2 + 461) & 127;
    if (stage_v_152 > 60) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_63 + pub_r001906_2 * 2 + 464) & 127;
    if (stage_v_153 > 22) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_70 + pub_r001906_2 * 2 + 467) & 127;
    if (stage_v_154 > 48) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001906_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (helper_flow_4 + pub_r001906_10 * 2 + 473) & 127;
    if (stage_v_156 > 26) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_60 + pub_r001906_16 * 2 + 476) & 127;
    if (stage_v_157 > 28) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001906_5 + pub_r001906_8 * 2 + 479) & 127;
    if (stage_v_158 > 41) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_0 + pub_r001906_6 * 2 + 482) & 127;
    if (stage_v_159 > 36) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_3 + pub_r001906_13 * 2 + 485) & 127;
    if (stage_v_160 > 35) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_3 + pub_r001906_13 * 2 + 488) & 127;
    if (stage_v_161 > 15) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_115 + pub_r001906_16 * 2 + 491) & 127;
    if (stage_v_162 > 28) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001906_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001906_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_83 + pub_r001906_9 * 2 + 500) & 127;
    if (stage_v_165 > 29) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_15 + pub_r001906_13 * 2 + 503) & 127;
    if (stage_v_166 > 43) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001906_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_111 + pub_r001906_13 * 2 + 509) & 127;
    if (stage_v_168 > 46) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_56 + pub_r001906_12 * 2 + 512) & 127;
    if (stage_v_169 > 47) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001906_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001906_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001906_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001906_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_125 + pub_r001906_9 * 2 + 527) & 127;
    if (stage_v_174 > 57) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001906_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_53 + pub_r001906_14 * 2 + 533) & 127;
    if (stage_v_176 > 51) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001906_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_130 + pub_r001906_19 * 2 + 539) & 127;
    if (stage_v_178 > 28) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_156 + pub_r001906_18 * 2 + 542) & 127;
    if (stage_v_179 > 35) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_55 + pub_r001906_18 * 2 + 545) & 127;
    if (stage_v_180 > 32) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_132 + pub_r001906_13 * 2 + 548) & 127;
    if (stage_v_181 > 45) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001906_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_27 + pub_r001906_20 * 2 + 554) & 127;
    if (stage_v_183 > 36) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_45 + pub_r001906_14 * 2 + 557) & 127;
    if (stage_v_184 > 30) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001906_13 + pub_r001906_19 * 2 + 560) & 127;
    if (stage_v_185 > 32) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_112 + pub_r001906_15 * 2 + 563) & 127;
    if (stage_v_186 > 41) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_133 + pub_r001906_9 * 2 + 566) & 127;
    if (stage_v_187 > 58) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_125 + pub_r001906_19 * 2 + 569) & 127;
    if (stage_v_188 > 28) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_21 + pub_r001906_0 * 2 + 572) & 127;
    if (stage_v_189 > 37) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_40 + pub_r001906_7 * 2 + 575) & 127;
    if (stage_v_190 > 25) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001906_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_97 + pub_r001906_9 * 2 + 581) & 127;
    if (stage_v_192 > 16) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001906_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_56 + pub_r001906_10 * 2 + 587) & 127;
    if (stage_v_194 > 35) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001906_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_94 + pub_r001906_3 * 2 + 593) & 127;
    if (stage_v_196 > 47) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001906_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_9 + pub_r001906_1 * 2 + 599) & 127;
    if (stage_v_198 > 25) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001906_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r001906_16 + pub_r001906_10 * 2 + 605) & 127;
    if (stage_v_200 > 37) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_91 + pub_r001906_14 * 2 + 608) & 127;
    if (stage_v_201 > 39) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001906_20 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001906_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (helper_flow_4 + pub_r001906_11 * 2 + 617) & 127;
    if (stage_v_204 > 25) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001906_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001906_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001906_19 + pub_r001906_0 * 2 + 626) & 127;
    if (stage_v_207 > 36) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_41 + pub_r001906_2 * 2 + 629) & 127;
    if (stage_v_208 > 20) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_24 + pub_r001906_6 * 2 + 632) & 127;
    if (stage_v_209 > 59) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_7 + pub_r001906_0 * 2 + 635) & 127;
    if (stage_v_210 > 29) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_3 + pub_r001906_17 * 2 + 638) & 127;
    if (stage_v_211 > 15) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_166 + pub_r001906_13 * 2 + 641) & 127;
    if (stage_v_212 > 53) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001906_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
