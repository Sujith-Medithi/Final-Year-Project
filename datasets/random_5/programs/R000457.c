/*
 * Benchmark Program: R000457
 * Security Family: nested_implicit_flow
 * Generator Seed: 545713
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000457_5713_0 {
    unsigned char id;
    int port;
    int baud_rate;
    int buffer[3];
};

struct MatrixBlock_R000457_5713_1 {
    int scale;
    int dim;
    short determinant;
    short trace;
    int density;
    int buffer[3];
};

union ColorPixel_R000457_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000457_5713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_65 = (aux + st.buffer[1]) & 3;
    switch (damping_65) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_51 = local_arr[aux % 3];
    acc = (acc + sample_51 * 2) & 127;
    int factor_91 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_91 > 36) {
        acc = (acc + factor_91 * 2 + 5) & 127;
        aux ^= (factor_91 & 15);
    } else {
        acc = (acc - factor_91 + 11) & 127;
        aux += 3;
    }
    int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_1(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int margin_82 = local_arr[aux % 3];
    acc = (acc + margin_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_42 = (aux + st.buffer[1]) & 3;
    switch (offset_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_84 = local_arr[aux % 3];
    acc = (acc + bound_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_3(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_78) & 63;
    acc ^= aux;
    int coefficient_90 = (aux + st.buffer[1]) & 3;
    switch (coefficient_90) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_17 = local_arr[aux % 3];
    acc = (acc + scale_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int weight_28 = local_arr[aux % 3];
    acc = (acc + weight_28 * 2) & 127;
    int tracker_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_10) & 63;
    acc ^= aux;
    int phase_40 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_40 > 41) {
        acc = (acc + phase_40 * 2 + 5) & 127;
        aux ^= (phase_40 & 15);
    } else {
        acc = (acc - phase_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_5(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int metric_50 = local_arr[aux % 3];
    acc = (acc + metric_50 * 2) & 127;
    int offset_33 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_33 > 33) {
        acc = (acc + offset_33 * 2 + 5) & 127;
        aux ^= (offset_33 & 15);
    } else {
        acc = (acc - offset_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_34 = (aux + st.buffer[1]) & 3;
    switch (index_reg_34) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_65 = local_arr[aux % 3];
    acc = (acc + parity_65 * 2) & 127;
    int parity_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_55 > 15) {
        acc = (acc + quotient_55 * 2 + 5) & 127;
        aux ^= (quotient_55 & 15);
    } else {
        acc = (acc - quotient_55 + 11) & 127;
        aux += 3;
    }
    int stride_84 = (aux + st.buffer[1]) & 3;
    switch (stride_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_96 = local_arr[aux % 3];
    acc = (acc + tracker_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_9(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int parity_40 = local_arr[aux % 3];
    acc = (acc + parity_40 * 2) & 127;
    int checksum_41 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_41 > 13) {
        acc = (acc + checksum_41 * 2 + 5) & 127;
        aux ^= (checksum_41 & 15);
    } else {
        acc = (acc - checksum_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_42 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_42 > 38) {
        acc = (acc + cursor_42 * 2 + 5) & 127;
        aux ^= (cursor_42 & 15);
    } else {
        acc = (acc - cursor_42 + 11) & 127;
        aux += 3;
    }
    int segment_54 = (aux + st.buffer[1]) & 3;
    switch (segment_54) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_11(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int quotient_76 = local_arr[aux % 3];
    acc = (acc + quotient_76 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_12(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int tally_77 = local_arr[aux % 3];
    acc = (acc + tally_77 * 2) & 127;
    int delta_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_14(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int phase_57 = local_arr[aux % 3];
    acc = (acc + phase_57 * 2) & 127;
    int accumulator_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_93) & 63;
    acc ^= aux;
    int parity_58 = (aux + st.buffer[1]) & 3;
    switch (parity_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_15(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int vector_33 = local_arr[aux % 3];
    acc = (acc + vector_33 * 2) & 127;
    int parity_13 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_13 > 41) {
        acc = (acc + parity_13 * 2 + 5) & 127;
        aux ^= (parity_13 & 15);
    } else {
        acc = (acc - parity_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_54 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_54 > 26) {
        acc = (acc + offset_54 * 2 + 5) & 127;
        aux ^= (offset_54 & 15);
    } else {
        acc = (acc - offset_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_32 = local_arr[aux % 3];
    acc = (acc + checksum_32 * 2) & 127;
    int segment_62 = (aux + st.buffer[1]) & 3;
    switch (segment_62) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_17(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int checksum_40 = (aux + st.buffer[1]) & 3;
    switch (checksum_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_78 = local_arr[aux % 3];
    acc = (acc + scale_78 * 2) & 127;
    int stride_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_18(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_57 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_57 > 30) {
        acc = (acc + anchor_57 * 2 + 5) & 127;
        aux ^= (anchor_57 & 15);
    } else {
        acc = (acc - anchor_57 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_92 = local_arr[aux % 3];
    acc = (acc + mask_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000457_5713_19(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000457_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_48 = local_arr[aux % 3];
    acc = (acc + offset_48 * 2) & 127;
    int phase_84 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_84 > 41) {
        acc = (acc + phase_84 * 2 + 5) & 127;
        aux ^= (phase_84 & 15);
    } else {
        acc = (acc - phase_84 + 11) & 127;
        aux += 3;
    }
    int cursor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000457_5713_21(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int scale_58 = local_arr[aux % 3];
    acc = (acc + scale_58 * 2) & 127;
    int scale_26 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_26 > 22) {
        acc = (acc + scale_26 * 2 + 5) & 127;
        aux ^= (scale_26 & 15);
    } else {
        acc = (acc - scale_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000457_5713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000457_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int phase_46 = local_arr[aux % 3];
    acc = (acc + phase_46 * 2) & 127;
    int cursor_76 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_76 > 44) {
        acc = (acc + cursor_76 * 2 + 5) & 127;
        aux ^= (cursor_76 & 15);
    } else {
        acc = (acc - cursor_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000457_0;
    int sec_r000457_1;
    int sec_r000457_2;
    int sec_r000457_3;
    int sec_r000457_4;
    int sec_r000457_5;
    int sec_r000457_6;
    int sec_r000457_7;
    int sec_r000457_8;
    int sec_r000457_9;
    int sec_r000457_10;
    int sec_r000457_11;
    int sec_r000457_12;
    int sec_r000457_13;
    int sec_r000457_14;
    int sec_r000457_15;
    int sec_r000457_16;
    int sec_r000457_17;
    int sec_r000457_18;
    int pub_r000457_0;
    int pub_r000457_1;
    int pub_r000457_2;
    int pub_r000457_3;
    int pub_r000457_4;
    int pub_r000457_5;
    int pub_r000457_6;
    int pub_r000457_7;
    int pub_r000457_8;
    int pub_r000457_9;
    int pub_r000457_10;
    int pub_r000457_11;
    int pub_r000457_12;
    int pub_r000457_13;
    int pub_r000457_14;
    int pub_r000457_15;
    int pub_r000457_16;
    int pub_r000457_17;
    int pub_r000457_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000457_0 >= -100 && pub_r000457_0 <= 100);
    __CPROVER_assume(pub_r000457_1 >= -100 && pub_r000457_1 <= 100);
    __CPROVER_assume(pub_r000457_2 >= -100 && pub_r000457_2 <= 100);
    __CPROVER_assume(pub_r000457_3 >= -100 && pub_r000457_3 <= 100);
    __CPROVER_assume(pub_r000457_4 >= -100 && pub_r000457_4 <= 100);
    __CPROVER_assume(pub_r000457_5 >= -100 && pub_r000457_5 <= 100);
    __CPROVER_assume(pub_r000457_6 >= -100 && pub_r000457_6 <= 100);
    __CPROVER_assume(pub_r000457_7 >= -100 && pub_r000457_7 <= 100);
    __CPROVER_assume(pub_r000457_8 >= -100 && pub_r000457_8 <= 100);
    __CPROVER_assume(pub_r000457_9 >= -100 && pub_r000457_9 <= 100);
    __CPROVER_assume(pub_r000457_10 >= -100 && pub_r000457_10 <= 100);
    __CPROVER_assume(pub_r000457_11 >= -100 && pub_r000457_11 <= 100);
    __CPROVER_assume(pub_r000457_12 >= -100 && pub_r000457_12 <= 100);
    __CPROVER_assume(pub_r000457_13 >= -100 && pub_r000457_13 <= 100);
    __CPROVER_assume(pub_r000457_14 >= -100 && pub_r000457_14 <= 100);
    __CPROVER_assume(pub_r000457_15 >= -100 && pub_r000457_15 <= 100);
    __CPROVER_assume(pub_r000457_16 >= -100 && pub_r000457_16 <= 100);
    __CPROVER_assume(pub_r000457_17 >= -100 && pub_r000457_17 <= 100);
    __CPROVER_assume(pub_r000457_18 >= -100 && pub_r000457_18 <= 100);
    __CPROVER_assume(sec_r000457_0 >= 0 && sec_r000457_0 <= 255);
    __CPROVER_assume(sec_r000457_1 >= 0 && sec_r000457_1 <= 255);
    __CPROVER_assume(sec_r000457_2 >= 0 && sec_r000457_2 <= 255);
    __CPROVER_assume(sec_r000457_3 >= 0 && sec_r000457_3 <= 255);
    __CPROVER_assume(sec_r000457_4 >= 0 && sec_r000457_4 <= 255);
    __CPROVER_assume(sec_r000457_5 >= 0 && sec_r000457_5 <= 255);
    __CPROVER_assume(sec_r000457_6 >= 0 && sec_r000457_6 <= 255);
    __CPROVER_assume(sec_r000457_7 >= 0 && sec_r000457_7 <= 255);
    __CPROVER_assume(sec_r000457_8 >= 0 && sec_r000457_8 <= 255);
    __CPROVER_assume(sec_r000457_9 >= 0 && sec_r000457_9 <= 255);
    __CPROVER_assume(sec_r000457_10 >= 0 && sec_r000457_10 <= 255);
    __CPROVER_assume(sec_r000457_11 >= 0 && sec_r000457_11 <= 255);
    __CPROVER_assume(sec_r000457_12 >= 0 && sec_r000457_12 <= 255);
    __CPROVER_assume(sec_r000457_13 >= 0 && sec_r000457_13 <= 255);
    __CPROVER_assume(sec_r000457_14 >= 0 && sec_r000457_14 <= 255);
    __CPROVER_assume(sec_r000457_15 >= 0 && sec_r000457_15 <= 255);
    __CPROVER_assume(sec_r000457_16 >= 0 && sec_r000457_16 <= 255);
    __CPROVER_assume(sec_r000457_17 >= 0 && sec_r000457_17 <= 255);
    __CPROVER_assume(sec_r000457_18 >= 0 && sec_r000457_18 <= 255);

    struct DeviceConfig_R000457_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000457_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000457_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000457_0 + 7) & 15;
    struct MatrixBlock_R000457_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000457_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000457_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000457_0 + 9) & 15;

    union ColorPixel_R000457_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 36) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 51) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 37) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 52) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

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
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
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
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 34) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 49) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 15) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 30) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 27) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 42) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

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
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 12) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 27) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 20) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 35) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 32) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 47) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[0] ^ 74) & 3;
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
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 24) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 39) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000457_8 & 1) != 0) {
        if ((sec_r000457_4 & 2) != 0) {
            stage_v_76 = (pub_r000457_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000457_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000457_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000457_14 & 1) != 0) {
        if ((sec_r000457_3 & 2) != 0) {
            stage_v_77 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000457_7 & 1) != 0) {
        if ((sec_r000457_6 & 2) != 0) {
            stage_v_78 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000457_16 & 2) != 0) {
            stage_v_79 = (pub_r000457_11 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000457_11 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000457_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000457_14 & 2) != 0) {
            stage_v_80 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000457_17 & 2) != 0) {
            stage_v_81 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000457_10 & 2) != 0) {
            stage_v_82 = (pub_r000457_1 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000457_1 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000457_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_83 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000457_16 & 2) != 0) {
            stage_v_84 = (pub_r000457_1 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000457_1 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000457_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_85 = (pub_r000457_13 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000457_13 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000457_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000457_11 & 1) != 0) {
        if ((sec_r000457_11 & 2) != 0) {
            stage_v_86 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000457_12 & 2) != 0) {
            stage_v_87 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000457_15 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_88 = (pub_r000457_18 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000457_18 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000457_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000457_3 & 2) != 0) {
            stage_v_89 = (pub_r000457_11 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000457_11 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000457_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000457_18 & 2) != 0) {
            stage_v_90 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000457_13 & 2) != 0) {
            stage_v_91 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_92 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000457_12 & 1) != 0) {
        if ((sec_r000457_15 & 2) != 0) {
            stage_v_93 = (pub_r000457_13 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000457_13 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000457_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000457_16 & 1) != 0) {
        if ((sec_r000457_10 & 2) != 0) {
            stage_v_94 = (pub_r000457_18 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000457_18 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000457_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_95 = (pub_r000457_18 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000457_18 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000457_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000457_15 & 2) != 0) {
            stage_v_96 = (pub_r000457_11 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000457_11 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000457_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_97 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000457_15 & 2) != 0) {
            stage_v_98 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000457_9 & 1) != 0) {
        if ((sec_r000457_9 & 2) != 0) {
            stage_v_99 = (pub_r000457_13 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000457_13 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000457_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000457_2 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_100 = (pub_r000457_16 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000457_16 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000457_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000457_9 & 2) != 0) {
            stage_v_101 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000457_16 & 1) != 0) {
        if ((sec_r000457_18 & 2) != 0) {
            stage_v_102 = (pub_r000457_2 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000457_2 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000457_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000457_6 & 1) != 0) {
        if ((sec_r000457_11 & 2) != 0) {
            stage_v_103 = (pub_r000457_4 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000457_4 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000457_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000457_0 & 2) != 0) {
            stage_v_104 = (pub_r000457_3 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000457_3 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000457_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000457_16 & 2) != 0) {
            stage_v_105 = (pub_r000457_2 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000457_2 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000457_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000457_9 & 1) != 0) {
        if ((sec_r000457_3 & 2) != 0) {
            stage_v_106 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000457_5 & 1) != 0) {
        if ((sec_r000457_1 & 2) != 0) {
            stage_v_107 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000457_16 & 2) != 0) {
            stage_v_108 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000457_16 & 1) != 0) {
        if ((sec_r000457_2 & 2) != 0) {
            stage_v_109 = (pub_r000457_4 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000457_4 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000457_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000457_11 & 2) != 0) {
            stage_v_110 = (pub_r000457_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000457_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000457_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000457_2 & 2) != 0) {
            stage_v_111 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_112 = (pub_r000457_9 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000457_9 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000457_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000457_17 & 2) != 0) {
            stage_v_113 = (pub_r000457_7 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000457_7 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000457_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000457_6 & 1) != 0) {
        if ((sec_r000457_15 & 2) != 0) {
            stage_v_114 = (pub_r000457_10 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000457_10 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000457_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000457_8 & 2) != 0) {
            stage_v_115 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000457_6 & 2) != 0) {
            stage_v_116 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000457_2 & 2) != 0) {
            stage_v_117 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000457_17 & 2) != 0) {
            stage_v_118 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000457_12 & 2) != 0) {
            stage_v_119 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000457_0 & 2) != 0) {
            stage_v_120 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000457_4 & 1) != 0) {
        if ((sec_r000457_13 & 2) != 0) {
            stage_v_121 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000457_16 & 2) != 0) {
            stage_v_122 = (pub_r000457_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000457_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000457_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000457_7 & 1) != 0) {
        if ((sec_r000457_12 & 2) != 0) {
            stage_v_123 = (pub_r000457_17 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000457_17 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000457_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000457_9 & 1) != 0) {
        if ((sec_r000457_4 & 2) != 0) {
            stage_v_124 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000457_13 & 2) != 0) {
            stage_v_125 = (pub_r000457_13 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000457_13 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000457_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000457_4 & 2) != 0) {
            stage_v_126 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000457_6 & 2) != 0) {
            stage_v_127 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000457_17 & 1) != 0) {
        if ((sec_r000457_18 & 2) != 0) {
            stage_v_128 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000457_13 & 2) != 0) {
            stage_v_129 = (pub_r000457_2 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000457_2 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000457_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000457_4 & 2) != 0) {
            stage_v_130 = (pub_r000457_17 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000457_17 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000457_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000457_3 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_131 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000457_3 & 1) != 0) {
        if ((sec_r000457_8 & 2) != 0) {
            stage_v_132 = (pub_r000457_2 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000457_2 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000457_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000457_14 & 2) != 0) {
            stage_v_133 = (pub_r000457_4 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000457_4 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000457_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000457_7 & 2) != 0) {
            stage_v_134 = (pub_r000457_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000457_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000457_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000457_13 & 2) != 0) {
            stage_v_135 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000457_3 & 2) != 0) {
            stage_v_136 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000457_12 & 2) != 0) {
            stage_v_137 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000457_6 & 2) != 0) {
            stage_v_138 = (pub_r000457_11 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000457_11 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000457_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000457_4 & 1) != 0) {
        if ((sec_r000457_9 & 2) != 0) {
            stage_v_139 = (pub_r000457_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000457_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000457_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000457_11 & 2) != 0) {
            stage_v_140 = (pub_r000457_16 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000457_16 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000457_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000457_17 & 2) != 0) {
            stage_v_141 = (pub_r000457_10 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000457_10 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000457_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000457_3 & 2) != 0) {
            stage_v_142 = (pub_r000457_1 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000457_1 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000457_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000457_8 & 1) != 0) {
        if ((sec_r000457_15 & 2) != 0) {
            stage_v_143 = (pub_r000457_6 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000457_6 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000457_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_144 = (pub_r000457_7 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000457_7 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000457_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000457_15 & 1) != 0) {
        if ((sec_r000457_11 & 2) != 0) {
            stage_v_145 = (pub_r000457_17 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000457_17 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000457_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000457_17 & 1) != 0) {
        if ((sec_r000457_0 & 2) != 0) {
            stage_v_146 = (pub_r000457_14 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000457_14 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000457_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000457_14 & 2) != 0) {
            stage_v_147 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000457_5 & 2) != 0) {
            stage_v_148 = (pub_r000457_8 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000457_8 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000457_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000457_16 & 1) != 0) {
        if ((sec_r000457_4 & 2) != 0) {
            stage_v_149 = (pub_r000457_15 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000457_15 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000457_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000457_9 & 2) != 0) {
            stage_v_150 = (pub_r000457_9 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000457_9 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000457_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000457_5 & 1) != 0) {
        if ((sec_r000457_2 & 2) != 0) {
            stage_v_151 = (pub_r000457_12 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000457_12 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000457_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
