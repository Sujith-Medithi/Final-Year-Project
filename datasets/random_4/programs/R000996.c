/*
 * Benchmark Program: R000996
 * Family: mixed_control_data
 * Generator Seed: 499613
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000996_9613_0 {
    int peak;
    int channels;
    short rms;
    int envelope;
    unsigned char sample_rate;
    int buffer[3];
};

struct Transaction_R000996_9613_1 {
    short fee;
    int account_id;
    int auth_code;
    int status;
    int buffer[3];
};

struct FilterState_R000996_9613_2 {
    int mode;
    int cutoff;
    int prev_in;
    int damping;
    int gain_db;
    int buffer[3];
};

struct MatrixBlock_R000996_9613_3 {
    unsigned char determinant;
    unsigned char trace;
    int scale;
    short stride;
    int buffer[3];
};

union TelemetryField_R000996_9613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000996_9613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000996_9613_0(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_77 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_77 > 42) {
        acc = (acc + cursor_77 * 2 + 5) & 127;
        aux ^= (cursor_77 & 15);
    } else {
        acc = (acc - cursor_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_88 = local_arr[aux % 3];
    acc = (acc + mask_88 * 2) & 127;
    int scale_27 = 0;
    for (int k = 0; k < 3; k++) {
        scale_27 = (scale_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tally_71 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_71 > 36) {
        acc = (acc + tally_71 * 2 + 5) & 127;
        aux ^= (tally_71 & 15);
    } else {
        acc = (acc - tally_71 + 11) & 127;
        aux += 3;
    }
    int tracker_53 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_53 = (tracker_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_53) & 127;
    }
    int stride_83 = (aux + st.buffer[1]) & 3;
    switch (stride_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int segment_47 = local_arr[aux % 3];
    acc = (acc + segment_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_47 = (aux + st.buffer[1]) & 3;
    switch (threshold_47) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_97 = local_arr[aux % 3];
    acc = (acc + parity_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_4(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_95 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_95 > 18) {
        acc = (acc + tracker_95 * 2 + 5) & 127;
        aux ^= (tracker_95 & 15);
    } else {
        acc = (acc - tracker_95 + 11) & 127;
        aux += 3;
    }
    int margin_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000996_9613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_17 = (aux + st.buffer[1]) & 3;
    switch (factor_17) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int factor_93 = (aux + st.buffer[1]) & 3;
    switch (factor_93) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_92 = local_arr[aux % 3];
    acc = (acc + anchor_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_7(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_25) & 63;
    acc ^= aux;
    int threshold_95 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_95 = (threshold_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_95) & 127;
    }
    int quotient_30 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_30 > 46) {
        acc = (acc + quotient_30 * 2 + 5) & 127;
        aux ^= (quotient_30 & 15);
    } else {
        acc = (acc - quotient_30 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int window_95 = local_arr[aux % 3];
    acc = (acc + window_95 * 2) & 127;
    int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_81) & 63;
    acc ^= aux;
    int cursor_84 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_84 > 39) {
        acc = (acc + cursor_84 * 2 + 5) & 127;
        aux ^= (cursor_84 & 15);
    } else {
        acc = (acc - cursor_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int window_70 = 0;
    for (int k = 0; k < 2; k++) {
        window_70 = (window_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_70) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_76 = local_arr[aux % 3];
    acc = (acc + checksum_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_27 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_27 > 29) {
        acc = (acc + phase_27 * 2 + 5) & 127;
        aux ^= (phase_27 & 15);
    } else {
        acc = (acc - phase_27 + 11) & 127;
        aux += 3;
    }
    int parity_66 = 0;
    for (int k = 0; k < 3; k++) {
        parity_66 = (parity_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_66) & 127;
    }
    int vector_82 = (aux + st.buffer[1]) & 3;
    switch (vector_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_11(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int sample_30 = local_arr[aux % 3];
    acc = (acc + sample_30 * 2) & 127;
    int index_reg_35 = (aux + st.buffer[1]) & 3;
    switch (index_reg_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_35) & 63;
    acc ^= aux;
    int scale_64 = 0;
    for (int k = 0; k < 2; k++) {
        scale_64 = (scale_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_46) & 63;
    acc ^= aux;
    int tracker_96 = (aux + st.buffer[1]) & 3;
    switch (tracker_96) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_14(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int index_reg_77 = local_arr[aux % 3];
    acc = (acc + index_reg_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_15(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int delta_60 = local_arr[aux % 3];
    acc = (acc + delta_60 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000996_9613_16(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_86 = (aux + st.buffer[1]) & 3;
    switch (threshold_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_36 = local_arr[aux % 3];
    acc = (acc + accumulator_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000996_9613_17(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000996_9613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_22) & 63;
    acc ^= aux;
    int weight_56 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_56 > 45) {
        acc = (acc + weight_56 * 2 + 5) & 127;
        aux ^= (weight_56 & 15);
    } else {
        acc = (acc - weight_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000996_9613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_71 = (aux + st.buffer[1]) & 3;
    switch (cursor_71) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_34 = local_arr[aux % 3];
    acc = (acc + offset_34 * 2) & 127;
    int offset_60 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_60 > 42) {
        acc = (acc + offset_60 * 2 + 5) & 127;
        aux ^= (offset_60 & 15);
    } else {
        acc = (acc - offset_60 + 11) & 127;
        aux += 3;
    }
    int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000996_9613_19(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_51 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_51 > 38) {
        acc = (acc + quotient_51 * 2 + 5) & 127;
        aux ^= (quotient_51 & 15);
    } else {
        acc = (acc - quotient_51 + 11) & 127;
        aux += 3;
    }
    int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000996_9613_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int threshold_65 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_65 > 40) {
        acc = (acc + threshold_65 * 2 + 5) & 127;
        aux ^= (threshold_65 & 15);
    } else {
        acc = (acc - threshold_65 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_75 = local_arr[aux % 3];
    acc = (acc + threshold_75 * 2) & 127;
    int scale_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000996_0;
    int sec_r000996_1;
    int sec_r000996_2;
    int sec_r000996_3;
    int sec_r000996_4;
    int sec_r000996_5;
    int sec_r000996_6;
    int sec_r000996_7;
    int sec_r000996_8;
    int sec_r000996_9;
    int sec_r000996_10;
    int sec_r000996_11;
    int sec_r000996_12;
    int sec_r000996_13;
    int sec_r000996_14;
    int sec_r000996_15;
    int sec_r000996_16;
    int sec_r000996_17;
    int sec_r000996_18;
    int sec_r000996_19;
    int sec_r000996_20;
    int pub_r000996_0;
    int pub_r000996_1;
    int pub_r000996_2;
    int pub_r000996_3;
    int pub_r000996_4;
    int pub_r000996_5;
    int pub_r000996_6;
    int pub_r000996_7;
    int pub_r000996_8;
    int pub_r000996_9;
    int pub_r000996_10;
    int pub_r000996_11;
    int pub_r000996_12;
    int pub_r000996_13;
    int pub_r000996_14;
    int pub_r000996_15;
    int pub_r000996_16;
    int pub_r000996_17;
    int pub_r000996_18;
    int pub_r000996_19;
    int pub_r000996_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000996_0 >= -100 && pub_r000996_0 <= 100);
    __CPROVER_assume(pub_r000996_1 >= -100 && pub_r000996_1 <= 100);
    __CPROVER_assume(pub_r000996_2 >= -100 && pub_r000996_2 <= 100);
    __CPROVER_assume(pub_r000996_3 >= -100 && pub_r000996_3 <= 100);
    __CPROVER_assume(pub_r000996_4 >= -100 && pub_r000996_4 <= 100);
    __CPROVER_assume(pub_r000996_5 >= -100 && pub_r000996_5 <= 100);
    __CPROVER_assume(pub_r000996_6 >= -100 && pub_r000996_6 <= 100);
    __CPROVER_assume(pub_r000996_7 >= -100 && pub_r000996_7 <= 100);
    __CPROVER_assume(pub_r000996_8 >= -100 && pub_r000996_8 <= 100);
    __CPROVER_assume(pub_r000996_9 >= -100 && pub_r000996_9 <= 100);
    __CPROVER_assume(pub_r000996_10 >= -100 && pub_r000996_10 <= 100);
    __CPROVER_assume(pub_r000996_11 >= -100 && pub_r000996_11 <= 100);
    __CPROVER_assume(pub_r000996_12 >= -100 && pub_r000996_12 <= 100);
    __CPROVER_assume(pub_r000996_13 >= -100 && pub_r000996_13 <= 100);
    __CPROVER_assume(pub_r000996_14 >= -100 && pub_r000996_14 <= 100);
    __CPROVER_assume(pub_r000996_15 >= -100 && pub_r000996_15 <= 100);
    __CPROVER_assume(pub_r000996_16 >= -100 && pub_r000996_16 <= 100);
    __CPROVER_assume(pub_r000996_17 >= -100 && pub_r000996_17 <= 100);
    __CPROVER_assume(pub_r000996_18 >= -100 && pub_r000996_18 <= 100);
    __CPROVER_assume(pub_r000996_19 >= -100 && pub_r000996_19 <= 100);
    __CPROVER_assume(pub_r000996_20 >= -100 && pub_r000996_20 <= 100);
    __CPROVER_assume(sec_r000996_0 >= 0 && sec_r000996_0 <= 255);
    __CPROVER_assume(sec_r000996_1 >= 0 && sec_r000996_1 <= 255);
    __CPROVER_assume(sec_r000996_2 >= 0 && sec_r000996_2 <= 255);
    __CPROVER_assume(sec_r000996_3 >= 0 && sec_r000996_3 <= 255);
    __CPROVER_assume(sec_r000996_4 >= 0 && sec_r000996_4 <= 255);
    __CPROVER_assume(sec_r000996_5 >= 0 && sec_r000996_5 <= 255);
    __CPROVER_assume(sec_r000996_6 >= 0 && sec_r000996_6 <= 255);
    __CPROVER_assume(sec_r000996_7 >= 0 && sec_r000996_7 <= 255);
    __CPROVER_assume(sec_r000996_8 >= 0 && sec_r000996_8 <= 255);
    __CPROVER_assume(sec_r000996_9 >= 0 && sec_r000996_9 <= 255);
    __CPROVER_assume(sec_r000996_10 >= 0 && sec_r000996_10 <= 255);
    __CPROVER_assume(sec_r000996_11 >= 0 && sec_r000996_11 <= 255);
    __CPROVER_assume(sec_r000996_12 >= 0 && sec_r000996_12 <= 255);
    __CPROVER_assume(sec_r000996_13 >= 0 && sec_r000996_13 <= 255);
    __CPROVER_assume(sec_r000996_14 >= 0 && sec_r000996_14 <= 255);
    __CPROVER_assume(sec_r000996_15 >= 0 && sec_r000996_15 <= 255);
    __CPROVER_assume(sec_r000996_16 >= 0 && sec_r000996_16 <= 255);
    __CPROVER_assume(sec_r000996_17 >= 0 && sec_r000996_17 <= 255);
    __CPROVER_assume(sec_r000996_18 >= 0 && sec_r000996_18 <= 255);
    __CPROVER_assume(sec_r000996_19 >= 0 && sec_r000996_19 <= 255);
    __CPROVER_assume(sec_r000996_20 >= 0 && sec_r000996_20 <= 255);

    struct AudioFrame_R000996_9613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000996_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000996_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000996_0 + 7) & 15;
    struct Transaction_R000996_9613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000996_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000996_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000996_0 + 9) & 15;
    struct FilterState_R000996_9613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000996_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000996_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000996_0 + 11) & 15;
    struct MatrixBlock_R000996_9613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000996_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000996_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000996_0 + 13) & 15;

    union TelemetryField_R000996_9613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 13) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 28) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 19) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 34) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 12) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 27) {
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
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
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
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 32) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 47) {
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
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
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
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 36) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 35) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 50) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 10) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 25) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 23) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 38) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 16) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 31) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 35) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 50) {
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
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 30) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 45) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 40) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 55) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 10) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 25) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 14) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 29) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 11) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 26) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_2.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 19) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 34) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_3.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 20) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 35) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 34) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 49) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = table[3];
    table[3] = (table[0] + 199) & 63;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_2.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_2.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 17) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 32) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_3.buffer[0] ^ 110) & 3;
    switch (stage_v_107) {
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

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 35) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 50) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 30) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 45) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_115 = (stage_v_115 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_3.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 12) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 27) {
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
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 25) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 40) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_3.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 15) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 30) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 26) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 41) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_2.buffer[0] * 2 + 421) & 63;
    if (stage_v_138 > 21) {
        out_sink = (out_sink + stage_v_138 - 5) & 255;
        if (stage_v_138 > 36) {
            chk_sum ^= (stage_v_138 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_138 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_3.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 17) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 32) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_142 = (st_var_2.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 10) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 25) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 21) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 36) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_153 = (stage_v_153 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 31) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 46) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 10) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 25) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 30) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 45) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_3.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_2.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 48) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 17) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 32) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_2.buffer[1] * 2 + 505) & 63;
    if (stage_v_166 > 26) {
        out_sink = (out_sink + stage_v_166 - 5) & 255;
        if (stage_v_166 > 41) {
            chk_sum ^= (stage_v_166 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_166 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 170) & 15;
    int stage_v_169 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= stage_v_169;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_3.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 26) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 41) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_0.buffer[1] * 2 + 523) & 63;
    if (stage_v_172 > 28) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 43) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_3.buffer[0] ^ 178) & 3;
    switch (stage_v_175) {
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

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_0.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 15) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 30) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] ^ 180) & 3;
    switch (stage_v_177) {
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

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000996_12 ^ 0x55) & 63;
    if (m_var > 32) {
        out_sink += (m_var * 2 + pub_r000996_9) & 127;
    } else {
        out_sink -= (m_var + 6) & 31;
    }
    out_sink ^= (sec_r000996_2 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
