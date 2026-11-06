/*
 * Benchmark Program: R000437
 * Security Family: nested_implicit_flow
 * Generator Seed: 543713
 * High Inputs: 18 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000437_3713_0 {
    int severity;
    int seq;
    int timestamp;
    int code;
    short facility;
    int buffer[3];
};

struct SensorNode_R000437_3713_1 {
    int reading;
    short offset;
    unsigned char threshold;
    int buffer[3];
};

struct MatrixBlock_R000437_3713_2 {
    short density;
    short scale;
    int dim;
    int buffer[3];
};

struct DeviceConfig_R000437_3713_3 {
    int id;
    short timeout;
    unsigned char port;
    int buffer[3];
};

union PacketPayload_R000437_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000437_3713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000437_3713_0(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_10 = (aux + st.buffer[1]) & 3;
    switch (accumulator_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_97 = local_arr[aux % 3];
    acc = (acc + checksum_97 * 2) & 127;
    int window_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000437_3713_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_53 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_53 > 32) {
        acc = (acc + index_reg_53 * 2 + 5) & 127;
        aux ^= (index_reg_53 & 15);
    } else {
        acc = (acc - index_reg_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_84 = local_arr[aux % 3];
    acc = (acc + stride_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_2(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_88 = (aux + st.buffer[1]) & 3;
    switch (tracker_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_83 = local_arr[aux % 3];
    acc = (acc + mask_83 * 2) & 127;
    int cursor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_20) & 63;
    acc ^= aux;
    int tracker_67 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_67 > 31) {
        acc = (acc + tracker_67 * 2 + 5) & 127;
        aux ^= (tracker_67 & 15);
    } else {
        acc = (acc - tracker_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000437_3713_3(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int index_reg_21 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_21 > 33) {
        acc = (acc + index_reg_21 * 2 + 5) & 127;
        aux ^= (index_reg_21 & 15);
    } else {
        acc = (acc - index_reg_21 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_4(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_99) & 63;
    acc ^= aux;
    int residue_11 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_11 > 26) {
        acc = (acc + residue_11 * 2 + 5) & 127;
        aux ^= (residue_11 & 15);
    } else {
        acc = (acc - residue_11 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_72 = local_arr[aux % 3];
    acc = (acc + cursor_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_21) & 63;
    acc ^= aux;
    int residue_63 = (aux + st.buffer[1]) & 3;
    switch (residue_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_81 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_81 > 21) {
        acc = (acc + margin_81 * 2 + 5) & 127;
        aux ^= (margin_81 & 15);
    } else {
        acc = (acc - margin_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000437_3713_6(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_73 = local_arr[aux % 3];
    acc = (acc + scale_73 * 2) & 127;
    int vector_47 = (aux + st.buffer[1]) & 3;
    switch (vector_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_7(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int checksum_57 = local_arr[aux % 3];
    acc = (acc + checksum_57 * 2) & 127;
    int residue_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_18 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_18 > 12) {
        acc = (acc + metric_18 * 2 + 5) & 127;
        aux ^= (metric_18 & 15);
    } else {
        acc = (acc - metric_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_55 = local_arr[aux % 3];
    acc = (acc + stride_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_9(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_45 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_45 > 37) {
        acc = (acc + damping_45 * 2 + 5) & 127;
        aux ^= (damping_45 & 15);
    } else {
        acc = (acc - damping_45 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_47 = local_arr[aux % 3];
    acc = (acc + residue_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_46 = (aux + st.buffer[1]) & 3;
    switch (delta_46) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_83 = (aux + st.buffer[1]) & 3;
    switch (damping_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_72 = local_arr[aux % 3];
    acc = (acc + scale_72 * 2) & 127;
    int tally_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000437_3713_12(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_88 = local_arr[aux % 3];
    acc = (acc + pivot_88 * 2) & 127;
    int stride_42 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_42 > 47) {
        acc = (acc + stride_42 * 2 + 5) & 127;
        aux ^= (stride_42 & 15);
    } else {
        acc = (acc - stride_42 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000437_3713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_48) & 63;
    acc ^= aux;
    int mask_52 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_52 > 26) {
        acc = (acc + mask_52 * 2 + 5) & 127;
        aux ^= (mask_52 & 15);
    } else {
        acc = (acc - mask_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000437_3713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_30 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_30 > 28) {
        acc = (acc + delta_30 * 2 + 5) & 127;
        aux ^= (delta_30 & 15);
    } else {
        acc = (acc - delta_30 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_11 = (aux + st.buffer[1]) & 3;
    switch (cursor_11) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000437_3713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_63 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_63 > 17) {
        acc = (acc + coefficient_63 * 2 + 5) & 127;
        aux ^= (coefficient_63 & 15);
    } else {
        acc = (acc - coefficient_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_55 = local_arr[aux % 3];
    acc = (acc + accumulator_55 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000437_0;
    int sec_r000437_1;
    int sec_r000437_2;
    int sec_r000437_3;
    int sec_r000437_4;
    int sec_r000437_5;
    int sec_r000437_6;
    int sec_r000437_7;
    int sec_r000437_8;
    int sec_r000437_9;
    int sec_r000437_10;
    int sec_r000437_11;
    int sec_r000437_12;
    int sec_r000437_13;
    int sec_r000437_14;
    int sec_r000437_15;
    int sec_r000437_16;
    int sec_r000437_17;
    int pub_r000437_0;
    int pub_r000437_1;
    int pub_r000437_2;
    int pub_r000437_3;
    int pub_r000437_4;
    int pub_r000437_5;
    int pub_r000437_6;
    int pub_r000437_7;
    int pub_r000437_8;
    int pub_r000437_9;
    int pub_r000437_10;
    int pub_r000437_11;
    int pub_r000437_12;
    int pub_r000437_13;
    int pub_r000437_14;
    int pub_r000437_15;
    int pub_r000437_16;
    int pub_r000437_17;
    int pub_r000437_18;
    int pub_r000437_19;
    int pub_r000437_20;
    int pub_r000437_21;
    int pub_r000437_22;
    int pub_r000437_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000437_0 >= -100 && pub_r000437_0 <= 100);
    __CPROVER_assume(pub_r000437_1 >= -100 && pub_r000437_1 <= 100);
    __CPROVER_assume(pub_r000437_2 >= -100 && pub_r000437_2 <= 100);
    __CPROVER_assume(pub_r000437_3 >= -100 && pub_r000437_3 <= 100);
    __CPROVER_assume(pub_r000437_4 >= -100 && pub_r000437_4 <= 100);
    __CPROVER_assume(pub_r000437_5 >= -100 && pub_r000437_5 <= 100);
    __CPROVER_assume(pub_r000437_6 >= -100 && pub_r000437_6 <= 100);
    __CPROVER_assume(pub_r000437_7 >= -100 && pub_r000437_7 <= 100);
    __CPROVER_assume(pub_r000437_8 >= -100 && pub_r000437_8 <= 100);
    __CPROVER_assume(pub_r000437_9 >= -100 && pub_r000437_9 <= 100);
    __CPROVER_assume(pub_r000437_10 >= -100 && pub_r000437_10 <= 100);
    __CPROVER_assume(pub_r000437_11 >= -100 && pub_r000437_11 <= 100);
    __CPROVER_assume(pub_r000437_12 >= -100 && pub_r000437_12 <= 100);
    __CPROVER_assume(pub_r000437_13 >= -100 && pub_r000437_13 <= 100);
    __CPROVER_assume(pub_r000437_14 >= -100 && pub_r000437_14 <= 100);
    __CPROVER_assume(pub_r000437_15 >= -100 && pub_r000437_15 <= 100);
    __CPROVER_assume(pub_r000437_16 >= -100 && pub_r000437_16 <= 100);
    __CPROVER_assume(pub_r000437_17 >= -100 && pub_r000437_17 <= 100);
    __CPROVER_assume(pub_r000437_18 >= -100 && pub_r000437_18 <= 100);
    __CPROVER_assume(pub_r000437_19 >= -100 && pub_r000437_19 <= 100);
    __CPROVER_assume(pub_r000437_20 >= -100 && pub_r000437_20 <= 100);
    __CPROVER_assume(pub_r000437_21 >= -100 && pub_r000437_21 <= 100);
    __CPROVER_assume(pub_r000437_22 >= -100 && pub_r000437_22 <= 100);
    __CPROVER_assume(pub_r000437_23 >= -100 && pub_r000437_23 <= 100);
    __CPROVER_assume(sec_r000437_0 >= 0 && sec_r000437_0 <= 255);
    __CPROVER_assume(sec_r000437_1 >= 0 && sec_r000437_1 <= 255);
    __CPROVER_assume(sec_r000437_2 >= 0 && sec_r000437_2 <= 255);
    __CPROVER_assume(sec_r000437_3 >= 0 && sec_r000437_3 <= 255);
    __CPROVER_assume(sec_r000437_4 >= 0 && sec_r000437_4 <= 255);
    __CPROVER_assume(sec_r000437_5 >= 0 && sec_r000437_5 <= 255);
    __CPROVER_assume(sec_r000437_6 >= 0 && sec_r000437_6 <= 255);
    __CPROVER_assume(sec_r000437_7 >= 0 && sec_r000437_7 <= 255);
    __CPROVER_assume(sec_r000437_8 >= 0 && sec_r000437_8 <= 255);
    __CPROVER_assume(sec_r000437_9 >= 0 && sec_r000437_9 <= 255);
    __CPROVER_assume(sec_r000437_10 >= 0 && sec_r000437_10 <= 255);
    __CPROVER_assume(sec_r000437_11 >= 0 && sec_r000437_11 <= 255);
    __CPROVER_assume(sec_r000437_12 >= 0 && sec_r000437_12 <= 255);
    __CPROVER_assume(sec_r000437_13 >= 0 && sec_r000437_13 <= 255);
    __CPROVER_assume(sec_r000437_14 >= 0 && sec_r000437_14 <= 255);
    __CPROVER_assume(sec_r000437_15 >= 0 && sec_r000437_15 <= 255);
    __CPROVER_assume(sec_r000437_16 >= 0 && sec_r000437_16 <= 255);
    __CPROVER_assume(sec_r000437_17 >= 0 && sec_r000437_17 <= 255);

    struct EventLog_R000437_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000437_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000437_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000437_0 + 7) & 15;
    struct SensorNode_R000437_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000437_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000437_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000437_0 + 9) & 15;
    struct MatrixBlock_R000437_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000437_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000437_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000437_0 + 11) & 15;
    struct DeviceConfig_R000437_3713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000437_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000437_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000437_0 + 13) & 15;

    union PacketPayload_R000437_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 31) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 46) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 18) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 33) {
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
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 32) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 47) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 29) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 44) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 26) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 41) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 17) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 32) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 32) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 47) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 12) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 27) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
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
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 26) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 41) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 22) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 37) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 14) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 29) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 35) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 50) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000437_14 & 1) != 0) {
        if ((sec_r000437_1 & 2) != 0) {
            stage_v_65 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_66 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000437_0 & 2) != 0) {
            stage_v_67 = (pub_r000437_5 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000437_5 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000437_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000437_3 & 1) != 0) {
        if ((sec_r000437_7 & 2) != 0) {
            stage_v_68 = (pub_r000437_5 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000437_5 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000437_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000437_6 & 2) != 0) {
            stage_v_69 = (pub_r000437_13 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000437_13 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000437_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000437_9 & 1) != 0) {
        if ((sec_r000437_6 & 2) != 0) {
            stage_v_70 = (pub_r000437_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000437_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000437_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_71 = (pub_r000437_1 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000437_1 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000437_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_72 = (pub_r000437_7 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000437_7 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000437_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000437_1 & 2) != 0) {
            stage_v_73 = (pub_r000437_15 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000437_15 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000437_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000437_13 & 2) != 0) {
            stage_v_74 = (pub_r000437_4 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000437_4 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000437_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000437_11 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_75 = (pub_r000437_3 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000437_3 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000437_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000437_2 & 2) != 0) {
            stage_v_76 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_77 = (pub_r000437_7 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000437_7 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000437_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000437_4 & 2) != 0) {
            stage_v_78 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_79 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_80 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000437_10 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_81 = (pub_r000437_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000437_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000437_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000437_6 & 2) != 0) {
            stage_v_82 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000437_2 & 2) != 0) {
            stage_v_83 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000437_5 & 2) != 0) {
            stage_v_84 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000437_2 & 1) != 0) {
        if ((sec_r000437_1 & 2) != 0) {
            stage_v_85 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000437_11 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_86 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000437_13 & 2) != 0) {
            stage_v_87 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000437_3 & 2) != 0) {
            stage_v_88 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000437_1 & 2) != 0) {
            stage_v_89 = (pub_r000437_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000437_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000437_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000437_0 & 1) != 0) {
        if ((sec_r000437_3 & 2) != 0) {
            stage_v_90 = (pub_r000437_7 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000437_7 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000437_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000437_7 & 2) != 0) {
            stage_v_91 = (pub_r000437_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000437_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000437_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000437_10 & 1) != 0) {
        if ((sec_r000437_15 & 2) != 0) {
            stage_v_92 = (pub_r000437_21 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000437_21 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000437_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_93 = (pub_r000437_1 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000437_1 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000437_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_94 = (pub_r000437_15 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000437_15 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000437_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000437_5 & 2) != 0) {
            stage_v_95 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_96 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000437_10 & 2) != 0) {
            stage_v_97 = (pub_r000437_7 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000437_7 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000437_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000437_7 & 1) != 0) {
        if ((sec_r000437_4 & 2) != 0) {
            stage_v_98 = (pub_r000437_3 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000437_3 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000437_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000437_13 & 2) != 0) {
            stage_v_99 = (pub_r000437_22 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000437_22 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000437_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_100 = (pub_r000437_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000437_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000437_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_101 = (pub_r000437_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000437_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000437_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000437_2 & 1) != 0) {
        if ((sec_r000437_7 & 2) != 0) {
            stage_v_102 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000437_3 & 2) != 0) {
            stage_v_103 = (pub_r000437_3 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000437_3 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000437_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000437_14 & 2) != 0) {
            stage_v_104 = (pub_r000437_4 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000437_4 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000437_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000437_4 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_105 = (pub_r000437_22 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000437_22 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000437_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000437_7 & 1) != 0) {
        if ((sec_r000437_14 & 2) != 0) {
            stage_v_106 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_107 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_108 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_109 = (pub_r000437_23 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000437_23 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000437_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_110 = (pub_r000437_3 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000437_3 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000437_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000437_0 & 2) != 0) {
            stage_v_111 = (pub_r000437_4 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000437_4 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000437_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000437_16 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_112 = (pub_r000437_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000437_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000437_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_113 = (pub_r000437_4 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000437_4 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000437_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000437_17 & 1) != 0) {
        if ((sec_r000437_12 & 2) != 0) {
            stage_v_114 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000437_15 & 2) != 0) {
            stage_v_115 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000437_16 & 2) != 0) {
            stage_v_116 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000437_12 & 2) != 0) {
            stage_v_117 = (pub_r000437_2 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000437_2 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000437_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_118 = (pub_r000437_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000437_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000437_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000437_0 & 2) != 0) {
            stage_v_119 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000437_13 & 1) != 0) {
        if ((sec_r000437_14 & 2) != 0) {
            stage_v_120 = (pub_r000437_3 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000437_3 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000437_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000437_14 & 2) != 0) {
            stage_v_121 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000437_1 & 2) != 0) {
            stage_v_122 = (pub_r000437_11 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000437_11 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000437_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000437_16 & 2) != 0) {
            stage_v_123 = (pub_r000437_22 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000437_22 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000437_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000437_0 & 2) != 0) {
            stage_v_124 = (pub_r000437_23 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000437_23 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000437_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000437_16 & 2) != 0) {
            stage_v_125 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000437_9 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_126 = (pub_r000437_12 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000437_12 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000437_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_127 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000437_5 & 2) != 0) {
            stage_v_128 = (pub_r000437_6 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000437_6 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000437_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000437_2 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_129 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000437_5 & 2) != 0) {
            stage_v_130 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000437_16 & 2) != 0) {
            stage_v_131 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000437_15 & 1) != 0) {
        if ((sec_r000437_4 & 2) != 0) {
            stage_v_132 = (pub_r000437_15 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000437_15 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000437_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000437_12 & 1) != 0) {
        if ((sec_r000437_16 & 2) != 0) {
            stage_v_133 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000437_15 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_134 = (pub_r000437_6 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000437_6 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000437_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_135 = (pub_r000437_23 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000437_23 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000437_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000437_13 & 2) != 0) {
            stage_v_136 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000437_14 & 2) != 0) {
            stage_v_137 = (pub_r000437_6 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000437_6 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000437_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000437_17 & 1) != 0) {
        if ((sec_r000437_0 & 2) != 0) {
            stage_v_138 = (pub_r000437_17 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000437_17 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000437_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000437_8 & 1) != 0) {
        if ((sec_r000437_9 & 2) != 0) {
            stage_v_139 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_140 = (pub_r000437_19 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000437_19 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000437_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000437_10 & 2) != 0) {
            stage_v_141 = (pub_r000437_18 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000437_18 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000437_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000437_15 & 1) != 0) {
        if ((sec_r000437_12 & 2) != 0) {
            stage_v_142 = (pub_r000437_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000437_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000437_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_143 = (pub_r000437_2 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000437_2 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000437_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000437_3 & 2) != 0) {
            stage_v_144 = (pub_r000437_10 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000437_10 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000437_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000437_11 & 2) != 0) {
            stage_v_145 = (pub_r000437_5 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000437_5 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000437_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000437_4 & 2) != 0) {
            stage_v_146 = (pub_r000437_12 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000437_12 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000437_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000437_2 & 1) != 0) {
        if ((sec_r000437_12 & 2) != 0) {
            stage_v_147 = (pub_r000437_14 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000437_14 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000437_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000437_2 & 1) != 0) {
        if ((sec_r000437_17 & 2) != 0) {
            stage_v_148 = (pub_r000437_17 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000437_17 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000437_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000437_15 & 2) != 0) {
            stage_v_149 = (pub_r000437_9 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000437_9 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000437_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000437_8 & 2) != 0) {
            stage_v_150 = (pub_r000437_0 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000437_0 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000437_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
