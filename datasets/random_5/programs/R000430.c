/*
 * Benchmark Program: R000430
 * Security Family: mixed_control_data
 * Generator Seed: 543013
 * High Inputs: 17 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000430_3013_0 {
    short peak;
    int envelope;
    int sample_rate;
    int buffer[3];
};

struct Transaction_R000430_3013_1 {
    int rate;
    short balance;
    int auth_code;
    int status;
    int account_id;
    short fee;
    int buffer[3];
};

struct Vector3D_R000430_3013_2 {
    int pitch;
    short coord_x;
    int norm_sq;
    int buffer[3];
};

union ColorPixel_R000430_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000430_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000430_3013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_57) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_53 = local_arr[aux % 3];
    acc = (acc + damping_53 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000430_3013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int scale_29 = local_arr[aux % 3];
    acc = (acc + scale_29 * 2) & 127;
    int pivot_75 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_75 > 13) {
        acc = (acc + pivot_75 * 2 + 5) & 127;
        aux ^= (pivot_75 & 15);
    } else {
        acc = (acc - pivot_75 + 11) & 127;
        aux += 3;
    }
    int delta_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000430_3013_2(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_10 = (st.buffer[0] * 3 + aux) & 63;
    if (window_10 > 34) {
        acc = (acc + window_10 * 2 + 5) & 127;
        aux ^= (window_10 & 15);
    } else {
        acc = (acc - window_10 + 11) & 127;
        aux += 3;
    }
    int checksum_58 = (aux + st.buffer[1]) & 3;
    switch (checksum_58) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000430_3013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int phase_12 = local_arr[aux % 3];
    acc = (acc + phase_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_32 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_32 > 44) {
        acc = (acc + pivot_32 * 2 + 5) & 127;
        aux ^= (pivot_32 & 15);
    } else {
        acc = (acc - pivot_32 + 11) & 127;
        aux += 3;
    }
    int parity_89 = (aux + st.buffer[1]) & 3;
    switch (parity_89) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int mask_56 = (aux + st.buffer[1]) & 3;
    switch (mask_56) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_76 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_76 > 26) {
        acc = (acc + delta_76 * 2 + 5) & 127;
        aux ^= (delta_76 & 15);
    } else {
        acc = (acc - delta_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_5(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_64 = (aux + st.buffer[1]) & 3;
    switch (cursor_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_71 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_71 > 28) {
        acc = (acc + residue_71 * 2 + 5) & 127;
        aux ^= (residue_71 & 15);
    } else {
        acc = (acc - residue_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_6(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000430_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000430_3013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000430_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int margin_40 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_40 > 24) {
        acc = (acc + margin_40 * 2 + 5) & 127;
        aux ^= (margin_40 & 15);
    } else {
        acc = (acc - margin_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_61 = local_arr[aux % 3];
    acc = (acc + sample_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000430_3013_8(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int anchor_16 = local_arr[aux % 3];
    acc = (acc + anchor_16 * 2) & 127;
    int stride_57 = (aux + st.buffer[1]) & 3;
    switch (stride_57) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_80 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_80 > 17) {
        acc = (acc + checksum_80 * 2 + 5) & 127;
        aux ^= (checksum_80 & 15);
    } else {
        acc = (acc - checksum_80 + 11) & 127;
        aux += 3;
    }
    int quotient_42 = (aux + st.buffer[1]) & 3;
    switch (quotient_42) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int window_25 = local_arr[aux % 3];
    acc = (acc + window_25 * 2) & 127;
    int tally_32 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_32 > 15) {
        acc = (acc + tally_32 * 2 + 5) & 127;
        aux ^= (tally_32 & 15);
    } else {
        acc = (acc - tally_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000430_3013_11(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_54 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_54 > 26) {
        acc = (acc + accumulator_54 * 2 + 5) & 127;
        aux ^= (accumulator_54 & 15);
    } else {
        acc = (acc - accumulator_54 + 11) & 127;
        aux += 3;
    }
    int delta_30 = (aux + st.buffer[1]) & 3;
    switch (delta_30) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_12(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_79 = (aux + st.buffer[1]) & 3;
    switch (delta_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_79 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_79 > 17) {
        acc = (acc + vector_79 * 2 + 5) & 127;
        aux ^= (vector_79 & 15);
    } else {
        acc = (acc - vector_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_64 = local_arr[aux % 3];
    acc = (acc + checksum_64 * 2) & 127;
    int tally_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000430_3013_13(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000430_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int tally_63 = local_arr[aux % 3];
    acc = (acc + tally_63 * 2) & 127;
    int metric_19 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_19 > 32) {
        acc = (acc + metric_19 * 2 + 5) & 127;
        aux ^= (metric_19 & 15);
    } else {
        acc = (acc - metric_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000430_3013_14(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_93 = (aux + st.buffer[1]) & 3;
    switch (tracker_93) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_62 = local_arr[aux % 3];
    acc = (acc + parity_62 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_89 = (aux + st.buffer[1]) & 3;
    switch (pivot_89) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000430_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_59 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_59 > 12) {
        acc = (acc + checksum_59 * 2 + 5) & 127;
        aux ^= (checksum_59 & 15);
    } else {
        acc = (acc - checksum_59 + 11) & 127;
        aux += 3;
    }
    int segment_24 = (aux + st.buffer[1]) & 3;
    switch (segment_24) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_19 = local_arr[aux % 3];
    acc = (acc + weight_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000430_3013_17(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000430_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_38 = local_arr[aux % 3];
    acc = (acc + margin_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000430_3013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_48 = local_arr[aux % 3];
    acc = (acc + tally_48 * 2) & 127;
    int residue_14 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_14 > 50) {
        acc = (acc + residue_14 * 2 + 5) & 127;
        aux ^= (residue_14 & 15);
    } else {
        acc = (acc - residue_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_19(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000430_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_38 > 27) {
        acc = (acc + tally_38 * 2 + 5) & 127;
        aux ^= (tally_38 & 15);
    } else {
        acc = (acc - tally_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_83) & 63;
    acc ^= aux;
    int residue_41 = (aux + st.buffer[1]) & 3;
    switch (residue_41) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000430_3013_20(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000430_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int index_reg_65 = local_arr[aux % 3];
    acc = (acc + index_reg_65 * 2) & 127;
    int margin_19 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_19 > 40) {
        acc = (acc + margin_19 * 2 + 5) & 127;
        aux ^= (margin_19 & 15);
    } else {
        acc = (acc - margin_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000430_0;
    int sec_r000430_1;
    int sec_r000430_2;
    int sec_r000430_3;
    int sec_r000430_4;
    int sec_r000430_5;
    int sec_r000430_6;
    int sec_r000430_7;
    int sec_r000430_8;
    int sec_r000430_9;
    int sec_r000430_10;
    int sec_r000430_11;
    int sec_r000430_12;
    int sec_r000430_13;
    int sec_r000430_14;
    int sec_r000430_15;
    int sec_r000430_16;
    int pub_r000430_0;
    int pub_r000430_1;
    int pub_r000430_2;
    int pub_r000430_3;
    int pub_r000430_4;
    int pub_r000430_5;
    int pub_r000430_6;
    int pub_r000430_7;
    int pub_r000430_8;
    int pub_r000430_9;
    int pub_r000430_10;
    int pub_r000430_11;
    int pub_r000430_12;
    int pub_r000430_13;
    int pub_r000430_14;
    int pub_r000430_15;
    int pub_r000430_16;
    int pub_r000430_17;
    int pub_r000430_18;
    int pub_r000430_19;
    int pub_r000430_20;
    int pub_r000430_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000430_0 >= -100 && pub_r000430_0 <= 100);
    __CPROVER_assume(pub_r000430_1 >= -100 && pub_r000430_1 <= 100);
    __CPROVER_assume(pub_r000430_2 >= -100 && pub_r000430_2 <= 100);
    __CPROVER_assume(pub_r000430_3 >= -100 && pub_r000430_3 <= 100);
    __CPROVER_assume(pub_r000430_4 >= -100 && pub_r000430_4 <= 100);
    __CPROVER_assume(pub_r000430_5 >= -100 && pub_r000430_5 <= 100);
    __CPROVER_assume(pub_r000430_6 >= -100 && pub_r000430_6 <= 100);
    __CPROVER_assume(pub_r000430_7 >= -100 && pub_r000430_7 <= 100);
    __CPROVER_assume(pub_r000430_8 >= -100 && pub_r000430_8 <= 100);
    __CPROVER_assume(pub_r000430_9 >= -100 && pub_r000430_9 <= 100);
    __CPROVER_assume(pub_r000430_10 >= -100 && pub_r000430_10 <= 100);
    __CPROVER_assume(pub_r000430_11 >= -100 && pub_r000430_11 <= 100);
    __CPROVER_assume(pub_r000430_12 >= -100 && pub_r000430_12 <= 100);
    __CPROVER_assume(pub_r000430_13 >= -100 && pub_r000430_13 <= 100);
    __CPROVER_assume(pub_r000430_14 >= -100 && pub_r000430_14 <= 100);
    __CPROVER_assume(pub_r000430_15 >= -100 && pub_r000430_15 <= 100);
    __CPROVER_assume(pub_r000430_16 >= -100 && pub_r000430_16 <= 100);
    __CPROVER_assume(pub_r000430_17 >= -100 && pub_r000430_17 <= 100);
    __CPROVER_assume(pub_r000430_18 >= -100 && pub_r000430_18 <= 100);
    __CPROVER_assume(pub_r000430_19 >= -100 && pub_r000430_19 <= 100);
    __CPROVER_assume(pub_r000430_20 >= -100 && pub_r000430_20 <= 100);
    __CPROVER_assume(pub_r000430_21 >= -100 && pub_r000430_21 <= 100);
    __CPROVER_assume(sec_r000430_0 >= 0 && sec_r000430_0 <= 255);
    __CPROVER_assume(sec_r000430_1 >= 0 && sec_r000430_1 <= 255);
    __CPROVER_assume(sec_r000430_2 >= 0 && sec_r000430_2 <= 255);
    __CPROVER_assume(sec_r000430_3 >= 0 && sec_r000430_3 <= 255);
    __CPROVER_assume(sec_r000430_4 >= 0 && sec_r000430_4 <= 255);
    __CPROVER_assume(sec_r000430_5 >= 0 && sec_r000430_5 <= 255);
    __CPROVER_assume(sec_r000430_6 >= 0 && sec_r000430_6 <= 255);
    __CPROVER_assume(sec_r000430_7 >= 0 && sec_r000430_7 <= 255);
    __CPROVER_assume(sec_r000430_8 >= 0 && sec_r000430_8 <= 255);
    __CPROVER_assume(sec_r000430_9 >= 0 && sec_r000430_9 <= 255);
    __CPROVER_assume(sec_r000430_10 >= 0 && sec_r000430_10 <= 255);
    __CPROVER_assume(sec_r000430_11 >= 0 && sec_r000430_11 <= 255);
    __CPROVER_assume(sec_r000430_12 >= 0 && sec_r000430_12 <= 255);
    __CPROVER_assume(sec_r000430_13 >= 0 && sec_r000430_13 <= 255);
    __CPROVER_assume(sec_r000430_14 >= 0 && sec_r000430_14 <= 255);
    __CPROVER_assume(sec_r000430_15 >= 0 && sec_r000430_15 <= 255);
    __CPROVER_assume(sec_r000430_16 >= 0 && sec_r000430_16 <= 255);

    struct AudioFrame_R000430_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000430_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000430_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000430_0 + 7) & 15;
    struct Transaction_R000430_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000430_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000430_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000430_0 + 9) & 15;
    struct Vector3D_R000430_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000430_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000430_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000430_0 + 11) & 15;

    union ColorPixel_R000430_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 12) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 27) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

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
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 27) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 42) {
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
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r000430_3 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_17 > 32) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_17 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_18 > 26) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r000430_1 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_19 > 37) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r000430_13 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_20 > 33) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r000430_12 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_21 > 23) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_20 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_22 > 49) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_18 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_23 > 40) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_17 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_24 > 23) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r000430_2 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_25 > 20) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_20 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_26 > 43) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_20 ^ 0x2A) + pub_r000430_12) & 127;
    if (stage_v_27 > 36) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_20 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_28 > 21) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r000430_0 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_29 > 44) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_21 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_30 > 36) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_20 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_31 > 36) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r000430_5 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_32 > 49) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_25 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_33 > 27) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r000430_11 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_34 > 25) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r000430_5 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_35 > 45) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_20 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_36 > 24) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_17 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_37 > 31) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_19 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_30 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_39 > 27) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r000430_2 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_40 > 44) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_35 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_41 > 25) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r000430_9 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_42 > 49) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_33 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_43 > 41) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_18 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000430_16 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_45 > 50) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_44 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_46 > 41) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_21 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_47 > 30) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r000430_6 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_48 > 50) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000430_10 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_49 > 23) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_33 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_50 > 30) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_17 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_51 > 21) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_42 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_52 > 35) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_38 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_53 > 31) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_25 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_54 > 49) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_23 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_55 > 40) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_40 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_56 > 36) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_48 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_57 > 44) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_50 ^ 0x2A) + pub_r000430_5) & 127;
    if (stage_v_58 > 44) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_51 ^ 0x2A) + pub_r000430_14) & 127;
    if (stage_v_59 > 35) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r000430_10 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_60 > 46) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_34 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_61 > 40) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_23 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_62 > 38) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_38 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_63 > 41) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_44 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_64 > 32) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_49 ^ 0x2A) + pub_r000430_14) & 127;
    if (stage_v_65 > 27) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000430_1 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_66 > 28) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_61 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_67 > 33) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000430_11 ^ 0x2A) + pub_r000430_12) & 127;
    if (stage_v_68 > 40) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000430_4 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_69 > 20) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000430_9 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_70 > 43) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_62 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_71 > 27) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_27 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_72 > 41) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_31 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_73 > 36) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_47 ^ 0x2A) + pub_r000430_4) & 127;
    if (stage_v_74 > 27) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_72 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_75 > 47) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_69 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_76 > 31) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r000430_4 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_77 > 23) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_54 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_78 > 38) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_38 ^ 0x2A) + pub_r000430_19) & 127;
    if (stage_v_79 > 25) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_79 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_80 > 32) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_60 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_81 > 37) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r000430_12 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_82 > 48) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r000430_5 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_83 > 44) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_62 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_84 > 50) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000430_5 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_85 > 23) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r000430_5 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_87 > 37) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r000430_16 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_88 > 40) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_36 ^ 0x2A) + pub_r000430_19) & 127;
    if (stage_v_89 > 39) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_60 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_90 > 21) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_91 > 23) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_35 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_92 > 26) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_18 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_93 > 25) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000430_8 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_94 > 47) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_92 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_95 > 42) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_56 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_96 > 29) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r000430_11 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_97 > 31) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_79 ^ 0x2A) + pub_r000430_19) & 127;
    if (stage_v_98 > 39) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_41 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_99 > 40) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_38 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_100 > 26) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000430_0 ^ 0x2A) + pub_r000430_3) & 127;
    if (stage_v_101 > 27) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_93 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_102 > 23) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_39 ^ 0x2A) + pub_r000430_19) & 127;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_104 > 21) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_67 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_99 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_106 > 33) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r000430_9 ^ 0x2A) + pub_r000430_12) & 127;
    if (stage_v_107 > 45) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000430_8 ^ 0x2A) + pub_r000430_4) & 127;
    if (stage_v_108 > 32) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r000430_9 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_109 > 31) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000430_15 ^ 0x2A) + pub_r000430_19) & 127;
    if (stage_v_110 > 43) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_75 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_111 > 20) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_50 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_112 > 30) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_67 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_113 > 49) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_53 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_114 > 48) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_41 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_115 > 32) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_37 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_116 > 43) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_45 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_117 > 32) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_98 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_118 > 24) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000430_12 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_119 > 46) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r000430_4 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_120 > 26) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000430_10 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_121 > 25) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_77 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_122 > 34) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_103 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_123 > 37) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_17 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_124 > 40) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000430_9 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_125 > 20) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000430_8 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_126 > 42) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r000430_13 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_127 > 43) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_47 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_128 > 42) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_28 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_129 > 44) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000430_11 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_130 > 41) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_125 ^ 0x2A) + pub_r000430_4) & 127;
    if (stage_v_131 > 26) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_132 > 36) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_122 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_133 > 21) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_134 > 45) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_101 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_135 > 22) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_118 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_136 > 32) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_61 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_137 > 29) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_63 ^ 0x2A) + pub_r000430_5) & 127;
    if (stage_v_138 > 40) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_117 ^ 0x2A) + pub_r000430_12) & 127;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_74 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_140 > 24) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_141 > 31) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r000430_3 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_142 > 41) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r000430_13 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_143 > 32) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000430_11 ^ 0x2A) + pub_r000430_3) & 127;
    if (stage_v_144 > 22) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_37 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_145 > 41) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_136 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_146 > 29) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_146 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_147 > 35) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_30 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000430_2 ^ 0x2A) + pub_r000430_1) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_118 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_150 > 26) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000430_13 ^ 0x2A) + pub_r000430_8) & 127;
    if (stage_v_151 > 28) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_105 ^ 0x2A) + pub_r000430_17) & 127;
    if (stage_v_152 > 50) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_125 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_153 > 33) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_104 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_154 > 46) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_114 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_155 > 44) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_20 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_156 > 50) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000430_4 ^ 0x2A) + pub_r000430_18) & 127;
    if (stage_v_157 > 20) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000430_2 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_158 > 23) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_32 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_159 > 43) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_81 ^ 0x2A) + pub_r000430_16) & 127;
    if (stage_v_160 > 35) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_141 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_161 > 43) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_71 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_162 > 21) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r000430_6 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_163 > 50) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_158 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_164 > 25) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_126 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_165 > 50) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_32 ^ 0x2A) + pub_r000430_20) & 127;
    if (stage_v_166 > 41) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_152 ^ 0x2A) + pub_r000430_13) & 127;
    if (stage_v_167 > 49) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000430_12 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_168 > 38) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_124 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_169 > 38) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_110 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_170 > 21) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_117 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_171 > 20) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_143 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_172 > 42) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000430_4 ^ 0x2A) + pub_r000430_2) & 127;
    if (stage_v_173 > 26) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_143 ^ 0x2A) + pub_r000430_6) & 127;
    if (stage_v_174 > 43) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000430_10 ^ 0x2A) + pub_r000430_7) & 127;
    if (stage_v_175 > 20) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_51 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_176 > 35) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_170 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_177 > 48) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000430_7 ^ 0x2A) + pub_r000430_12) & 127;
    if (stage_v_178 > 50) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_45 ^ 0x2A) + pub_r000430_14) & 127;
    if (stage_v_179 > 36) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000430_14 ^ 0x2A) + pub_r000430_0) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_176 ^ 0x2A) + pub_r000430_21) & 127;
    if (stage_v_181 > 24) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_55 ^ 0x2A) + pub_r000430_4) & 127;
    if (stage_v_182 > 48) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_121 ^ 0x2A) + pub_r000430_10) & 127;
    if (stage_v_183 > 36) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_172 ^ 0x2A) + pub_r000430_11) & 127;
    if (stage_v_184 > 24) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_104 ^ 0x2A) + pub_r000430_15) & 127;
    if (stage_v_185 > 39) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_121 ^ 0x2A) + pub_r000430_9) & 127;
    if (stage_v_186 > 23) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
