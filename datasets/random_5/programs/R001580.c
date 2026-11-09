/*
 * Benchmark Program: R001580
 * Security Family: mixed_control_data
 * Generator Seed: 658013
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001580_8013_0 {
    int gain;
    short sample_rate;
    int peak;
    int channels;
    int buffer[3];
};

struct FilterState_R001580_8013_1 {
    int prev_in;
    unsigned char mode;
    short damping;
    int cutoff;
    int buffer[3];
};

struct Transaction_R001580_8013_2 {
    int account_id;
    short rate;
    int status;
    unsigned char balance;
    unsigned char fee;
    short auth_code;
    int buffer[3];
};

union RegisterBank_R001580_8013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001580_8013_0(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_87 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_87 > 13) {
        acc = (acc + anchor_87 * 2 + 5) & 127;
        aux ^= (anchor_87 & 15);
    } else {
        acc = (acc - anchor_87 + 11) & 127;
        aux += 3;
    }
    int delta_83 = (aux + st.buffer[1]) & 3;
    switch (delta_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_13 = 0;
    for (int k = 0; k < 2; k++) {
        offset_13 = (offset_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int metric_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_22) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_33 = local_arr[aux % 3];
    acc = (acc + pivot_33 * 2) & 127;
    int metric_56 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_56 > 11) {
        acc = (acc + metric_56 * 2 + 5) & 127;
        aux ^= (metric_56 & 15);
    } else {
        acc = (acc - metric_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_74) & 63;
    acc ^= aux;
    int parity_56 = (aux + st.buffer[1]) & 3;
    switch (parity_56) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_28 = local_arr[aux % 3];
    acc = (acc + anchor_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_3(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_44 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_44 > 30) {
        acc = (acc + quantum_44 * 2 + 5) & 127;
        aux ^= (quantum_44 & 15);
    } else {
        acc = (acc - quantum_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_42 = local_arr[aux % 3];
    acc = (acc + residue_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_58 = 0;
    for (int k = 0; k < 2; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    int tally_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_91) & 63;
    acc ^= aux;
    int offset_56 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_56 > 37) {
        acc = (acc + offset_56 * 2 + 5) & 127;
        aux ^= (offset_56 & 15);
    } else {
        acc = (acc - offset_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_5(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int index_reg_83 = local_arr[aux % 3];
    acc = (acc + index_reg_83 * 2) & 127;
    int bound_36 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_36 > 43) {
        acc = (acc + bound_36 * 2 + 5) & 127;
        aux ^= (bound_36 & 15);
    } else {
        acc = (acc - bound_36 + 11) & 127;
        aux += 3;
    }
    int checksum_76 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_76 = (checksum_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_53 = (aux + st.buffer[1]) & 3;
    switch (scale_53) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_39 = 0;
    for (int k = 0; k < 2; k++) {
        mask_39 = (mask_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_39) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_33 = local_arr[aux % 3];
    acc = (acc + pivot_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_7(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_72 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_72 = (quotient_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_72) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_46 = (aux + st.buffer[1]) & 3;
    switch (offset_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_8(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int index_reg_61 = (aux + st.buffer[1]) & 3;
    switch (index_reg_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_77 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_77 > 15) {
        acc = (acc + mask_77 * 2 + 5) & 127;
        aux ^= (mask_77 & 15);
    } else {
        acc = (acc - mask_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int offset_50 = (aux + st.buffer[1]) & 3;
    switch (offset_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_73 = 0;
    for (int k = 0; k < 3; k++) {
        sample_73 = (sample_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_10(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_58 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_58 > 48) {
        acc = (acc + accumulator_58 * 2 + 5) & 127;
        aux ^= (accumulator_58 & 15);
    } else {
        acc = (acc - accumulator_58 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_82 = local_arr[aux % 3];
    acc = (acc + anchor_82 * 2) & 127;
    int metric_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001580_8013_11(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_76 = local_arr[aux % 3];
    acc = (acc + factor_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_12(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_25 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_25 = (quotient_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_25) & 127;
    }
    int weight_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001580_8013_13(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_81) & 63;
    acc ^= aux;
    int tracker_31 = (aux + st.buffer[1]) & 3;
    switch (tracker_31) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_46 = local_arr[aux % 3];
    acc = (acc + phase_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001580_8013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int phase_53 = local_arr[aux % 3];
    acc = (acc + phase_53 * 2) & 127;
    int quotient_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_86) & 63;
    acc ^= aux;
    int window_89 = (st.buffer[0] * 3 + aux) & 63;
    if (window_89 > 10) {
        acc = (acc + window_89 * 2 + 5) & 127;
        aux ^= (window_89 & 15);
    } else {
        acc = (acc - window_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int quantum_52 = local_arr[aux % 3];
    acc = (acc + quantum_52 * 2) & 127;
    int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001580_8013_16(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_90 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_90 > 33) {
        acc = (acc + mask_90 * 2 + 5) & 127;
        aux ^= (mask_90 & 15);
    } else {
        acc = (acc - mask_90 + 11) & 127;
        aux += 3;
    }
    int bound_60 = 0;
    for (int k = 0; k < 3; k++) {
        bound_60 = (bound_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_60) & 127;
    }
    int tally_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001580_8013_17(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001580_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int bound_77 = 0;
    for (int k = 0; k < 3; k++) {
        bound_77 = (bound_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_77) & 127;
    }
    int accumulator_68 = (aux + st.buffer[1]) & 3;
    switch (accumulator_68) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int index_reg_22 = local_arr[aux % 3];
    acc = (acc + index_reg_22 * 2) & 127;
    int scale_65 = 0;
    for (int k = 0; k < 2; k++) {
        scale_65 = (scale_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_19(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_30 > 22) {
        acc = (acc + anchor_30 * 2 + 5) & 127;
        aux ^= (anchor_30 & 15);
    } else {
        acc = (acc - anchor_30 + 11) & 127;
        aux += 3;
    }
    int threshold_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_38) & 63;
    acc ^= aux;
    int scale_62 = 0;
    for (int k = 0; k < 3; k++) {
        scale_62 = (scale_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_20(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001580_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_53 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_53 > 42) {
        acc = (acc + bound_53 * 2 + 5) & 127;
        aux ^= (bound_53 & 15);
    } else {
        acc = (acc - bound_53 + 11) & 127;
        aux += 3;
    }
    int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_43) & 63;
    acc ^= aux;
    int metric_82 = 0;
    for (int k = 0; k < 3; k++) {
        metric_82 = (metric_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_87 = (aux + st.buffer[1]) & 3;
    switch (residue_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001580_8013_22(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001580_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int scale_88 = local_arr[aux % 3];
    acc = (acc + scale_88 * 2) & 127;
    int weight_44 = 0;
    for (int k = 0; k < 3; k++) {
        weight_44 = (weight_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_44) & 127;
    }
    int residue_87 = (aux + st.buffer[1]) & 3;
    switch (residue_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001580_0;
    int sec_r001580_1;
    int sec_r001580_2;
    int sec_r001580_3;
    int sec_r001580_4;
    int sec_r001580_5;
    int sec_r001580_6;
    int sec_r001580_7;
    int sec_r001580_8;
    int sec_r001580_9;
    int sec_r001580_10;
    int sec_r001580_11;
    int sec_r001580_12;
    int sec_r001580_13;
    int sec_r001580_14;
    int sec_r001580_15;
    int sec_r001580_16;
    int sec_r001580_17;
    int sec_r001580_18;
    int sec_r001580_19;
    int sec_r001580_20;
    int sec_r001580_21;
    int sec_r001580_22;
    int sec_r001580_23;
    int pub_r001580_0;
    int pub_r001580_1;
    int pub_r001580_2;
    int pub_r001580_3;
    int pub_r001580_4;
    int pub_r001580_5;
    int pub_r001580_6;
    int pub_r001580_7;
    int pub_r001580_8;
    int pub_r001580_9;
    int pub_r001580_10;
    int pub_r001580_11;
    int pub_r001580_12;
    int pub_r001580_13;
    int pub_r001580_14;
    int pub_r001580_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001580_0 >= -100 && pub_r001580_0 <= 100);
    __CPROVER_assume(pub_r001580_1 >= -100 && pub_r001580_1 <= 100);
    __CPROVER_assume(pub_r001580_2 >= -100 && pub_r001580_2 <= 100);
    __CPROVER_assume(pub_r001580_3 >= -100 && pub_r001580_3 <= 100);
    __CPROVER_assume(pub_r001580_4 >= -100 && pub_r001580_4 <= 100);
    __CPROVER_assume(pub_r001580_5 >= -100 && pub_r001580_5 <= 100);
    __CPROVER_assume(pub_r001580_6 >= -100 && pub_r001580_6 <= 100);
    __CPROVER_assume(pub_r001580_7 >= -100 && pub_r001580_7 <= 100);
    __CPROVER_assume(pub_r001580_8 >= -100 && pub_r001580_8 <= 100);
    __CPROVER_assume(pub_r001580_9 >= -100 && pub_r001580_9 <= 100);
    __CPROVER_assume(pub_r001580_10 >= -100 && pub_r001580_10 <= 100);
    __CPROVER_assume(pub_r001580_11 >= -100 && pub_r001580_11 <= 100);
    __CPROVER_assume(pub_r001580_12 >= -100 && pub_r001580_12 <= 100);
    __CPROVER_assume(pub_r001580_13 >= -100 && pub_r001580_13 <= 100);
    __CPROVER_assume(pub_r001580_14 >= -100 && pub_r001580_14 <= 100);
    __CPROVER_assume(pub_r001580_15 >= -100 && pub_r001580_15 <= 100);
    __CPROVER_assume(sec_r001580_0 >= 0 && sec_r001580_0 <= 255);
    __CPROVER_assume(sec_r001580_1 >= 0 && sec_r001580_1 <= 255);
    __CPROVER_assume(sec_r001580_2 >= 0 && sec_r001580_2 <= 255);
    __CPROVER_assume(sec_r001580_3 >= 0 && sec_r001580_3 <= 255);
    __CPROVER_assume(sec_r001580_4 >= 0 && sec_r001580_4 <= 255);
    __CPROVER_assume(sec_r001580_5 >= 0 && sec_r001580_5 <= 255);
    __CPROVER_assume(sec_r001580_6 >= 0 && sec_r001580_6 <= 255);
    __CPROVER_assume(sec_r001580_7 >= 0 && sec_r001580_7 <= 255);
    __CPROVER_assume(sec_r001580_8 >= 0 && sec_r001580_8 <= 255);
    __CPROVER_assume(sec_r001580_9 >= 0 && sec_r001580_9 <= 255);
    __CPROVER_assume(sec_r001580_10 >= 0 && sec_r001580_10 <= 255);
    __CPROVER_assume(sec_r001580_11 >= 0 && sec_r001580_11 <= 255);
    __CPROVER_assume(sec_r001580_12 >= 0 && sec_r001580_12 <= 255);
    __CPROVER_assume(sec_r001580_13 >= 0 && sec_r001580_13 <= 255);
    __CPROVER_assume(sec_r001580_14 >= 0 && sec_r001580_14 <= 255);
    __CPROVER_assume(sec_r001580_15 >= 0 && sec_r001580_15 <= 255);
    __CPROVER_assume(sec_r001580_16 >= 0 && sec_r001580_16 <= 255);
    __CPROVER_assume(sec_r001580_17 >= 0 && sec_r001580_17 <= 255);
    __CPROVER_assume(sec_r001580_18 >= 0 && sec_r001580_18 <= 255);
    __CPROVER_assume(sec_r001580_19 >= 0 && sec_r001580_19 <= 255);
    __CPROVER_assume(sec_r001580_20 >= 0 && sec_r001580_20 <= 255);
    __CPROVER_assume(sec_r001580_21 >= 0 && sec_r001580_21 <= 255);
    __CPROVER_assume(sec_r001580_22 >= 0 && sec_r001580_22 <= 255);
    __CPROVER_assume(sec_r001580_23 >= 0 && sec_r001580_23 <= 255);

    struct AudioFrame_R001580_8013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001580_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001580_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001580_0 + 7) & 15;
    struct FilterState_R001580_8013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001580_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001580_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001580_0 + 9) & 15;
    struct Transaction_R001580_8013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001580_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001580_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001580_0 + 11) & 15;

    union RegisterBank_R001580_8013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001580_8013_0(sec_r001580_0, sec_r001580_1);
    int helper_flow_1 = fn_R001580_8013_1(sec_r001580_1, pub_r001580_2, pub_r001580_3, pub_r001580_4);
    int helper_flow_2 = fn_R001580_8013_2(sec_r001580_2, pub_r001580_3, pub_r001580_4, pub_r001580_5, pub_r001580_6);
    int helper_flow_3 = fn_R001580_8013_3(sec_r001580_3, sec_r001580_4, pub_r001580_5);
    int helper_flow_4 = fn_R001580_8013_4(sec_r001580_4, pub_r001580_5, pub_r001580_6, pub_r001580_7, pub_r001580_8);
    int helper_flow_5 = fn_R001580_8013_5(sec_r001580_5, sec_r001580_6, pub_r001580_7);
    int helper_flow_6 = fn_R001580_8013_6(sec_r001580_6, pub_r001580_7, pub_r001580_8, pub_r001580_9);
    int helper_flow_7 = fn_R001580_8013_7(sec_r001580_7, pub_r001580_8, pub_r001580_9);
    int helper_flow_8 = fn_R001580_8013_8(sec_r001580_8, sec_r001580_9);
    int helper_flow_9 = fn_R001580_8013_9(sec_r001580_9, pub_r001580_10, pub_r001580_11, pub_r001580_12);
    int helper_flow_10 = fn_R001580_8013_10(sec_r001580_10, sec_r001580_11, pub_r001580_12);
    int helper_flow_11 = fn_R001580_8013_11(sec_r001580_11, sec_r001580_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_0 > 41) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001580_20 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_1 > 47) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_2 > 41) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001580_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_4 > 49) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001580_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_6 > 34) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001580_5 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_8 > 27) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_9 > 21) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001580_18 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_10 > 49) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_11 > 34) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001580_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001580_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_14 > 47) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001580_16 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_15 > 41) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001580_21 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_17 > 36) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001580_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001580_2 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_19 > 45) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_20 > 37) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001580_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001580_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_23 > 21) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001580_7 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_24 > 38) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001580_17 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_25 > 27) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001580_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_27 > 46) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001580_9 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_28 > 35) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_30 > 50) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001580_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001580_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_33 > 50) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_34 > 20) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001580_14 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_35 > 50) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001580_8 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_36 > 21) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_37 > 32) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_38 > 43) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_39 > 29) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001580_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001580_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001580_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_43 > 20) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_44 > 24) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_45 > 23) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_46 > 31) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001580_2 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001580_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_49 > 22) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_50 > 50) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001580_2 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_51 > 23) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_52 > 42) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_53 > 46) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_54 > 40) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001580_1 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_55 > 34) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001580_22 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_56 > 50) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_57 > 50) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001580_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_59 > 31) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001580_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_61 > 33) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_62 > 44) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001580_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_64 > 38) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001580_19 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_65 > 38) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001580_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001580_21 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_67 > 38) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_68 > 40) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_69 > 29) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001580_20 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_70 > 34) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_71 > 38) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001580_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_73 > 20) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_74 > 41) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_75 > 49) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_77 > 41) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_78 > 25) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001580_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001580_4 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_80 > 40) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001580_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_82 > 48) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_83 > 50) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001580_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_85 > 29) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_86 > 49) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_87 > 45) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_88 > 49) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001580_17 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_89 > 32) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_90 > 36) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_91 > 24) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001580_15 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_92 > 36) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001580_11 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_93 > 25) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_94 > 47) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_95 > 36) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001580_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_97 > 42) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001580_10 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_98 > 36) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_99 > 50) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001580_10 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_100 > 40) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_101 > 31) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_102 > 47) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001580_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_104 > 34) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001580_12 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_105 > 37) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_106 > 26) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_107 > 45) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001580_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001580_20 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_109 > 43) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001580_17 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_110 > 45) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_111 > 25) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001580_0 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_112 > 28) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_113 > 28) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001580_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_115 > 27) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001580_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_117 > 47) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001580_22 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_118 > 49) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001580_23 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_119 > 31) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_120 > 46) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_121 > 21) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_122 > 45) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001580_16 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_123 > 34) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001580_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001580_12 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_125 > 38) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001580_3 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_126 > 41) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_127 > 50) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_128 > 21) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_129 > 48) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_130 > 23) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_131 > 39) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_132 > 40) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_133 > 32) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_134 > 39) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_136 > 35) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_137 > 23) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001580_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_139 > 44) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_140 > 29) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001580_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001580_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_143 > 47) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_144 > 24) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_145 > 46) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001580_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_147 > 41) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_148 > 25) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001580_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_151 > 23) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_152 > 48) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_153 > 49) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_154 > 23) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001580_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_156 > 31) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001580_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_158 > 45) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_159 > 33) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001580_9 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_160 > 50) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_161 > 22) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_162 > 31) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001580_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_164 > 37) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_165 > 34) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_166 > 30) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_167 > 34) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001580_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_169 > 20) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_170 > 37) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_171 > 29) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_172 > 45) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_173 > 24) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001580_10) & 127;
    if (stage_v_174 > 31) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001580_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001580_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_177 > 38) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001580_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001580_5 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_179 > 35) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_180 > 22) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_181 > 27) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001580_22 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_182 > 36) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001580_4 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_183 > 22) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001580_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_185 > 29) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_186 > 38) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001580_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_188 > 47) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_189 > 30) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001580_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001580_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001580_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_193 > 40) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_194 > 20) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_195 > 33) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_196 > 42) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_197 > 34) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_198 > 27) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001580_15) & 127;
    if (stage_v_199 > 38) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001580_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_201 > 34) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r001580_14 ^ 0x2A) * 2 + pub_r001580_7) & 127;
    if (stage_v_202 > 26) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_203 > 44) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_204 > 48) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_205 > 39) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001580_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001580_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001580_12 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_208 > 42) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_209 > 31) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_210 > 48) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001580_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r001580_6 ^ 0x2A) * 2 + pub_r001580_4) & 127;
    if (stage_v_212 > 43) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_213 > 41) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001580_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001580_11) & 127;
    if (stage_v_215 > 27) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_216 > 29) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_217 > 43) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001580_12) & 127;
    if (stage_v_218 > 50) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_212 ^ 0x2A) * 2 + pub_r001580_3) & 127;
    if (stage_v_219 > 23) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001580_2) & 127;
    if (stage_v_220 > 45) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_221 > 39) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_222 > 23) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001580_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001580_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001580_14) & 127;
    if (stage_v_225 > 41) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001580_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_227 > 30) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_212 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_228 > 26) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_229 > 37) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_230 > 38) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001580_5) & 127;
    if (stage_v_231 > 36) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001580_9) & 127;
    if (stage_v_232 > 31) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001580_1) & 127;
    if (stage_v_233 > 20) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_220 ^ 0x2A) * 2 + pub_r001580_6) & 127;
    if (stage_v_234 > 21) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001580_13) & 127;
    if (stage_v_235 > 26) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001580_10 ^ 0x2A) * 2 + pub_r001580_0) & 127;
    if (stage_v_236 > 41) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001580_8) & 127;
    if (stage_v_237 > 37) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
