/*
 * Benchmark Program: R001015
 * Security Family: bitwise_flow
 * Generator Seed: 601513
 * High Inputs: 20 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001015_1513_0 {
    int timeout;
    unsigned char port;
    unsigned char baud_rate;
    short id;
    int stop_bits;
    int buffer[3];
};

struct SensorNode_R001015_1513_1 {
    short reading;
    short status;
    unsigned char threshold;
    int offset;
    int buffer[3];
};

struct MatrixBlock_R001015_1513_2 {
    int stride;
    unsigned char trace;
    int dim;
    unsigned char density;
    unsigned char scale;
    short determinant;
    int buffer[3];
};

union ColorPixel_R001015_1513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001015_1513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001015_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tally_64 = local_arr[aux % 3];
    acc = (acc + tally_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001015_1513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001015_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_53 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_53 > 21) {
        acc = (acc + sample_53 * 2 + 5) & 127;
        aux ^= (sample_53 & 15);
    } else {
        acc = (acc - sample_53 + 11) & 127;
        aux += 3;
    }
    int coefficient_99 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_99 = (coefficient_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001015_1513_2(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_70 = 0;
    for (int k = 0; k < 2; k++) {
        weight_70 = (weight_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_70) & 127;
    }
    int tally_25 = (aux + st.buffer[1]) & 3;
    switch (tally_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_3(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int cursor_34 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_34 = (cursor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_34) & 127;
    }
    int accumulator_93 = (aux + st.buffer[1]) & 3;
    switch (accumulator_93) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_98 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_98 > 34) {
        acc = (acc + margin_98 * 2 + 5) & 127;
        aux ^= (margin_98 & 15);
    } else {
        acc = (acc - margin_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_10) & 63;
    acc ^= aux;
    int parity_66 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_66 > 12) {
        acc = (acc + parity_66 * 2 + 5) & 127;
        aux ^= (parity_66 & 15);
    } else {
        acc = (acc - parity_66 + 11) & 127;
        aux += 3;
    }
    int pivot_34 = (aux + st.buffer[1]) & 3;
    switch (pivot_34) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_5(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int quantum_81 = local_arr[aux % 3];
    acc = (acc + quantum_81 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_24 = 0;
    for (int k = 0; k < 2; k++) {
        segment_24 = (segment_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_24) & 127;
    }
    int margin_40 = (aux + st.buffer[1]) & 3;
    switch (margin_40) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_6(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_65 = 0;
    for (int k = 0; k < 2; k++) {
        mask_65 = (mask_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_65) & 127;
    }
    int accumulator_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_70) & 63;
    acc ^= aux;
    int stride_15 = (aux + st.buffer[1]) & 3;
    switch (stride_15) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_44 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_44 = (coefficient_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_44) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_30 = local_arr[aux % 3];
    acc = (acc + cursor_30 * 2) & 127;
    int checksum_67 = (aux + st.buffer[1]) & 3;
    switch (checksum_67) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_8(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_92 = 0;
    for (int k = 0; k < 3; k++) {
        window_92 = (window_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_92) & 127;
    }
    int phase_94 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_94 > 41) {
        acc = (acc + phase_94 * 2 + 5) & 127;
        aux ^= (phase_94 & 15);
    } else {
        acc = (acc - phase_94 + 11) & 127;
        aux += 3;
    }
    int index_reg_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001015_1513_9(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_91 = (st.buffer[0] * 3 + aux) & 63;
    if (window_91 > 41) {
        acc = (acc + window_91 * 2 + 5) & 127;
        aux ^= (window_91 & 15);
    } else {
        acc = (acc - window_91 + 11) & 127;
        aux += 3;
    }
    int tally_57 = (aux + st.buffer[1]) & 3;
    switch (tally_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_10(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int weight_72 = 0;
    for (int k = 0; k < 2; k++) {
        weight_72 = (weight_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_72) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int cursor_90 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_90 = (cursor_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_90) & 127;
    }
    int bound_45 = (aux + st.buffer[1]) & 3;
    switch (bound_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_12(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001015_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int phase_81 = local_arr[aux % 3];
    acc = (acc + phase_81 * 2) & 127;
    int stride_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_18) & 63;
    acc ^= aux;
    int phase_94 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_94 > 46) {
        acc = (acc + phase_94 * 2 + 5) & 127;
        aux ^= (phase_94 & 15);
    } else {
        acc = (acc - phase_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001015_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int offset_86 = 0;
    for (int k = 0; k < 2; k++) {
        offset_86 = (offset_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_86) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_19 = local_arr[aux % 3];
    acc = (acc + damping_19 * 2) & 127;
    int segment_78 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_78 > 26) {
        acc = (acc + segment_78 * 2 + 5) & 127;
        aux ^= (segment_78 & 15);
    } else {
        acc = (acc - segment_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_14(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_90 = local_arr[aux % 3];
    acc = (acc + index_reg_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_18 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_18 > 30) {
        acc = (acc + mask_18 * 2 + 5) & 127;
        aux ^= (mask_18 & 15);
    } else {
        acc = (acc - mask_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_19 = local_arr[aux % 3];
    acc = (acc + checksum_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int mask_99 = 0;
    for (int k = 0; k < 3; k++) {
        mask_99 = (mask_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_99) & 127;
    }
    int quantum_46 = (aux + st.buffer[1]) & 3;
    switch (quantum_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001015_1513_17(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001015_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int phase_68 = (aux + st.buffer[1]) & 3;
    switch (phase_68) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_71 = local_arr[aux % 3];
    acc = (acc + delta_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_18(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001015_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int metric_76 = local_arr[aux % 3];
    acc = (acc + metric_76 * 2) & 127;
    int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001015_1513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001015_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_80) & 63;
    acc ^= aux;
    int margin_38 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_38 > 23) {
        acc = (acc + margin_38 * 2 + 5) & 127;
        aux ^= (margin_38 & 15);
    } else {
        acc = (acc - margin_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001015_0;
    int sec_r001015_1;
    int sec_r001015_2;
    int sec_r001015_3;
    int sec_r001015_4;
    int sec_r001015_5;
    int sec_r001015_6;
    int sec_r001015_7;
    int sec_r001015_8;
    int sec_r001015_9;
    int sec_r001015_10;
    int sec_r001015_11;
    int sec_r001015_12;
    int sec_r001015_13;
    int sec_r001015_14;
    int sec_r001015_15;
    int sec_r001015_16;
    int sec_r001015_17;
    int sec_r001015_18;
    int sec_r001015_19;
    int pub_r001015_0;
    int pub_r001015_1;
    int pub_r001015_2;
    int pub_r001015_3;
    int pub_r001015_4;
    int pub_r001015_5;
    int pub_r001015_6;
    int pub_r001015_7;
    int pub_r001015_8;
    int pub_r001015_9;
    int pub_r001015_10;
    int pub_r001015_11;
    int pub_r001015_12;
    int pub_r001015_13;
    int pub_r001015_14;
    int pub_r001015_15;
    int pub_r001015_16;
    int pub_r001015_17;
    int pub_r001015_18;
    int pub_r001015_19;
    int pub_r001015_20;
    int pub_r001015_21;
    int pub_r001015_22;
    int pub_r001015_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001015_0 >= -100 && pub_r001015_0 <= 100);
    __CPROVER_assume(pub_r001015_1 >= -100 && pub_r001015_1 <= 100);
    __CPROVER_assume(pub_r001015_2 >= -100 && pub_r001015_2 <= 100);
    __CPROVER_assume(pub_r001015_3 >= -100 && pub_r001015_3 <= 100);
    __CPROVER_assume(pub_r001015_4 >= -100 && pub_r001015_4 <= 100);
    __CPROVER_assume(pub_r001015_5 >= -100 && pub_r001015_5 <= 100);
    __CPROVER_assume(pub_r001015_6 >= -100 && pub_r001015_6 <= 100);
    __CPROVER_assume(pub_r001015_7 >= -100 && pub_r001015_7 <= 100);
    __CPROVER_assume(pub_r001015_8 >= -100 && pub_r001015_8 <= 100);
    __CPROVER_assume(pub_r001015_9 >= -100 && pub_r001015_9 <= 100);
    __CPROVER_assume(pub_r001015_10 >= -100 && pub_r001015_10 <= 100);
    __CPROVER_assume(pub_r001015_11 >= -100 && pub_r001015_11 <= 100);
    __CPROVER_assume(pub_r001015_12 >= -100 && pub_r001015_12 <= 100);
    __CPROVER_assume(pub_r001015_13 >= -100 && pub_r001015_13 <= 100);
    __CPROVER_assume(pub_r001015_14 >= -100 && pub_r001015_14 <= 100);
    __CPROVER_assume(pub_r001015_15 >= -100 && pub_r001015_15 <= 100);
    __CPROVER_assume(pub_r001015_16 >= -100 && pub_r001015_16 <= 100);
    __CPROVER_assume(pub_r001015_17 >= -100 && pub_r001015_17 <= 100);
    __CPROVER_assume(pub_r001015_18 >= -100 && pub_r001015_18 <= 100);
    __CPROVER_assume(pub_r001015_19 >= -100 && pub_r001015_19 <= 100);
    __CPROVER_assume(pub_r001015_20 >= -100 && pub_r001015_20 <= 100);
    __CPROVER_assume(pub_r001015_21 >= -100 && pub_r001015_21 <= 100);
    __CPROVER_assume(pub_r001015_22 >= -100 && pub_r001015_22 <= 100);
    __CPROVER_assume(pub_r001015_23 >= -100 && pub_r001015_23 <= 100);
    __CPROVER_assume(sec_r001015_0 >= 0 && sec_r001015_0 <= 255);
    __CPROVER_assume(sec_r001015_1 >= 0 && sec_r001015_1 <= 255);
    __CPROVER_assume(sec_r001015_2 >= 0 && sec_r001015_2 <= 255);
    __CPROVER_assume(sec_r001015_3 >= 0 && sec_r001015_3 <= 255);
    __CPROVER_assume(sec_r001015_4 >= 0 && sec_r001015_4 <= 255);
    __CPROVER_assume(sec_r001015_5 >= 0 && sec_r001015_5 <= 255);
    __CPROVER_assume(sec_r001015_6 >= 0 && sec_r001015_6 <= 255);
    __CPROVER_assume(sec_r001015_7 >= 0 && sec_r001015_7 <= 255);
    __CPROVER_assume(sec_r001015_8 >= 0 && sec_r001015_8 <= 255);
    __CPROVER_assume(sec_r001015_9 >= 0 && sec_r001015_9 <= 255);
    __CPROVER_assume(sec_r001015_10 >= 0 && sec_r001015_10 <= 255);
    __CPROVER_assume(sec_r001015_11 >= 0 && sec_r001015_11 <= 255);
    __CPROVER_assume(sec_r001015_12 >= 0 && sec_r001015_12 <= 255);
    __CPROVER_assume(sec_r001015_13 >= 0 && sec_r001015_13 <= 255);
    __CPROVER_assume(sec_r001015_14 >= 0 && sec_r001015_14 <= 255);
    __CPROVER_assume(sec_r001015_15 >= 0 && sec_r001015_15 <= 255);
    __CPROVER_assume(sec_r001015_16 >= 0 && sec_r001015_16 <= 255);
    __CPROVER_assume(sec_r001015_17 >= 0 && sec_r001015_17 <= 255);
    __CPROVER_assume(sec_r001015_18 >= 0 && sec_r001015_18 <= 255);
    __CPROVER_assume(sec_r001015_19 >= 0 && sec_r001015_19 <= 255);

    struct DeviceConfig_R001015_1513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001015_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001015_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001015_0 + 7) & 15;
    struct SensorNode_R001015_1513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001015_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001015_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001015_0 + 9) & 15;
    struct MatrixBlock_R001015_1513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001015_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001015_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001015_0 + 11) & 15;

    union ColorPixel_R001015_1513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001015_1513_0(sec_r001015_0, pub_r001015_1, pub_r001015_2, pub_r001015_3, pub_r001015_4);
    int helper_flow_1 = fn_R001015_1513_1(sec_r001015_1, sec_r001015_2, pub_r001015_3, pub_r001015_4);
    int helper_flow_2 = fn_R001015_1513_2(sec_r001015_2, sec_r001015_3, pub_r001015_4);
    int helper_flow_3 = fn_R001015_1513_3(sec_r001015_3, sec_r001015_4);
    int helper_flow_4 = fn_R001015_1513_4(sec_r001015_4, sec_r001015_5, pub_r001015_6, pub_r001015_7, pub_r001015_8);
    int helper_flow_5 = fn_R001015_1513_5(sec_r001015_5, sec_r001015_6, pub_r001015_7);
    int helper_flow_6 = fn_R001015_1513_6(sec_r001015_6, sec_r001015_7, pub_r001015_8);
    int helper_flow_7 = fn_R001015_1513_7(sec_r001015_7, sec_r001015_8, pub_r001015_9, pub_r001015_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001015_6 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001015_10 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001015_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001015_9 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_3 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((stage_v_0 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001015_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001015_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001015_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001015_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001015_0 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001015_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_7 << 1) ^ (pub_r001015_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001015_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001015_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001015_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_6 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_12 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001015_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_4 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001015_9 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001015_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001015_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_5 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001015_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001015_2 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001015_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001015_1 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001015_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001015_13 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001015_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001015_10 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001015_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001015_9 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001015_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001015_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001015_12 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001015_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_25 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_16 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_0 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001015_19 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_4 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_7 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_4 << 1) ^ (pub_r001015_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001015_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001015_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001015_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001015_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001015_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001015_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001015_23 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_6 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001015_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_7 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_12 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_29 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_6 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001015_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001015_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_39 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_57 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_1 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001015_14 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001015_4 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001015_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001015_12 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001015_5 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001015_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001015_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001015_1 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001015_23 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001015_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_56 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001015_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_4 << 1) ^ (pub_r001015_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_0 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001015_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001015_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001015_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001015_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_54 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_0 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001015_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001015_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001015_22 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_5 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_17 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001015_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001015_4 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001015_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001015_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_41 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_36 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001015_1 << 1) ^ (pub_r001015_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001015_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_52 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_63 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001015_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_57 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_0 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001015_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_1 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001015_22 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001015_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001015_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001015_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_73 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001015_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001015_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001015_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_76 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001015_14 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_61 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_0 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_54 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_70 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001015_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001015_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001015_2 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001015_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_40 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_39 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_75 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_20 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001015_10 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001015_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_86 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001015_16 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_40 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001015_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_127 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_31 << 1) ^ (pub_r001015_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001015_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001015_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001015_8 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001015_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001015_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001015_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_89 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_64 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((helper_flow_5 << 1) ^ (pub_r001015_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_131 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001015_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_20 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001015_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_31 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_29 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001015_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_31 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001015_23 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_12 << 1) ^ (pub_r001015_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001015_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_146 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001015_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_128 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_57 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_66 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_52 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_131 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001015_22 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001015_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_155 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001015_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_63 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_1 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_16 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001015_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001015_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r001015_19 << 1) ^ (pub_r001015_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_115 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_27 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001015_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001015_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001015_17 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001015_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001015_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((helper_flow_4 << 1) ^ (pub_r001015_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001015_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001015_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_127 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001015_23 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001015_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_147 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_63 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001015_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001015_22 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_184 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001015_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001015_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r001015_0 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_187 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_151 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_42 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001015_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001015_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001015_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_144 << 1) ^ (pub_r001015_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_124 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_127 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001015_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_119 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r001015_9 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001015_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001015_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_39 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001015_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001015_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_56 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_135 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001015_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_124 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001015_22 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001015_22 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_29 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_17 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_56 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_208 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_119 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001015_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_93 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001015_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_147 << 1) ^ (pub_r001015_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_42 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001015_23 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_57 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_115 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_70 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_116 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_171 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001015_4 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_111 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001015_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001015_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_146 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001015_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_66 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001015_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_41 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_157 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_38 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001015_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_112 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_60 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_111 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((sec_r001015_13 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001015_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_153 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001015_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_29 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001015_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r001015_16 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_156 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((helper_flow_6 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001015_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_10 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_76 << 1) ^ (pub_r001015_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001015_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001015_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001015_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_3 << 1) ^ (pub_r001015_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_249 << 1) ^ (pub_r001015_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001015_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_228 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_240 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_31 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001015_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_41 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001015_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001015_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_214 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001015_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_86 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((helper_flow_6 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001015_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_107 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001015_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_131 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001015_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((sec_r001015_14 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001015_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_131 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_144 << 1) ^ (pub_r001015_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_256 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001015_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_265 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001015_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001015_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001015_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001015_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001015_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_123 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r001015_15 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001015_23 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_153 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_170 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001015_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_202 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_55 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001015_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_61 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001015_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001015_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_218 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001015_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r001015_0 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_174 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001015_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_180 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((helper_flow_2 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001015_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001015_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r001015_1 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001015_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001015_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001015_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001015_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_25 << 1) ^ (pub_r001015_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_184 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((helper_flow_5 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_198 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_272 << 1) ^ (pub_r001015_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((sec_r001015_2 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001015_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_86 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_223 << 1) ^ (pub_r001015_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_292 << 1) ^ (pub_r001015_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001015_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001015_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001015_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_92 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_242 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_312 << 1) ^ (pub_r001015_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001015_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001015_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_317 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((sec_r001015_4 << 1) ^ (pub_r001015_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_140 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_54 << 1) ^ (pub_r001015_23 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001015_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_29 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001015_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_174 << 1) ^ (pub_r001015_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((sec_r001015_15 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_142 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_62 << 1) ^ (pub_r001015_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_263 << 1) ^ (pub_r001015_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001015_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_121 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001015_21 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_116 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_325 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_272 << 1) ^ (pub_r001015_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_267 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001015_21 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001015_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_123 << 1) ^ (pub_r001015_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_208 << 1) ^ (pub_r001015_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001015_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001015_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001015_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001015_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001015_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001015_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001015_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_63 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001015_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_214 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001015_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_99 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001015_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((sec_r001015_15 << 1) ^ (pub_r001015_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_27 << 1) ^ (pub_r001015_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001015_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001015_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001015_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001015_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001015_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_16 << 1) ^ (pub_r001015_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_322 << 1) ^ (pub_r001015_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001015_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_208 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_52 << 1) ^ (pub_r001015_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001015_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_40 << 1) ^ (pub_r001015_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001015_23 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001015_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_345 << 1) ^ (pub_r001015_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_102 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_197 << 1) ^ (pub_r001015_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001015_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001015_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001015_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_267 << 1) ^ (pub_r001015_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001015_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001015_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_351 << 1) ^ (pub_r001015_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001015_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001015_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001015_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_285 << 1) ^ (pub_r001015_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
