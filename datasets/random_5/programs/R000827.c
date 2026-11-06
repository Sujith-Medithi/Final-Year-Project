/*
 * Benchmark Program: R000827
 * Security Family: nested_implicit_flow
 * Generator Seed: 582713
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000827_2713_0 {
    unsigned char density;
    unsigned char dim;
    unsigned char trace;
    int stride;
    short scale;
    int determinant;
    int buffer[3];
};

struct Transaction_R000827_2713_1 {
    short balance;
    int fee;
    int status;
    int auth_code;
    int buffer[3];
};

union ColorPixel_R000827_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000827_2713_0(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_63 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_63 > 25) {
        acc = (acc + damping_63 * 2 + 5) & 127;
        aux ^= (damping_63 & 15);
    } else {
        acc = (acc - damping_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_85 = local_arr[aux % 3];
    acc = (acc + margin_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_1(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int accumulator_73 = (aux + st.buffer[1]) & 3;
    switch (accumulator_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_10 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_10 > 36) {
        acc = (acc + margin_10 * 2 + 5) & 127;
        aux ^= (margin_10 & 15);
    } else {
        acc = (acc - margin_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_2(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int phase_97 = (aux + st.buffer[1]) & 3;
    switch (phase_97) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_63 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_63 > 43) {
        acc = (acc + bound_63 * 2 + 5) & 127;
        aux ^= (bound_63 & 15);
    } else {
        acc = (acc - bound_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_3(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_11 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_11 > 19) {
        acc = (acc + sample_11 * 2 + 5) & 127;
        aux ^= (sample_11 & 15);
    } else {
        acc = (acc - sample_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_4(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_94 = local_arr[aux % 3];
    acc = (acc + parity_94 * 2) & 127;
    int checksum_42 = (aux + st.buffer[1]) & 3;
    switch (checksum_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int sample_98 = local_arr[aux % 3];
    acc = (acc + sample_98 * 2) & 127;
    int delta_53 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_53 > 16) {
        acc = (acc + delta_53 * 2 + 5) & 127;
        aux ^= (delta_53 & 15);
    } else {
        acc = (acc - delta_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_6(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int factor_54 = local_arr[aux % 3];
    acc = (acc + factor_54 * 2) & 127;
    int offset_84 = (aux + st.buffer[1]) & 3;
    switch (offset_84) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000827_2713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_25 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_25 > 22) {
        acc = (acc + quantum_25 * 2 + 5) & 127;
        aux ^= (quantum_25 & 15);
    } else {
        acc = (acc - quantum_25 + 11) & 127;
        aux += 3;
    }
    int sample_18 = (aux + st.buffer[1]) & 3;
    switch (sample_18) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_16 = local_arr[aux % 3];
    acc = (acc + accumulator_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_8(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_60 = (aux + st.buffer[1]) & 3;
    switch (residue_60) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_33 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_33 > 29) {
        acc = (acc + mask_33 * 2 + 5) & 127;
        aux ^= (mask_33 & 15);
    } else {
        acc = (acc - mask_33 + 11) & 127;
        aux += 3;
    }
    int delta_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000827_2713_9(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_62) & 63;
    acc ^= aux;
    int tracker_48 = (aux + st.buffer[1]) & 3;
    switch (tracker_48) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_69 > 44) {
        acc = (acc + factor_69 * 2 + 5) & 127;
        aux ^= (factor_69 & 15);
    } else {
        acc = (acc - factor_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_10(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_40 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_40 > 13) {
        acc = (acc + checksum_40 * 2 + 5) & 127;
        aux ^= (checksum_40 & 15);
    } else {
        acc = (acc - checksum_40 + 11) & 127;
        aux += 3;
    }
    int stride_63 = (aux + st.buffer[1]) & 3;
    switch (stride_63) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_21) & 63;
    acc ^= aux;
    int cursor_81 = (aux + st.buffer[1]) & 3;
    switch (cursor_81) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_91) & 63;
    acc ^= aux;
    int bound_47 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_47 > 16) {
        acc = (acc + bound_47 * 2 + 5) & 127;
        aux ^= (bound_47 & 15);
    } else {
        acc = (acc - bound_47 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_91 = local_arr[aux % 3];
    acc = (acc + sample_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_64 = local_arr[aux % 3];
    acc = (acc + window_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_43 = (aux + st.buffer[1]) & 3;
    switch (coefficient_43) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_32 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_32 > 43) {
        acc = (acc + accumulator_32 * 2 + 5) & 127;
        aux ^= (accumulator_32 & 15);
    } else {
        acc = (acc - accumulator_32 + 11) & 127;
        aux += 3;
    }
    int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000827_2713_15(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int bound_63 = local_arr[aux % 3];
    acc = (acc + bound_63 * 2) & 127;
    int offset_25 = (aux + st.buffer[1]) & 3;
    switch (offset_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_87 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_87 > 17) {
        acc = (acc + delta_87 * 2 + 5) & 127;
        aux ^= (delta_87 & 15);
    } else {
        acc = (acc - delta_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_16(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_43) & 63;
    acc ^= aux;
    int anchor_98 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_98 > 19) {
        acc = (acc + anchor_98 * 2 + 5) & 127;
        aux ^= (anchor_98 & 15);
    } else {
        acc = (acc - anchor_98 + 11) & 127;
        aux += 3;
    }
    int accumulator_71 = (aux + st.buffer[1]) & 3;
    switch (accumulator_71) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000827_2713_17(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int weight_94 = (aux + st.buffer[1]) & 3;
    switch (weight_94) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_38 = (aux + st.buffer[1]) & 3;
    switch (cursor_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000827_2713_19(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000827_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int sample_52 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_52 > 13) {
        acc = (acc + sample_52 * 2 + 5) & 127;
        aux ^= (sample_52 & 15);
    } else {
        acc = (acc - sample_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000827_2713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000827_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int threshold_59 = (aux + st.buffer[1]) & 3;
    switch (threshold_59) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_86) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000827_0;
    int sec_r000827_1;
    int sec_r000827_2;
    int sec_r000827_3;
    int sec_r000827_4;
    int sec_r000827_5;
    int sec_r000827_6;
    int sec_r000827_7;
    int sec_r000827_8;
    int sec_r000827_9;
    int sec_r000827_10;
    int sec_r000827_11;
    int sec_r000827_12;
    int sec_r000827_13;
    int sec_r000827_14;
    int sec_r000827_15;
    int sec_r000827_16;
    int sec_r000827_17;
    int sec_r000827_18;
    int sec_r000827_19;
    int sec_r000827_20;
    int sec_r000827_21;
    int pub_r000827_0;
    int pub_r000827_1;
    int pub_r000827_2;
    int pub_r000827_3;
    int pub_r000827_4;
    int pub_r000827_5;
    int pub_r000827_6;
    int pub_r000827_7;
    int pub_r000827_8;
    int pub_r000827_9;
    int pub_r000827_10;
    int pub_r000827_11;
    int pub_r000827_12;
    int pub_r000827_13;
    int pub_r000827_14;
    int pub_r000827_15;
    int pub_r000827_16;
    int pub_r000827_17;
    int pub_r000827_18;
    int pub_r000827_19;
    int pub_r000827_20;
    int pub_r000827_21;
    int pub_r000827_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000827_0 >= -100 && pub_r000827_0 <= 100);
    __CPROVER_assume(pub_r000827_1 >= -100 && pub_r000827_1 <= 100);
    __CPROVER_assume(pub_r000827_2 >= -100 && pub_r000827_2 <= 100);
    __CPROVER_assume(pub_r000827_3 >= -100 && pub_r000827_3 <= 100);
    __CPROVER_assume(pub_r000827_4 >= -100 && pub_r000827_4 <= 100);
    __CPROVER_assume(pub_r000827_5 >= -100 && pub_r000827_5 <= 100);
    __CPROVER_assume(pub_r000827_6 >= -100 && pub_r000827_6 <= 100);
    __CPROVER_assume(pub_r000827_7 >= -100 && pub_r000827_7 <= 100);
    __CPROVER_assume(pub_r000827_8 >= -100 && pub_r000827_8 <= 100);
    __CPROVER_assume(pub_r000827_9 >= -100 && pub_r000827_9 <= 100);
    __CPROVER_assume(pub_r000827_10 >= -100 && pub_r000827_10 <= 100);
    __CPROVER_assume(pub_r000827_11 >= -100 && pub_r000827_11 <= 100);
    __CPROVER_assume(pub_r000827_12 >= -100 && pub_r000827_12 <= 100);
    __CPROVER_assume(pub_r000827_13 >= -100 && pub_r000827_13 <= 100);
    __CPROVER_assume(pub_r000827_14 >= -100 && pub_r000827_14 <= 100);
    __CPROVER_assume(pub_r000827_15 >= -100 && pub_r000827_15 <= 100);
    __CPROVER_assume(pub_r000827_16 >= -100 && pub_r000827_16 <= 100);
    __CPROVER_assume(pub_r000827_17 >= -100 && pub_r000827_17 <= 100);
    __CPROVER_assume(pub_r000827_18 >= -100 && pub_r000827_18 <= 100);
    __CPROVER_assume(pub_r000827_19 >= -100 && pub_r000827_19 <= 100);
    __CPROVER_assume(pub_r000827_20 >= -100 && pub_r000827_20 <= 100);
    __CPROVER_assume(pub_r000827_21 >= -100 && pub_r000827_21 <= 100);
    __CPROVER_assume(pub_r000827_22 >= -100 && pub_r000827_22 <= 100);
    __CPROVER_assume(sec_r000827_0 >= 0 && sec_r000827_0 <= 255);
    __CPROVER_assume(sec_r000827_1 >= 0 && sec_r000827_1 <= 255);
    __CPROVER_assume(sec_r000827_2 >= 0 && sec_r000827_2 <= 255);
    __CPROVER_assume(sec_r000827_3 >= 0 && sec_r000827_3 <= 255);
    __CPROVER_assume(sec_r000827_4 >= 0 && sec_r000827_4 <= 255);
    __CPROVER_assume(sec_r000827_5 >= 0 && sec_r000827_5 <= 255);
    __CPROVER_assume(sec_r000827_6 >= 0 && sec_r000827_6 <= 255);
    __CPROVER_assume(sec_r000827_7 >= 0 && sec_r000827_7 <= 255);
    __CPROVER_assume(sec_r000827_8 >= 0 && sec_r000827_8 <= 255);
    __CPROVER_assume(sec_r000827_9 >= 0 && sec_r000827_9 <= 255);
    __CPROVER_assume(sec_r000827_10 >= 0 && sec_r000827_10 <= 255);
    __CPROVER_assume(sec_r000827_11 >= 0 && sec_r000827_11 <= 255);
    __CPROVER_assume(sec_r000827_12 >= 0 && sec_r000827_12 <= 255);
    __CPROVER_assume(sec_r000827_13 >= 0 && sec_r000827_13 <= 255);
    __CPROVER_assume(sec_r000827_14 >= 0 && sec_r000827_14 <= 255);
    __CPROVER_assume(sec_r000827_15 >= 0 && sec_r000827_15 <= 255);
    __CPROVER_assume(sec_r000827_16 >= 0 && sec_r000827_16 <= 255);
    __CPROVER_assume(sec_r000827_17 >= 0 && sec_r000827_17 <= 255);
    __CPROVER_assume(sec_r000827_18 >= 0 && sec_r000827_18 <= 255);
    __CPROVER_assume(sec_r000827_19 >= 0 && sec_r000827_19 <= 255);
    __CPROVER_assume(sec_r000827_20 >= 0 && sec_r000827_20 <= 255);
    __CPROVER_assume(sec_r000827_21 >= 0 && sec_r000827_21 <= 255);

    struct MatrixBlock_R000827_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000827_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000827_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000827_0 + 7) & 15;
    struct Transaction_R000827_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000827_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000827_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000827_0 + 9) & 15;

    union ColorPixel_R000827_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 35) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 50) {
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
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 18) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 33) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 40) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 55) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 11) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 26) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 11) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 26) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 46) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 32) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 47) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 19) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 34) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 30) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 45) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
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
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 34) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 49) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 32) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 47) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 30) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 45) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000827_20 & 1) != 0) {
        if ((sec_r000827_5 & 2) != 0) {
            stage_v_74 = (pub_r000827_17 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000827_17 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000827_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000827_16 & 2) != 0) {
            stage_v_75 = (pub_r000827_16 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000827_16 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000827_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_76 = (pub_r000827_15 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000827_15 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000827_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000827_12 & 2) != 0) {
            stage_v_77 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000827_13 & 1) != 0) {
        if ((sec_r000827_21 & 2) != 0) {
            stage_v_78 = (pub_r000827_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000827_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000827_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_2 & 2) != 0) {
            stage_v_79 = (pub_r000827_14 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000827_14 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000827_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_21 & 2) != 0) {
            stage_v_80 = (pub_r000827_3 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000827_3 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000827_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000827_14 & 1) != 0) {
        if ((sec_r000827_15 & 2) != 0) {
            stage_v_81 = (pub_r000827_7 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000827_7 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000827_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000827_16 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_82 = (pub_r000827_16 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000827_16 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000827_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000827_3 & 2) != 0) {
            stage_v_83 = (pub_r000827_16 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000827_16 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000827_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000827_0 & 2) != 0) {
            stage_v_84 = (pub_r000827_21 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000827_21 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000827_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000827_2 & 2) != 0) {
            stage_v_85 = (pub_r000827_8 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000827_8 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000827_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000827_1 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_86 = (pub_r000827_7 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000827_7 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000827_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000827_18 & 2) != 0) {
            stage_v_87 = (pub_r000827_17 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000827_17 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000827_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_88 = (pub_r000827_1 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000827_1 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000827_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_14 & 2) != 0) {
            stage_v_89 = (pub_r000827_18 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000827_18 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000827_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000827_2 & 1) != 0) {
        if ((sec_r000827_12 & 2) != 0) {
            stage_v_90 = (pub_r000827_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000827_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000827_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000827_12 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_91 = (pub_r000827_10 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000827_10 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000827_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000827_6 & 2) != 0) {
            stage_v_92 = (pub_r000827_14 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000827_14 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000827_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_93 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000827_4 & 2) != 0) {
            stage_v_94 = (pub_r000827_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000827_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000827_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000827_13 & 2) != 0) {
            stage_v_95 = (pub_r000827_22 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000827_22 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000827_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000827_5 & 2) != 0) {
            stage_v_96 = (pub_r000827_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000827_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000827_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000827_1 & 1) != 0) {
        if ((sec_r000827_2 & 2) != 0) {
            stage_v_97 = (pub_r000827_21 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000827_21 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000827_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000827_14 & 1) != 0) {
        if ((sec_r000827_13 & 2) != 0) {
            stage_v_98 = (pub_r000827_22 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000827_22 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000827_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000827_6 & 1) != 0) {
        if ((sec_r000827_16 & 2) != 0) {
            stage_v_99 = (pub_r000827_16 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000827_16 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000827_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000827_8 & 2) != 0) {
            stage_v_100 = (pub_r000827_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000827_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000827_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000827_11 & 2) != 0) {
            stage_v_101 = (pub_r000827_6 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000827_6 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000827_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_3 & 2) != 0) {
            stage_v_102 = (pub_r000827_14 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000827_14 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000827_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000827_10 & 1) != 0) {
        if ((sec_r000827_19 & 2) != 0) {
            stage_v_103 = (pub_r000827_2 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000827_2 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000827_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000827_11 & 2) != 0) {
            stage_v_104 = (pub_r000827_19 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000827_19 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000827_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000827_0 & 2) != 0) {
            stage_v_105 = (pub_r000827_22 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000827_22 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000827_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000827_12 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_106 = (pub_r000827_7 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000827_7 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000827_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000827_14 & 1) != 0) {
        if ((sec_r000827_19 & 2) != 0) {
            stage_v_107 = (pub_r000827_13 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000827_13 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000827_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_108 = (pub_r000827_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000827_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000827_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000827_6 & 1) != 0) {
        if ((sec_r000827_4 & 2) != 0) {
            stage_v_109 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000827_19 & 2) != 0) {
            stage_v_110 = (pub_r000827_20 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000827_20 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000827_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000827_5 & 2) != 0) {
            stage_v_111 = (pub_r000827_13 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000827_13 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000827_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000827_12 & 1) != 0) {
        if ((sec_r000827_13 & 2) != 0) {
            stage_v_112 = (pub_r000827_6 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000827_6 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000827_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000827_9 & 2) != 0) {
            stage_v_113 = (pub_r000827_13 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000827_13 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000827_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000827_11 & 1) != 0) {
        if ((sec_r000827_17 & 2) != 0) {
            stage_v_114 = (pub_r000827_6 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000827_6 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000827_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000827_17 & 1) != 0) {
        if ((sec_r000827_8 & 2) != 0) {
            stage_v_115 = (pub_r000827_22 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000827_22 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000827_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000827_12 & 2) != 0) {
            stage_v_116 = (pub_r000827_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000827_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000827_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000827_1 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_117 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000827_9 & 2) != 0) {
            stage_v_118 = (pub_r000827_1 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000827_1 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000827_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000827_19 & 1) != 0) {
        if ((sec_r000827_0 & 2) != 0) {
            stage_v_119 = (pub_r000827_13 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000827_13 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000827_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000827_6 & 2) != 0) {
            stage_v_120 = (pub_r000827_9 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000827_9 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000827_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000827_8 & 1) != 0) {
        if ((sec_r000827_6 & 2) != 0) {
            stage_v_121 = (pub_r000827_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000827_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000827_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000827_10 & 2) != 0) {
            stage_v_122 = (pub_r000827_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000827_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000827_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000827_13 & 2) != 0) {
            stage_v_123 = (pub_r000827_18 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000827_18 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000827_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000827_16 & 2) != 0) {
            stage_v_124 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_125 = (pub_r000827_18 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000827_18 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000827_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_2 & 2) != 0) {
            stage_v_126 = (pub_r000827_11 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000827_11 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000827_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000827_21 & 1) != 0) {
        if ((sec_r000827_0 & 2) != 0) {
            stage_v_127 = (pub_r000827_21 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000827_21 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000827_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000827_1 & 2) != 0) {
            stage_v_128 = (pub_r000827_8 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000827_8 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000827_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000827_8 & 1) != 0) {
        if ((sec_r000827_14 & 2) != 0) {
            stage_v_129 = (pub_r000827_3 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000827_3 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000827_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000827_18 & 2) != 0) {
            stage_v_130 = (pub_r000827_16 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000827_16 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000827_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000827_5 & 2) != 0) {
            stage_v_131 = (pub_r000827_0 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000827_0 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000827_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000827_1 & 1) != 0) {
        if ((sec_r000827_13 & 2) != 0) {
            stage_v_132 = (pub_r000827_11 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000827_11 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000827_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000827_15 & 1) != 0) {
        if ((sec_r000827_21 & 2) != 0) {
            stage_v_133 = (pub_r000827_21 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000827_21 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000827_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000827_15 & 1) != 0) {
        if ((sec_r000827_9 & 2) != 0) {
            stage_v_134 = (pub_r000827_12 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000827_12 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000827_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000827_14 & 2) != 0) {
            stage_v_135 = (pub_r000827_7 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000827_7 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000827_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000827_17 & 1) != 0) {
        if ((sec_r000827_10 & 2) != 0) {
            stage_v_136 = (pub_r000827_19 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000827_19 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000827_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000827_10 & 2) != 0) {
            stage_v_137 = (pub_r000827_9 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000827_9 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000827_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000827_21 & 2) != 0) {
            stage_v_138 = (pub_r000827_20 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000827_20 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000827_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000827_20 & 2) != 0) {
            stage_v_139 = (pub_r000827_9 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000827_9 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000827_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000827_1 & 1) != 0) {
        if ((sec_r000827_7 & 2) != 0) {
            stage_v_140 = (pub_r000827_20 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000827_20 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000827_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000827_17 & 1) != 0) {
        if ((sec_r000827_5 & 2) != 0) {
            stage_v_141 = (pub_r000827_12 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000827_12 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000827_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
