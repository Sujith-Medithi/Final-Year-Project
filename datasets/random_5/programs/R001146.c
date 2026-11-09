/*
 * Benchmark Program: R001146
 * Security Family: implicit_flow
 * Generator Seed: 614613
 * High Inputs: 23 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001146_4613_0 {
    int cutoff;
    int gain_db;
    int prev_in;
    int buffer[3];
};

struct Vector3D_R001146_4613_1 {
    int coord_z;
    int norm_sq;
    short coord_y;
    int heading;
    unsigned char coord_x;
    int buffer[3];
};

struct StreamBuffer_R001146_4613_2 {
    unsigned char state;
    int tail;
    unsigned char checksum;
    int buffer[3];
};

union PacketPayload_R001146_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001146_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001146_4613_0(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001146_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_53 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_53 > 30) {
        acc = (acc + tally_53 * 2 + 5) & 127;
        aux ^= (tally_53 & 15);
    } else {
        acc = (acc - tally_53 + 11) & 127;
        aux += 3;
    }
    int mask_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001146_4613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001146_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int offset_86 = (aux + st.buffer[1]) & 3;
    switch (offset_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_36 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_36 > 44) {
        acc = (acc + threshold_36 * 2 + 5) & 127;
        aux ^= (threshold_36 & 15);
    } else {
        acc = (acc - threshold_36 + 11) & 127;
        aux += 3;
    }
    int index_reg_42 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_42 = (index_reg_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_42) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_2(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int factor_23 = (aux + st.buffer[1]) & 3;
    switch (factor_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_97 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_97 > 18) {
        acc = (acc + checksum_97 * 2 + 5) & 127;
        aux ^= (checksum_97 & 15);
    } else {
        acc = (acc - checksum_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_68 = local_arr[aux % 3];
    acc = (acc + parity_68 * 2) & 127;
    int window_44 = (st.buffer[0] * 3 + aux) & 63;
    if (window_44 > 48) {
        acc = (acc + window_44 * 2 + 5) & 127;
        aux ^= (window_44 & 15);
    } else {
        acc = (acc - window_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_77 = local_arr[aux % 3];
    acc = (acc + phase_77 * 2) & 127;
    int factor_15 = (aux + st.buffer[1]) & 3;
    switch (factor_15) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_69 = 0;
    for (int k = 0; k < 2; k++) {
        mask_69 = (mask_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_5(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001146_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_87 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_87 = (checksum_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_87) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_17) & 63;
    acc ^= aux;
    int scale_65 = (aux + st.buffer[1]) & 3;
    switch (scale_65) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001146_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_56 = (aux + st.buffer[1]) & 3;
    switch (stride_56) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_16 = local_arr[aux % 3];
    acc = (acc + scale_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_52 = (aux + st.buffer[1]) & 3;
    switch (metric_52) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_68 = local_arr[aux % 3];
    acc = (acc + offset_68 * 2) & 127;
    int tally_99 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_99 > 22) {
        acc = (acc + tally_99 * 2 + 5) & 127;
        aux ^= (tally_99 & 15);
    } else {
        acc = (acc - tally_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001146_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_70 = (aux + st.buffer[1]) & 3;
    switch (margin_70) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tracker_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_69) & 63;
    acc ^= aux;
    int sample_10 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_10 > 37) {
        acc = (acc + sample_10 * 2 + 5) & 127;
        aux ^= (sample_10 & 15);
    } else {
        acc = (acc - sample_10 + 11) & 127;
        aux += 3;
    }
    int accumulator_40 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_40 = (accumulator_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_40) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_10(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001146_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int stride_97 = (aux + st.buffer[1]) & 3;
    switch (stride_97) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_11(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tally_57 = 0;
    for (int k = 0; k < 3; k++) {
        tally_57 = (tally_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_57) & 127;
    }
    int delta_99 = (aux + st.buffer[1]) & 3;
    switch (delta_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_12(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001146_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_98 = 0;
    for (int k = 0; k < 2; k++) {
        residue_98 = (residue_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_98) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_99 = local_arr[aux % 3];
    acc = (acc + bound_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_39 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_39 > 30) {
        acc = (acc + metric_39 * 2 + 5) & 127;
        aux ^= (metric_39 & 15);
    } else {
        acc = (acc - metric_39 + 11) & 127;
        aux += 3;
    }
    int parity_58 = 0;
    for (int k = 0; k < 3; k++) {
        parity_58 = (parity_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001146_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int phase_85 = 0;
    for (int k = 0; k < 2; k++) {
        phase_85 = (phase_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_85) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_36 = local_arr[aux % 3];
    acc = (acc + margin_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001146_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_19 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_19 > 17) {
        acc = (acc + checksum_19 * 2 + 5) & 127;
        aux ^= (checksum_19 & 15);
    } else {
        acc = (acc - checksum_19 + 11) & 127;
        aux += 3;
    }
    int metric_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_34) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_16 = local_arr[aux % 3];
    acc = (acc + window_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001146_4613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001146_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_65) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_29 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_29 > 45) {
        acc = (acc + quotient_29 * 2 + 5) & 127;
        aux ^= (quotient_29 & 15);
    } else {
        acc = (acc - quotient_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_17(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_25 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_25 > 28) {
        acc = (acc + quantum_25 * 2 + 5) & 127;
        aux ^= (quantum_25 & 15);
    } else {
        acc = (acc - quantum_25 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_55 = local_arr[aux % 3];
    acc = (acc + weight_55 * 2) & 127;
    int accumulator_62 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_62 = (accumulator_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001146_4613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001146_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_57 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_57 > 48) {
        acc = (acc + checksum_57 * 2 + 5) & 127;
        aux ^= (checksum_57 & 15);
    } else {
        acc = (acc - checksum_57 + 11) & 127;
        aux += 3;
    }
    int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001146_0;
    int sec_r001146_1;
    int sec_r001146_2;
    int sec_r001146_3;
    int sec_r001146_4;
    int sec_r001146_5;
    int sec_r001146_6;
    int sec_r001146_7;
    int sec_r001146_8;
    int sec_r001146_9;
    int sec_r001146_10;
    int sec_r001146_11;
    int sec_r001146_12;
    int sec_r001146_13;
    int sec_r001146_14;
    int sec_r001146_15;
    int sec_r001146_16;
    int sec_r001146_17;
    int sec_r001146_18;
    int sec_r001146_19;
    int sec_r001146_20;
    int sec_r001146_21;
    int sec_r001146_22;
    int pub_r001146_0;
    int pub_r001146_1;
    int pub_r001146_2;
    int pub_r001146_3;
    int pub_r001146_4;
    int pub_r001146_5;
    int pub_r001146_6;
    int pub_r001146_7;
    int pub_r001146_8;
    int pub_r001146_9;
    int pub_r001146_10;
    int pub_r001146_11;
    int pub_r001146_12;
    int pub_r001146_13;
    int pub_r001146_14;
    int pub_r001146_15;
    int pub_r001146_16;
    int pub_r001146_17;
    int pub_r001146_18;
    int pub_r001146_19;
    int pub_r001146_20;
    int pub_r001146_21;
    int pub_r001146_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001146_0 >= -100 && pub_r001146_0 <= 100);
    __CPROVER_assume(pub_r001146_1 >= -100 && pub_r001146_1 <= 100);
    __CPROVER_assume(pub_r001146_2 >= -100 && pub_r001146_2 <= 100);
    __CPROVER_assume(pub_r001146_3 >= -100 && pub_r001146_3 <= 100);
    __CPROVER_assume(pub_r001146_4 >= -100 && pub_r001146_4 <= 100);
    __CPROVER_assume(pub_r001146_5 >= -100 && pub_r001146_5 <= 100);
    __CPROVER_assume(pub_r001146_6 >= -100 && pub_r001146_6 <= 100);
    __CPROVER_assume(pub_r001146_7 >= -100 && pub_r001146_7 <= 100);
    __CPROVER_assume(pub_r001146_8 >= -100 && pub_r001146_8 <= 100);
    __CPROVER_assume(pub_r001146_9 >= -100 && pub_r001146_9 <= 100);
    __CPROVER_assume(pub_r001146_10 >= -100 && pub_r001146_10 <= 100);
    __CPROVER_assume(pub_r001146_11 >= -100 && pub_r001146_11 <= 100);
    __CPROVER_assume(pub_r001146_12 >= -100 && pub_r001146_12 <= 100);
    __CPROVER_assume(pub_r001146_13 >= -100 && pub_r001146_13 <= 100);
    __CPROVER_assume(pub_r001146_14 >= -100 && pub_r001146_14 <= 100);
    __CPROVER_assume(pub_r001146_15 >= -100 && pub_r001146_15 <= 100);
    __CPROVER_assume(pub_r001146_16 >= -100 && pub_r001146_16 <= 100);
    __CPROVER_assume(pub_r001146_17 >= -100 && pub_r001146_17 <= 100);
    __CPROVER_assume(pub_r001146_18 >= -100 && pub_r001146_18 <= 100);
    __CPROVER_assume(pub_r001146_19 >= -100 && pub_r001146_19 <= 100);
    __CPROVER_assume(pub_r001146_20 >= -100 && pub_r001146_20 <= 100);
    __CPROVER_assume(pub_r001146_21 >= -100 && pub_r001146_21 <= 100);
    __CPROVER_assume(pub_r001146_22 >= -100 && pub_r001146_22 <= 100);
    __CPROVER_assume(sec_r001146_0 >= 0 && sec_r001146_0 <= 255);
    __CPROVER_assume(sec_r001146_1 >= 0 && sec_r001146_1 <= 255);
    __CPROVER_assume(sec_r001146_2 >= 0 && sec_r001146_2 <= 255);
    __CPROVER_assume(sec_r001146_3 >= 0 && sec_r001146_3 <= 255);
    __CPROVER_assume(sec_r001146_4 >= 0 && sec_r001146_4 <= 255);
    __CPROVER_assume(sec_r001146_5 >= 0 && sec_r001146_5 <= 255);
    __CPROVER_assume(sec_r001146_6 >= 0 && sec_r001146_6 <= 255);
    __CPROVER_assume(sec_r001146_7 >= 0 && sec_r001146_7 <= 255);
    __CPROVER_assume(sec_r001146_8 >= 0 && sec_r001146_8 <= 255);
    __CPROVER_assume(sec_r001146_9 >= 0 && sec_r001146_9 <= 255);
    __CPROVER_assume(sec_r001146_10 >= 0 && sec_r001146_10 <= 255);
    __CPROVER_assume(sec_r001146_11 >= 0 && sec_r001146_11 <= 255);
    __CPROVER_assume(sec_r001146_12 >= 0 && sec_r001146_12 <= 255);
    __CPROVER_assume(sec_r001146_13 >= 0 && sec_r001146_13 <= 255);
    __CPROVER_assume(sec_r001146_14 >= 0 && sec_r001146_14 <= 255);
    __CPROVER_assume(sec_r001146_15 >= 0 && sec_r001146_15 <= 255);
    __CPROVER_assume(sec_r001146_16 >= 0 && sec_r001146_16 <= 255);
    __CPROVER_assume(sec_r001146_17 >= 0 && sec_r001146_17 <= 255);
    __CPROVER_assume(sec_r001146_18 >= 0 && sec_r001146_18 <= 255);
    __CPROVER_assume(sec_r001146_19 >= 0 && sec_r001146_19 <= 255);
    __CPROVER_assume(sec_r001146_20 >= 0 && sec_r001146_20 <= 255);
    __CPROVER_assume(sec_r001146_21 >= 0 && sec_r001146_21 <= 255);
    __CPROVER_assume(sec_r001146_22 >= 0 && sec_r001146_22 <= 255);

    struct FilterState_R001146_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001146_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001146_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001146_0 + 7) & 15;
    struct Vector3D_R001146_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001146_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001146_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001146_0 + 9) & 15;
    struct StreamBuffer_R001146_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001146_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001146_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001146_0 + 11) & 15;

    union PacketPayload_R001146_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001146_4613_0(sec_r001146_0, sec_r001146_1, pub_r001146_2);
    int helper_flow_1 = fn_R001146_4613_1(sec_r001146_1, sec_r001146_2, pub_r001146_3, pub_r001146_4);
    int helper_flow_2 = fn_R001146_4613_2(sec_r001146_2, sec_r001146_3);
    int helper_flow_3 = fn_R001146_4613_3(sec_r001146_3, pub_r001146_4, pub_r001146_5, pub_r001146_6);
    int helper_flow_4 = fn_R001146_4613_4(sec_r001146_4, pub_r001146_5, pub_r001146_6, pub_r001146_7);
    int helper_flow_5 = fn_R001146_4613_5(sec_r001146_5, pub_r001146_6);
    int helper_flow_6 = fn_R001146_4613_6(sec_r001146_6, sec_r001146_7, pub_r001146_8, pub_r001146_9, pub_r001146_10);
    int helper_flow_7 = fn_R001146_4613_7(sec_r001146_7, sec_r001146_8, pub_r001146_9, pub_r001146_10, pub_r001146_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001146_5 + pub_r001146_8 * 2 + 5) & 127;
    if (stage_v_0 > 49) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001146_0 + pub_r001146_16 * 2 + 8) & 127;
    if (stage_v_1 > 23) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001146_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (stage_v_0 + pub_r001146_4 * 2 + 14) & 127;
    if (stage_v_3 > 29) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001146_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_3 + pub_r001146_21 * 2 + 20) & 127;
    if (stage_v_5 > 50) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001146_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001146_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001146_22 + pub_r001146_1 * 2 + 29) & 127;
    if (stage_v_8 > 50) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_5 + pub_r001146_19 * 2 + 32) & 127;
    if (stage_v_9 > 42) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001146_14 + pub_r001146_20 * 2 + 35) & 127;
    if (stage_v_10 > 44) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001146_11 + pub_r001146_18 * 2 + 38) & 127;
    if (stage_v_11 > 24) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001146_9 + pub_r001146_12 * 2 + 41) & 127;
    if (stage_v_12 > 35) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001146_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001146_6 + pub_r001146_19 * 2 + 47) & 127;
    if (stage_v_14 > 24) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001146_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_6 + pub_r001146_17 * 2 + 53) & 127;
    if (stage_v_16 > 26) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001146_21 + pub_r001146_22 * 2 + 56) & 127;
    if (stage_v_17 > 28) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001146_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001146_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001146_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001146_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_5 + pub_r001146_14 * 2 + 71) & 127;
    if (stage_v_22 > 17) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001146_19 + pub_r001146_7 * 2 + 74) & 127;
    if (stage_v_23 > 24) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_0 + pub_r001146_15 * 2 + 77) & 127;
    if (stage_v_24 > 22) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_5 + pub_r001146_10 * 2 + 80) & 127;
    if (stage_v_25 > 52) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001146_20 + pub_r001146_17 * 2 + 83) & 127;
    if (stage_v_26 > 28) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_4 + pub_r001146_14 * 2 + 86) & 127;
    if (stage_v_27 > 40) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001146_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_12 + pub_r001146_8 * 2 + 92) & 127;
    if (stage_v_29 > 17) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001146_1 + pub_r001146_3 * 2 + 95) & 127;
    if (stage_v_30 > 38) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001146_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_6 + pub_r001146_11 * 2 + 101) & 127;
    if (stage_v_32 > 23) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_17 + pub_r001146_5 * 2 + 104) & 127;
    if (stage_v_33 > 33) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_16 + pub_r001146_11 * 2 + 107) & 127;
    if (stage_v_34 > 56) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001146_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001146_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_11 + pub_r001146_22 * 2 + 116) & 127;
    if (stage_v_37 > 54) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001146_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001146_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_4 + pub_r001146_1 * 2 + 125) & 127;
    if (stage_v_40 > 49) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_16 + pub_r001146_12 * 2 + 128) & 127;
    if (stage_v_41 > 16) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001146_21 + pub_r001146_8 * 2 + 131) & 127;
    if (stage_v_42 > 19) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001146_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_2 + pub_r001146_5 * 2 + 137) & 127;
    if (stage_v_44 > 15) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001146_20 + pub_r001146_0 * 2 + 140) & 127;
    if (stage_v_45 > 44) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_14 + pub_r001146_1 * 2 + 143) & 127;
    if (stage_v_46 > 23) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001146_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_26 + pub_r001146_2 * 2 + 149) & 127;
    if (stage_v_48 > 31) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001146_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001146_21 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001146_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001146_17 + pub_r001146_14 * 2 + 161) & 127;
    if (stage_v_52 > 18) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001146_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_11 + pub_r001146_18 * 2 + 167) & 127;
    if (stage_v_54 > 59) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001146_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001146_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_12 + pub_r001146_20 * 2 + 176) & 127;
    if (stage_v_57 > 48) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_33 + pub_r001146_19 * 2 + 179) & 127;
    if (stage_v_58 > 59) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001146_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001146_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001146_13 + pub_r001146_12 * 2 + 188) & 127;
    if (stage_v_61 > 40) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001146_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001146_20 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001146_1 + pub_r001146_5 * 2 + 197) & 127;
    if (stage_v_64 > 30) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001146_20 + pub_r001146_22 * 2 + 200) & 127;
    if (stage_v_65 > 60) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001146_5 + pub_r001146_21 * 2 + 203) & 127;
    if (stage_v_66 > 53) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_45 + pub_r001146_2 * 2 + 206) & 127;
    if (stage_v_67 > 17) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001146_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001146_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_42 + pub_r001146_11 * 2 + 215) & 127;
    if (stage_v_70 > 23) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_29 + pub_r001146_15 * 2 + 218) & 127;
    if (stage_v_71 > 19) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_64 + pub_r001146_15 * 2 + 221) & 127;
    if (stage_v_72 > 18) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001146_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001146_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001146_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (helper_flow_4 + pub_r001146_11 * 2 + 233) & 127;
    if (stage_v_76 > 37) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_2 + pub_r001146_1 * 2 + 236) & 127;
    if (stage_v_77 > 21) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_32 + pub_r001146_10 * 2 + 239) & 127;
    if (stage_v_78 > 26) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001146_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_52 + pub_r001146_5 * 2 + 245) & 127;
    if (stage_v_80 > 41) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001146_7 + pub_r001146_2 * 2 + 248) & 127;
    if (stage_v_81 > 42) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001146_20 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_48 + pub_r001146_20 * 2 + 254) & 127;
    if (stage_v_83 > 20) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_2 + pub_r001146_15 * 2 + 257) & 127;
    if (stage_v_84 > 23) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_57 + pub_r001146_10 * 2 + 260) & 127;
    if (stage_v_85 > 40) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001146_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001146_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001146_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001146_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001146_7 + pub_r001146_6 * 2 + 275) & 127;
    if (stage_v_90 > 17) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_14 + pub_r001146_22 * 2 + 278) & 127;
    if (stage_v_91 > 27) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_52 + pub_r001146_4 * 2 + 281) & 127;
    if (stage_v_92 > 60) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_4 + pub_r001146_11 * 2 + 284) & 127;
    if (stage_v_93 > 17) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001146_5 + pub_r001146_12 * 2 + 287) & 127;
    if (stage_v_94 > 29) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001146_6 + pub_r001146_22 * 2 + 290) & 127;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001146_17 + pub_r001146_13 * 2 + 293) & 127;
    if (stage_v_96 > 36) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001146_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001146_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_80 + pub_r001146_16 * 2 + 302) & 127;
    if (stage_v_99 > 26) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001146_7 + pub_r001146_13 * 2 + 305) & 127;
    if (stage_v_100 > 56) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001146_10 + pub_r001146_8 * 2 + 308) & 127;
    if (stage_v_101 > 46) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_46 + pub_r001146_12 * 2 + 311) & 127;
    if (stage_v_102 > 58) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_27 + pub_r001146_17 * 2 + 314) & 127;
    if (stage_v_103 > 39) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_94 + pub_r001146_19 * 2 + 317) & 127;
    if (stage_v_104 > 27) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_91 + pub_r001146_19 * 2 + 320) & 127;
    if (stage_v_105 > 25) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001146_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001146_21 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_12 + pub_r001146_1 * 2 + 329) & 127;
    if (stage_v_108 > 46) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_83 + pub_r001146_2 * 2 + 332) & 127;
    if (stage_v_109 > 46) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001146_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001146_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_14 + pub_r001146_17 * 2 + 341) & 127;
    if (stage_v_112 > 53) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_100 + pub_r001146_5 * 2 + 344) & 127;
    if (stage_v_113 > 24) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_14 + pub_r001146_2 * 2 + 347) & 127;
    if (stage_v_114 > 58) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001146_22 + pub_r001146_4 * 2 + 350) & 127;
    if (stage_v_115 > 32) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001146_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001146_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001146_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_93 + pub_r001146_4 * 2 + 362) & 127;
    if (stage_v_119 > 42) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001146_7 + pub_r001146_17 * 2 + 365) & 127;
    if (stage_v_120 > 54) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001146_21 + pub_r001146_5 * 2 + 368) & 127;
    if (stage_v_121 > 39) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001146_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_76 + pub_r001146_8 * 2 + 374) & 127;
    if (stage_v_123 > 49) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_112 + pub_r001146_14 * 2 + 377) & 127;
    if (stage_v_124 > 29) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (helper_flow_2 + pub_r001146_22 * 2 + 380) & 127;
    if (stage_v_125 > 45) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001146_10 + pub_r001146_12 * 2 + 383) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001146_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001146_9 + pub_r001146_2 * 2 + 389) & 127;
    if (stage_v_128 > 55) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001146_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_99 + pub_r001146_12 * 2 + 395) & 127;
    if (stage_v_130 > 46) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_61 + pub_r001146_19 * 2 + 398) & 127;
    if (stage_v_131 > 45) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_23 + pub_r001146_10 * 2 + 401) & 127;
    if (stage_v_132 > 24) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001146_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001146_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001146_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_120 + pub_r001146_9 * 2 + 413) & 127;
    if (stage_v_136 > 23) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_41 + pub_r001146_15 * 2 + 416) & 127;
    if (stage_v_137 > 22) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_42 + pub_r001146_13 * 2 + 419) & 127;
    if (stage_v_138 > 25) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001146_13 + pub_r001146_4 * 2 + 422) & 127;
    if (stage_v_139 > 57) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_80 + pub_r001146_1 * 2 + 425) & 127;
    if (stage_v_140 > 48) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_132 + pub_r001146_1 * 2 + 428) & 127;
    if (stage_v_141 > 43) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_115 + pub_r001146_3 * 2 + 431) & 127;
    if (stage_v_142 > 26) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001146_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001146_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_24 + pub_r001146_0 * 2 + 440) & 127;
    if (stage_v_145 > 46) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_96 + pub_r001146_6 * 2 + 443) & 127;
    if (stage_v_146 > 17) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_3 + pub_r001146_20 * 2 + 446) & 127;
    if (stage_v_147 > 38) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001146_9 + pub_r001146_16 * 2 + 449) & 127;
    if (stage_v_148 > 32) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001146_0 + pub_r001146_5 * 2 + 452) & 127;
    if (stage_v_149 > 54) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_1 + pub_r001146_4 * 2 + 455) & 127;
    if (stage_v_150 > 19) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_91 + pub_r001146_6 * 2 + 458) & 127;
    if (stage_v_151 > 50) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_121 + pub_r001146_21 * 2 + 461) & 127;
    if (stage_v_152 > 47) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_81 + pub_r001146_15 * 2 + 464) & 127;
    if (stage_v_153 > 18) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_3 + pub_r001146_8 * 2 + 467) & 127;
    if (stage_v_154 > 38) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_119 + pub_r001146_13 * 2 + 470) & 127;
    if (stage_v_155 > 26) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_17 + pub_r001146_11 * 2 + 473) & 127;
    if (stage_v_156 > 52) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001146_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_154 + pub_r001146_4 * 2 + 479) & 127;
    if (stage_v_158 > 35) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001146_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_4 + pub_r001146_6 * 2 + 485) & 127;
    if (stage_v_160 > 59) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001146_22 + pub_r001146_3 * 2 + 488) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001146_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (helper_flow_7 + pub_r001146_12 * 2 + 494) & 127;
    if (stage_v_163 > 19) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_108 + pub_r001146_11 * 2 + 497) & 127;
    if (stage_v_164 > 34) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001146_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001146_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001146_21 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (sec_r001146_4 + pub_r001146_12 * 2 + 509) & 127;
    if (stage_v_168 > 29) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r001146_0 + pub_r001146_4 * 2 + 512) & 127;
    if (stage_v_169 > 57) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_16 + pub_r001146_22 * 2 + 515) & 127;
    if (stage_v_170 > 47) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001146_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_64 + pub_r001146_20 * 2 + 521) & 127;
    if (stage_v_172 > 43) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_70 + pub_r001146_16 * 2 + 524) & 127;
    if (stage_v_173 > 57) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_70 + pub_r001146_19 * 2 + 527) & 127;
    if (stage_v_174 > 30) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_131 + pub_r001146_5 * 2 + 530) & 127;
    if (stage_v_175 > 44) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_140 + pub_r001146_17 * 2 + 533) & 127;
    if (stage_v_176 > 24) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001146_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r001146_7 + pub_r001146_14 * 2 + 539) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_70 + pub_r001146_15 * 2 + 542) & 127;
    if (stage_v_179 > 21) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (helper_flow_7 + pub_r001146_0 * 2 + 545) & 127;
    if (stage_v_180 > 17) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001146_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_153 + pub_r001146_5 * 2 + 551) & 127;
    if (stage_v_182 > 38) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_90 + pub_r001146_5 * 2 + 554) & 127;
    if (stage_v_183 > 53) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (sec_r001146_4 + pub_r001146_21 * 2 + 557) & 127;
    if (stage_v_184 > 59) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001146_2 + pub_r001146_4 * 2 + 560) & 127;
    if (stage_v_185 > 37) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001146_21 + pub_r001146_8 * 2 + 563) & 127;
    if (stage_v_186 > 21) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001146_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001146_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001146_0 + pub_r001146_18 * 2 + 572) & 127;
    if (stage_v_189 > 24) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_3 + pub_r001146_3 * 2 + 575) & 127;
    if (stage_v_190 > 56) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_113 + pub_r001146_4 * 2 + 578) & 127;
    if (stage_v_191 > 26) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001146_22 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_8 + pub_r001146_12 * 2 + 584) & 127;
    if (stage_v_193 > 17) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_24 + pub_r001146_11 * 2 + 587) & 127;
    if (stage_v_194 > 30) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_112 + pub_r001146_15 * 2 + 590) & 127;
    if (stage_v_195 > 49) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_9 + pub_r001146_7 * 2 + 593) & 127;
    if (stage_v_196 > 15) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_33 + pub_r001146_12 * 2 + 596) & 127;
    if (stage_v_197 > 52) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001146_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_1 + pub_r001146_13 * 2 + 602) & 127;
    if (stage_v_199 > 45) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_67 + pub_r001146_14 * 2 + 605) & 127;
    if (stage_v_200 > 38) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001146_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_182 + pub_r001146_6 * 2 + 611) & 127;
    if (stage_v_202 > 30) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (sec_r001146_3 + pub_r001146_0 * 2 + 614) & 127;
    if (stage_v_203 > 15) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_169 + pub_r001146_3 * 2 + 617) & 127;
    if (stage_v_204 > 19) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_112 + pub_r001146_15 * 2 + 620) & 127;
    if (stage_v_205 > 58) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001146_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001146_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001146_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_149 + pub_r001146_5 * 2 + 632) & 127;
    if (stage_v_209 > 34) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001146_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (sec_r001146_14 + pub_r001146_13 * 2 + 638) & 127;
    if (stage_v_211 > 20) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_42 + pub_r001146_8 * 2 + 641) & 127;
    if (stage_v_212 > 58) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001146_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (helper_flow_3 + pub_r001146_0 * 2 + 647) & 127;
    if (stage_v_214 > 32) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001146_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_149 + pub_r001146_15 * 2 + 653) & 127;
    if (stage_v_216 > 34) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_185 + pub_r001146_6 * 2 + 656) & 127;
    if (stage_v_217 > 33) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001146_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001146_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001146_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_77 + pub_r001146_1 * 2 + 668) & 127;
    if (stage_v_221 > 33) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001146_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_57 + pub_r001146_3 * 2 + 674) & 127;
    if (stage_v_223 > 19) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (sec_r001146_19 + pub_r001146_15 * 2 + 677) & 127;
    if (stage_v_224 > 47) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
