/*
 * Benchmark Program: R000907
 * Security Family: nested_implicit_flow
 * Generator Seed: 590713
 * High Inputs: 19 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000907_713_0 {
    short peak;
    short rms;
    int sample_rate;
    unsigned char gain;
    short channels;
    int envelope;
    int buffer[3];
};

struct EventLog_R000907_713_1 {
    int signature;
    int facility;
    short code;
    int buffer[3];
};

struct FilterState_R000907_713_2 {
    unsigned char prev_in;
    int prev_out;
    int mode;
    int buffer[3];
};

struct DeviceConfig_R000907_713_3 {
    short parity;
    unsigned char stop_bits;
    int port;
    int buffer[3];
};

union PacketPayload_R000907_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000907_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000907_713_0(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_94 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_94 > 46) {
        acc = (acc + bound_94 * 2 + 5) & 127;
        aux ^= (bound_94 & 15);
    } else {
        acc = (acc - bound_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_16 = local_arr[aux % 3];
    acc = (acc + coefficient_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000907_713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int sample_20 = local_arr[aux % 3];
    acc = (acc + sample_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_86 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_86 > 41) {
        acc = (acc + vector_86 * 2 + 5) & 127;
        aux ^= (vector_86 & 15);
    } else {
        acc = (acc - vector_86 + 11) & 127;
        aux += 3;
    }
    int bound_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000907_713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_53 = (aux + st.buffer[1]) & 3;
    switch (tracker_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_77 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_77 > 15) {
        acc = (acc + accumulator_77 * 2 + 5) & 127;
        aux ^= (accumulator_77 & 15);
    } else {
        acc = (acc - accumulator_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_53 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_53 > 21) {
        acc = (acc + pivot_53 * 2 + 5) & 127;
        aux ^= (pivot_53 & 15);
    } else {
        acc = (acc - pivot_53 + 11) & 127;
        aux += 3;
    }
    int tally_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_33) & 63;
    acc ^= aux;
    int weight_33 = (aux + st.buffer[1]) & 3;
    switch (weight_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int margin_78 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_78 > 29) {
        acc = (acc + margin_78 * 2 + 5) & 127;
        aux ^= (margin_78 & 15);
    } else {
        acc = (acc - margin_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_44 = local_arr[aux % 3];
    acc = (acc + margin_44 * 2) & 127;
    int tracker_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000907_713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_63 = (aux + st.buffer[1]) & 3;
    switch (factor_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_99 = local_arr[aux % 3];
    acc = (acc + damping_99 * 2) & 127;
    int residue_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000907_713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int delta_22 = local_arr[aux % 3];
    acc = (acc + delta_22 * 2) & 127;
    int offset_73 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_73 > 21) {
        acc = (acc + offset_73 * 2 + 5) & 127;
        aux ^= (offset_73 & 15);
    } else {
        acc = (acc - offset_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_7(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000907_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_14 = local_arr[aux % 3];
    acc = (acc + tally_14 * 2) & 127;
    int parity_48 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_48 > 43) {
        acc = (acc + parity_48 * 2 + 5) & 127;
        aux ^= (parity_48 & 15);
    } else {
        acc = (acc - parity_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_8(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_69) & 63;
    acc ^= aux;
    int accumulator_66 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_66 > 16) {
        acc = (acc + accumulator_66 * 2 + 5) & 127;
        aux ^= (accumulator_66 & 15);
    } else {
        acc = (acc - accumulator_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_96 = local_arr[aux % 3];
    acc = (acc + offset_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000907_713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_15) & 63;
    acc ^= aux;
    int offset_32 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_32 > 12) {
        acc = (acc + offset_32 * 2 + 5) & 127;
        aux ^= (offset_32 & 15);
    } else {
        acc = (acc - offset_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000907_713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000907_713_12(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int damping_92 = local_arr[aux % 3];
    acc = (acc + damping_92 * 2) & 127;
    int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_70) & 63;
    acc ^= aux;
    int cursor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_97 > 34) {
        acc = (acc + cursor_97 * 2 + 5) & 127;
        aux ^= (cursor_97 & 15);
    } else {
        acc = (acc - cursor_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_54 = (aux + st.buffer[1]) & 3;
    switch (anchor_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_14(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int damping_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_57) & 63;
    acc ^= aux;
    int damping_67 = (aux + st.buffer[1]) & 3;
    switch (damping_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_95 = (aux + st.buffer[1]) & 3;
    switch (margin_95) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_99 > 48) {
        acc = (acc + factor_99 * 2 + 5) & 127;
        aux ^= (factor_99 & 15);
    } else {
        acc = (acc - factor_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000907_713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000907_713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_33 = (aux + st.buffer[1]) & 3;
    switch (quantum_33) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000907_0;
    int sec_r000907_1;
    int sec_r000907_2;
    int sec_r000907_3;
    int sec_r000907_4;
    int sec_r000907_5;
    int sec_r000907_6;
    int sec_r000907_7;
    int sec_r000907_8;
    int sec_r000907_9;
    int sec_r000907_10;
    int sec_r000907_11;
    int sec_r000907_12;
    int sec_r000907_13;
    int sec_r000907_14;
    int sec_r000907_15;
    int sec_r000907_16;
    int sec_r000907_17;
    int sec_r000907_18;
    int pub_r000907_0;
    int pub_r000907_1;
    int pub_r000907_2;
    int pub_r000907_3;
    int pub_r000907_4;
    int pub_r000907_5;
    int pub_r000907_6;
    int pub_r000907_7;
    int pub_r000907_8;
    int pub_r000907_9;
    int pub_r000907_10;
    int pub_r000907_11;
    int pub_r000907_12;
    int pub_r000907_13;
    int pub_r000907_14;
    int pub_r000907_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000907_0 >= -100 && pub_r000907_0 <= 100);
    __CPROVER_assume(pub_r000907_1 >= -100 && pub_r000907_1 <= 100);
    __CPROVER_assume(pub_r000907_2 >= -100 && pub_r000907_2 <= 100);
    __CPROVER_assume(pub_r000907_3 >= -100 && pub_r000907_3 <= 100);
    __CPROVER_assume(pub_r000907_4 >= -100 && pub_r000907_4 <= 100);
    __CPROVER_assume(pub_r000907_5 >= -100 && pub_r000907_5 <= 100);
    __CPROVER_assume(pub_r000907_6 >= -100 && pub_r000907_6 <= 100);
    __CPROVER_assume(pub_r000907_7 >= -100 && pub_r000907_7 <= 100);
    __CPROVER_assume(pub_r000907_8 >= -100 && pub_r000907_8 <= 100);
    __CPROVER_assume(pub_r000907_9 >= -100 && pub_r000907_9 <= 100);
    __CPROVER_assume(pub_r000907_10 >= -100 && pub_r000907_10 <= 100);
    __CPROVER_assume(pub_r000907_11 >= -100 && pub_r000907_11 <= 100);
    __CPROVER_assume(pub_r000907_12 >= -100 && pub_r000907_12 <= 100);
    __CPROVER_assume(pub_r000907_13 >= -100 && pub_r000907_13 <= 100);
    __CPROVER_assume(pub_r000907_14 >= -100 && pub_r000907_14 <= 100);
    __CPROVER_assume(pub_r000907_15 >= -100 && pub_r000907_15 <= 100);
    __CPROVER_assume(sec_r000907_0 >= 0 && sec_r000907_0 <= 255);
    __CPROVER_assume(sec_r000907_1 >= 0 && sec_r000907_1 <= 255);
    __CPROVER_assume(sec_r000907_2 >= 0 && sec_r000907_2 <= 255);
    __CPROVER_assume(sec_r000907_3 >= 0 && sec_r000907_3 <= 255);
    __CPROVER_assume(sec_r000907_4 >= 0 && sec_r000907_4 <= 255);
    __CPROVER_assume(sec_r000907_5 >= 0 && sec_r000907_5 <= 255);
    __CPROVER_assume(sec_r000907_6 >= 0 && sec_r000907_6 <= 255);
    __CPROVER_assume(sec_r000907_7 >= 0 && sec_r000907_7 <= 255);
    __CPROVER_assume(sec_r000907_8 >= 0 && sec_r000907_8 <= 255);
    __CPROVER_assume(sec_r000907_9 >= 0 && sec_r000907_9 <= 255);
    __CPROVER_assume(sec_r000907_10 >= 0 && sec_r000907_10 <= 255);
    __CPROVER_assume(sec_r000907_11 >= 0 && sec_r000907_11 <= 255);
    __CPROVER_assume(sec_r000907_12 >= 0 && sec_r000907_12 <= 255);
    __CPROVER_assume(sec_r000907_13 >= 0 && sec_r000907_13 <= 255);
    __CPROVER_assume(sec_r000907_14 >= 0 && sec_r000907_14 <= 255);
    __CPROVER_assume(sec_r000907_15 >= 0 && sec_r000907_15 <= 255);
    __CPROVER_assume(sec_r000907_16 >= 0 && sec_r000907_16 <= 255);
    __CPROVER_assume(sec_r000907_17 >= 0 && sec_r000907_17 <= 255);
    __CPROVER_assume(sec_r000907_18 >= 0 && sec_r000907_18 <= 255);

    struct AudioFrame_R000907_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000907_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000907_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000907_0 + 7) & 15;
    struct EventLog_R000907_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000907_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000907_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000907_0 + 9) & 15;
    struct FilterState_R000907_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000907_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000907_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000907_0 + 11) & 15;
    struct DeviceConfig_R000907_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000907_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000907_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000907_0 + 13) & 15;

    union PacketPayload_R000907_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 14) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 29) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

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
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 50) {
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
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
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
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 20) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 35) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 40) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 55) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 39) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 54) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 21) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 36) {
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
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 18) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 33) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 14) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 29) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 33) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 48) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 17) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 32) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000907_7 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_56 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_57 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000907_18 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_58 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_59 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000907_9 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_60 = (pub_r000907_1 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000907_1 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000907_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_61 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_62 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000907_5 & 2) != 0) {
            stage_v_63 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_64 = (pub_r000907_5 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000907_5 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000907_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000907_12 & 2) != 0) {
            stage_v_65 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000907_18 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_66 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_67 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_68 = (pub_r000907_12 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000907_12 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000907_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_69 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_70 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000907_18 & 2) != 0) {
            stage_v_71 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_72 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_73 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000907_9 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_74 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_75 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_76 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000907_12 & 1) != 0) {
        if ((sec_r000907_1 & 2) != 0) {
            stage_v_77 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000907_15 & 1) != 0) {
        if ((sec_r000907_11 & 2) != 0) {
            stage_v_78 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000907_1 & 2) != 0) {
            stage_v_79 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_80 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000907_0 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_81 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000907_3 & 1) != 0) {
        if ((sec_r000907_9 & 2) != 0) {
            stage_v_82 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000907_18 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_83 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_84 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000907_11 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_85 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000907_16 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_86 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000907_2 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_87 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_88 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000907_16 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_89 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_90 = (pub_r000907_12 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000907_12 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000907_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_91 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000907_3 & 2) != 0) {
            stage_v_92 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000907_9 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_93 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000907_8 & 1) != 0) {
        if ((sec_r000907_14 & 2) != 0) {
            stage_v_94 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000907_3 & 2) != 0) {
            stage_v_95 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000907_1 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_96 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_97 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_98 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000907_6 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_99 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000907_15 & 1) != 0) {
        if ((sec_r000907_3 & 2) != 0) {
            stage_v_100 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_101 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_102 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_103 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000907_12 & 2) != 0) {
            stage_v_104 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_105 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_106 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_107 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000907_11 & 2) != 0) {
            stage_v_108 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000907_15 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_109 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000907_12 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_110 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_111 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_112 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000907_17 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_113 = (pub_r000907_12 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000907_12 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000907_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000907_0 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_114 = (pub_r000907_10 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000907_10 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000907_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_115 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_116 = (pub_r000907_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000907_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000907_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_117 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000907_11 & 2) != 0) {
            stage_v_118 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_119 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_120 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000907_5 & 2) != 0) {
            stage_v_121 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000907_1 & 2) != 0) {
            stage_v_122 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_123 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_124 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000907_9 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_125 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000907_11 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_126 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000907_18 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_127 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_128 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_129 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_130 = (pub_r000907_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000907_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000907_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_131 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000907_8 & 1) != 0) {
        if ((sec_r000907_3 & 2) != 0) {
            stage_v_132 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000907_12 & 2) != 0) {
            stage_v_133 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000907_0 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_134 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_135 = (pub_r000907_5 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000907_5 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000907_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000907_14 & 2) != 0) {
            stage_v_136 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000907_8 & 2) != 0) {
            stage_v_137 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_138 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_139 = (pub_r000907_14 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000907_14 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000907_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000907_14 & 2) != 0) {
            stage_v_140 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000907_5 & 2) != 0) {
            stage_v_141 = (pub_r000907_1 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000907_1 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000907_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_142 = (pub_r000907_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000907_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000907_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_143 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000907_18 & 2) != 0) {
            stage_v_144 = (pub_r000907_9 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000907_9 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000907_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000907_8 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_145 = (pub_r000907_1 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000907_1 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000907_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000907_2 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_146 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000907_15 & 2) != 0) {
            stage_v_147 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000907_2 & 2) != 0) {
            stage_v_148 = (pub_r000907_8 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000907_8 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000907_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000907_8 & 1) != 0) {
        if ((sec_r000907_9 & 2) != 0) {
            stage_v_149 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000907_11 & 2) != 0) {
            stage_v_150 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_151 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000907_14 & 2) != 0) {
            stage_v_152 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000907_5 & 2) != 0) {
            stage_v_153 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000907_14 & 1) != 0) {
        if ((sec_r000907_6 & 2) != 0) {
            stage_v_154 = (pub_r000907_4 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000907_4 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000907_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000907_17 & 2) != 0) {
            stage_v_155 = (pub_r000907_3 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000907_3 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000907_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000907_18 & 2) != 0) {
            stage_v_156 = (pub_r000907_12 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000907_12 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000907_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r000907_13 & 2) != 0) {
            stage_v_157 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000907_2 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_158 = (pub_r000907_15 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000907_15 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000907_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000907_0 & 1) != 0) {
        if ((sec_r000907_0 & 2) != 0) {
            stage_v_159 = (pub_r000907_11 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000907_11 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000907_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000907_16 & 2) != 0) {
            stage_v_160 = (pub_r000907_13 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000907_13 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000907_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r000907_10 & 2) != 0) {
            stage_v_161 = (pub_r000907_1 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000907_1 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000907_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000907_13 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_162 = (pub_r000907_0 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000907_0 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000907_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000907_8 & 1) != 0) {
        if ((sec_r000907_7 & 2) != 0) {
            stage_v_163 = (pub_r000907_6 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000907_6 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000907_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000907_4 & 2) != 0) {
            stage_v_164 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000907_10 & 1) != 0) {
        if ((sec_r000907_9 & 2) != 0) {
            stage_v_165 = (pub_r000907_7 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000907_7 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000907_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
