/*
 * Benchmark Program: R000997
 * Security Family: nested_implicit_flow
 * Generator Seed: 601724
 * High Inputs: 16 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000997_1724_0 {
    unsigned char coord_y;
    short heading;
    short coord_z;
    int norm_sq;
    int pitch;
    int buffer[3];
};

struct CipherContext_R000997_1724_1 {
    unsigned char counter;
    int tag;
    int round_key;
    int iv;
    short nonce;
    int flags;
    int buffer[3];
};

struct AudioFrame_R000997_1724_2 {
    short rms;
    int peak;
    short sample_rate;
    int envelope;
    int gain;
    int buffer[3];
};

union PacketPayload_R000997_1724_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000997_1724_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000997_1724_0(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int accumulator_77 = local_arr[aux % 3];
    acc = (acc + accumulator_77 * 2) & 127;
    int tally_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_64) & 63;
    acc ^= aux;
    int mask_40 = (aux + st.buffer[1]) & 3;
    switch (mask_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_15 = (aux + st.buffer[1]) & 3;
    switch (coefficient_15) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_14 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_14 > 37) {
        acc = (acc + segment_14 * 2 + 5) & 127;
        aux ^= (segment_14 & 15);
    } else {
        acc = (acc - segment_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_16 = local_arr[aux % 3];
    acc = (acc + delta_16 * 2) & 127;
    int vector_64 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_64 > 12) {
        acc = (acc + vector_64 * 2 + 5) & 127;
        aux ^= (vector_64 & 15);
    } else {
        acc = (acc - vector_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int pivot_99 = local_arr[aux % 3];
    acc = (acc + pivot_99 * 2) & 127;
    int tally_68 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_68 > 23) {
        acc = (acc + tally_68 * 2 + 5) & 127;
        aux ^= (tally_68 & 15);
    } else {
        acc = (acc - tally_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000997_1724_4(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_62 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_62 > 29) {
        acc = (acc + anchor_62 * 2 + 5) & 127;
        aux ^= (anchor_62 & 15);
    } else {
        acc = (acc - anchor_62 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_51 = local_arr[aux % 3];
    acc = (acc + bound_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_5(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int pivot_22 = local_arr[aux % 3];
    acc = (acc + pivot_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_23 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_23 > 47) {
        acc = (acc + weight_23 * 2 + 5) & 127;
        aux ^= (weight_23 & 15);
    } else {
        acc = (acc - weight_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_6(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_87 = (aux + st.buffer[1]) & 3;
    switch (vector_87) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_16 > 17) {
        acc = (acc + cursor_16 * 2 + 5) & 127;
        aux ^= (cursor_16 & 15);
    } else {
        acc = (acc - cursor_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_13 = local_arr[aux % 3];
    acc = (acc + parity_13 * 2) & 127;
    int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000997_1724_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_40 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_40 > 18) {
        acc = (acc + offset_40 * 2 + 5) & 127;
        aux ^= (offset_40 & 15);
    } else {
        acc = (acc - offset_40 + 11) & 127;
        aux += 3;
    }
    int bound_27 = (aux + st.buffer[1]) & 3;
    switch (bound_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_76 = (aux + st.buffer[1]) & 3;
    switch (anchor_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_48) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_65 = local_arr[aux % 3];
    acc = (acc + segment_65 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_10(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int vector_51 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_51 > 47) {
        acc = (acc + vector_51 * 2 + 5) & 127;
        aux ^= (vector_51 & 15);
    } else {
        acc = (acc - vector_51 + 11) & 127;
        aux += 3;
    }
    int pivot_55 = (aux + st.buffer[1]) & 3;
    switch (pivot_55) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_44 = local_arr[aux % 3];
    acc = (acc + delta_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_11(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int accumulator_18 = local_arr[aux % 3];
    acc = (acc + accumulator_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_71) & 63;
    acc ^= aux;
    int offset_51 = (aux + st.buffer[1]) & 3;
    switch (offset_51) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int mask_29 = local_arr[aux % 3];
    acc = (acc + mask_29 * 2) & 127;
    int damping_81 = (aux + st.buffer[1]) & 3;
    switch (damping_81) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_66 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_66 > 40) {
        acc = (acc + tracker_66 * 2 + 5) & 127;
        aux ^= (tracker_66 & 15);
    } else {
        acc = (acc - tracker_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int bound_66 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_66 > 18) {
        acc = (acc + bound_66 * 2 + 5) & 127;
        aux ^= (bound_66 & 15);
    } else {
        acc = (acc - bound_66 + 11) & 127;
        aux += 3;
    }
    int segment_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_17 = local_arr[aux % 3];
    acc = (acc + quantum_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_14(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_63 = (aux + st.buffer[1]) & 3;
    switch (anchor_63) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_31 > 12) {
        acc = (acc + cursor_31 * 2 + 5) & 127;
        aux ^= (cursor_31 & 15);
    } else {
        acc = (acc - cursor_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_56 = local_arr[aux % 3];
    acc = (acc + accumulator_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_15(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_52 = (aux + st.buffer[1]) & 3;
    switch (quantum_52) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000997_1724_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int bound_65 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_65 > 16) {
        acc = (acc + bound_65 * 2 + 5) & 127;
        aux ^= (bound_65 & 15);
    } else {
        acc = (acc - bound_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_11 = local_arr[aux % 3];
    acc = (acc + sample_11 * 2) & 127;
    int quantum_67 = (aux + st.buffer[1]) & 3;
    switch (quantum_67) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000997_1724_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int accumulator_78 = (aux + st.buffer[1]) & 3;
    switch (accumulator_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_25 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_25 > 20) {
        acc = (acc + mask_25 * 2 + 5) & 127;
        aux ^= (mask_25 & 15);
    } else {
        acc = (acc - mask_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_18(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_69 = (aux + st.buffer[1]) & 3;
    switch (mask_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_19(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_85 = (aux + st.buffer[1]) & 3;
    switch (quantum_85) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_86 = local_arr[aux % 3];
    acc = (acc + vector_86 * 2) & 127;
    int pivot_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_22) & 63;
    acc ^= aux;
    int quotient_30 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_30 > 38) {
        acc = (acc + quotient_30 * 2 + 5) & 127;
        aux ^= (quotient_30 & 15);
    } else {
        acc = (acc - quotient_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_38 = local_arr[aux % 3];
    acc = (acc + threshold_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_59 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_59 > 25) {
        acc = (acc + checksum_59 * 2 + 5) & 127;
        aux ^= (checksum_59 & 15);
    } else {
        acc = (acc - checksum_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000997_1724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_72 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_72 > 25) {
        acc = (acc + damping_72 * 2 + 5) & 127;
        aux ^= (damping_72 & 15);
    } else {
        acc = (acc - damping_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_51 = local_arr[aux % 3];
    acc = (acc + mask_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000997_1724_22(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000997_1724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_76 = (aux + st.buffer[1]) & 3;
    switch (quotient_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_65 = local_arr[aux % 3];
    acc = (acc + checksum_65 * 2) & 127;
    int sample_53 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_53 > 18) {
        acc = (acc + sample_53 * 2 + 5) & 127;
        aux ^= (sample_53 & 15);
    } else {
        acc = (acc - sample_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000997_1724_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000997_1724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_72) & 63;
    acc ^= aux;
    int cursor_13 = (aux + st.buffer[1]) & 3;
    switch (cursor_13) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000997_0;
    int sec_r000997_1;
    int sec_r000997_2;
    int sec_r000997_3;
    int sec_r000997_4;
    int sec_r000997_5;
    int sec_r000997_6;
    int sec_r000997_7;
    int sec_r000997_8;
    int sec_r000997_9;
    int sec_r000997_10;
    int sec_r000997_11;
    int sec_r000997_12;
    int sec_r000997_13;
    int sec_r000997_14;
    int sec_r000997_15;
    int pub_r000997_0;
    int pub_r000997_1;
    int pub_r000997_2;
    int pub_r000997_3;
    int pub_r000997_4;
    int pub_r000997_5;
    int pub_r000997_6;
    int pub_r000997_7;
    int pub_r000997_8;
    int pub_r000997_9;
    int pub_r000997_10;
    int pub_r000997_11;
    int pub_r000997_12;
    int pub_r000997_13;
    int pub_r000997_14;
    int pub_r000997_15;
    int pub_r000997_16;
    int pub_r000997_17;
    int pub_r000997_18;
    int pub_r000997_19;
    int pub_r000997_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000997_0 >= -100 && pub_r000997_0 <= 100);
    __CPROVER_assume(pub_r000997_1 >= -100 && pub_r000997_1 <= 100);
    __CPROVER_assume(pub_r000997_2 >= -100 && pub_r000997_2 <= 100);
    __CPROVER_assume(pub_r000997_3 >= -100 && pub_r000997_3 <= 100);
    __CPROVER_assume(pub_r000997_4 >= -100 && pub_r000997_4 <= 100);
    __CPROVER_assume(pub_r000997_5 >= -100 && pub_r000997_5 <= 100);
    __CPROVER_assume(pub_r000997_6 >= -100 && pub_r000997_6 <= 100);
    __CPROVER_assume(pub_r000997_7 >= -100 && pub_r000997_7 <= 100);
    __CPROVER_assume(pub_r000997_8 >= -100 && pub_r000997_8 <= 100);
    __CPROVER_assume(pub_r000997_9 >= -100 && pub_r000997_9 <= 100);
    __CPROVER_assume(pub_r000997_10 >= -100 && pub_r000997_10 <= 100);
    __CPROVER_assume(pub_r000997_11 >= -100 && pub_r000997_11 <= 100);
    __CPROVER_assume(pub_r000997_12 >= -100 && pub_r000997_12 <= 100);
    __CPROVER_assume(pub_r000997_13 >= -100 && pub_r000997_13 <= 100);
    __CPROVER_assume(pub_r000997_14 >= -100 && pub_r000997_14 <= 100);
    __CPROVER_assume(pub_r000997_15 >= -100 && pub_r000997_15 <= 100);
    __CPROVER_assume(pub_r000997_16 >= -100 && pub_r000997_16 <= 100);
    __CPROVER_assume(pub_r000997_17 >= -100 && pub_r000997_17 <= 100);
    __CPROVER_assume(pub_r000997_18 >= -100 && pub_r000997_18 <= 100);
    __CPROVER_assume(pub_r000997_19 >= -100 && pub_r000997_19 <= 100);
    __CPROVER_assume(pub_r000997_20 >= -100 && pub_r000997_20 <= 100);
    __CPROVER_assume(sec_r000997_0 >= 0 && sec_r000997_0 <= 255);
    __CPROVER_assume(sec_r000997_1 >= 0 && sec_r000997_1 <= 255);
    __CPROVER_assume(sec_r000997_2 >= 0 && sec_r000997_2 <= 255);
    __CPROVER_assume(sec_r000997_3 >= 0 && sec_r000997_3 <= 255);
    __CPROVER_assume(sec_r000997_4 >= 0 && sec_r000997_4 <= 255);
    __CPROVER_assume(sec_r000997_5 >= 0 && sec_r000997_5 <= 255);
    __CPROVER_assume(sec_r000997_6 >= 0 && sec_r000997_6 <= 255);
    __CPROVER_assume(sec_r000997_7 >= 0 && sec_r000997_7 <= 255);
    __CPROVER_assume(sec_r000997_8 >= 0 && sec_r000997_8 <= 255);
    __CPROVER_assume(sec_r000997_9 >= 0 && sec_r000997_9 <= 255);
    __CPROVER_assume(sec_r000997_10 >= 0 && sec_r000997_10 <= 255);
    __CPROVER_assume(sec_r000997_11 >= 0 && sec_r000997_11 <= 255);
    __CPROVER_assume(sec_r000997_12 >= 0 && sec_r000997_12 <= 255);
    __CPROVER_assume(sec_r000997_13 >= 0 && sec_r000997_13 <= 255);
    __CPROVER_assume(sec_r000997_14 >= 0 && sec_r000997_14 <= 255);
    __CPROVER_assume(sec_r000997_15 >= 0 && sec_r000997_15 <= 255);

    struct Vector3D_R000997_1724_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000997_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000997_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000997_0 + 7) & 15;
    struct CipherContext_R000997_1724_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000997_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000997_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000997_0 + 9) & 15;
    struct AudioFrame_R000997_1724_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000997_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000997_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000997_0 + 11) & 15;

    union PacketPayload_R000997_1724_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 13) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 28) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 50) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 36) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 51) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 32) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 47) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 15) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 30) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 16) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 31) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 34) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 49) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 35) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 50) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 37) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 52) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 23) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 38) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 17) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 32) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 19) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 34) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 38) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 53) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000997_3 & 1) != 0) {
        if ((sec_r000997_14 & 2) != 0) {
            stage_v_86 = (pub_r000997_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000997_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000997_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000997_1 & 1) != 0) {
        if ((sec_r000997_10 & 2) != 0) {
            stage_v_87 = (pub_r000997_11 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000997_11 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000997_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_88 = (pub_r000997_2 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000997_2 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000997_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000997_10 & 2) != 0) {
            stage_v_89 = (pub_r000997_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000997_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000997_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000997_6 & 2) != 0) {
            stage_v_90 = (pub_r000997_3 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000997_3 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000997_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000997_11 & 2) != 0) {
            stage_v_91 = (pub_r000997_15 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000997_15 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000997_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_92 = (pub_r000997_13 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000997_13 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000997_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000997_0 & 2) != 0) {
            stage_v_93 = (pub_r000997_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000997_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000997_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000997_8 & 1) != 0) {
        if ((sec_r000997_3 & 2) != 0) {
            stage_v_94 = (pub_r000997_14 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000997_14 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000997_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000997_2 & 2) != 0) {
            stage_v_95 = (pub_r000997_1 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000997_1 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000997_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000997_9 & 2) != 0) {
            stage_v_96 = (pub_r000997_2 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000997_2 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000997_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000997_6 & 2) != 0) {
            stage_v_97 = (pub_r000997_6 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000997_6 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000997_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000997_2 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_98 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_99 = (pub_r000997_7 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000997_7 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000997_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_100 = (pub_r000997_0 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000997_0 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000997_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000997_9 & 1) != 0) {
        if ((sec_r000997_2 & 2) != 0) {
            stage_v_101 = (pub_r000997_11 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000997_11 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000997_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_102 = (pub_r000997_1 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000997_1 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000997_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000997_7 & 1) != 0) {
        if ((sec_r000997_9 & 2) != 0) {
            stage_v_103 = (pub_r000997_17 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000997_17 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000997_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_104 = (pub_r000997_12 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000997_12 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000997_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000997_0 & 2) != 0) {
            stage_v_105 = (pub_r000997_15 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000997_15 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000997_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000997_10 & 2) != 0) {
            stage_v_106 = (pub_r000997_1 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000997_1 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000997_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000997_4 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_107 = (pub_r000997_18 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000997_18 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000997_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000997_4 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_108 = (pub_r000997_13 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000997_13 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000997_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_109 = (pub_r000997_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000997_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000997_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_110 = (pub_r000997_17 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000997_17 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000997_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000997_3 & 2) != 0) {
            stage_v_111 = (pub_r000997_11 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000997_11 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000997_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000997_0 & 2) != 0) {
            stage_v_112 = (pub_r000997_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000997_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000997_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_113 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_114 = (pub_r000997_17 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000997_17 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000997_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_115 = (pub_r000997_15 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000997_15 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000997_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_116 = (pub_r000997_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000997_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000997_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000997_13 & 1) != 0) {
        if ((sec_r000997_14 & 2) != 0) {
            stage_v_117 = (pub_r000997_9 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000997_9 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000997_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000997_13 & 1) != 0) {
        if ((sec_r000997_0 & 2) != 0) {
            stage_v_118 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000997_2 & 1) != 0) {
        if ((sec_r000997_1 & 2) != 0) {
            stage_v_119 = (pub_r000997_2 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000997_2 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000997_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000997_3 & 2) != 0) {
            stage_v_120 = (pub_r000997_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000997_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000997_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_121 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000997_6 & 1) != 0) {
        if ((sec_r000997_12 & 2) != 0) {
            stage_v_122 = (pub_r000997_14 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000997_14 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000997_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000997_13 & 1) != 0) {
        if ((sec_r000997_11 & 2) != 0) {
            stage_v_123 = (pub_r000997_18 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000997_18 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000997_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_124 = (pub_r000997_0 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000997_0 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000997_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000997_9 & 2) != 0) {
            stage_v_125 = (pub_r000997_14 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000997_14 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000997_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_126 = (pub_r000997_0 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000997_0 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000997_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000997_1 & 2) != 0) {
            stage_v_127 = (pub_r000997_2 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000997_2 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000997_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_128 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000997_5 & 2) != 0) {
            stage_v_129 = (pub_r000997_1 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000997_1 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000997_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_130 = (pub_r000997_8 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000997_8 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000997_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000997_0 & 2) != 0) {
            stage_v_131 = (pub_r000997_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000997_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000997_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000997_3 & 2) != 0) {
            stage_v_132 = (pub_r000997_10 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000997_10 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000997_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000997_12 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_133 = (pub_r000997_9 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000997_9 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000997_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000997_7 & 1) != 0) {
        if ((sec_r000997_1 & 2) != 0) {
            stage_v_134 = (pub_r000997_14 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000997_14 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000997_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000997_11 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_135 = (pub_r000997_14 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000997_14 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000997_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000997_8 & 1) != 0) {
        if ((sec_r000997_15 & 2) != 0) {
            stage_v_136 = (pub_r000997_5 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000997_5 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000997_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000997_15 & 2) != 0) {
            stage_v_137 = (pub_r000997_3 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000997_3 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000997_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000997_12 & 2) != 0) {
            stage_v_138 = (pub_r000997_15 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000997_15 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000997_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000997_2 & 2) != 0) {
            stage_v_139 = (pub_r000997_10 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000997_10 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000997_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_140 = (pub_r000997_3 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000997_3 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000997_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000997_3 & 2) != 0) {
            stage_v_141 = (pub_r000997_3 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000997_3 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000997_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_142 = (pub_r000997_11 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000997_11 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000997_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000997_8 & 2) != 0) {
            stage_v_143 = (pub_r000997_4 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000997_4 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000997_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000997_11 & 1) != 0) {
        if ((sec_r000997_7 & 2) != 0) {
            stage_v_144 = (pub_r000997_8 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000997_8 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000997_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000997_13 & 2) != 0) {
            stage_v_145 = (pub_r000997_18 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000997_18 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000997_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000997_14 & 2) != 0) {
            stage_v_146 = (pub_r000997_7 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000997_7 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000997_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000997_5 & 2) != 0) {
            stage_v_147 = (pub_r000997_10 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000997_10 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000997_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000997_14 & 1) != 0) {
        if ((sec_r000997_4 & 2) != 0) {
            stage_v_148 = (pub_r000997_20 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000997_20 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000997_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
