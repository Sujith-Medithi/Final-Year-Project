/*
 * Benchmark Program: R000536
 * Security Family: implicit_flow
 * Generator Seed: 553613
 * High Inputs: 22 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000536_3613_0 {
    short balance;
    int status;
    int account_id;
    int buffer[3];
};

struct CipherContext_R000536_3613_1 {
    int flags;
    short counter;
    unsigned char round_key;
    short tag;
    short nonce;
    unsigned char iv;
    int buffer[3];
};

struct Vector3D_R000536_3613_2 {
    unsigned char pitch;
    int norm_sq;
    unsigned char coord_y;
    int coord_z;
    short heading;
    unsigned char coord_x;
    int buffer[3];
};

struct EventLog_R000536_3613_3 {
    int signature;
    short severity;
    unsigned char code;
    short timestamp;
    int buffer[3];
};

union TelemetryField_R000536_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000536_3613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000536_3613_0(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int cursor_21 = local_arr[aux % 3];
    acc = (acc + cursor_21 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_1(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int weight_96 = local_arr[aux % 3];
    acc = (acc + weight_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int pivot_67 = local_arr[aux % 3];
    acc = (acc + pivot_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_62) & 63;
    acc ^= aux;
    int parity_85 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_85 > 47) {
        acc = (acc + parity_85 * 2 + 5) & 127;
        aux ^= (parity_85 & 15);
    } else {
        acc = (acc - parity_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000536_3613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_65 = (aux + st.buffer[1]) & 3;
    switch (offset_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_49 = local_arr[aux % 3];
    acc = (acc + threshold_49 * 2) & 127;
    int index_reg_92 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_92 > 46) {
        acc = (acc + index_reg_92 * 2 + 5) & 127;
        aux ^= (index_reg_92 & 15);
    } else {
        acc = (acc - index_reg_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000536_3613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000536_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int coefficient_71 = local_arr[aux % 3];
    acc = (acc + coefficient_71 * 2) & 127;
    int tally_37 = (aux + st.buffer[1]) & 3;
    switch (tally_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_67) & 63;
    acc ^= aux;
    int scale_24 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_24 > 24) {
        acc = (acc + scale_24 * 2 + 5) & 127;
        aux ^= (scale_24 & 15);
    } else {
        acc = (acc - scale_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000536_3613_5(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000536_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int damping_97 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_97 > 20) {
        acc = (acc + damping_97 * 2 + 5) & 127;
        aux ^= (damping_97 & 15);
    } else {
        acc = (acc - damping_97 + 11) & 127;
        aux += 3;
    }
    int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_6(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_52 = (aux + st.buffer[1]) & 3;
    switch (margin_52) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_51 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_51 > 44) {
        acc = (acc + checksum_51 * 2 + 5) & 127;
        aux ^= (checksum_51 & 15);
    } else {
        acc = (acc - checksum_51 + 11) & 127;
        aux += 3;
    }
    int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_7(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_45 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_45 > 44) {
        acc = (acc + accumulator_45 * 2 + 5) & 127;
        aux ^= (accumulator_45 & 15);
    } else {
        acc = (acc - accumulator_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_83 = (aux + st.buffer[1]) & 3;
    switch (damping_83) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_82 = local_arr[aux % 3];
    acc = (acc + index_reg_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int factor_39 = local_arr[aux % 3];
    acc = (acc + factor_39 * 2) & 127;
    int offset_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_88) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int vector_89 = (aux + st.buffer[1]) & 3;
    switch (vector_89) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_17 = local_arr[aux % 3];
    acc = (acc + anchor_17 * 2) & 127;
    int tally_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_40 > 17) {
        acc = (acc + tally_40 * 2 + 5) & 127;
        aux ^= (tally_40 & 15);
    } else {
        acc = (acc - tally_40 + 11) & 127;
        aux += 3;
    }
    int pivot_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000536_3613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000536_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_23 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_23 > 33) {
        acc = (acc + accumulator_23 * 2 + 5) & 127;
        aux ^= (accumulator_23 & 15);
    } else {
        acc = (acc - accumulator_23 + 11) & 127;
        aux += 3;
    }
    int segment_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000536_3613_11(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000536_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int offset_72 = local_arr[aux % 3];
    acc = (acc + offset_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_84 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_84 > 36) {
        acc = (acc + tally_84 * 2 + 5) & 127;
        aux ^= (tally_84 & 15);
    } else {
        acc = (acc - tally_84 + 11) & 127;
        aux += 3;
    }
    int delta_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000536_3613_12(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_38 = (aux + st.buffer[1]) & 3;
    switch (factor_38) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_66 = local_arr[aux % 3];
    acc = (acc + delta_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_13(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_94) & 63;
    acc ^= aux;
    int vector_54 = (aux + st.buffer[1]) & 3;
    switch (vector_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000536_3613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000536_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_94 = (aux + st.buffer[1]) & 3;
    switch (accumulator_94) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_30 = local_arr[aux % 3];
    acc = (acc + stride_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000536_3613_15(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000536_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_91 = local_arr[aux % 3];
    acc = (acc + tally_91 * 2) & 127;
    int index_reg_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000536_3613_16(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000536_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_64 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_64 > 23) {
        acc = (acc + delta_64 * 2 + 5) & 127;
        aux ^= (delta_64 & 15);
    } else {
        acc = (acc - delta_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_19 = local_arr[aux % 3];
    acc = (acc + anchor_19 * 2) & 127;
    int tally_19 = (aux + st.buffer[1]) & 3;
    switch (tally_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000536_3613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000536_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_37 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_37 > 22) {
        acc = (acc + vector_37 * 2 + 5) & 127;
        aux ^= (vector_37 & 15);
    } else {
        acc = (acc - vector_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_65 = local_arr[aux % 3];
    acc = (acc + tally_65 * 2) & 127;
    int sample_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000536_0;
    int sec_r000536_1;
    int sec_r000536_2;
    int sec_r000536_3;
    int sec_r000536_4;
    int sec_r000536_5;
    int sec_r000536_6;
    int sec_r000536_7;
    int sec_r000536_8;
    int sec_r000536_9;
    int sec_r000536_10;
    int sec_r000536_11;
    int sec_r000536_12;
    int sec_r000536_13;
    int sec_r000536_14;
    int sec_r000536_15;
    int sec_r000536_16;
    int sec_r000536_17;
    int sec_r000536_18;
    int sec_r000536_19;
    int sec_r000536_20;
    int sec_r000536_21;
    int pub_r000536_0;
    int pub_r000536_1;
    int pub_r000536_2;
    int pub_r000536_3;
    int pub_r000536_4;
    int pub_r000536_5;
    int pub_r000536_6;
    int pub_r000536_7;
    int pub_r000536_8;
    int pub_r000536_9;
    int pub_r000536_10;
    int pub_r000536_11;
    int pub_r000536_12;
    int pub_r000536_13;
    int pub_r000536_14;
    int pub_r000536_15;
    int pub_r000536_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000536_0 >= -100 && pub_r000536_0 <= 100);
    __CPROVER_assume(pub_r000536_1 >= -100 && pub_r000536_1 <= 100);
    __CPROVER_assume(pub_r000536_2 >= -100 && pub_r000536_2 <= 100);
    __CPROVER_assume(pub_r000536_3 >= -100 && pub_r000536_3 <= 100);
    __CPROVER_assume(pub_r000536_4 >= -100 && pub_r000536_4 <= 100);
    __CPROVER_assume(pub_r000536_5 >= -100 && pub_r000536_5 <= 100);
    __CPROVER_assume(pub_r000536_6 >= -100 && pub_r000536_6 <= 100);
    __CPROVER_assume(pub_r000536_7 >= -100 && pub_r000536_7 <= 100);
    __CPROVER_assume(pub_r000536_8 >= -100 && pub_r000536_8 <= 100);
    __CPROVER_assume(pub_r000536_9 >= -100 && pub_r000536_9 <= 100);
    __CPROVER_assume(pub_r000536_10 >= -100 && pub_r000536_10 <= 100);
    __CPROVER_assume(pub_r000536_11 >= -100 && pub_r000536_11 <= 100);
    __CPROVER_assume(pub_r000536_12 >= -100 && pub_r000536_12 <= 100);
    __CPROVER_assume(pub_r000536_13 >= -100 && pub_r000536_13 <= 100);
    __CPROVER_assume(pub_r000536_14 >= -100 && pub_r000536_14 <= 100);
    __CPROVER_assume(pub_r000536_15 >= -100 && pub_r000536_15 <= 100);
    __CPROVER_assume(pub_r000536_16 >= -100 && pub_r000536_16 <= 100);
    __CPROVER_assume(sec_r000536_0 >= 0 && sec_r000536_0 <= 255);
    __CPROVER_assume(sec_r000536_1 >= 0 && sec_r000536_1 <= 255);
    __CPROVER_assume(sec_r000536_2 >= 0 && sec_r000536_2 <= 255);
    __CPROVER_assume(sec_r000536_3 >= 0 && sec_r000536_3 <= 255);
    __CPROVER_assume(sec_r000536_4 >= 0 && sec_r000536_4 <= 255);
    __CPROVER_assume(sec_r000536_5 >= 0 && sec_r000536_5 <= 255);
    __CPROVER_assume(sec_r000536_6 >= 0 && sec_r000536_6 <= 255);
    __CPROVER_assume(sec_r000536_7 >= 0 && sec_r000536_7 <= 255);
    __CPROVER_assume(sec_r000536_8 >= 0 && sec_r000536_8 <= 255);
    __CPROVER_assume(sec_r000536_9 >= 0 && sec_r000536_9 <= 255);
    __CPROVER_assume(sec_r000536_10 >= 0 && sec_r000536_10 <= 255);
    __CPROVER_assume(sec_r000536_11 >= 0 && sec_r000536_11 <= 255);
    __CPROVER_assume(sec_r000536_12 >= 0 && sec_r000536_12 <= 255);
    __CPROVER_assume(sec_r000536_13 >= 0 && sec_r000536_13 <= 255);
    __CPROVER_assume(sec_r000536_14 >= 0 && sec_r000536_14 <= 255);
    __CPROVER_assume(sec_r000536_15 >= 0 && sec_r000536_15 <= 255);
    __CPROVER_assume(sec_r000536_16 >= 0 && sec_r000536_16 <= 255);
    __CPROVER_assume(sec_r000536_17 >= 0 && sec_r000536_17 <= 255);
    __CPROVER_assume(sec_r000536_18 >= 0 && sec_r000536_18 <= 255);
    __CPROVER_assume(sec_r000536_19 >= 0 && sec_r000536_19 <= 255);
    __CPROVER_assume(sec_r000536_20 >= 0 && sec_r000536_20 <= 255);
    __CPROVER_assume(sec_r000536_21 >= 0 && sec_r000536_21 <= 255);

    struct Transaction_R000536_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000536_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000536_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000536_0 + 7) & 15;
    struct CipherContext_R000536_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000536_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000536_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000536_0 + 9) & 15;
    struct Vector3D_R000536_3613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000536_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000536_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000536_0 + 11) & 15;
    struct EventLog_R000536_3613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000536_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000536_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000536_0 + 13) & 15;

    union TelemetryField_R000536_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 32) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 47) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
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
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((sec_r000536_12 & 63) > 49) {
        stage_v_14 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_14) & 255;
    } else {
        stage_v_14 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_14 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((sec_r000536_19 & 63) > 45) {
        stage_v_15 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_15) & 255;
    } else {
        stage_v_15 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_15 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_15 & 63) > 26) {
        stage_v_16 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_16) & 255;
    } else {
        stage_v_16 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_16 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((stage_v_15 & 63) > 33) {
        stage_v_17 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_17) & 255;
    } else {
        stage_v_17 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_17 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_17 & 63) > 23) {
        stage_v_18 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_18) & 255;
    } else {
        stage_v_18 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_18 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((sec_r000536_7 & 63) > 42) {
        stage_v_19 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_19) & 255;
    } else {
        stage_v_19 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_19 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_17 & 63) > 57) {
        stage_v_20 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_20) & 255;
    } else {
        stage_v_20 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_20 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000536_12 & 63) > 59) {
        stage_v_21 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_21) & 255;
    } else {
        stage_v_21 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_21 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_21 & 63) > 16) {
        stage_v_22 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_22) & 255;
    } else {
        stage_v_22 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_22 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_16 & 63) > 30) {
        stage_v_23 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_23) & 255;
    } else {
        stage_v_23 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_23 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_16 & 63) > 55) {
        stage_v_24 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_24) & 255;
    } else {
        stage_v_24 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_24 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((sec_r000536_5 & 63) > 43) {
        stage_v_25 = (pub_r000536_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_25) & 255;
    } else {
        stage_v_25 = (pub_r000536_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_25 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((sec_r000536_7 & 63) > 53) {
        stage_v_26 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_26) & 255;
    } else {
        stage_v_26 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_26 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((sec_r000536_14 & 63) > 31) {
        stage_v_27 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_27) & 255;
    } else {
        stage_v_27 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_27 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_18 & 63) > 37) {
        stage_v_28 = (pub_r000536_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_28) & 255;
    } else {
        stage_v_28 = (pub_r000536_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_28 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_22 & 63) > 48) {
        stage_v_29 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_29) & 255;
    } else {
        stage_v_29 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_29 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_24 & 63) > 37) {
        stage_v_30 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_30) & 255;
    } else {
        stage_v_30 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_30 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((sec_r000536_5 & 63) > 26) {
        stage_v_31 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_31) & 255;
    } else {
        stage_v_31 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_31 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((sec_r000536_20 & 63) > 52) {
        stage_v_32 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_32) & 255;
    } else {
        stage_v_32 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_32 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_22 & 63) > 23) {
        stage_v_33 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_33) & 255;
    } else {
        stage_v_33 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_33 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000536_18 & 63) > 41) {
        stage_v_34 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_34) & 255;
    } else {
        stage_v_34 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_34 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((sec_r000536_16 & 63) > 27) {
        stage_v_35 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_35) & 255;
    } else {
        stage_v_35 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_35 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((sec_r000536_5 & 63) > 25) {
        stage_v_36 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_36) & 255;
    } else {
        stage_v_36 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_36 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_32 & 63) > 54) {
        stage_v_37 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_37) & 255;
    } else {
        stage_v_37 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_37 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000536_7 & 63) > 40) {
        stage_v_38 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_38) & 255;
    } else {
        stage_v_38 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_38 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_16 & 63) > 15) {
        stage_v_39 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_39) & 255;
    } else {
        stage_v_39 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_39 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000536_19 & 63) > 42) {
        stage_v_40 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_40) & 255;
    } else {
        stage_v_40 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_40 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_23 & 63) > 18) {
        stage_v_41 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_41) & 255;
    } else {
        stage_v_41 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_41 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_30 & 63) > 54) {
        stage_v_42 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_42) & 255;
    } else {
        stage_v_42 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_42 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_35 & 63) > 16) {
        stage_v_43 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_43) & 255;
    } else {
        stage_v_43 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_43 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_14 & 63) > 29) {
        stage_v_44 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_44) & 255;
    } else {
        stage_v_44 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_44 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_22 & 63) > 31) {
        stage_v_45 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_45) & 255;
    } else {
        stage_v_45 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_45 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_14 & 63) > 17) {
        stage_v_46 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_46) & 255;
    } else {
        stage_v_46 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_46 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000536_6 & 63) > 19) {
        stage_v_47 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_47) & 255;
    } else {
        stage_v_47 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_47 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_27 & 63) > 46) {
        stage_v_48 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_48) & 255;
    } else {
        stage_v_48 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_48 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_18 & 63) > 45) {
        stage_v_49 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_49) & 255;
    } else {
        stage_v_49 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_49 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_29 & 63) > 58) {
        stage_v_50 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_50) & 255;
    } else {
        stage_v_50 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_50 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_24 & 63) > 23) {
        stage_v_51 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_51) & 255;
    } else {
        stage_v_51 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_51 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_17 & 63) > 32) {
        stage_v_52 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_52) & 255;
    } else {
        stage_v_52 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_52 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_20 & 63) > 27) {
        stage_v_53 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_53) & 255;
    } else {
        stage_v_53 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_53 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000536_20 & 63) > 35) {
        stage_v_54 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_54) & 255;
    } else {
        stage_v_54 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_54 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000536_1 & 63) > 24) {
        stage_v_55 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_55) & 255;
    } else {
        stage_v_55 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_55 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_26 & 63) > 39) {
        stage_v_56 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_56) & 255;
    } else {
        stage_v_56 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_56 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000536_12 & 63) > 54) {
        stage_v_57 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_57) & 255;
    } else {
        stage_v_57 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_57 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_43 & 63) > 17) {
        stage_v_58 = (pub_r000536_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_58) & 255;
    } else {
        stage_v_58 = (pub_r000536_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_58 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_27 & 63) > 19) {
        stage_v_59 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_59) & 255;
    } else {
        stage_v_59 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_59 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_40 & 63) > 53) {
        stage_v_60 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_60) & 255;
    } else {
        stage_v_60 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_60 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_15 & 63) > 41) {
        stage_v_61 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_61) & 255;
    } else {
        stage_v_61 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_61 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_52 & 63) > 16) {
        stage_v_62 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_62) & 255;
    } else {
        stage_v_62 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_62 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000536_1 & 63) > 28) {
        stage_v_63 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_63) & 255;
    } else {
        stage_v_63 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_63 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_25 & 63) > 26) {
        stage_v_64 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_64) & 255;
    } else {
        stage_v_64 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_64 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000536_20 & 63) > 31) {
        stage_v_65 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_65) & 255;
    } else {
        stage_v_65 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_65 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000536_20 & 63) > 40) {
        stage_v_66 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_66) & 255;
    } else {
        stage_v_66 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_66 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_40 & 63) > 52) {
        stage_v_67 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_67) & 255;
    } else {
        stage_v_67 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_67 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_48 & 63) > 40) {
        stage_v_68 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_68) & 255;
    } else {
        stage_v_68 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_68 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_63 & 63) > 38) {
        stage_v_69 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_69) & 255;
    } else {
        stage_v_69 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_69 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_35 & 63) > 51) {
        stage_v_70 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_70) & 255;
    } else {
        stage_v_70 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_70 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_65 & 63) > 52) {
        stage_v_71 = (pub_r000536_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_71) & 255;
    } else {
        stage_v_71 = (pub_r000536_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_71 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_43 & 63) > 59) {
        stage_v_72 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_72) & 255;
    } else {
        stage_v_72 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_72 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000536_11 & 63) > 50) {
        stage_v_73 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_73) & 255;
    } else {
        stage_v_73 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_73 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_52 & 63) > 45) {
        stage_v_74 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_74) & 255;
    } else {
        stage_v_74 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_74 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000536_9 & 63) > 40) {
        stage_v_75 = (pub_r000536_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_75) & 255;
    } else {
        stage_v_75 = (pub_r000536_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_75 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000536_8 & 63) > 55) {
        stage_v_76 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_76) & 255;
    } else {
        stage_v_76 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_76 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_69 & 63) > 43) {
        stage_v_77 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_77) & 255;
    } else {
        stage_v_77 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_77 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_74 & 63) > 57) {
        stage_v_78 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_78) & 255;
    } else {
        stage_v_78 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_78 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_60 & 63) > 19) {
        stage_v_79 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_79) & 255;
    } else {
        stage_v_79 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_79 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_68 & 63) > 29) {
        stage_v_80 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_80) & 255;
    } else {
        stage_v_80 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_80 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_59 & 63) > 22) {
        stage_v_81 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_81) & 255;
    } else {
        stage_v_81 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_81 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000536_0 & 63) > 45) {
        stage_v_82 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_82) & 255;
    } else {
        stage_v_82 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_82 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_76 & 63) > 55) {
        stage_v_83 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_83) & 255;
    } else {
        stage_v_83 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_83 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000536_17 & 63) > 20) {
        stage_v_84 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_84) & 255;
    } else {
        stage_v_84 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_84 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_60 & 63) > 46) {
        stage_v_85 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_85) & 255;
    } else {
        stage_v_85 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_85 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_22 & 63) > 52) {
        stage_v_86 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_86) & 255;
    } else {
        stage_v_86 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_86 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_58 & 63) > 23) {
        stage_v_87 = (pub_r000536_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_87) & 255;
    } else {
        stage_v_87 = (pub_r000536_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_87 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000536_13 & 63) > 45) {
        stage_v_88 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_88) & 255;
    } else {
        stage_v_88 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_88 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000536_18 & 63) > 59) {
        stage_v_89 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_89) & 255;
    } else {
        stage_v_89 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_89 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000536_15 & 63) > 46) {
        stage_v_90 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_90) & 255;
    } else {
        stage_v_90 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_90 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_21 & 63) > 44) {
        stage_v_91 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_91) & 255;
    } else {
        stage_v_91 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_91 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000536_10 & 63) > 47) {
        stage_v_92 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_92) & 255;
    } else {
        stage_v_92 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_92 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_37 & 63) > 41) {
        stage_v_93 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_93) & 255;
    } else {
        stage_v_93 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_93 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 63) > 16) {
        stage_v_94 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_94) & 255;
    } else {
        stage_v_94 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_94 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_14 & 63) > 52) {
        stage_v_95 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_95) & 255;
    } else {
        stage_v_95 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_95 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000536_20 & 63) > 41) {
        stage_v_96 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_96) & 255;
    } else {
        stage_v_96 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_96 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_80 & 63) > 39) {
        stage_v_97 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_97) & 255;
    } else {
        stage_v_97 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_97 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000536_16 & 63) > 40) {
        stage_v_98 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_98) & 255;
    } else {
        stage_v_98 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_98 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000536_16 & 63) > 57) {
        stage_v_99 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_99) & 255;
    } else {
        stage_v_99 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_99 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_66 & 63) > 43) {
        stage_v_100 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_100) & 255;
    } else {
        stage_v_100 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_100 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000536_8 & 63) > 48) {
        stage_v_101 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_101) & 255;
    } else {
        stage_v_101 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_101 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000536_8 & 63) > 40) {
        stage_v_102 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_102) & 255;
    } else {
        stage_v_102 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_102 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_101 & 63) > 19) {
        stage_v_103 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_103) & 255;
    } else {
        stage_v_103 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_103 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_68 & 63) > 50) {
        stage_v_104 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_104) & 255;
    } else {
        stage_v_104 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_104 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000536_11 & 63) > 40) {
        stage_v_105 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_105) & 255;
    } else {
        stage_v_105 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_105 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_77 & 63) > 15) {
        stage_v_106 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_106) & 255;
    } else {
        stage_v_106 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_106 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000536_4 & 63) > 25) {
        stage_v_107 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_107) & 255;
    } else {
        stage_v_107 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_107 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_51 & 63) > 58) {
        stage_v_108 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_108) & 255;
    } else {
        stage_v_108 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_108 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000536_14 & 63) > 52) {
        stage_v_109 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_109) & 255;
    } else {
        stage_v_109 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_109 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000536_13 & 63) > 42) {
        stage_v_110 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_110) & 255;
    } else {
        stage_v_110 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_110 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000536_4 & 63) > 53) {
        stage_v_111 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_111) & 255;
    } else {
        stage_v_111 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_111 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_70 & 63) > 15) {
        stage_v_112 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_112) & 255;
    } else {
        stage_v_112 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_112 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_73 & 63) > 23) {
        stage_v_113 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_113) & 255;
    } else {
        stage_v_113 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_113 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000536_0 & 63) > 24) {
        stage_v_114 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_114) & 255;
    } else {
        stage_v_114 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_114 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000536_5 & 63) > 51) {
        stage_v_115 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_115) & 255;
    } else {
        stage_v_115 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_115 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000536_11 & 63) > 40) {
        stage_v_116 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_116) & 255;
    } else {
        stage_v_116 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_116 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000536_10 & 63) > 42) {
        stage_v_117 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_117) & 255;
    } else {
        stage_v_117 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_117 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000536_6 & 63) > 60) {
        stage_v_118 = (pub_r000536_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_118) & 255;
    } else {
        stage_v_118 = (pub_r000536_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_118 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_39 & 63) > 32) {
        stage_v_119 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_119) & 255;
    } else {
        stage_v_119 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_119 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000536_21 & 63) > 30) {
        stage_v_120 = (pub_r000536_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_120) & 255;
    } else {
        stage_v_120 = (pub_r000536_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_120 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_94 & 63) > 19) {
        stage_v_121 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_121) & 255;
    } else {
        stage_v_121 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_121 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000536_18 & 63) > 52) {
        stage_v_122 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_122) & 255;
    } else {
        stage_v_122 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_122 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000536_5 & 63) > 18) {
        stage_v_123 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_123) & 255;
    } else {
        stage_v_123 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_123 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_27 & 63) > 31) {
        stage_v_124 = (pub_r000536_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_124) & 255;
    } else {
        stage_v_124 = (pub_r000536_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_124 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_76 & 63) > 34) {
        stage_v_125 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_125) & 255;
    } else {
        stage_v_125 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_125 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_45 & 63) > 45) {
        stage_v_126 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_126) & 255;
    } else {
        stage_v_126 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_126 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_109 & 63) > 52) {
        stage_v_127 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_127) & 255;
    } else {
        stage_v_127 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_127 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_94 & 63) > 45) {
        stage_v_128 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_128) & 255;
    } else {
        stage_v_128 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_128 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_104 & 63) > 41) {
        stage_v_129 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_129) & 255;
    } else {
        stage_v_129 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_129 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000536_19 & 63) > 22) {
        stage_v_130 = (pub_r000536_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_130) & 255;
    } else {
        stage_v_130 = (pub_r000536_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_130 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_15 & 63) > 54) {
        stage_v_131 = (pub_r000536_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_131) & 255;
    } else {
        stage_v_131 = (pub_r000536_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_131 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_32 & 63) > 35) {
        stage_v_132 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_132) & 255;
    } else {
        stage_v_132 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_132 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000536_4 & 63) > 15) {
        stage_v_133 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_133) & 255;
    } else {
        stage_v_133 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_133 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000536_6 & 63) > 33) {
        stage_v_134 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_134) & 255;
    } else {
        stage_v_134 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_134 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_15 & 63) > 55) {
        stage_v_135 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_135) & 255;
    } else {
        stage_v_135 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_135 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000536_4 & 63) > 18) {
        stage_v_136 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_136) & 255;
    } else {
        stage_v_136 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_136 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_110 & 63) > 48) {
        stage_v_137 = (pub_r000536_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_137) & 255;
    } else {
        stage_v_137 = (pub_r000536_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_137 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_110 & 63) > 23) {
        stage_v_138 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_138) & 255;
    } else {
        stage_v_138 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_138 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_110 & 63) > 49) {
        stage_v_139 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_139) & 255;
    } else {
        stage_v_139 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_139 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_70 & 63) > 38) {
        stage_v_140 = (pub_r000536_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_140) & 255;
    } else {
        stage_v_140 = (pub_r000536_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_140 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000536_6 & 63) > 15) {
        stage_v_141 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_141) & 255;
    } else {
        stage_v_141 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_141 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_64 & 63) > 49) {
        stage_v_142 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_142) & 255;
    } else {
        stage_v_142 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_142 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_33 & 63) > 25) {
        stage_v_143 = (pub_r000536_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_143) & 255;
    } else {
        stage_v_143 = (pub_r000536_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_143 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_100 & 63) > 48) {
        stage_v_144 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_144) & 255;
    } else {
        stage_v_144 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_144 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_97 & 63) > 23) {
        stage_v_145 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_145) & 255;
    } else {
        stage_v_145 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_145 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000536_7 & 63) > 54) {
        stage_v_146 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_146) & 255;
    } else {
        stage_v_146 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_146 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_145 & 63) > 32) {
        stage_v_147 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_147) & 255;
    } else {
        stage_v_147 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_147 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000536_13 & 63) > 15) {
        stage_v_148 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_148) & 255;
    } else {
        stage_v_148 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_148 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_81 & 63) > 17) {
        stage_v_149 = (pub_r000536_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_149) & 255;
    } else {
        stage_v_149 = (pub_r000536_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_149 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_64 & 63) > 57) {
        stage_v_150 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_150) & 255;
    } else {
        stage_v_150 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_150 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000536_8 & 63) > 53) {
        stage_v_151 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_151) & 255;
    } else {
        stage_v_151 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_151 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000536_12 & 63) > 37) {
        stage_v_152 = (pub_r000536_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_152) & 255;
    } else {
        stage_v_152 = (pub_r000536_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_152 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_100 & 63) > 54) {
        stage_v_153 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_153) & 255;
    } else {
        stage_v_153 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_153 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_147 & 63) > 58) {
        stage_v_154 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_154) & 255;
    } else {
        stage_v_154 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_154 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000536_17 & 63) > 26) {
        stage_v_155 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_155) & 255;
    } else {
        stage_v_155 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_155 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000536_16 & 63) > 31) {
        stage_v_156 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_156) & 255;
    } else {
        stage_v_156 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_156 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_22 & 63) > 22) {
        stage_v_157 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_157) & 255;
    } else {
        stage_v_157 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_157 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_20 & 63) > 28) {
        stage_v_158 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_158) & 255;
    } else {
        stage_v_158 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_158 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_133 & 63) > 31) {
        stage_v_159 = (pub_r000536_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_159) & 255;
    } else {
        stage_v_159 = (pub_r000536_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_159 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000536_18 & 63) > 28) {
        stage_v_160 = (pub_r000536_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_160) & 255;
    } else {
        stage_v_160 = (pub_r000536_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_160 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000536_12 & 63) > 50) {
        stage_v_161 = (pub_r000536_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_161) & 255;
    } else {
        stage_v_161 = (pub_r000536_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_161 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_96 & 63) > 15) {
        stage_v_162 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_162) & 255;
    } else {
        stage_v_162 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_162 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_133 & 63) > 46) {
        stage_v_163 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_163) & 255;
    } else {
        stage_v_163 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_163 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_129 & 63) > 32) {
        stage_v_164 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_164) & 255;
    } else {
        stage_v_164 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_164 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_47 & 63) > 19) {
        stage_v_165 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_165) & 255;
    } else {
        stage_v_165 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_165 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((sec_r000536_10 & 63) > 59) {
        stage_v_166 = (pub_r000536_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_166) & 255;
    } else {
        stage_v_166 = (pub_r000536_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_166 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000536_12 & 63) > 21) {
        stage_v_167 = (pub_r000536_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_167) & 255;
    } else {
        stage_v_167 = (pub_r000536_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_167 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_34 & 63) > 29) {
        stage_v_168 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_168) & 255;
    } else {
        stage_v_168 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_168 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((sec_r000536_0 & 63) > 23) {
        stage_v_169 = (pub_r000536_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_169) & 255;
    } else {
        stage_v_169 = (pub_r000536_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_169 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((sec_r000536_17 & 63) > 44) {
        stage_v_170 = (pub_r000536_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_170) & 255;
    } else {
        stage_v_170 = (pub_r000536_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_170 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((stage_v_126 & 63) > 28) {
        stage_v_171 = (pub_r000536_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_171) & 255;
    } else {
        stage_v_171 = (pub_r000536_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_171 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((sec_r000536_18 & 63) > 54) {
        stage_v_172 = (pub_r000536_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_172) & 255;
    } else {
        stage_v_172 = (pub_r000536_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_172 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((stage_v_124 & 63) > 25) {
        stage_v_173 = (pub_r000536_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_173) & 255;
    } else {
        stage_v_173 = (pub_r000536_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_173 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    if ((stage_v_133 & 63) > 38) {
        stage_v_174 = (pub_r000536_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_174) & 255;
    } else {
        stage_v_174 = (pub_r000536_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_174 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    if ((stage_v_126 & 63) > 47) {
        stage_v_175 = (pub_r000536_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_175) & 255;
    } else {
        stage_v_175 = (pub_r000536_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_175 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    if ((stage_v_141 & 63) > 16) {
        stage_v_176 = (pub_r000536_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_176) & 255;
    } else {
        stage_v_176 = (pub_r000536_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_176 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
