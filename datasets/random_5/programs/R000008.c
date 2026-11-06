/*
 * Benchmark Program: R000008
 * Security Family: secret_dependent_loops
 * Generator Seed: 500813
 * High Inputs: 21 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000008_813_0 {
    unsigned char envelope;
    int gain;
    unsigned char peak;
    short rms;
    int buffer[3];
};

struct DeviceConfig_R000008_813_1 {
    unsigned char baud_rate;
    unsigned char parity;
    int stop_bits;
    int timeout;
    short port;
    int buffer[3];
};

struct FilterState_R000008_813_2 {
    int cutoff;
    int prev_in;
    int prev_out;
    int damping;
    int gain_db;
    int buffer[3];
};

struct MatrixBlock_R000008_813_3 {
    short trace;
    int dim;
    unsigned char scale;
    int determinant;
    int buffer[3];
};

union RegisterBank_R000008_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000008_813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000008_813_0(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int anchor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_94 = (aux + st.buffer[1]) & 3;
    switch (sample_94) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_12 = local_arr[aux % 3];
    acc = (acc + coefficient_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000008_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int segment_81 = local_arr[aux % 3];
    acc = (acc + segment_81 * 2) & 127;
    int phase_40 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_40 > 14) {
        acc = (acc + phase_40 * 2 + 5) & 127;
        aux ^= (phase_40 & 15);
    } else {
        acc = (acc - phase_40 + 11) & 127;
        aux += 3;
    }
    int metric_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_78) & 63;
    acc ^= aux;
    int coefficient_18 = (aux + st.buffer[1]) & 3;
    switch (coefficient_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000008_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_37 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_37 > 22) {
        acc = (acc + offset_37 * 2 + 5) & 127;
        aux ^= (offset_37 & 15);
    } else {
        acc = (acc - offset_37 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_31 = local_arr[aux % 3];
    acc = (acc + phase_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_86 = (st.buffer[0] * 3 + aux) & 63;
    if (window_86 > 27) {
        acc = (acc + window_86 * 2 + 5) & 127;
        aux ^= (window_86 & 15);
    } else {
        acc = (acc - window_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000008_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int margin_29 = local_arr[aux % 3];
    acc = (acc + margin_29 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_5(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000008_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_66 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_66 > 49) {
        acc = (acc + quotient_66 * 2 + 5) & 127;
        aux ^= (quotient_66 & 15);
    } else {
        acc = (acc - quotient_66 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_10 = (aux + st.buffer[1]) & 3;
    switch (phase_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_11 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_11 > 50) {
        acc = (acc + index_reg_11 * 2 + 5) & 127;
        aux ^= (index_reg_11 & 15);
    } else {
        acc = (acc - index_reg_11 + 11) & 127;
        aux += 3;
    }
    int scale_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000008_813_7(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000008_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_34 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_34 > 18) {
        acc = (acc + accumulator_34 * 2 + 5) & 127;
        aux ^= (accumulator_34 & 15);
    } else {
        acc = (acc - accumulator_34 + 11) & 127;
        aux += 3;
    }
    int anchor_95 = (aux + st.buffer[1]) & 3;
    switch (anchor_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_27 = local_arr[aux % 3];
    acc = (acc + damping_27 * 2) & 127;
    int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000008_813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_38 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_38 > 21) {
        acc = (acc + mask_38 * 2 + 5) & 127;
        aux ^= (mask_38 & 15);
    } else {
        acc = (acc - mask_38 + 11) & 127;
        aux += 3;
    }
    int tally_14 = (aux + st.buffer[1]) & 3;
    switch (tally_14) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_73 = local_arr[aux % 3];
    acc = (acc + weight_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int phase_61 = local_arr[aux % 3];
    acc = (acc + phase_61 * 2) & 127;
    int metric_65 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_65 > 49) {
        acc = (acc + metric_65 * 2 + 5) & 127;
        aux ^= (metric_65 & 15);
    } else {
        acc = (acc - metric_65 + 11) & 127;
        aux += 3;
    }
    int cursor_53 = (aux + st.buffer[1]) & 3;
    switch (cursor_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000008_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int stride_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_87 = local_arr[aux % 3];
    acc = (acc + phase_87 * 2) & 127;
    int tally_28 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_28 > 12) {
        acc = (acc + tally_28 * 2 + 5) & 127;
        aux ^= (tally_28 & 15);
    } else {
        acc = (acc - tally_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_63) & 63;
    acc ^= aux;
    int factor_81 = (aux + st.buffer[1]) & 3;
    switch (factor_81) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_60 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_60 > 30) {
        acc = (acc + stride_60 * 2 + 5) & 127;
        aux ^= (stride_60 & 15);
    } else {
        acc = (acc - stride_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000008_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int threshold_76 = (aux + st.buffer[1]) & 3;
    switch (threshold_76) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000008_813_13(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_85 = (aux + st.buffer[1]) & 3;
    switch (anchor_85) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_33 = local_arr[aux % 3];
    acc = (acc + index_reg_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int stride_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_62 = local_arr[aux % 3];
    acc = (acc + threshold_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int delta_27 = local_arr[aux % 3];
    acc = (acc + delta_27 * 2) & 127;
    int damping_15 = (aux + st.buffer[1]) & 3;
    switch (damping_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_12) & 63;
    acc ^= aux;
    int factor_91 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_91 > 26) {
        acc = (acc + factor_91 * 2 + 5) & 127;
        aux ^= (factor_91 & 15);
    } else {
        acc = (acc - factor_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_16(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000008_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_18 > 23) {
        acc = (acc + factor_18 * 2 + 5) & 127;
        aux ^= (factor_18 & 15);
    } else {
        acc = (acc - factor_18 + 11) & 127;
        aux += 3;
    }
    int index_reg_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_26) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_89 = local_arr[aux % 3];
    acc = (acc + margin_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_61 = (aux + st.buffer[1]) & 3;
    switch (factor_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_70 = local_arr[aux % 3];
    acc = (acc + checksum_70 * 2) & 127;
    int scale_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000008_813_18(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int offset_22 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_22 > 43) {
        acc = (acc + offset_22 * 2 + 5) & 127;
        aux ^= (offset_22 & 15);
    } else {
        acc = (acc - offset_22 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000008_813_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int cursor_20 = (aux + st.buffer[1]) & 3;
    switch (cursor_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_59 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_59 > 41) {
        acc = (acc + tally_59 * 2 + 5) & 127;
        aux ^= (tally_59 & 15);
    } else {
        acc = (acc - tally_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000008_813_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000008_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_42 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_42 > 34) {
        acc = (acc + coefficient_42 * 2 + 5) & 127;
        aux ^= (coefficient_42 & 15);
    } else {
        acc = (acc - coefficient_42 + 11) & 127;
        aux += 3;
    }
    int bound_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000008_813_21(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000008_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_14 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_14 > 43) {
        acc = (acc + residue_14 * 2 + 5) & 127;
        aux ^= (residue_14 & 15);
    } else {
        acc = (acc - residue_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_12 = local_arr[aux % 3];
    acc = (acc + window_12 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000008_0;
    int sec_r000008_1;
    int sec_r000008_2;
    int sec_r000008_3;
    int sec_r000008_4;
    int sec_r000008_5;
    int sec_r000008_6;
    int sec_r000008_7;
    int sec_r000008_8;
    int sec_r000008_9;
    int sec_r000008_10;
    int sec_r000008_11;
    int sec_r000008_12;
    int sec_r000008_13;
    int sec_r000008_14;
    int sec_r000008_15;
    int sec_r000008_16;
    int sec_r000008_17;
    int sec_r000008_18;
    int sec_r000008_19;
    int sec_r000008_20;
    int pub_r000008_0;
    int pub_r000008_1;
    int pub_r000008_2;
    int pub_r000008_3;
    int pub_r000008_4;
    int pub_r000008_5;
    int pub_r000008_6;
    int pub_r000008_7;
    int pub_r000008_8;
    int pub_r000008_9;
    int pub_r000008_10;
    int pub_r000008_11;
    int pub_r000008_12;
    int pub_r000008_13;
    int pub_r000008_14;
    int pub_r000008_15;
    int pub_r000008_16;
    int pub_r000008_17;
    int pub_r000008_18;
    int pub_r000008_19;
    int pub_r000008_20;
    int pub_r000008_21;
    int pub_r000008_22;
    int pub_r000008_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000008_0 >= -100 && pub_r000008_0 <= 100);
    __CPROVER_assume(pub_r000008_1 >= -100 && pub_r000008_1 <= 100);
    __CPROVER_assume(pub_r000008_2 >= -100 && pub_r000008_2 <= 100);
    __CPROVER_assume(pub_r000008_3 >= -100 && pub_r000008_3 <= 100);
    __CPROVER_assume(pub_r000008_4 >= -100 && pub_r000008_4 <= 100);
    __CPROVER_assume(pub_r000008_5 >= -100 && pub_r000008_5 <= 100);
    __CPROVER_assume(pub_r000008_6 >= -100 && pub_r000008_6 <= 100);
    __CPROVER_assume(pub_r000008_7 >= -100 && pub_r000008_7 <= 100);
    __CPROVER_assume(pub_r000008_8 >= -100 && pub_r000008_8 <= 100);
    __CPROVER_assume(pub_r000008_9 >= -100 && pub_r000008_9 <= 100);
    __CPROVER_assume(pub_r000008_10 >= -100 && pub_r000008_10 <= 100);
    __CPROVER_assume(pub_r000008_11 >= -100 && pub_r000008_11 <= 100);
    __CPROVER_assume(pub_r000008_12 >= -100 && pub_r000008_12 <= 100);
    __CPROVER_assume(pub_r000008_13 >= -100 && pub_r000008_13 <= 100);
    __CPROVER_assume(pub_r000008_14 >= -100 && pub_r000008_14 <= 100);
    __CPROVER_assume(pub_r000008_15 >= -100 && pub_r000008_15 <= 100);
    __CPROVER_assume(pub_r000008_16 >= -100 && pub_r000008_16 <= 100);
    __CPROVER_assume(pub_r000008_17 >= -100 && pub_r000008_17 <= 100);
    __CPROVER_assume(pub_r000008_18 >= -100 && pub_r000008_18 <= 100);
    __CPROVER_assume(pub_r000008_19 >= -100 && pub_r000008_19 <= 100);
    __CPROVER_assume(pub_r000008_20 >= -100 && pub_r000008_20 <= 100);
    __CPROVER_assume(pub_r000008_21 >= -100 && pub_r000008_21 <= 100);
    __CPROVER_assume(pub_r000008_22 >= -100 && pub_r000008_22 <= 100);
    __CPROVER_assume(pub_r000008_23 >= -100 && pub_r000008_23 <= 100);
    __CPROVER_assume(sec_r000008_0 >= 0 && sec_r000008_0 <= 255);
    __CPROVER_assume(sec_r000008_1 >= 0 && sec_r000008_1 <= 255);
    __CPROVER_assume(sec_r000008_2 >= 0 && sec_r000008_2 <= 255);
    __CPROVER_assume(sec_r000008_3 >= 0 && sec_r000008_3 <= 255);
    __CPROVER_assume(sec_r000008_4 >= 0 && sec_r000008_4 <= 255);
    __CPROVER_assume(sec_r000008_5 >= 0 && sec_r000008_5 <= 255);
    __CPROVER_assume(sec_r000008_6 >= 0 && sec_r000008_6 <= 255);
    __CPROVER_assume(sec_r000008_7 >= 0 && sec_r000008_7 <= 255);
    __CPROVER_assume(sec_r000008_8 >= 0 && sec_r000008_8 <= 255);
    __CPROVER_assume(sec_r000008_9 >= 0 && sec_r000008_9 <= 255);
    __CPROVER_assume(sec_r000008_10 >= 0 && sec_r000008_10 <= 255);
    __CPROVER_assume(sec_r000008_11 >= 0 && sec_r000008_11 <= 255);
    __CPROVER_assume(sec_r000008_12 >= 0 && sec_r000008_12 <= 255);
    __CPROVER_assume(sec_r000008_13 >= 0 && sec_r000008_13 <= 255);
    __CPROVER_assume(sec_r000008_14 >= 0 && sec_r000008_14 <= 255);
    __CPROVER_assume(sec_r000008_15 >= 0 && sec_r000008_15 <= 255);
    __CPROVER_assume(sec_r000008_16 >= 0 && sec_r000008_16 <= 255);
    __CPROVER_assume(sec_r000008_17 >= 0 && sec_r000008_17 <= 255);
    __CPROVER_assume(sec_r000008_18 >= 0 && sec_r000008_18 <= 255);
    __CPROVER_assume(sec_r000008_19 >= 0 && sec_r000008_19 <= 255);
    __CPROVER_assume(sec_r000008_20 >= 0 && sec_r000008_20 <= 255);

    struct AudioFrame_R000008_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000008_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000008_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000008_0 + 7) & 15;
    struct DeviceConfig_R000008_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000008_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000008_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000008_0 + 9) & 15;
    struct FilterState_R000008_813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000008_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000008_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000008_0 + 11) & 15;
    struct MatrixBlock_R000008_813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000008_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000008_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000008_0 + 13) & 15;

    union RegisterBank_R000008_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 20) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 35) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 25) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 40) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
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
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 15) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 30) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

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
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

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
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 22) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 37) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
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
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 14) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 29) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 18) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 33) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 52) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 29) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 44) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 32) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 47) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_2.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 31) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 46) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_3.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 41) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_4 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000008_12) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000008_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000008_3) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000008_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_19 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000008_10) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000008_15) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000008_6) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000008_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_18 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000008_5) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000008_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000008_15) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000008_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000008_15) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000008_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_8 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000008_4) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_18 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000008_4) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000008_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_12 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000008_16) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000008_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000008_7) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000008_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_3 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000008_2) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000008_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000008_21) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000008_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000008_7) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000008_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_11 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000008_6) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000008_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000008_18) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000008_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_4 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000008_10) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000008_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_15 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000008_5) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000008_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_10 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000008_21) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000008_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_1 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000008_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000008_3) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000008_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000008_9) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000008_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000008_14) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000008_4) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000008_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_7 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000008_6) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000008_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_14 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000008_16) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000008_17) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000008_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_3 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000008_12) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000008_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000008_2) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000008_9) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000008_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000008_20) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000008_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000008_10) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000008_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000008_19) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000008_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000008_14) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000008_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_17 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000008_3) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000008_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000008_22) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000008_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000008_17) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000008_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_7 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000008_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_16 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000008_9) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000008_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000008_14) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000008_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000008_4) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000008_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000008_16) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_10 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000008_2) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000008_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000008_7) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000008_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000008_12) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_19 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000008_18) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000008_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_10 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000008_19) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000008_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000008_8) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000008_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000008_5) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000008_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000008_9) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000008_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_7 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000008_6) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000008_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000008_23) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000008_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000008_8) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000008_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_18 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000008_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000008_8) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000008_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_10 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000008_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_19 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000008_7) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000008_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000008_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000008_0) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000008_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_5 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000008_16) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000008_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000008_10) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000008_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_8 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000008_14) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000008_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_139 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000008_4) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000008_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_3 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000008_19) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000008_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_7 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000008_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_12 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000008_14) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000008_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000008_2) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000008_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000008_14 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000008_11) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000008_3) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000008_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000008_20) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000008_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_137 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000008_8) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000008_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000008_20) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000008_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
