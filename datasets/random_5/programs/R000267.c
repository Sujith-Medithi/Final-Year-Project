/*
 * Benchmark Program: R000267
 * Security Family: nested_implicit_flow
 * Generator Seed: 526713
 * High Inputs: 23 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000267_6713_0 {
    int code;
    unsigned char severity;
    unsigned char signature;
    int buffer[3];
};

struct MatrixBlock_R000267_6713_1 {
    int trace;
    int density;
    int scale;
    int stride;
    int buffer[3];
};

union PacketPayload_R000267_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000267_6713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000267_6713_0(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int damping_62 = (aux + st.buffer[1]) & 3;
    switch (damping_62) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_62 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_62 > 21) {
        acc = (acc + delta_62 * 2 + 5) & 127;
        aux ^= (delta_62 & 15);
    } else {
        acc = (acc - delta_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000267_6713_1(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int phase_56 = local_arr[aux % 3];
    acc = (acc + phase_56 * 2) & 127;
    int delta_64 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_64 > 46) {
        acc = (acc + delta_64 * 2 + 5) & 127;
        aux ^= (delta_64 & 15);
    } else {
        acc = (acc - delta_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000267_6713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_3(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_57 = local_arr[aux % 3];
    acc = (acc + threshold_57 * 2) & 127;
    int vector_38 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_38 > 12) {
        acc = (acc + vector_38 * 2 + 5) & 127;
        aux ^= (vector_38 & 15);
    } else {
        acc = (acc - vector_38 + 11) & 127;
        aux += 3;
    }
    int phase_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000267_6713_4(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_45) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_54 = (aux + st.buffer[1]) & 3;
    switch (parity_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_81 = local_arr[aux % 3];
    acc = (acc + sample_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_44 = (aux + st.buffer[1]) & 3;
    switch (factor_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_67 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_67 > 21) {
        acc = (acc + bound_67 * 2 + 5) & 127;
        aux ^= (bound_67 & 15);
    } else {
        acc = (acc - bound_67 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_90 = local_arr[aux % 3];
    acc = (acc + sample_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_6(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_33 = (aux + st.buffer[1]) & 3;
    switch (accumulator_33) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000267_6713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_23 = local_arr[aux % 3];
    acc = (acc + margin_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_53 = local_arr[aux % 3];
    acc = (acc + parity_53 * 2) & 127;
    int delta_92 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_92 > 50) {
        acc = (acc + delta_92 * 2 + 5) & 127;
        aux ^= (delta_92 & 15);
    } else {
        acc = (acc - delta_92 + 11) & 127;
        aux += 3;
    }
    int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000267_6713_9(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_43 = (aux + st.buffer[1]) & 3;
    switch (vector_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_52 = local_arr[aux % 3];
    acc = (acc + parity_52 * 2) & 127;
    int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000267_6713_10(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_71 = local_arr[aux % 3];
    acc = (acc + bound_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_40) & 63;
    acc ^= aux;
    int threshold_13 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_13 > 46) {
        acc = (acc + threshold_13 * 2 + 5) & 127;
        aux ^= (threshold_13 & 15);
    } else {
        acc = (acc - threshold_13 + 11) & 127;
        aux += 3;
    }
    int bound_84 = (aux + st.buffer[1]) & 3;
    switch (bound_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000267_6713_12(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_26 = (aux + st.buffer[1]) & 3;
    switch (pivot_26) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_50 = local_arr[aux % 3];
    acc = (acc + pivot_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_13(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_48 = (aux + st.buffer[1]) & 3;
    switch (quantum_48) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_19 = local_arr[aux % 3];
    acc = (acc + offset_19 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_19 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_19 > 26) {
        acc = (acc + bound_19 * 2 + 5) & 127;
        aux ^= (bound_19 & 15);
    } else {
        acc = (acc - bound_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000267_6713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int factor_76 = local_arr[aux % 3];
    acc = (acc + factor_76 * 2) & 127;
    int damping_99 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_99 > 11) {
        acc = (acc + damping_99 * 2 + 5) & 127;
        aux ^= (damping_99 & 15);
    } else {
        acc = (acc - damping_99 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000267_6713_15(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int window_12 = local_arr[aux % 3];
    acc = (acc + window_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_16(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tracker_95 = local_arr[aux % 3];
    acc = (acc + tracker_95 * 2) & 127;
    int window_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_56) & 63;
    acc ^= aux;
    int quantum_61 = (aux + st.buffer[1]) & 3;
    switch (quantum_61) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_17(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000267_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_34 = local_arr[aux % 3];
    acc = (acc + coefficient_34 * 2) & 127;
    int delta_91 = (aux + st.buffer[1]) & 3;
    switch (delta_91) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000267_6713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000267_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_73 = local_arr[aux % 3];
    acc = (acc + damping_73 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000267_0;
    int sec_r000267_1;
    int sec_r000267_2;
    int sec_r000267_3;
    int sec_r000267_4;
    int sec_r000267_5;
    int sec_r000267_6;
    int sec_r000267_7;
    int sec_r000267_8;
    int sec_r000267_9;
    int sec_r000267_10;
    int sec_r000267_11;
    int sec_r000267_12;
    int sec_r000267_13;
    int sec_r000267_14;
    int sec_r000267_15;
    int sec_r000267_16;
    int sec_r000267_17;
    int sec_r000267_18;
    int sec_r000267_19;
    int sec_r000267_20;
    int sec_r000267_21;
    int sec_r000267_22;
    int pub_r000267_0;
    int pub_r000267_1;
    int pub_r000267_2;
    int pub_r000267_3;
    int pub_r000267_4;
    int pub_r000267_5;
    int pub_r000267_6;
    int pub_r000267_7;
    int pub_r000267_8;
    int pub_r000267_9;
    int pub_r000267_10;
    int pub_r000267_11;
    int pub_r000267_12;
    int pub_r000267_13;
    int pub_r000267_14;
    int pub_r000267_15;
    int pub_r000267_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000267_0 >= -100 && pub_r000267_0 <= 100);
    __CPROVER_assume(pub_r000267_1 >= -100 && pub_r000267_1 <= 100);
    __CPROVER_assume(pub_r000267_2 >= -100 && pub_r000267_2 <= 100);
    __CPROVER_assume(pub_r000267_3 >= -100 && pub_r000267_3 <= 100);
    __CPROVER_assume(pub_r000267_4 >= -100 && pub_r000267_4 <= 100);
    __CPROVER_assume(pub_r000267_5 >= -100 && pub_r000267_5 <= 100);
    __CPROVER_assume(pub_r000267_6 >= -100 && pub_r000267_6 <= 100);
    __CPROVER_assume(pub_r000267_7 >= -100 && pub_r000267_7 <= 100);
    __CPROVER_assume(pub_r000267_8 >= -100 && pub_r000267_8 <= 100);
    __CPROVER_assume(pub_r000267_9 >= -100 && pub_r000267_9 <= 100);
    __CPROVER_assume(pub_r000267_10 >= -100 && pub_r000267_10 <= 100);
    __CPROVER_assume(pub_r000267_11 >= -100 && pub_r000267_11 <= 100);
    __CPROVER_assume(pub_r000267_12 >= -100 && pub_r000267_12 <= 100);
    __CPROVER_assume(pub_r000267_13 >= -100 && pub_r000267_13 <= 100);
    __CPROVER_assume(pub_r000267_14 >= -100 && pub_r000267_14 <= 100);
    __CPROVER_assume(pub_r000267_15 >= -100 && pub_r000267_15 <= 100);
    __CPROVER_assume(pub_r000267_16 >= -100 && pub_r000267_16 <= 100);
    __CPROVER_assume(sec_r000267_0 >= 0 && sec_r000267_0 <= 255);
    __CPROVER_assume(sec_r000267_1 >= 0 && sec_r000267_1 <= 255);
    __CPROVER_assume(sec_r000267_2 >= 0 && sec_r000267_2 <= 255);
    __CPROVER_assume(sec_r000267_3 >= 0 && sec_r000267_3 <= 255);
    __CPROVER_assume(sec_r000267_4 >= 0 && sec_r000267_4 <= 255);
    __CPROVER_assume(sec_r000267_5 >= 0 && sec_r000267_5 <= 255);
    __CPROVER_assume(sec_r000267_6 >= 0 && sec_r000267_6 <= 255);
    __CPROVER_assume(sec_r000267_7 >= 0 && sec_r000267_7 <= 255);
    __CPROVER_assume(sec_r000267_8 >= 0 && sec_r000267_8 <= 255);
    __CPROVER_assume(sec_r000267_9 >= 0 && sec_r000267_9 <= 255);
    __CPROVER_assume(sec_r000267_10 >= 0 && sec_r000267_10 <= 255);
    __CPROVER_assume(sec_r000267_11 >= 0 && sec_r000267_11 <= 255);
    __CPROVER_assume(sec_r000267_12 >= 0 && sec_r000267_12 <= 255);
    __CPROVER_assume(sec_r000267_13 >= 0 && sec_r000267_13 <= 255);
    __CPROVER_assume(sec_r000267_14 >= 0 && sec_r000267_14 <= 255);
    __CPROVER_assume(sec_r000267_15 >= 0 && sec_r000267_15 <= 255);
    __CPROVER_assume(sec_r000267_16 >= 0 && sec_r000267_16 <= 255);
    __CPROVER_assume(sec_r000267_17 >= 0 && sec_r000267_17 <= 255);
    __CPROVER_assume(sec_r000267_18 >= 0 && sec_r000267_18 <= 255);
    __CPROVER_assume(sec_r000267_19 >= 0 && sec_r000267_19 <= 255);
    __CPROVER_assume(sec_r000267_20 >= 0 && sec_r000267_20 <= 255);
    __CPROVER_assume(sec_r000267_21 >= 0 && sec_r000267_21 <= 255);
    __CPROVER_assume(sec_r000267_22 >= 0 && sec_r000267_22 <= 255);

    struct EventLog_R000267_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000267_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000267_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000267_0 + 7) & 15;
    struct MatrixBlock_R000267_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000267_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000267_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000267_0 + 9) & 15;

    union PacketPayload_R000267_6713_0 u_var;
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
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 18) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 33) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 17) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 32) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 12) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 27) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 22) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 37) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 40) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 55) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 40) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 55) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 30) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 45) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 20) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 35) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 16) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 31) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 30) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 45) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 39) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 54) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

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
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 21) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 36) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 28) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 43) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 10) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 25) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] ^ 78) & 3;
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
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000267_14 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_83 = (pub_r000267_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000267_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000267_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000267_18 & 2) != 0) {
            stage_v_84 = (pub_r000267_8 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000267_8 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000267_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000267_14 & 1) != 0) {
        if ((sec_r000267_10 & 2) != 0) {
            stage_v_85 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000267_14 & 2) != 0) {
            stage_v_86 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000267_22 & 2) != 0) {
            stage_v_87 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000267_13 & 2) != 0) {
            stage_v_88 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000267_2 & 1) != 0) {
        if ((sec_r000267_18 & 2) != 0) {
            stage_v_89 = (pub_r000267_6 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000267_6 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000267_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000267_20 & 2) != 0) {
            stage_v_90 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000267_11 & 1) != 0) {
        if ((sec_r000267_9 & 2) != 0) {
            stage_v_91 = (pub_r000267_11 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000267_11 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000267_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_92 = (pub_r000267_11 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000267_11 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000267_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000267_7 & 2) != 0) {
            stage_v_93 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000267_9 & 2) != 0) {
            stage_v_94 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000267_15 & 1) != 0) {
        if ((sec_r000267_21 & 2) != 0) {
            stage_v_95 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000267_9 & 2) != 0) {
            stage_v_96 = (pub_r000267_16 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000267_16 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000267_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000267_7 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_97 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_98 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000267_12 & 2) != 0) {
            stage_v_99 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000267_16 & 2) != 0) {
            stage_v_100 = (pub_r000267_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000267_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000267_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000267_3 & 1) != 0) {
        if ((sec_r000267_9 & 2) != 0) {
            stage_v_101 = (pub_r000267_14 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000267_14 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000267_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000267_10 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_102 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000267_6 & 2) != 0) {
            stage_v_103 = (pub_r000267_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000267_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000267_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000267_7 & 1) != 0) {
        if ((sec_r000267_7 & 2) != 0) {
            stage_v_104 = (pub_r000267_3 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000267_3 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000267_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000267_12 & 1) != 0) {
        if ((sec_r000267_6 & 2) != 0) {
            stage_v_105 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_106 = (pub_r000267_3 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000267_3 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000267_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000267_12 & 2) != 0) {
            stage_v_107 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_108 = (pub_r000267_9 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000267_9 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000267_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000267_5 & 2) != 0) {
            stage_v_109 = (pub_r000267_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000267_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000267_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000267_12 & 2) != 0) {
            stage_v_110 = (pub_r000267_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000267_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000267_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000267_14 & 2) != 0) {
            stage_v_111 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000267_21 & 1) != 0) {
        if ((sec_r000267_5 & 2) != 0) {
            stage_v_112 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000267_22 & 2) != 0) {
            stage_v_113 = (pub_r000267_16 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000267_16 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000267_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000267_16 & 2) != 0) {
            stage_v_114 = (pub_r000267_11 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000267_11 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000267_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_115 = (pub_r000267_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000267_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000267_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000267_17 & 1) != 0) {
        if ((sec_r000267_22 & 2) != 0) {
            stage_v_116 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000267_14 & 2) != 0) {
            stage_v_117 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000267_13 & 2) != 0) {
            stage_v_118 = (pub_r000267_3 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000267_3 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000267_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000267_22 & 2) != 0) {
            stage_v_119 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000267_5 & 1) != 0) {
        if ((sec_r000267_12 & 2) != 0) {
            stage_v_120 = (pub_r000267_16 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000267_16 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000267_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000267_18 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_121 = (pub_r000267_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000267_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000267_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000267_19 & 1) != 0) {
        if ((sec_r000267_0 & 2) != 0) {
            stage_v_122 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_123 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_124 = (pub_r000267_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000267_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000267_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000267_11 & 2) != 0) {
            stage_v_125 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000267_18 & 2) != 0) {
            stage_v_126 = (pub_r000267_13 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000267_13 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000267_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000267_11 & 2) != 0) {
            stage_v_127 = (pub_r000267_0 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000267_0 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000267_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000267_14 & 2) != 0) {
            stage_v_128 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000267_3 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_129 = (pub_r000267_5 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000267_5 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000267_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000267_19 & 2) != 0) {
            stage_v_130 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000267_9 & 2) != 0) {
            stage_v_131 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000267_22 & 1) != 0) {
        if ((sec_r000267_19 & 2) != 0) {
            stage_v_132 = (pub_r000267_13 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000267_13 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000267_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000267_16 & 2) != 0) {
            stage_v_133 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000267_18 & 2) != 0) {
            stage_v_134 = (pub_r000267_10 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000267_10 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000267_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000267_7 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_135 = (pub_r000267_9 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000267_9 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000267_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000267_13 & 1) != 0) {
        if ((sec_r000267_13 & 2) != 0) {
            stage_v_136 = (pub_r000267_1 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000267_1 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000267_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000267_8 & 2) != 0) {
            stage_v_137 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000267_4 & 2) != 0) {
            stage_v_138 = (pub_r000267_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000267_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000267_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000267_6 & 2) != 0) {
            stage_v_139 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_140 = (pub_r000267_2 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000267_2 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000267_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_141 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000267_2 & 1) != 0) {
        if ((sec_r000267_1 & 2) != 0) {
            stage_v_142 = (pub_r000267_13 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000267_13 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000267_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000267_21 & 1) != 0) {
        if ((sec_r000267_20 & 2) != 0) {
            stage_v_143 = (pub_r000267_5 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000267_5 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000267_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000267_2 & 2) != 0) {
            stage_v_144 = (pub_r000267_15 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000267_15 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000267_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000267_5 & 2) != 0) {
            stage_v_145 = (pub_r000267_4 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000267_4 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000267_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000267_15 & 2) != 0) {
            stage_v_146 = (pub_r000267_7 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000267_7 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000267_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000267_5 & 2) != 0) {
            stage_v_147 = (pub_r000267_13 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000267_13 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000267_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000267_11 & 1) != 0) {
        if ((sec_r000267_17 & 2) != 0) {
            stage_v_148 = (pub_r000267_14 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000267_14 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000267_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000267_1 & 2) != 0) {
            stage_v_149 = (pub_r000267_9 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000267_9 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000267_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000267_16 & 2) != 0) {
            stage_v_150 = (pub_r000267_6 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000267_6 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000267_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000267_7 & 2) != 0) {
            stage_v_151 = (pub_r000267_16 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000267_16 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000267_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
