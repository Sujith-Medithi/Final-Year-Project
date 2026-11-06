/*
 * Benchmark Program: R000555
 * Security Family: bitwise_flow
 * Generator Seed: 555513
 * High Inputs: 22 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000555_5513_0 {
    int baud_rate;
    int timeout;
    unsigned char stop_bits;
    int parity;
    int buffer[3];
};

struct Transaction_R000555_5513_1 {
    int rate;
    unsigned char account_id;
    int status;
    short balance;
    int auth_code;
    int fee;
    int buffer[3];
};

struct Vector3D_R000555_5513_2 {
    int pitch;
    unsigned char coord_z;
    unsigned char heading;
    unsigned char coord_x;
    unsigned char coord_y;
    int buffer[3];
};

struct StreamBuffer_R000555_5513_3 {
    int head;
    int watermark;
    int capacity;
    int state;
    unsigned char checksum;
    int buffer[3];
};

union RegisterBank_R000555_5513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000555_5513_0(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_37 = (aux + st.buffer[1]) & 3;
    switch (weight_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_66 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_66 > 27) {
        acc = (acc + threshold_66 * 2 + 5) & 127;
        aux ^= (threshold_66 & 15);
    } else {
        acc = (acc - threshold_66 + 11) & 127;
        aux += 3;
    }
    int stride_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_89) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_1(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000555_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int parity_15 = local_arr[aux % 3];
    acc = (acc + parity_15 * 2) & 127;
    int damping_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_27) & 63;
    acc ^= aux;
    int tracker_11 = (aux + st.buffer[1]) & 3;
    switch (tracker_11) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000555_5513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int index_reg_86 = local_arr[aux % 3];
    acc = (acc + index_reg_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int checksum_10 = local_arr[aux % 3];
    acc = (acc + checksum_10 * 2) & 127;
    int coefficient_90 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_90 > 46) {
        acc = (acc + coefficient_90 * 2 + 5) & 127;
        aux ^= (coefficient_90 & 15);
    } else {
        acc = (acc - coefficient_90 + 11) & 127;
        aux += 3;
    }
    int threshold_69 = (aux + st.buffer[1]) & 3;
    switch (threshold_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000555_5513_4(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000555_5513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int stride_95 = (aux + st.buffer[1]) & 3;
    switch (stride_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_91 = (aux + st.buffer[1]) & 3;
    switch (index_reg_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_93 = local_arr[aux % 3];
    acc = (acc + offset_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_6(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000555_5513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_90 = (aux + st.buffer[1]) & 3;
    switch (quotient_90) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_72 = local_arr[aux % 3];
    acc = (acc + tally_72 * 2) & 127;
    int segment_26 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_26 > 21) {
        acc = (acc + segment_26 * 2 + 5) & 127;
        aux ^= (segment_26 & 15);
    } else {
        acc = (acc - segment_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000555_5513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_66 = (aux + st.buffer[1]) & 3;
    switch (cursor_66) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000555_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int quotient_86 = local_arr[aux % 3];
    acc = (acc + quotient_86 * 2) & 127;
    int segment_64 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_64 > 41) {
        acc = (acc + segment_64 * 2 + 5) & 127;
        aux ^= (segment_64 & 15);
    } else {
        acc = (acc - segment_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000555_5513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000555_5513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_10(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000555_5513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_37 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_37 > 32) {
        acc = (acc + segment_37 * 2 + 5) & 127;
        aux ^= (segment_37 & 15);
    } else {
        acc = (acc - segment_37 + 11) & 127;
        aux += 3;
    }
    int tally_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000555_5513_11(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000555_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int sample_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_97) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_31 = local_arr[aux % 3];
    acc = (acc + vector_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000555_5513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_29 = (aux + st.buffer[1]) & 3;
    switch (cursor_29) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000555_5513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_31 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_31 > 37) {
        acc = (acc + pivot_31 * 2 + 5) & 127;
        aux ^= (pivot_31 & 15);
    } else {
        acc = (acc - pivot_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_38 = local_arr[aux % 3];
    acc = (acc + index_reg_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000555_5513_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000555_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_48 = local_arr[aux % 3];
    acc = (acc + checksum_48 * 2) & 127;
    int pivot_60 = (aux + st.buffer[1]) & 3;
    switch (pivot_60) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000555_5513_15(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000555_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int checksum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_32 > 28) {
        acc = (acc + checksum_32 * 2 + 5) & 127;
        aux ^= (checksum_32 & 15);
    } else {
        acc = (acc - checksum_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_48 = local_arr[aux % 3];
    acc = (acc + quotient_48 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000555_0;
    int sec_r000555_1;
    int sec_r000555_2;
    int sec_r000555_3;
    int sec_r000555_4;
    int sec_r000555_5;
    int sec_r000555_6;
    int sec_r000555_7;
    int sec_r000555_8;
    int sec_r000555_9;
    int sec_r000555_10;
    int sec_r000555_11;
    int sec_r000555_12;
    int sec_r000555_13;
    int sec_r000555_14;
    int sec_r000555_15;
    int sec_r000555_16;
    int sec_r000555_17;
    int sec_r000555_18;
    int sec_r000555_19;
    int sec_r000555_20;
    int sec_r000555_21;
    int pub_r000555_0;
    int pub_r000555_1;
    int pub_r000555_2;
    int pub_r000555_3;
    int pub_r000555_4;
    int pub_r000555_5;
    int pub_r000555_6;
    int pub_r000555_7;
    int pub_r000555_8;
    int pub_r000555_9;
    int pub_r000555_10;
    int pub_r000555_11;
    int pub_r000555_12;
    int pub_r000555_13;
    int pub_r000555_14;
    int pub_r000555_15;
    int pub_r000555_16;
    int pub_r000555_17;
    int pub_r000555_18;
    int pub_r000555_19;
    int pub_r000555_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000555_0 >= -100 && pub_r000555_0 <= 100);
    __CPROVER_assume(pub_r000555_1 >= -100 && pub_r000555_1 <= 100);
    __CPROVER_assume(pub_r000555_2 >= -100 && pub_r000555_2 <= 100);
    __CPROVER_assume(pub_r000555_3 >= -100 && pub_r000555_3 <= 100);
    __CPROVER_assume(pub_r000555_4 >= -100 && pub_r000555_4 <= 100);
    __CPROVER_assume(pub_r000555_5 >= -100 && pub_r000555_5 <= 100);
    __CPROVER_assume(pub_r000555_6 >= -100 && pub_r000555_6 <= 100);
    __CPROVER_assume(pub_r000555_7 >= -100 && pub_r000555_7 <= 100);
    __CPROVER_assume(pub_r000555_8 >= -100 && pub_r000555_8 <= 100);
    __CPROVER_assume(pub_r000555_9 >= -100 && pub_r000555_9 <= 100);
    __CPROVER_assume(pub_r000555_10 >= -100 && pub_r000555_10 <= 100);
    __CPROVER_assume(pub_r000555_11 >= -100 && pub_r000555_11 <= 100);
    __CPROVER_assume(pub_r000555_12 >= -100 && pub_r000555_12 <= 100);
    __CPROVER_assume(pub_r000555_13 >= -100 && pub_r000555_13 <= 100);
    __CPROVER_assume(pub_r000555_14 >= -100 && pub_r000555_14 <= 100);
    __CPROVER_assume(pub_r000555_15 >= -100 && pub_r000555_15 <= 100);
    __CPROVER_assume(pub_r000555_16 >= -100 && pub_r000555_16 <= 100);
    __CPROVER_assume(pub_r000555_17 >= -100 && pub_r000555_17 <= 100);
    __CPROVER_assume(pub_r000555_18 >= -100 && pub_r000555_18 <= 100);
    __CPROVER_assume(pub_r000555_19 >= -100 && pub_r000555_19 <= 100);
    __CPROVER_assume(pub_r000555_20 >= -100 && pub_r000555_20 <= 100);
    __CPROVER_assume(sec_r000555_0 >= 0 && sec_r000555_0 <= 255);
    __CPROVER_assume(sec_r000555_1 >= 0 && sec_r000555_1 <= 255);
    __CPROVER_assume(sec_r000555_2 >= 0 && sec_r000555_2 <= 255);
    __CPROVER_assume(sec_r000555_3 >= 0 && sec_r000555_3 <= 255);
    __CPROVER_assume(sec_r000555_4 >= 0 && sec_r000555_4 <= 255);
    __CPROVER_assume(sec_r000555_5 >= 0 && sec_r000555_5 <= 255);
    __CPROVER_assume(sec_r000555_6 >= 0 && sec_r000555_6 <= 255);
    __CPROVER_assume(sec_r000555_7 >= 0 && sec_r000555_7 <= 255);
    __CPROVER_assume(sec_r000555_8 >= 0 && sec_r000555_8 <= 255);
    __CPROVER_assume(sec_r000555_9 >= 0 && sec_r000555_9 <= 255);
    __CPROVER_assume(sec_r000555_10 >= 0 && sec_r000555_10 <= 255);
    __CPROVER_assume(sec_r000555_11 >= 0 && sec_r000555_11 <= 255);
    __CPROVER_assume(sec_r000555_12 >= 0 && sec_r000555_12 <= 255);
    __CPROVER_assume(sec_r000555_13 >= 0 && sec_r000555_13 <= 255);
    __CPROVER_assume(sec_r000555_14 >= 0 && sec_r000555_14 <= 255);
    __CPROVER_assume(sec_r000555_15 >= 0 && sec_r000555_15 <= 255);
    __CPROVER_assume(sec_r000555_16 >= 0 && sec_r000555_16 <= 255);
    __CPROVER_assume(sec_r000555_17 >= 0 && sec_r000555_17 <= 255);
    __CPROVER_assume(sec_r000555_18 >= 0 && sec_r000555_18 <= 255);
    __CPROVER_assume(sec_r000555_19 >= 0 && sec_r000555_19 <= 255);
    __CPROVER_assume(sec_r000555_20 >= 0 && sec_r000555_20 <= 255);
    __CPROVER_assume(sec_r000555_21 >= 0 && sec_r000555_21 <= 255);

    struct DeviceConfig_R000555_5513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000555_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000555_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000555_0 + 7) & 15;
    struct Transaction_R000555_5513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000555_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000555_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000555_0 + 9) & 15;
    struct Vector3D_R000555_5513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000555_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000555_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000555_0 + 11) & 15;
    struct StreamBuffer_R000555_5513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000555_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000555_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000555_0 + 13) & 15;

    union RegisterBank_R000555_5513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r000555_20 << 1) ^ (sec_r000555_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r000555_5 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_27 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_26 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_28 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_26 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_27 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_26 << 1) ^ (sec_r000555_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r000555_12 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_34 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_33 << 1) ^ (sec_r000555_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r000555_7 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r000555_10 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r000555_13 << 2) ^ (sec_r000555_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_37 << 1) ^ (sec_r000555_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r000555_10 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_34 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_34 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_31 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_43 << 1) ^ (sec_r000555_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_26 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r000555_20 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r000555_18 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000555_10 << 2) ^ (sec_r000555_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_48 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_31 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_45 << 2) ^ (sec_r000555_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_46 << 2) ^ (sec_r000555_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000555_7 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_43 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_27 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_35 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_30 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_58 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_57 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000555_19 << 1) ^ (sec_r000555_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000555_2 << 1) ^ (sec_r000555_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r000555_17 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_47 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r000555_18 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000555_14 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r000555_8 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_66 << 2) ^ (sec_r000555_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000555_17 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_61 << 1) ^ (sec_r000555_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_62 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_56 << 2) ^ (sec_r000555_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_61 << 2) ^ (sec_r000555_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000555_10 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_68 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_49 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_28 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r000555_13 << 1) ^ (sec_r000555_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r000555_18 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_61 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_45 << 2) ^ (sec_r000555_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_42 << 2) ^ (sec_r000555_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000555_14 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000555_7 << 1) ^ (sec_r000555_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r000555_15 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_75 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_73 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_80 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000555_15 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000555_1 << 2) ^ (sec_r000555_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000555_16 << 1) ^ (sec_r000555_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_71 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_58 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_66 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_44 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_53 << 1) ^ (sec_r000555_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000555_20 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_68 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000555_3 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000555_14 << 2) ^ (sec_r000555_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_83 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_52 << 1) ^ (sec_r000555_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_54 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r000555_3 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000555_12 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_58 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_52 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_72 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_76 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_35 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r000555_5 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_73 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_111 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_85 << 1) ^ (sec_r000555_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000555_9 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000555_12 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_50 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_46 << 2) ^ (sec_r000555_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000555_3 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000555_12 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_103 << 1) ^ (sec_r000555_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000555_8 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_124 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_106 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000555_7 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000555_18 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_117 << 1) ^ (sec_r000555_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_121 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_119 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r000555_10 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000555_6 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_110 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r000555_3 << 1) ^ (sec_r000555_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_126 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000555_20 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_71 << 2) ^ (sec_r000555_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r000555_7 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_133 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_128 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_42 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000555_7 << 1) ^ (sec_r000555_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_118 << 1) ^ (sec_r000555_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_86 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000555_6 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r000555_18 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_59 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_96 << 1) ^ (sec_r000555_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_104 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000555_4 << 1) ^ (sec_r000555_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_135 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000555_10 << 1) ^ (sec_r000555_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_37 << 1) ^ (sec_r000555_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000555_8 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000555_21 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_26 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r000555_12 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000555_9 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_158 << 1) ^ (sec_r000555_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000555_8 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000555_21 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r000555_8 << 2) ^ (sec_r000555_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_120 << 2) ^ (sec_r000555_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_102 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_114 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000555_21 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000555_5 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_75 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_50 << 1) ^ (sec_r000555_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_45 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_56 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r000555_15 << 1) ^ (sec_r000555_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_154 << 1) ^ (sec_r000555_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_50 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_79 << 2) ^ (sec_r000555_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_42 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_150 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_139 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_150 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000555_3 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_27 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_70 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_120 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000555_19 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000555_9 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_37 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_130 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_196 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000555_16 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_58 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r000555_6 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_53 << 1) ^ (sec_r000555_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_201 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_196 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_202 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_138 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_203 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r000555_6 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((sec_r000555_21 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_195 << 2) ^ (sec_r000555_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_67 << 2) ^ (sec_r000555_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_162 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_205 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r000555_5 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r000555_13 << 2) ^ (sec_r000555_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_211 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000555_9 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_52 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_213 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_57 << 1) ^ (sec_r000555_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_106 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_32 << 1) ^ (sec_r000555_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_40 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_50 << 1) ^ (sec_r000555_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_218 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_217 << 1) ^ (sec_r000555_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_175 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_221 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r000555_11 << 2) ^ (sec_r000555_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_152 << 2) ^ (sec_r000555_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_223 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_140 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r000555_13 << 2) ^ (sec_r000555_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_225 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_189 << 1) ^ (sec_r000555_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_226 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000555_0 << 2) ^ (sec_r000555_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_227 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r000555_19 << 1) ^ (sec_r000555_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_228 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_185 << 1) ^ (sec_r000555_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_229 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000555_11 << 2) ^ (sec_r000555_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r000555_18 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_231 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r000555_18 << 2) ^ (sec_r000555_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_232 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_233 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((sec_r000555_12 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_234 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_151 << 1) ^ (sec_r000555_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_235 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_195 << 1) ^ (sec_r000555_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_236 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_146 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_237 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r000555_4 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_238 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_205 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_239 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000555_6 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_240 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_95 << 2) ^ (sec_r000555_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_241 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_242 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((sec_r000555_14 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_243 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r000555_21 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_244 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_154 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_245 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((sec_r000555_6 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_246 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_192 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_247 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_104 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_248 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r000555_1 << 2) ^ (sec_r000555_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_249 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_170 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_250 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000555_17 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_251 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_41 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_252 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_206 << 1) ^ (sec_r000555_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_253 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_103 << 1) ^ (sec_r000555_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_254 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_239 << 1) ^ (sec_r000555_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_255 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_31 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_256 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r000555_12 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_257 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_157 << 2) ^ (sec_r000555_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_258 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_127 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_259 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_244 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_260 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((sec_r000555_6 << 2) ^ (sec_r000555_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_261 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r000555_4 << 2) ^ (sec_r000555_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_262 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_143 << 2) ^ (sec_r000555_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_263 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_38 << 2) ^ (sec_r000555_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_264 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_243 << 2) ^ (sec_r000555_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_265 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_163 << 2) ^ (sec_r000555_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_266 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((sec_r000555_7 << 1) ^ (sec_r000555_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_267 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_268 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_88 << 1) ^ (sec_r000555_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_269 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_101 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_270 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((sec_r000555_0 << 2) ^ (sec_r000555_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_271 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((sec_r000555_1 << 1) ^ (sec_r000555_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_272 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_202 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_273 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_143 << 2) ^ (sec_r000555_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_274 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_248 << 2) ^ (sec_r000555_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_275 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r000555_17 << 2) ^ (sec_r000555_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_276 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_200 << 2) ^ (sec_r000555_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_277 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_68 << 2) ^ (sec_r000555_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_278 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_151 << 2) ^ (sec_r000555_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_279 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r000555_11 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_280 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r000555_3 << 1) ^ (sec_r000555_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_281 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r000555_0 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_282 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_27 << 1) ^ (sec_r000555_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_283 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_68 << 2) ^ (sec_r000555_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_284 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_65 << 1) ^ (sec_r000555_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_285 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_195 << 1) ^ (sec_r000555_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_286 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_240 << 1) ^ (sec_r000555_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_287 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_85 << 1) ^ (sec_r000555_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_288 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((sec_r000555_5 << 1) ^ (sec_r000555_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_289 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_154 << 2) ^ (sec_r000555_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_290 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_194 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_291 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_172 << 2) ^ (sec_r000555_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_292 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_278 << 1) ^ (sec_r000555_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_293 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_173 << 2) ^ (sec_r000555_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_294 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((sec_r000555_17 << 1) ^ (sec_r000555_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_295 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_190 << 2) ^ (sec_r000555_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_296 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_296 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
