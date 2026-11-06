/*
 * Benchmark Program: R000980
 * Security Family: mixed_control_data
 * Generator Seed: 598013
 * High Inputs: 21 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000980_8013_0 {
    int stride;
    short dim;
    unsigned char density;
    int determinant;
    int buffer[3];
};

struct EventLog_R000980_8013_1 {
    int timestamp;
    unsigned char seq;
    int severity;
    int signature;
    int code;
    int buffer[3];
};

struct AudioFrame_R000980_8013_2 {
    unsigned char gain;
    int sample_rate;
    short channels;
    int envelope;
    int peak;
    unsigned char rms;
    int buffer[3];
};

union TelemetryField_R000980_8013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000980_8013_0(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000980_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_21 = (aux + st.buffer[1]) & 3;
    switch (bound_21) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000980_8013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000980_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_91) & 63;
    acc ^= aux;
    int scale_10 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_10 > 32) {
        acc = (acc + scale_10 * 2 + 5) & 127;
        aux ^= (scale_10 & 15);
    } else {
        acc = (acc - scale_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_81 = local_arr[aux % 3];
    acc = (acc + cursor_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_60 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_60 > 13) {
        acc = (acc + factor_60 * 2 + 5) & 127;
        aux ^= (factor_60 & 15);
    } else {
        acc = (acc - factor_60 + 11) & 127;
        aux += 3;
    }
    int anchor_60 = (aux + st.buffer[1]) & 3;
    switch (anchor_60) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_57 = local_arr[aux % 3];
    acc = (acc + accumulator_57 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_97) & 63;
    acc ^= aux;
    int phase_51 = (aux + st.buffer[1]) & 3;
    switch (phase_51) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_74 = local_arr[aux % 3];
    acc = (acc + quotient_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_4(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int quantum_77 = local_arr[aux % 3];
    acc = (acc + quantum_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000980_8013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_33 = local_arr[aux % 3];
    acc = (acc + accumulator_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_6(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000980_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000980_8013_7(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_69 = (aux + st.buffer[1]) & 3;
    switch (vector_69) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_31) & 63;
    acc ^= aux;
    int cursor_51 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_51 > 44) {
        acc = (acc + cursor_51 * 2 + 5) & 127;
        aux ^= (cursor_51 & 15);
    } else {
        acc = (acc - cursor_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_25 = local_arr[aux % 3];
    acc = (acc + scale_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_8(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_18) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_34 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_34 > 33) {
        acc = (acc + scale_34 * 2 + 5) & 127;
        aux ^= (scale_34 & 15);
    } else {
        acc = (acc - scale_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000980_8013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_76 = local_arr[aux % 3];
    acc = (acc + metric_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_10(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000980_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_58 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_58 > 24) {
        acc = (acc + segment_58 * 2 + 5) & 127;
        aux ^= (segment_58 & 15);
    } else {
        acc = (acc - segment_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_11(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int anchor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_74 = local_arr[aux % 3];
    acc = (acc + index_reg_74 * 2) & 127;
    int delta_44 = (aux + st.buffer[1]) & 3;
    switch (delta_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_59 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_59 > 44) {
        acc = (acc + stride_59 * 2 + 5) & 127;
        aux ^= (stride_59 & 15);
    } else {
        acc = (acc - stride_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_76 = local_arr[aux % 3];
    acc = (acc + tracker_76 * 2) & 127;
    int weight_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000980_8013_13(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int sample_91 = (aux + st.buffer[1]) & 3;
    switch (sample_91) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_82 = local_arr[aux % 3];
    acc = (acc + metric_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000980_8013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int vector_36 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_36 > 17) {
        acc = (acc + vector_36 * 2 + 5) & 127;
        aux ^= (vector_36 & 15);
    } else {
        acc = (acc - vector_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_90 = (aux + st.buffer[1]) & 3;
    switch (pivot_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000980_8013_15(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int metric_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_15) & 63;
    acc ^= aux;
    int index_reg_93 = (aux + st.buffer[1]) & 3;
    switch (index_reg_93) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000980_8013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_20 > 10) {
        acc = (acc + cursor_20 * 2 + 5) & 127;
        aux ^= (cursor_20 & 15);
    } else {
        acc = (acc - cursor_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000980_8013_17(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000980_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int residue_58 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_58 > 26) {
        acc = (acc + residue_58 * 2 + 5) & 127;
        aux ^= (residue_58 & 15);
    } else {
        acc = (acc - residue_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000980_8013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000980_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int checksum_24 = local_arr[aux % 3];
    acc = (acc + checksum_24 * 2) & 127;
    int factor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_33 > 40) {
        acc = (acc + factor_33 * 2 + 5) & 127;
        aux ^= (factor_33 & 15);
    } else {
        acc = (acc - factor_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000980_0;
    int sec_r000980_1;
    int sec_r000980_2;
    int sec_r000980_3;
    int sec_r000980_4;
    int sec_r000980_5;
    int sec_r000980_6;
    int sec_r000980_7;
    int sec_r000980_8;
    int sec_r000980_9;
    int sec_r000980_10;
    int sec_r000980_11;
    int sec_r000980_12;
    int sec_r000980_13;
    int sec_r000980_14;
    int sec_r000980_15;
    int sec_r000980_16;
    int sec_r000980_17;
    int sec_r000980_18;
    int sec_r000980_19;
    int sec_r000980_20;
    int pub_r000980_0;
    int pub_r000980_1;
    int pub_r000980_2;
    int pub_r000980_3;
    int pub_r000980_4;
    int pub_r000980_5;
    int pub_r000980_6;
    int pub_r000980_7;
    int pub_r000980_8;
    int pub_r000980_9;
    int pub_r000980_10;
    int pub_r000980_11;
    int pub_r000980_12;
    int pub_r000980_13;
    int pub_r000980_14;
    int pub_r000980_15;
    int pub_r000980_16;
    int pub_r000980_17;
    int pub_r000980_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000980_0 >= -100 && pub_r000980_0 <= 100);
    __CPROVER_assume(pub_r000980_1 >= -100 && pub_r000980_1 <= 100);
    __CPROVER_assume(pub_r000980_2 >= -100 && pub_r000980_2 <= 100);
    __CPROVER_assume(pub_r000980_3 >= -100 && pub_r000980_3 <= 100);
    __CPROVER_assume(pub_r000980_4 >= -100 && pub_r000980_4 <= 100);
    __CPROVER_assume(pub_r000980_5 >= -100 && pub_r000980_5 <= 100);
    __CPROVER_assume(pub_r000980_6 >= -100 && pub_r000980_6 <= 100);
    __CPROVER_assume(pub_r000980_7 >= -100 && pub_r000980_7 <= 100);
    __CPROVER_assume(pub_r000980_8 >= -100 && pub_r000980_8 <= 100);
    __CPROVER_assume(pub_r000980_9 >= -100 && pub_r000980_9 <= 100);
    __CPROVER_assume(pub_r000980_10 >= -100 && pub_r000980_10 <= 100);
    __CPROVER_assume(pub_r000980_11 >= -100 && pub_r000980_11 <= 100);
    __CPROVER_assume(pub_r000980_12 >= -100 && pub_r000980_12 <= 100);
    __CPROVER_assume(pub_r000980_13 >= -100 && pub_r000980_13 <= 100);
    __CPROVER_assume(pub_r000980_14 >= -100 && pub_r000980_14 <= 100);
    __CPROVER_assume(pub_r000980_15 >= -100 && pub_r000980_15 <= 100);
    __CPROVER_assume(pub_r000980_16 >= -100 && pub_r000980_16 <= 100);
    __CPROVER_assume(pub_r000980_17 >= -100 && pub_r000980_17 <= 100);
    __CPROVER_assume(pub_r000980_18 >= -100 && pub_r000980_18 <= 100);
    __CPROVER_assume(sec_r000980_0 >= 0 && sec_r000980_0 <= 255);
    __CPROVER_assume(sec_r000980_1 >= 0 && sec_r000980_1 <= 255);
    __CPROVER_assume(sec_r000980_2 >= 0 && sec_r000980_2 <= 255);
    __CPROVER_assume(sec_r000980_3 >= 0 && sec_r000980_3 <= 255);
    __CPROVER_assume(sec_r000980_4 >= 0 && sec_r000980_4 <= 255);
    __CPROVER_assume(sec_r000980_5 >= 0 && sec_r000980_5 <= 255);
    __CPROVER_assume(sec_r000980_6 >= 0 && sec_r000980_6 <= 255);
    __CPROVER_assume(sec_r000980_7 >= 0 && sec_r000980_7 <= 255);
    __CPROVER_assume(sec_r000980_8 >= 0 && sec_r000980_8 <= 255);
    __CPROVER_assume(sec_r000980_9 >= 0 && sec_r000980_9 <= 255);
    __CPROVER_assume(sec_r000980_10 >= 0 && sec_r000980_10 <= 255);
    __CPROVER_assume(sec_r000980_11 >= 0 && sec_r000980_11 <= 255);
    __CPROVER_assume(sec_r000980_12 >= 0 && sec_r000980_12 <= 255);
    __CPROVER_assume(sec_r000980_13 >= 0 && sec_r000980_13 <= 255);
    __CPROVER_assume(sec_r000980_14 >= 0 && sec_r000980_14 <= 255);
    __CPROVER_assume(sec_r000980_15 >= 0 && sec_r000980_15 <= 255);
    __CPROVER_assume(sec_r000980_16 >= 0 && sec_r000980_16 <= 255);
    __CPROVER_assume(sec_r000980_17 >= 0 && sec_r000980_17 <= 255);
    __CPROVER_assume(sec_r000980_18 >= 0 && sec_r000980_18 <= 255);
    __CPROVER_assume(sec_r000980_19 >= 0 && sec_r000980_19 <= 255);
    __CPROVER_assume(sec_r000980_20 >= 0 && sec_r000980_20 <= 255);

    struct MatrixBlock_R000980_8013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000980_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000980_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000980_0 + 7) & 15;
    struct EventLog_R000980_8013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000980_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000980_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000980_0 + 9) & 15;
    struct AudioFrame_R000980_8013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000980_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000980_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000980_0 + 11) & 15;

    union TelemetryField_R000980_8013_0 u_var;
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
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 31) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 46) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 49) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

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
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 26) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 41) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 42) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 34) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 49) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
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
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 33) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 48) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 39) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 54) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 17) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 32) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 28) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 43) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 10) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 25) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000980_3 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_72 > 22) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_72 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_73 > 31) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_73 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_74 > 42) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_74 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_75 > 43) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_72 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_76 > 41) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_72 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_76 ^ 0x2A) + pub_r000980_6) & 127;
    if (stage_v_78 > 37) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_77 ^ 0x2A) + pub_r000980_6) & 127;
    if (stage_v_79 > 31) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_75 ^ 0x2A) + pub_r000980_1) & 127;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r000980_11 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_81 > 36) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000980_3 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_82 > 39) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_77 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_83 > 46) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_81 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_84 > 24) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_77 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_85 > 44) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_84 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_86 > 20) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000980_1 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_87 > 24) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_84 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_88 > 44) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_84 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_89 > 38) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_73 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_90 > 32) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_75 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_91 > 28) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000980_3 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_92 > 46) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_87 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_93 > 48) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_88 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_94 > 30) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_80 ^ 0x2A) + pub_r000980_1) & 127;
    if (stage_v_95 > 48) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000980_2 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_96 > 30) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r000980_1 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_97 > 30) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_92 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_98 > 34) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000980_10 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_99 > 38) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000980_7 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_100 > 40) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000980_10 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_101 > 24) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_91 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_102 > 28) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000980_15 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_103 > 20) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_88 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_104 > 35) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_81 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_105 > 45) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_101 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_106 > 25) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_89 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_107 > 44) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_99 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_108 > 22) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_95 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_109 > 39) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_101 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_110 > 30) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_74 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_111 > 30) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_87 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_112 > 43) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000980_10 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_113 > 38) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_107 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_89 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_93 ^ 0x2A) + pub_r000980_1) & 127;
    if (stage_v_116 > 24) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_83 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_117 > 25) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_109 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_118 > 28) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_76 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_119 > 35) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_87 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_120 > 46) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_111 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_121 > 36) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_108 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_122 > 20) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000980_12 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_123 > 24) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_75 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_124 > 21) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_115 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_125 > 44) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_110 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_126 > 50) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_72 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_127 > 38) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_124 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_128 > 50) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_120 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_129 > 49) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000980_18 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_130 > 41) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_110 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_131 > 48) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_108 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_132 > 41) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_105 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_133 > 30) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_130 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_134 > 33) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_130 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_135 > 25) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_77 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_136 > 47) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_136 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_137 > 22) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r000980_11 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_138 > 32) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r000980_16 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_139 > 49) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000980_0 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_140 > 49) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_80 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_141 > 36) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_116 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_142 > 22) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_120 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_143 > 41) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_112 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_144 > 49) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000980_18 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_145 > 37) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_125 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_146 > 20) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_138 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_147 > 41) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_129 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_148 > 28) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_84 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_149 > 30) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_75 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_150 > 35) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_138 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_151 > 29) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000980_9 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_152 > 39) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r000980_20 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_153 > 35) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000980_6 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_154 > 35) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_143 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_155 > 41) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_100 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_156 > 28) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_80 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_157 > 33) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000980_9 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_158 > 28) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_133 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_159 > 47) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_126 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_160 > 33) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000980_18 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_161 > 35) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000980_15 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_162 > 24) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_116 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_163 > 41) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_133 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_164 > 48) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_96 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_165 > 45) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_139 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_166 > 23) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_129 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_167 > 21) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_105 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_168 > 43) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_123 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_169 > 49) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_124 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_170 > 48) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_84 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_171 > 34) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000980_17 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_172 > 29) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_127 ^ 0x2A) + pub_r000980_6) & 127;
    if (stage_v_173 > 28) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000980_0 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_174 > 48) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_173 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_175 > 36) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_139 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_176 > 42) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_86 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_177 > 32) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_160 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_178 > 41) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r000980_20 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_179 > 33) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_145 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_180 > 36) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_73 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_165 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_182 > 29) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000980_16 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_183 > 35) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_107 ^ 0x2A) + pub_r000980_6) & 127;
    if (stage_v_184 > 39) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_119 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_185 > 27) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_95 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_186 > 20) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_114 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_187 > 50) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_102 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_188 > 37) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_180 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_189 > 42) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_187 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_190 > 40) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_123 ^ 0x2A) + pub_r000980_16) & 127;
    if (stage_v_191 > 33) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_76 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_192 > 21) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000980_5 ^ 0x2A) + pub_r000980_12) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_125 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_194 > 46) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000980_13 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_195 > 36) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000980_15 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_196 > 34) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_152 ^ 0x2A) + pub_r000980_9) & 127;
    if (stage_v_197 > 43) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_83 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_198 > 36) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_167 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_199 > 27) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r000980_0 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_200 > 27) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_119 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_201 > 49) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000980_13 ^ 0x2A) + pub_r000980_10) & 127;
    if (stage_v_202 > 27) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_105 ^ 0x2A) + pub_r000980_6) & 127;
    if (stage_v_203 > 45) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r000980_7 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_204 > 44) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_104 ^ 0x2A) + pub_r000980_18) & 127;
    if (stage_v_205 > 39) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_203 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_206 > 30) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_157 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_207 > 29) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_103 ^ 0x2A) + pub_r000980_11) & 127;
    if (stage_v_208 > 43) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_143 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_209 > 38) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r000980_6 ^ 0x2A) + pub_r000980_8) & 127;
    if (stage_v_210 > 29) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r000980_10 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_211 > 40) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_104 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_212 > 41) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r000980_12 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_213 > 34) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_134 ^ 0x2A) + pub_r000980_0) & 127;
    if (stage_v_214 > 34) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000980_11 ^ 0x2A) + pub_r000980_1) & 127;
    if (stage_v_215 > 21) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r000980_8 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_216 > 20) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_132 ^ 0x2A) + pub_r000980_13) & 127;
    if (stage_v_217 > 34) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_199 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_218 > 39) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_172 ^ 0x2A) + pub_r000980_5) & 127;
    if (stage_v_219 > 37) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_129 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_220 > 28) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r000980_14 ^ 0x2A) + pub_r000980_1) & 127;
    if (stage_v_221 > 22) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_176 ^ 0x2A) + pub_r000980_4) & 127;
    if (stage_v_222 > 31) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r000980_16 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_223 > 48) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_140 ^ 0x2A) + pub_r000980_7) & 127;
    if (stage_v_224 > 30) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_170 ^ 0x2A) + pub_r000980_3) & 127;
    if (stage_v_225 > 37) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r000980_6 ^ 0x2A) + pub_r000980_15) & 127;
    if (stage_v_226 > 27) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_141 ^ 0x2A) + pub_r000980_14) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_176 ^ 0x2A) + pub_r000980_2) & 127;
    if (stage_v_228 > 21) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_86 ^ 0x2A) + pub_r000980_17) & 127;
    if (stage_v_229 > 37) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
