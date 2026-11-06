/*
 * Benchmark Program: R000170
 * Security Family: mixed_control_data
 * Generator Seed: 517013
 * High Inputs: 17 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000170_7013_0 {
    int capacity;
    unsigned char tail;
    int checksum;
    int buffer[3];
};

struct MatrixBlock_R000170_7013_1 {
    int density;
    short dim;
    int stride;
    int scale;
    unsigned char trace;
    int buffer[3];
};

struct Vector3D_R000170_7013_2 {
    unsigned char coord_y;
    int heading;
    int pitch;
    int buffer[3];
};

struct AudioFrame_R000170_7013_3 {
    unsigned char gain;
    short channels;
    int sample_rate;
    int envelope;
    int buffer[3];
};

union RegisterBank_R000170_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000170_7013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int scale_76 = local_arr[aux % 3];
    acc = (acc + scale_76 * 2) & 127;
    int coefficient_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_41) & 63;
    acc ^= aux;
    int stride_31 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_31 > 28) {
        acc = (acc + stride_31 * 2 + 5) & 127;
        aux ^= (stride_31 & 15);
    } else {
        acc = (acc - stride_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int anchor_33 = local_arr[aux % 3];
    acc = (acc + anchor_33 * 2) & 127;
    int tracker_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_96) & 63;
    acc ^= aux;
    int quotient_13 = (aux + st.buffer[1]) & 3;
    switch (quotient_13) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_2(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int cursor_39 = local_arr[aux % 3];
    acc = (acc + cursor_39 * 2) & 127;
    int phase_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_86) & 63;
    acc ^= aux;
    int pivot_77 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_77 > 50) {
        acc = (acc + pivot_77 * 2 + 5) & 127;
        aux ^= (pivot_77 & 15);
    } else {
        acc = (acc - pivot_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_3(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_28 = (aux + st.buffer[1]) & 3;
    switch (factor_28) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_20) & 63;
    acc ^= aux;
    int quantum_62 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_62 > 42) {
        acc = (acc + quantum_62 * 2 + 5) & 127;
        aux ^= (quantum_62 & 15);
    } else {
        acc = (acc - quantum_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_24 = (aux + st.buffer[1]) & 3;
    switch (tally_24) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_5(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_66 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_66 > 12) {
        acc = (acc + threshold_66 * 2 + 5) & 127;
        aux ^= (threshold_66 & 15);
    } else {
        acc = (acc - threshold_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_80 = local_arr[aux % 3];
    acc = (acc + stride_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000170_7013_6(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int coefficient_11 = local_arr[aux % 3];
    acc = (acc + coefficient_11 * 2) & 127;
    int residue_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_80 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_80 > 33) {
        acc = (acc + weight_80 * 2 + 5) & 127;
        aux ^= (weight_80 & 15);
    } else {
        acc = (acc - weight_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int phase_12 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_12 > 22) {
        acc = (acc + phase_12 * 2 + 5) & 127;
        aux ^= (phase_12 & 15);
    } else {
        acc = (acc - phase_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_29 = local_arr[aux % 3];
    acc = (acc + delta_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000170_7013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_34) & 63;
    acc ^= aux;
    int weight_38 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_38 > 10) {
        acc = (acc + weight_38 * 2 + 5) & 127;
        aux ^= (weight_38 & 15);
    } else {
        acc = (acc - weight_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000170_7013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_26 = local_arr[aux % 3];
    acc = (acc + window_26 * 2) & 127;
    int offset_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int weight_58 = (aux + st.buffer[1]) & 3;
    switch (weight_58) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_90 = local_arr[aux % 3];
    acc = (acc + tally_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000170_7013_12(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int coefficient_48 = local_arr[aux % 3];
    acc = (acc + coefficient_48 * 2) & 127;
    int mask_49 = (aux + st.buffer[1]) & 3;
    switch (mask_49) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_13 = (aux + st.buffer[1]) & 3;
    switch (scale_13) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_63 = local_arr[aux % 3];
    acc = (acc + vector_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000170_7013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_87 = (aux + st.buffer[1]) & 3;
    switch (delta_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_35) & 63;
    acc ^= aux;
    int checksum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_38 > 50) {
        acc = (acc + checksum_38 * 2 + 5) & 127;
        aux ^= (checksum_38 & 15);
    } else {
        acc = (acc - checksum_38 + 11) & 127;
        aux += 3;
    }
    int scale_38 = (aux + st.buffer[1]) & 3;
    switch (scale_38) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_14 = local_arr[aux % 3];
    acc = (acc + checksum_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000170_7013_16(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int residue_13 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_13 > 32) {
        acc = (acc + residue_13 * 2 + 5) & 127;
        aux ^= (residue_13 & 15);
    } else {
        acc = (acc - residue_13 + 11) & 127;
        aux += 3;
    }
    int residue_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000170_7013_17(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int tracker_23 = local_arr[aux % 3];
    acc = (acc + tracker_23 * 2) & 127;
    int metric_24 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_24 > 26) {
        acc = (acc + metric_24 * 2 + 5) & 127;
        aux ^= (metric_24 & 15);
    } else {
        acc = (acc - metric_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000170_0;
    int sec_r000170_1;
    int sec_r000170_2;
    int sec_r000170_3;
    int sec_r000170_4;
    int sec_r000170_5;
    int sec_r000170_6;
    int sec_r000170_7;
    int sec_r000170_8;
    int sec_r000170_9;
    int sec_r000170_10;
    int sec_r000170_11;
    int sec_r000170_12;
    int sec_r000170_13;
    int sec_r000170_14;
    int sec_r000170_15;
    int sec_r000170_16;
    int pub_r000170_0;
    int pub_r000170_1;
    int pub_r000170_2;
    int pub_r000170_3;
    int pub_r000170_4;
    int pub_r000170_5;
    int pub_r000170_6;
    int pub_r000170_7;
    int pub_r000170_8;
    int pub_r000170_9;
    int pub_r000170_10;
    int pub_r000170_11;
    int pub_r000170_12;
    int pub_r000170_13;
    int pub_r000170_14;
    int pub_r000170_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000170_0 >= -100 && pub_r000170_0 <= 100);
    __CPROVER_assume(pub_r000170_1 >= -100 && pub_r000170_1 <= 100);
    __CPROVER_assume(pub_r000170_2 >= -100 && pub_r000170_2 <= 100);
    __CPROVER_assume(pub_r000170_3 >= -100 && pub_r000170_3 <= 100);
    __CPROVER_assume(pub_r000170_4 >= -100 && pub_r000170_4 <= 100);
    __CPROVER_assume(pub_r000170_5 >= -100 && pub_r000170_5 <= 100);
    __CPROVER_assume(pub_r000170_6 >= -100 && pub_r000170_6 <= 100);
    __CPROVER_assume(pub_r000170_7 >= -100 && pub_r000170_7 <= 100);
    __CPROVER_assume(pub_r000170_8 >= -100 && pub_r000170_8 <= 100);
    __CPROVER_assume(pub_r000170_9 >= -100 && pub_r000170_9 <= 100);
    __CPROVER_assume(pub_r000170_10 >= -100 && pub_r000170_10 <= 100);
    __CPROVER_assume(pub_r000170_11 >= -100 && pub_r000170_11 <= 100);
    __CPROVER_assume(pub_r000170_12 >= -100 && pub_r000170_12 <= 100);
    __CPROVER_assume(pub_r000170_13 >= -100 && pub_r000170_13 <= 100);
    __CPROVER_assume(pub_r000170_14 >= -100 && pub_r000170_14 <= 100);
    __CPROVER_assume(pub_r000170_15 >= -100 && pub_r000170_15 <= 100);
    __CPROVER_assume(sec_r000170_0 >= 0 && sec_r000170_0 <= 255);
    __CPROVER_assume(sec_r000170_1 >= 0 && sec_r000170_1 <= 255);
    __CPROVER_assume(sec_r000170_2 >= 0 && sec_r000170_2 <= 255);
    __CPROVER_assume(sec_r000170_3 >= 0 && sec_r000170_3 <= 255);
    __CPROVER_assume(sec_r000170_4 >= 0 && sec_r000170_4 <= 255);
    __CPROVER_assume(sec_r000170_5 >= 0 && sec_r000170_5 <= 255);
    __CPROVER_assume(sec_r000170_6 >= 0 && sec_r000170_6 <= 255);
    __CPROVER_assume(sec_r000170_7 >= 0 && sec_r000170_7 <= 255);
    __CPROVER_assume(sec_r000170_8 >= 0 && sec_r000170_8 <= 255);
    __CPROVER_assume(sec_r000170_9 >= 0 && sec_r000170_9 <= 255);
    __CPROVER_assume(sec_r000170_10 >= 0 && sec_r000170_10 <= 255);
    __CPROVER_assume(sec_r000170_11 >= 0 && sec_r000170_11 <= 255);
    __CPROVER_assume(sec_r000170_12 >= 0 && sec_r000170_12 <= 255);
    __CPROVER_assume(sec_r000170_13 >= 0 && sec_r000170_13 <= 255);
    __CPROVER_assume(sec_r000170_14 >= 0 && sec_r000170_14 <= 255);
    __CPROVER_assume(sec_r000170_15 >= 0 && sec_r000170_15 <= 255);
    __CPROVER_assume(sec_r000170_16 >= 0 && sec_r000170_16 <= 255);

    struct StreamBuffer_R000170_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000170_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000170_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000170_0 + 7) & 15;
    struct MatrixBlock_R000170_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000170_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000170_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000170_0 + 9) & 15;
    struct Vector3D_R000170_7013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000170_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000170_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000170_0 + 11) & 15;
    struct AudioFrame_R000170_7013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000170_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000170_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000170_0 + 13) & 15;

    union RegisterBank_R000170_7013_0 u_var;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 12) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 27) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 35) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 50) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 12) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 27) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 19) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 34) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 26) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 41) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
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
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

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
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r000170_16 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_28 > 41) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_28 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_29 > 40) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r000170_12 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_30 > 36) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r000170_12 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_31 > 23) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_29 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_32 > 48) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_32 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_33 > 39) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_32 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_34 > 46) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r000170_4 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_35 > 38) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_36 > 28) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_35 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_37 > 23) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_38 > 41) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_39 > 20) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_38 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_40 > 42) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_31 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_41 > 25) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_32 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_42 > 26) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_43 > 38) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_42 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_44 > 25) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000170_16 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_45 > 30) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_31 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_46 > 49) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_33 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_47 > 23) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_32 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_48 > 43) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000170_14 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_49 > 30) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_50 > 44) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_48 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_51 > 35) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_28 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_52 > 37) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_48 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_53 > 36) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_54 > 27) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_32 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_55 > 48) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_28 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_56 > 36) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_28 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_57 > 50) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_53 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_58 > 45) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_29 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_59 > 33) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_58 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_60 > 43) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000170_14 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_61 > 23) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_61 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_62 > 32) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_63 > 36) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000170_9 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_64 > 24) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_56 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_65 > 40) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_66 > 36) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_67 > 29) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_43 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_68 > 43) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_39 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_31 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_70 > 45) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_71 > 37) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_72 > 31) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r000170_5 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_73 > 48) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_71 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_74 > 21) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_43 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_75 > 32) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_64 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_76 > 49) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_77 > 42) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_55 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_78 > 31) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_63 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_79 > 22) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_35 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_80 > 28) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_61 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_81 > 25) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000170_2 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_82 > 34) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r000170_8 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_83 > 46) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_72 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_84 > 20) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_52 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_85 > 41) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r000170_16 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_86 > 30) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_68 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_87 > 28) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_46 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_88 > 21) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_72 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_89 > 21) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_78 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_90 > 50) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_62 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_91 > 50) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_78 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_92 > 34) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000170_8 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_93 > 35) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_66 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_94 > 49) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_66 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_41 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_96 > 35) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_79 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_97 > 28) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_98 > 31) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000170_6 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_99 > 48) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_64 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_100 > 44) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_92 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_101 > 34) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_89 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_102 > 31) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_103 > 42) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_104 > 26) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_100 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_105 > 42) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_55 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_106 > 31) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_74 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_107 > 42) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_105 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_108 > 37) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_106 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_109 > 47) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_64 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_110 > 22) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_111 > 43) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_39 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_68 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_113 > 39) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_65 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_114 > 27) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_74 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_115 > 37) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_94 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_116 > 28) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r000170_12 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_117 > 47) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_118 > 44) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_101 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_119 > 34) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_54 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_120 > 30) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_116 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_121 > 43) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000170_7 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_122 > 35) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_82 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_123 > 38) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_65 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_124 > 36) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_89 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_125 > 37) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_126 > 49) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_84 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_127 > 24) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_67 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_128 > 29) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_115 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_129 > 41) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_68 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_130 > 30) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_131 > 23) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_36 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_132 > 29) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_112 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_133 > 23) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_42 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_134 > 49) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000170_2 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_135 > 35) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_43 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_136 > 43) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_41 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_137 > 25) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_121 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_138 > 29) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_79 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_139 > 43) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_38 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_140 > 33) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_46 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_136 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_142 > 30) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_143 > 28) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_90 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_144 > 33) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_59 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_145 > 33) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_145 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_146 > 39) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_30 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_147 > 40) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_143 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_148 > 22) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_149 > 37) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_104 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_150 > 41) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_75 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_151 > 29) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000170_12 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_152 > 35) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_94 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_153 > 34) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000170_12 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_154 > 32) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_32 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_155 > 25) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000170_16 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_156 > 44) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_157 > 39) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_158 > 45) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_91 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_159 > 23) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_154 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_160 > 41) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_57 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_161 > 45) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_89 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_162 > 38) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_56 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_163 > 38) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_95 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_164 > 22) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_157 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_165 > 46) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_53 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_166 > 50) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_167 > 42) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_161 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_168 > 32) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_99 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_169 > 35) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r000170_6 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_170 > 42) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_171 > 26) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_84 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_172 > 45) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_35 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_173 > 20) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_155 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_174 > 29) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000170_11 ^ 0x2A) + pub_r000170_9) & 127;
    if (stage_v_175 > 45) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r000170_5 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_176 > 24) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_98 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_177 > 20) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000170_4 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_178 > 29) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_49 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_179 > 34) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_179 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_139 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_182 > 40) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000170_9 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_183 > 21) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_125 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_184 > 44) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r000170_8 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_185 > 40) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_182 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_186 > 50) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_80 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_187 > 30) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_67 ^ 0x2A) + pub_r000170_12) & 127;
    if (stage_v_188 > 30) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_99 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_189 > 50) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000170_13 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_190 > 39) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_72 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_191 > 25) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_192 > 37) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_193 > 30) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_194 > 22) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_101 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_195 > 49) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000170_0 ^ 0x2A) + pub_r000170_7) & 127;
    if (stage_v_196 > 48) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000170_16 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_197 > 29) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_54 ^ 0x2A) + pub_r000170_14) & 127;
    if (stage_v_198 > 46) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_106 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_199 > 48) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_161 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_200 > 35) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r000170_1 ^ 0x2A) + pub_r000170_1) & 127;
    if (stage_v_201 > 39) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000170_4 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_202 > 46) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_203 > 26) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_200 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_204 > 45) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_47 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_205 > 29) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_192 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_206 > 50) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r000170_4 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_207 > 47) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r000170_14 ^ 0x2A) + pub_r000170_15) & 127;
    if (stage_v_208 > 49) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_180 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_209 > 22) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r000170_9 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_210 > 41) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_29 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_211 > 40) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000170_5 ^ 0x2A) + pub_r000170_13) & 127;
    if (stage_v_212 > 28) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_130 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_213 > 23) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_38 ^ 0x2A) + pub_r000170_5) & 127;
    if (stage_v_214 > 46) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000170_15 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_215 > 49) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r000170_8 ^ 0x2A) + pub_r000170_4) & 127;
    if (stage_v_216 > 46) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_217 > 27) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_68 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_218 > 28) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r000170_10 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_219 > 34) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_58 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_220 > 25) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_218 ^ 0x2A) + pub_r000170_3) & 127;
    if (stage_v_221 > 28) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_31 ^ 0x2A) + pub_r000170_10) & 127;
    if (stage_v_222 > 22) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r000170_3 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_223 > 40) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_155 ^ 0x2A) + pub_r000170_11) & 127;
    if (stage_v_224 > 42) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_212 ^ 0x2A) + pub_r000170_0) & 127;
    if (stage_v_225 > 48) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r000170_14 ^ 0x2A) + pub_r000170_6) & 127;
    if (stage_v_226 > 31) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000170_6 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_227 > 49) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_213 ^ 0x2A) + pub_r000170_8) & 127;
    if (stage_v_228 > 41) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_204 ^ 0x2A) + pub_r000170_2) & 127;
    if (stage_v_229 > 35) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
