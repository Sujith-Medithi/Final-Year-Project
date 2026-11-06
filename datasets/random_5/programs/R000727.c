/*
 * Benchmark Program: R000727
 * Security Family: nested_implicit_flow
 * Generator Seed: 572713
 * High Inputs: 22 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000727_2713_0 {
    unsigned char fee;
    unsigned char auth_code;
    unsigned char balance;
    int buffer[3];
};

struct DeviceConfig_R000727_2713_1 {
    int timeout;
    unsigned char parity;
    short id;
    int baud_rate;
    short stop_bits;
    short port;
    int buffer[3];
};

union PacketPayload_R000727_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000727_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000727_2713_0(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int delta_55 = (aux + st.buffer[1]) & 3;
    switch (delta_55) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000727_2713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_18 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_18 > 47) {
        acc = (acc + segment_18 * 2 + 5) & 127;
        aux ^= (segment_18 & 15);
    } else {
        acc = (acc - segment_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_38 = (aux + st.buffer[1]) & 3;
    switch (mask_38) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000727_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int stride_44 = local_arr[aux % 3];
    acc = (acc + stride_44 * 2) & 127;
    int damping_16 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_16 > 15) {
        acc = (acc + damping_16 * 2 + 5) & 127;
        aux ^= (damping_16 & 15);
    } else {
        acc = (acc - damping_16 + 11) & 127;
        aux += 3;
    }
    int tally_73 = (aux + st.buffer[1]) & 3;
    switch (tally_73) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int threshold_34 = (aux + st.buffer[1]) & 3;
    switch (threshold_34) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_49 = local_arr[aux % 3];
    acc = (acc + residue_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_94 = (aux + st.buffer[1]) & 3;
    switch (metric_94) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_34 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_34 > 34) {
        acc = (acc + sample_34 * 2 + 5) & 127;
        aux ^= (sample_34 & 15);
    } else {
        acc = (acc - sample_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000727_2713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_12 = local_arr[aux % 3];
    acc = (acc + window_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int stride_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_27) & 63;
    acc ^= aux;
    int coefficient_82 = (aux + st.buffer[1]) & 3;
    switch (coefficient_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_18 = local_arr[aux % 3];
    acc = (acc + segment_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_56 = (aux + st.buffer[1]) & 3;
    switch (factor_56) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_13 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_13 > 27) {
        acc = (acc + segment_13 * 2 + 5) & 127;
        aux ^= (segment_13 & 15);
    } else {
        acc = (acc - segment_13 + 11) & 127;
        aux += 3;
    }
    int stride_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000727_2713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tracker_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_91) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_51 = local_arr[aux % 3];
    acc = (acc + factor_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_19 = (aux + st.buffer[1]) & 3;
    switch (quotient_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000727_2713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_22 = (aux + st.buffer[1]) & 3;
    switch (quantum_22) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_44 = local_arr[aux % 3];
    acc = (acc + index_reg_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_70 = (aux + st.buffer[1]) & 3;
    switch (metric_70) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000727_2713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_71 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_71 > 19) {
        acc = (acc + quotient_71 * 2 + 5) & 127;
        aux ^= (quotient_71 & 15);
    } else {
        acc = (acc - quotient_71 + 11) & 127;
        aux += 3;
    }
    int factor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000727_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int scale_57 = local_arr[aux % 3];
    acc = (acc + scale_57 * 2) & 127;
    int index_reg_32 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_32 > 43) {
        acc = (acc + index_reg_32 * 2 + 5) & 127;
        aux ^= (index_reg_32 & 15);
    } else {
        acc = (acc - index_reg_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000727_2713_14(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int segment_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_57 = (aux + st.buffer[1]) & 3;
    switch (quantum_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_68 = local_arr[aux % 3];
    acc = (acc + coefficient_68 * 2) & 127;
    int tally_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000727_2713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int metric_99 = (aux + st.buffer[1]) & 3;
    switch (metric_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_80 = local_arr[aux % 3];
    acc = (acc + quotient_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_17(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000727_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_24 = (aux + st.buffer[1]) & 3;
    switch (pivot_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_41 = local_arr[aux % 3];
    acc = (acc + anchor_41 * 2) & 127;
    int weight_48 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_48 > 21) {
        acc = (acc + weight_48 * 2 + 5) & 127;
        aux ^= (weight_48 & 15);
    } else {
        acc = (acc - weight_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000727_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_96 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_96 > 31) {
        acc = (acc + delta_96 * 2 + 5) & 127;
        aux ^= (delta_96 & 15);
    } else {
        acc = (acc - delta_96 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_67 = local_arr[aux % 3];
    acc = (acc + mask_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000727_2713_19(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000727_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_48) & 63;
    acc ^= aux;
    int stride_12 = (aux + st.buffer[1]) & 3;
    switch (stride_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000727_0;
    int sec_r000727_1;
    int sec_r000727_2;
    int sec_r000727_3;
    int sec_r000727_4;
    int sec_r000727_5;
    int sec_r000727_6;
    int sec_r000727_7;
    int sec_r000727_8;
    int sec_r000727_9;
    int sec_r000727_10;
    int sec_r000727_11;
    int sec_r000727_12;
    int sec_r000727_13;
    int sec_r000727_14;
    int sec_r000727_15;
    int sec_r000727_16;
    int sec_r000727_17;
    int sec_r000727_18;
    int sec_r000727_19;
    int sec_r000727_20;
    int sec_r000727_21;
    int pub_r000727_0;
    int pub_r000727_1;
    int pub_r000727_2;
    int pub_r000727_3;
    int pub_r000727_4;
    int pub_r000727_5;
    int pub_r000727_6;
    int pub_r000727_7;
    int pub_r000727_8;
    int pub_r000727_9;
    int pub_r000727_10;
    int pub_r000727_11;
    int pub_r000727_12;
    int pub_r000727_13;
    int pub_r000727_14;
    int pub_r000727_15;
    int pub_r000727_16;
    int pub_r000727_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000727_0 >= -100 && pub_r000727_0 <= 100);
    __CPROVER_assume(pub_r000727_1 >= -100 && pub_r000727_1 <= 100);
    __CPROVER_assume(pub_r000727_2 >= -100 && pub_r000727_2 <= 100);
    __CPROVER_assume(pub_r000727_3 >= -100 && pub_r000727_3 <= 100);
    __CPROVER_assume(pub_r000727_4 >= -100 && pub_r000727_4 <= 100);
    __CPROVER_assume(pub_r000727_5 >= -100 && pub_r000727_5 <= 100);
    __CPROVER_assume(pub_r000727_6 >= -100 && pub_r000727_6 <= 100);
    __CPROVER_assume(pub_r000727_7 >= -100 && pub_r000727_7 <= 100);
    __CPROVER_assume(pub_r000727_8 >= -100 && pub_r000727_8 <= 100);
    __CPROVER_assume(pub_r000727_9 >= -100 && pub_r000727_9 <= 100);
    __CPROVER_assume(pub_r000727_10 >= -100 && pub_r000727_10 <= 100);
    __CPROVER_assume(pub_r000727_11 >= -100 && pub_r000727_11 <= 100);
    __CPROVER_assume(pub_r000727_12 >= -100 && pub_r000727_12 <= 100);
    __CPROVER_assume(pub_r000727_13 >= -100 && pub_r000727_13 <= 100);
    __CPROVER_assume(pub_r000727_14 >= -100 && pub_r000727_14 <= 100);
    __CPROVER_assume(pub_r000727_15 >= -100 && pub_r000727_15 <= 100);
    __CPROVER_assume(pub_r000727_16 >= -100 && pub_r000727_16 <= 100);
    __CPROVER_assume(pub_r000727_17 >= -100 && pub_r000727_17 <= 100);
    __CPROVER_assume(sec_r000727_0 >= 0 && sec_r000727_0 <= 255);
    __CPROVER_assume(sec_r000727_1 >= 0 && sec_r000727_1 <= 255);
    __CPROVER_assume(sec_r000727_2 >= 0 && sec_r000727_2 <= 255);
    __CPROVER_assume(sec_r000727_3 >= 0 && sec_r000727_3 <= 255);
    __CPROVER_assume(sec_r000727_4 >= 0 && sec_r000727_4 <= 255);
    __CPROVER_assume(sec_r000727_5 >= 0 && sec_r000727_5 <= 255);
    __CPROVER_assume(sec_r000727_6 >= 0 && sec_r000727_6 <= 255);
    __CPROVER_assume(sec_r000727_7 >= 0 && sec_r000727_7 <= 255);
    __CPROVER_assume(sec_r000727_8 >= 0 && sec_r000727_8 <= 255);
    __CPROVER_assume(sec_r000727_9 >= 0 && sec_r000727_9 <= 255);
    __CPROVER_assume(sec_r000727_10 >= 0 && sec_r000727_10 <= 255);
    __CPROVER_assume(sec_r000727_11 >= 0 && sec_r000727_11 <= 255);
    __CPROVER_assume(sec_r000727_12 >= 0 && sec_r000727_12 <= 255);
    __CPROVER_assume(sec_r000727_13 >= 0 && sec_r000727_13 <= 255);
    __CPROVER_assume(sec_r000727_14 >= 0 && sec_r000727_14 <= 255);
    __CPROVER_assume(sec_r000727_15 >= 0 && sec_r000727_15 <= 255);
    __CPROVER_assume(sec_r000727_16 >= 0 && sec_r000727_16 <= 255);
    __CPROVER_assume(sec_r000727_17 >= 0 && sec_r000727_17 <= 255);
    __CPROVER_assume(sec_r000727_18 >= 0 && sec_r000727_18 <= 255);
    __CPROVER_assume(sec_r000727_19 >= 0 && sec_r000727_19 <= 255);
    __CPROVER_assume(sec_r000727_20 >= 0 && sec_r000727_20 <= 255);
    __CPROVER_assume(sec_r000727_21 >= 0 && sec_r000727_21 <= 255);

    struct Transaction_R000727_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000727_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000727_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000727_0 + 7) & 15;
    struct DeviceConfig_R000727_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000727_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000727_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000727_0 + 9) & 15;

    union PacketPayload_R000727_2713_0 u_var;
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
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 21) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 36) {
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

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
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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
    if (stage_v_28 > 15) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 30) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 34) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 49) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 22) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 37) {
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
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 11) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 26) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 26) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 41) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 38) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 53) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 25) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 40) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 17) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 32) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 38) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 53) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 31) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 46) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 32) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 47) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 34) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 49) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (out_sink > 100) ? (chk_sum & 31) : (92 & 31);
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= (stage_v_87 << 1) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000727_20 & 1) != 0) {
        if ((sec_r000727_18 & 2) != 0) {
            stage_v_91 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000727_8 & 2) != 0) {
            stage_v_92 = (pub_r000727_7 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000727_7 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000727_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000727_11 & 2) != 0) {
            stage_v_93 = (pub_r000727_12 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000727_12 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000727_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000727_7 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_94 = (pub_r000727_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000727_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000727_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000727_14 & 2) != 0) {
            stage_v_95 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000727_8 & 2) != 0) {
            stage_v_96 = (pub_r000727_16 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000727_16 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000727_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000727_21 & 1) != 0) {
        if ((sec_r000727_4 & 2) != 0) {
            stage_v_97 = (pub_r000727_11 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000727_11 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000727_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_0 & 2) != 0) {
            stage_v_98 = (pub_r000727_11 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000727_11 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000727_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000727_19 & 1) != 0) {
        if ((sec_r000727_21 & 2) != 0) {
            stage_v_99 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000727_7 & 2) != 0) {
            stage_v_100 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_101 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000727_0 & 2) != 0) {
            stage_v_102 = (pub_r000727_7 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000727_7 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000727_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000727_19 & 2) != 0) {
            stage_v_103 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000727_10 & 2) != 0) {
            stage_v_104 = (pub_r000727_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000727_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000727_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_105 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000727_4 & 2) != 0) {
            stage_v_106 = (pub_r000727_16 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000727_16 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000727_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000727_13 & 2) != 0) {
            stage_v_107 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000727_18 & 2) != 0) {
            stage_v_108 = (pub_r000727_7 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000727_7 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000727_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000727_19 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_109 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000727_13 & 1) != 0) {
        if ((sec_r000727_16 & 2) != 0) {
            stage_v_110 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000727_12 & 2) != 0) {
            stage_v_111 = (pub_r000727_10 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000727_10 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000727_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000727_6 & 2) != 0) {
            stage_v_112 = (pub_r000727_3 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000727_3 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000727_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000727_9 & 2) != 0) {
            stage_v_113 = (pub_r000727_10 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000727_10 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000727_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_114 = (pub_r000727_5 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000727_5 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000727_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000727_9 & 1) != 0) {
        if ((sec_r000727_15 & 2) != 0) {
            stage_v_115 = (pub_r000727_7 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000727_7 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000727_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000727_5 & 2) != 0) {
            stage_v_116 = (pub_r000727_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000727_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000727_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000727_0 & 2) != 0) {
            stage_v_117 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000727_1 & 1) != 0) {
        if ((sec_r000727_5 & 2) != 0) {
            stage_v_118 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000727_15 & 2) != 0) {
            stage_v_119 = (pub_r000727_6 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000727_6 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000727_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000727_9 & 1) != 0) {
        if ((sec_r000727_19 & 2) != 0) {
            stage_v_120 = (pub_r000727_15 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000727_15 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000727_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000727_15 & 1) != 0) {
        if ((sec_r000727_2 & 2) != 0) {
            stage_v_121 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000727_4 & 2) != 0) {
            stage_v_122 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000727_7 & 2) != 0) {
            stage_v_123 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000727_17 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_124 = (pub_r000727_16 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000727_16 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000727_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000727_2 & 1) != 0) {
        if ((sec_r000727_16 & 2) != 0) {
            stage_v_125 = (pub_r000727_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000727_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000727_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000727_2 & 2) != 0) {
            stage_v_126 = (pub_r000727_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000727_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000727_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000727_1 & 1) != 0) {
        if ((sec_r000727_11 & 2) != 0) {
            stage_v_127 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000727_0 & 2) != 0) {
            stage_v_128 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000727_17 & 1) != 0) {
        if ((sec_r000727_12 & 2) != 0) {
            stage_v_129 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_130 = (pub_r000727_6 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000727_6 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000727_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000727_8 & 2) != 0) {
            stage_v_131 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_132 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000727_8 & 1) != 0) {
        if ((sec_r000727_19 & 2) != 0) {
            stage_v_133 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_13 & 2) != 0) {
            stage_v_134 = (pub_r000727_10 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000727_10 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000727_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000727_5 & 1) != 0) {
        if ((sec_r000727_7 & 2) != 0) {
            stage_v_135 = (pub_r000727_4 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000727_4 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000727_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000727_2 & 2) != 0) {
            stage_v_136 = (pub_r000727_12 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000727_12 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000727_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000727_15 & 1) != 0) {
        if ((sec_r000727_14 & 2) != 0) {
            stage_v_137 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_138 = (pub_r000727_13 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000727_13 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000727_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000727_9 & 2) != 0) {
            stage_v_139 = (pub_r000727_15 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000727_15 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000727_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_140 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000727_16 & 2) != 0) {
            stage_v_141 = (pub_r000727_12 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000727_12 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000727_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000727_17 & 1) != 0) {
        if ((sec_r000727_2 & 2) != 0) {
            stage_v_142 = (pub_r000727_12 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000727_12 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000727_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000727_19 & 2) != 0) {
            stage_v_143 = (pub_r000727_5 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000727_5 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000727_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_144 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000727_7 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_145 = (pub_r000727_1 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000727_1 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000727_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000727_5 & 1) != 0) {
        if ((sec_r000727_18 & 2) != 0) {
            stage_v_146 = (pub_r000727_4 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000727_4 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000727_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000727_1 & 2) != 0) {
            stage_v_147 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000727_16 & 1) != 0) {
        if ((sec_r000727_18 & 2) != 0) {
            stage_v_148 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000727_19 & 1) != 0) {
        if ((sec_r000727_16 & 2) != 0) {
            stage_v_149 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_150 = (pub_r000727_10 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000727_10 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000727_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000727_9 & 1) != 0) {
        if ((sec_r000727_4 & 2) != 0) {
            stage_v_151 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000727_21 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_152 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000727_5 & 2) != 0) {
            stage_v_153 = (pub_r000727_12 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000727_12 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000727_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000727_20 & 1) != 0) {
        if ((sec_r000727_3 & 2) != 0) {
            stage_v_154 = (pub_r000727_17 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000727_17 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000727_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000727_21 & 2) != 0) {
            stage_v_155 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000727_0 & 2) != 0) {
            stage_v_156 = (pub_r000727_11 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000727_11 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000727_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000727_16 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_157 = (pub_r000727_10 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000727_10 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000727_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_8 & 2) != 0) {
            stage_v_158 = (pub_r000727_1 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000727_1 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000727_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000727_9 & 2) != 0) {
            stage_v_159 = (pub_r000727_0 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000727_0 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000727_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000727_6 & 1) != 0) {
        if ((sec_r000727_11 & 2) != 0) {
            stage_v_160 = (pub_r000727_4 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000727_4 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000727_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000727_15 & 2) != 0) {
            stage_v_161 = (pub_r000727_9 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000727_9 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000727_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000727_4 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_162 = (pub_r000727_3 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000727_3 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000727_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000727_9 & 2) != 0) {
            stage_v_163 = (pub_r000727_4 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000727_4 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000727_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000727_1 & 1) != 0) {
        if ((sec_r000727_13 & 2) != 0) {
            stage_v_164 = (pub_r000727_6 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000727_6 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000727_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000727_9 & 1) != 0) {
        if ((sec_r000727_16 & 2) != 0) {
            stage_v_165 = (pub_r000727_2 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000727_2 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000727_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_156 & 1) != 0) {
        if ((sec_r000727_17 & 2) != 0) {
            stage_v_166 = (pub_r000727_1 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000727_1 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000727_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000727_20 & 2) != 0) {
            stage_v_167 = (pub_r000727_8 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000727_8 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000727_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
