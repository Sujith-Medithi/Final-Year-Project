/*
 * Benchmark Program: R000553
 * Security Family: multi_step_explicit
 * Generator Seed: 555313
 * High Inputs: 20 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000553_5313_0 {
    int coord_z;
    int norm_sq;
    int coord_y;
    int coord_x;
    int heading;
    int buffer[3];
};

struct FilterState_R000553_5313_1 {
    int cutoff;
    short gain_db;
    short prev_in;
    int buffer[3];
};

struct MatrixBlock_R000553_5313_2 {
    unsigned char trace;
    short scale;
    int stride;
    int buffer[3];
};

struct AudioFrame_R000553_5313_3 {
    unsigned char channels;
    int peak;
    unsigned char rms;
    int envelope;
    int sample_rate;
    int buffer[3];
};

union TelemetryField_R000553_5313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000553_5313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000553_5313_0(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int mask_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_34 = local_arr[aux % 3];
    acc = (acc + metric_34 * 2) & 127;
    int parity_47 = (aux + st.buffer[1]) & 3;
    switch (parity_47) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000553_5313_1(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_43 = (aux + st.buffer[1]) & 3;
    switch (quantum_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_24 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_24 > 27) {
        acc = (acc + parity_24 * 2 + 5) & 127;
        aux ^= (parity_24 & 15);
    } else {
        acc = (acc - parity_24 + 11) & 127;
        aux += 3;
    }
    int scale_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000553_5313_2(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000553_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int window_18 = (aux + st.buffer[1]) & 3;
    switch (window_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_78) & 63;
    acc ^= aux;
    int margin_75 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_75 > 15) {
        acc = (acc + margin_75 * 2 + 5) & 127;
        aux ^= (margin_75 & 15);
    } else {
        acc = (acc - margin_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_78 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_78 > 34) {
        acc = (acc + margin_78 * 2 + 5) & 127;
        aux ^= (margin_78 & 15);
    } else {
        acc = (acc - margin_78 + 11) & 127;
        aux += 3;
    }
    int coefficient_26 = (aux + st.buffer[1]) & 3;
    switch (coefficient_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_4(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int weight_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_35) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_31 = local_arr[aux % 3];
    acc = (acc + phase_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_5(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000553_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_34 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_34 > 33) {
        acc = (acc + anchor_34 * 2 + 5) & 127;
        aux ^= (anchor_34 & 15);
    } else {
        acc = (acc - anchor_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_28 = local_arr[aux % 3];
    acc = (acc + checksum_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_6(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_70) & 63;
    acc ^= aux;
    int factor_49 = (aux + st.buffer[1]) & 3;
    switch (factor_49) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_78 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_78 > 31) {
        acc = (acc + parity_78 * 2 + 5) & 127;
        aux ^= (parity_78 & 15);
    } else {
        acc = (acc - parity_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000553_5313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000553_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_46 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_46 > 16) {
        acc = (acc + delta_46 * 2 + 5) & 127;
        aux ^= (delta_46 & 15);
    } else {
        acc = (acc - delta_46 + 11) & 127;
        aux += 3;
    }
    int factor_93 = (aux + st.buffer[1]) & 3;
    switch (factor_93) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000553_5313_8(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_79 = (aux + st.buffer[1]) & 3;
    switch (factor_79) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_17 = local_arr[aux % 3];
    acc = (acc + quotient_17 * 2) & 127;
    int quantum_35 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_35 > 28) {
        acc = (acc + quantum_35 * 2 + 5) & 127;
        aux ^= (quantum_35 & 15);
    } else {
        acc = (acc - quantum_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_9(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_67 = (aux + st.buffer[1]) & 3;
    switch (weight_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_40 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_40 > 49) {
        acc = (acc + sample_40 * 2 + 5) & 127;
        aux ^= (sample_40 & 15);
    } else {
        acc = (acc - sample_40 + 11) & 127;
        aux += 3;
    }
    int anchor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_73 = local_arr[aux % 3];
    acc = (acc + accumulator_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_73 = (aux + st.buffer[1]) & 3;
    switch (factor_73) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_78) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_71 = local_arr[aux % 3];
    acc = (acc + window_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000553_5313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000553_5313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000553_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int margin_22 = local_arr[aux % 3];
    acc = (acc + margin_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_57 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_57 > 37) {
        acc = (acc + checksum_57 * 2 + 5) & 127;
        aux ^= (checksum_57 & 15);
    } else {
        acc = (acc - checksum_57 + 11) & 127;
        aux += 3;
    }
    int anchor_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000553_5313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_15) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_32 = local_arr[aux % 3];
    acc = (acc + checksum_32 * 2) & 127;
    int tally_36 = (aux + st.buffer[1]) & 3;
    switch (tally_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000553_5313_14(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_63) & 63;
    acc ^= aux;
    int phase_80 = (aux + st.buffer[1]) & 3;
    switch (phase_80) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000553_5313_15(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000553_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_86 = local_arr[aux % 3];
    acc = (acc + scale_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000553_5313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_67 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_67 > 13) {
        acc = (acc + bound_67 * 2 + 5) & 127;
        aux ^= (bound_67 & 15);
    } else {
        acc = (acc - bound_67 + 11) & 127;
        aux += 3;
    }
    int delta_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_17(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000553_5313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_50 = (aux + st.buffer[1]) & 3;
    switch (mask_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000553_5313_18(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000553_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_33 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_33 > 42) {
        acc = (acc + delta_33 * 2 + 5) & 127;
        aux ^= (delta_33 & 15);
    } else {
        acc = (acc - delta_33 + 11) & 127;
        aux += 3;
    }
    int quotient_79 = (aux + st.buffer[1]) & 3;
    switch (quotient_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_49 = local_arr[aux % 3];
    acc = (acc + metric_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000553_5313_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000553_5313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int checksum_63 = local_arr[aux % 3];
    acc = (acc + checksum_63 * 2) & 127;
    int vector_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000553_0;
    int sec_r000553_1;
    int sec_r000553_2;
    int sec_r000553_3;
    int sec_r000553_4;
    int sec_r000553_5;
    int sec_r000553_6;
    int sec_r000553_7;
    int sec_r000553_8;
    int sec_r000553_9;
    int sec_r000553_10;
    int sec_r000553_11;
    int sec_r000553_12;
    int sec_r000553_13;
    int sec_r000553_14;
    int sec_r000553_15;
    int sec_r000553_16;
    int sec_r000553_17;
    int sec_r000553_18;
    int sec_r000553_19;
    int pub_r000553_0;
    int pub_r000553_1;
    int pub_r000553_2;
    int pub_r000553_3;
    int pub_r000553_4;
    int pub_r000553_5;
    int pub_r000553_6;
    int pub_r000553_7;
    int pub_r000553_8;
    int pub_r000553_9;
    int pub_r000553_10;
    int pub_r000553_11;
    int pub_r000553_12;
    int pub_r000553_13;
    int pub_r000553_14;
    int pub_r000553_15;
    int pub_r000553_16;
    int pub_r000553_17;
    int pub_r000553_18;
    int pub_r000553_19;
    int pub_r000553_20;
    int pub_r000553_21;
    int pub_r000553_22;
    int pub_r000553_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000553_0 >= -100 && pub_r000553_0 <= 100);
    __CPROVER_assume(pub_r000553_1 >= -100 && pub_r000553_1 <= 100);
    __CPROVER_assume(pub_r000553_2 >= -100 && pub_r000553_2 <= 100);
    __CPROVER_assume(pub_r000553_3 >= -100 && pub_r000553_3 <= 100);
    __CPROVER_assume(pub_r000553_4 >= -100 && pub_r000553_4 <= 100);
    __CPROVER_assume(pub_r000553_5 >= -100 && pub_r000553_5 <= 100);
    __CPROVER_assume(pub_r000553_6 >= -100 && pub_r000553_6 <= 100);
    __CPROVER_assume(pub_r000553_7 >= -100 && pub_r000553_7 <= 100);
    __CPROVER_assume(pub_r000553_8 >= -100 && pub_r000553_8 <= 100);
    __CPROVER_assume(pub_r000553_9 >= -100 && pub_r000553_9 <= 100);
    __CPROVER_assume(pub_r000553_10 >= -100 && pub_r000553_10 <= 100);
    __CPROVER_assume(pub_r000553_11 >= -100 && pub_r000553_11 <= 100);
    __CPROVER_assume(pub_r000553_12 >= -100 && pub_r000553_12 <= 100);
    __CPROVER_assume(pub_r000553_13 >= -100 && pub_r000553_13 <= 100);
    __CPROVER_assume(pub_r000553_14 >= -100 && pub_r000553_14 <= 100);
    __CPROVER_assume(pub_r000553_15 >= -100 && pub_r000553_15 <= 100);
    __CPROVER_assume(pub_r000553_16 >= -100 && pub_r000553_16 <= 100);
    __CPROVER_assume(pub_r000553_17 >= -100 && pub_r000553_17 <= 100);
    __CPROVER_assume(pub_r000553_18 >= -100 && pub_r000553_18 <= 100);
    __CPROVER_assume(pub_r000553_19 >= -100 && pub_r000553_19 <= 100);
    __CPROVER_assume(pub_r000553_20 >= -100 && pub_r000553_20 <= 100);
    __CPROVER_assume(pub_r000553_21 >= -100 && pub_r000553_21 <= 100);
    __CPROVER_assume(pub_r000553_22 >= -100 && pub_r000553_22 <= 100);
    __CPROVER_assume(pub_r000553_23 >= -100 && pub_r000553_23 <= 100);
    __CPROVER_assume(sec_r000553_0 >= 0 && sec_r000553_0 <= 255);
    __CPROVER_assume(sec_r000553_1 >= 0 && sec_r000553_1 <= 255);
    __CPROVER_assume(sec_r000553_2 >= 0 && sec_r000553_2 <= 255);
    __CPROVER_assume(sec_r000553_3 >= 0 && sec_r000553_3 <= 255);
    __CPROVER_assume(sec_r000553_4 >= 0 && sec_r000553_4 <= 255);
    __CPROVER_assume(sec_r000553_5 >= 0 && sec_r000553_5 <= 255);
    __CPROVER_assume(sec_r000553_6 >= 0 && sec_r000553_6 <= 255);
    __CPROVER_assume(sec_r000553_7 >= 0 && sec_r000553_7 <= 255);
    __CPROVER_assume(sec_r000553_8 >= 0 && sec_r000553_8 <= 255);
    __CPROVER_assume(sec_r000553_9 >= 0 && sec_r000553_9 <= 255);
    __CPROVER_assume(sec_r000553_10 >= 0 && sec_r000553_10 <= 255);
    __CPROVER_assume(sec_r000553_11 >= 0 && sec_r000553_11 <= 255);
    __CPROVER_assume(sec_r000553_12 >= 0 && sec_r000553_12 <= 255);
    __CPROVER_assume(sec_r000553_13 >= 0 && sec_r000553_13 <= 255);
    __CPROVER_assume(sec_r000553_14 >= 0 && sec_r000553_14 <= 255);
    __CPROVER_assume(sec_r000553_15 >= 0 && sec_r000553_15 <= 255);
    __CPROVER_assume(sec_r000553_16 >= 0 && sec_r000553_16 <= 255);
    __CPROVER_assume(sec_r000553_17 >= 0 && sec_r000553_17 <= 255);
    __CPROVER_assume(sec_r000553_18 >= 0 && sec_r000553_18 <= 255);
    __CPROVER_assume(sec_r000553_19 >= 0 && sec_r000553_19 <= 255);

    struct Vector3D_R000553_5313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000553_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000553_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000553_0 + 7) & 15;
    struct FilterState_R000553_5313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000553_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000553_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000553_0 + 9) & 15;
    struct MatrixBlock_R000553_5313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000553_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000553_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000553_0 + 11) & 15;
    struct AudioFrame_R000553_5313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000553_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000553_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000553_0 + 13) & 15;

    union TelemetryField_R000553_5313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 12) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 27) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
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
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 28) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 43) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 28) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 43) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 32) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 47) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 17) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 32) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 40) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 55) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 20) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 35) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 16) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 31) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 32) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 47) {
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
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 13) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 28) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 17) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 32) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    int sub_step_69 = (sec_r000553_3 + pub_r000553_13 + 26) & 127;
    int stage_v_69 = (sub_step_69 * 2 + pub_r000553_16) & 127;
    st_var_1.buffer[0] = (stage_v_69 & 15);
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int sub_step_70 = (stage_v_69 + pub_r000553_22 + 32) & 127;
    int stage_v_70 = (sub_step_70 * 2 + pub_r000553_11) & 127;
    st_var_2.buffer[1] = (stage_v_70 & 15);
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int sub_step_71 = (stage_v_70 + pub_r000553_9 + 27) & 127;
    int stage_v_71 = (sub_step_71 * 2 + pub_r000553_11) & 127;
    st_var_3.buffer[2] = (stage_v_71 & 15);
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (stage_v_71 + pub_r000553_4 + 18) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000553_13) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (sub_step_71 + pub_r000553_10 + 18) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000553_23) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (sub_step_70 + pub_r000553_23 + 35) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000553_6) & 127;
    st_var_2.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (sub_step_71 + pub_r000553_8 + 21) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000553_0) & 127;
    st_var_3.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (sub_step_69 + pub_r000553_21 + 21) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000553_21) & 127;
    st_var_0.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (stage_v_76 + pub_r000553_12 + 27) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000553_7) & 127;
    st_var_1.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (stage_v_69 + pub_r000553_11 + 30) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000553_9) & 127;
    st_var_2.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sec_r000553_9 + pub_r000553_16 + 23) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000553_9) & 127;
    st_var_3.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (stage_v_73 + pub_r000553_21 + 21) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000553_10) & 127;
    st_var_0.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000553_17 + pub_r000553_17 + 20) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000553_21) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (stage_v_74 + pub_r000553_23 + 32) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000553_20) & 127;
    st_var_2.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (sub_step_79 + pub_r000553_6 + 21) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000553_5) & 127;
    st_var_3.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sec_r000553_2 + pub_r000553_5 + 12) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000553_8) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sub_step_72 + pub_r000553_10 + 20) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000553_21) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sub_step_77 + pub_r000553_12 + 25) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000553_4) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (sub_step_76 + pub_r000553_1 + 24) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000553_4) & 127;
    st_var_3.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (sec_r000553_3 + pub_r000553_12 + 15) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000553_6) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sub_step_88 + pub_r000553_14 + 11) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000553_20) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sub_step_70 + pub_r000553_1 + 12) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000553_14 + pub_r000553_7 + 28) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000553_11) & 127;
    st_var_3.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sec_r000553_6 + pub_r000553_7 + 31) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000553_0) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sub_step_84 + pub_r000553_9 + 20) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000553_16) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (stage_v_87 + pub_r000553_10 + 12) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000553_14) & 127;
    st_var_2.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sec_r000553_3 + pub_r000553_20 + 8) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000553_11) & 127;
    st_var_3.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000553_8 + pub_r000553_7 + 22) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000553_13) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sec_r000553_18 + pub_r000553_23 + 18) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000553_6) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sub_step_75 + pub_r000553_12 + 18) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000553_14) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sub_step_88 + pub_r000553_9 + 23) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000553_2) & 127;
    st_var_3.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_69 + pub_r000553_5 + 27) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000553_16) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sec_r000553_6 + pub_r000553_19 + 17) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000553_0) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sub_step_97 + pub_r000553_16 + 6) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000553_0) & 127;
    st_var_2.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sub_step_71 + pub_r000553_18 + 10) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000553_21) & 127;
    st_var_3.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_84 + pub_r000553_14 + 20) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000553_12) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sub_step_94 + pub_r000553_13 + 19) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000553_11) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sub_step_83 + pub_r000553_20 + 31) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000553_15) & 127;
    st_var_2.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (stage_v_80 + pub_r000553_16 + 28) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000553_4) & 127;
    st_var_3.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_106 + pub_r000553_9 + 24) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000553_7) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (stage_v_93 + pub_r000553_1 + 16) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000553_20) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sec_r000553_0 + pub_r000553_10 + 13) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000553_2) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sec_r000553_5 + pub_r000553_1 + 22) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000553_5) & 127;
    st_var_3.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000553_18 + pub_r000553_17 + 10) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000553_23) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sub_step_93 + pub_r000553_23 + 8) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000553_14) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sec_r000553_0 + pub_r000553_13 + 16) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000553_14) & 127;
    st_var_2.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_87 + pub_r000553_16 + 29) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000553_7) & 127;
    st_var_3.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_102 + pub_r000553_9 + 13) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000553_4) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sec_r000553_1 + pub_r000553_19 + 29) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000553_3) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_100 + pub_r000553_1 + 33) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sec_r000553_11 + pub_r000553_7 + 33) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000553_22) & 127;
    st_var_3.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000553_3 + pub_r000553_18 + 19) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000553_11) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (stage_v_108 + pub_r000553_12 + 5) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000553_13) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000553_0 + pub_r000553_11 + 33) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000553_22) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000553_4 + pub_r000553_20 + 24) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000553_15) & 127;
    st_var_3.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_90 + pub_r000553_22 + 10) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000553_11) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sub_step_119 + pub_r000553_21 + 24) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000553_9) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (sub_step_100 + pub_r000553_6 + 31) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000553_0) & 127;
    st_var_2.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sec_r000553_9 + pub_r000553_19 + 33) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000553_2) & 127;
    st_var_3.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_77 + pub_r000553_11 + 35) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000553_14) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000553_5 + pub_r000553_0 + 26) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000553_6) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (stage_v_114 + pub_r000553_13 + 24) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000553_7) & 127;
    st_var_2.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (stage_v_96 + pub_r000553_9 + 9) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000553_4) & 127;
    st_var_3.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_73 + pub_r000553_14 + 16) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000553_14) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sub_step_129 + pub_r000553_0 + 31) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000553_20) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (stage_v_105 + pub_r000553_13 + 17) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000553_22) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_99 + pub_r000553_4 + 27) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000553_7) & 127;
    st_var_3.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_81 + pub_r000553_5 + 21) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000553_5) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sub_step_97 + pub_r000553_11 + 15) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000553_17) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (stage_v_126 + pub_r000553_3 + 12) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000553_19) & 127;
    st_var_2.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sec_r000553_10 + pub_r000553_15 + 21) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000553_9) & 127;
    st_var_3.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sub_step_119 + pub_r000553_20 + 8) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000553_20) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sub_step_78 + pub_r000553_19 + 30) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000553_4) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sec_r000553_4 + pub_r000553_14 + 11) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000553_18) & 127;
    st_var_2.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (stage_v_120 + pub_r000553_15 + 32) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000553_23) & 127;
    st_var_3.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (sec_r000553_1 + pub_r000553_16 + 15) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000553_14) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sub_step_141 + pub_r000553_3 + 7) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000553_8) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sec_r000553_12 + pub_r000553_21 + 9) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000553_1) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (stage_v_144 + pub_r000553_2 + 25) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000553_3) & 127;
    st_var_3.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sub_step_132 + pub_r000553_5 + 22) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000553_18) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sub_step_84 + pub_r000553_8 + 23) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000553_0) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (stage_v_93 + pub_r000553_8 + 8) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000553_5) & 127;
    st_var_2.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000553_3 + pub_r000553_4 + 18) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000553_3) & 127;
    st_var_3.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sub_step_77 + pub_r000553_13 + 25) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000553_22) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_93 + pub_r000553_23 + 10) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000553_5) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_80 + pub_r000553_19 + 21) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000553_5) & 127;
    st_var_2.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (stage_v_89 + pub_r000553_12 + 28) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000553_14) & 127;
    st_var_3.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (stage_v_84 + pub_r000553_19 + 16) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000553_13) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sub_step_136 + pub_r000553_0 + 19) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000553_18) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_82 + pub_r000553_7 + 12) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000553_1) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000553_14 + pub_r000553_8 + 26) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000553_1) & 127;
    st_var_3.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sec_r000553_9 + pub_r000553_9 + 35) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000553_16) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sub_step_83 + pub_r000553_14 + 22) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000553_10) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sub_step_127 + pub_r000553_15 + 19) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000553_13) & 127;
    st_var_2.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_138 + pub_r000553_1 + 30) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000553_14) & 127;
    st_var_3.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sub_step_154 + pub_r000553_9 + 15) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000553_23) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_90 + pub_r000553_14 + 6) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000553_10) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (stage_v_117 + pub_r000553_3 + 15) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000553_14) & 127;
    st_var_2.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sec_r000553_8 + pub_r000553_1 + 23) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000553_16) & 127;
    st_var_3.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sec_r000553_5 + pub_r000553_6 + 21) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000553_9) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (stage_v_157 + pub_r000553_2 + 22) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000553_11) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (stage_v_130 + pub_r000553_14 + 12) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000553_22) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000553_0 + pub_r000553_12 + 21) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000553_21) & 127;
    st_var_3.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sub_step_125 + pub_r000553_16 + 29) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000553_3) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (stage_v_112 + pub_r000553_12 + 20) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000553_17) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sub_step_76 + pub_r000553_2 + 21) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000553_7) & 127;
    st_var_2.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (sec_r000553_5 + pub_r000553_3 + 5) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000553_12) & 127;
    st_var_3.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sec_r000553_7 + pub_r000553_2 + 18) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000553_20) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (stage_v_77 + pub_r000553_22 + 13) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000553_15) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sec_r000553_5 + pub_r000553_15 + 20) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000553_2 + pub_r000553_19 + 8) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000553_6) & 127;
    st_var_3.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sec_r000553_17 + pub_r000553_15 + 8) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000553_19) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sec_r000553_0 + pub_r000553_8 + 5) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000553_22) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (stage_v_156 + pub_r000553_9 + 34) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000553_3 + pub_r000553_12 + 8) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000553_11) & 127;
    st_var_3.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sec_r000553_5 + pub_r000553_20 + 22) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000553_8) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sub_step_153 + pub_r000553_6 + 33) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000553_0) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000553_14 + pub_r000553_6 + 16) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000553_13) & 127;
    st_var_2.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sub_step_138 + pub_r000553_17 + 14) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000553_16) & 127;
    st_var_3.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sec_r000553_9 + pub_r000553_16 + 32) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000553_7) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sub_step_121 + pub_r000553_18 + 25) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000553_18) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sec_r000553_8 + pub_r000553_10 + 23) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000553_12) & 127;
    st_var_2.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_129 + pub_r000553_0 + 6) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000553_17) & 127;
    st_var_3.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sub_step_147 + pub_r000553_13 + 18) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000553_21) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (stage_v_147 + pub_r000553_16 + 16) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000553_13) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (sub_step_143 + pub_r000553_19 + 11) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000553_22) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sub_step_118 + pub_r000553_1 + 11) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000553_0) & 127;
    st_var_3.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_174 + pub_r000553_4 + 22) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000553_22) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (stage_v_173 + pub_r000553_16 + 7) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000553_3) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_90 + pub_r000553_13 + 34) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000553_20) & 127;
    st_var_2.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_122 + pub_r000553_23 + 17) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000553_16) & 127;
    st_var_3.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (stage_v_162 + pub_r000553_9 + 20) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000553_18) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (stage_v_119 + pub_r000553_7 + 13) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000553_10) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sec_r000553_12 + pub_r000553_22 + 10) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sub_step_158 + pub_r000553_3 + 31) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000553_15) & 127;
    st_var_3.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (stage_v_115 + pub_r000553_20 + 12) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000553_22) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sub_step_194 + pub_r000553_21 + 31) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000553_14) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sub_step_122 + pub_r000553_7 + 8) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000553_2) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_80 + pub_r000553_18 + 29) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000553_5) & 127;
    st_var_3.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (stage_v_139 + pub_r000553_19 + 8) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000553_6) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sub_step_188 + pub_r000553_11 + 10) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000553_8) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (stage_v_103 + pub_r000553_17 + 28) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000553_0) & 127;
    st_var_2.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000553_4 + pub_r000553_13 + 19) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000553_10) & 127;
    st_var_3.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (stage_v_74 + pub_r000553_18 + 13) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000553_11) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sec_r000553_3 + pub_r000553_14 + 28) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000553_8) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (sub_step_137 + pub_r000553_4 + 6) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000553_2) & 127;
    st_var_2.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_94 + pub_r000553_20 + 35) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000553_21) & 127;
    st_var_3.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (stage_v_154 + pub_r000553_10 + 22) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000553_18) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (stage_v_146 + pub_r000553_16 + 12) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000553_13) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sec_r000553_18 + pub_r000553_8 + 8) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000553_11) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000553_1 + pub_r000553_17 + 13) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000553_7) & 127;
    st_var_3.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sub_step_213 + pub_r000553_15 + 26) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000553_3) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_200 + pub_r000553_4 + 27) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000553_14) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (stage_v_218 + pub_r000553_14 + 27) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000553_17) & 127;
    st_var_2.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (stage_v_167 + pub_r000553_6 + 29) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000553_22) & 127;
    st_var_3.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000553_13 + pub_r000553_3 + 5) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000553_1) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_71 + pub_r000553_21 + 15) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000553_13) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sub_step_92 + pub_r000553_15 + 32) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000553_15) & 127;
    st_var_2.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sec_r000553_9 + pub_r000553_5 + 29) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000553_16) & 127;
    st_var_3.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_105 + pub_r000553_13 + 30) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000553_10) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sub_step_156 + pub_r000553_5 + 21) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000553_5) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000553_6 + pub_r000553_9 + 5) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000553_20) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sec_r000553_15 + pub_r000553_20 + 6) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000553_11) & 127;
    st_var_3.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (stage_v_199 + pub_r000553_16 + 6) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000553_9) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sec_r000553_6 + pub_r000553_8 + 20) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000553_15) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (stage_v_139 + pub_r000553_20 + 33) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000553_15) & 127;
    st_var_2.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_108 + pub_r000553_3 + 29) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000553_16) & 127;
    st_var_3.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_88 + pub_r000553_6 + 17) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000553_18) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_209 + pub_r000553_12 + 32) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000553_10) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (stage_v_120 + pub_r000553_2 + 33) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000553_16) & 127;
    st_var_2.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000553_18 + pub_r000553_4 + 35) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000553_22) & 127;
    st_var_3.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sec_r000553_11 + pub_r000553_12 + 14) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000553_14) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (stage_v_204 + pub_r000553_4 + 32) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000553_23) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000553_7 + pub_r000553_7 + 25) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000553_6) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sec_r000553_3 + pub_r000553_16 + 29) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000553_17) & 127;
    st_var_3.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (stage_v_126 + pub_r000553_4 + 34) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000553_18) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000553_13 + pub_r000553_14 + 31) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000553_20) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (sec_r000553_14 + pub_r000553_19 + 31) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000553_11) & 127;
    st_var_2.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (sub_step_243 + pub_r000553_3 + 30) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000553_15) & 127;
    st_var_3.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sec_r000553_3 + pub_r000553_5 + 9) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000553_19) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
