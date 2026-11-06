/*
 * Benchmark Program: R000707
 * Security Family: nested_implicit_flow
 * Generator Seed: 570713
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000707_713_0 {
    unsigned char peak;
    unsigned char channels;
    short sample_rate;
    unsigned char rms;
    int buffer[3];
};

struct DeviceConfig_R000707_713_1 {
    short stop_bits;
    int baud_rate;
    short port;
    short parity;
    int timeout;
    int id;
    int buffer[3];
};

struct SensorNode_R000707_713_2 {
    int reading;
    unsigned char threshold;
    short offset;
    int buffer[3];
};

struct Vector3D_R000707_713_3 {
    short coord_x;
    short coord_y;
    int heading;
    unsigned char norm_sq;
    int buffer[3];
};

union ColorPixel_R000707_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000707_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000707_713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000707_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int metric_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_75) & 63;
    acc ^= aux;
    int checksum_81 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_81 > 34) {
        acc = (acc + checksum_81 * 2 + 5) & 127;
        aux ^= (checksum_81 & 15);
    } else {
        acc = (acc - checksum_81 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000707_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_73 = (aux + st.buffer[1]) & 3;
    switch (window_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_2(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000707_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int scale_11 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_11 > 42) {
        acc = (acc + scale_11 * 2 + 5) & 127;
        aux ^= (scale_11 & 15);
    } else {
        acc = (acc - scale_11 + 11) & 127;
        aux += 3;
    }
    int tally_17 = (aux + st.buffer[1]) & 3;
    switch (tally_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_91 = local_arr[aux % 3];
    acc = (acc + weight_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_3(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000707_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tally_64 = local_arr[aux % 3];
    acc = (acc + tally_64 * 2) & 127;
    int vector_70 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_70 > 27) {
        acc = (acc + vector_70 * 2 + 5) & 127;
        aux ^= (vector_70 & 15);
    } else {
        acc = (acc - vector_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_4(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_88) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_33 = local_arr[aux % 3];
    acc = (acc + weight_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_5(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_25 = local_arr[aux % 3];
    acc = (acc + weight_25 * 2) & 127;
    int anchor_23 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_23 > 32) {
        acc = (acc + anchor_23 * 2 + 5) & 127;
        aux ^= (anchor_23 & 15);
    } else {
        acc = (acc - anchor_23 + 11) & 127;
        aux += 3;
    }
    int coefficient_97 = (aux + st.buffer[1]) & 3;
    switch (coefficient_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_6(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000707_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_27 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_27 > 29) {
        acc = (acc + mask_27 * 2 + 5) & 127;
        aux ^= (mask_27 & 15);
    } else {
        acc = (acc - mask_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_55 = local_arr[aux % 3];
    acc = (acc + tally_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_7(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000707_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_88 = local_arr[aux % 3];
    acc = (acc + pivot_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_52 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_52 > 29) {
        acc = (acc + delta_52 * 2 + 5) & 127;
        aux ^= (delta_52 & 15);
    } else {
        acc = (acc - delta_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000707_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int anchor_22 = local_arr[aux % 3];
    acc = (acc + anchor_22 * 2) & 127;
    int quotient_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_66) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_9(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_32 = local_arr[aux % 3];
    acc = (acc + coefficient_32 * 2) & 127;
    int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000707_713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000707_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_69) & 63;
    acc ^= aux;
    int index_reg_16 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_16 > 33) {
        acc = (acc + index_reg_16 * 2 + 5) & 127;
        aux ^= (index_reg_16 & 15);
    } else {
        acc = (acc - index_reg_16 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_99 = (aux + st.buffer[1]) & 3;
    switch (mask_99) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_11(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_51 = (aux + st.buffer[1]) & 3;
    switch (window_51) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_25) & 63;
    acc ^= aux;
    int sample_50 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_50 > 34) {
        acc = (acc + sample_50 * 2 + 5) & 127;
        aux ^= (sample_50 & 15);
    } else {
        acc = (acc - sample_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_12(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int damping_99 = local_arr[aux % 3];
    acc = (acc + damping_99 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_13(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_85 = (aux + st.buffer[1]) & 3;
    switch (damping_85) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_99 > 30) {
        acc = (acc + anchor_99 * 2 + 5) & 127;
        aux ^= (anchor_99 & 15);
    } else {
        acc = (acc - anchor_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_93 = local_arr[aux % 3];
    acc = (acc + stride_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_14(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000707_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_84) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_98 = local_arr[aux % 3];
    acc = (acc + pivot_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000707_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_55 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_55 > 49) {
        acc = (acc + phase_55 * 2 + 5) & 127;
        aux ^= (phase_55 & 15);
    } else {
        acc = (acc - phase_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000707_713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000707_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int factor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_20 > 21) {
        acc = (acc + factor_20 * 2 + 5) & 127;
        aux ^= (factor_20 & 15);
    } else {
        acc = (acc - factor_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_17(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000707_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int anchor_59 = local_arr[aux % 3];
    acc = (acc + anchor_59 * 2) & 127;
    int coefficient_74 = (aux + st.buffer[1]) & 3;
    switch (coefficient_74) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_37) & 63;
    acc ^= aux;
    int sample_67 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_67 > 22) {
        acc = (acc + sample_67 * 2 + 5) & 127;
        aux ^= (sample_67 & 15);
    } else {
        acc = (acc - sample_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000707_713_18(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000707_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_94) & 63;
    acc ^= aux;
    int factor_86 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_86 > 10) {
        acc = (acc + factor_86 * 2 + 5) & 127;
        aux ^= (factor_86 & 15);
    } else {
        acc = (acc - factor_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000707_0;
    int sec_r000707_1;
    int sec_r000707_2;
    int sec_r000707_3;
    int sec_r000707_4;
    int sec_r000707_5;
    int sec_r000707_6;
    int sec_r000707_7;
    int sec_r000707_8;
    int sec_r000707_9;
    int sec_r000707_10;
    int sec_r000707_11;
    int sec_r000707_12;
    int sec_r000707_13;
    int sec_r000707_14;
    int sec_r000707_15;
    int sec_r000707_16;
    int sec_r000707_17;
    int sec_r000707_18;
    int sec_r000707_19;
    int sec_r000707_20;
    int sec_r000707_21;
    int sec_r000707_22;
    int sec_r000707_23;
    int pub_r000707_0;
    int pub_r000707_1;
    int pub_r000707_2;
    int pub_r000707_3;
    int pub_r000707_4;
    int pub_r000707_5;
    int pub_r000707_6;
    int pub_r000707_7;
    int pub_r000707_8;
    int pub_r000707_9;
    int pub_r000707_10;
    int pub_r000707_11;
    int pub_r000707_12;
    int pub_r000707_13;
    int pub_r000707_14;
    int pub_r000707_15;
    int pub_r000707_16;
    int pub_r000707_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000707_0 >= -100 && pub_r000707_0 <= 100);
    __CPROVER_assume(pub_r000707_1 >= -100 && pub_r000707_1 <= 100);
    __CPROVER_assume(pub_r000707_2 >= -100 && pub_r000707_2 <= 100);
    __CPROVER_assume(pub_r000707_3 >= -100 && pub_r000707_3 <= 100);
    __CPROVER_assume(pub_r000707_4 >= -100 && pub_r000707_4 <= 100);
    __CPROVER_assume(pub_r000707_5 >= -100 && pub_r000707_5 <= 100);
    __CPROVER_assume(pub_r000707_6 >= -100 && pub_r000707_6 <= 100);
    __CPROVER_assume(pub_r000707_7 >= -100 && pub_r000707_7 <= 100);
    __CPROVER_assume(pub_r000707_8 >= -100 && pub_r000707_8 <= 100);
    __CPROVER_assume(pub_r000707_9 >= -100 && pub_r000707_9 <= 100);
    __CPROVER_assume(pub_r000707_10 >= -100 && pub_r000707_10 <= 100);
    __CPROVER_assume(pub_r000707_11 >= -100 && pub_r000707_11 <= 100);
    __CPROVER_assume(pub_r000707_12 >= -100 && pub_r000707_12 <= 100);
    __CPROVER_assume(pub_r000707_13 >= -100 && pub_r000707_13 <= 100);
    __CPROVER_assume(pub_r000707_14 >= -100 && pub_r000707_14 <= 100);
    __CPROVER_assume(pub_r000707_15 >= -100 && pub_r000707_15 <= 100);
    __CPROVER_assume(pub_r000707_16 >= -100 && pub_r000707_16 <= 100);
    __CPROVER_assume(pub_r000707_17 >= -100 && pub_r000707_17 <= 100);
    __CPROVER_assume(sec_r000707_0 >= 0 && sec_r000707_0 <= 255);
    __CPROVER_assume(sec_r000707_1 >= 0 && sec_r000707_1 <= 255);
    __CPROVER_assume(sec_r000707_2 >= 0 && sec_r000707_2 <= 255);
    __CPROVER_assume(sec_r000707_3 >= 0 && sec_r000707_3 <= 255);
    __CPROVER_assume(sec_r000707_4 >= 0 && sec_r000707_4 <= 255);
    __CPROVER_assume(sec_r000707_5 >= 0 && sec_r000707_5 <= 255);
    __CPROVER_assume(sec_r000707_6 >= 0 && sec_r000707_6 <= 255);
    __CPROVER_assume(sec_r000707_7 >= 0 && sec_r000707_7 <= 255);
    __CPROVER_assume(sec_r000707_8 >= 0 && sec_r000707_8 <= 255);
    __CPROVER_assume(sec_r000707_9 >= 0 && sec_r000707_9 <= 255);
    __CPROVER_assume(sec_r000707_10 >= 0 && sec_r000707_10 <= 255);
    __CPROVER_assume(sec_r000707_11 >= 0 && sec_r000707_11 <= 255);
    __CPROVER_assume(sec_r000707_12 >= 0 && sec_r000707_12 <= 255);
    __CPROVER_assume(sec_r000707_13 >= 0 && sec_r000707_13 <= 255);
    __CPROVER_assume(sec_r000707_14 >= 0 && sec_r000707_14 <= 255);
    __CPROVER_assume(sec_r000707_15 >= 0 && sec_r000707_15 <= 255);
    __CPROVER_assume(sec_r000707_16 >= 0 && sec_r000707_16 <= 255);
    __CPROVER_assume(sec_r000707_17 >= 0 && sec_r000707_17 <= 255);
    __CPROVER_assume(sec_r000707_18 >= 0 && sec_r000707_18 <= 255);
    __CPROVER_assume(sec_r000707_19 >= 0 && sec_r000707_19 <= 255);
    __CPROVER_assume(sec_r000707_20 >= 0 && sec_r000707_20 <= 255);
    __CPROVER_assume(sec_r000707_21 >= 0 && sec_r000707_21 <= 255);
    __CPROVER_assume(sec_r000707_22 >= 0 && sec_r000707_22 <= 255);
    __CPROVER_assume(sec_r000707_23 >= 0 && sec_r000707_23 <= 255);

    struct AudioFrame_R000707_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000707_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000707_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000707_0 + 7) & 15;
    struct DeviceConfig_R000707_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000707_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000707_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000707_0 + 9) & 15;
    struct SensorNode_R000707_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000707_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000707_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000707_0 + 11) & 15;
    struct Vector3D_R000707_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000707_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000707_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000707_0 + 13) & 15;

    union ColorPixel_R000707_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 23) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 38) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 15) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 30) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

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
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 12) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 27) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 18) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 33) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
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
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 23) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 38) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 18) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 33) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 39) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 54) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 29) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 44) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] ^ 78) & 3;
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
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 36) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 51) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (out_sink > 100) ? (chk_sum & 31) : (92 & 31);
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= (stage_v_87 << 1) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000707_3 & 1) != 0) {
        if ((sec_r000707_1 & 2) != 0) {
            stage_v_90 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_91 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000707_3 & 1) != 0) {
        if ((sec_r000707_13 & 2) != 0) {
            stage_v_92 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000707_19 & 2) != 0) {
            stage_v_93 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000707_6 & 2) != 0) {
            stage_v_94 = (pub_r000707_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000707_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000707_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000707_14 & 2) != 0) {
            stage_v_95 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000707_2 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_96 = (pub_r000707_15 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000707_15 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000707_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000707_20 & 2) != 0) {
            stage_v_97 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000707_2 & 2) != 0) {
            stage_v_98 = (pub_r000707_13 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000707_13 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000707_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000707_15 & 2) != 0) {
            stage_v_99 = (pub_r000707_8 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000707_8 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000707_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000707_22 & 2) != 0) {
            stage_v_100 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000707_15 & 2) != 0) {
            stage_v_101 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000707_21 & 2) != 0) {
            stage_v_102 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000707_5 & 2) != 0) {
            stage_v_103 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000707_15 & 1) != 0) {
        if ((sec_r000707_14 & 2) != 0) {
            stage_v_104 = (pub_r000707_16 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000707_16 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000707_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000707_12 & 1) != 0) {
        if ((sec_r000707_21 & 2) != 0) {
            stage_v_105 = (pub_r000707_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000707_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000707_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_106 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000707_1 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_107 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000707_5 & 2) != 0) {
            stage_v_108 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000707_14 & 1) != 0) {
        if ((sec_r000707_23 & 2) != 0) {
            stage_v_109 = (pub_r000707_10 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000707_10 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000707_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000707_9 & 1) != 0) {
        if ((sec_r000707_22 & 2) != 0) {
            stage_v_110 = (pub_r000707_16 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000707_16 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000707_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000707_6 & 1) != 0) {
        if ((sec_r000707_5 & 2) != 0) {
            stage_v_111 = (pub_r000707_8 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000707_8 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000707_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000707_22 & 2) != 0) {
            stage_v_112 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000707_22 & 1) != 0) {
        if ((sec_r000707_5 & 2) != 0) {
            stage_v_113 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000707_10 & 2) != 0) {
            stage_v_114 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000707_23 & 2) != 0) {
            stage_v_115 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000707_20 & 1) != 0) {
        if ((sec_r000707_17 & 2) != 0) {
            stage_v_116 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000707_19 & 1) != 0) {
        if ((sec_r000707_4 & 2) != 0) {
            stage_v_117 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000707_14 & 2) != 0) {
            stage_v_118 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000707_13 & 2) != 0) {
            stage_v_119 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000707_9 & 2) != 0) {
            stage_v_120 = (pub_r000707_14 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000707_14 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000707_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000707_18 & 2) != 0) {
            stage_v_121 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000707_14 & 2) != 0) {
            stage_v_122 = (pub_r000707_15 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000707_15 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000707_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000707_14 & 1) != 0) {
        if ((sec_r000707_19 & 2) != 0) {
            stage_v_123 = (pub_r000707_13 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000707_13 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000707_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000707_3 & 1) != 0) {
        if ((sec_r000707_8 & 2) != 0) {
            stage_v_124 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000707_4 & 1) != 0) {
        if ((sec_r000707_7 & 2) != 0) {
            stage_v_125 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000707_10 & 1) != 0) {
        if ((sec_r000707_3 & 2) != 0) {
            stage_v_126 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000707_5 & 2) != 0) {
            stage_v_127 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000707_18 & 1) != 0) {
        if ((sec_r000707_1 & 2) != 0) {
            stage_v_128 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000707_10 & 2) != 0) {
            stage_v_129 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000707_1 & 2) != 0) {
            stage_v_130 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000707_4 & 2) != 0) {
            stage_v_131 = (pub_r000707_3 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000707_3 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000707_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_132 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000707_4 & 1) != 0) {
        if ((sec_r000707_13 & 2) != 0) {
            stage_v_133 = (pub_r000707_11 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000707_11 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000707_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000707_17 & 2) != 0) {
            stage_v_134 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000707_21 & 2) != 0) {
            stage_v_135 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000707_16 & 1) != 0) {
        if ((sec_r000707_1 & 2) != 0) {
            stage_v_136 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_137 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000707_8 & 2) != 0) {
            stage_v_138 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r000707_6 & 2) != 0) {
            stage_v_139 = (pub_r000707_15 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000707_15 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000707_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000707_4 & 2) != 0) {
            stage_v_140 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_131 & 1) != 0) {
        if ((sec_r000707_10 & 2) != 0) {
            stage_v_141 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000707_3 & 2) != 0) {
            stage_v_142 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_143 = (pub_r000707_17 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000707_17 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000707_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000707_9 & 1) != 0) {
        if ((sec_r000707_18 & 2) != 0) {
            stage_v_144 = (pub_r000707_15 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000707_15 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000707_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000707_2 & 1) != 0) {
        if ((sec_r000707_10 & 2) != 0) {
            stage_v_145 = (pub_r000707_17 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000707_17 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000707_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000707_9 & 2) != 0) {
            stage_v_146 = (pub_r000707_11 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000707_11 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000707_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000707_23 & 2) != 0) {
            stage_v_147 = (pub_r000707_8 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000707_8 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000707_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000707_7 & 1) != 0) {
        if ((sec_r000707_22 & 2) != 0) {
            stage_v_148 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000707_11 & 2) != 0) {
            stage_v_149 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000707_20 & 2) != 0) {
            stage_v_150 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000707_7 & 1) != 0) {
        if ((sec_r000707_11 & 2) != 0) {
            stage_v_151 = (pub_r000707_17 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000707_17 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000707_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000707_13 & 1) != 0) {
        if ((sec_r000707_17 & 2) != 0) {
            stage_v_152 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000707_0 & 2) != 0) {
            stage_v_153 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000707_16 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_154 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000707_9 & 2) != 0) {
            stage_v_155 = (pub_r000707_11 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000707_11 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000707_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000707_1 & 2) != 0) {
            stage_v_156 = (pub_r000707_8 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000707_8 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000707_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r000707_17 & 2) != 0) {
            stage_v_157 = (pub_r000707_16 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000707_16 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000707_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000707_7 & 1) != 0) {
        if ((sec_r000707_6 & 2) != 0) {
            stage_v_158 = (pub_r000707_9 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000707_9 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000707_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_159 = (pub_r000707_13 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000707_13 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000707_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000707_16 & 2) != 0) {
            stage_v_160 = (pub_r000707_17 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000707_17 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000707_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000707_23 & 2) != 0) {
            stage_v_161 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000707_18 & 1) != 0) {
        if ((sec_r000707_13 & 2) != 0) {
            stage_v_162 = (pub_r000707_2 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000707_2 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000707_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000707_8 & 1) != 0) {
        if ((sec_r000707_22 & 2) != 0) {
            stage_v_163 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000707_18 & 1) != 0) {
        if ((sec_r000707_3 & 2) != 0) {
            stage_v_164 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000707_21 & 1) != 0) {
        if ((sec_r000707_21 & 2) != 0) {
            stage_v_165 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000707_10 & 2) != 0) {
            stage_v_166 = (pub_r000707_7 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000707_7 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000707_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_159 & 1) != 0) {
        if ((sec_r000707_14 & 2) != 0) {
            stage_v_167 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_168 = (pub_r000707_5 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000707_5 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000707_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r000707_17 & 2) != 0) {
            stage_v_169 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r000707_7 & 2) != 0) {
            stage_v_170 = (pub_r000707_0 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000707_0 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000707_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((sec_r000707_3 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_171 = (pub_r000707_6 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000707_6 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000707_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((stage_v_171 & 1) != 0) {
        if ((sec_r000707_6 & 2) != 0) {
            stage_v_172 = (pub_r000707_13 + 31) & 127;
        } else {
            stage_v_172 = (pub_r000707_13 + 13) & 127;
        }
    } else {
        stage_v_172 = (pub_r000707_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((sec_r000707_10 & 1) != 0) {
        if ((sec_r000707_12 & 2) != 0) {
            stage_v_173 = (pub_r000707_4 + 31) & 127;
        } else {
            stage_v_173 = (pub_r000707_4 + 13) & 127;
        }
    } else {
        stage_v_173 = (pub_r000707_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000707_13 & 2) != 0) {
            stage_v_174 = (pub_r000707_12 + 31) & 127;
        } else {
            stage_v_174 = (pub_r000707_12 + 13) & 127;
        }
    } else {
        stage_v_174 = (pub_r000707_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000707_9 & 2) != 0) {
            stage_v_175 = (pub_r000707_1 + 31) & 127;
        } else {
            stage_v_175 = (pub_r000707_1 + 13) & 127;
        }
    } else {
        stage_v_175 = (pub_r000707_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
