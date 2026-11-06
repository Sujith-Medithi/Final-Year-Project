/*
 * Benchmark Program: R000453
 * Security Family: multi_step_explicit
 * Generator Seed: 545313
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000453_5313_0 {
    unsigned char stop_bits;
    int baud_rate;
    int port;
    int timeout;
    int buffer[3];
};

struct SensorNode_R000453_5313_1 {
    short offset;
    int gain;
    short threshold;
    short calib;
    short status;
    int buffer[3];
};

struct EventLog_R000453_5313_2 {
    short code;
    int seq;
    int severity;
    int buffer[3];
};

union RegisterBank_R000453_5313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000453_5313_0(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_76 = (aux + st.buffer[1]) & 3;
    switch (quantum_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_73 = local_arr[aux % 3];
    acc = (acc + factor_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_1(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000453_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_46 = (aux + st.buffer[1]) & 3;
    switch (bound_46) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_2(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_38) & 63;
    acc ^= aux;
    int delta_76 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_76 > 24) {
        acc = (acc + delta_76 * 2 + 5) & 127;
        aux ^= (delta_76 & 15);
    } else {
        acc = (acc - delta_76 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_53 = local_arr[aux % 3];
    acc = (acc + scale_53 * 2) & 127;
    int stride_83 = (aux + st.buffer[1]) & 3;
    switch (stride_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000453_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int vector_42 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_42 > 42) {
        acc = (acc + vector_42 * 2 + 5) & 127;
        aux ^= (vector_42 & 15);
    } else {
        acc = (acc - vector_42 + 11) & 127;
        aux += 3;
    }
    int parity_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int threshold_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_53) & 63;
    acc ^= aux;
    int accumulator_63 = (aux + st.buffer[1]) & 3;
    switch (accumulator_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_35 > 24) {
        acc = (acc + anchor_35 * 2 + 5) & 127;
        aux ^= (anchor_35 & 15);
    } else {
        acc = (acc - anchor_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_6(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_76 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_76 > 42) {
        acc = (acc + delta_76 * 2 + 5) & 127;
        aux ^= (delta_76 & 15);
    } else {
        acc = (acc - delta_76 + 11) & 127;
        aux += 3;
    }
    int tally_42 = (aux + st.buffer[1]) & 3;
    switch (tally_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_47 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_47 > 37) {
        acc = (acc + damping_47 * 2 + 5) & 127;
        aux ^= (damping_47 & 15);
    } else {
        acc = (acc - damping_47 + 11) & 127;
        aux += 3;
    }
    int coefficient_63 = (aux + st.buffer[1]) & 3;
    switch (coefficient_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000453_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_40 = (aux + st.buffer[1]) & 3;
    switch (residue_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_84 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_84 > 10) {
        acc = (acc + quotient_84 * 2 + 5) & 127;
        aux ^= (quotient_84 & 15);
    } else {
        acc = (acc - quotient_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_9(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_94 > 28) {
        acc = (acc + anchor_94 * 2 + 5) & 127;
        aux ^= (anchor_94 & 15);
    } else {
        acc = (acc - anchor_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_18 = local_arr[aux % 3];
    acc = (acc + anchor_18 * 2) & 127;
    int pivot_32 = (aux + st.buffer[1]) & 3;
    switch (pivot_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_10(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_38 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_38 > 41) {
        acc = (acc + segment_38 * 2 + 5) & 127;
        aux ^= (segment_38 & 15);
    } else {
        acc = (acc - segment_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_95 = local_arr[aux % 3];
    acc = (acc + scale_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_11(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int index_reg_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_47) & 63;
    acc ^= aux;
    int anchor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_29 > 26) {
        acc = (acc + anchor_29 * 2 + 5) & 127;
        aux ^= (anchor_29 & 15);
    } else {
        acc = (acc - anchor_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_68 = local_arr[aux % 3];
    acc = (acc + residue_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_48) & 63;
    acc ^= aux;
    int metric_42 = (aux + st.buffer[1]) & 3;
    switch (metric_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_13(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int damping_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_81 = local_arr[aux % 3];
    acc = (acc + phase_81 * 2) & 127;
    int tally_88 = (aux + st.buffer[1]) & 3;
    switch (tally_88) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_20 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_20 > 42) {
        acc = (acc + vector_20 * 2 + 5) & 127;
        aux ^= (vector_20 & 15);
    } else {
        acc = (acc - vector_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_14(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_88) & 63;
    acc ^= aux;
    int factor_86 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_86 > 36) {
        acc = (acc + factor_86 * 2 + 5) & 127;
        aux ^= (factor_86 & 15);
    } else {
        acc = (acc - factor_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_72 = local_arr[aux % 3];
    acc = (acc + cursor_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000453_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int cursor_78 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_78 > 18) {
        acc = (acc + cursor_78 * 2 + 5) & 127;
        aux ^= (cursor_78 & 15);
    } else {
        acc = (acc - cursor_78 + 11) & 127;
        aux += 3;
    }
    int bound_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_12 = local_arr[aux % 3];
    acc = (acc + factor_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_81 = (aux + st.buffer[1]) & 3;
    switch (coefficient_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_57 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_57 > 13) {
        acc = (acc + parity_57 * 2 + 5) & 127;
        aux ^= (parity_57 & 15);
    } else {
        acc = (acc - parity_57 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_80 = local_arr[aux % 3];
    acc = (acc + sample_80 * 2) & 127;
    int tally_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_88) & 63;
    acc ^= aux;
    int index_reg_17 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_17 > 36) {
        acc = (acc + index_reg_17 * 2 + 5) & 127;
        aux ^= (index_reg_17 & 15);
    } else {
        acc = (acc - index_reg_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int pivot_29 = local_arr[aux % 3];
    acc = (acc + pivot_29 * 2) & 127;
    int mask_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_19(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_79 = local_arr[aux % 3];
    acc = (acc + accumulator_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000453_5313_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_96 = (aux + st.buffer[1]) & 3;
    switch (anchor_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_15 = local_arr[aux % 3];
    acc = (acc + delta_15 * 2) & 127;
    int quotient_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000453_5313_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000453_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_56 = local_arr[aux % 3];
    acc = (acc + parity_56 * 2) & 127;
    int scale_14 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_14 > 22) {
        acc = (acc + scale_14 * 2 + 5) & 127;
        aux ^= (scale_14 & 15);
    } else {
        acc = (acc - scale_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000453_5313_22(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000453_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_27 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_27 > 39) {
        acc = (acc + metric_27 * 2 + 5) & 127;
        aux ^= (metric_27 & 15);
    } else {
        acc = (acc - metric_27 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_84 = local_arr[aux % 3];
    acc = (acc + tracker_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_42 = (aux + st.buffer[1]) & 3;
    switch (threshold_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000453_0;
    int sec_r000453_1;
    int sec_r000453_2;
    int sec_r000453_3;
    int sec_r000453_4;
    int sec_r000453_5;
    int sec_r000453_6;
    int sec_r000453_7;
    int sec_r000453_8;
    int sec_r000453_9;
    int sec_r000453_10;
    int sec_r000453_11;
    int sec_r000453_12;
    int sec_r000453_13;
    int sec_r000453_14;
    int sec_r000453_15;
    int sec_r000453_16;
    int sec_r000453_17;
    int sec_r000453_18;
    int sec_r000453_19;
    int sec_r000453_20;
    int sec_r000453_21;
    int sec_r000453_22;
    int sec_r000453_23;
    int pub_r000453_0;
    int pub_r000453_1;
    int pub_r000453_2;
    int pub_r000453_3;
    int pub_r000453_4;
    int pub_r000453_5;
    int pub_r000453_6;
    int pub_r000453_7;
    int pub_r000453_8;
    int pub_r000453_9;
    int pub_r000453_10;
    int pub_r000453_11;
    int pub_r000453_12;
    int pub_r000453_13;
    int pub_r000453_14;
    int pub_r000453_15;
    int pub_r000453_16;
    int pub_r000453_17;
    int pub_r000453_18;
    int pub_r000453_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000453_0 >= -100 && pub_r000453_0 <= 100);
    __CPROVER_assume(pub_r000453_1 >= -100 && pub_r000453_1 <= 100);
    __CPROVER_assume(pub_r000453_2 >= -100 && pub_r000453_2 <= 100);
    __CPROVER_assume(pub_r000453_3 >= -100 && pub_r000453_3 <= 100);
    __CPROVER_assume(pub_r000453_4 >= -100 && pub_r000453_4 <= 100);
    __CPROVER_assume(pub_r000453_5 >= -100 && pub_r000453_5 <= 100);
    __CPROVER_assume(pub_r000453_6 >= -100 && pub_r000453_6 <= 100);
    __CPROVER_assume(pub_r000453_7 >= -100 && pub_r000453_7 <= 100);
    __CPROVER_assume(pub_r000453_8 >= -100 && pub_r000453_8 <= 100);
    __CPROVER_assume(pub_r000453_9 >= -100 && pub_r000453_9 <= 100);
    __CPROVER_assume(pub_r000453_10 >= -100 && pub_r000453_10 <= 100);
    __CPROVER_assume(pub_r000453_11 >= -100 && pub_r000453_11 <= 100);
    __CPROVER_assume(pub_r000453_12 >= -100 && pub_r000453_12 <= 100);
    __CPROVER_assume(pub_r000453_13 >= -100 && pub_r000453_13 <= 100);
    __CPROVER_assume(pub_r000453_14 >= -100 && pub_r000453_14 <= 100);
    __CPROVER_assume(pub_r000453_15 >= -100 && pub_r000453_15 <= 100);
    __CPROVER_assume(pub_r000453_16 >= -100 && pub_r000453_16 <= 100);
    __CPROVER_assume(pub_r000453_17 >= -100 && pub_r000453_17 <= 100);
    __CPROVER_assume(pub_r000453_18 >= -100 && pub_r000453_18 <= 100);
    __CPROVER_assume(pub_r000453_19 >= -100 && pub_r000453_19 <= 100);
    __CPROVER_assume(sec_r000453_0 >= 0 && sec_r000453_0 <= 255);
    __CPROVER_assume(sec_r000453_1 >= 0 && sec_r000453_1 <= 255);
    __CPROVER_assume(sec_r000453_2 >= 0 && sec_r000453_2 <= 255);
    __CPROVER_assume(sec_r000453_3 >= 0 && sec_r000453_3 <= 255);
    __CPROVER_assume(sec_r000453_4 >= 0 && sec_r000453_4 <= 255);
    __CPROVER_assume(sec_r000453_5 >= 0 && sec_r000453_5 <= 255);
    __CPROVER_assume(sec_r000453_6 >= 0 && sec_r000453_6 <= 255);
    __CPROVER_assume(sec_r000453_7 >= 0 && sec_r000453_7 <= 255);
    __CPROVER_assume(sec_r000453_8 >= 0 && sec_r000453_8 <= 255);
    __CPROVER_assume(sec_r000453_9 >= 0 && sec_r000453_9 <= 255);
    __CPROVER_assume(sec_r000453_10 >= 0 && sec_r000453_10 <= 255);
    __CPROVER_assume(sec_r000453_11 >= 0 && sec_r000453_11 <= 255);
    __CPROVER_assume(sec_r000453_12 >= 0 && sec_r000453_12 <= 255);
    __CPROVER_assume(sec_r000453_13 >= 0 && sec_r000453_13 <= 255);
    __CPROVER_assume(sec_r000453_14 >= 0 && sec_r000453_14 <= 255);
    __CPROVER_assume(sec_r000453_15 >= 0 && sec_r000453_15 <= 255);
    __CPROVER_assume(sec_r000453_16 >= 0 && sec_r000453_16 <= 255);
    __CPROVER_assume(sec_r000453_17 >= 0 && sec_r000453_17 <= 255);
    __CPROVER_assume(sec_r000453_18 >= 0 && sec_r000453_18 <= 255);
    __CPROVER_assume(sec_r000453_19 >= 0 && sec_r000453_19 <= 255);
    __CPROVER_assume(sec_r000453_20 >= 0 && sec_r000453_20 <= 255);
    __CPROVER_assume(sec_r000453_21 >= 0 && sec_r000453_21 <= 255);
    __CPROVER_assume(sec_r000453_22 >= 0 && sec_r000453_22 <= 255);
    __CPROVER_assume(sec_r000453_23 >= 0 && sec_r000453_23 <= 255);

    struct DeviceConfig_R000453_5313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000453_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000453_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000453_0 + 7) & 15;
    struct SensorNode_R000453_5313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000453_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000453_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000453_0 + 9) & 15;
    struct EventLog_R000453_5313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000453_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000453_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000453_0 + 11) & 15;

    union RegisterBank_R000453_5313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 24) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 39) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 40) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 55) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

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
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 17) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 32) {
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
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 31) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 46) {
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
    int stage_v_29 = (st_var_2.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 20) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 35) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 35) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 50) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 20) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 35) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

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
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 28) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 43) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int sub_step_66 = (sec_r000453_1 + pub_r000453_12 + 15) & 127;
    int stage_v_66 = (sub_step_66 * 2 + pub_r000453_1) & 127;
    st_var_0.buffer[0] = (stage_v_66 & 15);
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int sub_step_67 = (sec_r000453_2 + pub_r000453_15 + 9) & 127;
    int stage_v_67 = (sub_step_67 * 2 + pub_r000453_2) & 127;
    st_var_1.buffer[1] = (stage_v_67 & 15);
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int sub_step_68 = (stage_v_67 + pub_r000453_11 + 20) & 127;
    int stage_v_68 = (sub_step_68 * 2 + pub_r000453_19) & 127;
    st_var_2.buffer[2] = (stage_v_68 & 15);
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int sub_step_69 = (stage_v_67 + pub_r000453_12 + 11) & 127;
    int stage_v_69 = (sub_step_69 * 2 + pub_r000453_9) & 127;
    st_var_0.buffer[0] = (stage_v_69 & 15);
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int sub_step_70 = (stage_v_66 + pub_r000453_6 + 31) & 127;
    int stage_v_70 = (sub_step_70 * 2 + pub_r000453_0) & 127;
    st_var_1.buffer[1] = (stage_v_70 & 15);
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int sub_step_71 = (stage_v_67 + pub_r000453_12 + 22) & 127;
    int stage_v_71 = (sub_step_71 * 2 + pub_r000453_10) & 127;
    st_var_2.buffer[2] = (stage_v_71 & 15);
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (stage_v_67 + pub_r000453_0 + 8) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000453_19) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (stage_v_67 + pub_r000453_19 + 34) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000453_18) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (sub_step_68 + pub_r000453_17 + 15) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000453_6) & 127;
    st_var_2.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (sec_r000453_18 + pub_r000453_14 + 7) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000453_6) & 127;
    st_var_0.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (sub_step_69 + pub_r000453_6 + 7) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000453_16) & 127;
    st_var_1.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (sub_step_70 + pub_r000453_2 + 14) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000453_17) & 127;
    st_var_2.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (stage_v_70 + pub_r000453_15 + 31) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000453_4) & 127;
    st_var_0.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sec_r000453_2 + pub_r000453_10 + 13) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (sub_step_73 + pub_r000453_12 + 16) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000453_10) & 127;
    st_var_2.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (stage_v_74 + pub_r000453_15 + 28) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sub_step_74 + pub_r000453_0 + 12) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (stage_v_73 + pub_r000453_16 + 20) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sec_r000453_18 + pub_r000453_11 + 32) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sec_r000453_10 + pub_r000453_14 + 10) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000453_1) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (stage_v_79 + pub_r000453_8 + 17) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000453_11) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (stage_v_85 + pub_r000453_0 + 30) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (stage_v_74 + pub_r000453_13 + 24) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000453_6) & 127;
    st_var_1.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (stage_v_83 + pub_r000453_7 + 9) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sub_step_78 + pub_r000453_5 + 26) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000453_8) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (stage_v_82 + pub_r000453_15 + 29) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000453_4) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sub_step_87 + pub_r000453_15 + 10) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000453_0) & 127;
    st_var_2.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sec_r000453_4 + pub_r000453_0 + 10) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000453_9) & 127;
    st_var_0.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (stage_v_83 + pub_r000453_17 + 29) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000453_3) & 127;
    st_var_1.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (stage_v_66 + pub_r000453_0 + 35) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000453_13) & 127;
    st_var_2.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000453_1 + pub_r000453_14 + 35) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000453_17) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sub_step_81 + pub_r000453_12 + 30) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sec_r000453_17 + pub_r000453_12 + 6) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000453_3) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sub_step_72 + pub_r000453_4 + 12) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000453_17) & 127;
    st_var_0.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sec_r000453_15 + pub_r000453_17 + 31) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000453_3) & 127;
    st_var_1.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sec_r000453_5 + pub_r000453_18 + 33) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000453_19) & 127;
    st_var_2.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000453_3 + pub_r000453_18 + 20) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000453_12) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sub_step_92 + pub_r000453_0 + 33) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000453_4) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_80 + pub_r000453_1 + 32) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sec_r000453_6 + pub_r000453_1 + 22) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000453_13) & 127;
    st_var_0.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sec_r000453_12 + pub_r000453_14 + 9) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (stage_v_70 + pub_r000453_7 + 22) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000453_12) & 127;
    st_var_2.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sec_r000453_7 + pub_r000453_1 + 7) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000453_14) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sec_r000453_14 + pub_r000453_5 + 35) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sec_r000453_8 + pub_r000453_8 + 17) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000453_5) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sub_step_76 + pub_r000453_19 + 22) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000453_9) & 127;
    st_var_0.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (stage_v_69 + pub_r000453_11 + 6) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (stage_v_112 + pub_r000453_18 + 11) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sub_step_79 + pub_r000453_16 + 6) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000453_9) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_75 + pub_r000453_0 + 31) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sub_step_82 + pub_r000453_8 + 25) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_83 + pub_r000453_5 + 25) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000453_4) & 127;
    st_var_0.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_80 + pub_r000453_8 + 23) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000453_18) & 127;
    st_var_1.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sec_r000453_20 + pub_r000453_15 + 30) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000453_9 + pub_r000453_9 + 13) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sub_step_99 + pub_r000453_6 + 7) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000453_3) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000453_20 + pub_r000453_17 + 24) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000453_8) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000453_11 + pub_r000453_0 + 11) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000453_3) & 127;
    st_var_0.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_96 + pub_r000453_8 + 14) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000453_13) & 127;
    st_var_1.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (stage_v_111 + pub_r000453_15 + 23) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000453_10) & 127;
    st_var_2.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_67 + pub_r000453_2 + 21) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000453_0) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sub_step_81 + pub_r000453_18 + 20) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000453_8) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (sec_r000453_22 + pub_r000453_7 + 16) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (stage_v_104 + pub_r000453_10 + 13) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000453_16) & 127;
    st_var_0.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (stage_v_111 + pub_r000453_17 + 19) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000453_4 + pub_r000453_3 + 20) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000453_16) & 127;
    st_var_2.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_77 + pub_r000453_19 + 15) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000453_15) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_79 + pub_r000453_2 + 6) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000453_1) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (stage_v_75 + pub_r000453_10 + 7) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000453_2) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sub_step_105 + pub_r000453_1 + 33) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000453_4) & 127;
    st_var_0.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_113 + pub_r000453_7 + 34) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sub_step_130 + pub_r000453_10 + 20) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000453_8) & 127;
    st_var_2.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sec_r000453_20 + pub_r000453_17 + 26) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000453_10) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_75 + pub_r000453_17 + 34) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000453_11) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (stage_v_131 + pub_r000453_11 + 35) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000453_5) & 127;
    st_var_2.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (stage_v_100 + pub_r000453_12 + 27) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sub_step_72 + pub_r000453_11 + 32) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sub_step_129 + pub_r000453_2 + 5) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000453_11) & 127;
    st_var_2.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_68 + pub_r000453_17 + 5) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000453_3) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_112 + pub_r000453_14 + 8) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000453_13) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_95 + pub_r000453_7 + 30) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (stage_v_128 + pub_r000453_13 + 29) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000453_7 + pub_r000453_1 + 6) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000453_6) & 127;
    st_var_1.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_73 + pub_r000453_7 + 14) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (stage_v_129 + pub_r000453_3 + 10) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000453_1) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000453_6 + pub_r000453_9 + 31) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000453_2) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (stage_v_79 + pub_r000453_7 + 11) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000453_15) & 127;
    st_var_2.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (stage_v_97 + pub_r000453_3 + 30) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000453_0) & 127;
    st_var_0.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_129 + pub_r000453_18 + 23) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sub_step_125 + pub_r000453_1 + 21) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000453_13) & 127;
    st_var_2.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (stage_v_134 + pub_r000453_3 + 35) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sub_step_133 + pub_r000453_0 + 21) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sec_r000453_22 + pub_r000453_3 + 33) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000453_17) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sub_step_143 + pub_r000453_5 + 9) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000453_7) & 127;
    st_var_0.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (stage_v_94 + pub_r000453_4 + 16) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000453_13) & 127;
    st_var_1.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (stage_v_102 + pub_r000453_19 + 13) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sec_r000453_16 + pub_r000453_14 + 35) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000453_1) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_101 + pub_r000453_0 + 25) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sub_step_126 + pub_r000453_9 + 16) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000453_16) & 127;
    st_var_2.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_124 + pub_r000453_11 + 9) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sec_r000453_5 + pub_r000453_19 + 23) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000453_18) & 127;
    st_var_1.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (stage_v_161 + pub_r000453_13 + 25) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000453_10) & 127;
    st_var_2.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (stage_v_76 + pub_r000453_16 + 5) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (stage_v_74 + pub_r000453_16 + 6) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000453_15) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sec_r000453_6 + pub_r000453_18 + 11) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000453_0) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000453_11 + pub_r000453_9 + 35) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000453_11) & 127;
    st_var_0.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sec_r000453_12 + pub_r000453_4 + 16) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000453_7) & 127;
    st_var_1.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (stage_v_115 + pub_r000453_3 + 15) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (stage_v_87 + pub_r000453_14 + 28) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000453_9) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_85 + pub_r000453_7 + 30) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (stage_v_170 + pub_r000453_7 + 21) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000453_15) & 127;
    st_var_2.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sec_r000453_15 + pub_r000453_12 + 21) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (stage_v_118 + pub_r000453_14 + 23) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000453_17) & 127;
    st_var_1.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sub_step_131 + pub_r000453_19 + 26) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000453_2) & 127;
    st_var_2.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (stage_v_132 + pub_r000453_17 + 7) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000453_17) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sub_step_169 + pub_r000453_5 + 23) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sec_r000453_5 + pub_r000453_9 + 12) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sub_step_152 + pub_r000453_1 + 14) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000453_16) & 127;
    st_var_0.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (stage_v_115 + pub_r000453_16 + 27) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000453_4) & 127;
    st_var_1.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (stage_v_141 + pub_r000453_12 + 25) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sub_step_67 + pub_r000453_14 + 30) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sub_step_115 + pub_r000453_8 + 7) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (stage_v_76 + pub_r000453_19 + 11) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000453_2) & 127;
    st_var_2.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sec_r000453_14 + pub_r000453_0 + 11) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000453_1) & 127;
    st_var_0.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sub_step_168 + pub_r000453_17 + 8) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000453_15) & 127;
    st_var_1.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (sec_r000453_8 + pub_r000453_12 + 14) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sub_step_134 + pub_r000453_18 + 15) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (stage_v_187 + pub_r000453_13 + 34) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000453_11) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (sub_step_112 + pub_r000453_4 + 15) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000453_17) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000453_10 + pub_r000453_18 + 31) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sec_r000453_19 + pub_r000453_17 + 24) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000453_19) & 127;
    st_var_1.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sec_r000453_13 + pub_r000453_14 + 15) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sec_r000453_6 + pub_r000453_1 + 25) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000453_7) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_132 + pub_r000453_5 + 28) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000453_18) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (stage_v_185 + pub_r000453_0 + 7) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000453_9) & 127;
    st_var_2.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000453_4 + pub_r000453_11 + 10) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000453_13) & 127;
    st_var_0.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (stage_v_143 + pub_r000453_14 + 27) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000453_14) & 127;
    st_var_1.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sub_step_66 + pub_r000453_14 + 18) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000453_4 + pub_r000453_19 + 9) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000453_10) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sub_step_169 + pub_r000453_0 + 13) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000453_13) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (stage_v_81 + pub_r000453_13 + 26) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000453_8) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_135 + pub_r000453_14 + 28) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000453_5 + pub_r000453_9 + 7) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000453_6) & 127;
    st_var_1.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sec_r000453_18 + pub_r000453_6 + 6) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000453_5) & 127;
    st_var_2.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sub_step_82 + pub_r000453_0 + 24) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000453_7) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (stage_v_89 + pub_r000453_12 + 23) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sub_step_124 + pub_r000453_8 + 13) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000453_13) & 127;
    st_var_2.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_122 + pub_r000453_6 + 6) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000453_1) & 127;
    st_var_0.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (sub_step_117 + pub_r000453_11 + 25) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (stage_v_156 + pub_r000453_2 + 31) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000453_2) & 127;
    st_var_2.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000453_8 + pub_r000453_1 + 23) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000453_10) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (stage_v_154 + pub_r000453_1 + 7) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sub_step_81 + pub_r000453_15 + 14) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000453_11) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000453_5 + pub_r000453_17 + 12) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000453_8) & 127;
    st_var_0.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_181 + pub_r000453_1 + 17) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000453_18) & 127;
    st_var_1.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sec_r000453_10 + pub_r000453_2 + 14) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000453_6) & 127;
    st_var_2.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_139 + pub_r000453_15 + 15) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000453_11) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000453_22 + pub_r000453_7 + 10) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000453_8) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (stage_v_200 + pub_r000453_6 + 9) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000453_12) & 127;
    st_var_2.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sec_r000453_9 + pub_r000453_18 + 19) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000453_15) & 127;
    st_var_0.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (stage_v_73 + pub_r000453_12 + 8) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000453_2) & 127;
    st_var_1.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sub_step_223 + pub_r000453_15 + 22) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000453_17) & 127;
    st_var_2.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_90 + pub_r000453_16 + 7) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000453_11) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (stage_v_212 + pub_r000453_15 + 16) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000453_13) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000453_14 + pub_r000453_16 + 14) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000453_17) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (stage_v_119 + pub_r000453_13 + 17) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (stage_v_186 + pub_r000453_7 + 14) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000453_11) & 127;
    st_var_1.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sub_step_148 + pub_r000453_5 + 25) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000453_14) & 127;
    st_var_2.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sub_step_120 + pub_r000453_9 + 6) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000453_10) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sec_r000453_3 + pub_r000453_2 + 27) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000453_11) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_133 + pub_r000453_1 + 23) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000453_10) & 127;
    st_var_2.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_217 + pub_r000453_5 + 29) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000453_2) & 127;
    st_var_0.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (stage_v_66 + pub_r000453_7 + 16) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000453_5) & 127;
    st_var_1.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sub_step_120 + pub_r000453_8 + 25) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000453_18) & 127;
    st_var_2.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sec_r000453_14 + pub_r000453_9 + 28) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000453_15) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_83 + pub_r000453_14 + 26) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000453_5) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000453_7 + pub_r000453_9 + 10) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000453_3) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sub_step_157 + pub_r000453_7 + 24) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000453_18) & 127;
    st_var_0.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (sub_step_228 + pub_r000453_5 + 8) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000453_7) & 127;
    st_var_1.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sub_step_87 + pub_r000453_13 + 21) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000453_5) & 127;
    st_var_2.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (sec_r000453_3 + pub_r000453_18 + 15) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000453_15) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (stage_v_225 + pub_r000453_2 + 22) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000453_11) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sub_step_109 + pub_r000453_9 + 11) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000453_15) & 127;
    st_var_2.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (stage_v_76 + pub_r000453_2 + 27) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000453_3) & 127;
    st_var_0.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (sec_r000453_5 + pub_r000453_19 + 17) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000453_8) & 127;
    st_var_1.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (stage_v_249 + pub_r000453_11 + 8) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000453_7) & 127;
    st_var_2.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sec_r000453_15 + pub_r000453_14 + 23) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000453_12) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (sub_step_172 + pub_r000453_6 + 12) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sub_step_235 + pub_r000453_0 + 5) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000453_4) & 127;
    st_var_2.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sub_step_159 + pub_r000453_8 + 27) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000453_13) & 127;
    st_var_0.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (stage_v_154 + pub_r000453_14 + 28) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000453_7) & 127;
    st_var_1.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (stage_v_196 + pub_r000453_17 + 9) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000453_9) & 127;
    st_var_2.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (sec_r000453_19 + pub_r000453_3 + 24) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000453_14) & 127;
    st_var_0.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (sec_r000453_7 + pub_r000453_18 + 25) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000453_5) & 127;
    st_var_1.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (sub_step_193 + pub_r000453_18 + 18) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000453_1) & 127;
    st_var_2.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int sub_step_261 = (sec_r000453_13 + pub_r000453_15 + 24) & 127;
    int stage_v_261 = (sub_step_261 * 2 + pub_r000453_14) & 127;
    st_var_0.buffer[0] = (stage_v_261 & 15);
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int sub_step_262 = (sec_r000453_4 + pub_r000453_13 + 11) & 127;
    int stage_v_262 = (sub_step_262 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_262 & 15);
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int sub_step_263 = (stage_v_67 + pub_r000453_14 + 10) & 127;
    int stage_v_263 = (sub_step_263 * 2 + pub_r000453_13) & 127;
    st_var_2.buffer[2] = (stage_v_263 & 15);
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int sub_step_264 = (stage_v_248 + pub_r000453_11 + 6) & 127;
    int stage_v_264 = (sub_step_264 * 2 + pub_r000453_5) & 127;
    st_var_0.buffer[0] = (stage_v_264 & 15);
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int sub_step_265 = (sec_r000453_17 + pub_r000453_1 + 20) & 127;
    int stage_v_265 = (sub_step_265 * 2 + pub_r000453_15) & 127;
    st_var_1.buffer[1] = (stage_v_265 & 15);
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int sub_step_266 = (sec_r000453_8 + pub_r000453_6 + 15) & 127;
    int stage_v_266 = (sub_step_266 * 2 + pub_r000453_19) & 127;
    st_var_2.buffer[2] = (stage_v_266 & 15);
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int sub_step_267 = (stage_v_222 + pub_r000453_1 + 28) & 127;
    int stage_v_267 = (sub_step_267 * 2 + pub_r000453_12) & 127;
    st_var_0.buffer[0] = (stage_v_267 & 15);
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int sub_step_268 = (sec_r000453_13 + pub_r000453_4 + 15) & 127;
    int stage_v_268 = (sub_step_268 * 2 + pub_r000453_3) & 127;
    st_var_1.buffer[1] = (stage_v_268 & 15);
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int sub_step_269 = (stage_v_198 + pub_r000453_7 + 14) & 127;
    int stage_v_269 = (sub_step_269 * 2 + pub_r000453_11) & 127;
    st_var_2.buffer[2] = (stage_v_269 & 15);
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int sub_step_270 = (sec_r000453_1 + pub_r000453_10 + 24) & 127;
    int stage_v_270 = (sub_step_270 * 2 + pub_r000453_13) & 127;
    st_var_0.buffer[0] = (stage_v_270 & 15);
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int sub_step_271 = (stage_v_208 + pub_r000453_10 + 8) & 127;
    int stage_v_271 = (sub_step_271 * 2 + pub_r000453_12) & 127;
    st_var_1.buffer[1] = (stage_v_271 & 15);
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int sub_step_272 = (stage_v_156 + pub_r000453_15 + 33) & 127;
    int stage_v_272 = (sub_step_272 * 2 + pub_r000453_8) & 127;
    st_var_2.buffer[2] = (stage_v_272 & 15);
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int sub_step_273 = (stage_v_225 + pub_r000453_17 + 8) & 127;
    int stage_v_273 = (sub_step_273 * 2 + pub_r000453_15) & 127;
    st_var_0.buffer[0] = (stage_v_273 & 15);
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int sub_step_274 = (sec_r000453_20 + pub_r000453_10 + 19) & 127;
    int stage_v_274 = (sub_step_274 * 2 + pub_r000453_10) & 127;
    st_var_1.buffer[1] = (stage_v_274 & 15);
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int sub_step_275 = (sub_step_233 + pub_r000453_17 + 22) & 127;
    int stage_v_275 = (sub_step_275 * 2 + pub_r000453_15) & 127;
    st_var_2.buffer[2] = (stage_v_275 & 15);
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int sub_step_276 = (sec_r000453_22 + pub_r000453_15 + 29) & 127;
    int stage_v_276 = (sub_step_276 * 2 + pub_r000453_8) & 127;
    st_var_0.buffer[0] = (stage_v_276 & 15);
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int sub_step_277 = (sub_step_216 + pub_r000453_18 + 17) & 127;
    int stage_v_277 = (sub_step_277 * 2 + pub_r000453_16) & 127;
    st_var_1.buffer[1] = (stage_v_277 & 15);
    out_sink = (out_sink + stage_v_277) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
