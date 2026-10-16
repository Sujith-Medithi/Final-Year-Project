typedef unsigned char BYTE;
typedef unsigned int INT32;
INT32 sha_info_digest_1[5];
INT32 sha_info_digest_2[5];
INT32 sha_info_digest[5];
INT32 sha_info_count_lo_1;
INT32 sha_info_count_lo_2;
INT32 sha_info_count_lo;
INT32 sha_info_count_hi_1;
INT32 sha_info_count_hi_2;
INT32 sha_info_count_hi;
INT32 sha_info_data_1[16];
INT32 sha_info_data_2[16];
INT32 sha_info_data[16];
void sha_init();
void sha_update(const BYTE *, int);
void sha_final();
void sha_stream();
void sha_print();
const BYTE indata_1[2][8192];
const BYTE indata_2[2][8192];
const BYTE indata[2][8192];
const int in_i_1[2];
const int in_i_2[2];
const int in_i[2];
INT32 nd_sha_info_digest();
void local_memset_2(INT32 *s_1, int c_1, int n_1, int e_1, INT32 *s_2, int c_2, int n_2, int e_2)
{
  INT32 uc_1;
  INT32 uc_2;
  INT32 *p_1;
  INT32 *p_2;
  int m_1;
  int m_2;
  m_1 = n_1 / 4;
  m_2 = n_2 / 4;
  uc_1 = c_1;
  uc_2 = c_2;
  p_1 = (INT32 *) s_1;
  p_2 = (INT32 *) s_2;
  while (((e_1--) > 0) && ((e_2--) > 0))
  {
    p_1++;
    p_2++;
  }

  while (((m_1--) > 0) && ((m_2--) > 0))
  {
    *(p_1++) = uc_1;
    *(p_2++) = uc_2;
  }

  assert(uc_1 == uc_2);
  assert((*p_1) == (*p_2));
  assert(m_1 == m_2);
}

void local_memset(INT32 *s, int c, int n, int e)
{
  INT32 uc;
  INT32 *p;
  int m;
  m = n / 4;
  uc = c;
  p = (INT32 *) s;
  while ((e--) > 0)
  {
    p++;
  }

  while ((m--) > 0)
  {
    *(p++) = uc;
  }

}

void local_memcpy_2(INT32 *s1_1, const BYTE *s2_1, int n_1, INT32 *s1_2, const BYTE *s2_2, int n_2)
{
  INT32 *p1_1;
  INT32 *p1_2;
  BYTE *p2_1;
  BYTE *p2_2;
  INT32 tmp_1;
  INT32 tmp_2;
  int m_1;
  int m_2;
  m_1 = n_1 / 4;
  m_2 = n_2 / 4;
  p1_1 = (INT32 *) s1_1;
  p1_2 = (INT32 *) s1_2;
  p2_1 = (BYTE *) s2_1;
  p2_2 = (BYTE *) s2_2;
  while (((m_1--) > 0) && ((m_2--) > 0))
  {
    tmp_1 = 0;
    tmp_2 = 0;
    tmp_1 |= 0xFF & (*(p2_1++));
    tmp_2 |= 0xFF & (*(p2_2++));
    tmp_1 |= (0xFF & (*(p2_1++))) << 8;
    tmp_2 |= (0xFF & (*(p2_2++))) << 8;
    tmp_1 |= (0xFF & (*(p2_1++))) << 16;
    tmp_2 |= (0xFF & (*(p2_2++))) << 16;
    tmp_1 |= (0xFF & (*(p2_1++))) << 24;
    tmp_2 |= (0xFF & (*(p2_2++))) << 24;
    *p1_1 = tmp_1;
    *p1_2 = tmp_2;
    p1_1++;
    p1_2++;
  }

  assert((*p1_1) == (*p1_2));
  assert((*p2_1) == (*p2_2));
  assert(tmp_1 == tmp_2);
  assert(m_1 == m_2);
}

void local_memcpy(INT32 *s1, const BYTE *s2, int n)
{
  INT32 *p1;
  BYTE *p2;
  INT32 tmp;
  int m;
  m = n / 4;
  p1 = (INT32 *) s1;
  p2 = (BYTE *) s2;
  while ((m--) > 0)
  {
    tmp = 0;
    tmp |= 0xFF & (*(p2++));
    tmp |= (0xFF & (*(p2++))) << 8;
    tmp |= (0xFF & (*(p2++))) << 16;
    tmp |= (0xFF & (*(p2++))) << 24;
    *p1 = tmp;
    p1++;
  }

}

static void sha_transform_2()
{
  int i_1;
  int i_2;
  INT32 temp_1;
  INT32 temp_2;
  INT32 A_1;
  INT32 A_2;
  INT32 B_1;
  INT32 B_2;
  INT32 C_1;
  INT32 C_2;
  INT32 D_1;
  INT32 D_2;
  INT32 E_1;
  INT32 E_2;
  INT32 W_1[80];
  INT32 W_2[80];
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); ++i_1, ++i_2)
  {
    W_1[i_1] = sha_info_data_1[i_1];
    W_2[i_2] = sha_info_data_2[i_2];
  }

  for (i_1 = 16, i_2 = 16; (i_1 < 80) && (i_2 < 80); ++i_1, ++i_2)
  {
    W_1[i_1] = ((W_1[i_1 - 3] ^ W_1[i_1 - 8]) ^ W_1[i_1 - 14]) ^ W_1[i_1 - 16];
    W_2[i_2] = ((W_2[i_2 - 3] ^ W_2[i_2 - 8]) ^ W_2[i_2 - 14]) ^ W_2[i_2 - 16];
  }

  A_1 = sha_info_digest_1[0];
  A_2 = sha_info_digest_2[0];
  B_1 = sha_info_digest_1[1];
  B_2 = sha_info_digest_2[1];
  C_1 = sha_info_digest_1[2];
  C_2 = sha_info_digest_2[2];
  D_1 = sha_info_digest_1[3];
  D_2 = sha_info_digest_2[3];
  E_1 = sha_info_digest_1[4];
  E_2 = sha_info_digest_2[4];
  for (i_1 = 0, i_2 = 0; (i_1 < 20) && (i_2 < 20); ++i_1, ++i_2)
  {
    temp_1 = (((((A_1 << 5) | (A_1 >> (32 - 5))) + ((B_1 & C_1) | ((~B_1) & D_1))) + E_1) + W_1[i_1]) + 0x5a827999L;
    temp_2 = (((((A_2 << 5) | (A_2 >> (32 - 5))) + ((B_2 & C_2) | ((~B_2) & D_2))) + E_2) + W_2[i_2]) + 0x5a827999L;
    E_1 = D_1;
    E_2 = D_2;
    D_1 = C_1;
    D_2 = C_2;
    C_1 = (B_1 << 30) | (B_1 >> (32 - 30));
    C_2 = (B_2 << 30) | (B_2 >> (32 - 30));
    B_1 = A_1;
    B_2 = A_2;
    A_1 = temp_1;
    A_2 = temp_2;
  }

  for (i_1 = 20, i_2 = 20; (i_1 < 40) && (i_2 < 40); ++i_1, ++i_2)
  {
    temp_1 = (((((A_1 << 5) | (A_1 >> (32 - 5))) + ((B_1 ^ C_1) ^ D_1)) + E_1) + W_1[i_1]) + 0x6ed9eba1L;
    temp_2 = (((((A_2 << 5) | (A_2 >> (32 - 5))) + ((B_2 ^ C_2) ^ D_2)) + E_2) + W_2[i_2]) + 0x6ed9eba1L;
    E_1 = D_1;
    E_2 = D_2;
    D_1 = C_1;
    D_2 = C_2;
    C_1 = (B_1 << 30) | (B_1 >> (32 - 30));
    C_2 = (B_2 << 30) | (B_2 >> (32 - 30));
    B_1 = A_1;
    B_2 = A_2;
    A_1 = temp_1;
    A_2 = temp_2;
  }

  for (i_1 = 40, i_2 = 40; (i_1 < 60) && (i_2 < 60); ++i_1, ++i_2)
  {
    temp_1 = (((((A_1 << 5) | (A_1 >> (32 - 5))) + (((B_1 & C_1) | (B_1 & D_1)) | (C_1 & D_1))) + E_1) + W_1[i_1]) + 0x8f1bbcdcL;
    temp_2 = (((((A_2 << 5) | (A_2 >> (32 - 5))) + (((B_2 & C_2) | (B_2 & D_2)) | (C_2 & D_2))) + E_2) + W_2[i_2]) + 0x8f1bbcdcL;
    E_1 = D_1;
    E_2 = D_2;
    D_1 = C_1;
    D_2 = C_2;
    C_1 = (B_1 << 30) | (B_1 >> (32 - 30));
    C_2 = (B_2 << 30) | (B_2 >> (32 - 30));
    B_1 = A_1;
    B_2 = A_2;
    A_1 = temp_1;
    A_2 = temp_2;
  }

  for (i_1 = 60, i_2 = 60; (i_1 < 80) && (i_2 < 80); ++i_1, ++i_2)
  {
    temp_1 = (((((A_1 << 5) | (A_1 >> (32 - 5))) + ((B_1 ^ C_1) ^ D_1)) + E_1) + W_1[i_1]) + 0xca62c1d6L;
    temp_2 = (((((A_2 << 5) | (A_2 >> (32 - 5))) + ((B_2 ^ C_2) ^ D_2)) + E_2) + W_2[i_2]) + 0xca62c1d6L;
    E_1 = D_1;
    E_2 = D_2;
    D_1 = C_1;
    D_2 = C_2;
    C_1 = (B_1 << 30) | (B_1 >> (32 - 30));
    C_2 = (B_2 << 30) | (B_2 >> (32 - 30));
    B_1 = A_1;
    B_2 = A_2;
    A_1 = temp_1;
    A_2 = temp_2;
  }

  sha_info_digest_1[0] += A_1;
  sha_info_digest_2[0] += A_2;
  sha_info_digest_1[1] += B_1;
  sha_info_digest_2[1] += B_2;
  sha_info_digest_1[2] += C_1;
  sha_info_digest_2[2] += C_2;
  sha_info_digest_1[3] += D_1;
  sha_info_digest_2[3] += D_2;
  sha_info_digest_1[4] += E_1;
  sha_info_digest_2[4] += E_2;
  assert(i_1 == i_2);
  assert(temp_1 == temp_2);
  assert(A_1 == A_2);
  assert(B_1 == B_2);
  assert(C_1 == C_2);
  assert(D_1 == D_2);
  assert(E_1 == E_2);
  for (int i_0 = 0; i_0 < 80; i_0++)
  {
    assert(W_1[i_0] == W_2[i_0]);
  }

}

static void sha_transform()
{
  int i;
  INT32 temp;
  INT32 A;
  INT32 B;
  INT32 C;
  INT32 D;
  INT32 E;
  INT32 W[80];
  for (i = 0; i < 16; ++i)
  {
    W[i] = sha_info_data[i];
  }

  for (i = 16; i < 80; ++i)
  {
    W[i] = ((W[i - 3] ^ W[i - 8]) ^ W[i - 14]) ^ W[i - 16];
  }

  A = sha_info_digest[0];
  B = sha_info_digest[1];
  C = sha_info_digest[2];
  D = sha_info_digest[3];
  E = sha_info_digest[4];
  for (i = 0; i < 20; ++i)
  {
    temp = (((((A << 5) | (A >> (32 - 5))) + ((B & C) | ((~B) & D))) + E) + W[i]) + 0x5a827999L;
    E = D;
    D = C;
    C = (B << 30) | (B >> (32 - 30));
    B = A;
    A = temp;
  }

  for (i = 20; i < 40; ++i)
  {
    temp = (((((A << 5) | (A >> (32 - 5))) + ((B ^ C) ^ D)) + E) + W[i]) + 0x6ed9eba1L;
    E = D;
    D = C;
    C = (B << 30) | (B >> (32 - 30));
    B = A;
    A = temp;
  }

  for (i = 40; i < 60; ++i)
  {
    temp = (((((A << 5) | (A >> (32 - 5))) + (((B & C) | (B & D)) | (C & D))) + E) + W[i]) + 0x8f1bbcdcL;
    E = D;
    D = C;
    C = (B << 30) | (B >> (32 - 30));
    B = A;
    A = temp;
  }

  for (i = 60; i < 80; ++i)
  {
    temp = (((((A << 5) | (A >> (32 - 5))) + ((B ^ C) ^ D)) + E) + W[i]) + 0xca62c1d6L;
    E = D;
    D = C;
    C = (B << 30) | (B >> (32 - 30));
    B = A;
    A = temp;
  }

  sha_info_digest[0] += A;
  sha_info_digest[1] += B;
  sha_info_digest[2] += C;
  sha_info_digest[3] += D;
  sha_info_digest[4] += E;
}

void sha_init_2()
{
  sha_info_digest_1[0] = 0x67452301L;
  sha_info_digest_2[0] = 0x67452301L;
  sha_info_digest_1[1] = 0xefcdab89L;
  sha_info_digest_2[1] = 0xefcdab89L;
  sha_info_digest_1[2] = 0x98badcfeL;
  sha_info_digest_2[2] = 0x98badcfeL;
  sha_info_digest_1[3] = 0x10325476L;
  sha_info_digest_2[3] = 0x10325476L;
  sha_info_digest_1[4] = 0xc3d2e1f0L;
  sha_info_digest_2[4] = 0xc3d2e1f0L;
  sha_info_count_lo_1 = 0L;
  sha_info_count_lo_2 = 0L;
  sha_info_count_hi_1 = 0L;
  sha_info_count_hi_2 = 0L;
  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
}

void sha_init()
{
  sha_info_digest[0] = 0x67452301L;
  sha_info_digest[1] = 0xefcdab89L;
  sha_info_digest[2] = 0x98badcfeL;
  sha_info_digest[3] = 0x10325476L;
  sha_info_digest[4] = 0xc3d2e1f0L;
  sha_info_count_lo = 0L;
  sha_info_count_hi = 0L;
}

void sha_update_2(const BYTE *buffer_1, int count_1, const BYTE *buffer_2, int count_2)
{
  if ((sha_info_count_lo_1 + (((INT32) count_1) << 3)) < sha_info_count_lo_1)
  {
    ++sha_info_count_hi_1;
  }
  if ((sha_info_count_lo_2 + (((INT32) count_2) << 3)) < sha_info_count_lo_2)
  {
    ++sha_info_count_hi_2;
  }
  sha_info_count_lo_1 += ((INT32) count_1) << 3;
  sha_info_count_lo_2 += ((INT32) count_2) << 3;
  sha_info_count_hi_1 += ((INT32) count_1) >> 29;
  sha_info_count_hi_2 += ((INT32) count_2) >> 29;
  while ((count_1 >= 64) && (count_2 >= 64))
  {
    local_memcpy(sha_info_data_1, buffer_1, 64);
    local_memcpy(sha_info_data_2, buffer_2, 64);
    local_memcpy_2(sha_info_data_1, buffer_1, 64, sha_info_data_2, buffer_2, 64);
    sha_transform();
    sha_transform();
    sha_transform_2();
    buffer_1 += 64;
    buffer_2 += 64;
    count_1 -= 64;
    count_2 -= 64;
  }

  local_memcpy(sha_info_data_1, buffer_1, count_1);
  local_memcpy(sha_info_data_2, buffer_2, count_2);
  local_memcpy_2(sha_info_data_1, buffer_1, count_1, sha_info_data_2, buffer_2, count_2);
  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
}

void sha_update(const BYTE *buffer, int count)
{
  if ((sha_info_count_lo + (((INT32) count) << 3)) < sha_info_count_lo)
  {
    ++sha_info_count_hi;
  }
  sha_info_count_lo += ((INT32) count) << 3;
  sha_info_count_hi += ((INT32) count) >> 29;
  while (count >= 64)
  {
    local_memcpy(sha_info_data, buffer, 64);
    sha_transform();
    buffer += 64;
    count -= 64;
  }

  local_memcpy(sha_info_data, buffer, count);
}

void sha_final_2()
{
  int count_1;
  int count_2;
  INT32 lo_bit_count_1;
  INT32 lo_bit_count_2;
  INT32 hi_bit_count_1;
  INT32 hi_bit_count_2;
  lo_bit_count_1 = sha_info_count_lo_1;
  lo_bit_count_2 = sha_info_count_lo_2;
  hi_bit_count_1 = sha_info_count_hi_1;
  hi_bit_count_2 = sha_info_count_hi_2;
  count_1 = (int) ((lo_bit_count_1 >> 3) & 0x3f);
  count_2 = (int) ((lo_bit_count_2 >> 3) & 0x3f);
  sha_info_data_1[count_1++] = 0x80;
  sha_info_data_2[count_2++] = 0x80;
  if (count_1 > 56)
  {
    local_memset(sha_info_data_1, 0, 64 - count_1, count_1);
    sha_transform();
    local_memset(sha_info_data_1, 0, 56, 0);
  }
  else
  {
    local_memset(sha_info_data_1, 0, 56 - count_1, count_1);
  }
  if (count_2 > 56)
  {
    local_memset(sha_info_data_2, 0, 64 - count_2, count_2);
    sha_transform();
    local_memset(sha_info_data_2, 0, 56, 0);
  }
  else
  {
    local_memset(sha_info_data_2, 0, 56 - count_2, count_2);
  }
  local_memset_2(sha_info_data_1, 0, 64 - count_1, count_1, sha_info_data_2, 0, 64 - count_2, count_2);
  sha_transform_2();
  sha_info_data_1[14] = hi_bit_count_1;
  sha_info_data_2[14] = hi_bit_count_2;
  sha_info_data_1[15] = lo_bit_count_1;
  sha_info_data_2[15] = lo_bit_count_2;
  sha_transform();
  sha_transform();
  sha_transform_2();
  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
  assert(count_1 == count_2);
  assert(lo_bit_count_1 == lo_bit_count_2);
  assert(hi_bit_count_1 == hi_bit_count_2);
}

void sha_final()
{
  int count;
  INT32 lo_bit_count;
  INT32 hi_bit_count;
  lo_bit_count = sha_info_count_lo;
  hi_bit_count = sha_info_count_hi;
  count = (int) ((lo_bit_count >> 3) & 0x3f);
  sha_info_data[count++] = 0x80;
  if (count > 56)
  {
    local_memset(sha_info_data, 0, 64 - count, count);
    sha_transform();
    local_memset(sha_info_data, 0, 56, 0);
  }
  else
  {
    local_memset(sha_info_data, 0, 56 - count, count);
  }
  sha_info_data[14] = hi_bit_count;
  sha_info_data[15] = lo_bit_count;
  sha_transform();
}

void sha_stream_2()
{
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  const BYTE *p_1;
  const BYTE *p_2;
  sha_init();
  sha_init();
  sha_init_2();
  for (j_1 = 0, j_2 = 0; (j_1 < 2) && (j_2 < 2); j_1++, j_2++)
  {
    i_1 = in_i_1[j_1];
    i_2 = in_i_2[j_2];
    p_1 = &indata_1[j_1][0];
    p_2 = &indata_2[j_2][0];
    sha_update(p_1, i_1);
    sha_update(p_2, i_2);
    sha_update_2(p_1, i_1, p_2, i_2);
  }

  sha_final();
  sha_final();
  sha_final_2();
  for (int i_0 = 0; i_0 < 2; i_0++)
  {
    for (int i_1 = 0; i_1 < 8192; i_1++)
    {
      assert(indata_1[i_0][i_1] == indata_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 2; i_0++)
  {
    assert(in_i_1[i_0] == in_i_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(j_1 == j_2);
  assert((*p_1) == (*p_2));
}

void sha_stream()
{
  int i;
  int j;
  const BYTE *p;
  sha_init();
  for (j = 0; j < 2; j++)
  {
    i = in_i[j];
    p = &indata[j][0];
    sha_update(p, i);
  }

  sha_final();
}

const INT32 outData_1[5] = {0x006a5a37UL, 0x93dc9485UL, 0x2c412112UL, 0x63f7ba43UL, 0xad73f922UL};
const INT32 outData_2[5] = {0x006a5a37UL, 0x93dc9485UL, 0x2c412112UL, 0x63f7ba43UL, 0xad73f922UL};
const INT32 outData[5] = {0x006a5a37UL, 0x93dc9485UL, 0x2c412112UL, 0x63f7ba43UL, 0xad73f922UL};
void main()
{
  for (int i_0 = 0; i_0 < 5; i_0++)
  {
    sha_info_digest_1[i_0] = nd_sha_info_digest();
  }

  for (int i_0 = 0; i_0 < 5; i_0++)
  {
    sha_info_digest_2[i_0] = nd_sha_info_digest();
  }

  int i_1;
  int i_2;
  int main_result_1;
  int main_result_2;
  main_result_1 = 0;
  main_result_2 = 0;
  sha_stream();
  sha_stream();
  sha_stream_2();
  for (i_1 = 0, i_2 = 0; (i_1 < 5) && (i_2 < 5); i_1++, i_2++)
  {
    main_result_1 += sha_info_digest_1[i_1] != outData_1[i_1];
    main_result_2 += sha_info_digest_2[i_2] != outData_2[i_2];
  }

  printf("%d\n", main_result_1);
  printf("%d\n", main_result_2);
  printf_2("%d\n", main_result_1, "%d\n", main_result_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    __CPROVER_assume(sha_info_data_1[i_0] == sha_info_data_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 5; i_0++)
  {
    __CPROVER_assume(sha_info_digest_1[i_0] != sha_info_digest_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 5; i_0++)
  {
    assert(outData_1[i_0] == outData_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(main_result_1 == main_result_2);
}


