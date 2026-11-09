/*
 * Benchmark Program: R001386
 * Security Family: implicit_flow
 * Generator Seed: 638613
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001386_8613_0 {
    int norm_sq;
    int pitch;
    int coord_z;
    int heading;
    int coord_x;
    int coord_y;
    int buffer[3];
};

struct SensorNode_R001386_8613_1 {
    int status;
    int offset;
    unsigned char threshold;
    int gain;
    int calib;
    int buffer[3];
};

struct FilterState_R001386_8613_2 {
    short mode;
    unsigned char prev_in;
    unsigned char damping;
    short gain_db;
    int prev_out;
    int cutoff;
    int buffer[3];
};

union TelemetryField_R001386_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001386_8613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001386_8613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001386_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_89 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_89 > 46) {
        acc = (acc + delta_89 * 2 + 5) & 127;
        aux ^= (delta_89 & 15);
    } else {
        acc = (acc - delta_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001386_8613_1(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001386_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_97 = (aux + st.buffer[1]) & 3;
    switch (coefficient_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_30 = local_arr[aux % 3];
    acc = (acc + metric_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001386_8613_2(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001386_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_55 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_55 > 33) {
        acc = (acc + tally_55 * 2 + 5) & 127;
        aux ^= (tally_55 & 15);
    } else {
        acc = (acc - tally_55 + 11) & 127;
        aux += 3;
    }
    int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001386_8613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001386_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int coefficient_15 = local_arr[aux % 3];
    acc = (acc + coefficient_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001386_8613_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001386_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int cursor_42 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_42 > 30) {
        acc = (acc + cursor_42 * 2 + 5) & 127;
        aux ^= (cursor_42 & 15);
    } else {
        acc = (acc - cursor_42 + 11) & 127;
        aux += 3;
    }
    int quantum_23 = (aux + st.buffer[1]) & 3;
    switch (quantum_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_5(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_75 > 24) {
        acc = (acc + quantum_75 * 2 + 5) & 127;
        aux ^= (quantum_75 & 15);
    } else {
        acc = (acc - quantum_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_99 = local_arr[aux % 3];
    acc = (acc + delta_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001386_8613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_20 = 0;
    for (int k = 0; k < 2; k++) {
        delta_20 = (delta_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001386_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int delta_65 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_65 > 50) {
        acc = (acc + delta_65 * 2 + 5) & 127;
        aux ^= (delta_65 & 15);
    } else {
        acc = (acc - delta_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_28 = local_arr[aux % 3];
    acc = (acc + offset_28 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001386_8613_8(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_66 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_66 = (coefficient_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001386_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_39 = (aux + st.buffer[1]) & 3;
    switch (index_reg_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_80) & 63;
    acc ^= aux;
    int mask_46 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_46 > 44) {
        acc = (acc + mask_46 * 2 + 5) & 127;
        aux ^= (mask_46 & 15);
    } else {
        acc = (acc - mask_46 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001386_8613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001386_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_61) & 63;
    acc ^= aux;
    int tally_99 = 0;
    for (int k = 0; k < 2; k++) {
        tally_99 = (tally_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_11(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001386_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_95 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_95 > 20) {
        acc = (acc + delta_95 * 2 + 5) & 127;
        aux ^= (delta_95 & 15);
    } else {
        acc = (acc - delta_95 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_26 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_26 = (tracker_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_26) & 127;
    }
    int scale_71 = (aux + st.buffer[1]) & 3;
    switch (scale_71) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_12(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_70 = (aux + st.buffer[1]) & 3;
    switch (scale_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_27 = local_arr[aux % 3];
    acc = (acc + mask_27 * 2) & 127;
    int threshold_61 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_61 = (threshold_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_27 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_27 = (tracker_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_27) & 127;
    }
    int checksum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_49) & 63;
    acc ^= aux;
    int checksum_97 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_97 > 30) {
        acc = (acc + checksum_97 * 2 + 5) & 127;
        aux ^= (checksum_97 & 15);
    } else {
        acc = (acc - checksum_97 + 11) & 127;
        aux += 3;
    }
    int sample_24 = (aux + st.buffer[1]) & 3;
    switch (sample_24) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001386_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int checksum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_23) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_88 = local_arr[aux % 3];
    acc = (acc + weight_88 * 2) & 127;
    int index_reg_73 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_73 = (index_reg_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001386_8613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001386_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001386_0;
    int sec_r001386_1;
    int sec_r001386_2;
    int sec_r001386_3;
    int sec_r001386_4;
    int sec_r001386_5;
    int sec_r001386_6;
    int sec_r001386_7;
    int sec_r001386_8;
    int sec_r001386_9;
    int sec_r001386_10;
    int sec_r001386_11;
    int sec_r001386_12;
    int sec_r001386_13;
    int sec_r001386_14;
    int sec_r001386_15;
    int sec_r001386_16;
    int sec_r001386_17;
    int sec_r001386_18;
    int sec_r001386_19;
    int sec_r001386_20;
    int pub_r001386_0;
    int pub_r001386_1;
    int pub_r001386_2;
    int pub_r001386_3;
    int pub_r001386_4;
    int pub_r001386_5;
    int pub_r001386_6;
    int pub_r001386_7;
    int pub_r001386_8;
    int pub_r001386_9;
    int pub_r001386_10;
    int pub_r001386_11;
    int pub_r001386_12;
    int pub_r001386_13;
    int pub_r001386_14;
    int pub_r001386_15;
    int pub_r001386_16;
    int pub_r001386_17;
    int pub_r001386_18;
    int pub_r001386_19;
    int pub_r001386_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001386_0 >= -100 && pub_r001386_0 <= 100);
    __CPROVER_assume(pub_r001386_1 >= -100 && pub_r001386_1 <= 100);
    __CPROVER_assume(pub_r001386_2 >= -100 && pub_r001386_2 <= 100);
    __CPROVER_assume(pub_r001386_3 >= -100 && pub_r001386_3 <= 100);
    __CPROVER_assume(pub_r001386_4 >= -100 && pub_r001386_4 <= 100);
    __CPROVER_assume(pub_r001386_5 >= -100 && pub_r001386_5 <= 100);
    __CPROVER_assume(pub_r001386_6 >= -100 && pub_r001386_6 <= 100);
    __CPROVER_assume(pub_r001386_7 >= -100 && pub_r001386_7 <= 100);
    __CPROVER_assume(pub_r001386_8 >= -100 && pub_r001386_8 <= 100);
    __CPROVER_assume(pub_r001386_9 >= -100 && pub_r001386_9 <= 100);
    __CPROVER_assume(pub_r001386_10 >= -100 && pub_r001386_10 <= 100);
    __CPROVER_assume(pub_r001386_11 >= -100 && pub_r001386_11 <= 100);
    __CPROVER_assume(pub_r001386_12 >= -100 && pub_r001386_12 <= 100);
    __CPROVER_assume(pub_r001386_13 >= -100 && pub_r001386_13 <= 100);
    __CPROVER_assume(pub_r001386_14 >= -100 && pub_r001386_14 <= 100);
    __CPROVER_assume(pub_r001386_15 >= -100 && pub_r001386_15 <= 100);
    __CPROVER_assume(pub_r001386_16 >= -100 && pub_r001386_16 <= 100);
    __CPROVER_assume(pub_r001386_17 >= -100 && pub_r001386_17 <= 100);
    __CPROVER_assume(pub_r001386_18 >= -100 && pub_r001386_18 <= 100);
    __CPROVER_assume(pub_r001386_19 >= -100 && pub_r001386_19 <= 100);
    __CPROVER_assume(pub_r001386_20 >= -100 && pub_r001386_20 <= 100);
    __CPROVER_assume(sec_r001386_0 >= 0 && sec_r001386_0 <= 255);
    __CPROVER_assume(sec_r001386_1 >= 0 && sec_r001386_1 <= 255);
    __CPROVER_assume(sec_r001386_2 >= 0 && sec_r001386_2 <= 255);
    __CPROVER_assume(sec_r001386_3 >= 0 && sec_r001386_3 <= 255);
    __CPROVER_assume(sec_r001386_4 >= 0 && sec_r001386_4 <= 255);
    __CPROVER_assume(sec_r001386_5 >= 0 && sec_r001386_5 <= 255);
    __CPROVER_assume(sec_r001386_6 >= 0 && sec_r001386_6 <= 255);
    __CPROVER_assume(sec_r001386_7 >= 0 && sec_r001386_7 <= 255);
    __CPROVER_assume(sec_r001386_8 >= 0 && sec_r001386_8 <= 255);
    __CPROVER_assume(sec_r001386_9 >= 0 && sec_r001386_9 <= 255);
    __CPROVER_assume(sec_r001386_10 >= 0 && sec_r001386_10 <= 255);
    __CPROVER_assume(sec_r001386_11 >= 0 && sec_r001386_11 <= 255);
    __CPROVER_assume(sec_r001386_12 >= 0 && sec_r001386_12 <= 255);
    __CPROVER_assume(sec_r001386_13 >= 0 && sec_r001386_13 <= 255);
    __CPROVER_assume(sec_r001386_14 >= 0 && sec_r001386_14 <= 255);
    __CPROVER_assume(sec_r001386_15 >= 0 && sec_r001386_15 <= 255);
    __CPROVER_assume(sec_r001386_16 >= 0 && sec_r001386_16 <= 255);
    __CPROVER_assume(sec_r001386_17 >= 0 && sec_r001386_17 <= 255);
    __CPROVER_assume(sec_r001386_18 >= 0 && sec_r001386_18 <= 255);
    __CPROVER_assume(sec_r001386_19 >= 0 && sec_r001386_19 <= 255);
    __CPROVER_assume(sec_r001386_20 >= 0 && sec_r001386_20 <= 255);

    struct Vector3D_R001386_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001386_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001386_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001386_0 + 7) & 15;
    struct SensorNode_R001386_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001386_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001386_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001386_0 + 9) & 15;
    struct FilterState_R001386_8613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001386_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001386_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001386_0 + 11) & 15;

    union TelemetryField_R001386_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001386_8613_0(sec_r001386_0, sec_r001386_1, pub_r001386_2, pub_r001386_3);
    int helper_flow_1 = fn_R001386_8613_1(sec_r001386_1, sec_r001386_2);
    int helper_flow_2 = fn_R001386_8613_2(sec_r001386_2, sec_r001386_3, pub_r001386_4);
    int helper_flow_3 = fn_R001386_8613_3(sec_r001386_3, pub_r001386_4, pub_r001386_5, pub_r001386_6, pub_r001386_7);
    int helper_flow_4 = fn_R001386_8613_4(sec_r001386_4, pub_r001386_5, pub_r001386_6);
    int helper_flow_5 = fn_R001386_8613_5(sec_r001386_5, pub_r001386_6, pub_r001386_7);
    int helper_flow_6 = fn_R001386_8613_6(sec_r001386_6, pub_r001386_7, pub_r001386_8, pub_r001386_9, pub_r001386_10);
    int helper_flow_7 = fn_R001386_8613_7(sec_r001386_7, pub_r001386_8, pub_r001386_9, pub_r001386_10, pub_r001386_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001386_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001386_8 + pub_r001386_18 * 2 + 8) & 127;
    if (stage_v_1 > 57) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001386_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001386_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001386_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001386_10 + pub_r001386_17 * 2 + 20) & 127;
    if (stage_v_5 > 28) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001386_20 + pub_r001386_12 * 2 + 23) & 127;
    if (stage_v_6 > 56) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001386_6 + pub_r001386_13 * 2 + 26) & 127;
    if (stage_v_7 > 46) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_7 + pub_r001386_2 * 2 + 29) & 127;
    if (stage_v_8 > 24) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001386_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_1 + pub_r001386_8 * 2 + 35) & 127;
    if (stage_v_10 > 37) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001386_18 + pub_r001386_3 * 2 + 38) & 127;
    if (stage_v_11 > 20) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001386_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001386_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001386_19 + pub_r001386_16 * 2 + 47) & 127;
    if (stage_v_14 > 41) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001386_20 + pub_r001386_8 * 2 + 50) & 127;
    if (stage_v_15 > 31) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001386_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_6 + pub_r001386_1 * 2 + 56) & 127;
    if (stage_v_17 > 51) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001386_20 + pub_r001386_8 * 2 + 59) & 127;
    if (stage_v_18 > 59) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001386_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_7 + pub_r001386_6 * 2 + 65) & 127;
    if (stage_v_20 > 24) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001386_15 + pub_r001386_5 * 2 + 68) & 127;
    if (stage_v_21 > 47) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001386_8 + pub_r001386_13 * 2 + 71) & 127;
    if (stage_v_22 > 58) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001386_8 + pub_r001386_8 * 2 + 74) & 127;
    if (stage_v_23 > 49) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001386_8 + pub_r001386_12 * 2 + 77) & 127;
    if (stage_v_24 > 20) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001386_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_10 + pub_r001386_7 * 2 + 83) & 127;
    if (stage_v_26 > 20) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001386_8 + pub_r001386_10 * 2 + 86) & 127;
    if (stage_v_27 > 52) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001386_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001386_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001386_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001386_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001386_18 + pub_r001386_17 * 2 + 101) & 127;
    if (stage_v_32 > 26) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001386_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_4 + pub_r001386_7 * 2 + 107) & 127;
    if (stage_v_34 > 17) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001386_9 + pub_r001386_11 * 2 + 110) & 127;
    if (stage_v_35 > 32) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001386_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_3 + pub_r001386_2 * 2 + 116) & 127;
    if (stage_v_37 > 59) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001386_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001386_8 + pub_r001386_1 * 2 + 122) & 127;
    if (stage_v_39 > 33) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001386_11 + pub_r001386_19 * 2 + 125) & 127;
    if (stage_v_40 > 15) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001386_11 + pub_r001386_12 * 2 + 128) & 127;
    if (stage_v_41 > 33) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_11 + pub_r001386_0 * 2 + 131) & 127;
    if (stage_v_42 > 22) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001386_18 + pub_r001386_14 * 2 + 134) & 127;
    if (stage_v_43 > 49) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_14 + pub_r001386_3 * 2 + 137) & 127;
    if (stage_v_44 > 35) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001386_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001386_11 + pub_r001386_9 * 2 + 143) & 127;
    if (stage_v_46 > 33) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_10 + pub_r001386_4 * 2 + 146) & 127;
    if (stage_v_47 > 32) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001386_7 + pub_r001386_19 * 2 + 149) & 127;
    if (stage_v_48 > 22) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001386_18 + pub_r001386_20 * 2 + 152) & 127;
    if (stage_v_49 > 45) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001386_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_10 + pub_r001386_4 * 2 + 158) & 127;
    if (stage_v_51 > 27) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001386_12 + pub_r001386_15 * 2 + 161) & 127;
    if (stage_v_52 > 33) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001386_4 + pub_r001386_8 * 2 + 164) & 127;
    if (stage_v_53 > 18) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001386_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_41 + pub_r001386_0 * 2 + 170) & 127;
    if (stage_v_55 > 42) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001386_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001386_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001386_15 + pub_r001386_5 * 2 + 179) & 127;
    if (stage_v_58 > 31) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_5 + pub_r001386_13 * 2 + 182) & 127;
    if (stage_v_59 > 25) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001386_17 + pub_r001386_16 * 2 + 185) & 127;
    if (stage_v_60 > 38) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001386_4 + pub_r001386_9 * 2 + 188) & 127;
    if (stage_v_61 > 44) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_7 + pub_r001386_9 * 2 + 191) & 127;
    if (stage_v_62 > 28) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_18 + pub_r001386_10 * 2 + 194) & 127;
    if (stage_v_63 > 44) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001386_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001386_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001386_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_63 + pub_r001386_4 * 2 + 206) & 127;
    if (stage_v_67 > 24) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_47 + pub_r001386_11 * 2 + 209) & 127;
    if (stage_v_68 > 52) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001386_16 + pub_r001386_11 * 2 + 212) & 127;
    if (stage_v_69 > 55) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_61 + pub_r001386_11 * 2 + 215) & 127;
    if (stage_v_70 > 27) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_6 + pub_r001386_14 * 2 + 218) & 127;
    if (stage_v_71 > 44) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_6 + pub_r001386_9 * 2 + 221) & 127;
    if (stage_v_72 > 50) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_60 + pub_r001386_17 * 2 + 224) & 127;
    if (stage_v_73 > 17) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001386_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_47 + pub_r001386_18 * 2 + 230) & 127;
    if (stage_v_75 > 39) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001386_13 + pub_r001386_11 * 2 + 233) & 127;
    if (stage_v_76 > 30) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001386_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_49 + pub_r001386_11 * 2 + 239) & 127;
    if (stage_v_78 > 43) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_69 + pub_r001386_8 * 2 + 242) & 127;
    if (stage_v_79 > 24) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_34 + pub_r001386_3 * 2 + 245) & 127;
    if (stage_v_80 > 21) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_73 + pub_r001386_16 * 2 + 248) & 127;
    if (stage_v_81 > 45) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_58 + pub_r001386_2 * 2 + 251) & 127;
    if (stage_v_82 > 43) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001386_5 + pub_r001386_11 * 2 + 254) & 127;
    if (stage_v_83 > 49) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001386_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_8 + pub_r001386_17 * 2 + 260) & 127;
    if (stage_v_85 > 54) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_76 + pub_r001386_7 * 2 + 263) & 127;
    if (stage_v_86 > 26) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_8 + pub_r001386_8 * 2 + 266) & 127;
    if (stage_v_87 > 24) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_35 + pub_r001386_10 * 2 + 269) & 127;
    if (stage_v_88 > 50) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_87 + pub_r001386_3 * 2 + 272) & 127;
    if (stage_v_89 > 43) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001386_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_35 + pub_r001386_16 * 2 + 278) & 127;
    if (stage_v_91 > 52) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001386_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_0 + pub_r001386_13 * 2 + 284) & 127;
    if (stage_v_93 > 28) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001386_20 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001386_3 + pub_r001386_9 * 2 + 290) & 127;
    if (stage_v_95 > 45) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001386_11 + pub_r001386_13 * 2 + 293) & 127;
    if (stage_v_96 > 24) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_8 + pub_r001386_1 * 2 + 296) & 127;
    if (stage_v_97 > 37) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001386_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_96 + pub_r001386_19 * 2 + 302) & 127;
    if (stage_v_99 > 40) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001386_10 + pub_r001386_17 * 2 + 305) & 127;
    if (stage_v_100 > 48) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001386_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001386_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001386_3 + pub_r001386_5 * 2 + 314) & 127;
    if (stage_v_103 > 32) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_95 + pub_r001386_15 * 2 + 317) & 127;
    if (stage_v_104 > 19) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_86 + pub_r001386_0 * 2 + 320) & 127;
    if (stage_v_105 > 20) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_17 + pub_r001386_20 * 2 + 323) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001386_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_79 + pub_r001386_5 * 2 + 329) & 127;
    if (stage_v_108 > 38) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_46 + pub_r001386_2 * 2 + 332) & 127;
    if (stage_v_109 > 16) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001386_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_62 + pub_r001386_1 * 2 + 338) & 127;
    if (stage_v_111 > 50) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001386_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r001386_11 + pub_r001386_0 * 2 + 344) & 127;
    if (stage_v_113 > 15) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (helper_flow_4 + pub_r001386_9 * 2 + 347) & 127;
    if (stage_v_114 > 46) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (helper_flow_1 + pub_r001386_13 * 2 + 350) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001386_17 + pub_r001386_13 * 2 + 353) & 127;
    if (stage_v_116 > 42) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_35 + pub_r001386_18 * 2 + 356) & 127;
    if (stage_v_117 > 49) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_69 + pub_r001386_1 * 2 + 359) & 127;
    if (stage_v_118 > 19) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001386_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001386_5 + pub_r001386_11 * 2 + 365) & 127;
    if (stage_v_120 > 46) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_24 + pub_r001386_1 * 2 + 368) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_97 + pub_r001386_16 * 2 + 371) & 127;
    if (stage_v_122 > 45) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_73 + pub_r001386_3 * 2 + 374) & 127;
    if (stage_v_123 > 56) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001386_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001386_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_37 + pub_r001386_20 * 2 + 383) & 127;
    if (stage_v_126 > 55) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_6 + pub_r001386_16 * 2 + 386) & 127;
    if (stage_v_127 > 30) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001386_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001386_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_26 + pub_r001386_15 * 2 + 395) & 127;
    if (stage_v_130 > 29) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001386_20 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_105 + pub_r001386_12 * 2 + 401) & 127;
    if (stage_v_132 > 49) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_113 + pub_r001386_2 * 2 + 404) & 127;
    if (stage_v_133 > 57) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001386_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001386_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001386_4 + pub_r001386_16 * 2 + 413) & 127;
    if (stage_v_136 > 24) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_126 + pub_r001386_18 * 2 + 416) & 127;
    if (stage_v_137 > 50) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001386_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001386_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_113 + pub_r001386_8 * 2 + 425) & 127;
    if (stage_v_140 > 36) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001386_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (helper_flow_5 + pub_r001386_1 * 2 + 431) & 127;
    if (stage_v_142 > 18) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_142 + pub_r001386_19 * 2 + 434) & 127;
    if (stage_v_143 > 17) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_46 + pub_r001386_13 * 2 + 437) & 127;
    if (stage_v_144 > 27) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_121 + pub_r001386_10 * 2 + 440) & 127;
    if (stage_v_145 > 15) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_130 + pub_r001386_8 * 2 + 443) & 127;
    if (stage_v_146 > 59) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r001386_9 + pub_r001386_20 * 2 + 446) & 127;
    if (stage_v_147 > 25) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (helper_flow_0 + pub_r001386_19 * 2 + 449) & 127;
    if (stage_v_148 > 46) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_7 + pub_r001386_10 * 2 + 452) & 127;
    if (stage_v_149 > 60) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001386_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001386_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001386_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_99 + pub_r001386_2 * 2 + 464) & 127;
    if (stage_v_153 > 18) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_140 + pub_r001386_14 * 2 + 467) & 127;
    if (stage_v_154 > 35) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001386_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_117 + pub_r001386_7 * 2 + 473) & 127;
    if (stage_v_156 > 50) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (sec_r001386_7 + pub_r001386_0 * 2 + 476) & 127;
    if (stage_v_157 > 57) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_73 + pub_r001386_16 * 2 + 479) & 127;
    if (stage_v_158 > 19) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001386_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001386_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001386_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_32 + pub_r001386_3 * 2 + 491) & 127;
    if (stage_v_162 > 21) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001386_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_99 + pub_r001386_9 * 2 + 497) & 127;
    if (stage_v_164 > 29) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_103 + pub_r001386_17 * 2 + 500) & 127;
    if (stage_v_165 > 43) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_55 + pub_r001386_12 * 2 + 503) & 127;
    if (stage_v_166 > 38) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001386_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_143 + pub_r001386_4 * 2 + 509) & 127;
    if (stage_v_168 > 54) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_132 + pub_r001386_15 * 2 + 512) & 127;
    if (stage_v_169 > 50) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_96 + pub_r001386_2 * 2 + 515) & 127;
    if (stage_v_170 > 59) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001386_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_81 + pub_r001386_6 * 2 + 521) & 127;
    if (stage_v_172 > 27) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001386_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_85 + pub_r001386_18 * 2 + 527) & 127;
    if (stage_v_174 > 47) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (helper_flow_2 + pub_r001386_2 * 2 + 530) & 127;
    if (stage_v_175 > 32) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_5 + pub_r001386_5 * 2 + 533) & 127;
    if (stage_v_176 > 58) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_24 + pub_r001386_15 * 2 + 536) & 127;
    if (stage_v_177 > 38) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_164 + pub_r001386_8 * 2 + 539) & 127;
    if (stage_v_178 > 46) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_156 + pub_r001386_0 * 2 + 542) & 127;
    if (stage_v_179 > 58) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001386_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001386_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_179 + pub_r001386_17 * 2 + 551) & 127;
    if (stage_v_182 > 48) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (helper_flow_3 + pub_r001386_2 * 2 + 554) & 127;
    if (stage_v_183 > 55) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001386_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001386_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001386_11 + pub_r001386_20 * 2 + 563) & 127;
    if (stage_v_186 > 39) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_83 + pub_r001386_1 * 2 + 566) & 127;
    if (stage_v_187 > 50) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_146 + pub_r001386_11 * 2 + 569) & 127;
    if (stage_v_188 > 55) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001386_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (sec_r001386_6 + pub_r001386_16 * 2 + 575) & 127;
    if (stage_v_190 > 47) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001386_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_22 + pub_r001386_1 * 2 + 581) & 127;
    if (stage_v_192 > 35) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_24 + pub_r001386_14 * 2 + 584) & 127;
    if (stage_v_193 > 58) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001386_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_127 + pub_r001386_17 * 2 + 590) & 127;
    if (stage_v_195 > 20) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_172 + pub_r001386_7 * 2 + 593) & 127;
    if (stage_v_196 > 51) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_114 + pub_r001386_8 * 2 + 596) & 127;
    if (stage_v_197 > 44) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001386_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_196 + pub_r001386_14 * 2 + 602) & 127;
    if (stage_v_199 > 30) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_21 + pub_r001386_14 * 2 + 605) & 127;
    if (stage_v_200 > 38) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001386_19 + pub_r001386_2 * 2 + 608) & 127;
    if (stage_v_201 > 16) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001386_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001386_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001386_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_81 + pub_r001386_8 * 2 + 620) & 127;
    if (stage_v_205 > 35) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_177 + pub_r001386_15 * 2 + 623) & 127;
    if (stage_v_206 > 17) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_87 + pub_r001386_17 * 2 + 626) & 127;
    if (stage_v_207 > 49) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (helper_flow_1 + pub_r001386_14 * 2 + 629) & 127;
    if (stage_v_208 > 39) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (sec_r001386_16 + pub_r001386_0 * 2 + 632) & 127;
    if (stage_v_209 > 39) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_81 + pub_r001386_14 * 2 + 635) & 127;
    if (stage_v_210 > 22) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_207 + pub_r001386_17 * 2 + 638) & 127;
    if (stage_v_211 > 19) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_71 + pub_r001386_19 * 2 + 641) & 127;
    if (stage_v_212 > 17) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (helper_flow_3 + pub_r001386_0 * 2 + 644) & 127;
    if (stage_v_213 > 34) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001386_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001386_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001386_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001386_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_60 + pub_r001386_8 * 2 + 659) & 127;
    if (stage_v_218 > 20) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001386_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001386_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001386_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (helper_flow_6 + pub_r001386_10 * 2 + 671) & 127;
    if (stage_v_222 > 32) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001386_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_48 + pub_r001386_19 * 2 + 677) & 127;
    if (stage_v_224 > 54) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_93 + pub_r001386_2 * 2 + 680) & 127;
    if (stage_v_225 > 60) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (sec_r001386_12 + pub_r001386_16 * 2 + 683) & 127;
    if (stage_v_226 > 18) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_47 + pub_r001386_12 * 2 + 686) & 127;
    if (stage_v_227 > 40) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001386_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001386_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001386_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_178 + pub_r001386_6 * 2 + 698) & 127;
    if (stage_v_231 > 19) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001386_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001386_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_133 + pub_r001386_8 * 2 + 707) & 127;
    if (stage_v_234 > 50) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001386_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_20 + pub_r001386_15 * 2 + 713) & 127;
    if (stage_v_236 > 23) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001386_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001386_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001386_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (helper_flow_3 + pub_r001386_17 * 2 + 725) & 127;
    if (stage_v_240 > 26) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (sec_r001386_2 + pub_r001386_13 * 2 + 728) & 127;
    if (stage_v_241 > 46) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_86 + pub_r001386_3 * 2 + 731) & 127;
    if (stage_v_242 > 17) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_169 + pub_r001386_1 * 2 + 734) & 127;
    if (stage_v_243 > 27) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
