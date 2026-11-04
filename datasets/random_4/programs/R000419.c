/*
 * Benchmark Program: R000419
 * Family: bitwise_flow
 * Generator Seed: 441913
 * High Inputs: 16 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000419_1913_0 {
    short pitch;
    short norm_sq;
    unsigned char coord_x;
    short coord_z;
    int coord_y;
    int heading;
    int buffer[3];
};

struct SensorNode_R000419_1913_1 {
    short reading;
    short calib;
    int offset;
    short gain;
    unsigned char status;
    int threshold;
    int buffer[3];
};

struct FilterState_R000419_1913_2 {
    int gain_db;
    unsigned char damping;
    int prev_in;
    int mode;
    int cutoff;
    short prev_out;
    int buffer[3];
};

union PacketPayload_R000419_1913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000419_1913_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000419_1913_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000419_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_60 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_60 > 12) {
        acc = (acc + stride_60 * 2 + 5) & 127;
        aux ^= (stride_60 & 15);
    } else {
        acc = (acc - stride_60 + 11) & 127;
        aux += 3;
    }
    int weight_31 = 0;
    for (int k = 0; k < 2; k++) {
        weight_31 = (weight_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_1(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_13 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_13 > 18) {
        acc = (acc + stride_13 * 2 + 5) & 127;
        aux ^= (stride_13 & 15);
    } else {
        acc = (acc - stride_13 + 11) & 127;
        aux += 3;
    }
    int threshold_78 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_78 = (threshold_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_78) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_2(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_92 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_92 > 13) {
        acc = (acc + parity_92 * 2 + 5) & 127;
        aux ^= (parity_92 & 15);
    } else {
        acc = (acc - parity_92 + 11) & 127;
        aux += 3;
    }
    int pivot_59 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_59 = (pivot_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_3(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_26 = local_arr[aux % 3];
    acc = (acc + margin_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000419_1913_4(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000419_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_43 = 0;
    for (int k = 0; k < 3; k++) {
        metric_43 = (metric_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_43) & 127;
    }
    int delta_11 = (aux + st.buffer[1]) & 3;
    switch (delta_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000419_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int segment_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_15 = local_arr[aux % 3];
    acc = (acc + bound_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000419_1913_6(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000419_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int phase_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_21 = local_arr[aux % 3];
    acc = (acc + factor_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000419_1913_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000419_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int anchor_12 = local_arr[aux % 3];
    acc = (acc + anchor_12 * 2) & 127;
    int residue_58 = (aux + st.buffer[1]) & 3;
    switch (residue_58) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_12 = 0;
    for (int k = 0; k < 3; k++) {
        phase_12 = (phase_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_12) & 127;
    }
    int anchor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000419_1913_8(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000419_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_44 = (aux + st.buffer[1]) & 3;
    switch (quotient_44) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_20) & 63;
    acc ^= aux;
    int damping_57 = 0;
    for (int k = 0; k < 2; k++) {
        damping_57 = (damping_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_98 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_98 > 15) {
        acc = (acc + weight_98 * 2 + 5) & 127;
        aux ^= (weight_98 & 15);
    } else {
        acc = (acc - weight_98 + 11) & 127;
        aux += 3;
    }
    int checksum_84 = (aux + st.buffer[1]) & 3;
    switch (checksum_84) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_14 = 0;
    for (int k = 0; k < 3; k++) {
        segment_14 = (segment_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_14) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000419_1913_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_70 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_70 > 12) {
        acc = (acc + segment_70 * 2 + 5) & 127;
        aux ^= (segment_70 & 15);
    } else {
        acc = (acc - segment_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000419_1913_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_27 = 0;
    for (int k = 0; k < 2; k++) {
        parity_27 = (parity_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_27) & 127;
    }
    int index_reg_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_93) & 63;
    acc ^= aux;
    int parity_65 = (aux + st.buffer[1]) & 3;
    switch (parity_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_77 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_77 > 31) {
        acc = (acc + offset_77 * 2 + 5) & 127;
        aux ^= (offset_77 & 15);
    } else {
        acc = (acc - offset_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_27 = local_arr[aux % 3];
    acc = (acc + tally_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000419_1913_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000419_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_51 = 0;
    for (int k = 0; k < 3; k++) {
        stride_51 = (stride_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_51) & 127;
    }
    int margin_65 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_65 > 17) {
        acc = (acc + margin_65 * 2 + 5) & 127;
        aux ^= (margin_65 & 15);
    } else {
        acc = (acc - margin_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000419_1913_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000419_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_34 = (aux + st.buffer[1]) & 3;
    switch (quantum_34) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_15 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_15 > 34) {
        acc = (acc + checksum_15 * 2 + 5) & 127;
        aux ^= (checksum_15 & 15);
    } else {
        acc = (acc - checksum_15 + 11) & 127;
        aux += 3;
    }
    int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_62) & 63;
    acc ^= aux;
    int stride_82 = 0;
    for (int k = 0; k < 2; k++) {
        stride_82 = (stride_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_82) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000419_0;
    int sec_r000419_1;
    int sec_r000419_2;
    int sec_r000419_3;
    int sec_r000419_4;
    int sec_r000419_5;
    int sec_r000419_6;
    int sec_r000419_7;
    int sec_r000419_8;
    int sec_r000419_9;
    int sec_r000419_10;
    int sec_r000419_11;
    int sec_r000419_12;
    int sec_r000419_13;
    int sec_r000419_14;
    int sec_r000419_15;
    int pub_r000419_0;
    int pub_r000419_1;
    int pub_r000419_2;
    int pub_r000419_3;
    int pub_r000419_4;
    int pub_r000419_5;
    int pub_r000419_6;
    int pub_r000419_7;
    int pub_r000419_8;
    int pub_r000419_9;
    int pub_r000419_10;
    int pub_r000419_11;
    int pub_r000419_12;
    int pub_r000419_13;
    int pub_r000419_14;
    int pub_r000419_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000419_0 >= -100 && pub_r000419_0 <= 100);
    __CPROVER_assume(pub_r000419_1 >= -100 && pub_r000419_1 <= 100);
    __CPROVER_assume(pub_r000419_2 >= -100 && pub_r000419_2 <= 100);
    __CPROVER_assume(pub_r000419_3 >= -100 && pub_r000419_3 <= 100);
    __CPROVER_assume(pub_r000419_4 >= -100 && pub_r000419_4 <= 100);
    __CPROVER_assume(pub_r000419_5 >= -100 && pub_r000419_5 <= 100);
    __CPROVER_assume(pub_r000419_6 >= -100 && pub_r000419_6 <= 100);
    __CPROVER_assume(pub_r000419_7 >= -100 && pub_r000419_7 <= 100);
    __CPROVER_assume(pub_r000419_8 >= -100 && pub_r000419_8 <= 100);
    __CPROVER_assume(pub_r000419_9 >= -100 && pub_r000419_9 <= 100);
    __CPROVER_assume(pub_r000419_10 >= -100 && pub_r000419_10 <= 100);
    __CPROVER_assume(pub_r000419_11 >= -100 && pub_r000419_11 <= 100);
    __CPROVER_assume(pub_r000419_12 >= -100 && pub_r000419_12 <= 100);
    __CPROVER_assume(pub_r000419_13 >= -100 && pub_r000419_13 <= 100);
    __CPROVER_assume(pub_r000419_14 >= -100 && pub_r000419_14 <= 100);
    __CPROVER_assume(pub_r000419_15 >= -100 && pub_r000419_15 <= 100);
    __CPROVER_assume(sec_r000419_0 >= 0 && sec_r000419_0 <= 255);
    __CPROVER_assume(sec_r000419_1 >= 0 && sec_r000419_1 <= 255);
    __CPROVER_assume(sec_r000419_2 >= 0 && sec_r000419_2 <= 255);
    __CPROVER_assume(sec_r000419_3 >= 0 && sec_r000419_3 <= 255);
    __CPROVER_assume(sec_r000419_4 >= 0 && sec_r000419_4 <= 255);
    __CPROVER_assume(sec_r000419_5 >= 0 && sec_r000419_5 <= 255);
    __CPROVER_assume(sec_r000419_6 >= 0 && sec_r000419_6 <= 255);
    __CPROVER_assume(sec_r000419_7 >= 0 && sec_r000419_7 <= 255);
    __CPROVER_assume(sec_r000419_8 >= 0 && sec_r000419_8 <= 255);
    __CPROVER_assume(sec_r000419_9 >= 0 && sec_r000419_9 <= 255);
    __CPROVER_assume(sec_r000419_10 >= 0 && sec_r000419_10 <= 255);
    __CPROVER_assume(sec_r000419_11 >= 0 && sec_r000419_11 <= 255);
    __CPROVER_assume(sec_r000419_12 >= 0 && sec_r000419_12 <= 255);
    __CPROVER_assume(sec_r000419_13 >= 0 && sec_r000419_13 <= 255);
    __CPROVER_assume(sec_r000419_14 >= 0 && sec_r000419_14 <= 255);
    __CPROVER_assume(sec_r000419_15 >= 0 && sec_r000419_15 <= 255);

    struct Vector3D_R000419_1913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000419_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000419_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000419_0 + 7) & 15;
    struct SensorNode_R000419_1913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000419_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000419_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000419_0 + 9) & 15;
    struct FilterState_R000419_1913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000419_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000419_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000419_0 + 11) & 15;

    union PacketPayload_R000419_1913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 19) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 34) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 28) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 43) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

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
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 37) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 52) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 17) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 32) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 33) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 48) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 25) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 40) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 10) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 25) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 16) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 31) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 11) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 26) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 25) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 40) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 13) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 28) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 32) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 28) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 43) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
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
    int stage_v_72 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 24) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 39) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] ^ 78) & 3;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 10) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 25) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 14) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 29) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 14) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 29) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 12) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 27) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 12) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 27) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 11) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 26) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 26) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 41) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_2.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
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

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 14) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 29) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 17) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 32) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 20) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 35) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_110 = (stage_v_110 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_1.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 54) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 21) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 36) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_1.buffer[0] ^ 121) & 3;
    switch (stage_v_118) {
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

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_2.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = table[1];
    table[1] = (table[2] + 267) & 63;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_1.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_147 = (stage_v_147 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_159 = (stage_v_159 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_1.buffer[1] * 2 + 487) & 63;
    if (stage_v_160 > 15) {
        out_sink = (out_sink + stage_v_160 - 5) & 255;
        if (stage_v_160 > 30) {
            chk_sum ^= (stage_v_160 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_160 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (out_sink > 100) ? (chk_sum & 31) : (167 & 31);
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= (stage_v_162 << 1) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = table[1];
    table[1] = (table[2] + 331) & 63;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_169 = (stage_v_169 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_0.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 37) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 52) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_1.buffer[1] * 2 + 523) & 63;
    if (stage_v_172 > 39) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 54) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 21) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 36) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_177 = (stage_v_177 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_1.buffer[1] * 2 + 541) & 63;
    if (stage_v_178 > 14) {
        out_sink = (out_sink + stage_v_178 - 5) & 255;
        if (stage_v_178 > 29) {
            chk_sum ^= (stage_v_178 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_178 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 179 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[0] ^ 184) & 3;
    switch (stage_v_181) {
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

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (st_var_0.buffer[0] ^ 186) & 3;
    switch (stage_v_183) {
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

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = table[0];
    table[0] = (table[1] + 369) & 63;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] ^ 189) & 3;
    switch (stage_v_186) {
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

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = table[1];
    table[1] = (table[2] + 379) & 63;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_1.buffer[0] ^ 193) & 3;
    switch (stage_v_190) {
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

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_191 = (stage_v_191 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_191) & 127;
    }
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] * 2 + 583) & 63;
    if (stage_v_192 > 23) {
        out_sink = (out_sink + stage_v_192 - 5) & 255;
        if (stage_v_192 > 38) {
            chk_sum ^= (stage_v_192 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_192 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[1] * 2 + 586) & 63;
    if (stage_v_193 > 33) {
        out_sink = (out_sink + stage_v_193 - 5) & 255;
        if (stage_v_193 > 48) {
            chk_sum ^= (stage_v_193 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_193 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2];
    table[2] = (table[3] + 389) & 63;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 196) & 15;
    int stage_v_195 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    chk_sum ^= stage_v_195;

    /* Security Information Flow: Family = bitwise_flow */
    int b_w0 = (sec_r000419_10 ^ 0x5A) & 63;
    int b_w1 = ((b_w0 << 2) & (sec_r000419_5 >> 2)) & 63;
    int b_w2 = ((b_w1 << 2) & (sec_r000419_4 >> 2)) & 63;
    int b_w3 = ((b_w2 << 1) ^ (sec_r000419_1 >> 1)) & 63;
    int b_w4 = ((b_w3 << 1) & (sec_r000419_8 >> 1)) & 63;
    int b_w5 = ((b_w4 << 1) ^ (sec_r000419_10 >> 1)) & 63;
    out_sink += b_w5 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
