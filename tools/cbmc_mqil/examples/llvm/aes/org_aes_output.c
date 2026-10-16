int type_1;
int type_2;
int type;
int nb_1;
int nb_2;
int nb;
int round_val_1;
int round_val_2;
int round_val;
int key_1[32];
int key_2[32];
int key[32];
int statemt_1[32];
int statemt_2[32];
int statemt[32];
int word_1[4][120];
int word_2[4][120];
int word[4][120];
int KeySchedule(int, int *);
int SubByte(int);
void ByteSub_ShiftRow(int *, int);
void InversShiftRow_ByteSub(int *, int);
int MixColumn_AddRoundKey(int *, int, int);
int AddRoundKey_InversMixColumn(int *, int, int);
int AddRoundKey(int *, int, int);
int encrypt(int *, int *, int);
int decrypt(int *, int *, int);
int main_result_1;
int main_result_2;
int main_result;
int nd_key();
void decrypt_2(int statemt_1[32], int key_1[32], int type_1, int statemt_2[32], int key_2[32], int type_2)
{
  int i_1;
  int i_2;
  const int out_dec_statemt_1[16];
  const int out_dec_statemt_2[16];
  KeySchedule(type_1, key_1);
  KeySchedule(type_2, key_2);
  KeySchedule_2(type_1, key_1, type_2, key_2);
  switch (type_1)
  {
    case 128128:
      round_val_1 = 10;
      nb_1 = 4;
      break;

    case 128192:

    case 192192:
      round_val_1 = 12;
      nb_1 = 6;
      break;

    case 192128:
      round_val_1 = 12;
      nb_1 = 4;
      break;

    case 128256:

    case 192256:
      round_val_1 = 14;
      nb_1 = 8;
      break;

    case 256128:
      round_val_1 = 14;
      nb_1 = 4;
      break;

    case 256192:
      round_val_1 = 14;
      nb_1 = 6;
      break;

    case 256256:
      round_val_1 = 14;
      nb_1 = 8;
      break;

  }

  switch (type_2)
  {
    case 128128:
      round_val_2 = 10;
      nb_2 = 4;
      break;

    case 128192:

    case 192192:
      round_val_2 = 12;
      nb_2 = 6;
      break;

    case 192128:
      round_val_2 = 12;
      nb_2 = 4;
      break;

    case 128256:

    case 192256:
      round_val_2 = 14;
      nb_2 = 8;
      break;

    case 256128:
      round_val_2 = 14;
      nb_2 = 4;
      break;

    case 256192:
      round_val_2 = 14;
      nb_2 = 6;
      break;

    case 256256:
      round_val_2 = 14;
      nb_2 = 8;
      break;

  }

  AddRoundKey(statemt_1, type_1, round_val_1);
  AddRoundKey(statemt_2, type_2, round_val_2);
  AddRoundKey_2(statemt_1, type_1, round_val_1, statemt_2, type_2, round_val_2);
  InversShiftRow_ByteSub(statemt_1, nb_1);
  InversShiftRow_ByteSub(statemt_2, nb_2);
  InversShiftRow_ByteSub_2(statemt_1, nb_1, statemt_2, nb_2);
  for (i_1 = round_val_1 - 1, i_2 = round_val_2 - 1; (i_1 >= 1) && (i_2 >= 1); --i_1, --i_2)
  {
    AddRoundKey_InversMixColumn(statemt_1, nb_1, i_1);
    AddRoundKey_InversMixColumn(statemt_2, nb_2, i_2);
    AddRoundKey_InversMixColumn_2(statemt_1, nb_1, i_1, statemt_2, nb_2, i_2);
    InversShiftRow_ByteSub(statemt_1, nb_1);
    InversShiftRow_ByteSub(statemt_2, nb_2);
    InversShiftRow_ByteSub_2(statemt_1, nb_1, statemt_2, nb_2);
  }

  AddRoundKey(statemt_1, type_1, 0);
  AddRoundKey(statemt_2, type_2, 0);
  AddRoundKey_2(statemt_1, type_1, 0, statemt_2, type_2, 0);
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    main_result_1 += statemt_1[i_1] != out_dec_statemt_1[i_1];
    main_result_2 += statemt_2[i_2] != out_dec_statemt_2[i_2];
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  assert(round_val_1 == round_val_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
  assert(i_1 == i_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(out_dec_statemt_1[i_0] == out_dec_statemt_2[i_0]);
  }

}

int decrypt(int statemt[32], int key[32], int type)
{
  int i;
  const int out_dec_statemt[16];
  KeySchedule(type, key);
  switch (type)
  {
    case 128128:
      round_val = 10;
      nb = 4;
      break;

    case 128192:

    case 192192:
      round_val = 12;
      nb = 6;
      break;

    case 192128:
      round_val = 12;
      nb = 4;
      break;

    case 128256:

    case 192256:
      round_val = 14;
      nb = 8;
      break;

    case 256128:
      round_val = 14;
      nb = 4;
      break;

    case 256192:
      round_val = 14;
      nb = 6;
      break;

    case 256256:
      round_val = 14;
      nb = 8;
      break;

  }

  AddRoundKey(statemt, type, round_val);
  InversShiftRow_ByteSub(statemt, nb);
  for (i = round_val - 1; i >= 1; --i)
  {
    AddRoundKey_InversMixColumn(statemt, nb, i);
    InversShiftRow_ByteSub(statemt, nb);
  }

  AddRoundKey(statemt, type, 0);
  for (i = 0; i < 16; i++)
  {
    main_result += statemt[i] != out_dec_statemt[i];
  }

  return 0;
}

void encrypt_2(int statemt_1[32], int key_1[32], int type_1, int statemt_2[32], int key_2[32], int type_2)
{
  int i_1;
  int i_2;
  const int out_enc_statemt_1[16] = {0x39, 0x25, 0x84, 0x1d, 0x2, 0xdc, 0x9, 0xfb, 0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0xb, 0x32};
  const int out_enc_statemt_2[16] = {0x39, 0x25, 0x84, 0x1d, 0x2, 0xdc, 0x9, 0xfb, 0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0xb, 0x32};
  KeySchedule(type_1, key_1);
  KeySchedule(type_2, key_2);
  KeySchedule_2(type_1, key_1, type_2, key_2);
  switch (type_1)
  {
    case 128128:
      round_val_1 = 0;
      nb_1 = 4;
      break;

    case 192128:
      round_val_1 = 2;
      nb_1 = 4;
      break;

    case 256128:
      round_val_1 = 4;
      nb_1 = 4;
      break;

    case 128192:

    case 192192:
      round_val_1 = 2;
      nb_1 = 6;
      break;

    case 256192:
      round_val_1 = 4;
      nb_1 = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      round_val_1 = 4;
      nb_1 = 8;
      break;

  }

  switch (type_2)
  {
    case 128128:
      round_val_2 = 0;
      nb_2 = 4;
      break;

    case 192128:
      round_val_2 = 2;
      nb_2 = 4;
      break;

    case 256128:
      round_val_2 = 4;
      nb_2 = 4;
      break;

    case 128192:

    case 192192:
      round_val_2 = 2;
      nb_2 = 6;
      break;

    case 256192:
      round_val_2 = 4;
      nb_2 = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      round_val_2 = 4;
      nb_2 = 8;
      break;

  }

  AddRoundKey(statemt_1, type_1, 0);
  AddRoundKey(statemt_2, type_2, 0);
  AddRoundKey_2(statemt_1, type_1, 0, statemt_2, type_2, 0);
  for (i_1 = 1, i_2 = 1; (i_1 <= (round_val_1 + 9)) && (i_2 <= (round_val_2 + 9)); ++i_1, ++i_2)
  {
    ByteSub_ShiftRow(statemt_1, nb_1);
    ByteSub_ShiftRow(statemt_2, nb_2);
    ByteSub_ShiftRow_2(statemt_1, nb_1, statemt_2, nb_2);
    MixColumn_AddRoundKey(statemt_1, nb_1, i_1);
    MixColumn_AddRoundKey(statemt_2, nb_2, i_2);
    MixColumn_AddRoundKey_2(statemt_1, nb_1, i_1, statemt_2, nb_2, i_2);
  }

  ByteSub_ShiftRow(statemt_1, nb_1);
  ByteSub_ShiftRow(statemt_2, nb_2);
  ByteSub_ShiftRow_2(statemt_1, nb_1, statemt_2, nb_2);
  AddRoundKey(statemt_1, type_1, i_1);
  AddRoundKey(statemt_2, type_2, i_2);
  AddRoundKey_2(statemt_1, type_1, i_1, statemt_2, type_2, i_2);
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    main_result_1 += statemt_1[i_1] != out_enc_statemt_1[i_1];
    main_result_2 += statemt_2[i_2] != out_enc_statemt_2[i_2];
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  assert(round_val_1 == round_val_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
  assert(i_1 == i_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(out_enc_statemt_1[i_0] == out_enc_statemt_2[i_0]);
  }

}

int encrypt(int statemt[32], int key[32], int type)
{
  int i;
  const int out_enc_statemt[16] = {0x39, 0x25, 0x84, 0x1d, 0x2, 0xdc, 0x9, 0xfb, 0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0xb, 0x32};
  KeySchedule(type, key);
  switch (type)
  {
    case 128128:
      round_val = 0;
      nb = 4;
      break;

    case 192128:
      round_val = 2;
      nb = 4;
      break;

    case 256128:
      round_val = 4;
      nb = 4;
      break;

    case 128192:

    case 192192:
      round_val = 2;
      nb = 6;
      break;

    case 256192:
      round_val = 4;
      nb = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      round_val = 4;
      nb = 8;
      break;

  }

  AddRoundKey(statemt, type, 0);
  for (i = 1; i <= (round_val + 9); ++i)
  {
    ByteSub_ShiftRow(statemt, nb);
    MixColumn_AddRoundKey(statemt, nb, i);
  }

  ByteSub_ShiftRow(statemt, nb);
  AddRoundKey(statemt, type, i);
  for (i = 0; i < 16; i++)
  {
    main_result += statemt[i] != out_enc_statemt[i];
  }

  return 0;
}

const int Sbox_1[16][16];
const int Sbox_2[16][16];
const int Sbox[16][16];
const int invSbox_1[16][16];
const int invSbox_2[16][16];
const int invSbox[16][16];
void ByteSub_ShiftRow_2(int statemt_1[32], int nb_1, int statemt_2[32], int nb_2)
{
  int temp_1;
  int temp_2;
  switch (nb_1)
  {
    case 4:
      temp_1 = Sbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = Sbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = Sbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = Sbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = temp_1;
      temp_1 = Sbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = Sbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = temp_1;
      temp_1 = Sbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = Sbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = temp_1;
      temp_1 = Sbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = Sbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = Sbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = Sbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = temp_1;
      statemt_1[0] = Sbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = Sbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = Sbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = Sbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      break;

    case 6:
      temp_1 = Sbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = Sbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = Sbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = Sbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = Sbox_1[statemt_1[17] >> 4][statemt_1[17] & 0xf];
      statemt_1[17] = Sbox_1[statemt_1[21] >> 4][statemt_1[21] & 0xf];
      statemt_1[21] = temp_1;
      temp_1 = Sbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = Sbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = Sbox_1[statemt_1[18] >> 4][statemt_1[18] & 0xf];
      statemt_1[18] = temp_1;
      temp_1 = Sbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = Sbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = Sbox_1[statemt_1[22] >> 4][statemt_1[22] & 0xf];
      statemt_1[22] = temp_1;
      temp_1 = Sbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = Sbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = temp_1;
      temp_1 = Sbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = Sbox_1[statemt_1[19] >> 4][statemt_1[19] & 0xf];
      statemt_1[19] = temp_1;
      temp_1 = Sbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = Sbox_1[statemt_1[23] >> 4][statemt_1[23] & 0xf];
      statemt_1[23] = temp_1;
      statemt_1[0] = Sbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = Sbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = Sbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = Sbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      statemt_1[16] = Sbox_1[statemt_1[16] >> 4][statemt_1[16] & 0xf];
      statemt_1[20] = Sbox_1[statemt_1[20] >> 4][statemt_1[20] & 0xf];
      break;

    case 8:
      temp_1 = Sbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = Sbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = Sbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = Sbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = Sbox_1[statemt_1[17] >> 4][statemt_1[17] & 0xf];
      statemt_1[17] = Sbox_1[statemt_1[21] >> 4][statemt_1[21] & 0xf];
      statemt_1[21] = Sbox_1[statemt_1[25] >> 4][statemt_1[25] & 0xf];
      statemt_1[25] = Sbox_1[statemt_1[29] >> 4][statemt_1[29] & 0xf];
      statemt_1[29] = temp_1;
      temp_1 = Sbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = Sbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = Sbox_1[statemt_1[26] >> 4][statemt_1[26] & 0xf];
      statemt_1[26] = Sbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = Sbox_1[statemt_1[18] >> 4][statemt_1[18] & 0xf];
      statemt_1[18] = Sbox_1[statemt_1[30] >> 4][statemt_1[30] & 0xf];
      statemt_1[30] = Sbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = Sbox_1[statemt_1[22] >> 4][statemt_1[22] & 0xf];
      statemt_1[22] = temp_1;
      temp_1 = Sbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = Sbox_1[statemt_1[19] >> 4][statemt_1[19] & 0xf];
      statemt_1[19] = temp_1;
      temp_1 = Sbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = Sbox_1[statemt_1[23] >> 4][statemt_1[23] & 0xf];
      statemt_1[23] = temp_1;
      temp_1 = Sbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = Sbox_1[statemt_1[27] >> 4][statemt_1[27] & 0xf];
      statemt_1[27] = temp_1;
      temp_1 = Sbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = Sbox_1[statemt_1[31] >> 4][statemt_1[31] & 0xf];
      statemt_1[31] = temp_1;
      statemt_1[0] = Sbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = Sbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = Sbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = Sbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      statemt_1[16] = Sbox_1[statemt_1[16] >> 4][statemt_1[16] & 0xf];
      statemt_1[20] = Sbox_1[statemt_1[20] >> 4][statemt_1[20] & 0xf];
      statemt_1[24] = Sbox_1[statemt_1[24] >> 4][statemt_1[24] & 0xf];
      statemt_1[28] = Sbox_1[statemt_1[28] >> 4][statemt_1[28] & 0xf];
      break;

  }

  switch (nb_2)
  {
    case 4:
      temp_2 = Sbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = Sbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = Sbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = Sbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = temp_2;
      temp_2 = Sbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = Sbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = temp_2;
      temp_2 = Sbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = Sbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = temp_2;
      temp_2 = Sbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = Sbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = Sbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = Sbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = temp_2;
      statemt_2[0] = Sbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = Sbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = Sbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = Sbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      break;

    case 6:
      temp_2 = Sbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = Sbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = Sbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = Sbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = Sbox_2[statemt_2[17] >> 4][statemt_2[17] & 0xf];
      statemt_2[17] = Sbox_2[statemt_2[21] >> 4][statemt_2[21] & 0xf];
      statemt_2[21] = temp_2;
      temp_2 = Sbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = Sbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = Sbox_2[statemt_2[18] >> 4][statemt_2[18] & 0xf];
      statemt_2[18] = temp_2;
      temp_2 = Sbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = Sbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = Sbox_2[statemt_2[22] >> 4][statemt_2[22] & 0xf];
      statemt_2[22] = temp_2;
      temp_2 = Sbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = Sbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = temp_2;
      temp_2 = Sbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = Sbox_2[statemt_2[19] >> 4][statemt_2[19] & 0xf];
      statemt_2[19] = temp_2;
      temp_2 = Sbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = Sbox_2[statemt_2[23] >> 4][statemt_2[23] & 0xf];
      statemt_2[23] = temp_2;
      statemt_2[0] = Sbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = Sbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = Sbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = Sbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      statemt_2[16] = Sbox_2[statemt_2[16] >> 4][statemt_2[16] & 0xf];
      statemt_2[20] = Sbox_2[statemt_2[20] >> 4][statemt_2[20] & 0xf];
      break;

    case 8:
      temp_2 = Sbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = Sbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = Sbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = Sbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = Sbox_2[statemt_2[17] >> 4][statemt_2[17] & 0xf];
      statemt_2[17] = Sbox_2[statemt_2[21] >> 4][statemt_2[21] & 0xf];
      statemt_2[21] = Sbox_2[statemt_2[25] >> 4][statemt_2[25] & 0xf];
      statemt_2[25] = Sbox_2[statemt_2[29] >> 4][statemt_2[29] & 0xf];
      statemt_2[29] = temp_2;
      temp_2 = Sbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = Sbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = Sbox_2[statemt_2[26] >> 4][statemt_2[26] & 0xf];
      statemt_2[26] = Sbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = Sbox_2[statemt_2[18] >> 4][statemt_2[18] & 0xf];
      statemt_2[18] = Sbox_2[statemt_2[30] >> 4][statemt_2[30] & 0xf];
      statemt_2[30] = Sbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = Sbox_2[statemt_2[22] >> 4][statemt_2[22] & 0xf];
      statemt_2[22] = temp_2;
      temp_2 = Sbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = Sbox_2[statemt_2[19] >> 4][statemt_2[19] & 0xf];
      statemt_2[19] = temp_2;
      temp_2 = Sbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = Sbox_2[statemt_2[23] >> 4][statemt_2[23] & 0xf];
      statemt_2[23] = temp_2;
      temp_2 = Sbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = Sbox_2[statemt_2[27] >> 4][statemt_2[27] & 0xf];
      statemt_2[27] = temp_2;
      temp_2 = Sbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = Sbox_2[statemt_2[31] >> 4][statemt_2[31] & 0xf];
      statemt_2[31] = temp_2;
      statemt_2[0] = Sbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = Sbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = Sbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = Sbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      statemt_2[16] = Sbox_2[statemt_2[16] >> 4][statemt_2[16] & 0xf];
      statemt_2[20] = Sbox_2[statemt_2[20] >> 4][statemt_2[20] & 0xf];
      statemt_2[24] = Sbox_2[statemt_2[24] >> 4][statemt_2[24] & 0xf];
      statemt_2[28] = Sbox_2[statemt_2[28] >> 4][statemt_2[28] & 0xf];
      break;

  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  assert(temp_1 == temp_2);
}

void ByteSub_ShiftRow(int statemt[32], int nb)
{
  int temp;
  switch (nb)
  {
    case 4:
      temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = temp;
      temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = temp;
      temp = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = temp;
      temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = temp;
      statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
      break;

    case 6:
      temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = Sbox[statemt[17] >> 4][statemt[17] & 0xf];
      statemt[17] = Sbox[statemt[21] >> 4][statemt[21] & 0xf];
      statemt[21] = temp;
      temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = Sbox[statemt[18] >> 4][statemt[18] & 0xf];
      statemt[18] = temp;
      temp = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = Sbox[statemt[22] >> 4][statemt[22] & 0xf];
      statemt[22] = temp;
      temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = temp;
      temp = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = Sbox[statemt[19] >> 4][statemt[19] & 0xf];
      statemt[19] = temp;
      temp = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = Sbox[statemt[23] >> 4][statemt[23] & 0xf];
      statemt[23] = temp;
      statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
      statemt[16] = Sbox[statemt[16] >> 4][statemt[16] & 0xf];
      statemt[20] = Sbox[statemt[20] >> 4][statemt[20] & 0xf];
      break;

    case 8:
      temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = Sbox[statemt[17] >> 4][statemt[17] & 0xf];
      statemt[17] = Sbox[statemt[21] >> 4][statemt[21] & 0xf];
      statemt[21] = Sbox[statemt[25] >> 4][statemt[25] & 0xf];
      statemt[25] = Sbox[statemt[29] >> 4][statemt[29] & 0xf];
      statemt[29] = temp;
      temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = Sbox[statemt[26] >> 4][statemt[26] & 0xf];
      statemt[26] = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = Sbox[statemt[18] >> 4][statemt[18] & 0xf];
      statemt[18] = Sbox[statemt[30] >> 4][statemt[30] & 0xf];
      statemt[30] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = Sbox[statemt[22] >> 4][statemt[22] & 0xf];
      statemt[22] = temp;
      temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = Sbox[statemt[19] >> 4][statemt[19] & 0xf];
      statemt[19] = temp;
      temp = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = Sbox[statemt[23] >> 4][statemt[23] & 0xf];
      statemt[23] = temp;
      temp = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = Sbox[statemt[27] >> 4][statemt[27] & 0xf];
      statemt[27] = temp;
      temp = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = Sbox[statemt[31] >> 4][statemt[31] & 0xf];
      statemt[31] = temp;
      statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
      statemt[16] = Sbox[statemt[16] >> 4][statemt[16] & 0xf];
      statemt[20] = Sbox[statemt[20] >> 4][statemt[20] & 0xf];
      statemt[24] = Sbox[statemt[24] >> 4][statemt[24] & 0xf];
      statemt[28] = Sbox[statemt[28] >> 4][statemt[28] & 0xf];
      break;

  }

}

void SubByte_2(int in_1, int in_2)
{
}

int SubByte(int in)
{
  return Sbox[in / 16][in % 16];
}

void InversShiftRow_ByteSub_2(int statemt_1[32], int nb_1, int statemt_2[32], int nb_2)
{
  int temp_1;
  int temp_2;
  switch (nb_1)
  {
    case 4:
      temp_1 = invSbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = invSbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = invSbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = invSbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = temp_1;
      temp_1 = invSbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = invSbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = temp_1;
      temp_1 = invSbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = invSbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = temp_1;
      temp_1 = invSbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = invSbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = invSbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = invSbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = temp_1;
      statemt_1[0] = invSbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = invSbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = invSbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = invSbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      break;

    case 6:
      temp_1 = invSbox_1[statemt_1[21] >> 4][statemt_1[21] & 0xf];
      statemt_1[21] = invSbox_1[statemt_1[17] >> 4][statemt_1[17] & 0xf];
      statemt_1[17] = invSbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = invSbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = invSbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = invSbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = temp_1;
      temp_1 = invSbox_1[statemt_1[22] >> 4][statemt_1[22] & 0xf];
      statemt_1[22] = invSbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = invSbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = temp_1;
      temp_1 = invSbox_1[statemt_1[18] >> 4][statemt_1[18] & 0xf];
      statemt_1[18] = invSbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = invSbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = temp_1;
      temp_1 = invSbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = invSbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = temp_1;
      temp_1 = invSbox_1[statemt_1[19] >> 4][statemt_1[19] & 0xf];
      statemt_1[19] = invSbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = temp_1;
      temp_1 = invSbox_1[statemt_1[23] >> 4][statemt_1[23] & 0xf];
      statemt_1[23] = invSbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = temp_1;
      statemt_1[0] = invSbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = invSbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = invSbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = invSbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      statemt_1[16] = invSbox_1[statemt_1[16] >> 4][statemt_1[16] & 0xf];
      statemt_1[20] = invSbox_1[statemt_1[20] >> 4][statemt_1[20] & 0xf];
      break;

    case 8:
      temp_1 = invSbox_1[statemt_1[29] >> 4][statemt_1[29] & 0xf];
      statemt_1[29] = invSbox_1[statemt_1[25] >> 4][statemt_1[25] & 0xf];
      statemt_1[25] = invSbox_1[statemt_1[21] >> 4][statemt_1[21] & 0xf];
      statemt_1[21] = invSbox_1[statemt_1[17] >> 4][statemt_1[17] & 0xf];
      statemt_1[17] = invSbox_1[statemt_1[13] >> 4][statemt_1[13] & 0xf];
      statemt_1[13] = invSbox_1[statemt_1[9] >> 4][statemt_1[9] & 0xf];
      statemt_1[9] = invSbox_1[statemt_1[5] >> 4][statemt_1[5] & 0xf];
      statemt_1[5] = invSbox_1[statemt_1[1] >> 4][statemt_1[1] & 0xf];
      statemt_1[1] = temp_1;
      temp_1 = invSbox_1[statemt_1[30] >> 4][statemt_1[30] & 0xf];
      statemt_1[30] = invSbox_1[statemt_1[18] >> 4][statemt_1[18] & 0xf];
      statemt_1[18] = invSbox_1[statemt_1[6] >> 4][statemt_1[6] & 0xf];
      statemt_1[6] = invSbox_1[statemt_1[26] >> 4][statemt_1[26] & 0xf];
      statemt_1[26] = invSbox_1[statemt_1[14] >> 4][statemt_1[14] & 0xf];
      statemt_1[14] = invSbox_1[statemt_1[2] >> 4][statemt_1[2] & 0xf];
      statemt_1[2] = invSbox_1[statemt_1[22] >> 4][statemt_1[22] & 0xf];
      statemt_1[22] = invSbox_1[statemt_1[10] >> 4][statemt_1[10] & 0xf];
      statemt_1[10] = temp_1;
      temp_1 = invSbox_1[statemt_1[31] >> 4][statemt_1[31] & 0xf];
      statemt_1[31] = invSbox_1[statemt_1[15] >> 4][statemt_1[15] & 0xf];
      statemt_1[15] = temp_1;
      temp_1 = invSbox_1[statemt_1[27] >> 4][statemt_1[27] & 0xf];
      statemt_1[27] = invSbox_1[statemt_1[11] >> 4][statemt_1[11] & 0xf];
      statemt_1[11] = temp_1;
      temp_1 = invSbox_1[statemt_1[23] >> 4][statemt_1[23] & 0xf];
      statemt_1[23] = invSbox_1[statemt_1[7] >> 4][statemt_1[7] & 0xf];
      statemt_1[7] = temp_1;
      temp_1 = invSbox_1[statemt_1[19] >> 4][statemt_1[19] & 0xf];
      statemt_1[19] = invSbox_1[statemt_1[3] >> 4][statemt_1[3] & 0xf];
      statemt_1[3] = temp_1;
      statemt_1[0] = invSbox_1[statemt_1[0] >> 4][statemt_1[0] & 0xf];
      statemt_1[4] = invSbox_1[statemt_1[4] >> 4][statemt_1[4] & 0xf];
      statemt_1[8] = invSbox_1[statemt_1[8] >> 4][statemt_1[8] & 0xf];
      statemt_1[12] = invSbox_1[statemt_1[12] >> 4][statemt_1[12] & 0xf];
      statemt_1[16] = invSbox_1[statemt_1[16] >> 4][statemt_1[16] & 0xf];
      statemt_1[20] = invSbox_1[statemt_1[20] >> 4][statemt_1[20] & 0xf];
      statemt_1[24] = invSbox_1[statemt_1[24] >> 4][statemt_1[24] & 0xf];
      statemt_1[28] = invSbox_1[statemt_1[28] >> 4][statemt_1[28] & 0xf];
      break;

  }

  switch (nb_2)
  {
    case 4:
      temp_2 = invSbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = invSbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = invSbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = invSbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = temp_2;
      temp_2 = invSbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = invSbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = temp_2;
      temp_2 = invSbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = invSbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = temp_2;
      temp_2 = invSbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = invSbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = invSbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = invSbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = temp_2;
      statemt_2[0] = invSbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = invSbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = invSbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = invSbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      break;

    case 6:
      temp_2 = invSbox_2[statemt_2[21] >> 4][statemt_2[21] & 0xf];
      statemt_2[21] = invSbox_2[statemt_2[17] >> 4][statemt_2[17] & 0xf];
      statemt_2[17] = invSbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = invSbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = invSbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = invSbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = temp_2;
      temp_2 = invSbox_2[statemt_2[22] >> 4][statemt_2[22] & 0xf];
      statemt_2[22] = invSbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = invSbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = temp_2;
      temp_2 = invSbox_2[statemt_2[18] >> 4][statemt_2[18] & 0xf];
      statemt_2[18] = invSbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = invSbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = temp_2;
      temp_2 = invSbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = invSbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = temp_2;
      temp_2 = invSbox_2[statemt_2[19] >> 4][statemt_2[19] & 0xf];
      statemt_2[19] = invSbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = temp_2;
      temp_2 = invSbox_2[statemt_2[23] >> 4][statemt_2[23] & 0xf];
      statemt_2[23] = invSbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = temp_2;
      statemt_2[0] = invSbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = invSbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = invSbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = invSbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      statemt_2[16] = invSbox_2[statemt_2[16] >> 4][statemt_2[16] & 0xf];
      statemt_2[20] = invSbox_2[statemt_2[20] >> 4][statemt_2[20] & 0xf];
      break;

    case 8:
      temp_2 = invSbox_2[statemt_2[29] >> 4][statemt_2[29] & 0xf];
      statemt_2[29] = invSbox_2[statemt_2[25] >> 4][statemt_2[25] & 0xf];
      statemt_2[25] = invSbox_2[statemt_2[21] >> 4][statemt_2[21] & 0xf];
      statemt_2[21] = invSbox_2[statemt_2[17] >> 4][statemt_2[17] & 0xf];
      statemt_2[17] = invSbox_2[statemt_2[13] >> 4][statemt_2[13] & 0xf];
      statemt_2[13] = invSbox_2[statemt_2[9] >> 4][statemt_2[9] & 0xf];
      statemt_2[9] = invSbox_2[statemt_2[5] >> 4][statemt_2[5] & 0xf];
      statemt_2[5] = invSbox_2[statemt_2[1] >> 4][statemt_2[1] & 0xf];
      statemt_2[1] = temp_2;
      temp_2 = invSbox_2[statemt_2[30] >> 4][statemt_2[30] & 0xf];
      statemt_2[30] = invSbox_2[statemt_2[18] >> 4][statemt_2[18] & 0xf];
      statemt_2[18] = invSbox_2[statemt_2[6] >> 4][statemt_2[6] & 0xf];
      statemt_2[6] = invSbox_2[statemt_2[26] >> 4][statemt_2[26] & 0xf];
      statemt_2[26] = invSbox_2[statemt_2[14] >> 4][statemt_2[14] & 0xf];
      statemt_2[14] = invSbox_2[statemt_2[2] >> 4][statemt_2[2] & 0xf];
      statemt_2[2] = invSbox_2[statemt_2[22] >> 4][statemt_2[22] & 0xf];
      statemt_2[22] = invSbox_2[statemt_2[10] >> 4][statemt_2[10] & 0xf];
      statemt_2[10] = temp_2;
      temp_2 = invSbox_2[statemt_2[31] >> 4][statemt_2[31] & 0xf];
      statemt_2[31] = invSbox_2[statemt_2[15] >> 4][statemt_2[15] & 0xf];
      statemt_2[15] = temp_2;
      temp_2 = invSbox_2[statemt_2[27] >> 4][statemt_2[27] & 0xf];
      statemt_2[27] = invSbox_2[statemt_2[11] >> 4][statemt_2[11] & 0xf];
      statemt_2[11] = temp_2;
      temp_2 = invSbox_2[statemt_2[23] >> 4][statemt_2[23] & 0xf];
      statemt_2[23] = invSbox_2[statemt_2[7] >> 4][statemt_2[7] & 0xf];
      statemt_2[7] = temp_2;
      temp_2 = invSbox_2[statemt_2[19] >> 4][statemt_2[19] & 0xf];
      statemt_2[19] = invSbox_2[statemt_2[3] >> 4][statemt_2[3] & 0xf];
      statemt_2[3] = temp_2;
      statemt_2[0] = invSbox_2[statemt_2[0] >> 4][statemt_2[0] & 0xf];
      statemt_2[4] = invSbox_2[statemt_2[4] >> 4][statemt_2[4] & 0xf];
      statemt_2[8] = invSbox_2[statemt_2[8] >> 4][statemt_2[8] & 0xf];
      statemt_2[12] = invSbox_2[statemt_2[12] >> 4][statemt_2[12] & 0xf];
      statemt_2[16] = invSbox_2[statemt_2[16] >> 4][statemt_2[16] & 0xf];
      statemt_2[20] = invSbox_2[statemt_2[20] >> 4][statemt_2[20] & 0xf];
      statemt_2[24] = invSbox_2[statemt_2[24] >> 4][statemt_2[24] & 0xf];
      statemt_2[28] = invSbox_2[statemt_2[28] >> 4][statemt_2[28] & 0xf];
      break;

  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(invSbox_1[i_0][i_1] == invSbox_2[i_0][i_1]);
    }

  }

  assert(temp_1 == temp_2);
}

void InversShiftRow_ByteSub(int statemt[32], int nb)
{
  int temp;
  switch (nb)
  {
    case 4:
      temp = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = temp;
      temp = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = temp;
      temp = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = temp;
      temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = temp;
      statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
      break;

    case 6:
      temp = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
      statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
      statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = temp;
      temp = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
      statemt[22] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = temp;
      temp = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
      statemt[18] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = temp;
      temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = temp;
      temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
      statemt[19] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = temp;
      temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
      statemt[23] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = temp;
      statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
      statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
      statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
      break;

    case 8:
      temp = invSbox[statemt[29] >> 4][statemt[29] & 0xf];
      statemt[29] = invSbox[statemt[25] >> 4][statemt[25] & 0xf];
      statemt[25] = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
      statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
      statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
      statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
      statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
      statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
      statemt[1] = temp;
      temp = invSbox[statemt[30] >> 4][statemt[30] & 0xf];
      statemt[30] = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
      statemt[18] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
      statemt[6] = invSbox[statemt[26] >> 4][statemt[26] & 0xf];
      statemt[26] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
      statemt[14] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
      statemt[2] = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
      statemt[22] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
      statemt[10] = temp;
      temp = invSbox[statemt[31] >> 4][statemt[31] & 0xf];
      statemt[31] = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
      statemt[15] = temp;
      temp = invSbox[statemt[27] >> 4][statemt[27] & 0xf];
      statemt[27] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
      statemt[11] = temp;
      temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
      statemt[23] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
      statemt[7] = temp;
      temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
      statemt[19] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
      statemt[3] = temp;
      statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
      statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
      statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
      statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
      statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
      statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
      statemt[24] = invSbox[statemt[24] >> 4][statemt[24] & 0xf];
      statemt[28] = invSbox[statemt[28] >> 4][statemt[28] & 0xf];
      break;

  }

}

void MixColumn_AddRoundKey_2(int statemt_1[32], int nb_1, int n_1, int statemt_2[32], int nb_2, int n_2)
{
  int ret_1[8 * 4];
  int ret_2[8 * 4];
  int j_1;
  int j_2;
  register int x_1;
  register int x_2;
  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    ret_1[j_1 * 4] = statemt_1[j_1 * 4] << 1;
    ret_2[j_2 * 4] = statemt_2[j_2 * 4] << 1;
    if ((ret_1[j_1 * 4] >> 8) == 1)
    {
      ret_1[j_1 * 4] ^= 283;
    }
    if ((ret_2[j_2 * 4] >> 8) == 1)
    {
      ret_2[j_2 * 4] ^= 283;
    }
    x_1 = statemt_1[1 + (j_1 * 4)];
    x_2 = statemt_2[1 + (j_2 * 4)];
    x_1 ^= x_1 << 1;
    x_2 ^= x_2 << 1;
    if ((x_1 >> 8) == 1)
    {
      ret_1[j_1 * 4] ^= x_1 ^ 283;
    }
    else
    {
      ret_1[j_1 * 4] ^= x_1;
    }
    if ((x_2 >> 8) == 1)
    {
      ret_2[j_2 * 4] ^= x_2 ^ 283;
    }
    else
    {
      ret_2[j_2 * 4] ^= x_2;
    }
    ret_1[j_1 * 4] ^= (statemt_1[2 + (j_1 * 4)] ^ statemt_1[3 + (j_1 * 4)]) ^ word_1[0][j_1 + (nb_1 * n_1)];
    ret_2[j_2 * 4] ^= (statemt_2[2 + (j_2 * 4)] ^ statemt_2[3 + (j_2 * 4)]) ^ word_2[0][j_2 + (nb_2 * n_2)];
    ret_1[1 + (j_1 * 4)] = statemt_1[1 + (j_1 * 4)] << 1;
    ret_2[1 + (j_2 * 4)] = statemt_2[1 + (j_2 * 4)] << 1;
    if ((ret_1[1 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[1 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[1 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[1 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemt_1[2 + (j_1 * 4)];
    x_2 = statemt_2[2 + (j_2 * 4)];
    x_1 ^= x_1 << 1;
    x_2 ^= x_2 << 1;
    if ((x_1 >> 8) == 1)
    {
      ret_1[1 + (j_1 * 4)] ^= x_1 ^ 283;
    }
    else
    {
      ret_1[1 + (j_1 * 4)] ^= x_1;
    }
    if ((x_2 >> 8) == 1)
    {
      ret_2[1 + (j_2 * 4)] ^= x_2 ^ 283;
    }
    else
    {
      ret_2[1 + (j_2 * 4)] ^= x_2;
    }
    ret_1[1 + (j_1 * 4)] ^= (statemt_1[3 + (j_1 * 4)] ^ statemt_1[j_1 * 4]) ^ word_1[1][j_1 + (nb_1 * n_1)];
    ret_2[1 + (j_2 * 4)] ^= (statemt_2[3 + (j_2 * 4)] ^ statemt_2[j_2 * 4]) ^ word_2[1][j_2 + (nb_2 * n_2)];
    ret_1[2 + (j_1 * 4)] = statemt_1[2 + (j_1 * 4)] << 1;
    ret_2[2 + (j_2 * 4)] = statemt_2[2 + (j_2 * 4)] << 1;
    if ((ret_1[2 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[2 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[2 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[2 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemt_1[3 + (j_1 * 4)];
    x_2 = statemt_2[3 + (j_2 * 4)];
    x_1 ^= x_1 << 1;
    x_2 ^= x_2 << 1;
    if ((x_1 >> 8) == 1)
    {
      ret_1[2 + (j_1 * 4)] ^= x_1 ^ 283;
    }
    else
    {
      ret_1[2 + (j_1 * 4)] ^= x_1;
    }
    if ((x_2 >> 8) == 1)
    {
      ret_2[2 + (j_2 * 4)] ^= x_2 ^ 283;
    }
    else
    {
      ret_2[2 + (j_2 * 4)] ^= x_2;
    }
    ret_1[2 + (j_1 * 4)] ^= (statemt_1[j_1 * 4] ^ statemt_1[1 + (j_1 * 4)]) ^ word_1[2][j_1 + (nb_1 * n_1)];
    ret_2[2 + (j_2 * 4)] ^= (statemt_2[j_2 * 4] ^ statemt_2[1 + (j_2 * 4)]) ^ word_2[2][j_2 + (nb_2 * n_2)];
    ret_1[3 + (j_1 * 4)] = statemt_1[3 + (j_1 * 4)] << 1;
    ret_2[3 + (j_2 * 4)] = statemt_2[3 + (j_2 * 4)] << 1;
    if ((ret_1[3 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[3 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[3 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[3 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemt_1[j_1 * 4];
    x_2 = statemt_2[j_2 * 4];
    x_1 ^= x_1 << 1;
    x_2 ^= x_2 << 1;
    if ((x_1 >> 8) == 1)
    {
      ret_1[3 + (j_1 * 4)] ^= x_1 ^ 283;
    }
    else
    {
      ret_1[3 + (j_1 * 4)] ^= x_1;
    }
    if ((x_2 >> 8) == 1)
    {
      ret_2[3 + (j_2 * 4)] ^= x_2 ^ 283;
    }
    else
    {
      ret_2[3 + (j_2 * 4)] ^= x_2;
    }
    ret_1[3 + (j_1 * 4)] ^= (statemt_1[1 + (j_1 * 4)] ^ statemt_1[2 + (j_1 * 4)]) ^ word_1[3][j_1 + (nb_1 * n_1)];
    ret_2[3 + (j_2 * 4)] ^= (statemt_2[1 + (j_2 * 4)] ^ statemt_2[2 + (j_2 * 4)]) ^ word_2[3][j_2 + (nb_2 * n_2)];
  }

  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    statemt_1[j_1 * 4] = ret_1[j_1 * 4];
    statemt_2[j_2 * 4] = ret_2[j_2 * 4];
    statemt_1[1 + (j_1 * 4)] = ret_1[1 + (j_1 * 4)];
    statemt_2[1 + (j_2 * 4)] = ret_2[1 + (j_2 * 4)];
    statemt_1[2 + (j_1 * 4)] = ret_1[2 + (j_1 * 4)];
    statemt_2[2 + (j_2 * 4)] = ret_2[2 + (j_2 * 4)];
    statemt_1[3 + (j_1 * 4)] = ret_1[3 + (j_1 * 4)];
    statemt_2[3 + (j_2 * 4)] = ret_2[3 + (j_2 * 4)];
  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < (8 * 4); i_0++)
  {
    assert(ret_1[i_0] == ret_2[i_0]);
  }

  assert(j_1 == j_2);
  assert(x_1 == x_2);
}

int MixColumn_AddRoundKey(int statemt[32], int nb, int n)
{
  int ret[8 * 4];
  int j;
  register int x;
  for (j = 0; j < nb; ++j)
  {
    ret[j * 4] = statemt[j * 4] << 1;
    if ((ret[j * 4] >> 8) == 1)
    {
      ret[j * 4] ^= 283;
    }
    x = statemt[1 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[j * 4] ^= x ^ 283;
    }
    else
    {
      ret[j * 4] ^= x;
    }
    ret[j * 4] ^= (statemt[2 + (j * 4)] ^ statemt[3 + (j * 4)]) ^ word[0][j + (nb * n)];
    ret[1 + (j * 4)] = statemt[1 + (j * 4)] << 1;
    if ((ret[1 + (j * 4)] >> 8) == 1)
    {
      ret[1 + (j * 4)] ^= 283;
    }
    x = statemt[2 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[1 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[1 + (j * 4)] ^= x;
    }
    ret[1 + (j * 4)] ^= (statemt[3 + (j * 4)] ^ statemt[j * 4]) ^ word[1][j + (nb * n)];
    ret[2 + (j * 4)] = statemt[2 + (j * 4)] << 1;
    if ((ret[2 + (j * 4)] >> 8) == 1)
    {
      ret[2 + (j * 4)] ^= 283;
    }
    x = statemt[3 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[2 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[2 + (j * 4)] ^= x;
    }
    ret[2 + (j * 4)] ^= (statemt[j * 4] ^ statemt[1 + (j * 4)]) ^ word[2][j + (nb * n)];
    ret[3 + (j * 4)] = statemt[3 + (j * 4)] << 1;
    if ((ret[3 + (j * 4)] >> 8) == 1)
    {
      ret[3 + (j * 4)] ^= 283;
    }
    x = statemt[j * 4];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[3 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[3 + (j * 4)] ^= x;
    }
    ret[3 + (j * 4)] ^= (statemt[1 + (j * 4)] ^ statemt[2 + (j * 4)]) ^ word[3][j + (nb * n)];
  }

  for (j = 0; j < nb; ++j)
  {
    statemt[j * 4] = ret[j * 4];
    statemt[1 + (j * 4)] = ret[1 + (j * 4)];
    statemt[2 + (j * 4)] = ret[2 + (j * 4)];
    statemt[3 + (j * 4)] = ret[3 + (j * 4)];
  }

  return 0;
}

void AddRoundKey_InversMixColumn_2(int statemt_1[32], int nb_1, int n_1, int statemt_2[32], int nb_2, int n_2)
{
  int ret_1[8 * 4];
  int ret_2[8 * 4];
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  register int x_1;
  register int x_2;
  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    statemt_1[j_1 * 4] ^= word_1[0][j_1 + (nb_1 * n_1)];
    statemt_2[j_2 * 4] ^= word_2[0][j_2 + (nb_2 * n_2)];
    statemt_1[1 + (j_1 * 4)] ^= word_1[1][j_1 + (nb_1 * n_1)];
    statemt_2[1 + (j_2 * 4)] ^= word_2[1][j_2 + (nb_2 * n_2)];
    statemt_1[2 + (j_1 * 4)] ^= word_1[2][j_1 + (nb_1 * n_1)];
    statemt_2[2 + (j_2 * 4)] ^= word_2[2][j_2 + (nb_2 * n_2)];
    statemt_1[3 + (j_1 * 4)] ^= word_1[3][j_1 + (nb_1 * n_1)];
    statemt_2[3 + (j_2 * 4)] ^= word_2[3][j_2 + (nb_2 * n_2)];
  }

  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); ++i_1, ++i_2)
    {
      x_1 = statemt_1[i_1 + (j_1 * 4)] << 1;
      x_2 = statemt_2[i_2 + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[i_1 + (j_1 * 4)];
      x_2 ^= statemt_2[i_2 + (j_2 * 4)];
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[i_1 + (j_1 * 4)];
      x_2 ^= statemt_2[i_2 + (j_2 * 4)];
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      ret_1[i_1 + (j_1 * 4)] = x_1;
      ret_2[i_2 + (j_2 * 4)] = x_2;
      x_1 = statemt_1[((i_1 + 1) % 4) + (j_1 * 4)] << 1;
      x_2 = statemt_2[((i_2 + 1) % 4) + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[((i_1 + 1) % 4) + (j_1 * 4)];
      x_2 ^= statemt_2[((i_2 + 1) % 4) + (j_2 * 4)];
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[((i_1 + 1) % 4) + (j_1 * 4)];
      x_2 ^= statemt_2[((i_2 + 1) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
      x_1 = statemt_1[((i_1 + 2) % 4) + (j_1 * 4)] << 1;
      x_2 = statemt_2[((i_2 + 2) % 4) + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[((i_1 + 2) % 4) + (j_1 * 4)];
      x_2 ^= statemt_2[((i_2 + 2) % 4) + (j_2 * 4)];
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[((i_1 + 2) % 4) + (j_1 * 4)];
      x_2 ^= statemt_2[((i_2 + 2) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
      x_1 = statemt_1[((i_1 + 3) % 4) + (j_1 * 4)] << 1;
      x_2 = statemt_2[((i_2 + 3) % 4) + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 = x_1 << 1;
      x_2 = x_2 << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemt_1[((i_1 + 3) % 4) + (j_1 * 4)];
      x_2 ^= statemt_2[((i_2 + 3) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
    }

  }

  for (i_1 = 0, i_2 = 0; (i_1 < nb_1) && (i_2 < nb_2); ++i_1, ++i_2)
  {
    statemt_1[i_1 * 4] = ret_1[i_1 * 4];
    statemt_2[i_2 * 4] = ret_2[i_2 * 4];
    statemt_1[1 + (i_1 * 4)] = ret_1[1 + (i_1 * 4)];
    statemt_2[1 + (i_2 * 4)] = ret_2[1 + (i_2 * 4)];
    statemt_1[2 + (i_1 * 4)] = ret_1[2 + (i_1 * 4)];
    statemt_2[2 + (i_2 * 4)] = ret_2[2 + (i_2 * 4)];
    statemt_1[3 + (i_1 * 4)] = ret_1[3 + (i_1 * 4)];
    statemt_2[3 + (i_2 * 4)] = ret_2[3 + (i_2 * 4)];
  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < (8 * 4); i_0++)
  {
    assert(ret_1[i_0] == ret_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(j_1 == j_2);
  assert(x_1 == x_2);
}

int AddRoundKey_InversMixColumn(int statemt[32], int nb, int n)
{
  int ret[8 * 4];
  int i;
  int j;
  register int x;
  for (j = 0; j < nb; ++j)
  {
    statemt[j * 4] ^= word[0][j + (nb * n)];
    statemt[1 + (j * 4)] ^= word[1][j + (nb * n)];
    statemt[2 + (j * 4)] ^= word[2][j + (nb * n)];
    statemt[3 + (j * 4)] ^= word[3][j + (nb * n)];
  }

  for (j = 0; j < nb; ++j)
  {
    for (i = 0; i < 4; ++i)
    {
      x = statemt[i + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[i + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[i + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      ret[i + (j * 4)] = x;
      x = statemt[((i + 1) % 4) + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[((i + 1) % 4) + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[((i + 1) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
      x = statemt[((i + 2) % 4) + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[((i + 2) % 4) + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[((i + 2) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
      x = statemt[((i + 3) % 4) + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemt[((i + 3) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
    }

  }

  for (i = 0; i < nb; ++i)
  {
    statemt[i * 4] = ret[i * 4];
    statemt[1 + (i * 4)] = ret[1 + (i * 4)];
    statemt[2 + (i * 4)] = ret[2 + (i * 4)];
    statemt[3 + (i * 4)] = ret[3 + (i * 4)];
  }

  return 0;
}

void AddRoundKey_2(int statemt_1[32], int type_1, int n_1, int statemt_2[32], int type_2, int n_2)
{
  int j_1;
  int j_2;
  int nb_1;
  int nb_2;
  switch (type_1)
  {
    case 128128:

    case 192128:

    case 256128:
      nb_1 = 4;
      break;

    case 128192:

    case 192192:

    case 256192:
      nb_1 = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      nb_1 = 8;
      break;

  }

  switch (type_2)
  {
    case 128128:

    case 192128:

    case 256128:
      nb_2 = 4;
      break;

    case 128192:

    case 192192:

    case 256192:
      nb_2 = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      nb_2 = 8;
      break;

  }

  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    statemt_1[j_1 * 4] ^= word_1[0][j_1 + (nb_1 * n_1)];
    statemt_2[j_2 * 4] ^= word_2[0][j_2 + (nb_2 * n_2)];
    statemt_1[1 + (j_1 * 4)] ^= word_1[1][j_1 + (nb_1 * n_1)];
    statemt_2[1 + (j_2 * 4)] ^= word_2[1][j_2 + (nb_2 * n_2)];
    statemt_1[2 + (j_1 * 4)] ^= word_1[2][j_1 + (nb_1 * n_1)];
    statemt_2[2 + (j_2 * 4)] ^= word_2[2][j_2 + (nb_2 * n_2)];
    statemt_1[3 + (j_1 * 4)] ^= word_1[3][j_1 + (nb_1 * n_1)];
    statemt_2[3 + (j_2 * 4)] ^= word_2[3][j_2 + (nb_2 * n_2)];
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(j_1 == j_2);
}

int AddRoundKey(int statemt[32], int type, int n)
{
  int j;
  int nb;
  switch (type)
  {
    case 128128:

    case 192128:

    case 256128:
      nb = 4;
      break;

    case 128192:

    case 192192:

    case 256192:
      nb = 6;
      break;

    case 128256:

    case 192256:

    case 256256:
      nb = 8;
      break;

  }

  for (j = 0; j < nb; ++j)
  {
    statemt[j * 4] ^= word[0][j + (nb * n)];
    statemt[1 + (j * 4)] ^= word[1][j + (nb * n)];
    statemt[2 + (j * 4)] ^= word[2][j + (nb * n)];
    statemt[3 + (j * 4)] ^= word[3][j + (nb * n)];
  }

  return 0;
}

const int Rcon0_1[30] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91};
const int Rcon0_2[30] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91};
const int Rcon0[30] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91};
void KeySchedule_2(int type_1, int key_1[32], int type_2, int key_2[32])
{
  int nk_1;
  int nk_2;
  int nb_1;
  int nb_2;
  int round_val_1;
  int round_val_2;
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  int temp_1[4];
  int temp_2[4];
  switch (type_1)
  {
    case 128128:
      nk_1 = 4;
      nb_1 = 4;
      round_val_1 = 10;
      break;

    case 128192:
      nk_1 = 4;
      nb_1 = 6;
      round_val_1 = 12;
      break;

    case 128256:
      nk_1 = 4;
      nb_1 = 8;
      round_val_1 = 14;
      break;

    case 192128:
      nk_1 = 6;
      nb_1 = 4;
      round_val_1 = 12;
      break;

    case 192192:
      nk_1 = 6;
      nb_1 = 6;
      round_val_1 = 12;
      break;

    case 192256:
      nk_1 = 6;
      nb_1 = 8;
      round_val_1 = 14;
      break;

    case 256128:
      nk_1 = 8;
      nb_1 = 4;
      round_val_1 = 14;
      break;

    case 256192:
      nk_1 = 8;
      nb_1 = 6;
      round_val_1 = 14;
      break;

    case 256256:
      nk_1 = 8;
      nb_1 = 8;
      round_val_1 = 14;
      break;

    default:
      return -1;

  }

  switch (type_2)
  {
    case 128128:
      nk_2 = 4;
      nb_2 = 4;
      round_val_2 = 10;
      break;

    case 128192:
      nk_2 = 4;
      nb_2 = 6;
      round_val_2 = 12;
      break;

    case 128256:
      nk_2 = 4;
      nb_2 = 8;
      round_val_2 = 14;
      break;

    case 192128:
      nk_2 = 6;
      nb_2 = 4;
      round_val_2 = 12;
      break;

    case 192192:
      nk_2 = 6;
      nb_2 = 6;
      round_val_2 = 12;
      break;

    case 192256:
      nk_2 = 6;
      nb_2 = 8;
      round_val_2 = 14;
      break;

    case 256128:
      nk_2 = 8;
      nb_2 = 4;
      round_val_2 = 14;
      break;

    case 256192:
      nk_2 = 8;
      nb_2 = 6;
      round_val_2 = 14;
      break;

    case 256256:
      nk_2 = 8;
      nb_2 = 8;
      round_val_2 = 14;
      break;

    default:
      return -1;

  }

  for (j_1 = 0, j_2 = 0; (j_1 < nk_1) && (j_2 < nk_2); ++j_1, ++j_2)
  {
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); ++i_1, ++i_2)
    {
      word_1[i_1][j_1] = key_1[i_1 + (j_1 * 4)];
      word_2[i_2][j_2] = key_2[i_2 + (j_2 * 4)];
    }

  }

  for (j_1 = nk_1, j_2 = nk_2; (j_1 < (nb_1 * (round_val_1 + 1))) && (j_2 < (nb_2 * (round_val_2 + 1))); ++j_1, ++j_2)
  {
    if ((j_1 % nk_1) == 0)
    {
      temp_1[0] = SubByte(word_1[1][j_1 - 1]) ^ Rcon0_1[(j_1 / nk_1) - 1];
      temp_1[1] = SubByte(word_1[2][j_1 - 1]);
      temp_1[2] = SubByte(word_1[3][j_1 - 1]);
      temp_1[3] = SubByte(word_1[0][j_1 - 1]);
    }
    if ((j_2 % nk_2) == 0)
    {
      temp_2[0] = SubByte(word_2[1][j_2 - 1]) ^ Rcon0_2[(j_2 / nk_2) - 1];
      temp_2[1] = SubByte(word_2[2][j_2 - 1]);
      temp_2[2] = SubByte(word_2[3][j_2 - 1]);
      temp_2[3] = SubByte(word_2[0][j_2 - 1]);
    }
    SubByte_2(word_1[1][j_1 - 1], word_2[1][j_2 - 1]);
    if ((j_1 % nk_1) != 0)
    {
      temp_1[0] = word_1[0][j_1 - 1];
      temp_1[1] = word_1[1][j_1 - 1];
      temp_1[2] = word_1[2][j_1 - 1];
      temp_1[3] = word_1[3][j_1 - 1];
    }
    if ((j_2 % nk_2) != 0)
    {
      temp_2[0] = word_2[0][j_2 - 1];
      temp_2[1] = word_2[1][j_2 - 1];
      temp_2[2] = word_2[2][j_2 - 1];
      temp_2[3] = word_2[3][j_2 - 1];
    }
    if ((nk_1 > 6) && ((j_1 % nk_1) == 4))
    {
      for (i_1 = 0; i_1 < 4; ++i_1)
      {
        temp_1[i_1] = SubByte(temp_1[i_1]);
      }

    }
    if ((nk_2 > 6) && ((j_2 % nk_2) == 4))
    {
      for (i_2 = 0; i_2 < 4; ++i_2)
      {
        temp_2[i_2] = SubByte(temp_2[i_2]);
      }

    }
    SubByte_2(temp_1[i_1], temp_2[i_2]);
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); ++i_1, ++i_2)
    {
      word_1[i_1][j_1] = word_1[i_1][j_1 - nk_1] ^ temp_1[i_1];
      word_2[i_2][j_2] = word_2[i_2][j_2 - nk_2] ^ temp_2[i_2];
    }

  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  assert(round_val_1 == round_val_2);
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 30; i_0++)
  {
    assert(Rcon0_1[i_0] == Rcon0_2[i_0]);
  }

  assert(nk_1 == nk_2);
  assert(i_1 == i_2);
  assert(j_1 == j_2);
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(temp_1[i_0] == temp_2[i_0]);
  }

}

int KeySchedule(int type, int key[32])
{
  int nk;
  int nb;
  int round_val;
  int i;
  int j;
  int temp[4];
  switch (type)
  {
    case 128128:
      nk = 4;
      nb = 4;
      round_val = 10;
      break;

    case 128192:
      nk = 4;
      nb = 6;
      round_val = 12;
      break;

    case 128256:
      nk = 4;
      nb = 8;
      round_val = 14;
      break;

    case 192128:
      nk = 6;
      nb = 4;
      round_val = 12;
      break;

    case 192192:
      nk = 6;
      nb = 6;
      round_val = 12;
      break;

    case 192256:
      nk = 6;
      nb = 8;
      round_val = 14;
      break;

    case 256128:
      nk = 8;
      nb = 4;
      round_val = 14;
      break;

    case 256192:
      nk = 8;
      nb = 6;
      round_val = 14;
      break;

    case 256256:
      nk = 8;
      nb = 8;
      round_val = 14;
      break;

    default:
      return -1;

  }

  for (j = 0; j < nk; ++j)
  {
    for (i = 0; i < 4; ++i)
    {
      word[i][j] = key[i + (j * 4)];
    }

  }

  for (j = nk; j < (nb * (round_val + 1)); ++j)
  {
    if ((j % nk) == 0)
    {
      temp[0] = SubByte(word[1][j - 1]) ^ Rcon0[(j / nk) - 1];
      temp[1] = SubByte(word[2][j - 1]);
      temp[2] = SubByte(word[3][j - 1]);
      temp[3] = SubByte(word[0][j - 1]);
    }
    if ((j % nk) != 0)
    {
      temp[0] = word[0][j - 1];
      temp[1] = word[1][j - 1];
      temp[2] = word[2][j - 1];
      temp[3] = word[3][j - 1];
    }
    if ((nk > 6) && ((j % nk) == 4))
    {
      for (i = 0; i < 4; ++i)
      {
        temp[i] = SubByte(temp[i]);
      }

    }
    for (i = 0; i < 4; ++i)
    {
      word[i][j] = word[i][j - nk] ^ temp[i];
    }

  }

  return 0;
}

void main()
{
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_1[i_0] = nd_key();
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_2[i_0] = nd_key();
  }

  main_result_1 = 0;
  main_result_2 = 0;
  encrypt(statemt_1, key_1, 128128);
  encrypt(statemt_2, key_2, 128128);
  encrypt_2(statemt_1, key_1, 128128, statemt_2, key_2, 128128);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
}


