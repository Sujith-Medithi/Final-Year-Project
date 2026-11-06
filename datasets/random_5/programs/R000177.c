/*
 * Benchmark Program: R000177
 * Security Family: nested_implicit_flow
 * Generator Seed: 517713
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000177_7713_0 {
    int seq;
    unsigned char signature;
    int code;
    short facility;
    short timestamp;
    int buffer[3];
};

struct Vector3D_R000177_7713_1 {
    int coord_y;
    int norm_sq;
    short coord_z;
    short heading;
    int pitch;
    int buffer[3];
};

union ColorPixel_R000177_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000177_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int delta_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000177_7713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_11 = local_arr[aux % 3];
    acc = (acc + tally_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000177_7713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_87 = (aux + st.buffer[1]) & 3;
    switch (checksum_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_10 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_10 > 17) {
        acc = (acc + damping_10 * 2 + 5) & 127;
        aux ^= (damping_10 & 15);
    } else {
        acc = (acc - damping_10 + 11) & 127;
        aux += 3;
    }
    int factor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000177_7713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int damping_47 = local_arr[aux % 3];
    acc = (acc + damping_47 * 2) & 127;
    int scale_26 = (aux + st.buffer[1]) & 3;
    switch (scale_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_77) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000177_7713_4(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int tracker_11 = local_arr[aux % 3];
    acc = (acc + tracker_11 * 2) & 127;
    int pivot_22 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_22 > 15) {
        acc = (acc + pivot_22 * 2 + 5) & 127;
        aux ^= (pivot_22 & 15);
    } else {
        acc = (acc - pivot_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_5(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int factor_75 = local_arr[aux % 3];
    acc = (acc + factor_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000177_7713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_66 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_66 > 49) {
        acc = (acc + phase_66 * 2 + 5) & 127;
        aux ^= (phase_66 & 15);
    } else {
        acc = (acc - phase_66 + 11) & 127;
        aux += 3;
    }
    int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000177_7713_7(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_80 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_80 > 45) {
        acc = (acc + vector_80 * 2 + 5) & 127;
        aux ^= (vector_80 & 15);
    } else {
        acc = (acc - vector_80 + 11) & 127;
        aux += 3;
    }
    int window_15 = (aux + st.buffer[1]) & 3;
    switch (window_15) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_92 = (aux + st.buffer[1]) & 3;
    switch (bound_92) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_38 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_38 > 40) {
        acc = (acc + margin_38 * 2 + 5) & 127;
        aux ^= (margin_38 & 15);
    } else {
        acc = (acc - margin_38 + 11) & 127;
        aux += 3;
    }
    int mask_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000177_7713_9(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_37 = (aux + st.buffer[1]) & 3;
    switch (quantum_37) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_30 = local_arr[aux % 3];
    acc = (acc + margin_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000177_7713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_16 = (aux + st.buffer[1]) & 3;
    switch (margin_16) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000177_7713_11(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_83) & 63;
    acc ^= aux;
    int quantum_13 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_13 > 50) {
        acc = (acc + quantum_13 * 2 + 5) & 127;
        aux ^= (quantum_13 & 15);
    } else {
        acc = (acc - quantum_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_57 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_57 > 31) {
        acc = (acc + mask_57 * 2 + 5) & 127;
        aux ^= (mask_57 & 15);
    } else {
        acc = (acc - mask_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_35) & 63;
    acc ^= aux;
    int offset_61 = (aux + st.buffer[1]) & 3;
    switch (offset_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_14(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000177_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_37 = (aux + st.buffer[1]) & 3;
    switch (delta_37) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int residue_23 = (aux + st.buffer[1]) & 3;
    switch (residue_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_23 = local_arr[aux % 3];
    acc = (acc + vector_23 * 2) & 127;
    int cursor_83 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_83 > 38) {
        acc = (acc + cursor_83 * 2 + 5) & 127;
        aux ^= (cursor_83 & 15);
    } else {
        acc = (acc - cursor_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000177_7713_16(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int index_reg_21 = local_arr[aux % 3];
    acc = (acc + index_reg_21 * 2) & 127;
    int cursor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000177_7713_17(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000177_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_88 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_88 > 18) {
        acc = (acc + quotient_88 * 2 + 5) & 127;
        aux ^= (quotient_88 & 15);
    } else {
        acc = (acc - quotient_88 + 11) & 127;
        aux += 3;
    }
    int quotient_91 = (aux + st.buffer[1]) & 3;
    switch (quotient_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000177_0;
    int sec_r000177_1;
    int sec_r000177_2;
    int sec_r000177_3;
    int sec_r000177_4;
    int sec_r000177_5;
    int sec_r000177_6;
    int sec_r000177_7;
    int sec_r000177_8;
    int sec_r000177_9;
    int sec_r000177_10;
    int sec_r000177_11;
    int sec_r000177_12;
    int sec_r000177_13;
    int sec_r000177_14;
    int sec_r000177_15;
    int pub_r000177_0;
    int pub_r000177_1;
    int pub_r000177_2;
    int pub_r000177_3;
    int pub_r000177_4;
    int pub_r000177_5;
    int pub_r000177_6;
    int pub_r000177_7;
    int pub_r000177_8;
    int pub_r000177_9;
    int pub_r000177_10;
    int pub_r000177_11;
    int pub_r000177_12;
    int pub_r000177_13;
    int pub_r000177_14;
    int pub_r000177_15;
    int pub_r000177_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000177_0 >= -100 && pub_r000177_0 <= 100);
    __CPROVER_assume(pub_r000177_1 >= -100 && pub_r000177_1 <= 100);
    __CPROVER_assume(pub_r000177_2 >= -100 && pub_r000177_2 <= 100);
    __CPROVER_assume(pub_r000177_3 >= -100 && pub_r000177_3 <= 100);
    __CPROVER_assume(pub_r000177_4 >= -100 && pub_r000177_4 <= 100);
    __CPROVER_assume(pub_r000177_5 >= -100 && pub_r000177_5 <= 100);
    __CPROVER_assume(pub_r000177_6 >= -100 && pub_r000177_6 <= 100);
    __CPROVER_assume(pub_r000177_7 >= -100 && pub_r000177_7 <= 100);
    __CPROVER_assume(pub_r000177_8 >= -100 && pub_r000177_8 <= 100);
    __CPROVER_assume(pub_r000177_9 >= -100 && pub_r000177_9 <= 100);
    __CPROVER_assume(pub_r000177_10 >= -100 && pub_r000177_10 <= 100);
    __CPROVER_assume(pub_r000177_11 >= -100 && pub_r000177_11 <= 100);
    __CPROVER_assume(pub_r000177_12 >= -100 && pub_r000177_12 <= 100);
    __CPROVER_assume(pub_r000177_13 >= -100 && pub_r000177_13 <= 100);
    __CPROVER_assume(pub_r000177_14 >= -100 && pub_r000177_14 <= 100);
    __CPROVER_assume(pub_r000177_15 >= -100 && pub_r000177_15 <= 100);
    __CPROVER_assume(pub_r000177_16 >= -100 && pub_r000177_16 <= 100);
    __CPROVER_assume(sec_r000177_0 >= 0 && sec_r000177_0 <= 255);
    __CPROVER_assume(sec_r000177_1 >= 0 && sec_r000177_1 <= 255);
    __CPROVER_assume(sec_r000177_2 >= 0 && sec_r000177_2 <= 255);
    __CPROVER_assume(sec_r000177_3 >= 0 && sec_r000177_3 <= 255);
    __CPROVER_assume(sec_r000177_4 >= 0 && sec_r000177_4 <= 255);
    __CPROVER_assume(sec_r000177_5 >= 0 && sec_r000177_5 <= 255);
    __CPROVER_assume(sec_r000177_6 >= 0 && sec_r000177_6 <= 255);
    __CPROVER_assume(sec_r000177_7 >= 0 && sec_r000177_7 <= 255);
    __CPROVER_assume(sec_r000177_8 >= 0 && sec_r000177_8 <= 255);
    __CPROVER_assume(sec_r000177_9 >= 0 && sec_r000177_9 <= 255);
    __CPROVER_assume(sec_r000177_10 >= 0 && sec_r000177_10 <= 255);
    __CPROVER_assume(sec_r000177_11 >= 0 && sec_r000177_11 <= 255);
    __CPROVER_assume(sec_r000177_12 >= 0 && sec_r000177_12 <= 255);
    __CPROVER_assume(sec_r000177_13 >= 0 && sec_r000177_13 <= 255);
    __CPROVER_assume(sec_r000177_14 >= 0 && sec_r000177_14 <= 255);
    __CPROVER_assume(sec_r000177_15 >= 0 && sec_r000177_15 <= 255);

    struct EventLog_R000177_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000177_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000177_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000177_0 + 7) & 15;
    struct Vector3D_R000177_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000177_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000177_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000177_0 + 9) & 15;

    union ColorPixel_R000177_7713_0 u_var;
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
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 32) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 47) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 21) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 36) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 34) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 49) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 39) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 54) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 10) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 25) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 20) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 35) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 12) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 27) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 33) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 48) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 19) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 34) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 36) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 51) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
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
    int stage_v_70 = 0;
    if ((sec_r000177_0 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_70 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000177_3 & 1) != 0) {
        if ((sec_r000177_15 & 2) != 0) {
            stage_v_71 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_72 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_73 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_6 & 2) != 0) {
            stage_v_74 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_75 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000177_12 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_76 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000177_5 & 2) != 0) {
            stage_v_77 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000177_1 & 2) != 0) {
            stage_v_78 = (pub_r000177_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000177_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000177_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000177_1 & 1) != 0) {
        if ((sec_r000177_6 & 2) != 0) {
            stage_v_79 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_80 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000177_4 & 1) != 0) {
        if ((sec_r000177_14 & 2) != 0) {
            stage_v_81 = (pub_r000177_2 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000177_2 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000177_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000177_1 & 2) != 0) {
            stage_v_82 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000177_2 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_83 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_84 = (pub_r000177_1 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000177_1 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000177_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_85 = (pub_r000177_6 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000177_6 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000177_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000177_5 & 2) != 0) {
            stage_v_86 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_87 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000177_0 & 1) != 0) {
        if ((sec_r000177_15 & 2) != 0) {
            stage_v_88 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000177_14 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_89 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_90 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_0 & 2) != 0) {
            stage_v_91 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000177_9 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_92 = (pub_r000177_16 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000177_16 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000177_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000177_14 & 2) != 0) {
            stage_v_93 = (pub_r000177_13 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000177_13 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000177_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000177_15 & 2) != 0) {
            stage_v_94 = (pub_r000177_13 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000177_13 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000177_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_95 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000177_13 & 2) != 0) {
            stage_v_96 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000177_13 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_97 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000177_7 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_98 = (pub_r000177_4 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000177_4 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000177_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000177_6 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_99 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_100 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000177_14 & 1) != 0) {
        if ((sec_r000177_10 & 2) != 0) {
            stage_v_101 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_102 = (pub_r000177_2 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000177_2 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000177_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_14 & 2) != 0) {
            stage_v_103 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_104 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_105 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_106 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_107 = (pub_r000177_0 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000177_0 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000177_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000177_5 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_108 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000177_11 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_109 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_10 & 2) != 0) {
            stage_v_110 = (pub_r000177_6 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000177_6 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000177_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000177_7 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_111 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000177_1 & 1) != 0) {
        if ((sec_r000177_5 & 2) != 0) {
            stage_v_112 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_113 = (pub_r000177_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000177_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000177_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_114 = (pub_r000177_0 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000177_0 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000177_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_115 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_116 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_117 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_118 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_119 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000177_7 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_120 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_121 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000177_1 & 2) != 0) {
            stage_v_122 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_123 = (pub_r000177_1 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000177_1 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000177_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_124 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_125 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_126 = (pub_r000177_6 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000177_6 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000177_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_127 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_128 = (pub_r000177_0 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000177_0 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000177_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_129 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000177_15 & 2) != 0) {
            stage_v_130 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000177_4 & 1) != 0) {
        if ((sec_r000177_13 & 2) != 0) {
            stage_v_131 = (pub_r000177_4 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000177_4 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000177_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_132 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000177_3 & 1) != 0) {
        if ((sec_r000177_0 & 2) != 0) {
            stage_v_133 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000177_6 & 2) != 0) {
            stage_v_134 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_135 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000177_1 & 1) != 0) {
        if ((sec_r000177_10 & 2) != 0) {
            stage_v_136 = (pub_r000177_6 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000177_6 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000177_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_137 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000177_15 & 2) != 0) {
            stage_v_138 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_139 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_140 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_141 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000177_9 & 2) != 0) {
            stage_v_142 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_143 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_144 = (pub_r000177_12 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000177_12 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000177_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000177_0 & 2) != 0) {
            stage_v_145 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000177_6 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_146 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000177_9 & 1) != 0) {
        if ((sec_r000177_1 & 2) != 0) {
            stage_v_147 = (pub_r000177_11 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000177_11 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000177_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_148 = (pub_r000177_4 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000177_4 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000177_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000177_6 & 2) != 0) {
            stage_v_149 = (pub_r000177_6 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000177_6 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000177_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_150 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000177_13 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_151 = (pub_r000177_13 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000177_13 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000177_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r000177_1 & 2) != 0) {
            stage_v_152 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_153 = (pub_r000177_9 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000177_9 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000177_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_8 & 2) != 0) {
            stage_v_154 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_155 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000177_1 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_156 = (pub_r000177_5 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000177_5 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000177_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000177_15 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_157 = (pub_r000177_14 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000177_14 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000177_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000177_4 & 2) != 0) {
            stage_v_158 = (pub_r000177_1 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000177_1 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000177_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_159 = (pub_r000177_10 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000177_10 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000177_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000177_12 & 2) != 0) {
            stage_v_160 = (pub_r000177_15 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000177_15 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000177_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000177_13 & 2) != 0) {
            stage_v_161 = (pub_r000177_3 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000177_3 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000177_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000177_2 & 2) != 0) {
            stage_v_162 = (pub_r000177_4 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000177_4 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000177_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000177_7 & 2) != 0) {
            stage_v_163 = (pub_r000177_13 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000177_13 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000177_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000177_12 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_164 = (pub_r000177_0 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000177_0 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000177_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000177_11 & 2) != 0) {
            stage_v_165 = (pub_r000177_7 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000177_7 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000177_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000177_0 & 2) != 0) {
            stage_v_166 = (pub_r000177_2 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000177_2 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000177_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r000177_3 & 2) != 0) {
            stage_v_167 = (pub_r000177_8 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000177_8 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000177_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
