/*
 * Benchmark Program: R000307
 * Security Family: nested_implicit_flow
 * Generator Seed: 530713
 * High Inputs: 16 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000307_713_0 {
    int dim;
    int trace;
    short determinant;
    short scale;
    unsigned char stride;
    short density;
    int buffer[3];
};

struct FilterState_R000307_713_1 {
    int prev_out;
    int damping;
    unsigned char cutoff;
    short prev_in;
    int gain_db;
    short mode;
    int buffer[3];
};

union PacketPayload_R000307_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000307_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000307_713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_92 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_92 > 43) {
        acc = (acc + threshold_92 * 2 + 5) & 127;
        aux ^= (threshold_92 & 15);
    } else {
        acc = (acc - threshold_92 + 11) & 127;
        aux += 3;
    }
    int metric_18 = (aux + st.buffer[1]) & 3;
    switch (metric_18) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_1(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int segment_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_32) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_37 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_37 > 11) {
        acc = (acc + scale_37 * 2 + 5) & 127;
        aux ^= (scale_37 & 15);
    } else {
        acc = (acc - scale_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_66 = local_arr[aux % 3];
    acc = (acc + stride_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_2(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_47 = local_arr[aux % 3];
    acc = (acc + stride_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_3(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int sample_93 = local_arr[aux % 3];
    acc = (acc + sample_93 * 2) & 127;
    int margin_34 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_34 > 29) {
        acc = (acc + margin_34 * 2 + 5) & 127;
        aux ^= (margin_34 & 15);
    } else {
        acc = (acc - margin_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_4(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_49 = local_arr[aux % 3];
    acc = (acc + scale_49 * 2) & 127;
    int damping_49 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_49 > 23) {
        acc = (acc + damping_49 * 2 + 5) & 127;
        aux ^= (damping_49 & 15);
    } else {
        acc = (acc - damping_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_56) & 63;
    acc ^= aux;
    int threshold_75 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_75 > 18) {
        acc = (acc + threshold_75 * 2 + 5) & 127;
        aux ^= (threshold_75 & 15);
    } else {
        acc = (acc - threshold_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_32 = local_arr[aux % 3];
    acc = (acc + coefficient_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000307_713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_31 = local_arr[aux % 3];
    acc = (acc + accumulator_31 * 2) & 127;
    int bound_64 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_64 > 35) {
        acc = (acc + bound_64 * 2 + 5) & 127;
        aux ^= (bound_64 & 15);
    } else {
        acc = (acc - bound_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int pivot_44 = local_arr[aux % 3];
    acc = (acc + pivot_44 * 2) & 127;
    int parity_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000307_713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_44) & 63;
    acc ^= aux;
    int cursor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_77 > 31) {
        acc = (acc + cursor_77 * 2 + 5) & 127;
        aux ^= (cursor_77 & 15);
    } else {
        acc = (acc - cursor_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_10(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_44) & 63;
    acc ^= aux;
    int window_67 = (aux + st.buffer[1]) & 3;
    switch (window_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_79 > 28) {
        acc = (acc + checksum_79 * 2 + 5) & 127;
        aux ^= (checksum_79 & 15);
    } else {
        acc = (acc - checksum_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_69 = local_arr[aux % 3];
    acc = (acc + tally_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int scale_85 = local_arr[aux % 3];
    acc = (acc + scale_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_11 = (aux + st.buffer[1]) & 3;
    switch (damping_11) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_12(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_65 = (aux + st.buffer[1]) & 3;
    switch (damping_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_52 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_52 > 21) {
        acc = (acc + stride_52 * 2 + 5) & 127;
        aux ^= (stride_52 & 15);
    } else {
        acc = (acc - stride_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_13(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int offset_87 = (aux + st.buffer[1]) & 3;
    switch (offset_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    int cursor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_99 > 44) {
        acc = (acc + cursor_99 * 2 + 5) & 127;
        aux ^= (cursor_99 & 15);
    } else {
        acc = (acc - cursor_99 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_20 = local_arr[aux % 3];
    acc = (acc + offset_20 * 2) & 127;
    int index_reg_11 = (aux + st.buffer[1]) & 3;
    switch (index_reg_11) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_84) & 63;
    acc ^= aux;
    int mask_34 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_34 > 48) {
        acc = (acc + mask_34 * 2 + 5) & 127;
        aux ^= (mask_34 & 15);
    } else {
        acc = (acc - mask_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_16(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_62 = local_arr[aux % 3];
    acc = (acc + margin_62 * 2) & 127;
    int mask_92 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_92 > 39) {
        acc = (acc + mask_92 * 2 + 5) & 127;
        aux ^= (mask_92 & 15);
    } else {
        acc = (acc - mask_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_92 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_92 > 11) {
        acc = (acc + stride_92 * 2 + 5) & 127;
        aux ^= (stride_92 & 15);
    } else {
        acc = (acc - stride_92 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_60) & 63;
    acc ^= aux;
    int weight_85 = (aux + st.buffer[1]) & 3;
    switch (weight_85) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_18(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_56 = (aux + st.buffer[1]) & 3;
    switch (mask_56) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int parity_43 = (aux + st.buffer[1]) & 3;
    switch (parity_43) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_80 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_80 > 32) {
        acc = (acc + cursor_80 * 2 + 5) & 127;
        aux ^= (cursor_80 & 15);
    } else {
        acc = (acc - cursor_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_87 = local_arr[aux % 3];
    acc = (acc + threshold_87 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_20(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_35 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_35 > 19) {
        acc = (acc + phase_35 * 2 + 5) & 127;
        aux ^= (phase_35 & 15);
    } else {
        acc = (acc - phase_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int checksum_70 = local_arr[aux % 3];
    acc = (acc + checksum_70 * 2) & 127;
    int anchor_73 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_73 > 35) {
        acc = (acc + anchor_73 * 2 + 5) & 127;
        aux ^= (anchor_73 & 15);
    } else {
        acc = (acc - anchor_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000307_713_22(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000307_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_56 = local_arr[aux % 3];
    acc = (acc + threshold_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000307_713_23(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000307_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int mask_63 = (aux + st.buffer[1]) & 3;
    switch (mask_63) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_39 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_39 > 24) {
        acc = (acc + coefficient_39 * 2 + 5) & 127;
        aux ^= (coefficient_39 & 15);
    } else {
        acc = (acc - coefficient_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000307_0;
    int sec_r000307_1;
    int sec_r000307_2;
    int sec_r000307_3;
    int sec_r000307_4;
    int sec_r000307_5;
    int sec_r000307_6;
    int sec_r000307_7;
    int sec_r000307_8;
    int sec_r000307_9;
    int sec_r000307_10;
    int sec_r000307_11;
    int sec_r000307_12;
    int sec_r000307_13;
    int sec_r000307_14;
    int sec_r000307_15;
    int pub_r000307_0;
    int pub_r000307_1;
    int pub_r000307_2;
    int pub_r000307_3;
    int pub_r000307_4;
    int pub_r000307_5;
    int pub_r000307_6;
    int pub_r000307_7;
    int pub_r000307_8;
    int pub_r000307_9;
    int pub_r000307_10;
    int pub_r000307_11;
    int pub_r000307_12;
    int pub_r000307_13;
    int pub_r000307_14;
    int pub_r000307_15;
    int pub_r000307_16;
    int pub_r000307_17;
    int pub_r000307_18;
    int pub_r000307_19;
    int pub_r000307_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000307_0 >= -100 && pub_r000307_0 <= 100);
    __CPROVER_assume(pub_r000307_1 >= -100 && pub_r000307_1 <= 100);
    __CPROVER_assume(pub_r000307_2 >= -100 && pub_r000307_2 <= 100);
    __CPROVER_assume(pub_r000307_3 >= -100 && pub_r000307_3 <= 100);
    __CPROVER_assume(pub_r000307_4 >= -100 && pub_r000307_4 <= 100);
    __CPROVER_assume(pub_r000307_5 >= -100 && pub_r000307_5 <= 100);
    __CPROVER_assume(pub_r000307_6 >= -100 && pub_r000307_6 <= 100);
    __CPROVER_assume(pub_r000307_7 >= -100 && pub_r000307_7 <= 100);
    __CPROVER_assume(pub_r000307_8 >= -100 && pub_r000307_8 <= 100);
    __CPROVER_assume(pub_r000307_9 >= -100 && pub_r000307_9 <= 100);
    __CPROVER_assume(pub_r000307_10 >= -100 && pub_r000307_10 <= 100);
    __CPROVER_assume(pub_r000307_11 >= -100 && pub_r000307_11 <= 100);
    __CPROVER_assume(pub_r000307_12 >= -100 && pub_r000307_12 <= 100);
    __CPROVER_assume(pub_r000307_13 >= -100 && pub_r000307_13 <= 100);
    __CPROVER_assume(pub_r000307_14 >= -100 && pub_r000307_14 <= 100);
    __CPROVER_assume(pub_r000307_15 >= -100 && pub_r000307_15 <= 100);
    __CPROVER_assume(pub_r000307_16 >= -100 && pub_r000307_16 <= 100);
    __CPROVER_assume(pub_r000307_17 >= -100 && pub_r000307_17 <= 100);
    __CPROVER_assume(pub_r000307_18 >= -100 && pub_r000307_18 <= 100);
    __CPROVER_assume(pub_r000307_19 >= -100 && pub_r000307_19 <= 100);
    __CPROVER_assume(pub_r000307_20 >= -100 && pub_r000307_20 <= 100);
    __CPROVER_assume(sec_r000307_0 >= 0 && sec_r000307_0 <= 255);
    __CPROVER_assume(sec_r000307_1 >= 0 && sec_r000307_1 <= 255);
    __CPROVER_assume(sec_r000307_2 >= 0 && sec_r000307_2 <= 255);
    __CPROVER_assume(sec_r000307_3 >= 0 && sec_r000307_3 <= 255);
    __CPROVER_assume(sec_r000307_4 >= 0 && sec_r000307_4 <= 255);
    __CPROVER_assume(sec_r000307_5 >= 0 && sec_r000307_5 <= 255);
    __CPROVER_assume(sec_r000307_6 >= 0 && sec_r000307_6 <= 255);
    __CPROVER_assume(sec_r000307_7 >= 0 && sec_r000307_7 <= 255);
    __CPROVER_assume(sec_r000307_8 >= 0 && sec_r000307_8 <= 255);
    __CPROVER_assume(sec_r000307_9 >= 0 && sec_r000307_9 <= 255);
    __CPROVER_assume(sec_r000307_10 >= 0 && sec_r000307_10 <= 255);
    __CPROVER_assume(sec_r000307_11 >= 0 && sec_r000307_11 <= 255);
    __CPROVER_assume(sec_r000307_12 >= 0 && sec_r000307_12 <= 255);
    __CPROVER_assume(sec_r000307_13 >= 0 && sec_r000307_13 <= 255);
    __CPROVER_assume(sec_r000307_14 >= 0 && sec_r000307_14 <= 255);
    __CPROVER_assume(sec_r000307_15 >= 0 && sec_r000307_15 <= 255);

    struct MatrixBlock_R000307_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000307_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000307_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000307_0 + 7) & 15;
    struct FilterState_R000307_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000307_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000307_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000307_0 + 9) & 15;

    union PacketPayload_R000307_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
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
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 35) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 50) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 38) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 53) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

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
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 23) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 38) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 13) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 28) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 10) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 25) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 38) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 53) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000307_14 & 1) != 0) {
        if ((sec_r000307_15 & 2) != 0) {
            stage_v_51 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000307_0 & 2) != 0) {
            stage_v_52 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000307_14 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_53 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000307_13 & 1) != 0) {
        if ((sec_r000307_6 & 2) != 0) {
            stage_v_54 = (pub_r000307_1 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000307_1 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000307_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000307_1 & 2) != 0) {
            stage_v_55 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000307_6 & 2) != 0) {
            stage_v_56 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000307_6 & 2) != 0) {
            stage_v_57 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000307_2 & 1) != 0) {
        if ((sec_r000307_15 & 2) != 0) {
            stage_v_58 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_59 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000307_12 & 1) != 0) {
        if ((sec_r000307_15 & 2) != 0) {
            stage_v_60 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_61 = (pub_r000307_10 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000307_10 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000307_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_62 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000307_6 & 1) != 0) {
        if ((sec_r000307_0 & 2) != 0) {
            stage_v_63 = (pub_r000307_2 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000307_2 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000307_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_64 = (pub_r000307_6 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000307_6 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000307_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_65 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000307_5 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_66 = (pub_r000307_9 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000307_9 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000307_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000307_10 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_67 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000307_12 & 1) != 0) {
        if ((sec_r000307_11 & 2) != 0) {
            stage_v_68 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_69 = (pub_r000307_5 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000307_5 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000307_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000307_10 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_70 = (pub_r000307_10 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000307_10 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000307_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_71 = (pub_r000307_10 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000307_10 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000307_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_72 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000307_8 & 2) != 0) {
            stage_v_73 = (pub_r000307_1 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000307_1 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000307_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_74 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000307_3 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_75 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_76 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000307_4 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_77 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_78 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000307_15 & 2) != 0) {
            stage_v_79 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_80 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000307_0 & 2) != 0) {
            stage_v_81 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000307_13 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_82 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000307_11 & 2) != 0) {
            stage_v_83 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000307_11 & 2) != 0) {
            stage_v_84 = (pub_r000307_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000307_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000307_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000307_15 & 2) != 0) {
            stage_v_85 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000307_7 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_86 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000307_9 & 2) != 0) {
            stage_v_87 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000307_5 & 1) != 0) {
        if ((sec_r000307_1 & 2) != 0) {
            stage_v_88 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000307_1 & 2) != 0) {
            stage_v_89 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_90 = (pub_r000307_18 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000307_18 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000307_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000307_4 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_91 = (pub_r000307_0 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000307_0 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000307_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_92 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_93 = (pub_r000307_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000307_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000307_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000307_3 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_94 = (pub_r000307_18 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000307_18 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000307_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000307_5 & 2) != 0) {
            stage_v_95 = (pub_r000307_13 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000307_13 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000307_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_96 = (pub_r000307_0 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000307_0 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000307_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_97 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_98 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000307_1 & 2) != 0) {
            stage_v_99 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000307_6 & 2) != 0) {
            stage_v_100 = (pub_r000307_13 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000307_13 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000307_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000307_0 & 2) != 0) {
            stage_v_101 = (pub_r000307_16 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000307_16 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000307_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000307_12 & 2) != 0) {
            stage_v_102 = (pub_r000307_6 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000307_6 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000307_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000307_2 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_103 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000307_10 & 2) != 0) {
            stage_v_104 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000307_4 & 1) != 0) {
        if ((sec_r000307_5 & 2) != 0) {
            stage_v_105 = (pub_r000307_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000307_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000307_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_106 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000307_14 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_107 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_108 = (pub_r000307_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000307_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000307_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000307_1 & 1) != 0) {
        if ((sec_r000307_1 & 2) != 0) {
            stage_v_109 = (pub_r000307_9 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000307_9 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000307_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000307_11 & 2) != 0) {
            stage_v_110 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_111 = (pub_r000307_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000307_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000307_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_112 = (pub_r000307_1 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000307_1 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000307_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000307_12 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_113 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000307_10 & 2) != 0) {
            stage_v_114 = (pub_r000307_1 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000307_1 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000307_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_115 = (pub_r000307_13 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000307_13 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000307_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000307_9 & 2) != 0) {
            stage_v_116 = (pub_r000307_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000307_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000307_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000307_11 & 1) != 0) {
        if ((sec_r000307_9 & 2) != 0) {
            stage_v_117 = (pub_r000307_18 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000307_18 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000307_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_118 = (pub_r000307_5 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000307_5 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000307_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000307_2 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_119 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000307_12 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_120 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000307_11 & 2) != 0) {
            stage_v_121 = (pub_r000307_9 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000307_9 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000307_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000307_9 & 2) != 0) {
            stage_v_122 = (pub_r000307_1 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000307_1 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000307_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000307_1 & 1) != 0) {
        if ((sec_r000307_7 & 2) != 0) {
            stage_v_123 = (pub_r000307_5 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000307_5 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000307_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000307_13 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_124 = (pub_r000307_13 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000307_13 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000307_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000307_13 & 2) != 0) {
            stage_v_125 = (pub_r000307_7 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000307_7 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000307_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000307_9 & 2) != 0) {
            stage_v_126 = (pub_r000307_6 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000307_6 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000307_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_127 = (pub_r000307_8 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000307_8 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000307_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000307_14 & 2) != 0) {
            stage_v_128 = (pub_r000307_20 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000307_20 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000307_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_129 = (pub_r000307_19 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000307_19 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000307_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000307_4 & 2) != 0) {
            stage_v_130 = (pub_r000307_15 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000307_15 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000307_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000307_11 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_131 = (pub_r000307_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000307_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000307_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000307_2 & 2) != 0) {
            stage_v_132 = (pub_r000307_3 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000307_3 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000307_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000307_1 & 1) != 0) {
        if ((sec_r000307_8 & 2) != 0) {
            stage_v_133 = (pub_r000307_16 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000307_16 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000307_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000307_3 & 2) != 0) {
            stage_v_134 = (pub_r000307_11 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000307_11 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000307_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
