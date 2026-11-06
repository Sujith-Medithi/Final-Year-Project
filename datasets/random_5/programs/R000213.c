/*
 * Benchmark Program: R000213
 * Security Family: multi_step_explicit
 * Generator Seed: 521313
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000213_1313_0 {
    int code;
    int timestamp;
    int signature;
    int buffer[3];
};

struct Vector3D_R000213_1313_1 {
    unsigned char norm_sq;
    short pitch;
    short coord_y;
    short coord_x;
    int buffer[3];
};

struct StreamBuffer_R000213_1313_2 {
    int tail;
    short checksum;
    int watermark;
    int buffer[3];
};

struct MatrixBlock_R000213_1313_3 {
    short determinant;
    unsigned char stride;
    int density;
    int dim;
    int scale;
    int trace;
    int buffer[3];
};

union RegisterBank_R000213_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000213_1313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000213_1313_0(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_75 = (aux + st.buffer[1]) & 3;
    switch (checksum_75) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000213_1313_1(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000213_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = (aux + st.buffer[1]) & 3;
    switch (tally_80) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_40 > 43) {
        acc = (acc + tracker_40 * 2 + 5) & 127;
        aux ^= (tracker_40 & 15);
    } else {
        acc = (acc - tracker_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_36 = local_arr[aux % 3];
    acc = (acc + tally_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_2(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000213_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_56 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_56 > 30) {
        acc = (acc + pivot_56 * 2 + 5) & 127;
        aux ^= (pivot_56 & 15);
    } else {
        acc = (acc - pivot_56 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_85 = local_arr[aux % 3];
    acc = (acc + metric_85 * 2) & 127;
    int stride_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_3(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000213_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int cursor_96 = local_arr[aux % 3];
    acc = (acc + cursor_96 * 2) & 127;
    int factor_81 = (aux + st.buffer[1]) & 3;
    switch (factor_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_40 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_40 > 45) {
        acc = (acc + checksum_40 * 2 + 5) & 127;
        aux ^= (checksum_40 & 15);
    } else {
        acc = (acc - checksum_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_4(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_68 > 19) {
        acc = (acc + cursor_68 * 2 + 5) & 127;
        aux ^= (cursor_68 & 15);
    } else {
        acc = (acc - cursor_68 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_56 = local_arr[aux % 3];
    acc = (acc + phase_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_5(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_89 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_89 > 45) {
        acc = (acc + cursor_89 * 2 + 5) & 127;
        aux ^= (cursor_89 & 15);
    } else {
        acc = (acc - cursor_89 + 11) & 127;
        aux += 3;
    }
    int factor_33 = (aux + st.buffer[1]) & 3;
    switch (factor_33) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_6(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int mask_41 = local_arr[aux % 3];
    acc = (acc + mask_41 * 2) & 127;
    int tracker_23 = (aux + st.buffer[1]) & 3;
    switch (tracker_23) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000213_1313_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tally_30 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_30 > 48) {
        acc = (acc + tally_30 * 2 + 5) & 127;
        aux ^= (tally_30 & 15);
    } else {
        acc = (acc - tally_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_27 = local_arr[aux % 3];
    acc = (acc + tally_27 * 2) & 127;
    int index_reg_51 = (aux + st.buffer[1]) & 3;
    switch (index_reg_51) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_8(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000213_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_34 > 50) {
        acc = (acc + coefficient_34 * 2 + 5) & 127;
        aux ^= (coefficient_34 & 15);
    } else {
        acc = (acc - coefficient_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000213_1313_9(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_85 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_85 > 15) {
        acc = (acc + stride_85 * 2 + 5) & 127;
        aux ^= (stride_85 & 15);
    } else {
        acc = (acc - stride_85 + 11) & 127;
        aux += 3;
    }
    int tally_68 = (aux + st.buffer[1]) & 3;
    switch (tally_68) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_10(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_51) & 63;
    acc ^= aux;
    int weight_42 = (aux + st.buffer[1]) & 3;
    switch (weight_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_74 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_74 > 25) {
        acc = (acc + weight_74 * 2 + 5) & 127;
        aux ^= (weight_74 & 15);
    } else {
        acc = (acc - weight_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_35 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_35 > 14) {
        acc = (acc + scale_35 * 2 + 5) & 127;
        aux ^= (scale_35 & 15);
    } else {
        acc = (acc - scale_35 + 11) & 127;
        aux += 3;
    }
    int cursor_67 = (aux + st.buffer[1]) & 3;
    switch (cursor_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_69 = local_arr[aux % 3];
    acc = (acc + cursor_69 * 2) & 127;
    int mask_81 = (aux + st.buffer[1]) & 3;
    switch (mask_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000213_1313_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_46 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_46 > 24) {
        acc = (acc + damping_46 * 2 + 5) & 127;
        aux ^= (damping_46 & 15);
    } else {
        acc = (acc - damping_46 + 11) & 127;
        aux += 3;
    }
    int coefficient_95 = (aux + st.buffer[1]) & 3;
    switch (coefficient_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_35) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_80 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_80 > 37) {
        acc = (acc + sample_80 * 2 + 5) & 127;
        aux ^= (sample_80 & 15);
    } else {
        acc = (acc - sample_80 + 11) & 127;
        aux += 3;
    }
    int index_reg_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000213_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int threshold_32 = (aux + st.buffer[1]) & 3;
    switch (threshold_32) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_39 = (st.buffer[0] * 3 + aux) & 63;
    if (window_39 > 11) {
        acc = (acc + window_39 * 2 + 5) & 127;
        aux ^= (window_39 & 15);
    } else {
        acc = (acc - window_39 + 11) & 127;
        aux += 3;
    }
    int index_reg_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000213_1313_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000213_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int window_14 = (st.buffer[0] * 3 + aux) & 63;
    if (window_14 > 13) {
        acc = (acc + window_14 * 2 + 5) & 127;
        aux ^= (window_14 & 15);
    } else {
        acc = (acc - window_14 + 11) & 127;
        aux += 3;
    }
    int pivot_35 = (aux + st.buffer[1]) & 3;
    switch (pivot_35) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000213_1313_17(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000213_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int segment_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_89) & 63;
    acc ^= aux;
    int margin_18 = (aux + st.buffer[1]) & 3;
    switch (margin_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_15 = local_arr[aux % 3];
    acc = (acc + bound_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000213_1313_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000213_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int tally_20 = local_arr[aux % 3];
    acc = (acc + tally_20 * 2) & 127;
    int phase_75 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_75 > 44) {
        acc = (acc + phase_75 * 2 + 5) & 127;
        aux ^= (phase_75 & 15);
    } else {
        acc = (acc - phase_75 + 11) & 127;
        aux += 3;
    }
    int parity_60 = (aux + st.buffer[1]) & 3;
    switch (parity_60) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000213_0;
    int sec_r000213_1;
    int sec_r000213_2;
    int sec_r000213_3;
    int sec_r000213_4;
    int sec_r000213_5;
    int sec_r000213_6;
    int sec_r000213_7;
    int sec_r000213_8;
    int sec_r000213_9;
    int sec_r000213_10;
    int sec_r000213_11;
    int sec_r000213_12;
    int sec_r000213_13;
    int sec_r000213_14;
    int sec_r000213_15;
    int sec_r000213_16;
    int sec_r000213_17;
    int sec_r000213_18;
    int pub_r000213_0;
    int pub_r000213_1;
    int pub_r000213_2;
    int pub_r000213_3;
    int pub_r000213_4;
    int pub_r000213_5;
    int pub_r000213_6;
    int pub_r000213_7;
    int pub_r000213_8;
    int pub_r000213_9;
    int pub_r000213_10;
    int pub_r000213_11;
    int pub_r000213_12;
    int pub_r000213_13;
    int pub_r000213_14;
    int pub_r000213_15;
    int pub_r000213_16;
    int pub_r000213_17;
    int pub_r000213_18;
    int pub_r000213_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000213_0 >= -100 && pub_r000213_0 <= 100);
    __CPROVER_assume(pub_r000213_1 >= -100 && pub_r000213_1 <= 100);
    __CPROVER_assume(pub_r000213_2 >= -100 && pub_r000213_2 <= 100);
    __CPROVER_assume(pub_r000213_3 >= -100 && pub_r000213_3 <= 100);
    __CPROVER_assume(pub_r000213_4 >= -100 && pub_r000213_4 <= 100);
    __CPROVER_assume(pub_r000213_5 >= -100 && pub_r000213_5 <= 100);
    __CPROVER_assume(pub_r000213_6 >= -100 && pub_r000213_6 <= 100);
    __CPROVER_assume(pub_r000213_7 >= -100 && pub_r000213_7 <= 100);
    __CPROVER_assume(pub_r000213_8 >= -100 && pub_r000213_8 <= 100);
    __CPROVER_assume(pub_r000213_9 >= -100 && pub_r000213_9 <= 100);
    __CPROVER_assume(pub_r000213_10 >= -100 && pub_r000213_10 <= 100);
    __CPROVER_assume(pub_r000213_11 >= -100 && pub_r000213_11 <= 100);
    __CPROVER_assume(pub_r000213_12 >= -100 && pub_r000213_12 <= 100);
    __CPROVER_assume(pub_r000213_13 >= -100 && pub_r000213_13 <= 100);
    __CPROVER_assume(pub_r000213_14 >= -100 && pub_r000213_14 <= 100);
    __CPROVER_assume(pub_r000213_15 >= -100 && pub_r000213_15 <= 100);
    __CPROVER_assume(pub_r000213_16 >= -100 && pub_r000213_16 <= 100);
    __CPROVER_assume(pub_r000213_17 >= -100 && pub_r000213_17 <= 100);
    __CPROVER_assume(pub_r000213_18 >= -100 && pub_r000213_18 <= 100);
    __CPROVER_assume(pub_r000213_19 >= -100 && pub_r000213_19 <= 100);
    __CPROVER_assume(sec_r000213_0 >= 0 && sec_r000213_0 <= 255);
    __CPROVER_assume(sec_r000213_1 >= 0 && sec_r000213_1 <= 255);
    __CPROVER_assume(sec_r000213_2 >= 0 && sec_r000213_2 <= 255);
    __CPROVER_assume(sec_r000213_3 >= 0 && sec_r000213_3 <= 255);
    __CPROVER_assume(sec_r000213_4 >= 0 && sec_r000213_4 <= 255);
    __CPROVER_assume(sec_r000213_5 >= 0 && sec_r000213_5 <= 255);
    __CPROVER_assume(sec_r000213_6 >= 0 && sec_r000213_6 <= 255);
    __CPROVER_assume(sec_r000213_7 >= 0 && sec_r000213_7 <= 255);
    __CPROVER_assume(sec_r000213_8 >= 0 && sec_r000213_8 <= 255);
    __CPROVER_assume(sec_r000213_9 >= 0 && sec_r000213_9 <= 255);
    __CPROVER_assume(sec_r000213_10 >= 0 && sec_r000213_10 <= 255);
    __CPROVER_assume(sec_r000213_11 >= 0 && sec_r000213_11 <= 255);
    __CPROVER_assume(sec_r000213_12 >= 0 && sec_r000213_12 <= 255);
    __CPROVER_assume(sec_r000213_13 >= 0 && sec_r000213_13 <= 255);
    __CPROVER_assume(sec_r000213_14 >= 0 && sec_r000213_14 <= 255);
    __CPROVER_assume(sec_r000213_15 >= 0 && sec_r000213_15 <= 255);
    __CPROVER_assume(sec_r000213_16 >= 0 && sec_r000213_16 <= 255);
    __CPROVER_assume(sec_r000213_17 >= 0 && sec_r000213_17 <= 255);
    __CPROVER_assume(sec_r000213_18 >= 0 && sec_r000213_18 <= 255);

    struct EventLog_R000213_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000213_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000213_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000213_0 + 7) & 15;
    struct Vector3D_R000213_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000213_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000213_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000213_0 + 9) & 15;
    struct StreamBuffer_R000213_1313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000213_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000213_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000213_0 + 11) & 15;
    struct MatrixBlock_R000213_1313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000213_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000213_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000213_0 + 13) & 15;

    union RegisterBank_R000213_1313_0 u_var;
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
    if (stage_v_1 > 38) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 53) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

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
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 37) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 52) {
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
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 36) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 51) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
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
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 13) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 28) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 17) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 32) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
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
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 35) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 50) {
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
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 18) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 33) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 27) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 42) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 19) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 34) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 35) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 50) {
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
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 25) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 40) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

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
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 29) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 44) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 33) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 48) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_3.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sec_r000213_4 + pub_r000213_15 + 29) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000213_11) & 127;
    st_var_2.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (stage_v_90 + pub_r000213_15 + 21) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000213_15) & 127;
    st_var_3.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (stage_v_91 + pub_r000213_8 + 5) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000213_10) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (stage_v_90 + pub_r000213_6 + 35) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000213_10) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (stage_v_93 + pub_r000213_18 + 11) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000213_11) & 127;
    st_var_2.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sec_r000213_9 + pub_r000213_8 + 15) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000213_18) & 127;
    st_var_3.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000213_6 + pub_r000213_6 + 21) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000213_13) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sec_r000213_18 + pub_r000213_5 + 6) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000213_6) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sec_r000213_6 + pub_r000213_2 + 16) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000213_8) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (stage_v_92 + pub_r000213_4 + 34) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000213_8) & 127;
    st_var_3.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sec_r000213_6 + pub_r000213_14 + 8) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000213_13) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (stage_v_100 + pub_r000213_4 + 33) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000213_5) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (stage_v_95 + pub_r000213_6 + 23) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000213_7) & 127;
    st_var_2.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000213_1 + pub_r000213_6 + 12) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000213_12) & 127;
    st_var_3.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_93 + pub_r000213_14 + 13) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000213_17) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sec_r000213_12 + pub_r000213_6 + 28) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000213_12) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_94 + pub_r000213_12 + 18) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000213_10) & 127;
    st_var_2.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sub_step_101 + pub_r000213_13 + 10) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000213_17) & 127;
    st_var_3.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (stage_v_93 + pub_r000213_19 + 33) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000213_13) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sec_r000213_18 + pub_r000213_7 + 21) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000213_8) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_94 + pub_r000213_4 + 18) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000213_18) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (stage_v_90 + pub_r000213_6 + 18) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000213_6) & 127;
    st_var_3.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (stage_v_111 + pub_r000213_12 + 32) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000213_4) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000213_4 + pub_r000213_7 + 20) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000213_19) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_91 + pub_r000213_17 + 9) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000213_18) & 127;
    st_var_2.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_112 + pub_r000213_15 + 31) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000213_17) & 127;
    st_var_3.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sec_r000213_8 + pub_r000213_11 + 22) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000213_1) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sec_r000213_2 + pub_r000213_10 + 26) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000213_8) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (stage_v_95 + pub_r000213_15 + 33) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000213_18) & 127;
    st_var_2.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (stage_v_114 + pub_r000213_10 + 19) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000213_10) & 127;
    st_var_3.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sub_step_109 + pub_r000213_17 + 21) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000213_6) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sub_step_91 + pub_r000213_8 + 15) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000213_19) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000213_9 + pub_r000213_13 + 34) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000213_8) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000213_3 + pub_r000213_13 + 20) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000213_0) & 127;
    st_var_3.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sec_r000213_15 + pub_r000213_8 + 6) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000213_19) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (stage_v_98 + pub_r000213_10 + 18) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000213_9) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (sub_step_118 + pub_r000213_4 + 16) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000213_8) & 127;
    st_var_2.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (stage_v_111 + pub_r000213_18 + 19) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000213_0) & 127;
    st_var_3.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_125 + pub_r000213_6 + 16) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000213_10) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (stage_v_120 + pub_r000213_0 + 33) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000213_9) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sub_step_102 + pub_r000213_6 + 31) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000213_10) & 127;
    st_var_2.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000213_0 + pub_r000213_18 + 32) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000213_1) & 127;
    st_var_3.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_93 + pub_r000213_12 + 7) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000213_8) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_109 + pub_r000213_10 + 11) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000213_18) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sec_r000213_15 + pub_r000213_8 + 31) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000213_7) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_120 + pub_r000213_7 + 20) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000213_16) & 127;
    st_var_3.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (stage_v_114 + pub_r000213_15 + 21) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000213_1) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sec_r000213_7 + pub_r000213_1 + 11) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000213_2) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (stage_v_98 + pub_r000213_0 + 12) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000213_16) & 127;
    st_var_2.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_129 + pub_r000213_6 + 16) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000213_7) & 127;
    st_var_3.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sub_step_130 + pub_r000213_12 + 16) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000213_6) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sec_r000213_18 + pub_r000213_0 + 13) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000213_2) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sub_step_90 + pub_r000213_11 + 26) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000213_9) & 127;
    st_var_2.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000213_4 + pub_r000213_16 + 34) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000213_9) & 127;
    st_var_3.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_100 + pub_r000213_16 + 23) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000213_14) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sec_r000213_14 + pub_r000213_1 + 24) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000213_4) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (stage_v_101 + pub_r000213_9 + 12) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000213_1) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sub_step_146 + pub_r000213_13 + 27) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000213_6) & 127;
    st_var_3.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000213_5 + pub_r000213_13 + 20) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000213_11) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sec_r000213_3 + pub_r000213_17 + 8) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000213_4) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sub_step_111 + pub_r000213_8 + 24) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000213_12) & 127;
    st_var_2.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000213_0 + pub_r000213_4 + 23) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000213_0) & 127;
    st_var_3.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (stage_v_116 + pub_r000213_18 + 18) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000213_14) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_132 + pub_r000213_5 + 14) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000213_4) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_135 + pub_r000213_1 + 24) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000213_6) & 127;
    st_var_2.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000213_2 + pub_r000213_14 + 35) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000213_6) & 127;
    st_var_3.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000213_14 + pub_r000213_15 + 17) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000213_12) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (stage_v_153 + pub_r000213_10 + 18) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000213_13) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (stage_v_95 + pub_r000213_16 + 9) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000213_17) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000213_17 + pub_r000213_10 + 25) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000213_4) & 127;
    st_var_3.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sub_step_95 + pub_r000213_8 + 10) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000213_7) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (stage_v_96 + pub_r000213_15 + 9) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000213_15) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (stage_v_152 + pub_r000213_18 + 19) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000213_1) & 127;
    st_var_2.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_99 + pub_r000213_3 + 27) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000213_7) & 127;
    st_var_3.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000213_4 + pub_r000213_19 + 13) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000213_3) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_127 + pub_r000213_10 + 6) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000213_17) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sub_step_116 + pub_r000213_1 + 32) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000213_5) & 127;
    st_var_2.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (stage_v_94 + pub_r000213_15 + 33) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000213_9) & 127;
    st_var_3.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sub_step_143 + pub_r000213_14 + 10) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000213_17) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sub_step_105 + pub_r000213_2 + 32) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000213_11) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_124 + pub_r000213_9 + 27) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000213_2) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (stage_v_105 + pub_r000213_18 + 34) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000213_2) & 127;
    st_var_3.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (stage_v_96 + pub_r000213_19 + 22) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000213_1) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sub_step_149 + pub_r000213_17 + 25) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000213_19) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sub_step_103 + pub_r000213_16 + 17) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000213_10) & 127;
    st_var_2.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_152 + pub_r000213_14 + 11) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000213_15) & 127;
    st_var_3.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sec_r000213_17 + pub_r000213_4 + 5) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000213_2) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sec_r000213_4 + pub_r000213_2 + 16) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000213_10) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sub_step_140 + pub_r000213_7 + 24) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000213_9) & 127;
    st_var_2.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000213_17 + pub_r000213_1 + 24) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000213_7) & 127;
    st_var_3.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (stage_v_177 + pub_r000213_9 + 18) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000213_19) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sec_r000213_1 + pub_r000213_12 + 10) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000213_9) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_118 + pub_r000213_8 + 30) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000213_14) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sub_step_130 + pub_r000213_16 + 24) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000213_3) & 127;
    st_var_3.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (stage_v_183 + pub_r000213_10 + 15) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000213_10) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000213_5 + pub_r000213_17 + 35) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000213_13) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (stage_v_183 + pub_r000213_7 + 33) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000213_6) & 127;
    st_var_2.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (stage_v_169 + pub_r000213_15 + 7) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000213_7) & 127;
    st_var_3.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_186 + pub_r000213_14 + 32) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000213_3) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sec_r000213_10 + pub_r000213_14 + 24) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000213_2) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (stage_v_107 + pub_r000213_3 + 30) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000213_9) & 127;
    st_var_2.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (sub_step_151 + pub_r000213_7 + 27) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000213_9) & 127;
    st_var_3.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (stage_v_153 + pub_r000213_12 + 29) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000213_14) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000213_17 + pub_r000213_10 + 5) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000213_3) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_143 + pub_r000213_19 + 9) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000213_7) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000213_11 + pub_r000213_15 + 19) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000213_19) & 127;
    st_var_3.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sub_step_119 + pub_r000213_16 + 27) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000213_0) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sub_step_98 + pub_r000213_13 + 26) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000213_6) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sec_r000213_16 + pub_r000213_6 + 24) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000213_8) & 127;
    st_var_2.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_191 + pub_r000213_0 + 9) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000213_3) & 127;
    st_var_3.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_169 + pub_r000213_8 + 34) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000213_12) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000213_0 + pub_r000213_1 + 6) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000213_17) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sub_step_99 + pub_r000213_14 + 6) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000213_6) & 127;
    st_var_2.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (stage_v_115 + pub_r000213_4 + 30) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000213_7) & 127;
    st_var_3.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000213_2 + pub_r000213_16 + 10) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000213_12) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sec_r000213_5 + pub_r000213_4 + 28) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000213_14) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sub_step_198 + pub_r000213_8 + 22) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000213_5) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (stage_v_181 + pub_r000213_8 + 34) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000213_5) & 127;
    st_var_3.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (stage_v_189 + pub_r000213_5 + 14) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000213_17) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sec_r000213_17 + pub_r000213_13 + 9) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000213_4) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sec_r000213_10 + pub_r000213_1 + 25) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000213_1) & 127;
    st_var_2.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000213_10 + pub_r000213_11 + 10) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000213_12) & 127;
    st_var_3.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (stage_v_108 + pub_r000213_7 + 8) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000213_8) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sub_step_124 + pub_r000213_16 + 19) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000213_16) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_176 + pub_r000213_1 + 25) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000213_13) & 127;
    st_var_2.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (stage_v_181 + pub_r000213_0 + 7) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000213_9) & 127;
    st_var_3.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (stage_v_147 + pub_r000213_12 + 18) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000213_6) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sec_r000213_18 + pub_r000213_0 + 8) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000213_2) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_205 + pub_r000213_19 + 12) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000213_1) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000213_13 + pub_r000213_2 + 19) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000213_4) & 127;
    st_var_3.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sub_step_101 + pub_r000213_5 + 35) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000213_18) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_185 + pub_r000213_1 + 28) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000213_4) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_110 + pub_r000213_19 + 22) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000213_0) & 127;
    st_var_2.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000213_15 + pub_r000213_12 + 19) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000213_15) & 127;
    st_var_3.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000213_0 + pub_r000213_3 + 11) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000213_5) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_108 + pub_r000213_7 + 34) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000213_2) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
