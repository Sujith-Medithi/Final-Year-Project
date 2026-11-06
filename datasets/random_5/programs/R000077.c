/*
 * Benchmark Program: R000077
 * Security Family: nested_implicit_flow
 * Generator Seed: 507713
 * High Inputs: 18 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000077_7713_0 {
    short envelope;
    unsigned char gain;
    int peak;
    int channels;
    int rms;
    int sample_rate;
    int buffer[3];
};

struct StreamBuffer_R000077_7713_1 {
    int watermark;
    short tail;
    unsigned char checksum;
    int head;
    int capacity;
    short state;
    int buffer[3];
};

union TelemetryField_R000077_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000077_7713_0(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int mask_37 = local_arr[aux % 3];
    acc = (acc + mask_37 * 2) & 127;
    int vector_47 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_47 > 40) {
        acc = (acc + vector_47 * 2 + 5) & 127;
        aux ^= (vector_47 & 15);
    } else {
        acc = (acc - vector_47 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_1(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int quantum_87 = local_arr[aux % 3];
    acc = (acc + quantum_87 * 2) & 127;
    int bound_93 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_93 > 24) {
        acc = (acc + bound_93 * 2 + 5) & 127;
        aux ^= (bound_93 & 15);
    } else {
        acc = (acc - bound_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_2(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_59 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_59 > 42) {
        acc = (acc + pivot_59 * 2 + 5) & 127;
        aux ^= (pivot_59 & 15);
    } else {
        acc = (acc - pivot_59 + 11) & 127;
        aux += 3;
    }
    int accumulator_78 = (aux + st.buffer[1]) & 3;
    switch (accumulator_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int sample_97 = local_arr[aux % 3];
    acc = (acc + sample_97 * 2) & 127;
    int factor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_37) & 63;
    acc ^= aux;
    int bound_79 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_79 > 18) {
        acc = (acc + bound_79 * 2 + 5) & 127;
        aux ^= (bound_79 & 15);
    } else {
        acc = (acc - bound_79 + 11) & 127;
        aux += 3;
    }
    int scale_22 = (aux + st.buffer[1]) & 3;
    switch (scale_22) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_75) & 63;
    acc ^= aux;
    int accumulator_48 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_48 > 40) {
        acc = (acc + accumulator_48 * 2 + 5) & 127;
        aux ^= (accumulator_48 & 15);
    } else {
        acc = (acc - accumulator_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_50 = local_arr[aux % 3];
    acc = (acc + coefficient_50 * 2) & 127;
    int pivot_47 = (aux + st.buffer[1]) & 3;
    switch (pivot_47) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_5(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int parity_53 = (aux + st.buffer[1]) & 3;
    switch (parity_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_52 = local_arr[aux % 3];
    acc = (acc + delta_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_48) & 63;
    acc ^= aux;
    int bound_51 = (aux + st.buffer[1]) & 3;
    switch (bound_51) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_7(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_96) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_25 = (aux + st.buffer[1]) & 3;
    switch (accumulator_25) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_8(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int segment_44 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_44 > 48) {
        acc = (acc + segment_44 * 2 + 5) & 127;
        aux ^= (segment_44 & 15);
    } else {
        acc = (acc - segment_44 + 11) & 127;
        aux += 3;
    }
    int sample_83 = (aux + st.buffer[1]) & 3;
    switch (sample_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_41 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_41 > 32) {
        acc = (acc + quotient_41 * 2 + 5) & 127;
        aux ^= (quotient_41 & 15);
    } else {
        acc = (acc - quotient_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_62 = local_arr[aux % 3];
    acc = (acc + pivot_62 * 2) & 127;
    int weight_62 = (aux + st.buffer[1]) & 3;
    switch (weight_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_48 = (aux + st.buffer[1]) & 3;
    switch (sample_48) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_15 = local_arr[aux % 3];
    acc = (acc + coefficient_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_11(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_98 = (aux + st.buffer[1]) & 3;
    switch (residue_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int stride_48 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_48 > 28) {
        acc = (acc + stride_48 * 2 + 5) & 127;
        aux ^= (stride_48 & 15);
    } else {
        acc = (acc - stride_48 + 11) & 127;
        aux += 3;
    }
    int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000077_7713_12(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int anchor_23 = local_arr[aux % 3];
    acc = (acc + anchor_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000077_7713_13(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int accumulator_49 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_49 > 16) {
        acc = (acc + accumulator_49 * 2 + 5) & 127;
        aux ^= (accumulator_49 & 15);
    } else {
        acc = (acc - accumulator_49 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_70 = local_arr[aux % 3];
    acc = (acc + pivot_70 * 2) & 127;
    int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int parity_69 = local_arr[aux % 3];
    acc = (acc + parity_69 * 2) & 127;
    int tracker_92 = (aux + st.buffer[1]) & 3;
    switch (tracker_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000077_7713_15(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_30 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_30 > 32) {
        acc = (acc + vector_30 * 2 + 5) & 127;
        aux ^= (vector_30 & 15);
    } else {
        acc = (acc - vector_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_40 = local_arr[aux % 3];
    acc = (acc + coefficient_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_69 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_69 > 12) {
        acc = (acc + sample_69 * 2 + 5) & 127;
        aux ^= (sample_69 & 15);
    } else {
        acc = (acc - sample_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_17(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int damping_15 = (aux + st.buffer[1]) & 3;
    switch (damping_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_61) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_40 = local_arr[aux % 3];
    acc = (acc + tally_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int bound_36 = (aux + st.buffer[1]) & 3;
    switch (bound_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_32 = local_arr[aux % 3];
    acc = (acc + damping_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000077_7713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_35 = (aux + st.buffer[1]) & 3;
    switch (margin_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_16 = local_arr[aux % 3];
    acc = (acc + quotient_16 * 2) & 127;
    int sample_13 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_13 > 48) {
        acc = (acc + sample_13 * 2 + 5) & 127;
        aux ^= (sample_13 & 15);
    } else {
        acc = (acc - sample_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000077_7713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int vector_37 = local_arr[aux % 3];
    acc = (acc + vector_37 * 2) & 127;
    int window_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000077_0;
    int sec_r000077_1;
    int sec_r000077_2;
    int sec_r000077_3;
    int sec_r000077_4;
    int sec_r000077_5;
    int sec_r000077_6;
    int sec_r000077_7;
    int sec_r000077_8;
    int sec_r000077_9;
    int sec_r000077_10;
    int sec_r000077_11;
    int sec_r000077_12;
    int sec_r000077_13;
    int sec_r000077_14;
    int sec_r000077_15;
    int sec_r000077_16;
    int sec_r000077_17;
    int pub_r000077_0;
    int pub_r000077_1;
    int pub_r000077_2;
    int pub_r000077_3;
    int pub_r000077_4;
    int pub_r000077_5;
    int pub_r000077_6;
    int pub_r000077_7;
    int pub_r000077_8;
    int pub_r000077_9;
    int pub_r000077_10;
    int pub_r000077_11;
    int pub_r000077_12;
    int pub_r000077_13;
    int pub_r000077_14;
    int pub_r000077_15;
    int pub_r000077_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000077_0 >= -100 && pub_r000077_0 <= 100);
    __CPROVER_assume(pub_r000077_1 >= -100 && pub_r000077_1 <= 100);
    __CPROVER_assume(pub_r000077_2 >= -100 && pub_r000077_2 <= 100);
    __CPROVER_assume(pub_r000077_3 >= -100 && pub_r000077_3 <= 100);
    __CPROVER_assume(pub_r000077_4 >= -100 && pub_r000077_4 <= 100);
    __CPROVER_assume(pub_r000077_5 >= -100 && pub_r000077_5 <= 100);
    __CPROVER_assume(pub_r000077_6 >= -100 && pub_r000077_6 <= 100);
    __CPROVER_assume(pub_r000077_7 >= -100 && pub_r000077_7 <= 100);
    __CPROVER_assume(pub_r000077_8 >= -100 && pub_r000077_8 <= 100);
    __CPROVER_assume(pub_r000077_9 >= -100 && pub_r000077_9 <= 100);
    __CPROVER_assume(pub_r000077_10 >= -100 && pub_r000077_10 <= 100);
    __CPROVER_assume(pub_r000077_11 >= -100 && pub_r000077_11 <= 100);
    __CPROVER_assume(pub_r000077_12 >= -100 && pub_r000077_12 <= 100);
    __CPROVER_assume(pub_r000077_13 >= -100 && pub_r000077_13 <= 100);
    __CPROVER_assume(pub_r000077_14 >= -100 && pub_r000077_14 <= 100);
    __CPROVER_assume(pub_r000077_15 >= -100 && pub_r000077_15 <= 100);
    __CPROVER_assume(pub_r000077_16 >= -100 && pub_r000077_16 <= 100);
    __CPROVER_assume(sec_r000077_0 >= 0 && sec_r000077_0 <= 255);
    __CPROVER_assume(sec_r000077_1 >= 0 && sec_r000077_1 <= 255);
    __CPROVER_assume(sec_r000077_2 >= 0 && sec_r000077_2 <= 255);
    __CPROVER_assume(sec_r000077_3 >= 0 && sec_r000077_3 <= 255);
    __CPROVER_assume(sec_r000077_4 >= 0 && sec_r000077_4 <= 255);
    __CPROVER_assume(sec_r000077_5 >= 0 && sec_r000077_5 <= 255);
    __CPROVER_assume(sec_r000077_6 >= 0 && sec_r000077_6 <= 255);
    __CPROVER_assume(sec_r000077_7 >= 0 && sec_r000077_7 <= 255);
    __CPROVER_assume(sec_r000077_8 >= 0 && sec_r000077_8 <= 255);
    __CPROVER_assume(sec_r000077_9 >= 0 && sec_r000077_9 <= 255);
    __CPROVER_assume(sec_r000077_10 >= 0 && sec_r000077_10 <= 255);
    __CPROVER_assume(sec_r000077_11 >= 0 && sec_r000077_11 <= 255);
    __CPROVER_assume(sec_r000077_12 >= 0 && sec_r000077_12 <= 255);
    __CPROVER_assume(sec_r000077_13 >= 0 && sec_r000077_13 <= 255);
    __CPROVER_assume(sec_r000077_14 >= 0 && sec_r000077_14 <= 255);
    __CPROVER_assume(sec_r000077_15 >= 0 && sec_r000077_15 <= 255);
    __CPROVER_assume(sec_r000077_16 >= 0 && sec_r000077_16 <= 255);
    __CPROVER_assume(sec_r000077_17 >= 0 && sec_r000077_17 <= 255);

    struct AudioFrame_R000077_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000077_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000077_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000077_0 + 7) & 15;
    struct StreamBuffer_R000077_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000077_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000077_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000077_0 + 9) & 15;

    union TelemetryField_R000077_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
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
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 24) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 39) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 38) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 53) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((sec_r000077_1 & 1) != 0) {
        if ((sec_r000077_4 & 2) != 0) {
            stage_v_36 = (pub_r000077_13 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000077_13 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000077_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_37 = (pub_r000077_4 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000077_4 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000077_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000077_11 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_38 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_39 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000077_1 & 1) != 0) {
        if ((sec_r000077_8 & 2) != 0) {
            stage_v_40 = (pub_r000077_0 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000077_0 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000077_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000077_6 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_41 = (pub_r000077_4 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000077_4 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000077_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000077_10 & 1) != 0) {
        if ((sec_r000077_16 & 2) != 0) {
            stage_v_42 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_43 = (pub_r000077_4 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000077_4 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000077_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000077_12 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_44 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((sec_r000077_0 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_45 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000077_5 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_46 = (pub_r000077_10 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000077_10 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000077_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000077_15 & 1) != 0) {
        if ((sec_r000077_11 & 2) != 0) {
            stage_v_47 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000077_17 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_48 = (pub_r000077_16 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000077_16 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000077_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_49 = (pub_r000077_9 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000077_9 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000077_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000077_17 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_50 = (pub_r000077_5 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000077_5 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000077_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_51 = (pub_r000077_3 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000077_3 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000077_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000077_8 & 2) != 0) {
            stage_v_52 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000077_0 & 2) != 0) {
            stage_v_53 = (pub_r000077_15 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000077_15 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000077_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000077_5 & 1) != 0) {
        if ((sec_r000077_0 & 2) != 0) {
            stage_v_54 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_55 = (pub_r000077_15 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000077_15 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000077_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000077_17 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_56 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000077_10 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_57 = (pub_r000077_0 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000077_0 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000077_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000077_5 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_58 = (pub_r000077_0 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000077_0 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000077_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000077_13 & 2) != 0) {
            stage_v_59 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000077_6 & 1) != 0) {
        if ((sec_r000077_9 & 2) != 0) {
            stage_v_60 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_61 = (pub_r000077_14 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000077_14 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000077_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000077_7 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_62 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000077_17 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_63 = (pub_r000077_15 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000077_15 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000077_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_64 = (pub_r000077_2 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000077_2 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000077_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000077_4 & 2) != 0) {
            stage_v_65 = (pub_r000077_15 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000077_15 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000077_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_66 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000077_2 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_67 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_68 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_69 = (pub_r000077_14 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000077_14 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000077_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_70 = (pub_r000077_2 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000077_2 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000077_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000077_8 & 2) != 0) {
            stage_v_71 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_72 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_73 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_74 = (pub_r000077_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000077_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000077_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000077_15 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_75 = (pub_r000077_13 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000077_13 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000077_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_76 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000077_11 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_77 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000077_5 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_78 = (pub_r000077_3 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000077_3 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000077_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_79 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_80 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000077_7 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_81 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_82 = (pub_r000077_9 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000077_9 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000077_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000077_7 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_83 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_84 = (pub_r000077_15 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000077_15 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000077_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000077_13 & 2) != 0) {
            stage_v_85 = (pub_r000077_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000077_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000077_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_86 = (pub_r000077_16 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000077_16 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000077_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000077_9 & 2) != 0) {
            stage_v_87 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_88 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000077_10 & 1) != 0) {
        if ((sec_r000077_13 & 2) != 0) {
            stage_v_89 = (pub_r000077_13 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000077_13 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000077_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_90 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000077_0 & 1) != 0) {
        if ((sec_r000077_0 & 2) != 0) {
            stage_v_91 = (pub_r000077_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000077_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000077_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_92 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000077_12 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_93 = (pub_r000077_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000077_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000077_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_94 = (pub_r000077_16 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000077_16 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000077_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000077_0 & 2) != 0) {
            stage_v_95 = (pub_r000077_13 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000077_13 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000077_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_96 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000077_11 & 2) != 0) {
            stage_v_97 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000077_8 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_98 = (pub_r000077_2 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000077_2 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000077_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_99 = (pub_r000077_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000077_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000077_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000077_5 & 2) != 0) {
            stage_v_100 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_101 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_102 = (pub_r000077_1 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000077_1 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000077_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_103 = (pub_r000077_16 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000077_16 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000077_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_104 = (pub_r000077_14 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000077_14 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000077_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_105 = (pub_r000077_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000077_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000077_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_106 = (pub_r000077_4 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000077_4 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000077_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_107 = (pub_r000077_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000077_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000077_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000077_11 & 2) != 0) {
            stage_v_108 = (pub_r000077_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000077_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000077_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_109 = (pub_r000077_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000077_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000077_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000077_15 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_110 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000077_7 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_111 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000077_8 & 2) != 0) {
            stage_v_112 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000077_15 & 2) != 0) {
            stage_v_113 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_114 = (pub_r000077_5 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000077_5 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000077_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_115 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000077_16 & 2) != 0) {
            stage_v_116 = (pub_r000077_5 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000077_5 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000077_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000077_1 & 2) != 0) {
            stage_v_117 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000077_10 & 2) != 0) {
            stage_v_118 = (pub_r000077_10 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000077_10 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000077_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000077_2 & 2) != 0) {
            stage_v_119 = (pub_r000077_14 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000077_14 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000077_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_120 = (pub_r000077_8 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000077_8 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000077_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000077_17 & 2) != 0) {
            stage_v_121 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_122 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000077_3 & 2) != 0) {
            stage_v_123 = (pub_r000077_12 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000077_12 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000077_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000077_16 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_124 = (pub_r000077_7 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000077_7 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000077_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000077_6 & 2) != 0) {
            stage_v_125 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000077_14 & 2) != 0) {
            stage_v_126 = (pub_r000077_11 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000077_11 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000077_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000077_7 & 2) != 0) {
            stage_v_127 = (pub_r000077_6 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000077_6 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000077_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000077_12 & 1) != 0) {
        if ((sec_r000077_12 & 2) != 0) {
            stage_v_128 = (pub_r000077_5 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000077_5 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000077_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
