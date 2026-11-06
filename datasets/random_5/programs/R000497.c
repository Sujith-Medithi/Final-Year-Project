/*
 * Benchmark Program: R000497
 * Security Family: nested_implicit_flow
 * Generator Seed: 549713
 * High Inputs: 18 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000497_9713_0 {
    int severity;
    int facility;
    int signature;
    int timestamp;
    unsigned char code;
    int seq;
    int buffer[3];
};

struct Vector3D_R000497_9713_1 {
    unsigned char pitch;
    short coord_y;
    short coord_z;
    int heading;
    int norm_sq;
    int buffer[3];
};

union PacketPayload_R000497_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000497_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_72) & 63;
    acc ^= aux;
    int parity_29 = (aux + st.buffer[1]) & 3;
    switch (parity_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_27 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_27 > 36) {
        acc = (acc + quantum_27 * 2 + 5) & 127;
        aux ^= (quantum_27 & 15);
    } else {
        acc = (acc - quantum_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_83 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_83 > 26) {
        acc = (acc + delta_83 * 2 + 5) & 127;
        aux ^= (delta_83 & 15);
    } else {
        acc = (acc - delta_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_45 = local_arr[aux % 3];
    acc = (acc + delta_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_2(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int pivot_56 = (aux + st.buffer[1]) & 3;
    switch (pivot_56) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_76) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_67 = local_arr[aux % 3];
    acc = (acc + anchor_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_88 = (aux + st.buffer[1]) & 3;
    switch (anchor_88) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_18 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_18 > 45) {
        acc = (acc + quotient_18 * 2 + 5) & 127;
        aux ^= (quotient_18 & 15);
    } else {
        acc = (acc - quotient_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_54 = local_arr[aux % 3];
    acc = (acc + parity_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_58) & 63;
    acc ^= aux;
    int sample_38 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_38 > 33) {
        acc = (acc + sample_38 * 2 + 5) & 127;
        aux ^= (sample_38 & 15);
    } else {
        acc = (acc - sample_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_92 = local_arr[aux % 3];
    acc = (acc + factor_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_6(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_52) & 63;
    acc ^= aux;
    int checksum_77 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_77 > 46) {
        acc = (acc + checksum_77 * 2 + 5) & 127;
        aux ^= (checksum_77 & 15);
    } else {
        acc = (acc - checksum_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_73 = (aux + st.buffer[1]) & 3;
    switch (phase_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_87 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_87 > 24) {
        acc = (acc + phase_87 * 2 + 5) & 127;
        aux ^= (phase_87 & 15);
    } else {
        acc = (acc - phase_87 + 11) & 127;
        aux += 3;
    }
    int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000497_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int index_reg_25 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_25 > 25) {
        acc = (acc + index_reg_25 * 2 + 5) & 127;
        aux ^= (index_reg_25 & 15);
    } else {
        acc = (acc - index_reg_25 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_27 = local_arr[aux % 3];
    acc = (acc + sample_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_71 = local_arr[aux % 3];
    acc = (acc + scale_71 * 2) & 127;
    int index_reg_45 = (aux + st.buffer[1]) & 3;
    switch (index_reg_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_10(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_44) & 63;
    acc ^= aux;
    int residue_98 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_98 > 40) {
        acc = (acc + residue_98 * 2 + 5) & 127;
        aux ^= (residue_98 & 15);
    } else {
        acc = (acc - residue_98 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_89 = (aux + st.buffer[1]) & 3;
    switch (index_reg_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int tally_93 = local_arr[aux % 3];
    acc = (acc + tally_93 * 2) & 127;
    int accumulator_70 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_70 > 33) {
        acc = (acc + accumulator_70 * 2 + 5) & 127;
        aux ^= (accumulator_70 & 15);
    } else {
        acc = (acc - accumulator_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_72 = local_arr[aux % 3];
    acc = (acc + quotient_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_37 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_37 > 28) {
        acc = (acc + phase_37 * 2 + 5) & 127;
        aux ^= (phase_37 & 15);
    } else {
        acc = (acc - phase_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000497_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int phase_62 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_62 > 50) {
        acc = (acc + phase_62 * 2 + 5) & 127;
        aux ^= (phase_62 & 15);
    } else {
        acc = (acc - phase_62 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_14(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_13 = (aux + st.buffer[1]) & 3;
    switch (quantum_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_35 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_35 > 10) {
        acc = (acc + offset_35 * 2 + 5) & 127;
        aux ^= (offset_35 & 15);
    } else {
        acc = (acc - offset_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000497_9713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int cursor_30 = local_arr[aux % 3];
    acc = (acc + cursor_30 * 2) & 127;
    int index_reg_60 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_60 > 19) {
        acc = (acc + index_reg_60 * 2 + 5) & 127;
        aux ^= (index_reg_60 & 15);
    } else {
        acc = (acc - index_reg_60 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_16(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int margin_73 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_73 > 16) {
        acc = (acc + margin_73 * 2 + 5) & 127;
        aux ^= (margin_73 & 15);
    } else {
        acc = (acc - margin_73 + 11) & 127;
        aux += 3;
    }
    int segment_94 = (aux + st.buffer[1]) & 3;
    switch (segment_94) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_52 = local_arr[aux % 3];
    acc = (acc + metric_52 * 2) & 127;
    int threshold_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000497_9713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_92 = local_arr[aux % 3];
    acc = (acc + coefficient_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000497_9713_18(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000497_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_95 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_95 > 31) {
        acc = (acc + damping_95 * 2 + 5) & 127;
        aux ^= (damping_95 & 15);
    } else {
        acc = (acc - damping_95 + 11) & 127;
        aux += 3;
    }
    int checksum_44 = (aux + st.buffer[1]) & 3;
    switch (checksum_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000497_0;
    int sec_r000497_1;
    int sec_r000497_2;
    int sec_r000497_3;
    int sec_r000497_4;
    int sec_r000497_5;
    int sec_r000497_6;
    int sec_r000497_7;
    int sec_r000497_8;
    int sec_r000497_9;
    int sec_r000497_10;
    int sec_r000497_11;
    int sec_r000497_12;
    int sec_r000497_13;
    int sec_r000497_14;
    int sec_r000497_15;
    int sec_r000497_16;
    int sec_r000497_17;
    int pub_r000497_0;
    int pub_r000497_1;
    int pub_r000497_2;
    int pub_r000497_3;
    int pub_r000497_4;
    int pub_r000497_5;
    int pub_r000497_6;
    int pub_r000497_7;
    int pub_r000497_8;
    int pub_r000497_9;
    int pub_r000497_10;
    int pub_r000497_11;
    int pub_r000497_12;
    int pub_r000497_13;
    int pub_r000497_14;
    int pub_r000497_15;
    int pub_r000497_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000497_0 >= -100 && pub_r000497_0 <= 100);
    __CPROVER_assume(pub_r000497_1 >= -100 && pub_r000497_1 <= 100);
    __CPROVER_assume(pub_r000497_2 >= -100 && pub_r000497_2 <= 100);
    __CPROVER_assume(pub_r000497_3 >= -100 && pub_r000497_3 <= 100);
    __CPROVER_assume(pub_r000497_4 >= -100 && pub_r000497_4 <= 100);
    __CPROVER_assume(pub_r000497_5 >= -100 && pub_r000497_5 <= 100);
    __CPROVER_assume(pub_r000497_6 >= -100 && pub_r000497_6 <= 100);
    __CPROVER_assume(pub_r000497_7 >= -100 && pub_r000497_7 <= 100);
    __CPROVER_assume(pub_r000497_8 >= -100 && pub_r000497_8 <= 100);
    __CPROVER_assume(pub_r000497_9 >= -100 && pub_r000497_9 <= 100);
    __CPROVER_assume(pub_r000497_10 >= -100 && pub_r000497_10 <= 100);
    __CPROVER_assume(pub_r000497_11 >= -100 && pub_r000497_11 <= 100);
    __CPROVER_assume(pub_r000497_12 >= -100 && pub_r000497_12 <= 100);
    __CPROVER_assume(pub_r000497_13 >= -100 && pub_r000497_13 <= 100);
    __CPROVER_assume(pub_r000497_14 >= -100 && pub_r000497_14 <= 100);
    __CPROVER_assume(pub_r000497_15 >= -100 && pub_r000497_15 <= 100);
    __CPROVER_assume(pub_r000497_16 >= -100 && pub_r000497_16 <= 100);
    __CPROVER_assume(sec_r000497_0 >= 0 && sec_r000497_0 <= 255);
    __CPROVER_assume(sec_r000497_1 >= 0 && sec_r000497_1 <= 255);
    __CPROVER_assume(sec_r000497_2 >= 0 && sec_r000497_2 <= 255);
    __CPROVER_assume(sec_r000497_3 >= 0 && sec_r000497_3 <= 255);
    __CPROVER_assume(sec_r000497_4 >= 0 && sec_r000497_4 <= 255);
    __CPROVER_assume(sec_r000497_5 >= 0 && sec_r000497_5 <= 255);
    __CPROVER_assume(sec_r000497_6 >= 0 && sec_r000497_6 <= 255);
    __CPROVER_assume(sec_r000497_7 >= 0 && sec_r000497_7 <= 255);
    __CPROVER_assume(sec_r000497_8 >= 0 && sec_r000497_8 <= 255);
    __CPROVER_assume(sec_r000497_9 >= 0 && sec_r000497_9 <= 255);
    __CPROVER_assume(sec_r000497_10 >= 0 && sec_r000497_10 <= 255);
    __CPROVER_assume(sec_r000497_11 >= 0 && sec_r000497_11 <= 255);
    __CPROVER_assume(sec_r000497_12 >= 0 && sec_r000497_12 <= 255);
    __CPROVER_assume(sec_r000497_13 >= 0 && sec_r000497_13 <= 255);
    __CPROVER_assume(sec_r000497_14 >= 0 && sec_r000497_14 <= 255);
    __CPROVER_assume(sec_r000497_15 >= 0 && sec_r000497_15 <= 255);
    __CPROVER_assume(sec_r000497_16 >= 0 && sec_r000497_16 <= 255);
    __CPROVER_assume(sec_r000497_17 >= 0 && sec_r000497_17 <= 255);

    struct EventLog_R000497_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000497_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000497_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000497_0 + 7) & 15;
    struct Vector3D_R000497_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000497_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000497_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000497_0 + 9) & 15;

    union PacketPayload_R000497_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 24) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 39) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 33) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 48) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 31) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 46) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 11) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 26) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 31) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 46) {
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
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 22) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 37) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000497_13 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_38 = (pub_r000497_5 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000497_5 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000497_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000497_3 & 2) != 0) {
            stage_v_39 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000497_16 & 2) != 0) {
            stage_v_40 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000497_3 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_41 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_42 = (pub_r000497_14 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000497_14 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000497_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000497_7 & 2) != 0) {
            stage_v_43 = (pub_r000497_10 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000497_10 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000497_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000497_7 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_44 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000497_13 & 2) != 0) {
            stage_v_45 = (pub_r000497_11 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000497_11 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000497_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000497_16 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_46 = (pub_r000497_10 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000497_10 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000497_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000497_7 & 2) != 0) {
            stage_v_47 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000497_4 & 2) != 0) {
            stage_v_48 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000497_0 & 1) != 0) {
        if ((sec_r000497_11 & 2) != 0) {
            stage_v_49 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_50 = (pub_r000497_9 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000497_9 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000497_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_51 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000497_11 & 1) != 0) {
        if ((sec_r000497_13 & 2) != 0) {
            stage_v_52 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_53 = (pub_r000497_7 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000497_7 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000497_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_54 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000497_10 & 2) != 0) {
            stage_v_55 = (pub_r000497_12 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000497_12 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000497_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000497_1 & 2) != 0) {
            stage_v_56 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_57 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_58 = (pub_r000497_7 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000497_7 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000497_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_59 = (pub_r000497_9 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000497_9 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000497_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_60 = (pub_r000497_11 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000497_11 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000497_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000497_0 & 1) != 0) {
        if ((sec_r000497_3 & 2) != 0) {
            stage_v_61 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000497_2 & 1) != 0) {
        if ((sec_r000497_9 & 2) != 0) {
            stage_v_62 = (pub_r000497_14 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000497_14 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000497_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_63 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000497_3 & 2) != 0) {
            stage_v_64 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_65 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000497_13 & 2) != 0) {
            stage_v_66 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000497_5 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_67 = (pub_r000497_7 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000497_7 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000497_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_68 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000497_12 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_69 = (pub_r000497_16 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000497_16 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000497_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_70 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000497_14 & 1) != 0) {
        if ((sec_r000497_9 & 2) != 0) {
            stage_v_71 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000497_10 & 2) != 0) {
            stage_v_72 = (pub_r000497_10 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000497_10 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000497_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000497_2 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_73 = (pub_r000497_4 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000497_4 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000497_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_74 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_75 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_76 = (pub_r000497_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000497_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000497_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_77 = (pub_r000497_9 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000497_9 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000497_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000497_7 & 2) != 0) {
            stage_v_78 = (pub_r000497_5 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000497_5 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000497_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_79 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000497_9 & 2) != 0) {
            stage_v_80 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_81 = (pub_r000497_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000497_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000497_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_82 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000497_4 & 2) != 0) {
            stage_v_83 = (pub_r000497_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000497_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000497_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_84 = (pub_r000497_12 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000497_12 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000497_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000497_14 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_85 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_86 = (pub_r000497_1 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000497_1 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000497_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_87 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000497_2 & 1) != 0) {
        if ((sec_r000497_16 & 2) != 0) {
            stage_v_88 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000497_15 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_89 = (pub_r000497_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000497_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000497_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000497_12 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_90 = (pub_r000497_4 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000497_4 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000497_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_91 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_92 = (pub_r000497_4 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000497_4 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000497_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000497_8 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_93 = (pub_r000497_3 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000497_3 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000497_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000497_13 & 2) != 0) {
            stage_v_94 = (pub_r000497_9 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000497_9 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000497_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000497_3 & 2) != 0) {
            stage_v_95 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000497_12 & 2) != 0) {
            stage_v_96 = (pub_r000497_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000497_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000497_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000497_12 & 2) != 0) {
            stage_v_97 = (pub_r000497_3 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000497_3 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000497_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000497_7 & 2) != 0) {
            stage_v_98 = (pub_r000497_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000497_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000497_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000497_10 & 1) != 0) {
        if ((sec_r000497_7 & 2) != 0) {
            stage_v_99 = (pub_r000497_3 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000497_3 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000497_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_100 = (pub_r000497_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000497_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000497_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000497_11 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_101 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000497_12 & 1) != 0) {
        if ((sec_r000497_13 & 2) != 0) {
            stage_v_102 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000497_9 & 1) != 0) {
        if ((sec_r000497_12 & 2) != 0) {
            stage_v_103 = (pub_r000497_11 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000497_11 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000497_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000497_4 & 2) != 0) {
            stage_v_104 = (pub_r000497_5 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000497_5 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000497_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_105 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000497_9 & 1) != 0) {
        if ((sec_r000497_8 & 2) != 0) {
            stage_v_106 = (pub_r000497_7 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000497_7 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000497_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000497_16 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_107 = (pub_r000497_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000497_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000497_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_108 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000497_0 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_109 = (pub_r000497_15 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000497_15 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000497_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000497_11 & 1) != 0) {
        if ((sec_r000497_11 & 2) != 0) {
            stage_v_110 = (pub_r000497_2 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000497_2 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000497_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000497_11 & 2) != 0) {
            stage_v_111 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000497_16 & 2) != 0) {
            stage_v_112 = (pub_r000497_11 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000497_11 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000497_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_113 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_114 = (pub_r000497_7 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000497_7 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000497_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_115 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000497_17 & 1) != 0) {
        if ((sec_r000497_9 & 2) != 0) {
            stage_v_116 = (pub_r000497_14 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000497_14 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000497_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000497_17 & 2) != 0) {
            stage_v_117 = (pub_r000497_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000497_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000497_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_118 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000497_12 & 1) != 0) {
        if ((sec_r000497_15 & 2) != 0) {
            stage_v_119 = (pub_r000497_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000497_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000497_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000497_9 & 1) != 0) {
        if ((sec_r000497_2 & 2) != 0) {
            stage_v_120 = (pub_r000497_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000497_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000497_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000497_0 & 2) != 0) {
            stage_v_121 = (pub_r000497_2 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000497_2 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000497_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000497_16 & 2) != 0) {
            stage_v_122 = (pub_r000497_9 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000497_9 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000497_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000497_10 & 2) != 0) {
            stage_v_123 = (pub_r000497_1 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000497_1 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000497_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000497_4 & 1) != 0) {
        if ((sec_r000497_6 & 2) != 0) {
            stage_v_124 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000497_14 & 2) != 0) {
            stage_v_125 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000497_5 & 2) != 0) {
            stage_v_126 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000497_16 & 2) != 0) {
            stage_v_127 = (pub_r000497_13 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000497_13 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000497_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000497_4 & 2) != 0) {
            stage_v_128 = (pub_r000497_0 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000497_0 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000497_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
