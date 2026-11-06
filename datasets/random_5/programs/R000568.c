/*
 * Benchmark Program: R000568
 * Security Family: secret_dependent_loops
 * Generator Seed: 556813
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000568_6813_0 {
    int rate;
    int account_id;
    int status;
    short auth_code;
    int buffer[3];
};

struct EventLog_R000568_6813_1 {
    short code;
    int seq;
    int timestamp;
    int severity;
    int signature;
    int facility;
    int buffer[3];
};

struct AudioFrame_R000568_6813_2 {
    int gain;
    short envelope;
    unsigned char peak;
    int rms;
    int channels;
    int sample_rate;
    int buffer[3];
};

union PacketPayload_R000568_6813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000568_6813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000568_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_77 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_77 > 29) {
        acc = (acc + stride_77 * 2 + 5) & 127;
        aux ^= (stride_77 & 15);
    } else {
        acc = (acc - stride_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_52 = local_arr[aux % 3];
    acc = (acc + index_reg_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000568_6813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int residue_80 = local_arr[aux % 3];
    acc = (acc + residue_80 * 2) & 127;
    int checksum_63 = (aux + st.buffer[1]) & 3;
    switch (checksum_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_2(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_42 = (aux + st.buffer[1]) & 3;
    switch (bound_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_76) & 63;
    acc ^= aux;
    int anchor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_75 > 15) {
        acc = (acc + anchor_75 * 2 + 5) & 127;
        aux ^= (anchor_75 & 15);
    } else {
        acc = (acc - anchor_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000568_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int residue_47 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_47 > 23) {
        acc = (acc + residue_47 * 2 + 5) & 127;
        aux ^= (residue_47 & 15);
    } else {
        acc = (acc - residue_47 + 11) & 127;
        aux += 3;
    }
    int metric_61 = (aux + st.buffer[1]) & 3;
    switch (metric_61) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000568_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int delta_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_47) & 63;
    acc ^= aux;
    int mask_18 = (aux + st.buffer[1]) & 3;
    switch (mask_18) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int checksum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_63) & 63;
    acc ^= aux;
    int bound_73 = (aux + st.buffer[1]) & 3;
    switch (bound_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_91 = local_arr[aux % 3];
    acc = (acc + quotient_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_6(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int metric_72 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_72 > 27) {
        acc = (acc + metric_72 * 2 + 5) & 127;
        aux ^= (metric_72 & 15);
    } else {
        acc = (acc - metric_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_10 = local_arr[aux % 3];
    acc = (acc + weight_10 * 2) & 127;
    int damping_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_83) & 63;
    acc ^= aux;
    int vector_89 = (aux + st.buffer[1]) & 3;
    switch (vector_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_30 = (aux + st.buffer[1]) & 3;
    switch (index_reg_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000568_6813_8(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_38 = (aux + st.buffer[1]) & 3;
    switch (margin_38) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_61) & 63;
    acc ^= aux;
    int quotient_80 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_80 > 25) {
        acc = (acc + quotient_80 * 2 + 5) & 127;
        aux ^= (quotient_80 & 15);
    } else {
        acc = (acc - quotient_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_87 = (aux + st.buffer[1]) & 3;
    switch (threshold_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_10(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000568_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_52 = (aux + st.buffer[1]) & 3;
    switch (delta_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_19 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_19 > 40) {
        acc = (acc + metric_19 * 2 + 5) & 127;
        aux ^= (metric_19 & 15);
    } else {
        acc = (acc - metric_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_93 = local_arr[aux % 3];
    acc = (acc + tally_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int mask_69 = local_arr[aux % 3];
    acc = (acc + mask_69 * 2) & 127;
    int coefficient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000568_6813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_32 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_32 > 22) {
        acc = (acc + delta_32 * 2 + 5) & 127;
        aux ^= (delta_32 & 15);
    } else {
        acc = (acc - delta_32 + 11) & 127;
        aux += 3;
    }
    int mask_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_91) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_36 = local_arr[aux % 3];
    acc = (acc + checksum_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_71) & 63;
    acc ^= aux;
    int segment_17 = (aux + st.buffer[1]) & 3;
    switch (segment_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_14(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int mask_55 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_55 > 26) {
        acc = (acc + mask_55 * 2 + 5) & 127;
        aux ^= (mask_55 & 15);
    } else {
        acc = (acc - mask_55 + 11) & 127;
        aux += 3;
    }
    int tracker_25 = (aux + st.buffer[1]) & 3;
    switch (tracker_25) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000568_6813_15(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000568_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_24 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_24 > 36) {
        acc = (acc + delta_24 * 2 + 5) & 127;
        aux ^= (delta_24 & 15);
    } else {
        acc = (acc - delta_24 + 11) & 127;
        aux += 3;
    }
    int bound_41 = (aux + st.buffer[1]) & 3;
    switch (bound_41) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_61) & 63;
    acc ^= aux;
    int window_98 = (aux + st.buffer[1]) & 3;
    switch (window_98) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000568_6813_17(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000568_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_44 = (aux + st.buffer[1]) & 3;
    switch (quotient_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_70 = local_arr[aux % 3];
    acc = (acc + window_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000568_6813_18(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000568_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int stride_56 = local_arr[aux % 3];
    acc = (acc + stride_56 * 2) & 127;
    int coefficient_74 = (aux + st.buffer[1]) & 3;
    switch (coefficient_74) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_20) & 63;
    acc ^= aux;
    int parity_14 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_14 > 46) {
        acc = (acc + parity_14 * 2 + 5) & 127;
        aux ^= (parity_14 & 15);
    } else {
        acc = (acc - parity_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000568_0;
    int sec_r000568_1;
    int sec_r000568_2;
    int sec_r000568_3;
    int sec_r000568_4;
    int sec_r000568_5;
    int sec_r000568_6;
    int sec_r000568_7;
    int sec_r000568_8;
    int sec_r000568_9;
    int sec_r000568_10;
    int sec_r000568_11;
    int sec_r000568_12;
    int sec_r000568_13;
    int sec_r000568_14;
    int sec_r000568_15;
    int pub_r000568_0;
    int pub_r000568_1;
    int pub_r000568_2;
    int pub_r000568_3;
    int pub_r000568_4;
    int pub_r000568_5;
    int pub_r000568_6;
    int pub_r000568_7;
    int pub_r000568_8;
    int pub_r000568_9;
    int pub_r000568_10;
    int pub_r000568_11;
    int pub_r000568_12;
    int pub_r000568_13;
    int pub_r000568_14;
    int pub_r000568_15;
    int pub_r000568_16;
    int pub_r000568_17;
    int pub_r000568_18;
    int pub_r000568_19;
    int pub_r000568_20;
    int pub_r000568_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000568_0 >= -100 && pub_r000568_0 <= 100);
    __CPROVER_assume(pub_r000568_1 >= -100 && pub_r000568_1 <= 100);
    __CPROVER_assume(pub_r000568_2 >= -100 && pub_r000568_2 <= 100);
    __CPROVER_assume(pub_r000568_3 >= -100 && pub_r000568_3 <= 100);
    __CPROVER_assume(pub_r000568_4 >= -100 && pub_r000568_4 <= 100);
    __CPROVER_assume(pub_r000568_5 >= -100 && pub_r000568_5 <= 100);
    __CPROVER_assume(pub_r000568_6 >= -100 && pub_r000568_6 <= 100);
    __CPROVER_assume(pub_r000568_7 >= -100 && pub_r000568_7 <= 100);
    __CPROVER_assume(pub_r000568_8 >= -100 && pub_r000568_8 <= 100);
    __CPROVER_assume(pub_r000568_9 >= -100 && pub_r000568_9 <= 100);
    __CPROVER_assume(pub_r000568_10 >= -100 && pub_r000568_10 <= 100);
    __CPROVER_assume(pub_r000568_11 >= -100 && pub_r000568_11 <= 100);
    __CPROVER_assume(pub_r000568_12 >= -100 && pub_r000568_12 <= 100);
    __CPROVER_assume(pub_r000568_13 >= -100 && pub_r000568_13 <= 100);
    __CPROVER_assume(pub_r000568_14 >= -100 && pub_r000568_14 <= 100);
    __CPROVER_assume(pub_r000568_15 >= -100 && pub_r000568_15 <= 100);
    __CPROVER_assume(pub_r000568_16 >= -100 && pub_r000568_16 <= 100);
    __CPROVER_assume(pub_r000568_17 >= -100 && pub_r000568_17 <= 100);
    __CPROVER_assume(pub_r000568_18 >= -100 && pub_r000568_18 <= 100);
    __CPROVER_assume(pub_r000568_19 >= -100 && pub_r000568_19 <= 100);
    __CPROVER_assume(pub_r000568_20 >= -100 && pub_r000568_20 <= 100);
    __CPROVER_assume(pub_r000568_21 >= -100 && pub_r000568_21 <= 100);
    __CPROVER_assume(sec_r000568_0 >= 0 && sec_r000568_0 <= 255);
    __CPROVER_assume(sec_r000568_1 >= 0 && sec_r000568_1 <= 255);
    __CPROVER_assume(sec_r000568_2 >= 0 && sec_r000568_2 <= 255);
    __CPROVER_assume(sec_r000568_3 >= 0 && sec_r000568_3 <= 255);
    __CPROVER_assume(sec_r000568_4 >= 0 && sec_r000568_4 <= 255);
    __CPROVER_assume(sec_r000568_5 >= 0 && sec_r000568_5 <= 255);
    __CPROVER_assume(sec_r000568_6 >= 0 && sec_r000568_6 <= 255);
    __CPROVER_assume(sec_r000568_7 >= 0 && sec_r000568_7 <= 255);
    __CPROVER_assume(sec_r000568_8 >= 0 && sec_r000568_8 <= 255);
    __CPROVER_assume(sec_r000568_9 >= 0 && sec_r000568_9 <= 255);
    __CPROVER_assume(sec_r000568_10 >= 0 && sec_r000568_10 <= 255);
    __CPROVER_assume(sec_r000568_11 >= 0 && sec_r000568_11 <= 255);
    __CPROVER_assume(sec_r000568_12 >= 0 && sec_r000568_12 <= 255);
    __CPROVER_assume(sec_r000568_13 >= 0 && sec_r000568_13 <= 255);
    __CPROVER_assume(sec_r000568_14 >= 0 && sec_r000568_14 <= 255);
    __CPROVER_assume(sec_r000568_15 >= 0 && sec_r000568_15 <= 255);

    struct Transaction_R000568_6813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000568_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000568_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000568_0 + 7) & 15;
    struct EventLog_R000568_6813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000568_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000568_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000568_0 + 9) & 15;
    struct AudioFrame_R000568_6813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000568_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000568_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000568_0 + 11) & 15;

    union PacketPayload_R000568_6813_0 u_var;
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
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

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
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 11) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 26) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
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
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

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
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 40) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 55) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 14) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 29) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 18) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 33) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_9 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000568_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000568_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_3 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_3 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000568_21) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000568_15) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000568_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000568_14) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_1 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000568_21) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_15 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000568_20) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_11 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000568_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_15 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000568_3) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000568_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000568_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000568_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000568_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_3 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000568_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000568_8) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000568_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_13 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000568_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000568_15) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000568_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000568_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_1 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000568_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_4 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000568_14) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000568_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_11 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000568_11) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_1 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000568_3) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000568_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000568_10) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000568_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000568_17) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000568_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000568_15) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_9 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000568_3) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_52 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000568_17) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000568_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000568_20) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000568_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_9 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000568_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000568_7) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_2 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_15 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000568_10) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000568_17) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_9 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000568_21) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_11 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000568_3) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000568_8) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_5 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000568_14) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000568_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000568_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000568_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000568_17) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000568_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_12 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_10 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_13 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000568_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_14 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000568_11) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000568_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_8 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000568_6) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000568_2) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_7 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000568_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000568_14) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000568_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_146 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000568_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_137 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000568_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_144 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000568_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000568_11) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000568_0) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000568_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000568_9) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000568_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_8 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000568_5) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_6 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000568_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000568_1) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000568_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000568_4) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_156 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000568_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_11 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000568_18) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000568_13) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000568_6) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000568_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000568_12) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000568_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000568_15 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000568_8) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000568_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000568_19) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000568_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_138 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000568_17) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000568_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000568_16) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000568_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000568_8) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000568_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
