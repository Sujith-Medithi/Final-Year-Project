/*
 * Benchmark Program: R001007
 * Security Family: nested_implicit_flow
 * Generator Seed: 600713
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001007_713_0 {
    unsigned char checksum;
    int tail;
    int watermark;
    int state;
    int buffer[3];
};

struct AudioFrame_R001007_713_1 {
    short sample_rate;
    int peak;
    int rms;
    short gain;
    unsigned char envelope;
    int buffer[3];
};

struct FilterState_R001007_713_2 {
    unsigned char prev_out;
    unsigned char gain_db;
    unsigned char cutoff;
    int damping;
    int mode;
    int buffer[3];
};

struct Vector3D_R001007_713_3 {
    unsigned char coord_y;
    short heading;
    short coord_x;
    unsigned char coord_z;
    short pitch;
    int buffer[3];
};

union ColorPixel_R001007_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001007_713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_91 = 0;
    for (int k = 0; k < 3; k++) {
        bound_91 = (bound_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_91) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_56 = local_arr[aux % 3];
    acc = (acc + segment_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_1(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int tally_71 = local_arr[aux % 3];
    acc = (acc + tally_71 * 2) & 127;
    int quotient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_80) & 63;
    acc ^= aux;
    int factor_72 = 0;
    for (int k = 0; k < 3; k++) {
        factor_72 = (factor_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_2(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_45 = (aux + st.buffer[1]) & 3;
    switch (cursor_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_93 = 0;
    for (int k = 0; k < 3; k++) {
        vector_93 = (vector_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_93) & 127;
    }
    int offset_73 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_73 > 41) {
        acc = (acc + offset_73 * 2 + 5) & 127;
        aux ^= (offset_73 & 15);
    } else {
        acc = (acc - offset_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_14) & 63;
    acc ^= aux;
    int quantum_59 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_59 = (quantum_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_4(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int metric_65 = (aux + st.buffer[1]) & 3;
    switch (metric_65) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_63 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_63 > 40) {
        acc = (acc + segment_63 * 2 + 5) & 127;
        aux ^= (segment_63 & 15);
    } else {
        acc = (acc - segment_63 + 11) & 127;
        aux += 3;
    }
    int tally_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001007_713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int window_49 = local_arr[aux % 3];
    acc = (acc + window_49 * 2) & 127;
    int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_57 = 0;
    for (int k = 0; k < 3; k++) {
        parity_57 = (parity_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_6(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int offset_48 = (aux + st.buffer[1]) & 3;
    switch (offset_48) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_83 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_83 = (tracker_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_31 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_31 > 23) {
        acc = (acc + accumulator_31 * 2 + 5) & 127;
        aux ^= (accumulator_31 & 15);
    } else {
        acc = (acc - accumulator_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_32 > 31) {
        acc = (acc + anchor_32 * 2 + 5) & 127;
        aux ^= (anchor_32 & 15);
    } else {
        acc = (acc - anchor_32 + 11) & 127;
        aux += 3;
    }
    int offset_12 = (aux + st.buffer[1]) & 3;
    switch (offset_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_19 = local_arr[aux % 3];
    acc = (acc + residue_19 * 2) & 127;
    int offset_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001007_713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int vector_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_95) & 63;
    acc ^= aux;
    int threshold_89 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_89 > 17) {
        acc = (acc + threshold_89 * 2 + 5) & 127;
        aux ^= (threshold_89 & 15);
    } else {
        acc = (acc - threshold_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_68 = local_arr[aux % 3];
    acc = (acc + cursor_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_72) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_95 > 43) {
        acc = (acc + quotient_95 * 2 + 5) & 127;
        aux ^= (quotient_95 & 15);
    } else {
        acc = (acc - quotient_95 + 11) & 127;
        aux += 3;
    }
    int index_reg_80 = (aux + st.buffer[1]) & 3;
    switch (index_reg_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_10(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_34 = (aux + st.buffer[1]) & 3;
    switch (stride_34) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_11(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_46 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_46 = (anchor_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_46) & 127;
    }
    int accumulator_64 = (aux + st.buffer[1]) & 3;
    switch (accumulator_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_12(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_38 = 0;
    for (int k = 0; k < 3; k++) {
        parity_38 = (parity_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_38) & 127;
    }
    int vector_81 = (aux + st.buffer[1]) & 3;
    switch (vector_81) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_63 = local_arr[aux % 3];
    acc = (acc + factor_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_13(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_48 = 0;
    for (int k = 0; k < 3; k++) {
        delta_48 = (delta_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_48) & 127;
    }
    int vector_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001007_713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_77 = 0;
    for (int k = 0; k < 2; k++) {
        phase_77 = (phase_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_77) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_16 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_16 > 11) {
        acc = (acc + scale_16 * 2 + 5) & 127;
        aux ^= (scale_16 & 15);
    } else {
        acc = (acc - scale_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_21) & 63;
    acc ^= aux;
    int damping_18 = (aux + st.buffer[1]) & 3;
    switch (damping_18) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_17(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int delta_56 = 0;
    for (int k = 0; k < 3; k++) {
        delta_56 = (delta_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_56) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_37 = local_arr[aux % 3];
    acc = (acc + tally_37 * 2) & 127;
    int index_reg_66 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_66 > 12) {
        acc = (acc + index_reg_66 * 2 + 5) & 127;
        aux ^= (index_reg_66 & 15);
    } else {
        acc = (acc - index_reg_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_43 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_43 > 20) {
        acc = (acc + coefficient_43 * 2 + 5) & 127;
        aux ^= (coefficient_43 & 15);
    } else {
        acc = (acc - coefficient_43 + 11) & 127;
        aux += 3;
    }
    int quantum_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001007_713_19(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int margin_80 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_80 > 36) {
        acc = (acc + margin_80 * 2 + 5) & 127;
        aux ^= (margin_80 & 15);
    } else {
        acc = (acc - margin_80 + 11) & 127;
        aux += 3;
    }
    int sample_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001007_713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_30 = 0;
    for (int k = 0; k < 2; k++) {
        scale_30 = (scale_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_30) & 127;
    }
    int anchor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_40 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_40 > 15) {
        acc = (acc + index_reg_40 * 2 + 5) & 127;
        aux ^= (index_reg_40 & 15);
    } else {
        acc = (acc - index_reg_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int factor_22 = local_arr[aux % 3];
    acc = (acc + factor_22 * 2) & 127;
    int metric_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_57) & 63;
    acc ^= aux;
    int sample_91 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_91 > 25) {
        acc = (acc + sample_91 * 2 + 5) & 127;
        aux ^= (sample_91 & 15);
    } else {
        acc = (acc - sample_91 + 11) & 127;
        aux += 3;
    }
    int accumulator_65 = (aux + st.buffer[1]) & 3;
    switch (accumulator_65) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001007_713_22(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_17 = 0;
    for (int k = 0; k < 3; k++) {
        delta_17 = (delta_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_17) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_91 = local_arr[aux % 3];
    acc = (acc + residue_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001007_713_23(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_36 = 0;
    for (int k = 0; k < 2; k++) {
        vector_36 = (vector_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_36) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_36 = local_arr[aux % 3];
    acc = (acc + index_reg_36 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001007_0;
    int sec_r001007_1;
    int sec_r001007_2;
    int sec_r001007_3;
    int sec_r001007_4;
    int sec_r001007_5;
    int sec_r001007_6;
    int sec_r001007_7;
    int sec_r001007_8;
    int sec_r001007_9;
    int sec_r001007_10;
    int sec_r001007_11;
    int sec_r001007_12;
    int sec_r001007_13;
    int sec_r001007_14;
    int sec_r001007_15;
    int sec_r001007_16;
    int sec_r001007_17;
    int sec_r001007_18;
    int sec_r001007_19;
    int pub_r001007_0;
    int pub_r001007_1;
    int pub_r001007_2;
    int pub_r001007_3;
    int pub_r001007_4;
    int pub_r001007_5;
    int pub_r001007_6;
    int pub_r001007_7;
    int pub_r001007_8;
    int pub_r001007_9;
    int pub_r001007_10;
    int pub_r001007_11;
    int pub_r001007_12;
    int pub_r001007_13;
    int pub_r001007_14;
    int pub_r001007_15;
    int pub_r001007_16;
    int pub_r001007_17;
    int pub_r001007_18;
    int pub_r001007_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001007_0 >= -100 && pub_r001007_0 <= 100);
    __CPROVER_assume(pub_r001007_1 >= -100 && pub_r001007_1 <= 100);
    __CPROVER_assume(pub_r001007_2 >= -100 && pub_r001007_2 <= 100);
    __CPROVER_assume(pub_r001007_3 >= -100 && pub_r001007_3 <= 100);
    __CPROVER_assume(pub_r001007_4 >= -100 && pub_r001007_4 <= 100);
    __CPROVER_assume(pub_r001007_5 >= -100 && pub_r001007_5 <= 100);
    __CPROVER_assume(pub_r001007_6 >= -100 && pub_r001007_6 <= 100);
    __CPROVER_assume(pub_r001007_7 >= -100 && pub_r001007_7 <= 100);
    __CPROVER_assume(pub_r001007_8 >= -100 && pub_r001007_8 <= 100);
    __CPROVER_assume(pub_r001007_9 >= -100 && pub_r001007_9 <= 100);
    __CPROVER_assume(pub_r001007_10 >= -100 && pub_r001007_10 <= 100);
    __CPROVER_assume(pub_r001007_11 >= -100 && pub_r001007_11 <= 100);
    __CPROVER_assume(pub_r001007_12 >= -100 && pub_r001007_12 <= 100);
    __CPROVER_assume(pub_r001007_13 >= -100 && pub_r001007_13 <= 100);
    __CPROVER_assume(pub_r001007_14 >= -100 && pub_r001007_14 <= 100);
    __CPROVER_assume(pub_r001007_15 >= -100 && pub_r001007_15 <= 100);
    __CPROVER_assume(pub_r001007_16 >= -100 && pub_r001007_16 <= 100);
    __CPROVER_assume(pub_r001007_17 >= -100 && pub_r001007_17 <= 100);
    __CPROVER_assume(pub_r001007_18 >= -100 && pub_r001007_18 <= 100);
    __CPROVER_assume(pub_r001007_19 >= -100 && pub_r001007_19 <= 100);
    __CPROVER_assume(sec_r001007_0 >= 0 && sec_r001007_0 <= 255);
    __CPROVER_assume(sec_r001007_1 >= 0 && sec_r001007_1 <= 255);
    __CPROVER_assume(sec_r001007_2 >= 0 && sec_r001007_2 <= 255);
    __CPROVER_assume(sec_r001007_3 >= 0 && sec_r001007_3 <= 255);
    __CPROVER_assume(sec_r001007_4 >= 0 && sec_r001007_4 <= 255);
    __CPROVER_assume(sec_r001007_5 >= 0 && sec_r001007_5 <= 255);
    __CPROVER_assume(sec_r001007_6 >= 0 && sec_r001007_6 <= 255);
    __CPROVER_assume(sec_r001007_7 >= 0 && sec_r001007_7 <= 255);
    __CPROVER_assume(sec_r001007_8 >= 0 && sec_r001007_8 <= 255);
    __CPROVER_assume(sec_r001007_9 >= 0 && sec_r001007_9 <= 255);
    __CPROVER_assume(sec_r001007_10 >= 0 && sec_r001007_10 <= 255);
    __CPROVER_assume(sec_r001007_11 >= 0 && sec_r001007_11 <= 255);
    __CPROVER_assume(sec_r001007_12 >= 0 && sec_r001007_12 <= 255);
    __CPROVER_assume(sec_r001007_13 >= 0 && sec_r001007_13 <= 255);
    __CPROVER_assume(sec_r001007_14 >= 0 && sec_r001007_14 <= 255);
    __CPROVER_assume(sec_r001007_15 >= 0 && sec_r001007_15 <= 255);
    __CPROVER_assume(sec_r001007_16 >= 0 && sec_r001007_16 <= 255);
    __CPROVER_assume(sec_r001007_17 >= 0 && sec_r001007_17 <= 255);
    __CPROVER_assume(sec_r001007_18 >= 0 && sec_r001007_18 <= 255);
    __CPROVER_assume(sec_r001007_19 >= 0 && sec_r001007_19 <= 255);

    struct StreamBuffer_R001007_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001007_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001007_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001007_0 + 7) & 15;
    struct AudioFrame_R001007_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001007_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001007_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001007_0 + 9) & 15;
    struct FilterState_R001007_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001007_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001007_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001007_0 + 11) & 15;
    struct Vector3D_R001007_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001007_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001007_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001007_0 + 13) & 15;

    union ColorPixel_R001007_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001007_713_0(sec_r001007_0, pub_r001007_1, pub_r001007_2, pub_r001007_3);
    int helper_flow_1 = fn_R001007_713_1(sec_r001007_1, pub_r001007_2);
    int helper_flow_2 = fn_R001007_713_2(sec_r001007_2, pub_r001007_3, pub_r001007_4);
    int helper_flow_3 = fn_R001007_713_3(sec_r001007_3, pub_r001007_4, pub_r001007_5, pub_r001007_6);
    int helper_flow_4 = fn_R001007_713_4(sec_r001007_4, sec_r001007_5, pub_r001007_6);
    int helper_flow_5 = fn_R001007_713_5(sec_r001007_5, pub_r001007_6, pub_r001007_7, pub_r001007_8, pub_r001007_9);
    int helper_flow_6 = fn_R001007_713_6(sec_r001007_6, pub_r001007_7, pub_r001007_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001007_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_6 ^ pub_r001007_15) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_0 ^ pub_r001007_13) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001007_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (stage_v_2 ^ pub_r001007_15) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001007_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001007_14 ^ pub_r001007_12) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001007_1 ^ pub_r001007_15) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_3 ^ pub_r001007_6) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001007_19 ^ pub_r001007_1) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001007_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001007_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_1 ^ pub_r001007_9) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001007_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001007_18 ^ pub_r001007_19) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001007_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001007_15 ^ pub_r001007_9) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_10 ^ pub_r001007_12) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001007_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001007_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001007_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001007_0 ^ pub_r001007_18) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_13 ^ pub_r001007_19) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001007_12 ^ pub_r001007_4) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001007_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001007_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001007_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_19 ^ pub_r001007_19) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_3 ^ pub_r001007_1) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001007_15 ^ pub_r001007_15) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001007_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_0 ^ pub_r001007_6) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_25 ^ pub_r001007_6) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001007_16 ^ pub_r001007_0) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_23 ^ pub_r001007_17) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001007_11 ^ pub_r001007_15) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001007_11 ^ pub_r001007_19) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001007_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_22 ^ pub_r001007_6) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_22 ^ pub_r001007_19) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001007_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001007_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001007_12 ^ pub_r001007_3) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_10 ^ pub_r001007_14) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001007_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_2 ^ pub_r001007_17) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001007_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001007_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001007_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001007_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001007_3 ^ pub_r001007_15) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_11 ^ pub_r001007_11) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001007_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001007_5 ^ pub_r001007_8) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_5 ^ pub_r001007_7) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001007_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001007_10 ^ pub_r001007_9) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_30 ^ pub_r001007_0) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001007_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_4 ^ pub_r001007_2) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001007_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001007_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001007_11 ^ pub_r001007_16) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_28 ^ pub_r001007_9) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001007_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_33 ^ pub_r001007_12) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001007_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001007_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001007_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_48 ^ pub_r001007_3) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_24 ^ pub_r001007_3) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_43 ^ pub_r001007_15) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_10 ^ pub_r001007_14) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_2 ^ pub_r001007_2) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001007_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_36 ^ pub_r001007_4) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001007_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_43 ^ pub_r001007_7) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r001007_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_26 ^ pub_r001007_5) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001007_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_54 ^ pub_r001007_0) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_5 ^ pub_r001007_5) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_53 ^ pub_r001007_7) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_69 ^ pub_r001007_4) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_36 ^ pub_r001007_3) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_0 ^ pub_r001007_0) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001007_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_70 ^ pub_r001007_5) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001007_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001007_17 ^ pub_r001007_17) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001007_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001007_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_6 ^ pub_r001007_18) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001007_2 ^ pub_r001007_10) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_2 ^ pub_r001007_3) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_58 ^ pub_r001007_10) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001007_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_26 ^ pub_r001007_15) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001007_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001007_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_26 ^ pub_r001007_1) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_30 ^ pub_r001007_8) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001007_2 ^ pub_r001007_7) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_64 ^ pub_r001007_12) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r001007_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001007_7 ^ pub_r001007_0) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_27 ^ pub_r001007_12) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001007_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_92 ^ pub_r001007_13) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001007_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_62 ^ pub_r001007_9) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001007_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001007_4 ^ pub_r001007_8) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_5 ^ pub_r001007_14) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001007_6 ^ pub_r001007_2) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_17 ^ pub_r001007_16) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001007_6 ^ pub_r001007_13) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_10 ^ pub_r001007_5) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_97 ^ pub_r001007_4) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_66 ^ pub_r001007_12) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001007_14 ^ pub_r001007_7) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_28 ^ pub_r001007_9) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_81 ^ pub_r001007_0) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_23 ^ pub_r001007_13) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_69 ^ pub_r001007_15) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_32 ^ pub_r001007_9) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r001007_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_17 ^ pub_r001007_1) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001007_13 ^ pub_r001007_14) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_37 ^ pub_r001007_12) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_19 ^ pub_r001007_15) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_101 ^ pub_r001007_5) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001007_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001007_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_11 ^ pub_r001007_6) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_26 ^ pub_r001007_13) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_99 ^ pub_r001007_15) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_64 ^ pub_r001007_5) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_119 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_28 ^ pub_r001007_6) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r001007_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001007_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_7 ^ pub_r001007_8) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001007_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001007_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_93 ^ pub_r001007_9) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001007_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001007_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_107 ^ pub_r001007_13) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001007_7 ^ pub_r001007_12) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001007_11 ^ pub_r001007_19) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_88 ^ pub_r001007_15) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001007_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001007_5 ^ pub_r001007_15) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_23 ^ pub_r001007_15) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001007_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (helper_flow_4 ^ pub_r001007_4) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001007_15 ^ pub_r001007_19) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_71 ^ pub_r001007_12) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_4 ^ pub_r001007_19) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_73 ^ pub_r001007_17) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_72 ^ pub_r001007_10) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_102 ^ pub_r001007_8) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_112 ^ pub_r001007_1) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_64 ^ pub_r001007_4) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r001007_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_10 ^ pub_r001007_17) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r001007_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_14 ^ pub_r001007_13) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_27 ^ pub_r001007_4) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_33 ^ pub_r001007_0) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_119 ^ pub_r001007_12) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_72 ^ pub_r001007_16) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001007_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_82 ^ pub_r001007_12) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r001007_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_75 ^ pub_r001007_18) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_104 ^ pub_r001007_1) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001007_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (helper_flow_2 ^ pub_r001007_17) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
