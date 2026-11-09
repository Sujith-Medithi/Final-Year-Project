/*
 * Benchmark Program: R001056
 * Security Family: implicit_flow
 * Generator Seed: 605613
 * High Inputs: 20 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001056_5613_0 {
    int coord_z;
    short coord_x;
    int pitch;
    int buffer[3];
};

struct AudioFrame_R001056_5613_1 {
    short envelope;
    unsigned char gain;
    short channels;
    int sample_rate;
    int buffer[3];
};

union TelemetryField_R001056_5613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001056_5613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001056_5613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tracker_54 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_54 = (tracker_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_54) & 127;
    }
    int phase_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001056_5613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_12 = (aux + st.buffer[1]) & 3;
    switch (quotient_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_38 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_38 = (anchor_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_38) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_15 = local_arr[aux % 3];
    acc = (acc + sample_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001056_5613_2(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_72 = 0;
    for (int k = 0; k < 3; k++) {
        residue_72 = (residue_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_72) & 127;
    }
    int tracker_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_38 > 41) {
        acc = (acc + tracker_38 * 2 + 5) & 127;
        aux ^= (tracker_38 & 15);
    } else {
        acc = (acc - tracker_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_34 = (aux + st.buffer[1]) & 3;
    switch (damping_34) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_96 = local_arr[aux % 3];
    acc = (acc + pivot_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001056_5613_4(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int segment_62 = local_arr[aux % 3];
    acc = (acc + segment_62 * 2) & 127;
    int phase_20 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_20 > 17) {
        acc = (acc + phase_20 * 2 + 5) & 127;
        aux ^= (phase_20 & 15);
    } else {
        acc = (acc - phase_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_5(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int accumulator_71 = local_arr[aux % 3];
    acc = (acc + accumulator_71 * 2) & 127;
    int sample_20 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_20 > 37) {
        acc = (acc + sample_20 * 2 + 5) & 127;
        aux ^= (sample_20 & 15);
    } else {
        acc = (acc - sample_20 + 11) & 127;
        aux += 3;
    }
    int margin_75 = (aux + st.buffer[1]) & 3;
    switch (margin_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_6(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_37 = local_arr[aux % 3];
    acc = (acc + sample_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001056_5613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int scale_38 = local_arr[aux % 3];
    acc = (acc + scale_38 * 2) & 127;
    int sample_30 = 0;
    for (int k = 0; k < 2; k++) {
        sample_30 = (sample_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_30) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_8(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_66 = (aux + st.buffer[1]) & 3;
    switch (tracker_66) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_12) & 63;
    acc ^= aux;
    int parity_87 = 0;
    for (int k = 0; k < 2; k++) {
        parity_87 = (parity_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_87) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_89 = local_arr[aux % 3];
    acc = (acc + delta_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001056_5613_9(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_79 = 0;
    for (int k = 0; k < 3; k++) {
        bound_79 = (bound_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_79) & 127;
    }
    int stride_62 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_62 > 34) {
        acc = (acc + stride_62 * 2 + 5) & 127;
        aux ^= (stride_62 & 15);
    } else {
        acc = (acc - stride_62 + 11) & 127;
        aux += 3;
    }
    int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_46 = local_arr[aux % 3];
    acc = (acc + tally_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001056_5613_10(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_53 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_53 > 50) {
        acc = (acc + quotient_53 * 2 + 5) & 127;
        aux ^= (quotient_53 & 15);
    } else {
        acc = (acc - quotient_53 + 11) & 127;
        aux += 3;
    }
    int mask_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_73) & 63;
    acc ^= aux;
    int segment_60 = 0;
    for (int k = 0; k < 2; k++) {
        segment_60 = (segment_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_60) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_11(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_79 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_79 = (quantum_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_79) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_92 = local_arr[aux % 3];
    acc = (acc + weight_92 * 2) & 127;
    int delta_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001056_5613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_13 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_13 > 10) {
        acc = (acc + phase_13 * 2 + 5) & 127;
        aux ^= (phase_13 & 15);
    } else {
        acc = (acc - phase_13 + 11) & 127;
        aux += 3;
    }
    int quotient_33 = (aux + st.buffer[1]) & 3;
    switch (quotient_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_13(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int stride_87 = (aux + st.buffer[1]) & 3;
    switch (stride_87) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_57 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_57 > 29) {
        acc = (acc + mask_57 * 2 + 5) & 127;
        aux ^= (mask_57 & 15);
    } else {
        acc = (acc - mask_57 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_51 = local_arr[aux % 3];
    acc = (acc + window_51 * 2) & 127;
    int tally_64 = 0;
    for (int k = 0; k < 3; k++) {
        tally_64 = (tally_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_14(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int anchor_59 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_59 = (anchor_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_59) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_33 = local_arr[aux % 3];
    acc = (acc + anchor_33 * 2) & 127;
    int quotient_81 = (aux + st.buffer[1]) & 3;
    switch (quotient_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001056_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_90 = 0;
    for (int k = 0; k < 3; k++) {
        residue_90 = (residue_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_90) & 127;
    }
    int factor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_66) & 63;
    acc ^= aux;
    int metric_21 = (aux + st.buffer[1]) & 3;
    switch (metric_21) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001056_5613_16(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001056_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int factor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_97 > 48) {
        acc = (acc + factor_97 * 2 + 5) & 127;
        aux ^= (factor_97 & 15);
    } else {
        acc = (acc - factor_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_15) & 63;
    acc ^= aux;
    int checksum_64 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_64 = (checksum_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_64) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001056_0;
    int sec_r001056_1;
    int sec_r001056_2;
    int sec_r001056_3;
    int sec_r001056_4;
    int sec_r001056_5;
    int sec_r001056_6;
    int sec_r001056_7;
    int sec_r001056_8;
    int sec_r001056_9;
    int sec_r001056_10;
    int sec_r001056_11;
    int sec_r001056_12;
    int sec_r001056_13;
    int sec_r001056_14;
    int sec_r001056_15;
    int sec_r001056_16;
    int sec_r001056_17;
    int sec_r001056_18;
    int sec_r001056_19;
    int pub_r001056_0;
    int pub_r001056_1;
    int pub_r001056_2;
    int pub_r001056_3;
    int pub_r001056_4;
    int pub_r001056_5;
    int pub_r001056_6;
    int pub_r001056_7;
    int pub_r001056_8;
    int pub_r001056_9;
    int pub_r001056_10;
    int pub_r001056_11;
    int pub_r001056_12;
    int pub_r001056_13;
    int pub_r001056_14;
    int pub_r001056_15;
    int pub_r001056_16;
    int pub_r001056_17;
    int pub_r001056_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001056_0 >= -100 && pub_r001056_0 <= 100);
    __CPROVER_assume(pub_r001056_1 >= -100 && pub_r001056_1 <= 100);
    __CPROVER_assume(pub_r001056_2 >= -100 && pub_r001056_2 <= 100);
    __CPROVER_assume(pub_r001056_3 >= -100 && pub_r001056_3 <= 100);
    __CPROVER_assume(pub_r001056_4 >= -100 && pub_r001056_4 <= 100);
    __CPROVER_assume(pub_r001056_5 >= -100 && pub_r001056_5 <= 100);
    __CPROVER_assume(pub_r001056_6 >= -100 && pub_r001056_6 <= 100);
    __CPROVER_assume(pub_r001056_7 >= -100 && pub_r001056_7 <= 100);
    __CPROVER_assume(pub_r001056_8 >= -100 && pub_r001056_8 <= 100);
    __CPROVER_assume(pub_r001056_9 >= -100 && pub_r001056_9 <= 100);
    __CPROVER_assume(pub_r001056_10 >= -100 && pub_r001056_10 <= 100);
    __CPROVER_assume(pub_r001056_11 >= -100 && pub_r001056_11 <= 100);
    __CPROVER_assume(pub_r001056_12 >= -100 && pub_r001056_12 <= 100);
    __CPROVER_assume(pub_r001056_13 >= -100 && pub_r001056_13 <= 100);
    __CPROVER_assume(pub_r001056_14 >= -100 && pub_r001056_14 <= 100);
    __CPROVER_assume(pub_r001056_15 >= -100 && pub_r001056_15 <= 100);
    __CPROVER_assume(pub_r001056_16 >= -100 && pub_r001056_16 <= 100);
    __CPROVER_assume(pub_r001056_17 >= -100 && pub_r001056_17 <= 100);
    __CPROVER_assume(pub_r001056_18 >= -100 && pub_r001056_18 <= 100);
    __CPROVER_assume(sec_r001056_0 >= 0 && sec_r001056_0 <= 255);
    __CPROVER_assume(sec_r001056_1 >= 0 && sec_r001056_1 <= 255);
    __CPROVER_assume(sec_r001056_2 >= 0 && sec_r001056_2 <= 255);
    __CPROVER_assume(sec_r001056_3 >= 0 && sec_r001056_3 <= 255);
    __CPROVER_assume(sec_r001056_4 >= 0 && sec_r001056_4 <= 255);
    __CPROVER_assume(sec_r001056_5 >= 0 && sec_r001056_5 <= 255);
    __CPROVER_assume(sec_r001056_6 >= 0 && sec_r001056_6 <= 255);
    __CPROVER_assume(sec_r001056_7 >= 0 && sec_r001056_7 <= 255);
    __CPROVER_assume(sec_r001056_8 >= 0 && sec_r001056_8 <= 255);
    __CPROVER_assume(sec_r001056_9 >= 0 && sec_r001056_9 <= 255);
    __CPROVER_assume(sec_r001056_10 >= 0 && sec_r001056_10 <= 255);
    __CPROVER_assume(sec_r001056_11 >= 0 && sec_r001056_11 <= 255);
    __CPROVER_assume(sec_r001056_12 >= 0 && sec_r001056_12 <= 255);
    __CPROVER_assume(sec_r001056_13 >= 0 && sec_r001056_13 <= 255);
    __CPROVER_assume(sec_r001056_14 >= 0 && sec_r001056_14 <= 255);
    __CPROVER_assume(sec_r001056_15 >= 0 && sec_r001056_15 <= 255);
    __CPROVER_assume(sec_r001056_16 >= 0 && sec_r001056_16 <= 255);
    __CPROVER_assume(sec_r001056_17 >= 0 && sec_r001056_17 <= 255);
    __CPROVER_assume(sec_r001056_18 >= 0 && sec_r001056_18 <= 255);
    __CPROVER_assume(sec_r001056_19 >= 0 && sec_r001056_19 <= 255);

    struct Vector3D_R001056_5613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001056_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001056_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001056_0 + 7) & 15;
    struct AudioFrame_R001056_5613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001056_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001056_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001056_0 + 9) & 15;

    union TelemetryField_R001056_5613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001056_5613_0(sec_r001056_0, sec_r001056_1, pub_r001056_2, pub_r001056_3);
    int helper_flow_1 = fn_R001056_5613_1(sec_r001056_1, sec_r001056_2, pub_r001056_3, pub_r001056_4, pub_r001056_5);
    int helper_flow_2 = fn_R001056_5613_2(sec_r001056_2, pub_r001056_3);
    int helper_flow_3 = fn_R001056_5613_3(sec_r001056_3, pub_r001056_4, pub_r001056_5, pub_r001056_6, pub_r001056_7);
    int helper_flow_4 = fn_R001056_5613_4(sec_r001056_4, sec_r001056_5, pub_r001056_6);
    int helper_flow_5 = fn_R001056_5613_5(sec_r001056_5, sec_r001056_6, pub_r001056_7);
    int helper_flow_6 = fn_R001056_5613_6(sec_r001056_6, pub_r001056_7, pub_r001056_8);
    int helper_flow_7 = fn_R001056_5613_7(sec_r001056_7, sec_r001056_8, pub_r001056_9, pub_r001056_10, pub_r001056_11);
    int helper_flow_8 = fn_R001056_5613_8(sec_r001056_8, sec_r001056_9);
    int helper_flow_9 = fn_R001056_5613_9(sec_r001056_9, sec_r001056_10, pub_r001056_11);
    int helper_flow_10 = fn_R001056_5613_10(sec_r001056_10, pub_r001056_11, pub_r001056_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_10 + pub_r001056_13 * 2 + 5) & 127;
    if (stage_v_0 > 43) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_1 + pub_r001056_17 * 2 + 8) & 127;
    if (stage_v_1 > 37) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001056_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_7 + pub_r001056_12 * 2 + 14) & 127;
    if (stage_v_3 > 33) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001056_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001056_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_8 + pub_r001056_10 * 2 + 23) & 127;
    if (stage_v_6 > 27) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001056_12 + pub_r001056_17 * 2 + 26) & 127;
    if (stage_v_7 > 30) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001056_4 + pub_r001056_16 * 2 + 29) & 127;
    if (stage_v_8 > 52) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001056_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001056_11 + pub_r001056_3 * 2 + 35) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001056_14 + pub_r001056_6 * 2 + 38) & 127;
    if (stage_v_11 > 52) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001056_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_8 + pub_r001056_6 * 2 + 44) & 127;
    if (stage_v_13 > 52) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_8 + pub_r001056_10 * 2 + 47) & 127;
    if (stage_v_14 > 22) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001056_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_9 + pub_r001056_15 * 2 + 53) & 127;
    if (stage_v_16 > 20) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001056_3 + pub_r001056_5 * 2 + 56) & 127;
    if (stage_v_17 > 17) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_6 + pub_r001056_17 * 2 + 59) & 127;
    if (stage_v_18 > 60) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001056_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_17 + pub_r001056_1 * 2 + 65) & 127;
    if (stage_v_20 > 48) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_4 + pub_r001056_2 * 2 + 68) & 127;
    if (stage_v_21 > 50) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001056_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_9 + pub_r001056_17 * 2 + 74) & 127;
    if (stage_v_23 > 44) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_18 + pub_r001056_0 * 2 + 77) & 127;
    if (stage_v_24 > 58) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001056_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001056_0 + pub_r001056_15 * 2 + 83) & 127;
    if (stage_v_26 > 22) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001056_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001056_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001056_6 + pub_r001056_0 * 2 + 92) & 127;
    if (stage_v_29 > 20) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_1 + pub_r001056_18 * 2 + 95) & 127;
    if (stage_v_30 > 35) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001056_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_3 + pub_r001056_13 * 2 + 101) & 127;
    if (stage_v_32 > 38) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_10 + pub_r001056_5 * 2 + 104) & 127;
    if (stage_v_33 > 33) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001056_13 + pub_r001056_9 * 2 + 107) & 127;
    if (stage_v_34 > 31) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_29 + pub_r001056_15 * 2 + 110) & 127;
    if (stage_v_35 > 49) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_7 + pub_r001056_6 * 2 + 113) & 127;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001056_17 + pub_r001056_14 * 2 + 116) & 127;
    if (stage_v_37 > 21) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001056_13 + pub_r001056_2 * 2 + 119) & 127;
    if (stage_v_38 > 42) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001056_8 + pub_r001056_4 * 2 + 122) & 127;
    if (stage_v_39 > 56) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_34 + pub_r001056_8 * 2 + 125) & 127;
    if (stage_v_40 > 28) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_18 + pub_r001056_18 * 2 + 128) & 127;
    if (stage_v_41 > 53) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_10 + pub_r001056_18 * 2 + 131) & 127;
    if (stage_v_42 > 52) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001056_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001056_19 + pub_r001056_1 * 2 + 137) & 127;
    if (stage_v_44 > 39) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001056_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001056_2 + pub_r001056_8 * 2 + 143) & 127;
    if (stage_v_46 > 27) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_33 + pub_r001056_4 * 2 + 146) & 127;
    if (stage_v_47 > 20) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001056_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001056_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_6 + pub_r001056_3 * 2 + 155) & 127;
    if (stage_v_50 > 46) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_41 + pub_r001056_16 * 2 + 158) & 127;
    if (stage_v_51 > 60) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001056_8 + pub_r001056_9 * 2 + 161) & 127;
    if (stage_v_52 > 24) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_4 + pub_r001056_1 * 2 + 164) & 127;
    if (stage_v_53 > 31) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_11 + pub_r001056_4 * 2 + 167) & 127;
    if (stage_v_54 > 52) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001056_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_14 + pub_r001056_6 * 2 + 173) & 127;
    if (stage_v_56 > 37) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_16 + pub_r001056_18 * 2 + 176) & 127;
    if (stage_v_57 > 30) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_41 + pub_r001056_5 * 2 + 179) & 127;
    if (stage_v_58 > 28) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001056_6 + pub_r001056_5 * 2 + 182) & 127;
    if (stage_v_59 > 34) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001056_2 + pub_r001056_6 * 2 + 185) & 127;
    if (stage_v_60 > 31) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_36 + pub_r001056_5 * 2 + 188) & 127;
    if (stage_v_61 > 54) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_29 + pub_r001056_7 * 2 + 191) & 127;
    if (stage_v_62 > 19) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_0 + pub_r001056_15 * 2 + 194) & 127;
    if (stage_v_63 > 17) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001056_7 + pub_r001056_6 * 2 + 197) & 127;
    if (stage_v_64 > 20) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001056_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_0 + pub_r001056_2 * 2 + 203) & 127;
    if (stage_v_66 > 26) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001056_14 + pub_r001056_5 * 2 + 206) & 127;
    if (stage_v_67 > 34) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_26 + pub_r001056_6 * 2 + 209) & 127;
    if (stage_v_68 > 28) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_68 + pub_r001056_15 * 2 + 212) & 127;
    if (stage_v_69 > 56) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001056_0 + pub_r001056_16 * 2 + 215) & 127;
    if (stage_v_70 > 24) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001056_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001056_17 + pub_r001056_1 * 2 + 221) & 127;
    if (stage_v_72 > 39) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001056_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_30 + pub_r001056_3 * 2 + 227) & 127;
    if (stage_v_74 > 22) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_16 + pub_r001056_5 * 2 + 230) & 127;
    if (stage_v_75 > 48) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001056_2 + pub_r001056_14 * 2 + 233) & 127;
    if (stage_v_76 > 28) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_32 + pub_r001056_1 * 2 + 236) & 127;
    if (stage_v_77 > 57) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_10 + pub_r001056_4 * 2 + 239) & 127;
    if (stage_v_78 > 50) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_68 + pub_r001056_13 * 2 + 242) & 127;
    if (stage_v_79 > 44) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_5 + pub_r001056_12 * 2 + 245) & 127;
    if (stage_v_80 > 51) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001056_9 + pub_r001056_11 * 2 + 248) & 127;
    if (stage_v_81 > 60) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001056_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (helper_flow_4 + pub_r001056_8 * 2 + 254) & 127;
    if (stage_v_83 > 44) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_14 + pub_r001056_14 * 2 + 257) & 127;
    if (stage_v_84 > 34) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001056_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_37 + pub_r001056_18 * 2 + 263) & 127;
    if (stage_v_86 > 39) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001056_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001056_9 + pub_r001056_10 * 2 + 269) & 127;
    if (stage_v_88 > 18) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_61 + pub_r001056_10 * 2 + 272) & 127;
    if (stage_v_89 > 49) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001056_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_32 + pub_r001056_2 * 2 + 278) & 127;
    if (stage_v_91 > 36) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001056_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001056_16 + pub_r001056_3 * 2 + 284) & 127;
    if (stage_v_93 > 37) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001056_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001056_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001056_14 + pub_r001056_16 * 2 + 293) & 127;
    if (stage_v_96 > 57) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_75 + pub_r001056_13 * 2 + 296) & 127;
    if (stage_v_97 > 24) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_37 + pub_r001056_3 * 2 + 299) & 127;
    if (stage_v_98 > 33) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_3 + pub_r001056_12 * 2 + 302) & 127;
    if (stage_v_99 > 19) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001056_1 + pub_r001056_2 * 2 + 305) & 127;
    if (stage_v_100 > 34) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001056_15 + pub_r001056_18 * 2 + 308) & 127;
    if (stage_v_101 > 59) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_53 + pub_r001056_11 * 2 + 311) & 127;
    if (stage_v_102 > 42) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001056_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_18 + pub_r001056_14 * 2 + 317) & 127;
    if (stage_v_104 > 15) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_98 + pub_r001056_6 * 2 + 320) & 127;
    if (stage_v_105 > 36) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001056_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_61 + pub_r001056_6 * 2 + 326) & 127;
    if (stage_v_107 > 17) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001056_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_93 + pub_r001056_11 * 2 + 332) & 127;
    if (stage_v_109 > 55) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001056_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001056_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_104 + pub_r001056_5 * 2 + 341) & 127;
    if (stage_v_112 > 50) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_11 + pub_r001056_3 * 2 + 344) & 127;
    if (stage_v_113 > 52) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_6 + pub_r001056_0 * 2 + 347) & 127;
    if (stage_v_114 > 45) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_69 + pub_r001056_4 * 2 + 350) & 127;
    if (stage_v_115 > 36) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001056_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001056_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_14 + pub_r001056_12 * 2 + 359) & 127;
    if (stage_v_118 > 57) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_47 + pub_r001056_4 * 2 + 362) & 127;
    if (stage_v_119 > 21) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_99 + pub_r001056_2 * 2 + 365) & 127;
    if (stage_v_120 > 25) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_34 + pub_r001056_11 * 2 + 368) & 127;
    if (stage_v_121 > 38) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001056_8 + pub_r001056_7 * 2 + 371) & 127;
    if (stage_v_122 > 49) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_39 + pub_r001056_16 * 2 + 374) & 127;
    if (stage_v_123 > 29) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001056_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001056_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_79 + pub_r001056_4 * 2 + 383) & 127;
    if (stage_v_126 > 36) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (helper_flow_1 + pub_r001056_15 * 2 + 386) & 127;
    if (stage_v_127 > 19) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_113 + pub_r001056_15 * 2 + 389) & 127;
    if (stage_v_128 > 38) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001056_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001056_14 + pub_r001056_14 * 2 + 395) & 127;
    if (stage_v_130 > 18) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_64 + pub_r001056_18 * 2 + 398) & 127;
    if (stage_v_131 > 50) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001056_5 + pub_r001056_1 * 2 + 401) & 127;
    if (stage_v_132 > 22) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001056_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001056_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001056_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001056_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_80 + pub_r001056_0 * 2 + 416) & 127;
    if (stage_v_137 > 25) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_63 + pub_r001056_5 * 2 + 419) & 127;
    if (stage_v_138 > 49) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_99 + pub_r001056_6 * 2 + 422) & 127;
    if (stage_v_139 > 36) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_99 + pub_r001056_0 * 2 + 425) & 127;
    if (stage_v_140 > 36) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (helper_flow_5 + pub_r001056_11 * 2 + 428) & 127;
    if (stage_v_141 > 49) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_93 + pub_r001056_18 * 2 + 431) & 127;
    if (stage_v_142 > 40) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001056_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_102 + pub_r001056_2 * 2 + 437) & 127;
    if (stage_v_144 > 27) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001056_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001056_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001056_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_72 + pub_r001056_10 * 2 + 449) & 127;
    if (stage_v_148 > 28) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_72 + pub_r001056_9 * 2 + 452) & 127;
    if (stage_v_149 > 37) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (helper_flow_4 + pub_r001056_1 * 2 + 455) & 127;
    if (stage_v_150 > 43) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_52 + pub_r001056_10 * 2 + 458) & 127;
    if (stage_v_151 > 59) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001056_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (sec_r001056_7 + pub_r001056_11 * 2 + 464) & 127;
    if (stage_v_153 > 56) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001056_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_121 + pub_r001056_8 * 2 + 470) & 127;
    if (stage_v_155 > 56) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001056_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_24 + pub_r001056_7 * 2 + 476) & 127;
    if (stage_v_157 > 48) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001056_3 + pub_r001056_1 * 2 + 479) & 127;
    if (stage_v_158 > 28) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_0 + pub_r001056_9 * 2 + 482) & 127;
    if (stage_v_159 > 49) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001056_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001056_13 + pub_r001056_0 * 2 + 488) & 127;
    if (stage_v_161 > 16) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001056_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001056_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001056_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001056_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_96 + pub_r001056_18 * 2 + 503) & 127;
    if (stage_v_166 > 28) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001056_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_10 + pub_r001056_5 * 2 + 509) & 127;
    if (stage_v_168 > 39) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_78 + pub_r001056_18 * 2 + 512) & 127;
    if (stage_v_169 > 22) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001056_9 + pub_r001056_14 * 2 + 515) & 127;
    if (stage_v_170 > 27) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001056_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001056_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_151 + pub_r001056_3 * 2 + 524) & 127;
    if (stage_v_173 > 43) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001056_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001056_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_63 + pub_r001056_16 * 2 + 533) & 127;
    if (stage_v_176 > 36) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001056_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_79 + pub_r001056_17 * 2 + 539) & 127;
    if (stage_v_178 > 16) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_51 + pub_r001056_13 * 2 + 542) & 127;
    if (stage_v_179 > 49) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001056_15 + pub_r001056_0 * 2 + 545) & 127;
    if (stage_v_180 > 58) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_20 + pub_r001056_9 * 2 + 548) & 127;
    if (stage_v_181 > 28) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_99 + pub_r001056_4 * 2 + 551) & 127;
    if (stage_v_182 > 30) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001056_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_18 + pub_r001056_12 * 2 + 557) & 127;
    if (stage_v_184 > 42) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001056_14 + pub_r001056_14 * 2 + 560) & 127;
    if (stage_v_185 > 24) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_132 + pub_r001056_12 * 2 + 563) & 127;
    if (stage_v_186 > 55) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_32 + pub_r001056_1 * 2 + 566) & 127;
    if (stage_v_187 > 20) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_142 + pub_r001056_8 * 2 + 569) & 127;
    if (stage_v_188 > 29) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_150 + pub_r001056_4 * 2 + 572) & 127;
    if (stage_v_189 > 60) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_139 + pub_r001056_13 * 2 + 575) & 127;
    if (stage_v_190 > 60) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001056_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001056_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_188 + pub_r001056_11 * 2 + 584) & 127;
    if (stage_v_193 > 34) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001056_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_51 + pub_r001056_1 * 2 + 590) & 127;
    if (stage_v_195 > 44) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001056_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r001056_3 + pub_r001056_10 * 2 + 596) & 127;
    if (stage_v_197 > 30) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_33 + pub_r001056_18 * 2 + 599) & 127;
    if (stage_v_198 > 44) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001056_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001056_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_179 + pub_r001056_2 * 2 + 608) & 127;
    if (stage_v_201 > 45) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001056_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_41 + pub_r001056_11 * 2 + 614) & 127;
    if (stage_v_203 > 21) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001056_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001056_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_47 + pub_r001056_11 * 2 + 623) & 127;
    if (stage_v_206 > 55) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001056_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001056_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001056_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001056_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_17 + pub_r001056_14 * 2 + 638) & 127;
    if (stage_v_211 > 42) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_64 + pub_r001056_13 * 2 + 641) & 127;
    if (stage_v_212 > 48) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001056_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001056_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_153 + pub_r001056_14 * 2 + 650) & 127;
    if (stage_v_215 > 60) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_62 + pub_r001056_10 * 2 + 653) & 127;
    if (stage_v_216 > 46) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001056_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_185 + pub_r001056_14 * 2 + 659) & 127;
    if (stage_v_218 > 17) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_203 + pub_r001056_18 * 2 + 662) & 127;
    if (stage_v_219 > 36) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001056_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_14 + pub_r001056_8 * 2 + 668) & 127;
    if (stage_v_221 > 40) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_215 + pub_r001056_6 * 2 + 671) & 127;
    if (stage_v_222 > 48) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001056_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (helper_flow_0 + pub_r001056_17 * 2 + 677) & 127;
    if (stage_v_224 > 16) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_157 + pub_r001056_15 * 2 + 680) & 127;
    if (stage_v_225 > 40) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_3 + pub_r001056_8 * 2 + 683) & 127;
    if (stage_v_226 > 43) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_153 + pub_r001056_10 * 2 + 686) & 127;
    if (stage_v_227 > 50) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_93 + pub_r001056_5 * 2 + 689) & 127;
    if (stage_v_228 > 51) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_77 + pub_r001056_10 * 2 + 692) & 127;
    if (stage_v_229 > 55) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_218 + pub_r001056_17 * 2 + 695) & 127;
    if (stage_v_230 > 40) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_157 + pub_r001056_17 * 2 + 698) & 127;
    if (stage_v_231 > 15) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001056_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001056_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_93 + pub_r001056_14 * 2 + 707) & 127;
    if (stage_v_234 > 58) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_34 + pub_r001056_12 * 2 + 710) & 127;
    if (stage_v_235 > 51) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_187 + pub_r001056_10 * 2 + 713) & 127;
    if (stage_v_236 > 54) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_35 + pub_r001056_8 * 2 + 716) & 127;
    if (stage_v_237 > 56) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001056_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_179 + pub_r001056_3 * 2 + 722) & 127;
    if (stage_v_239 > 43) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
