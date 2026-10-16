int type;
int nb;
int round_val;
int key[32];
int word[4][120];
int main_result;
const int Sbox[16][16];

int SubByte(int in) { return Sbox[(in / 16)][(in % 16)]; }

const int invSbox[16][16];

void main() {
  int statemt[32];
  encrypt(statemt, key, 128128);
}

const int Rcon0[30];
int KeySchedule(int type, int keyarg[32]) {

  int nk, nb, round_val;
  int i, j, temp[4];
  switch (type) {
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
  for (j = 0; j < nk; ++j) {
    for (i = 0; i < 4; ++i) {
      word[i][j] = keyarg[i + j * 4];
    }
  }

  for (j = nk; j < nb * (round_val + 1); ++j) {

    if ((j % nk) == 0) {
      temp[0] = SubByte(word[1][j - 1]) ^ Rcon0[(j / nk) - 1];
      temp[1] = SubByte(word[2][j - 1]);
      temp[2] = SubByte(word[3][j - 1]);
      temp[3] = SubByte(word[0][j - 1]);
    }
    if ((j % nk) != 0) {
      temp[0] = word[0][j - 1];
      temp[1] = word[1][j - 1];
      temp[2] = word[2][j - 1];
      temp[3] = word[3][j - 1];
    }
    if (nk > 6 && j % nk == 4) {
      for (i = 0; i < 4; ++i) {
        temp[i] = SubByte(temp[i]);
      }
    }
    for (i = 0; i < 4; ++i) {
      word[i][j] = word[i][j - nk] ^ temp[i];
    }
  }

  return 0;
}

void ByteSub_ShiftRow(int statemtarg[32], int nb) {
  int temp;

  switch (nb) {
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

void InversShiftRow_ByteSub(int statemtarg[32], int nb) {
  int temp;

  switch (nb) {
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

int MixColumn_AddRoundKey(int statemtarg[32], int nb, int n) {
  int ret[8 * 4], j;
  register int x;

  int word[4][120];

  for (j = 0; j < nb; ++j) {
    ret[j * 4] = (statemtarg[j * 4] << 1);
    if ((ret[j * 4] >> 8) == 1) {
      ret[j * 4] ^= 283;
    }
    x = statemtarg[1 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1) {
      ret[j * 4] ^= (x ^ 283);
    } else {
      ret[j * 4] ^= x;
    }
    ret[j * 4] ^=
        statemtarg[2 + j * 4] ^ statemtarg[3 + j * 4] ^ word[0][j + nb * n];

    ret[1 + j * 4] = (statemtarg[1 + j * 4] << 1);
    if ((ret[1 + j * 4] >> 8) == 1) {
      ret[1 + j * 4] ^= 283;
    }
    x = statemtarg[2 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1) {
      ret[1 + j * 4] ^= (x ^ 283);
    } else {
      ret[1 + j * 4] ^= x;
    }
    ret[1 + j * 4] ^=
        statemtarg[3 + j * 4] ^ statemtarg[j * 4] ^ word[1][j + nb * n];

    ret[2 + j * 4] = (statemtarg[2 + j * 4] << 1);
    if ((ret[2 + j * 4] >> 8) == 1) {
      ret[2 + j * 4] ^= 283;
    }
    x = statemtarg[3 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1) {
      ret[2 + j * 4] ^= (x ^ 283);
    } else {
      ret[2 + j * 4] ^= x;
    }
    ret[2 + j * 4] ^=
        statemtarg[j * 4] ^ statemtarg[1 + j * 4] ^ word[2][j + nb * n];

    ret[3 + j * 4] = (statemtarg[3 + j * 4] << 1);
    if ((ret[3 + j * 4] >> 8) == 1) {
      ret[3 + j * 4] ^= 283;
    }
    x = statemtarg[j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1) {
      ret[3 + j * 4] ^= (x ^ 283);
    } else {
      ret[3 + j * 4] ^= x;
    }
    ret[3 + j * 4] ^=
        statemtarg[1 + j * 4] ^ statemtarg[2 + j * 4] ^ word[3][j + nb * n];
  }
  int i;

  for (j = 0; j < nb; ++j) {
    statemtarg[j * 4] = ret[j * 4];
    statemtarg[1 + j * 4] = ret[1 + j * 4];
    statemtarg[2 + j * 4] = ret[2 + j * 4];
    statemtarg[3 + j * 4] = ret[3 + j * 4];
  }
  return 0;
}

int AddRoundKey_InversMixColumn(int statemtarg[32], int nb, int n) {
  int ret[8 * 4], i, j;
  register int x;

  for (j = 0; j < nb; ++j) {
    statemtarg[j * 4] ^= word[0][j + nb * n];
    statemtarg[1 + j * 4] ^= word[1][j + nb * n];
    statemtarg[2 + j * 4] ^= word[2][j + nb * n];
    statemtarg[3 + j * 4] ^= word[3][j + nb * n];
  }
  for (j = 0; j < nb; ++j) {
    for (i = 0; i < 4; ++i) {
      x = (statemtarg[i + j * 4] << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[i + j * 4];
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[i + j * 4];
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      ret[i + j * 4] = x;

      x = (statemtarg[(i + 1) % 4 + j * 4] << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[(i + 1) % 4 + j * 4];
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[(i + 1) % 4 + j * 4];
      ret[i + j * 4] ^= x;

      x = (statemtarg[(i + 2) % 4 + j * 4] << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[(i + 2) % 4 + j * 4];
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[(i + 2) % 4 + j * 4];
      ret[i + j * 4] ^= x;

      x = (statemtarg[(i + 3) % 4 + j * 4] << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x = (x << 1);
      if ((x >> 8) == 1) {
        x ^= 283;
      }
      x ^= statemtarg[(i + 3) % 4 + j * 4];
      ret[i + j * 4] ^= x;
    }
  }

  for (i = 0; i < nb; ++i) {
    statemtarg[i * 4] = ret[i * 4];
    statemtarg[1 + i * 4] = ret[1 + i * 4];
    statemtarg[2 + i * 4] = ret[2 + i * 4];
    statemtarg[3 + i * 4] = ret[3 + i * 4];
  }
  return 0;
}

int AddRoundKey(int statemtarg[32], int type, int n, int word[4][120]) {
  int j, nb;
  switch (type) {
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
  for (j = 0; j < nb; ++j) {

    statemtarg[j * 4] ^= word[0][j + nb * n];
    statemtarg[1 + j * 4] ^= word[1][j + nb * n];
    statemtarg[2 + j * 4] ^= word[2][j + nb * n];
    statemtarg[3 + j * 4] ^= word[3][j + nb * n];
  }
  return 0;
}

void aes_func_call(int statemt1[32]) {
  int type = 128128;
  int nb = 4;
  int i1, i, j;
  int statemt[32];

  for (i = 0; i < 32; i++) {
    statemt[i] = statemt1[i];
  }

  int word1[4][120];
  AddRoundKey(statemt, type, 0, word1);

  for (i = 1; i <= round_val + 9; ++i) {
    ByteSub_ShiftRow(statemt, nb);
    MixColumn_AddRoundKey(statemt, nb, i);
  }

  ByteSub_ShiftRow(statemt, nb);
  AddRoundKey(statemt, type, i, word1);
  for (i = 0; i < 32; i++) {
    statemt1[i] = statemt[i];
  }
}

int encrypt(int statemtarg[32], int keyarg[32], int type) {
  int i;

  const int out_enc_statemt[16];
  int i1;
  KeySchedule(type, keyarg);
  switch (type) {
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
  for (i = 0; i < 16; i++) {
    main_result += (statemtarg[i] != out_enc_statemt[i]);
  }

  return 0;
}