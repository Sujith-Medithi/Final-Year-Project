/*
 * Benchmark Program: R000517
 * Security Family: nested_implicit_flow
 * Generator Seed: 551713
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000517_1713_0 {
    unsigned char tail;
    unsigned char state;
    unsigned char capacity;
    unsigned char checksum;
    int watermark;
    int buffer[3];
};

struct SensorNode_R000517_1713_1 {
    int offset;
    int reading;
    int calib;
    int buffer[3];
};

union PacketPayload_R000517_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000517_1713_0(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000517_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tracker_40 = (aux + st.buffer[1]) & 3;
    switch (tracker_40) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_69 = local_arr[aux % 3];
    acc = (acc + offset_69 * 2) & 127;
    int index_reg_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_97) & 63;
    acc ^= aux;
    int index_reg_55 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_55 > 50) {
        acc = (acc + index_reg_55 * 2 + 5) & 127;
        aux ^= (index_reg_55 & 15);
    } else {
        acc = (acc - index_reg_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000517_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_36 = local_arr[aux % 3];
    acc = (acc + delta_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int index_reg_10 = local_arr[aux % 3];
    acc = (acc + index_reg_10 * 2) & 127;
    int index_reg_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_99) & 63;
    acc ^= aux;
    int mask_98 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_98 > 42) {
        acc = (acc + mask_98 * 2 + 5) & 127;
        aux ^= (mask_98 & 15);
    } else {
        acc = (acc - mask_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_67) & 63;
    acc ^= aux;
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 36) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_84 = local_arr[aux % 3];
    acc = (acc + parity_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_4(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_27 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_27 > 44) {
        acc = (acc + factor_27 * 2 + 5) & 127;
        aux ^= (factor_27 & 15);
    } else {
        acc = (acc - factor_27 + 11) & 127;
        aux += 3;
    }
    int damping_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000517_1713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_65) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_6(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int scale_62 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_62 > 23) {
        acc = (acc + scale_62 * 2 + 5) & 127;
        aux ^= (scale_62 & 15);
    } else {
        acc = (acc - scale_62 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int tally_56 = local_arr[aux % 3];
    acc = (acc + tally_56 * 2) & 127;
    int cursor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_35 > 15) {
        acc = (acc + cursor_35 * 2 + 5) & 127;
        aux ^= (cursor_35 & 15);
    } else {
        acc = (acc - cursor_35 + 11) & 127;
        aux += 3;
    }
    int threshold_44 = (aux + st.buffer[1]) & 3;
    switch (threshold_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_33 = (aux + st.buffer[1]) & 3;
    switch (bound_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_74) & 63;
    acc ^= aux;
    int checksum_39 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_39 > 21) {
        acc = (acc + checksum_39 * 2 + 5) & 127;
        aux ^= (checksum_39 & 15);
    } else {
        acc = (acc - checksum_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_9(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int vector_82 = local_arr[aux % 3];
    acc = (acc + vector_82 * 2) & 127;
    int segment_57 = (aux + st.buffer[1]) & 3;
    switch (segment_57) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_25 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_25 > 19) {
        acc = (acc + quantum_25 * 2 + 5) & 127;
        aux ^= (quantum_25 & 15);
    } else {
        acc = (acc - quantum_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_10(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000517_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_33 = (aux + st.buffer[1]) & 3;
    switch (pivot_33) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_51 = local_arr[aux % 3];
    acc = (acc + scale_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000517_1713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int residue_76 = local_arr[aux % 3];
    acc = (acc + residue_76 * 2) & 127;
    int window_52 = (aux + st.buffer[1]) & 3;
    switch (window_52) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000517_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_13 = local_arr[aux % 3];
    acc = (acc + tally_13 * 2) & 127;
    int cursor_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_67) & 63;
    acc ^= aux;
    int pivot_64 = (aux + st.buffer[1]) & 3;
    switch (pivot_64) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_51 = local_arr[aux % 3];
    acc = (acc + index_reg_51 * 2) & 127;
    int factor_17 = (aux + st.buffer[1]) & 3;
    switch (factor_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_94 = local_arr[aux % 3];
    acc = (acc + factor_94 * 2) & 127;
    int delta_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_85) & 63;
    acc ^= aux;
    int index_reg_19 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_19 > 49) {
        acc = (acc + index_reg_19 * 2 + 5) & 127;
        aux ^= (index_reg_19 & 15);
    } else {
        acc = (acc - index_reg_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000517_1713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000517_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int mask_29 = local_arr[aux % 3];
    acc = (acc + mask_29 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000517_0;
    int sec_r000517_1;
    int sec_r000517_2;
    int sec_r000517_3;
    int sec_r000517_4;
    int sec_r000517_5;
    int sec_r000517_6;
    int sec_r000517_7;
    int sec_r000517_8;
    int sec_r000517_9;
    int sec_r000517_10;
    int sec_r000517_11;
    int sec_r000517_12;
    int sec_r000517_13;
    int sec_r000517_14;
    int sec_r000517_15;
    int sec_r000517_16;
    int sec_r000517_17;
    int sec_r000517_18;
    int pub_r000517_0;
    int pub_r000517_1;
    int pub_r000517_2;
    int pub_r000517_3;
    int pub_r000517_4;
    int pub_r000517_5;
    int pub_r000517_6;
    int pub_r000517_7;
    int pub_r000517_8;
    int pub_r000517_9;
    int pub_r000517_10;
    int pub_r000517_11;
    int pub_r000517_12;
    int pub_r000517_13;
    int pub_r000517_14;
    int pub_r000517_15;
    int pub_r000517_16;
    int pub_r000517_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000517_0 >= -100 && pub_r000517_0 <= 100);
    __CPROVER_assume(pub_r000517_1 >= -100 && pub_r000517_1 <= 100);
    __CPROVER_assume(pub_r000517_2 >= -100 && pub_r000517_2 <= 100);
    __CPROVER_assume(pub_r000517_3 >= -100 && pub_r000517_3 <= 100);
    __CPROVER_assume(pub_r000517_4 >= -100 && pub_r000517_4 <= 100);
    __CPROVER_assume(pub_r000517_5 >= -100 && pub_r000517_5 <= 100);
    __CPROVER_assume(pub_r000517_6 >= -100 && pub_r000517_6 <= 100);
    __CPROVER_assume(pub_r000517_7 >= -100 && pub_r000517_7 <= 100);
    __CPROVER_assume(pub_r000517_8 >= -100 && pub_r000517_8 <= 100);
    __CPROVER_assume(pub_r000517_9 >= -100 && pub_r000517_9 <= 100);
    __CPROVER_assume(pub_r000517_10 >= -100 && pub_r000517_10 <= 100);
    __CPROVER_assume(pub_r000517_11 >= -100 && pub_r000517_11 <= 100);
    __CPROVER_assume(pub_r000517_12 >= -100 && pub_r000517_12 <= 100);
    __CPROVER_assume(pub_r000517_13 >= -100 && pub_r000517_13 <= 100);
    __CPROVER_assume(pub_r000517_14 >= -100 && pub_r000517_14 <= 100);
    __CPROVER_assume(pub_r000517_15 >= -100 && pub_r000517_15 <= 100);
    __CPROVER_assume(pub_r000517_16 >= -100 && pub_r000517_16 <= 100);
    __CPROVER_assume(pub_r000517_17 >= -100 && pub_r000517_17 <= 100);
    __CPROVER_assume(sec_r000517_0 >= 0 && sec_r000517_0 <= 255);
    __CPROVER_assume(sec_r000517_1 >= 0 && sec_r000517_1 <= 255);
    __CPROVER_assume(sec_r000517_2 >= 0 && sec_r000517_2 <= 255);
    __CPROVER_assume(sec_r000517_3 >= 0 && sec_r000517_3 <= 255);
    __CPROVER_assume(sec_r000517_4 >= 0 && sec_r000517_4 <= 255);
    __CPROVER_assume(sec_r000517_5 >= 0 && sec_r000517_5 <= 255);
    __CPROVER_assume(sec_r000517_6 >= 0 && sec_r000517_6 <= 255);
    __CPROVER_assume(sec_r000517_7 >= 0 && sec_r000517_7 <= 255);
    __CPROVER_assume(sec_r000517_8 >= 0 && sec_r000517_8 <= 255);
    __CPROVER_assume(sec_r000517_9 >= 0 && sec_r000517_9 <= 255);
    __CPROVER_assume(sec_r000517_10 >= 0 && sec_r000517_10 <= 255);
    __CPROVER_assume(sec_r000517_11 >= 0 && sec_r000517_11 <= 255);
    __CPROVER_assume(sec_r000517_12 >= 0 && sec_r000517_12 <= 255);
    __CPROVER_assume(sec_r000517_13 >= 0 && sec_r000517_13 <= 255);
    __CPROVER_assume(sec_r000517_14 >= 0 && sec_r000517_14 <= 255);
    __CPROVER_assume(sec_r000517_15 >= 0 && sec_r000517_15 <= 255);
    __CPROVER_assume(sec_r000517_16 >= 0 && sec_r000517_16 <= 255);
    __CPROVER_assume(sec_r000517_17 >= 0 && sec_r000517_17 <= 255);
    __CPROVER_assume(sec_r000517_18 >= 0 && sec_r000517_18 <= 255);

    struct StreamBuffer_R000517_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000517_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000517_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000517_0 + 7) & 15;
    struct SensorNode_R000517_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000517_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000517_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000517_0 + 9) & 15;

    union PacketPayload_R000517_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 20) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 35) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_12 & 2) != 0) {
            stage_v_8 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_8 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_8 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_9 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_9 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_9 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((sec_r000517_5 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_10 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_10 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_10 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_11 = (pub_r000517_11 + 31) & 127;
        } else {
            stage_v_11 = (pub_r000517_11 + 13) & 127;
        }
    } else {
        stage_v_11 = (pub_r000517_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000517_1 & 2) != 0) {
            stage_v_12 = (pub_r000517_2 + 31) & 127;
        } else {
            stage_v_12 = (pub_r000517_2 + 13) & 127;
        }
    } else {
        stage_v_12 = (pub_r000517_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((sec_r000517_12 & 1) != 0) {
        if ((sec_r000517_13 & 2) != 0) {
            stage_v_13 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_13 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_13 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_4 & 2) != 0) {
            stage_v_14 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_14 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_14 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_15 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_15 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_15 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000517_2 & 2) != 0) {
            stage_v_16 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_16 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_16 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_17 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_17 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_17 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((sec_r000517_17 & 1) != 0) {
        if ((sec_r000517_2 & 2) != 0) {
            stage_v_18 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_18 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_18 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_19 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_19 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_19 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_20 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_20 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_20 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000517_12 & 2) != 0) {
            stage_v_21 = (pub_r000517_17 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000517_17 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000517_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((sec_r000517_13 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_22 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_23 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((sec_r000517_0 & 1) != 0) {
        if ((sec_r000517_16 & 2) != 0) {
            stage_v_24 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_25 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_26 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_27 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((sec_r000517_17 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_28 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_29 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000517_8 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_30 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_31 = (pub_r000517_2 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000517_2 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000517_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_32 = (pub_r000517_0 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000517_0 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000517_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_33 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000517_7 & 2) != 0) {
            stage_v_34 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000517_16 & 2) != 0) {
            stage_v_35 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000517_13 & 2) != 0) {
            stage_v_36 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_37 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_38 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000517_4 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_39 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000517_5 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_40 = (pub_r000517_0 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000517_0 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000517_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_41 = (pub_r000517_1 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000517_1 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000517_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000517_14 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_42 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000517_1 & 2) != 0) {
            stage_v_43 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000517_2 & 2) != 0) {
            stage_v_44 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000517_4 & 2) != 0) {
            stage_v_45 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000517_6 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_46 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_47 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_48 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_49 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000517_16 & 2) != 0) {
            stage_v_50 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000517_4 & 2) != 0) {
            stage_v_51 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_52 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_53 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_54 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000517_6 & 1) != 0) {
        if ((sec_r000517_1 & 2) != 0) {
            stage_v_55 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_56 = (pub_r000517_4 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000517_4 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000517_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000517_2 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_57 = (pub_r000517_17 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000517_17 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000517_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_58 = (pub_r000517_1 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000517_1 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000517_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_59 = (pub_r000517_17 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000517_17 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000517_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000517_16 & 1) != 0) {
        if ((sec_r000517_4 & 2) != 0) {
            stage_v_60 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000517_16 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_61 = (pub_r000517_11 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000517_11 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000517_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_62 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_63 = (pub_r000517_13 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000517_13 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000517_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000517_10 & 1) != 0) {
        if ((sec_r000517_16 & 2) != 0) {
            stage_v_64 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000517_13 & 2) != 0) {
            stage_v_65 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000517_7 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_66 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_7 & 2) != 0) {
            stage_v_67 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000517_7 & 2) != 0) {
            stage_v_68 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000517_13 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_69 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_70 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_71 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000517_7 & 1) != 0) {
        if ((sec_r000517_4 & 2) != 0) {
            stage_v_72 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000517_16 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_73 = (pub_r000517_13 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000517_13 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000517_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000517_6 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_74 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000517_5 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_75 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_76 = (pub_r000517_1 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000517_1 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000517_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_77 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_78 = (pub_r000517_4 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000517_4 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000517_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000517_7 & 2) != 0) {
            stage_v_79 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000517_17 & 1) != 0) {
        if ((sec_r000517_12 & 2) != 0) {
            stage_v_80 = (pub_r000517_0 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000517_0 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000517_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000517_16 & 2) != 0) {
            stage_v_81 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_82 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_83 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000517_13 & 1) != 0) {
        if ((sec_r000517_1 & 2) != 0) {
            stage_v_84 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000517_11 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_85 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000517_5 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_86 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000517_1 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_87 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_88 = (pub_r000517_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000517_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000517_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000517_11 & 1) != 0) {
        if ((sec_r000517_17 & 2) != 0) {
            stage_v_89 = (pub_r000517_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000517_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000517_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000517_7 & 2) != 0) {
            stage_v_90 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_91 = (pub_r000517_1 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000517_1 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000517_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_92 = (pub_r000517_17 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000517_17 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000517_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000517_16 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_93 = (pub_r000517_16 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000517_16 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000517_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000517_9 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_94 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_95 = (pub_r000517_13 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000517_13 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000517_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_96 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_97 = (pub_r000517_0 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000517_0 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000517_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000517_13 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_98 = (pub_r000517_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000517_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000517_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000517_15 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_99 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_100 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000517_7 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_101 = (pub_r000517_8 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000517_8 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000517_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000517_1 & 2) != 0) {
            stage_v_102 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000517_15 & 2) != 0) {
            stage_v_103 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_104 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_105 = (pub_r000517_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000517_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000517_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000517_11 & 2) != 0) {
            stage_v_106 = (pub_r000517_13 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000517_13 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000517_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000517_8 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_107 = (pub_r000517_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000517_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000517_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_108 = (pub_r000517_12 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000517_12 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000517_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000517_2 & 2) != 0) {
            stage_v_109 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_110 = (pub_r000517_11 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000517_11 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000517_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000517_9 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_111 = (pub_r000517_14 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000517_14 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000517_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000517_0 & 2) != 0) {
            stage_v_112 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000517_18 & 1) != 0) {
        if ((sec_r000517_5 & 2) != 0) {
            stage_v_113 = (pub_r000517_11 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000517_11 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000517_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000517_12 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_114 = (pub_r000517_9 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000517_9 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000517_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000517_4 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_115 = (pub_r000517_15 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000517_15 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000517_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_116 = (pub_r000517_13 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000517_13 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000517_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000517_2 & 2) != 0) {
            stage_v_117 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000517_6 & 2) != 0) {
            stage_v_118 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_119 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000517_14 & 1) != 0) {
        if ((sec_r000517_8 & 2) != 0) {
            stage_v_120 = (pub_r000517_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000517_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000517_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000517_3 & 2) != 0) {
            stage_v_121 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_122 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000517_14 & 2) != 0) {
            stage_v_123 = (pub_r000517_3 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000517_3 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000517_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000517_10 & 2) != 0) {
            stage_v_124 = (pub_r000517_10 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000517_10 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000517_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000517_9 & 2) != 0) {
            stage_v_125 = (pub_r000517_7 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000517_7 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000517_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
