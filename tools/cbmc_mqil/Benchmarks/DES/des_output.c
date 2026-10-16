struct key_set {
  unsigned char k[8];
  unsigned char c[4];
  unsigned char d[4];
};
int initial_key_permutaion_1[56];
int initial_key_permutaion_2[56];
int initial_key_permutaion[56];
int initial_message_permutation_1[64];
int initial_message_permutation_2[64];
int initial_message_permutation[64];
int key_shift_sizes_1[17];
int key_shift_sizes_2[17];
int key_shift_sizes[17];
int sub_key_permutation_1[48];
int sub_key_permutation_2[48];
int sub_key_permutation[48];
int message_expansion_1[48];
int message_expansion_2[48];
int message_expansion[48];
int S1_1[64];
int S1_2[64];
int S1[64];
int S2_1[64];
int S2_2[64];
int S2[64];
int S3_1[64];
int S3_2[64];
int S3[64];
int S4_1[64];
int S4_2[64];
int S4[64];
int S5_1[64];
int S5_2[64];
int S5[64];
int S6_1[64];
int S6_2[64];
int S6[64];
int S7_1[64];
int S7_2[64];
int S7[64];
int S8_1[64];
int S8_2[64];
int S8[64];
int right_sub_message_permutation_1[32];
int right_sub_message_permutation_2[32];
int right_sub_message_permutation[32];
int final_message_permutation_1[64];
int final_message_permutation_2[64];
int final_message_permutation[64];
void generate_key_2(unsigned char *key_1, unsigned char *key_2) {
  int i_1;
  int i_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 8) && (i_2 < 8); i_1++, i_2++) {
    key_1[i_1] = rand() % 255;
    key_2[i_2] = rand() % 255;
    rand_2();
  }

  assert(i_1 == i_2);
}

void generate_key(unsigned char *key) {
  int i;
  for (i = 0; i < 8; i++) {
    key[i] = rand() % 255;
  }
}

void generate_sub_keys_2(unsigned char *main_key_1, struct key_set *key_sets_1,
                         unsigned char *main_key_2,
                         struct key_set *key_sets_2) {
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  int shift_size_1;
  int shift_size_2;
  unsigned char shift_byte_1;
  unsigned char shift_byte_2;
  unsigned char first_shift_bits_1;
  unsigned char first_shift_bits_2;
  unsigned char second_shift_bits_1;
  unsigned char second_shift_bits_2;
  unsigned char third_shift_bits_1;
  unsigned char third_shift_bits_2;
  unsigned char fourth_shift_bits_1;
  unsigned char fourth_shift_bits_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 8) && (i_2 < 8); i_1++, i_2++) {
    key_sets_1[0].k[i_1] = 0;
    key_sets_2[0].k[i_2] = 0;
  }

  for (i_1 = 0, i_2 = 0; (i_1 < 56) && (i_2 < 56); i_1++, i_2++) {
    shift_size_1 = initial_key_permutaion_1[i_1];
    shift_size_2 = initial_key_permutaion_2[i_2];
    shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
    shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
    shift_byte_1 &= main_key_1[(shift_size_1 - 1) / 8];
    shift_byte_2 &= main_key_2[(shift_size_2 - 1) / 8];
    shift_byte_1 <<= (shift_size_1 - 1) % 8;
    shift_byte_2 <<= (shift_size_2 - 1) % 8;
    key_sets_1[0].k[i_1 / 8] |= shift_byte_1 >> (i_1 % 8);
    key_sets_2[0].k[i_2 / 8] |= shift_byte_2 >> (i_2 % 8);
  }

  for (i_1 = 0, i_2 = 0; (i_1 < 3) && (i_2 < 3); i_1++, i_2++) {
    key_sets_1[0].c[i_1] = key_sets_1[0].k[i_1];
    key_sets_2[0].c[i_2] = key_sets_2[0].k[i_2];
  }

  key_sets_1[0].c[3] = key_sets_1[0].k[3] & 0xF0;
  key_sets_2[0].c[3] = key_sets_2[0].k[3] & 0xF0;
  for (i_1 = 0, i_2 = 0; (i_1 < 3) && (i_2 < 3); i_1++, i_2++) {
    key_sets_1[0].d[i_1] = (key_sets_1[0].k[i_1 + 3] & 0x0F) << 4;
    key_sets_2[0].d[i_2] = (key_sets_2[0].k[i_2 + 3] & 0x0F) << 4;
    key_sets_1[0].d[i_1] |= (key_sets_1[0].k[i_1 + 4] & 0xF0) >> 4;
    key_sets_2[0].d[i_2] |= (key_sets_2[0].k[i_2 + 4] & 0xF0) >> 4;
  }

  key_sets_1[0].d[3] = (key_sets_1[0].k[6] & 0x0F) << 4;
  key_sets_2[0].d[3] = (key_sets_2[0].k[6] & 0x0F) << 4;
  for (i_1 = 1, i_2 = 1; (i_1 < 17) && (i_2 < 17); i_1++, i_2++) {
    for (j_1 = 0, j_2 = 0; (j_1 < 4) && (j_2 < 4); j_1++, j_2++) {
      key_sets_1[i_1].c[j_1] = key_sets_1[i_1 - 1].c[j_1];
      key_sets_2[i_2].c[j_2] = key_sets_2[i_2 - 1].c[j_2];
      key_sets_1[i_1].d[j_1] = key_sets_1[i_1 - 1].d[j_1];
      key_sets_2[i_2].d[j_2] = key_sets_2[i_2 - 1].d[j_2];
    }

    shift_size_1 = key_shift_sizes_1[i_1];
    shift_size_2 = key_shift_sizes_2[i_2];
    if (shift_size_1 == 1) {
      shift_byte_1 = 0x80;
    } else {
      shift_byte_1 = 0xC0;
    }
    if (shift_size_2 == 1) {
      shift_byte_2 = 0x80;
    } else {
      shift_byte_2 = 0xC0;
    }
    first_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].c[0];
    first_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].c[0];
    second_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].c[1];
    second_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].c[1];
    third_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].c[2];
    third_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].c[2];
    fourth_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].c[3];
    fourth_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].c[3];
    key_sets_1[i_1].c[0] <<= shift_size_1;
    key_sets_2[i_2].c[0] <<= shift_size_2;
    key_sets_1[i_1].c[0] |= second_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].c[0] |= second_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].c[1] <<= shift_size_1;
    key_sets_2[i_2].c[1] <<= shift_size_2;
    key_sets_1[i_1].c[1] |= third_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].c[1] |= third_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].c[2] <<= shift_size_1;
    key_sets_2[i_2].c[2] <<= shift_size_2;
    key_sets_1[i_1].c[2] |= fourth_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].c[2] |= fourth_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].c[3] <<= shift_size_1;
    key_sets_2[i_2].c[3] <<= shift_size_2;
    key_sets_1[i_1].c[3] |= first_shift_bits_1 >> (4 - shift_size_1);
    key_sets_2[i_2].c[3] |= first_shift_bits_2 >> (4 - shift_size_2);
    first_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].d[0];
    first_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].d[0];
    second_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].d[1];
    second_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].d[1];
    third_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].d[2];
    third_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].d[2];
    fourth_shift_bits_1 = shift_byte_1 & key_sets_1[i_1].d[3];
    fourth_shift_bits_2 = shift_byte_2 & key_sets_2[i_2].d[3];
    key_sets_1[i_1].d[0] <<= shift_size_1;
    key_sets_2[i_2].d[0] <<= shift_size_2;
    key_sets_1[i_1].d[0] |= second_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].d[0] |= second_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].d[1] <<= shift_size_1;
    key_sets_2[i_2].d[1] <<= shift_size_2;
    key_sets_1[i_1].d[1] |= third_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].d[1] |= third_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].d[2] <<= shift_size_1;
    key_sets_2[i_2].d[2] <<= shift_size_2;
    key_sets_1[i_1].d[2] |= fourth_shift_bits_1 >> (8 - shift_size_1);
    key_sets_2[i_2].d[2] |= fourth_shift_bits_2 >> (8 - shift_size_2);
    key_sets_1[i_1].d[3] <<= shift_size_1;
    key_sets_2[i_2].d[3] <<= shift_size_2;
    key_sets_1[i_1].d[3] |= first_shift_bits_1 >> (4 - shift_size_1);
    key_sets_2[i_2].d[3] |= first_shift_bits_2 >> (4 - shift_size_2);
    for (j_1 = 0, j_2 = 0; (j_1 < 48) && (j_2 < 48); j_1++, j_2++) {
      shift_size_1 = sub_key_permutation_1[j_1];
      shift_size_2 = sub_key_permutation_2[j_2];
      if (shift_size_1 <= 28) {
        shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
        shift_byte_1 &= key_sets_1[i_1].c[(shift_size_1 - 1) / 8];
        shift_byte_1 <<= (shift_size_1 - 1) % 8;
      } else {
        shift_byte_1 = 0x80 >> ((shift_size_1 - 29) % 8);
        shift_byte_1 &= key_sets_1[i_1].d[(shift_size_1 - 29) / 8];
        shift_byte_1 <<= (shift_size_1 - 29) % 8;
      }
      if (shift_size_2 <= 28) {
        shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
        shift_byte_2 &= key_sets_2[i_2].c[(shift_size_2 - 1) / 8];
        shift_byte_2 <<= (shift_size_2 - 1) % 8;
      } else {
        shift_byte_2 = 0x80 >> ((shift_size_2 - 29) % 8);
        shift_byte_2 &= key_sets_2[i_2].d[(shift_size_2 - 29) / 8];
        shift_byte_2 <<= (shift_size_2 - 29) % 8;
      }
      key_sets_1[i_1].k[j_1 / 8] |= shift_byte_1 >> (j_1 % 8);
      key_sets_2[i_2].k[j_2 / 8] |= shift_byte_2 >> (j_2 % 8);
    }
  }

  __CPROVER_assume((*key_sets_1).c != (*key_sets_2).c);
  __CPROVER_assume((*key_sets_1).d != (*key_sets_2).d);
  __CPROVER_assume((*key_sets_1).k != (*key_sets_2).k);
  for (int i_0 = 0; i_0 < 56; i_0++) {
    assert(initial_key_permutaion_1[i_0] == initial_key_permutaion_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 17; i_0++) {
    assert(key_shift_sizes_1[i_0] == key_shift_sizes_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 48; i_0++) {
    assert(sub_key_permutation_1[i_0] == sub_key_permutation_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(j_1 == j_2);
  assert(shift_size_1 == shift_size_2);
  assert(shift_byte_1 == shift_byte_2);
  assert(first_shift_bits_1 == first_shift_bits_2);
  assert(second_shift_bits_1 == second_shift_bits_2);
  assert(third_shift_bits_1 == third_shift_bits_2);
  assert(fourth_shift_bits_1 == fourth_shift_bits_2);
}

void generate_sub_keys(unsigned char *main_key, struct key_set *key_sets) {
  int i;
  int j;
  int shift_size;
  unsigned char shift_byte;
  unsigned char first_shift_bits;
  unsigned char second_shift_bits;
  unsigned char third_shift_bits;
  unsigned char fourth_shift_bits;
  for (i = 0; i < 8; i++) {
    key_sets[0].k[i] = 0;
  }

  for (i = 0; i < 56; i++) {
    shift_size = initial_key_permutaion[i];
    shift_byte = 0x80 >> ((shift_size - 1) % 8);
    shift_byte &= main_key[(shift_size - 1) / 8];
    shift_byte <<= (shift_size - 1) % 8;
    key_sets[0].k[i / 8] |= shift_byte >> (i % 8);
  }

  for (i = 0; i < 3; i++) {
    key_sets[0].c[i] = key_sets[0].k[i];
  }

  key_sets[0].c[3] = key_sets[0].k[3] & 0xF0;
  for (i = 0; i < 3; i++) {
    key_sets[0].d[i] = (key_sets[0].k[i + 3] & 0x0F) << 4;
    key_sets[0].d[i] |= (key_sets[0].k[i + 4] & 0xF0) >> 4;
  }

  key_sets[0].d[3] = (key_sets[0].k[6] & 0x0F) << 4;
  for (i = 1; i < 17; i++) {
    for (j = 0; j < 4; j++) {
      key_sets[i].c[j] = key_sets[i - 1].c[j];
      key_sets[i].d[j] = key_sets[i - 1].d[j];
    }

    shift_size = key_shift_sizes[i];
    if (shift_size == 1) {
      shift_byte = 0x80;
    } else {
      shift_byte = 0xC0;
    }
    first_shift_bits = shift_byte & key_sets[i].c[0];
    second_shift_bits = shift_byte & key_sets[i].c[1];
    third_shift_bits = shift_byte & key_sets[i].c[2];
    fourth_shift_bits = shift_byte & key_sets[i].c[3];
    key_sets[i].c[0] <<= shift_size;
    key_sets[i].c[0] |= second_shift_bits >> (8 - shift_size);
    key_sets[i].c[1] <<= shift_size;
    key_sets[i].c[1] |= third_shift_bits >> (8 - shift_size);
    key_sets[i].c[2] <<= shift_size;
    key_sets[i].c[2] |= fourth_shift_bits >> (8 - shift_size);
    key_sets[i].c[3] <<= shift_size;
    key_sets[i].c[3] |= first_shift_bits >> (4 - shift_size);
    first_shift_bits = shift_byte & key_sets[i].d[0];
    second_shift_bits = shift_byte & key_sets[i].d[1];
    third_shift_bits = shift_byte & key_sets[i].d[2];
    fourth_shift_bits = shift_byte & key_sets[i].d[3];
    key_sets[i].d[0] <<= shift_size;
    key_sets[i].d[0] |= second_shift_bits >> (8 - shift_size);
    key_sets[i].d[1] <<= shift_size;
    key_sets[i].d[1] |= third_shift_bits >> (8 - shift_size);
    key_sets[i].d[2] <<= shift_size;
    key_sets[i].d[2] |= fourth_shift_bits >> (8 - shift_size);
    key_sets[i].d[3] <<= shift_size;
    key_sets[i].d[3] |= first_shift_bits >> (4 - shift_size);
    for (j = 0; j < 48; j++) {
      shift_size = sub_key_permutation[j];
      if (shift_size <= 28) {
        shift_byte = 0x80 >> ((shift_size - 1) % 8);
        shift_byte &= key_sets[i].c[(shift_size - 1) / 8];
        shift_byte <<= (shift_size - 1) % 8;
      } else {
        shift_byte = 0x80 >> ((shift_size - 29) % 8);
        shift_byte &= key_sets[i].d[(shift_size - 29) / 8];
        shift_byte <<= (shift_size - 29) % 8;
      }
      key_sets[i].k[j / 8] |= shift_byte >> (j % 8);
    }
  }
}

void process_message_2(unsigned char *message_piece_1,
                       unsigned char *processed_piece_1,
                       struct key_set *key_sets_1, int mode_1,
                       unsigned char *message_piece_2,
                       unsigned char *processed_piece_2,
                       struct key_set *key_sets_2, int mode_2) {
  int i_1;
  int i_2;
  int k_1;
  int k_2;
  int shift_size_1;
  int shift_size_2;
  unsigned char shift_byte_1;
  unsigned char shift_byte_2;
  unsigned char initial_permutation_1[8];
  unsigned char initial_permutation_2[8];
  memset(initial_permutation_1, 0, 8);
  memset(initial_permutation_2, 0, 8);
  memset_2(initial_permutation_1, 0, 8, initial_permutation_2, 0, 8);
  memset(processed_piece_1, 0, 8);
  memset(processed_piece_2, 0, 8);
  memset_2(processed_piece_1, 0, 8, processed_piece_2, 0, 8);
  for (i_1 = 0, i_2 = 0; (i_1 < 64) && (i_2 < 64); i_1++, i_2++) {
    shift_size_1 = initial_message_permutation_1[i_1];
    shift_size_2 = initial_message_permutation_2[i_2];
    shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
    shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
    shift_byte_1 &= message_piece_1[(shift_size_1 - 1) / 8];
    shift_byte_2 &= message_piece_2[(shift_size_2 - 1) / 8];
    shift_byte_1 <<= (shift_size_1 - 1) % 8;
    shift_byte_2 <<= (shift_size_2 - 1) % 8;
    initial_permutation_1[i_1 / 8] |= shift_byte_1 >> (i_1 % 8);
    initial_permutation_2[i_2 / 8] |= shift_byte_2 >> (i_2 % 8);
  }

  unsigned char l_1[4];
  unsigned char l_2[4];
  unsigned char r_1[4];
  unsigned char r_2[4];
  for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
    l_1[i_1] = initial_permutation_1[i_1];
    l_2[i_2] = initial_permutation_2[i_2];
    r_1[i_1] = initial_permutation_1[i_1 + 4];
    r_2[i_2] = initial_permutation_2[i_2 + 4];
  }

  unsigned char ln_1[4];
  unsigned char ln_2[4];
  unsigned char rn_1[4];
  unsigned char rn_2[4];
  unsigned char er_1[6];
  unsigned char er_2[6];
  unsigned char ser_1[4];
  unsigned char ser_2[4];
  int key_index_1;
  int key_index_2;
  for (k_1 = 1, k_2 = 1; (k_1 <= 16) && (k_2 <= 16); k_1++, k_2++) {
    memcpy(ln_1, r_1, 4);
    memcpy(ln_2, r_2, 4);
    memcpy_2(ln_1, r_1, 4, ln_2, r_2, 4);
    memset(er_1, 0, 6);
    memset(er_2, 0, 6);
    memset_2(er_1, 0, 6, er_2, 0, 6);
    for (i_1 = 0, i_2 = 0; (i_1 < 48) && (i_2 < 48); i_1++, i_2++) {
      shift_size_1 = message_expansion_1[i_1];
      shift_size_2 = message_expansion_2[i_2];
      shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
      shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
      shift_byte_1 &= r_1[(shift_size_1 - 1) / 8];
      shift_byte_2 &= r_2[(shift_size_2 - 1) / 8];
      shift_byte_1 <<= (shift_size_1 - 1) % 8;
      shift_byte_2 <<= (shift_size_2 - 1) % 8;
      er_1[i_1 / 8] |= shift_byte_1 >> (i_1 % 8);
      er_2[i_2 / 8] |= shift_byte_2 >> (i_2 % 8);
    }

    if (mode_1 == 0) {
      key_index_1 = 17 - k_1;
    } else {
      key_index_1 = k_1;
    }
    if (mode_2 == 0) {
      key_index_2 = 17 - k_2;
    } else {
      key_index_2 = k_2;
    }
    for (i_1 = 0, i_2 = 0; (i_1 < 6) && (i_2 < 6); i_1++, i_2++) {
      er_1[i_1] ^= key_sets_1[key_index_1].k[i_1];
      er_2[i_2] ^= key_sets_2[key_index_2].k[i_2];
    }

    unsigned char row_1;
    unsigned char row_2;
    unsigned char column_1;
    unsigned char column_2;
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
      ser_1[i_1] = 0;
      ser_2[i_2] = 0;
    }

    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[0] & 0x80) >> 6;
    row_2 |= (er_2[0] & 0x80) >> 6;
    row_1 |= (er_1[0] & 0x04) >> 2;
    row_2 |= (er_2[0] & 0x04) >> 2;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[0] & 0x78) >> 3;
    column_2 |= (er_2[0] & 0x78) >> 3;
    ser_1[0] |= ((unsigned char)S1_1[(row_1 * 16) + column_1]) << 4;
    ser_2[0] |= ((unsigned char)S1_2[(row_2 * 16) + column_2]) << 4;
    row_1 = 0;
    row_2 = 0;
    row_1 |= er_1[0] & 0x02;
    row_2 |= er_2[0] & 0x02;
    row_1 |= (er_1[1] & 0x10) >> 4;
    row_2 |= (er_2[1] & 0x10) >> 4;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[0] & 0x01) << 3;
    column_2 |= (er_2[0] & 0x01) << 3;
    column_1 |= (er_1[1] & 0xE0) >> 5;
    column_2 |= (er_2[1] & 0xE0) >> 5;
    ser_1[0] |= (unsigned char)S2_1[(row_1 * 16) + column_1];
    ser_2[0] |= (unsigned char)S2_2[(row_2 * 16) + column_2];
    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[1] & 0x08) >> 2;
    row_2 |= (er_2[1] & 0x08) >> 2;
    row_1 |= (er_1[2] & 0x40) >> 6;
    row_2 |= (er_2[2] & 0x40) >> 6;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[1] & 0x07) << 1;
    column_2 |= (er_2[1] & 0x07) << 1;
    column_1 |= (er_1[2] & 0x80) >> 7;
    column_2 |= (er_2[2] & 0x80) >> 7;
    ser_1[1] |= ((unsigned char)S3_1[(row_1 * 16) + column_1]) << 4;
    ser_2[1] |= ((unsigned char)S3_2[(row_2 * 16) + column_2]) << 4;
    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[2] & 0x20) >> 4;
    row_2 |= (er_2[2] & 0x20) >> 4;
    row_1 |= er_1[2] & 0x01;
    row_2 |= er_2[2] & 0x01;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[2] & 0x1E) >> 1;
    column_2 |= (er_2[2] & 0x1E) >> 1;
    ser_1[1] |= (unsigned char)S4_1[(row_1 * 16) + column_1];
    ser_2[1] |= (unsigned char)S4_2[(row_2 * 16) + column_2];
    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[3] & 0x80) >> 6;
    row_2 |= (er_2[3] & 0x80) >> 6;
    row_1 |= (er_1[3] & 0x04) >> 2;
    row_2 |= (er_2[3] & 0x04) >> 2;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[3] & 0x78) >> 3;
    column_2 |= (er_2[3] & 0x78) >> 3;
    ser_1[2] |= ((unsigned char)S5_1[(row_1 * 16) + column_1]) << 4;
    ser_2[2] |= ((unsigned char)S5_2[(row_2 * 16) + column_2]) << 4;
    row_1 = 0;
    row_2 = 0;
    row_1 |= er_1[3] & 0x02;
    row_2 |= er_2[3] & 0x02;
    row_1 |= (er_1[4] & 0x10) >> 4;
    row_2 |= (er_2[4] & 0x10) >> 4;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[3] & 0x01) << 3;
    column_2 |= (er_2[3] & 0x01) << 3;
    column_1 |= (er_1[4] & 0xE0) >> 5;
    column_2 |= (er_2[4] & 0xE0) >> 5;
    ser_1[2] |= (unsigned char)S6_1[(row_1 * 16) + column_1];
    ser_2[2] |= (unsigned char)S6_2[(row_2 * 16) + column_2];
    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[4] & 0x08) >> 2;
    row_2 |= (er_2[4] & 0x08) >> 2;
    row_1 |= (er_1[5] & 0x40) >> 6;
    row_2 |= (er_2[5] & 0x40) >> 6;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[4] & 0x07) << 1;
    column_2 |= (er_2[4] & 0x07) << 1;
    column_1 |= (er_1[5] & 0x80) >> 7;
    column_2 |= (er_2[5] & 0x80) >> 7;
    ser_1[3] |= ((unsigned char)S7_1[(row_1 * 16) + column_1]) << 4;
    ser_2[3] |= ((unsigned char)S7_2[(row_2 * 16) + column_2]) << 4;
    row_1 = 0;
    row_2 = 0;
    row_1 |= (er_1[5] & 0x20) >> 4;
    row_2 |= (er_2[5] & 0x20) >> 4;
    row_1 |= er_1[5] & 0x01;
    row_2 |= er_2[5] & 0x01;
    column_1 = 0;
    column_2 = 0;
    column_1 |= (er_1[5] & 0x1E) >> 1;
    column_2 |= (er_2[5] & 0x1E) >> 1;
    ser_1[3] |= (unsigned char)S8_1[(row_1 * 16) + column_1];
    ser_2[3] |= (unsigned char)S8_2[(row_2 * 16) + column_2];
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
      rn_1[i_1] = 0;
      rn_2[i_2] = 0;
    }

    for (i_1 = 0, i_2 = 0; (i_1 < 32) && (i_2 < 32); i_1++, i_2++) {
      shift_size_1 = right_sub_message_permutation_1[i_1];
      shift_size_2 = right_sub_message_permutation_2[i_2];
      shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
      shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
      shift_byte_1 &= ser_1[(shift_size_1 - 1) / 8];
      shift_byte_2 &= ser_2[(shift_size_2 - 1) / 8];
      shift_byte_1 <<= (shift_size_1 - 1) % 8;
      shift_byte_2 <<= (shift_size_2 - 1) % 8;
      rn_1[i_1 / 8] |= shift_byte_1 >> (i_1 % 8);
      rn_2[i_2 / 8] |= shift_byte_2 >> (i_2 % 8);
    }

    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
      rn_1[i_1] ^= l_1[i_1];
      rn_2[i_2] ^= l_2[i_2];
    }

    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
      l_1[i_1] = ln_1[i_1];
      l_2[i_2] = ln_2[i_2];
      r_1[i_1] = rn_1[i_1];
      r_2[i_2] = rn_2[i_2];
    }
  }

  unsigned char pre_end_permutation_1[8];
  unsigned char pre_end_permutation_2[8];
  for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++) {
    pre_end_permutation_1[i_1] = r_1[i_1];
    pre_end_permutation_2[i_2] = r_2[i_2];
    pre_end_permutation_1[4 + i_1] = l_1[i_1];
    pre_end_permutation_2[4 + i_2] = l_2[i_2];
  }

  for (i_1 = 0, i_2 = 0; (i_1 < 64) && (i_2 < 64); i_1++, i_2++) {
    shift_size_1 = final_message_permutation_1[i_1];
    shift_size_2 = final_message_permutation_2[i_2];
    shift_byte_1 = 0x80 >> ((shift_size_1 - 1) % 8);
    shift_byte_2 = 0x80 >> ((shift_size_2 - 1) % 8);
    shift_byte_1 &= pre_end_permutation_1[(shift_size_1 - 1) / 8];
    shift_byte_2 &= pre_end_permutation_2[(shift_size_2 - 1) / 8];
    shift_byte_1 <<= (shift_size_1 - 1) % 8;
    shift_byte_2 <<= (shift_size_2 - 1) % 8;
    processed_piece_1[i_1 / 8] |= shift_byte_1 >> (i_1 % 8);
    processed_piece_2[i_2 / 8] |= shift_byte_2 >> (i_2 % 8);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(initial_message_permutation_1[i_0] ==
           initial_message_permutation_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 48; i_0++) {
    assert(message_expansion_1[i_0] == message_expansion_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S1_1[i_0] == S1_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S2_1[i_0] == S2_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S3_1[i_0] == S3_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S4_1[i_0] == S4_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S5_1[i_0] == S5_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S6_1[i_0] == S6_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S7_1[i_0] == S7_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(S8_1[i_0] == S8_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 32; i_0++) {
    assert(right_sub_message_permutation_1[i_0] ==
           right_sub_message_permutation_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++) {
    assert(final_message_permutation_1[i_0] ==
           final_message_permutation_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(k_1 == k_2);
  assert(shift_size_1 == shift_size_2);
  assert(shift_byte_1 == shift_byte_2);
  for (int i_0 = 0; i_0 < 8; i_0++) {
    assert(initial_permutation_1[i_0] == initial_permutation_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(l_1[i_0] == l_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(r_1[i_0] == r_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(ln_1[i_0] == ln_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(rn_1[i_0] == rn_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 6; i_0++) {
    assert(er_1[i_0] == er_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(ser_1[i_0] == ser_2[i_0]);
  }

  assert(key_index_1 == key_index_2);
  for (int i_0 = 0; i_0 < 8; i_0++) {
    assert(pre_end_permutation_1[i_0] == pre_end_permutation_2[i_0]);
  }
}

void process_message(unsigned char *message_piece,
                     unsigned char *processed_piece, struct key_set *key_sets,
                     int mode) {
  int i;
  int k;
  int shift_size;
  unsigned char shift_byte;
  unsigned char initial_permutation[8];
  memset(initial_permutation, 0, 8);
  memset(processed_piece, 0, 8);
  for (i = 0; i < 64; i++) {
    shift_size = initial_message_permutation[i];
    shift_byte = 0x80 >> ((shift_size - 1) % 8);
    shift_byte &= message_piece[(shift_size - 1) / 8];
    shift_byte <<= (shift_size - 1) % 8;
    initial_permutation[i / 8] |= shift_byte >> (i % 8);
  }

  unsigned char l[4];
  unsigned char r[4];
  for (i = 0; i < 4; i++) {
    l[i] = initial_permutation[i];
    r[i] = initial_permutation[i + 4];
  }

  unsigned char ln[4];
  unsigned char rn[4];
  unsigned char er[6];
  unsigned char ser[4];
  int key_index;
  for (k = 1; k <= 16; k++) {
    memcpy(ln, r, 4);
    memset(er, 0, 6);
    for (i = 0; i < 48; i++) {
      shift_size = message_expansion[i];
      shift_byte = 0x80 >> ((shift_size - 1) % 8);
      shift_byte &= r[(shift_size - 1) / 8];
      shift_byte <<= (shift_size - 1) % 8;
      er[i / 8] |= shift_byte >> (i % 8);
    }

    if (mode == 0) {
      key_index = 17 - k;
    } else {
      key_index = k;
    }
    for (i = 0; i < 6; i++) {
      er[i] ^= key_sets[key_index].k[i];
    }

    unsigned char row;
    unsigned char column;
    for (i = 0; i < 4; i++) {
      ser[i] = 0;
    }

    row = 0;
    row |= (er[0] & 0x80) >> 6;
    row |= (er[0] & 0x04) >> 2;
    column = 0;
    column |= (er[0] & 0x78) >> 3;
    ser[0] |= ((unsigned char)S1[(row * 16) + column]) << 4;
    row = 0;
    row |= er[0] & 0x02;
    row |= (er[1] & 0x10) >> 4;
    column = 0;
    column |= (er[0] & 0x01) << 3;
    column |= (er[1] & 0xE0) >> 5;
    ser[0] |= (unsigned char)S2[(row * 16) + column];
    row = 0;
    row |= (er[1] & 0x08) >> 2;
    row |= (er[2] & 0x40) >> 6;
    column = 0;
    column |= (er[1] & 0x07) << 1;
    column |= (er[2] & 0x80) >> 7;
    ser[1] |= ((unsigned char)S3[(row * 16) + column]) << 4;
    row = 0;
    row |= (er[2] & 0x20) >> 4;
    row |= er[2] & 0x01;
    column = 0;
    column |= (er[2] & 0x1E) >> 1;
    ser[1] |= (unsigned char)S4[(row * 16) + column];
    row = 0;
    row |= (er[3] & 0x80) >> 6;
    row |= (er[3] & 0x04) >> 2;
    column = 0;
    column |= (er[3] & 0x78) >> 3;
    ser[2] |= ((unsigned char)S5[(row * 16) + column]) << 4;
    row = 0;
    row |= er[3] & 0x02;
    row |= (er[4] & 0x10) >> 4;
    column = 0;
    column |= (er[3] & 0x01) << 3;
    column |= (er[4] & 0xE0) >> 5;
    ser[2] |= (unsigned char)S6[(row * 16) + column];
    row = 0;
    row |= (er[4] & 0x08) >> 2;
    row |= (er[5] & 0x40) >> 6;
    column = 0;
    column |= (er[4] & 0x07) << 1;
    column |= (er[5] & 0x80) >> 7;
    ser[3] |= ((unsigned char)S7[(row * 16) + column]) << 4;
    row = 0;
    row |= (er[5] & 0x20) >> 4;
    row |= er[5] & 0x01;
    column = 0;
    column |= (er[5] & 0x1E) >> 1;
    ser[3] |= (unsigned char)S8[(row * 16) + column];
    for (i = 0; i < 4; i++) {
      rn[i] = 0;
    }

    for (i = 0; i < 32; i++) {
      shift_size = right_sub_message_permutation[i];
      shift_byte = 0x80 >> ((shift_size - 1) % 8);
      shift_byte &= ser[(shift_size - 1) / 8];
      shift_byte <<= (shift_size - 1) % 8;
      rn[i / 8] |= shift_byte >> (i % 8);
    }

    for (i = 0; i < 4; i++) {
      rn[i] ^= l[i];
    }

    for (i = 0; i < 4; i++) {
      l[i] = ln[i];
      r[i] = rn[i];
    }
  }

  unsigned char pre_end_permutation[8];
  for (i = 0; i < 4; i++) {
    pre_end_permutation[i] = r[i];
    pre_end_permutation[4 + i] = l[i];
  }

  for (i = 0; i < 64; i++) {
    shift_size = final_message_permutation[i];
    shift_byte = 0x80 >> ((shift_size - 1) % 8);
    shift_byte &= pre_end_permutation[(shift_size - 1) / 8];
    shift_byte <<= (shift_size - 1) % 8;
    processed_piece[i / 8] |= shift_byte >> (i % 8);
  }
}

void main() {
  struct key_set *key_sets_1;
  struct key_set *key_sets_2;
  unsigned char *des_key_1;
  unsigned char *des_key_2;
  unsigned char *data_block_1;
  unsigned char *data_block_2;
  unsigned char *processed_block_1;
  unsigned char *processed_block_2;
  int process_mode_1 = 1;
  int process_mode_2 = 1;
  generate_sub_keys(des_key_1, key_sets_1);
  generate_sub_keys(des_key_2, key_sets_2);
  generate_sub_keys_2(des_key_1, key_sets_1, des_key_2, key_sets_2);
  process_message(data_block_1, processed_block_1, key_sets_1, process_mode_1);
  process_message(data_block_2, processed_block_2, key_sets_2, process_mode_2);
  process_message_2(data_block_1, processed_block_1, key_sets_1, process_mode_1,
                    data_block_2, processed_block_2, key_sets_2,
                    process_mode_2);
  __CPROVER_assume((*data_block_1) == (*data_block_2));
  __CPROVER_assume((*des_key_1) != (*des_key_2));
  __CPROVER_assume((*key_sets_1).c != (*key_sets_2).c);
  __CPROVER_assume((*key_sets_1).d != (*key_sets_2).d);
  __CPROVER_assume((*key_sets_1).k != (*key_sets_2).k);
  assert((*processed_block_1) == (*processed_block_2));
  assert(process_mode_1 == process_mode_2);
}
