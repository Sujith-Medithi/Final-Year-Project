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
int word_1[4][120];
int word_2[4][120];
int word[4][120];
int main_result_1;
int main_result_2;
int main_result;
const int Sbox_1[16][16];
const int Sbox_2[16][16];
const int Sbox[16][16];
int nd_key();
void SubByte_2(int in_1, int in_2)
{
}

int SubByte(int in)
{
  return Sbox[in / 16][in % 16];
}

const int invSbox_1[16][16];
const int invSbox_2[16][16];
const int invSbox[16][16];
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

  int statemt_1[32];
  int statemt_2[32];
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

}

const int Rcon0_1[30];
const int Rcon0_2[30];
const int Rcon0[30];
void KeySchedule_2(int type_1, int keyarg_1[32], int type_2, int keyarg_2[32])
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
      word_1[i_1][j_1] = keyarg_1[i_1 + (j_1 * 4)];
      word_2[i_2][j_2] = keyarg_2[i_2 + (j_2 * 4)];
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

int KeySchedule(int type, int keyarg[32])
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
      word[i][j] = keyarg[i + (j * 4)];
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

void ByteSub_ShiftRow_2(int statemtarg_1[32], int nb_1, int statemtarg_2[32], int nb_2)
{
  int temp_1;
  int temp_2;
  switch (nb_1)
  {
    case 4:
      temp_1 = Sbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = Sbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = Sbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = Sbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = Sbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = Sbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = Sbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = Sbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = Sbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = temp_1;
      statemtarg_1[0] = Sbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = Sbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = Sbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = Sbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      break;

    case 6:
      temp_1 = Sbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = Sbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = Sbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = Sbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = Sbox_1[statemtarg_1[17] >> 4][statemtarg_1[17] & 0xf];
      statemtarg_1[17] = Sbox_1[statemtarg_1[21] >> 4][statemtarg_1[21] & 0xf];
      statemtarg_1[21] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = Sbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = Sbox_1[statemtarg_1[18] >> 4][statemtarg_1[18] & 0xf];
      statemtarg_1[18] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = Sbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = Sbox_1[statemtarg_1[22] >> 4][statemtarg_1[22] & 0xf];
      statemtarg_1[22] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = Sbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = Sbox_1[statemtarg_1[19] >> 4][statemtarg_1[19] & 0xf];
      statemtarg_1[19] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = Sbox_1[statemtarg_1[23] >> 4][statemtarg_1[23] & 0xf];
      statemtarg_1[23] = temp_1;
      statemtarg_1[0] = Sbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = Sbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = Sbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = Sbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      statemtarg_1[16] = Sbox_1[statemtarg_1[16] >> 4][statemtarg_1[16] & 0xf];
      statemtarg_1[20] = Sbox_1[statemtarg_1[20] >> 4][statemtarg_1[20] & 0xf];
      break;

    case 8:
      temp_1 = Sbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = Sbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = Sbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = Sbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = Sbox_1[statemtarg_1[17] >> 4][statemtarg_1[17] & 0xf];
      statemtarg_1[17] = Sbox_1[statemtarg_1[21] >> 4][statemtarg_1[21] & 0xf];
      statemtarg_1[21] = Sbox_1[statemtarg_1[25] >> 4][statemtarg_1[25] & 0xf];
      statemtarg_1[25] = Sbox_1[statemtarg_1[29] >> 4][statemtarg_1[29] & 0xf];
      statemtarg_1[29] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = Sbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = Sbox_1[statemtarg_1[26] >> 4][statemtarg_1[26] & 0xf];
      statemtarg_1[26] = Sbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = Sbox_1[statemtarg_1[18] >> 4][statemtarg_1[18] & 0xf];
      statemtarg_1[18] = Sbox_1[statemtarg_1[30] >> 4][statemtarg_1[30] & 0xf];
      statemtarg_1[30] = Sbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = Sbox_1[statemtarg_1[22] >> 4][statemtarg_1[22] & 0xf];
      statemtarg_1[22] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = Sbox_1[statemtarg_1[19] >> 4][statemtarg_1[19] & 0xf];
      statemtarg_1[19] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = Sbox_1[statemtarg_1[23] >> 4][statemtarg_1[23] & 0xf];
      statemtarg_1[23] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = Sbox_1[statemtarg_1[27] >> 4][statemtarg_1[27] & 0xf];
      statemtarg_1[27] = temp_1;
      temp_1 = Sbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = Sbox_1[statemtarg_1[31] >> 4][statemtarg_1[31] & 0xf];
      statemtarg_1[31] = temp_1;
      statemtarg_1[0] = Sbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = Sbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = Sbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = Sbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      statemtarg_1[16] = Sbox_1[statemtarg_1[16] >> 4][statemtarg_1[16] & 0xf];
      statemtarg_1[20] = Sbox_1[statemtarg_1[20] >> 4][statemtarg_1[20] & 0xf];
      statemtarg_1[24] = Sbox_1[statemtarg_1[24] >> 4][statemtarg_1[24] & 0xf];
      statemtarg_1[28] = Sbox_1[statemtarg_1[28] >> 4][statemtarg_1[28] & 0xf];
      break;

  }

  switch (nb_2)
  {
    case 4:
      temp_2 = Sbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = Sbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = Sbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = Sbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = Sbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = Sbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = Sbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = Sbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = Sbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = temp_2;
      statemtarg_2[0] = Sbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = Sbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = Sbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = Sbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      break;

    case 6:
      temp_2 = Sbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = Sbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = Sbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = Sbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = Sbox_2[statemtarg_2[17] >> 4][statemtarg_2[17] & 0xf];
      statemtarg_2[17] = Sbox_2[statemtarg_2[21] >> 4][statemtarg_2[21] & 0xf];
      statemtarg_2[21] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = Sbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = Sbox_2[statemtarg_2[18] >> 4][statemtarg_2[18] & 0xf];
      statemtarg_2[18] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = Sbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = Sbox_2[statemtarg_2[22] >> 4][statemtarg_2[22] & 0xf];
      statemtarg_2[22] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = Sbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = Sbox_2[statemtarg_2[19] >> 4][statemtarg_2[19] & 0xf];
      statemtarg_2[19] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = Sbox_2[statemtarg_2[23] >> 4][statemtarg_2[23] & 0xf];
      statemtarg_2[23] = temp_2;
      statemtarg_2[0] = Sbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = Sbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = Sbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = Sbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      statemtarg_2[16] = Sbox_2[statemtarg_2[16] >> 4][statemtarg_2[16] & 0xf];
      statemtarg_2[20] = Sbox_2[statemtarg_2[20] >> 4][statemtarg_2[20] & 0xf];
      break;

    case 8:
      temp_2 = Sbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = Sbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = Sbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = Sbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = Sbox_2[statemtarg_2[17] >> 4][statemtarg_2[17] & 0xf];
      statemtarg_2[17] = Sbox_2[statemtarg_2[21] >> 4][statemtarg_2[21] & 0xf];
      statemtarg_2[21] = Sbox_2[statemtarg_2[25] >> 4][statemtarg_2[25] & 0xf];
      statemtarg_2[25] = Sbox_2[statemtarg_2[29] >> 4][statemtarg_2[29] & 0xf];
      statemtarg_2[29] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = Sbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = Sbox_2[statemtarg_2[26] >> 4][statemtarg_2[26] & 0xf];
      statemtarg_2[26] = Sbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = Sbox_2[statemtarg_2[18] >> 4][statemtarg_2[18] & 0xf];
      statemtarg_2[18] = Sbox_2[statemtarg_2[30] >> 4][statemtarg_2[30] & 0xf];
      statemtarg_2[30] = Sbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = Sbox_2[statemtarg_2[22] >> 4][statemtarg_2[22] & 0xf];
      statemtarg_2[22] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = Sbox_2[statemtarg_2[19] >> 4][statemtarg_2[19] & 0xf];
      statemtarg_2[19] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = Sbox_2[statemtarg_2[23] >> 4][statemtarg_2[23] & 0xf];
      statemtarg_2[23] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = Sbox_2[statemtarg_2[27] >> 4][statemtarg_2[27] & 0xf];
      statemtarg_2[27] = temp_2;
      temp_2 = Sbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = Sbox_2[statemtarg_2[31] >> 4][statemtarg_2[31] & 0xf];
      statemtarg_2[31] = temp_2;
      statemtarg_2[0] = Sbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = Sbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = Sbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = Sbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      statemtarg_2[16] = Sbox_2[statemtarg_2[16] >> 4][statemtarg_2[16] & 0xf];
      statemtarg_2[20] = Sbox_2[statemtarg_2[20] >> 4][statemtarg_2[20] & 0xf];
      statemtarg_2[24] = Sbox_2[statemtarg_2[24] >> 4][statemtarg_2[24] & 0xf];
      statemtarg_2[28] = Sbox_2[statemtarg_2[28] >> 4][statemtarg_2[28] & 0xf];
      break;

  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  assert(temp_1 == temp_2);
}

void ByteSub_ShiftRow(int statemtarg[32], int nb)
{
  int temp;
  switch (nb)
  {
    case 4:
      temp = Sbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = Sbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = Sbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = Sbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = temp;
      temp = Sbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = Sbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = temp;
      temp = Sbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = Sbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = temp;
      temp = Sbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = Sbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = Sbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = Sbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = temp;
      statemtarg[0] = Sbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = Sbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = Sbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = Sbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      break;

    case 6:
      temp = Sbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = Sbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = Sbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = Sbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = Sbox[statemtarg[17] >> 4][statemtarg[17] & 0xf];
      statemtarg[17] = Sbox[statemtarg[21] >> 4][statemtarg[21] & 0xf];
      statemtarg[21] = temp;
      temp = Sbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = Sbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = Sbox[statemtarg[18] >> 4][statemtarg[18] & 0xf];
      statemtarg[18] = temp;
      temp = Sbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = Sbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = Sbox[statemtarg[22] >> 4][statemtarg[22] & 0xf];
      statemtarg[22] = temp;
      temp = Sbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = Sbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = temp;
      temp = Sbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = Sbox[statemtarg[19] >> 4][statemtarg[19] & 0xf];
      statemtarg[19] = temp;
      temp = Sbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = Sbox[statemtarg[23] >> 4][statemtarg[23] & 0xf];
      statemtarg[23] = temp;
      statemtarg[0] = Sbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = Sbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = Sbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = Sbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      statemtarg[16] = Sbox[statemtarg[16] >> 4][statemtarg[16] & 0xf];
      statemtarg[20] = Sbox[statemtarg[20] >> 4][statemtarg[20] & 0xf];
      break;

    case 8:
      temp = Sbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = Sbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = Sbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = Sbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = Sbox[statemtarg[17] >> 4][statemtarg[17] & 0xf];
      statemtarg[17] = Sbox[statemtarg[21] >> 4][statemtarg[21] & 0xf];
      statemtarg[21] = Sbox[statemtarg[25] >> 4][statemtarg[25] & 0xf];
      statemtarg[25] = Sbox[statemtarg[29] >> 4][statemtarg[29] & 0xf];
      statemtarg[29] = temp;
      temp = Sbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = Sbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = Sbox[statemtarg[26] >> 4][statemtarg[26] & 0xf];
      statemtarg[26] = Sbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = Sbox[statemtarg[18] >> 4][statemtarg[18] & 0xf];
      statemtarg[18] = Sbox[statemtarg[30] >> 4][statemtarg[30] & 0xf];
      statemtarg[30] = Sbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = Sbox[statemtarg[22] >> 4][statemtarg[22] & 0xf];
      statemtarg[22] = temp;
      temp = Sbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = Sbox[statemtarg[19] >> 4][statemtarg[19] & 0xf];
      statemtarg[19] = temp;
      temp = Sbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = Sbox[statemtarg[23] >> 4][statemtarg[23] & 0xf];
      statemtarg[23] = temp;
      temp = Sbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = Sbox[statemtarg[27] >> 4][statemtarg[27] & 0xf];
      statemtarg[27] = temp;
      temp = Sbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = Sbox[statemtarg[31] >> 4][statemtarg[31] & 0xf];
      statemtarg[31] = temp;
      statemtarg[0] = Sbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = Sbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = Sbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = Sbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      statemtarg[16] = Sbox[statemtarg[16] >> 4][statemtarg[16] & 0xf];
      statemtarg[20] = Sbox[statemtarg[20] >> 4][statemtarg[20] & 0xf];
      statemtarg[24] = Sbox[statemtarg[24] >> 4][statemtarg[24] & 0xf];
      statemtarg[28] = Sbox[statemtarg[28] >> 4][statemtarg[28] & 0xf];
      break;

  }

}

void InversShiftRow_ByteSub_2(int statemtarg_1[32], int nb_1, int statemtarg_2[32], int nb_2)
{
  int temp_1;
  int temp_2;
  switch (nb_1)
  {
    case 4:
      temp_1 = invSbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = invSbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = invSbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = invSbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = invSbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = invSbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = invSbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = invSbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = invSbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = temp_1;
      statemtarg_1[0] = invSbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = invSbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = invSbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = invSbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      break;

    case 6:
      temp_1 = invSbox_1[statemtarg_1[21] >> 4][statemtarg_1[21] & 0xf];
      statemtarg_1[21] = invSbox_1[statemtarg_1[17] >> 4][statemtarg_1[17] & 0xf];
      statemtarg_1[17] = invSbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = invSbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = invSbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = invSbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[22] >> 4][statemtarg_1[22] & 0xf];
      statemtarg_1[22] = invSbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = invSbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[18] >> 4][statemtarg_1[18] & 0xf];
      statemtarg_1[18] = invSbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = invSbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = invSbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[19] >> 4][statemtarg_1[19] & 0xf];
      statemtarg_1[19] = invSbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[23] >> 4][statemtarg_1[23] & 0xf];
      statemtarg_1[23] = invSbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = temp_1;
      statemtarg_1[0] = invSbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = invSbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = invSbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = invSbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      statemtarg_1[16] = invSbox_1[statemtarg_1[16] >> 4][statemtarg_1[16] & 0xf];
      statemtarg_1[20] = invSbox_1[statemtarg_1[20] >> 4][statemtarg_1[20] & 0xf];
      break;

    case 8:
      temp_1 = invSbox_1[statemtarg_1[29] >> 4][statemtarg_1[29] & 0xf];
      statemtarg_1[29] = invSbox_1[statemtarg_1[25] >> 4][statemtarg_1[25] & 0xf];
      statemtarg_1[25] = invSbox_1[statemtarg_1[21] >> 4][statemtarg_1[21] & 0xf];
      statemtarg_1[21] = invSbox_1[statemtarg_1[17] >> 4][statemtarg_1[17] & 0xf];
      statemtarg_1[17] = invSbox_1[statemtarg_1[13] >> 4][statemtarg_1[13] & 0xf];
      statemtarg_1[13] = invSbox_1[statemtarg_1[9] >> 4][statemtarg_1[9] & 0xf];
      statemtarg_1[9] = invSbox_1[statemtarg_1[5] >> 4][statemtarg_1[5] & 0xf];
      statemtarg_1[5] = invSbox_1[statemtarg_1[1] >> 4][statemtarg_1[1] & 0xf];
      statemtarg_1[1] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[30] >> 4][statemtarg_1[30] & 0xf];
      statemtarg_1[30] = invSbox_1[statemtarg_1[18] >> 4][statemtarg_1[18] & 0xf];
      statemtarg_1[18] = invSbox_1[statemtarg_1[6] >> 4][statemtarg_1[6] & 0xf];
      statemtarg_1[6] = invSbox_1[statemtarg_1[26] >> 4][statemtarg_1[26] & 0xf];
      statemtarg_1[26] = invSbox_1[statemtarg_1[14] >> 4][statemtarg_1[14] & 0xf];
      statemtarg_1[14] = invSbox_1[statemtarg_1[2] >> 4][statemtarg_1[2] & 0xf];
      statemtarg_1[2] = invSbox_1[statemtarg_1[22] >> 4][statemtarg_1[22] & 0xf];
      statemtarg_1[22] = invSbox_1[statemtarg_1[10] >> 4][statemtarg_1[10] & 0xf];
      statemtarg_1[10] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[31] >> 4][statemtarg_1[31] & 0xf];
      statemtarg_1[31] = invSbox_1[statemtarg_1[15] >> 4][statemtarg_1[15] & 0xf];
      statemtarg_1[15] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[27] >> 4][statemtarg_1[27] & 0xf];
      statemtarg_1[27] = invSbox_1[statemtarg_1[11] >> 4][statemtarg_1[11] & 0xf];
      statemtarg_1[11] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[23] >> 4][statemtarg_1[23] & 0xf];
      statemtarg_1[23] = invSbox_1[statemtarg_1[7] >> 4][statemtarg_1[7] & 0xf];
      statemtarg_1[7] = temp_1;
      temp_1 = invSbox_1[statemtarg_1[19] >> 4][statemtarg_1[19] & 0xf];
      statemtarg_1[19] = invSbox_1[statemtarg_1[3] >> 4][statemtarg_1[3] & 0xf];
      statemtarg_1[3] = temp_1;
      statemtarg_1[0] = invSbox_1[statemtarg_1[0] >> 4][statemtarg_1[0] & 0xf];
      statemtarg_1[4] = invSbox_1[statemtarg_1[4] >> 4][statemtarg_1[4] & 0xf];
      statemtarg_1[8] = invSbox_1[statemtarg_1[8] >> 4][statemtarg_1[8] & 0xf];
      statemtarg_1[12] = invSbox_1[statemtarg_1[12] >> 4][statemtarg_1[12] & 0xf];
      statemtarg_1[16] = invSbox_1[statemtarg_1[16] >> 4][statemtarg_1[16] & 0xf];
      statemtarg_1[20] = invSbox_1[statemtarg_1[20] >> 4][statemtarg_1[20] & 0xf];
      statemtarg_1[24] = invSbox_1[statemtarg_1[24] >> 4][statemtarg_1[24] & 0xf];
      statemtarg_1[28] = invSbox_1[statemtarg_1[28] >> 4][statemtarg_1[28] & 0xf];
      break;

  }

  switch (nb_2)
  {
    case 4:
      temp_2 = invSbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = invSbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = invSbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = invSbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = invSbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = invSbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = invSbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = invSbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = invSbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = temp_2;
      statemtarg_2[0] = invSbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = invSbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = invSbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = invSbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      break;

    case 6:
      temp_2 = invSbox_2[statemtarg_2[21] >> 4][statemtarg_2[21] & 0xf];
      statemtarg_2[21] = invSbox_2[statemtarg_2[17] >> 4][statemtarg_2[17] & 0xf];
      statemtarg_2[17] = invSbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = invSbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = invSbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = invSbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[22] >> 4][statemtarg_2[22] & 0xf];
      statemtarg_2[22] = invSbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = invSbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[18] >> 4][statemtarg_2[18] & 0xf];
      statemtarg_2[18] = invSbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = invSbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = invSbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[19] >> 4][statemtarg_2[19] & 0xf];
      statemtarg_2[19] = invSbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[23] >> 4][statemtarg_2[23] & 0xf];
      statemtarg_2[23] = invSbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = temp_2;
      statemtarg_2[0] = invSbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = invSbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = invSbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = invSbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      statemtarg_2[16] = invSbox_2[statemtarg_2[16] >> 4][statemtarg_2[16] & 0xf];
      statemtarg_2[20] = invSbox_2[statemtarg_2[20] >> 4][statemtarg_2[20] & 0xf];
      break;

    case 8:
      temp_2 = invSbox_2[statemtarg_2[29] >> 4][statemtarg_2[29] & 0xf];
      statemtarg_2[29] = invSbox_2[statemtarg_2[25] >> 4][statemtarg_2[25] & 0xf];
      statemtarg_2[25] = invSbox_2[statemtarg_2[21] >> 4][statemtarg_2[21] & 0xf];
      statemtarg_2[21] = invSbox_2[statemtarg_2[17] >> 4][statemtarg_2[17] & 0xf];
      statemtarg_2[17] = invSbox_2[statemtarg_2[13] >> 4][statemtarg_2[13] & 0xf];
      statemtarg_2[13] = invSbox_2[statemtarg_2[9] >> 4][statemtarg_2[9] & 0xf];
      statemtarg_2[9] = invSbox_2[statemtarg_2[5] >> 4][statemtarg_2[5] & 0xf];
      statemtarg_2[5] = invSbox_2[statemtarg_2[1] >> 4][statemtarg_2[1] & 0xf];
      statemtarg_2[1] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[30] >> 4][statemtarg_2[30] & 0xf];
      statemtarg_2[30] = invSbox_2[statemtarg_2[18] >> 4][statemtarg_2[18] & 0xf];
      statemtarg_2[18] = invSbox_2[statemtarg_2[6] >> 4][statemtarg_2[6] & 0xf];
      statemtarg_2[6] = invSbox_2[statemtarg_2[26] >> 4][statemtarg_2[26] & 0xf];
      statemtarg_2[26] = invSbox_2[statemtarg_2[14] >> 4][statemtarg_2[14] & 0xf];
      statemtarg_2[14] = invSbox_2[statemtarg_2[2] >> 4][statemtarg_2[2] & 0xf];
      statemtarg_2[2] = invSbox_2[statemtarg_2[22] >> 4][statemtarg_2[22] & 0xf];
      statemtarg_2[22] = invSbox_2[statemtarg_2[10] >> 4][statemtarg_2[10] & 0xf];
      statemtarg_2[10] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[31] >> 4][statemtarg_2[31] & 0xf];
      statemtarg_2[31] = invSbox_2[statemtarg_2[15] >> 4][statemtarg_2[15] & 0xf];
      statemtarg_2[15] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[27] >> 4][statemtarg_2[27] & 0xf];
      statemtarg_2[27] = invSbox_2[statemtarg_2[11] >> 4][statemtarg_2[11] & 0xf];
      statemtarg_2[11] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[23] >> 4][statemtarg_2[23] & 0xf];
      statemtarg_2[23] = invSbox_2[statemtarg_2[7] >> 4][statemtarg_2[7] & 0xf];
      statemtarg_2[7] = temp_2;
      temp_2 = invSbox_2[statemtarg_2[19] >> 4][statemtarg_2[19] & 0xf];
      statemtarg_2[19] = invSbox_2[statemtarg_2[3] >> 4][statemtarg_2[3] & 0xf];
      statemtarg_2[3] = temp_2;
      statemtarg_2[0] = invSbox_2[statemtarg_2[0] >> 4][statemtarg_2[0] & 0xf];
      statemtarg_2[4] = invSbox_2[statemtarg_2[4] >> 4][statemtarg_2[4] & 0xf];
      statemtarg_2[8] = invSbox_2[statemtarg_2[8] >> 4][statemtarg_2[8] & 0xf];
      statemtarg_2[12] = invSbox_2[statemtarg_2[12] >> 4][statemtarg_2[12] & 0xf];
      statemtarg_2[16] = invSbox_2[statemtarg_2[16] >> 4][statemtarg_2[16] & 0xf];
      statemtarg_2[20] = invSbox_2[statemtarg_2[20] >> 4][statemtarg_2[20] & 0xf];
      statemtarg_2[24] = invSbox_2[statemtarg_2[24] >> 4][statemtarg_2[24] & 0xf];
      statemtarg_2[28] = invSbox_2[statemtarg_2[28] >> 4][statemtarg_2[28] & 0xf];
      break;

  }

  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(invSbox_1[i_0][i_1] == invSbox_2[i_0][i_1]);
    }

  }

  assert(temp_1 == temp_2);
}

void InversShiftRow_ByteSub(int statemtarg[32], int nb)
{
  int temp;
  switch (nb)
  {
    case 4:
      temp = invSbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = invSbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = invSbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = invSbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = temp;
      temp = invSbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = invSbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = temp;
      temp = invSbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = invSbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = temp;
      temp = invSbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = invSbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = invSbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = invSbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = temp;
      statemtarg[0] = invSbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = invSbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = invSbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = invSbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      break;

    case 6:
      temp = invSbox[statemtarg[21] >> 4][statemtarg[21] & 0xf];
      statemtarg[21] = invSbox[statemtarg[17] >> 4][statemtarg[17] & 0xf];
      statemtarg[17] = invSbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = invSbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = invSbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = invSbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = temp;
      temp = invSbox[statemtarg[22] >> 4][statemtarg[22] & 0xf];
      statemtarg[22] = invSbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = invSbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = temp;
      temp = invSbox[statemtarg[18] >> 4][statemtarg[18] & 0xf];
      statemtarg[18] = invSbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = invSbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = temp;
      temp = invSbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = invSbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = temp;
      temp = invSbox[statemtarg[19] >> 4][statemtarg[19] & 0xf];
      statemtarg[19] = invSbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = temp;
      temp = invSbox[statemtarg[23] >> 4][statemtarg[23] & 0xf];
      statemtarg[23] = invSbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = temp;
      statemtarg[0] = invSbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = invSbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = invSbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = invSbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      statemtarg[16] = invSbox[statemtarg[16] >> 4][statemtarg[16] & 0xf];
      statemtarg[20] = invSbox[statemtarg[20] >> 4][statemtarg[20] & 0xf];
      break;

    case 8:
      temp = invSbox[statemtarg[29] >> 4][statemtarg[29] & 0xf];
      statemtarg[29] = invSbox[statemtarg[25] >> 4][statemtarg[25] & 0xf];
      statemtarg[25] = invSbox[statemtarg[21] >> 4][statemtarg[21] & 0xf];
      statemtarg[21] = invSbox[statemtarg[17] >> 4][statemtarg[17] & 0xf];
      statemtarg[17] = invSbox[statemtarg[13] >> 4][statemtarg[13] & 0xf];
      statemtarg[13] = invSbox[statemtarg[9] >> 4][statemtarg[9] & 0xf];
      statemtarg[9] = invSbox[statemtarg[5] >> 4][statemtarg[5] & 0xf];
      statemtarg[5] = invSbox[statemtarg[1] >> 4][statemtarg[1] & 0xf];
      statemtarg[1] = temp;
      temp = invSbox[statemtarg[30] >> 4][statemtarg[30] & 0xf];
      statemtarg[30] = invSbox[statemtarg[18] >> 4][statemtarg[18] & 0xf];
      statemtarg[18] = invSbox[statemtarg[6] >> 4][statemtarg[6] & 0xf];
      statemtarg[6] = invSbox[statemtarg[26] >> 4][statemtarg[26] & 0xf];
      statemtarg[26] = invSbox[statemtarg[14] >> 4][statemtarg[14] & 0xf];
      statemtarg[14] = invSbox[statemtarg[2] >> 4][statemtarg[2] & 0xf];
      statemtarg[2] = invSbox[statemtarg[22] >> 4][statemtarg[22] & 0xf];
      statemtarg[22] = invSbox[statemtarg[10] >> 4][statemtarg[10] & 0xf];
      statemtarg[10] = temp;
      temp = invSbox[statemtarg[31] >> 4][statemtarg[31] & 0xf];
      statemtarg[31] = invSbox[statemtarg[15] >> 4][statemtarg[15] & 0xf];
      statemtarg[15] = temp;
      temp = invSbox[statemtarg[27] >> 4][statemtarg[27] & 0xf];
      statemtarg[27] = invSbox[statemtarg[11] >> 4][statemtarg[11] & 0xf];
      statemtarg[11] = temp;
      temp = invSbox[statemtarg[23] >> 4][statemtarg[23] & 0xf];
      statemtarg[23] = invSbox[statemtarg[7] >> 4][statemtarg[7] & 0xf];
      statemtarg[7] = temp;
      temp = invSbox[statemtarg[19] >> 4][statemtarg[19] & 0xf];
      statemtarg[19] = invSbox[statemtarg[3] >> 4][statemtarg[3] & 0xf];
      statemtarg[3] = temp;
      statemtarg[0] = invSbox[statemtarg[0] >> 4][statemtarg[0] & 0xf];
      statemtarg[4] = invSbox[statemtarg[4] >> 4][statemtarg[4] & 0xf];
      statemtarg[8] = invSbox[statemtarg[8] >> 4][statemtarg[8] & 0xf];
      statemtarg[12] = invSbox[statemtarg[12] >> 4][statemtarg[12] & 0xf];
      statemtarg[16] = invSbox[statemtarg[16] >> 4][statemtarg[16] & 0xf];
      statemtarg[20] = invSbox[statemtarg[20] >> 4][statemtarg[20] & 0xf];
      statemtarg[24] = invSbox[statemtarg[24] >> 4][statemtarg[24] & 0xf];
      statemtarg[28] = invSbox[statemtarg[28] >> 4][statemtarg[28] & 0xf];
      break;

  }

}

void MixColumn_AddRoundKey_2(int statemtarg_1[32], int nb_1, int n_1, int statemtarg_2[32], int nb_2, int n_2)
{
  int ret_1[8 * 4];
  int ret_2[8 * 4];
  int j_1;
  int j_2;
  register int x_1;
  register int x_2;
  int word_1[4][120];
  int word_2[4][120];
  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    ret_1[j_1 * 4] = statemtarg_1[j_1 * 4] << 1;
    ret_2[j_2 * 4] = statemtarg_2[j_2 * 4] << 1;
    if ((ret_1[j_1 * 4] >> 8) == 1)
    {
      ret_1[j_1 * 4] ^= 283;
    }
    if ((ret_2[j_2 * 4] >> 8) == 1)
    {
      ret_2[j_2 * 4] ^= 283;
    }
    x_1 = statemtarg_1[1 + (j_1 * 4)];
    x_2 = statemtarg_2[1 + (j_2 * 4)];
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
    ret_1[j_1 * 4] ^= (statemtarg_1[2 + (j_1 * 4)] ^ statemtarg_1[3 + (j_1 * 4)]) ^ word_1[0][j_1 + (nb_1 * n_1)];
    ret_2[j_2 * 4] ^= (statemtarg_2[2 + (j_2 * 4)] ^ statemtarg_2[3 + (j_2 * 4)]) ^ word_2[0][j_2 + (nb_2 * n_2)];
    ret_1[1 + (j_1 * 4)] = statemtarg_1[1 + (j_1 * 4)] << 1;
    ret_2[1 + (j_2 * 4)] = statemtarg_2[1 + (j_2 * 4)] << 1;
    if ((ret_1[1 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[1 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[1 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[1 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemtarg_1[2 + (j_1 * 4)];
    x_2 = statemtarg_2[2 + (j_2 * 4)];
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
    ret_1[1 + (j_1 * 4)] ^= (statemtarg_1[3 + (j_1 * 4)] ^ statemtarg_1[j_1 * 4]) ^ word_1[1][j_1 + (nb_1 * n_1)];
    ret_2[1 + (j_2 * 4)] ^= (statemtarg_2[3 + (j_2 * 4)] ^ statemtarg_2[j_2 * 4]) ^ word_2[1][j_2 + (nb_2 * n_2)];
    ret_1[2 + (j_1 * 4)] = statemtarg_1[2 + (j_1 * 4)] << 1;
    ret_2[2 + (j_2 * 4)] = statemtarg_2[2 + (j_2 * 4)] << 1;
    if ((ret_1[2 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[2 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[2 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[2 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemtarg_1[3 + (j_1 * 4)];
    x_2 = statemtarg_2[3 + (j_2 * 4)];
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
    ret_1[2 + (j_1 * 4)] ^= (statemtarg_1[j_1 * 4] ^ statemtarg_1[1 + (j_1 * 4)]) ^ word_1[2][j_1 + (nb_1 * n_1)];
    ret_2[2 + (j_2 * 4)] ^= (statemtarg_2[j_2 * 4] ^ statemtarg_2[1 + (j_2 * 4)]) ^ word_2[2][j_2 + (nb_2 * n_2)];
    ret_1[3 + (j_1 * 4)] = statemtarg_1[3 + (j_1 * 4)] << 1;
    ret_2[3 + (j_2 * 4)] = statemtarg_2[3 + (j_2 * 4)] << 1;
    if ((ret_1[3 + (j_1 * 4)] >> 8) == 1)
    {
      ret_1[3 + (j_1 * 4)] ^= 283;
    }
    if ((ret_2[3 + (j_2 * 4)] >> 8) == 1)
    {
      ret_2[3 + (j_2 * 4)] ^= 283;
    }
    x_1 = statemtarg_1[j_1 * 4];
    x_2 = statemtarg_2[j_2 * 4];
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
    ret_1[3 + (j_1 * 4)] ^= (statemtarg_1[1 + (j_1 * 4)] ^ statemtarg_1[2 + (j_1 * 4)]) ^ word_1[3][j_1 + (nb_1 * n_1)];
    ret_2[3 + (j_2 * 4)] ^= (statemtarg_2[1 + (j_2 * 4)] ^ statemtarg_2[2 + (j_2 * 4)]) ^ word_2[3][j_2 + (nb_2 * n_2)];
  }

  int i_1;
  int i_2;
  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    statemtarg_1[j_1 * 4] = ret_1[j_1 * 4];
    statemtarg_2[j_2 * 4] = ret_2[j_2 * 4];
    statemtarg_1[1 + (j_1 * 4)] = ret_1[1 + (j_1 * 4)];
    statemtarg_2[1 + (j_2 * 4)] = ret_2[1 + (j_2 * 4)];
    statemtarg_1[2 + (j_1 * 4)] = ret_1[2 + (j_1 * 4)];
    statemtarg_2[2 + (j_2 * 4)] = ret_2[2 + (j_2 * 4)];
    statemtarg_1[3 + (j_1 * 4)] = ret_1[3 + (j_1 * 4)];
    statemtarg_2[3 + (j_2 * 4)] = ret_2[3 + (j_2 * 4)];
  }

  assert(nb_1 == nb_2);
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
  assert(i_1 == i_2);
}

int MixColumn_AddRoundKey(int statemtarg[32], int nb, int n)
{
  int ret[8 * 4];
  int j;
  register int x;
  int word[4][120];
  for (j = 0; j < nb; ++j)
  {
    ret[j * 4] = statemtarg[j * 4] << 1;
    if ((ret[j * 4] >> 8) == 1)
    {
      ret[j * 4] ^= 283;
    }
    x = statemtarg[1 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[j * 4] ^= x ^ 283;
    }
    else
    {
      ret[j * 4] ^= x;
    }
    ret[j * 4] ^= (statemtarg[2 + (j * 4)] ^ statemtarg[3 + (j * 4)]) ^ word[0][j + (nb * n)];
    ret[1 + (j * 4)] = statemtarg[1 + (j * 4)] << 1;
    if ((ret[1 + (j * 4)] >> 8) == 1)
    {
      ret[1 + (j * 4)] ^= 283;
    }
    x = statemtarg[2 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[1 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[1 + (j * 4)] ^= x;
    }
    ret[1 + (j * 4)] ^= (statemtarg[3 + (j * 4)] ^ statemtarg[j * 4]) ^ word[1][j + (nb * n)];
    ret[2 + (j * 4)] = statemtarg[2 + (j * 4)] << 1;
    if ((ret[2 + (j * 4)] >> 8) == 1)
    {
      ret[2 + (j * 4)] ^= 283;
    }
    x = statemtarg[3 + (j * 4)];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[2 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[2 + (j * 4)] ^= x;
    }
    ret[2 + (j * 4)] ^= (statemtarg[j * 4] ^ statemtarg[1 + (j * 4)]) ^ word[2][j + (nb * n)];
    ret[3 + (j * 4)] = statemtarg[3 + (j * 4)] << 1;
    if ((ret[3 + (j * 4)] >> 8) == 1)
    {
      ret[3 + (j * 4)] ^= 283;
    }
    x = statemtarg[j * 4];
    x ^= x << 1;
    if ((x >> 8) == 1)
    {
      ret[3 + (j * 4)] ^= x ^ 283;
    }
    else
    {
      ret[3 + (j * 4)] ^= x;
    }
    ret[3 + (j * 4)] ^= (statemtarg[1 + (j * 4)] ^ statemtarg[2 + (j * 4)]) ^ word[3][j + (nb * n)];
  }

  int i;
  for (j = 0; j < nb; ++j)
  {
    statemtarg[j * 4] = ret[j * 4];
    statemtarg[1 + (j * 4)] = ret[1 + (j * 4)];
    statemtarg[2 + (j * 4)] = ret[2 + (j * 4)];
    statemtarg[3 + (j * 4)] = ret[3 + (j * 4)];
  }

  return 0;
}

void AddRoundKey_InversMixColumn_2(int statemtarg_1[32], int nb_1, int n_1, int statemtarg_2[32], int nb_2, int n_2)
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
    statemtarg_1[j_1 * 4] ^= word_1[0][j_1 + (nb_1 * n_1)];
    statemtarg_2[j_2 * 4] ^= word_2[0][j_2 + (nb_2 * n_2)];
    statemtarg_1[1 + (j_1 * 4)] ^= word_1[1][j_1 + (nb_1 * n_1)];
    statemtarg_2[1 + (j_2 * 4)] ^= word_2[1][j_2 + (nb_2 * n_2)];
    statemtarg_1[2 + (j_1 * 4)] ^= word_1[2][j_1 + (nb_1 * n_1)];
    statemtarg_2[2 + (j_2 * 4)] ^= word_2[2][j_2 + (nb_2 * n_2)];
    statemtarg_1[3 + (j_1 * 4)] ^= word_1[3][j_1 + (nb_1 * n_1)];
    statemtarg_2[3 + (j_2 * 4)] ^= word_2[3][j_2 + (nb_2 * n_2)];
  }

  for (j_1 = 0, j_2 = 0; (j_1 < nb_1) && (j_2 < nb_2); ++j_1, ++j_2)
  {
    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); ++i_1, ++i_2)
    {
      x_1 = statemtarg_1[i_1 + (j_1 * 4)] << 1;
      x_2 = statemtarg_2[i_2 + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemtarg_1[i_1 + (j_1 * 4)];
      x_2 ^= statemtarg_2[i_2 + (j_2 * 4)];
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
      x_1 ^= statemtarg_1[i_1 + (j_1 * 4)];
      x_2 ^= statemtarg_2[i_2 + (j_2 * 4)];
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
      x_1 = statemtarg_1[((i_1 + 1) % 4) + (j_1 * 4)] << 1;
      x_2 = statemtarg_2[((i_2 + 1) % 4) + (j_2 * 4)] << 1;
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
      x_1 ^= statemtarg_1[((i_1 + 1) % 4) + (j_1 * 4)];
      x_2 ^= statemtarg_2[((i_2 + 1) % 4) + (j_2 * 4)];
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
      x_1 ^= statemtarg_1[((i_1 + 1) % 4) + (j_1 * 4)];
      x_2 ^= statemtarg_2[((i_2 + 1) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
      x_1 = statemtarg_1[((i_1 + 2) % 4) + (j_1 * 4)] << 1;
      x_2 = statemtarg_2[((i_2 + 2) % 4) + (j_2 * 4)] << 1;
      if ((x_1 >> 8) == 1)
      {
        x_1 ^= 283;
      }
      if ((x_2 >> 8) == 1)
      {
        x_2 ^= 283;
      }
      x_1 ^= statemtarg_1[((i_1 + 2) % 4) + (j_1 * 4)];
      x_2 ^= statemtarg_2[((i_2 + 2) % 4) + (j_2 * 4)];
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
      x_1 ^= statemtarg_1[((i_1 + 2) % 4) + (j_1 * 4)];
      x_2 ^= statemtarg_2[((i_2 + 2) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
      x_1 = statemtarg_1[((i_1 + 3) % 4) + (j_1 * 4)] << 1;
      x_2 = statemtarg_2[((i_2 + 3) % 4) + (j_2 * 4)] << 1;
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
      x_1 ^= statemtarg_1[((i_1 + 3) % 4) + (j_1 * 4)];
      x_2 ^= statemtarg_2[((i_2 + 3) % 4) + (j_2 * 4)];
      ret_1[i_1 + (j_1 * 4)] ^= x_1;
      ret_2[i_2 + (j_2 * 4)] ^= x_2;
    }

  }

  for (i_1 = 0, i_2 = 0; (i_1 < nb_1) && (i_2 < nb_2); ++i_1, ++i_2)
  {
    statemtarg_1[i_1 * 4] = ret_1[i_1 * 4];
    statemtarg_2[i_2 * 4] = ret_2[i_2 * 4];
    statemtarg_1[1 + (i_1 * 4)] = ret_1[1 + (i_1 * 4)];
    statemtarg_2[1 + (i_2 * 4)] = ret_2[1 + (i_2 * 4)];
    statemtarg_1[2 + (i_1 * 4)] = ret_1[2 + (i_1 * 4)];
    statemtarg_2[2 + (i_2 * 4)] = ret_2[2 + (i_2 * 4)];
    statemtarg_1[3 + (i_1 * 4)] = ret_1[3 + (i_1 * 4)];
    statemtarg_2[3 + (i_2 * 4)] = ret_2[3 + (i_2 * 4)];
  }

  assert(nb_1 == nb_2);
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

int AddRoundKey_InversMixColumn(int statemtarg[32], int nb, int n)
{
  int ret[8 * 4];
  int i;
  int j;
  register int x;
  for (j = 0; j < nb; ++j)
  {
    statemtarg[j * 4] ^= word[0][j + (nb * n)];
    statemtarg[1 + (j * 4)] ^= word[1][j + (nb * n)];
    statemtarg[2 + (j * 4)] ^= word[2][j + (nb * n)];
    statemtarg[3 + (j * 4)] ^= word[3][j + (nb * n)];
  }

  for (j = 0; j < nb; ++j)
  {
    for (i = 0; i < 4; ++i)
    {
      x = statemtarg[i + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemtarg[i + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemtarg[i + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      ret[i + (j * 4)] = x;
      x = statemtarg[((i + 1) % 4) + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemtarg[((i + 1) % 4) + (j * 4)];
      x = x << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemtarg[((i + 1) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
      x = statemtarg[((i + 2) % 4) + (j * 4)] << 1;
      if ((x >> 8) == 1)
      {
        x ^= 283;
      }
      x ^= statemtarg[((i + 2) % 4) + (j * 4)];
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
      x ^= statemtarg[((i + 2) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
      x = statemtarg[((i + 3) % 4) + (j * 4)] << 1;
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
      x ^= statemtarg[((i + 3) % 4) + (j * 4)];
      ret[i + (j * 4)] ^= x;
    }

  }

  for (i = 0; i < nb; ++i)
  {
    statemtarg[i * 4] = ret[i * 4];
    statemtarg[1 + (i * 4)] = ret[1 + (i * 4)];
    statemtarg[2 + (i * 4)] = ret[2 + (i * 4)];
    statemtarg[3 + (i * 4)] = ret[3 + (i * 4)];
  }

  return 0;
}

void AddRoundKey_2(int statemtarg_1[32], int type_1, int n_1, int word_1[4][120], int statemtarg_2[32], int type_2, int n_2, int word_2[4][120])
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
    statemtarg_1[j_1 * 4] ^= word_1[0][j_1 + (nb_1 * n_1)];
    statemtarg_2[j_2 * 4] ^= word_2[0][j_2 + (nb_2 * n_2)];
    statemtarg_1[1 + (j_1 * 4)] ^= word_1[1][j_1 + (nb_1 * n_1)];
    statemtarg_2[1 + (j_2 * 4)] ^= word_2[1][j_2 + (nb_2 * n_2)];
    statemtarg_1[2 + (j_1 * 4)] ^= word_1[2][j_1 + (nb_1 * n_1)];
    statemtarg_2[2 + (j_2 * 4)] ^= word_2[2][j_2 + (nb_2 * n_2)];
    statemtarg_1[3 + (j_1 * 4)] ^= word_1[3][j_1 + (nb_1 * n_1)];
    statemtarg_2[3 + (j_2 * 4)] ^= word_2[3][j_2 + (nb_2 * n_2)];
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(j_1 == j_2);
}

int AddRoundKey(int statemtarg[32], int type, int n, int word[4][120])
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
    statemtarg[j * 4] ^= word[0][j + (nb * n)];
    statemtarg[1 + (j * 4)] ^= word[1][j + (nb * n)];
    statemtarg[2 + (j * 4)] ^= word[2][j + (nb * n)];
    statemtarg[3 + (j * 4)] ^= word[3][j + (nb * n)];
  }

  return 0;
}

void aes_func_call_2(int statemt1_1[32], int statemt1_2[32])
{
  int type_1 = 128128;
  int type_2 = 128128;
  int nb_1 = 4;
  int nb_2 = 4;
  int i1_1;
  int i1_2;
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  int statemt_1[32];
  int statemt_2[32];
  for (i_1 = 0, i_2 = 0; (i_1 < 32) && (i_2 < 32); i_1++, i_2++)
  {
    statemt_1[i_1] = statemt1_1[i_1];
    statemt_2[i_2] = statemt1_2[i_2];
  }

  int word1_1[4][120];
  int word1_2[4][120];
  AddRoundKey(statemt_1, type_1, 0, word1_1);
  AddRoundKey(statemt_2, type_2, 0, word1_2);
  AddRoundKey_2(statemt_1, type_1, 0, word1_1, statemt_2, type_2, 0, word1_2);
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
  AddRoundKey(statemt_1, type_1, i_1, word1_1);
  AddRoundKey(statemt_2, type_2, i_2, word1_2);
  AddRoundKey_2(statemt_1, type_1, i_1, word1_1, statemt_2, type_2, i_2, word1_2);
  for (i_1 = 0, i_2 = 0; (i_1 < 32) && (i_2 < 32); i_1++, i_2++)
  {
    statemt1_1[i_1] = statemt_1[i_1];
    statemt1_2[i_2] = statemt_2[i_2];
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  assert(round_val_1 == round_val_2);
  assert(i1_1 == i1_2);
  assert(i_1 == i_2);
  assert(j_1 == j_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word1_1[i_0][i_1] == word1_2[i_0][i_1]);
    }

  }

}

void aes_func_call(int statemt1[32])
{
  int type = 128128;
  int nb = 4;
  int i1;
  int i;
  int j;
  int statemt[32];
  for (i = 0; i < 32; i++)
  {
    statemt[i] = statemt1[i];
  }

  int word1[4][120];
  AddRoundKey(statemt, type, 0, word1);
  for (i = 1; i <= (round_val + 9); ++i)
  {
    ByteSub_ShiftRow(statemt, nb);
    MixColumn_AddRoundKey(statemt, nb, i);
  }

  ByteSub_ShiftRow(statemt, nb);
  AddRoundKey(statemt, type, i, word1);
  for (i = 0; i < 32; i++)
  {
    statemt1[i] = statemt[i];
  }

}

void encrypt_2(int statemtarg_1[32], int keyarg_1[32], int type_1, int statemtarg_2[32], int keyarg_2[32], int type_2)
{
  int i_1;
  int i_2;
  const int out_enc_statemt_1[16];
  const int out_enc_statemt_2[16];
  int i1_1;
  int i1_2;
  KeySchedule(type_1, keyarg_1);
  KeySchedule(type_2, keyarg_2);
  KeySchedule_2(type_1, keyarg_1, type_2, keyarg_2);
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

  aes_func_call(statemtarg_1);
  aes_func_call(statemtarg_2);
  aes_func_call_2(statemtarg_1, statemtarg_2);
  int main_result_1;
  int main_result_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    main_result_1 += statemtarg_1[i_1] != out_enc_statemt_1[i_1];
    main_result_2 += statemtarg_2[i_2] != out_enc_statemt_2[i_2];
  }

  assert(type_1 == type_2);
  assert(nb_1 == nb_2);
  assert(round_val_1 == round_val_2);
  assert(main_result_1 == main_result_2);
  assert(i_1 == i_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(out_enc_statemt_1[i_0] == out_enc_statemt_2[i_0]);
  }

  assert(i1_1 == i1_2);
}

int encrypt(int statemtarg[32], int keyarg[32], int type)
{
  int i;
  const int out_enc_statemt[16];
  int i1;
  KeySchedule(type, keyarg);
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

  aes_func_call(statemtarg);
  int main_result;
  for (i = 0; i < 16; i++)
  {
    main_result += statemtarg[i] != out_enc_statemt[i];
  }

  return 0;
}


