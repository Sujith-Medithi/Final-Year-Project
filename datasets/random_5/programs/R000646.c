/*
 * Benchmark Program: R000646
 * Security Family: implicit_flow
 * Generator Seed: 564613
 * High Inputs: 22 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000646_4613_0 {
    int severity;
    int code;
    unsigned char facility;
    int signature;
    int timestamp;
    short seq;
    int buffer[3];
};

struct StreamBuffer_R000646_4613_1 {
    unsigned char tail;
    int checksum;
    unsigned char head;
    unsigned char state;
    short watermark;
    int buffer[3];
};

struct AudioFrame_R000646_4613_2 {
    short gain;
    short rms;
    short envelope;
    int channels;
    int peak;
    unsigned char sample_rate;
    int buffer[3];
};

struct Vector3D_R000646_4613_3 {
    int pitch;
    unsigned char coord_z;
    unsigned char heading;
    int buffer[3];
};

union TelemetryField_R000646_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000646_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000646_4613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_35 = (aux + st.buffer[1]) & 3;
    switch (bound_35) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_27 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_27 > 17) {
        acc = (acc + index_reg_27 * 2 + 5) & 127;
        aux ^= (index_reg_27 & 15);
    } else {
        acc = (acc - index_reg_27 + 11) & 127;
        aux += 3;
    }
    int checksum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000646_4613_1(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000646_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int offset_58 = (aux + st.buffer[1]) & 3;
    switch (offset_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_38 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_38 > 29) {
        acc = (acc + pivot_38 * 2 + 5) & 127;
        aux ^= (pivot_38 & 15);
    } else {
        acc = (acc - pivot_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_77 = local_arr[aux % 3];
    acc = (acc + damping_77 * 2) & 127;
    int tracker_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000646_4613_2(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_78) & 63;
    acc ^= aux;
    int cursor_38 = (aux + st.buffer[1]) & 3;
    switch (cursor_38) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_69 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_69 > 33) {
        acc = (acc + offset_69 * 2 + 5) & 127;
        aux ^= (offset_69 & 15);
    } else {
        acc = (acc - offset_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_3(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_97 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_97 > 47) {
        acc = (acc + vector_97 * 2 + 5) & 127;
        aux ^= (vector_97 & 15);
    } else {
        acc = (acc - vector_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_13 = (aux + st.buffer[1]) & 3;
    switch (bound_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_4(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_19 = (aux + st.buffer[1]) & 3;
    switch (mask_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_74 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_74 > 10) {
        acc = (acc + sample_74 * 2 + 5) & 127;
        aux ^= (sample_74 & 15);
    } else {
        acc = (acc - sample_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_83 = local_arr[aux % 3];
    acc = (acc + quantum_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_42 = (aux + st.buffer[1]) & 3;
    switch (index_reg_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_55 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_55 > 33) {
        acc = (acc + bound_55 * 2 + 5) & 127;
        aux ^= (bound_55 & 15);
    } else {
        acc = (acc - bound_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_6(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int index_reg_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_50 = local_arr[aux % 3];
    acc = (acc + threshold_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_74 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_74 > 11) {
        acc = (acc + metric_74 * 2 + 5) & 127;
        aux ^= (metric_74 & 15);
    } else {
        acc = (acc - metric_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_18 = local_arr[aux % 3];
    acc = (acc + offset_18 * 2) & 127;
    int vector_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_78) & 63;
    acc ^= aux;
    int accumulator_22 = (aux + st.buffer[1]) & 3;
    switch (accumulator_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_28 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_28 > 15) {
        acc = (acc + quotient_28 * 2 + 5) & 127;
        aux ^= (quotient_28 & 15);
    } else {
        acc = (acc - quotient_28 + 11) & 127;
        aux += 3;
    }
    int quantum_98 = (aux + st.buffer[1]) & 3;
    switch (quantum_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_9(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_67 = (aux + st.buffer[1]) & 3;
    switch (factor_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_44 = local_arr[aux % 3];
    acc = (acc + scale_44 * 2) & 127;
    int factor_36 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_36 > 28) {
        acc = (acc + factor_36 * 2 + 5) & 127;
        aux ^= (factor_36 & 15);
    } else {
        acc = (acc - factor_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int metric_19 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_19 > 16) {
        acc = (acc + metric_19 * 2 + 5) & 127;
        aux ^= (metric_19 & 15);
    } else {
        acc = (acc - metric_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_20 = local_arr[aux % 3];
    acc = (acc + delta_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000646_4613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int factor_21 = local_arr[aux % 3];
    acc = (acc + factor_21 * 2) & 127;
    int residue_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_63) & 63;
    acc ^= aux;
    int sample_32 = (aux + st.buffer[1]) & 3;
    switch (sample_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_12(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_73 = (aux + st.buffer[1]) & 3;
    switch (factor_73) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_51) & 63;
    acc ^= aux;
    int parity_70 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_70 > 22) {
        acc = (acc + parity_70 * 2 + 5) & 127;
        aux ^= (parity_70 & 15);
    } else {
        acc = (acc - parity_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_13(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000646_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_94 > 43) {
        acc = (acc + quotient_94 * 2 + 5) & 127;
        aux ^= (quotient_94 & 15);
    } else {
        acc = (acc - quotient_94 + 11) & 127;
        aux += 3;
    }
    int damping_80 = (aux + st.buffer[1]) & 3;
    switch (damping_80) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_14(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000646_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_73 = (aux + st.buffer[1]) & 3;
    switch (bound_73) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_65 = local_arr[aux % 3];
    acc = (acc + mask_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_15(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000646_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int tracker_47 = local_arr[aux % 3];
    acc = (acc + tracker_47 * 2) & 127;
    int offset_42 = (aux + st.buffer[1]) & 3;
    switch (offset_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_26 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_26 > 14) {
        acc = (acc + factor_26 * 2 + 5) & 127;
        aux ^= (factor_26 & 15);
    } else {
        acc = (acc - factor_26 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000646_4613_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000646_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int factor_74 = local_arr[aux % 3];
    acc = (acc + factor_74 * 2) & 127;
    int bound_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_15 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_15 > 29) {
        acc = (acc + cursor_15 * 2 + 5) & 127;
        aux ^= (cursor_15 & 15);
    } else {
        acc = (acc - cursor_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_17(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int tally_14 = local_arr[aux % 3];
    acc = (acc + tally_14 * 2) & 127;
    int residue_63 = (aux + st.buffer[1]) & 3;
    switch (residue_63) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000646_4613_18(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quotient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_11) & 63;
    acc ^= aux;
    int tracker_76 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_76 > 32) {
        acc = (acc + tracker_76 * 2 + 5) & 127;
        aux ^= (tracker_76 & 15);
    } else {
        acc = (acc - tracker_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000646_0;
    int sec_r000646_1;
    int sec_r000646_2;
    int sec_r000646_3;
    int sec_r000646_4;
    int sec_r000646_5;
    int sec_r000646_6;
    int sec_r000646_7;
    int sec_r000646_8;
    int sec_r000646_9;
    int sec_r000646_10;
    int sec_r000646_11;
    int sec_r000646_12;
    int sec_r000646_13;
    int sec_r000646_14;
    int sec_r000646_15;
    int sec_r000646_16;
    int sec_r000646_17;
    int sec_r000646_18;
    int sec_r000646_19;
    int sec_r000646_20;
    int sec_r000646_21;
    int pub_r000646_0;
    int pub_r000646_1;
    int pub_r000646_2;
    int pub_r000646_3;
    int pub_r000646_4;
    int pub_r000646_5;
    int pub_r000646_6;
    int pub_r000646_7;
    int pub_r000646_8;
    int pub_r000646_9;
    int pub_r000646_10;
    int pub_r000646_11;
    int pub_r000646_12;
    int pub_r000646_13;
    int pub_r000646_14;
    int pub_r000646_15;
    int pub_r000646_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000646_0 >= -100 && pub_r000646_0 <= 100);
    __CPROVER_assume(pub_r000646_1 >= -100 && pub_r000646_1 <= 100);
    __CPROVER_assume(pub_r000646_2 >= -100 && pub_r000646_2 <= 100);
    __CPROVER_assume(pub_r000646_3 >= -100 && pub_r000646_3 <= 100);
    __CPROVER_assume(pub_r000646_4 >= -100 && pub_r000646_4 <= 100);
    __CPROVER_assume(pub_r000646_5 >= -100 && pub_r000646_5 <= 100);
    __CPROVER_assume(pub_r000646_6 >= -100 && pub_r000646_6 <= 100);
    __CPROVER_assume(pub_r000646_7 >= -100 && pub_r000646_7 <= 100);
    __CPROVER_assume(pub_r000646_8 >= -100 && pub_r000646_8 <= 100);
    __CPROVER_assume(pub_r000646_9 >= -100 && pub_r000646_9 <= 100);
    __CPROVER_assume(pub_r000646_10 >= -100 && pub_r000646_10 <= 100);
    __CPROVER_assume(pub_r000646_11 >= -100 && pub_r000646_11 <= 100);
    __CPROVER_assume(pub_r000646_12 >= -100 && pub_r000646_12 <= 100);
    __CPROVER_assume(pub_r000646_13 >= -100 && pub_r000646_13 <= 100);
    __CPROVER_assume(pub_r000646_14 >= -100 && pub_r000646_14 <= 100);
    __CPROVER_assume(pub_r000646_15 >= -100 && pub_r000646_15 <= 100);
    __CPROVER_assume(pub_r000646_16 >= -100 && pub_r000646_16 <= 100);
    __CPROVER_assume(sec_r000646_0 >= 0 && sec_r000646_0 <= 255);
    __CPROVER_assume(sec_r000646_1 >= 0 && sec_r000646_1 <= 255);
    __CPROVER_assume(sec_r000646_2 >= 0 && sec_r000646_2 <= 255);
    __CPROVER_assume(sec_r000646_3 >= 0 && sec_r000646_3 <= 255);
    __CPROVER_assume(sec_r000646_4 >= 0 && sec_r000646_4 <= 255);
    __CPROVER_assume(sec_r000646_5 >= 0 && sec_r000646_5 <= 255);
    __CPROVER_assume(sec_r000646_6 >= 0 && sec_r000646_6 <= 255);
    __CPROVER_assume(sec_r000646_7 >= 0 && sec_r000646_7 <= 255);
    __CPROVER_assume(sec_r000646_8 >= 0 && sec_r000646_8 <= 255);
    __CPROVER_assume(sec_r000646_9 >= 0 && sec_r000646_9 <= 255);
    __CPROVER_assume(sec_r000646_10 >= 0 && sec_r000646_10 <= 255);
    __CPROVER_assume(sec_r000646_11 >= 0 && sec_r000646_11 <= 255);
    __CPROVER_assume(sec_r000646_12 >= 0 && sec_r000646_12 <= 255);
    __CPROVER_assume(sec_r000646_13 >= 0 && sec_r000646_13 <= 255);
    __CPROVER_assume(sec_r000646_14 >= 0 && sec_r000646_14 <= 255);
    __CPROVER_assume(sec_r000646_15 >= 0 && sec_r000646_15 <= 255);
    __CPROVER_assume(sec_r000646_16 >= 0 && sec_r000646_16 <= 255);
    __CPROVER_assume(sec_r000646_17 >= 0 && sec_r000646_17 <= 255);
    __CPROVER_assume(sec_r000646_18 >= 0 && sec_r000646_18 <= 255);
    __CPROVER_assume(sec_r000646_19 >= 0 && sec_r000646_19 <= 255);
    __CPROVER_assume(sec_r000646_20 >= 0 && sec_r000646_20 <= 255);
    __CPROVER_assume(sec_r000646_21 >= 0 && sec_r000646_21 <= 255);

    struct EventLog_R000646_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000646_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000646_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000646_0 + 7) & 15;
    struct StreamBuffer_R000646_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000646_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000646_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000646_0 + 9) & 15;
    struct AudioFrame_R000646_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000646_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000646_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000646_0 + 11) & 15;
    struct Vector3D_R000646_4613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000646_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000646_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000646_0 + 13) & 15;

    union TelemetryField_R000646_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 11) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 26) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 15) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 30) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

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
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((sec_r000646_8 & 63) > 21) {
        stage_v_18 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_18) & 255;
    } else {
        stage_v_18 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_18 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_18 & 63) > 33) {
        stage_v_19 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_19) & 255;
    } else {
        stage_v_19 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_19 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_19 & 63) > 19) {
        stage_v_20 = (pub_r000646_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_20) & 255;
    } else {
        stage_v_20 = (pub_r000646_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_20 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((stage_v_20 & 63) > 19) {
        stage_v_21 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_21) & 255;
    } else {
        stage_v_21 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_21 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((sec_r000646_20 & 63) > 15) {
        stage_v_22 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_22) & 255;
    } else {
        stage_v_22 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_22 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_18 & 63) > 36) {
        stage_v_23 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_23) & 255;
    } else {
        stage_v_23 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_23 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((sec_r000646_3 & 63) > 17) {
        stage_v_24 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_24) & 255;
    } else {
        stage_v_24 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_24 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((sec_r000646_6 & 63) > 51) {
        stage_v_25 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_25) & 255;
    } else {
        stage_v_25 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_25 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((sec_r000646_20 & 63) > 22) {
        stage_v_26 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_26) & 255;
    } else {
        stage_v_26 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_26 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_21 & 63) > 24) {
        stage_v_27 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_27) & 255;
    } else {
        stage_v_27 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_27 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_27 & 63) > 22) {
        stage_v_28 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_28) & 255;
    } else {
        stage_v_28 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_28 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_25 & 63) > 27) {
        stage_v_29 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_29) & 255;
    } else {
        stage_v_29 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_29 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_25 & 63) > 15) {
        stage_v_30 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_30) & 255;
    } else {
        stage_v_30 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_30 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_28 & 63) > 42) {
        stage_v_31 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_31) & 255;
    } else {
        stage_v_31 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_31 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((sec_r000646_15 & 63) > 19) {
        stage_v_32 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_32) & 255;
    } else {
        stage_v_32 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_32 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_19 & 63) > 31) {
        stage_v_33 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_33) & 255;
    } else {
        stage_v_33 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_33 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_33 & 63) > 21) {
        stage_v_34 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_34) & 255;
    } else {
        stage_v_34 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_34 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_32 & 63) > 58) {
        stage_v_35 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_35) & 255;
    } else {
        stage_v_35 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_35 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_32 & 63) > 50) {
        stage_v_36 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_36) & 255;
    } else {
        stage_v_36 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_36 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_31 & 63) > 20) {
        stage_v_37 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_37) & 255;
    } else {
        stage_v_37 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_37 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000646_17 & 63) > 21) {
        stage_v_38 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_38) & 255;
    } else {
        stage_v_38 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_38 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000646_17 & 63) > 21) {
        stage_v_39 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_39) & 255;
    } else {
        stage_v_39 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_39 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_25 & 63) > 29) {
        stage_v_40 = (pub_r000646_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_40) & 255;
    } else {
        stage_v_40 = (pub_r000646_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_40 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000646_16 & 63) > 60) {
        stage_v_41 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_41) & 255;
    } else {
        stage_v_41 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_41 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000646_8 & 63) > 54) {
        stage_v_42 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_42) & 255;
    } else {
        stage_v_42 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_42 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_41 & 63) > 60) {
        stage_v_43 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_43) & 255;
    } else {
        stage_v_43 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_43 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_21 & 63) > 46) {
        stage_v_44 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_44) & 255;
    } else {
        stage_v_44 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_44 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((sec_r000646_20 & 63) > 29) {
        stage_v_45 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_45) & 255;
    } else {
        stage_v_45 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_45 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_44 & 63) > 53) {
        stage_v_46 = (pub_r000646_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_46) & 255;
    } else {
        stage_v_46 = (pub_r000646_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_46 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_28 & 63) > 38) {
        stage_v_47 = (pub_r000646_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_47) & 255;
    } else {
        stage_v_47 = (pub_r000646_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_47 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_44 & 63) > 46) {
        stage_v_48 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_48) & 255;
    } else {
        stage_v_48 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_48 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_27 & 63) > 16) {
        stage_v_49 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_49) & 255;
    } else {
        stage_v_49 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_49 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_45 & 63) > 44) {
        stage_v_50 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_50) & 255;
    } else {
        stage_v_50 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_50 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_49 & 63) > 26) {
        stage_v_51 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_51) & 255;
    } else {
        stage_v_51 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_51 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_50 & 63) > 19) {
        stage_v_52 = (pub_r000646_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_52) & 255;
    } else {
        stage_v_52 = (pub_r000646_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_52 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_24 & 63) > 44) {
        stage_v_53 = (pub_r000646_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_53) & 255;
    } else {
        stage_v_53 = (pub_r000646_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_53 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_39 & 63) > 43) {
        stage_v_54 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_54) & 255;
    } else {
        stage_v_54 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_54 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_37 & 63) > 34) {
        stage_v_55 = (pub_r000646_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_55) & 255;
    } else {
        stage_v_55 = (pub_r000646_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_55 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_25 & 63) > 54) {
        stage_v_56 = (pub_r000646_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_56) & 255;
    } else {
        stage_v_56 = (pub_r000646_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_56 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000646_18 & 63) > 31) {
        stage_v_57 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_57) & 255;
    } else {
        stage_v_57 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_57 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_56 & 63) > 60) {
        stage_v_58 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_58) & 255;
    } else {
        stage_v_58 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_58 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000646_12 & 63) > 41) {
        stage_v_59 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_59) & 255;
    } else {
        stage_v_59 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_59 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_45 & 63) > 58) {
        stage_v_60 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_60) & 255;
    } else {
        stage_v_60 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_60 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_51 & 63) > 22) {
        stage_v_61 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_61) & 255;
    } else {
        stage_v_61 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_61 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000646_17 & 63) > 27) {
        stage_v_62 = (pub_r000646_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_62) & 255;
    } else {
        stage_v_62 = (pub_r000646_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_62 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_45 & 63) > 15) {
        stage_v_63 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_63) & 255;
    } else {
        stage_v_63 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_63 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_46 & 63) > 22) {
        stage_v_64 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_64) & 255;
    } else {
        stage_v_64 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_64 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_39 & 63) > 38) {
        stage_v_65 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_65) & 255;
    } else {
        stage_v_65 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_65 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_51 & 63) > 52) {
        stage_v_66 = (pub_r000646_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_66) & 255;
    } else {
        stage_v_66 = (pub_r000646_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_66 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000646_17 & 63) > 56) {
        stage_v_67 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_67) & 255;
    } else {
        stage_v_67 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_67 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_47 & 63) > 36) {
        stage_v_68 = (pub_r000646_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_68) & 255;
    } else {
        stage_v_68 = (pub_r000646_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_68 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_52 & 63) > 56) {
        stage_v_69 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_69) & 255;
    } else {
        stage_v_69 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_69 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_53 & 63) > 18) {
        stage_v_70 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_70) & 255;
    } else {
        stage_v_70 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_70 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000646_13 & 63) > 54) {
        stage_v_71 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_71) & 255;
    } else {
        stage_v_71 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_71 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000646_3 & 63) > 49) {
        stage_v_72 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_72) & 255;
    } else {
        stage_v_72 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_72 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_72 & 63) > 35) {
        stage_v_73 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_73) & 255;
    } else {
        stage_v_73 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_73 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000646_15 & 63) > 43) {
        stage_v_74 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_74) & 255;
    } else {
        stage_v_74 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_74 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_36 & 63) > 51) {
        stage_v_75 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_75) & 255;
    } else {
        stage_v_75 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_75 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_58 & 63) > 45) {
        stage_v_76 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_76) & 255;
    } else {
        stage_v_76 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_76 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_33 & 63) > 59) {
        stage_v_77 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_77) & 255;
    } else {
        stage_v_77 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_77 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_72 & 63) > 23) {
        stage_v_78 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_78) & 255;
    } else {
        stage_v_78 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_78 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_69 & 63) > 42) {
        stage_v_79 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_79) & 255;
    } else {
        stage_v_79 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_79 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000646_20 & 63) > 41) {
        stage_v_80 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_80) & 255;
    } else {
        stage_v_80 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_80 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000646_18 & 63) > 60) {
        stage_v_81 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_81) & 255;
    } else {
        stage_v_81 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_81 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_49 & 63) > 22) {
        stage_v_82 = (pub_r000646_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_82) & 255;
    } else {
        stage_v_82 = (pub_r000646_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_82 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000646_1 & 63) > 47) {
        stage_v_83 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_83) & 255;
    } else {
        stage_v_83 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_83 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_68 & 63) > 53) {
        stage_v_84 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_84) & 255;
    } else {
        stage_v_84 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_84 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000646_17 & 63) > 45) {
        stage_v_85 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_85) & 255;
    } else {
        stage_v_85 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_85 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_44 & 63) > 30) {
        stage_v_86 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_86) & 255;
    } else {
        stage_v_86 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_86 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000646_15 & 63) > 16) {
        stage_v_87 = (pub_r000646_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_87) & 255;
    } else {
        stage_v_87 = (pub_r000646_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_87 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_29 & 63) > 25) {
        stage_v_88 = (pub_r000646_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_88) & 255;
    } else {
        stage_v_88 = (pub_r000646_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_88 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000646_19 & 63) > 53) {
        stage_v_89 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_89) & 255;
    } else {
        stage_v_89 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_89 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_40 & 63) > 37) {
        stage_v_90 = (pub_r000646_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_90) & 255;
    } else {
        stage_v_90 = (pub_r000646_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_90 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_42 & 63) > 54) {
        stage_v_91 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_91) & 255;
    } else {
        stage_v_91 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_91 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_25 & 63) > 31) {
        stage_v_92 = (pub_r000646_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_92) & 255;
    } else {
        stage_v_92 = (pub_r000646_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_92 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_82 & 63) > 51) {
        stage_v_93 = (pub_r000646_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_93) & 255;
    } else {
        stage_v_93 = (pub_r000646_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_93 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000646_5 & 63) > 54) {
        stage_v_94 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_94) & 255;
    } else {
        stage_v_94 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_94 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_36 & 63) > 34) {
        stage_v_95 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_95) & 255;
    } else {
        stage_v_95 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_95 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_28 & 63) > 38) {
        stage_v_96 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_96) & 255;
    } else {
        stage_v_96 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_96 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_58 & 63) > 57) {
        stage_v_97 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_97) & 255;
    } else {
        stage_v_97 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_97 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_92 & 63) > 45) {
        stage_v_98 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_98) & 255;
    } else {
        stage_v_98 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_98 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_43 & 63) > 26) {
        stage_v_99 = (pub_r000646_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_99) & 255;
    } else {
        stage_v_99 = (pub_r000646_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_99 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_42 & 63) > 33) {
        stage_v_100 = (pub_r000646_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_100) & 255;
    } else {
        stage_v_100 = (pub_r000646_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_100 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000646_1 & 63) > 55) {
        stage_v_101 = (pub_r000646_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_101) & 255;
    } else {
        stage_v_101 = (pub_r000646_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_101 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000646_17 & 63) > 36) {
        stage_v_102 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_102) & 255;
    } else {
        stage_v_102 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_102 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_64 & 63) > 17) {
        stage_v_103 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_103) & 255;
    } else {
        stage_v_103 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_103 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000646_21 & 63) > 52) {
        stage_v_104 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_104) & 255;
    } else {
        stage_v_104 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_104 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000646_20 & 63) > 50) {
        stage_v_105 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_105) & 255;
    } else {
        stage_v_105 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_105 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_92 & 63) > 19) {
        stage_v_106 = (pub_r000646_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_106) & 255;
    } else {
        stage_v_106 = (pub_r000646_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_106 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_28 & 63) > 47) {
        stage_v_107 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_107) & 255;
    } else {
        stage_v_107 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_107 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_39 & 63) > 17) {
        stage_v_108 = (pub_r000646_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_108) & 255;
    } else {
        stage_v_108 = (pub_r000646_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_108 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_96 & 63) > 52) {
        stage_v_109 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_109) & 255;
    } else {
        stage_v_109 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_109 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_91 & 63) > 43) {
        stage_v_110 = (pub_r000646_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_110) & 255;
    } else {
        stage_v_110 = (pub_r000646_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_110 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_43 & 63) > 60) {
        stage_v_111 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_111) & 255;
    } else {
        stage_v_111 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_111 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_37 & 63) > 37) {
        stage_v_112 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_112) & 255;
    } else {
        stage_v_112 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_112 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_60 & 63) > 58) {
        stage_v_113 = (pub_r000646_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_113) & 255;
    } else {
        stage_v_113 = (pub_r000646_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_113 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_108 & 63) > 33) {
        stage_v_114 = (pub_r000646_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_114) & 255;
    } else {
        stage_v_114 = (pub_r000646_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_114 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_83 & 63) > 32) {
        stage_v_115 = (pub_r000646_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_115) & 255;
    } else {
        stage_v_115 = (pub_r000646_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_115 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000646_6 & 63) > 52) {
        stage_v_116 = (pub_r000646_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_116) & 255;
    } else {
        stage_v_116 = (pub_r000646_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_116 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_84 & 63) > 38) {
        stage_v_117 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_117) & 255;
    } else {
        stage_v_117 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_117 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000646_9 & 63) > 18) {
        stage_v_118 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_118) & 255;
    } else {
        stage_v_118 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_118 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_75 & 63) > 16) {
        stage_v_119 = (pub_r000646_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_119) & 255;
    } else {
        stage_v_119 = (pub_r000646_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_119 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_19 & 63) > 48) {
        stage_v_120 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_120) & 255;
    } else {
        stage_v_120 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_120 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_28 & 63) > 59) {
        stage_v_121 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_121) & 255;
    } else {
        stage_v_121 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_121 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000646_21 & 63) > 43) {
        stage_v_122 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_122) & 255;
    } else {
        stage_v_122 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_122 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_18 & 63) > 41) {
        stage_v_123 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_123) & 255;
    } else {
        stage_v_123 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_123 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_33 & 63) > 18) {
        stage_v_124 = (pub_r000646_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_124) & 255;
    } else {
        stage_v_124 = (pub_r000646_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_124 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_43 & 63) > 60) {
        stage_v_125 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_125) & 255;
    } else {
        stage_v_125 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_125 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000646_6 & 63) > 49) {
        stage_v_126 = (pub_r000646_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_126) & 255;
    } else {
        stage_v_126 = (pub_r000646_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_126 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_100 & 63) > 32) {
        stage_v_127 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_127) & 255;
    } else {
        stage_v_127 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_127 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_109 & 63) > 43) {
        stage_v_128 = (pub_r000646_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_128) & 255;
    } else {
        stage_v_128 = (pub_r000646_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_128 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_87 & 63) > 17) {
        stage_v_129 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_129) & 255;
    } else {
        stage_v_129 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_129 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000646_7 & 63) > 24) {
        stage_v_130 = (pub_r000646_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_130) & 255;
    } else {
        stage_v_130 = (pub_r000646_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_130 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_84 & 63) > 58) {
        stage_v_131 = (pub_r000646_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_131) & 255;
    } else {
        stage_v_131 = (pub_r000646_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_131 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000646_18 & 63) > 45) {
        stage_v_132 = (pub_r000646_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_132) & 255;
    } else {
        stage_v_132 = (pub_r000646_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_132 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_64 & 63) > 55) {
        stage_v_133 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_133) & 255;
    } else {
        stage_v_133 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_133 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000646_13 & 63) > 48) {
        stage_v_134 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_134) & 255;
    } else {
        stage_v_134 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_134 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_40 & 63) > 32) {
        stage_v_135 = (pub_r000646_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_135) & 255;
    } else {
        stage_v_135 = (pub_r000646_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_135 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000646_12 & 63) > 27) {
        stage_v_136 = (pub_r000646_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_136) & 255;
    } else {
        stage_v_136 = (pub_r000646_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_136 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_46 & 63) > 40) {
        stage_v_137 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_137) & 255;
    } else {
        stage_v_137 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_137 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000646_1 & 63) > 41) {
        stage_v_138 = (pub_r000646_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_138) & 255;
    } else {
        stage_v_138 = (pub_r000646_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_138 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000646_6 & 63) > 24) {
        stage_v_139 = (pub_r000646_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_139) & 255;
    } else {
        stage_v_139 = (pub_r000646_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_139 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_64 & 63) > 16) {
        stage_v_140 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_140) & 255;
    } else {
        stage_v_140 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_140 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000646_6 & 63) > 21) {
        stage_v_141 = (pub_r000646_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_141) & 255;
    } else {
        stage_v_141 = (pub_r000646_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_141 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000646_12 & 63) > 36) {
        stage_v_142 = (pub_r000646_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_142) & 255;
    } else {
        stage_v_142 = (pub_r000646_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_142 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000646_2 & 63) > 43) {
        stage_v_143 = (pub_r000646_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_143) & 255;
    } else {
        stage_v_143 = (pub_r000646_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_143 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
