typedef void FILE;
typedef unsigned int size_t;
extern FILE *stdin_1;
extern FILE *stdin_2;
extern FILE *stdin;
extern FILE *stdout_1;
extern FILE *stdout_2;
extern FILE *stdout;
extern FILE *stderr_1;
extern FILE *stderr_2;
extern FILE *stderr;
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int puts(const char *str);
int putchar(int c);
int getchar(void);
typedef unsigned int size_t;
void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void exit(int status);
void abort(void);
int abs(int j);
long int labs(long int j);
int rand(void);
void srand(unsigned int seed);
typedef unsigned int size_t;
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strcat(char *dest, const char *src);
void assert(int expression);
void __CPROVER_assume(int expression);
struct State_R000010_370
{
  int id;
  int val;
  short flag;
  int buffer[3];
};
union Packet_R000010_370
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
struct Meta_R000010_370
{
  int status;
  int mask;
};
int g_out_1 = 0;
int g_out_2 = 0;
int g_out = 0;
int g_chk_1 = 0;
int g_chk_2 = 0;
int g_chk = 0;
void helper_R000010_370_0_2(int a_1, int b_1, int c_1, int d_1, int a_2, int b_2, int c_2, int d_2)
{
  int acc_1 = a_1 + 1;
  int acc_2 = a_2 + 1;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 1;
  st_2.id = 1;
  st_1.val = b_1 + 5;
  st_2.val = b_2 + 5;
  st_1.flag = (short) 0;
  st_2.flag = (short) 0;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  if (st_1.val > 10)
  {
    acc_1 += ((st_1.buffer[0] * 2) + 3) & 31;
    if (acc_1 > 20)
    {
      acc_1 -= 7;
    }
    else
    {
      acc_1 += 5;
    }
  }
  else
  {
    acc_1 -= (st_1.buffer[1] + 1) & 15;
  }
  if (st_2.val > 10)
  {
    acc_2 += ((st_2.buffer[0] * 2) + 3) & 31;
    if (acc_2 > 20)
    {
      acc_2 -= 7;
    }
    else
    {
      acc_2 += 5;
    }
  }
  else
  {
    acc_2 -= (st_2.buffer[1] + 1) & 15;
  }
  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_0(int a, int b, int c, int d)
{
  int acc = a + 1;
  struct State_R000010_370 st;
  st.id = 1;
  st.val = b + 5;
  st.flag = (short) 0;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 7;
  if (st.val > 10)
  {
    acc += ((st.buffer[0] * 2) + 3) & 31;
    if (acc > 20)
    {
      acc -= 7;
    }
    else
    {
      acc += 5;
    }
  }
  else
  {
    acc -= (st.buffer[1] + 1) & 15;
  }
  return (acc + st.flag) & 127;
}

void helper_R000010_370_1_2(int a_1, int b_1, int c_1, int d_1, int a_2, int b_2, int c_2, int d_2)
{
  int acc_1 = a_1 + 4;
  int acc_2 = a_2 + 4;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 2;
  st_2.id = 2;
  st_1.val = b_1 + 7;
  st_2.val = b_2 + 7;
  st_1.flag = (short) 1;
  st_2.flag = (short) 1;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    acc_1 += ((k_1 * 3) + st_1.buffer[k_1]) & 15;
    acc_2 += ((k_2 * 3) + st_2.buffer[k_2]) & 15;
    if (acc_1 > 30)
    {
      acc_1 -= 10;
    }
    if (acc_2 > 30)
    {
      acc_2 -= 10;
    }
  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_1(int a, int b, int c, int d)
{
  int acc = a + 4;
  struct State_R000010_370 st;
  st.id = 2;
  st.val = b + 7;
  st.flag = (short) 1;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 8;
  for (int k = 0; k < 2; k++)
  {
    acc += ((k * 3) + st.buffer[k]) & 15;
    if (acc > 30)
    {
      acc -= 10;
    }
  }

  return (acc + st.flag) & 127;
}

void helper_R000010_370_2_2(int a_1, int b_1, int c_1, int d_1, int a_2, int b_2, int c_2, int d_2)
{
  int acc_1 = a_1 + 7;
  int acc_2 = a_2 + 7;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 3;
  st_2.id = 3;
  st_1.val = b_1 + 9;
  st_2.val = b_2 + 9;
  st_1.flag = (short) 2;
  st_2.flag = (short) 2;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  switch (a_1 & 3)
  {
    case 0:
      acc_1 ^= 7;
      break;

    case 1:
      acc_1 += (b_1 & 15) + 3;
      break;

    case 2:
      acc_1 = ((acc_1 * 2) + 1) & 63;
      break;

    default:
      acc_1 -= 5;
      break;

  }

  switch (a_2 & 3)
  {
    case 0:
      acc_2 ^= 7;
      break;

    case 1:
      acc_2 += (b_2 & 15) + 3;
      break;

    case 2:
      acc_2 = ((acc_2 * 2) + 1) & 63;
      break;

    default:
      acc_2 -= 5;
      break;

  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_2(int a, int b, int c, int d)
{
  int acc = a + 7;
  struct State_R000010_370 st;
  st.id = 3;
  st.val = b + 9;
  st.flag = (short) 2;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 9;
  switch (a & 3)
  {
    case 0:
      acc ^= 7;
      break;

    case 1:
      acc += (b & 15) + 3;
      break;

    case 2:
      acc = ((acc * 2) + 1) & 63;
      break;

    default:
      acc -= 5;
      break;

  }

  return (acc + st.flag) & 127;
}

void helper_R000010_370_3_2(int a_1, int b_1, int a_2, int b_2)
{
  int acc_1 = a_1 + 10;
  int acc_2 = a_2 + 10;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 4;
  st_2.id = 4;
  st_1.val = b_1 + 11;
  st_2.val = b_2 + 11;
  st_1.flag = (short) 3;
  st_2.flag = (short) 3;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  union Packet_R000010_370 pkt_1;
  union Packet_R000010_370 pkt_2;
  pkt_1.word = ((a_1 + b_1) + 12) & 255;
  pkt_2.word = ((a_2 + b_2) + 12) & 255;
  acc_1 += (pkt_1.raw[0] ^ pkt_1.raw[1]) & 31;
  acc_2 += (pkt_2.raw[0] ^ pkt_2.raw[1]) & 31;
  if ((acc_1 & 1) != 0)
  {
    acc_1 = (acc_1 << 1) & 127;
  }
  else
  {
    acc_1 = (acc_1 >> 1) + 2;
  }
  if ((acc_2 & 1) != 0)
  {
    acc_2 = (acc_2 << 1) & 127;
  }
  else
  {
    acc_2 = (acc_2 >> 1) + 2;
  }
  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pkt_1.word == pkt_2.word);
  for (int i_raw = 0; i_raw < 4; i_raw++)
  {
    assert(pkt_1.raw[i_raw] == pkt_2.raw[i_raw]);
  }

  for (int i_pairs = 0; i_pairs < 2; i_pairs++)
  {
    assert(pkt_1.pairs[i_pairs] == pkt_2.pairs[i_pairs]);
  }

}

int helper_R000010_370_3(int a, int b)
{
  int acc = a + 10;
  struct State_R000010_370 st;
  st.id = 4;
  st.val = b + 11;
  st.flag = (short) 3;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 10;
  union Packet_R000010_370 pkt;
  pkt.word = ((a + b) + 12) & 255;
  acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;
  if ((acc & 1) != 0)
  {
    acc = (acc << 1) & 127;
  }
  else
  {
    acc = (acc >> 1) + 2;
  }
  return (acc + st.flag) & 127;
}

void helper_R000010_370_4_2(int a_1, int b_1, int a_2, int b_2)
{
  int acc_1 = a_1 + 13;
  int acc_2 = a_2 + 13;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 5;
  st_2.id = 5;
  st_1.val = b_1 + 13;
  st_2.val = b_2 + 13;
  st_1.flag = (short) 4;
  st_2.flag = (short) 4;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cnt_1 = 0;
  int cnt_2 = 0;
  while ((cnt_1 < 2) && (cnt_2 < 2))
  {
    acc_1 += (cnt_1 + 1) * 4;
    acc_2 += (cnt_2 + 1) * 4;
    cnt_1++;
    cnt_2++;
  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cnt_1 == cnt_2);
}

int helper_R000010_370_4(int a, int b)
{
  int acc = a + 13;
  struct State_R000010_370 st;
  st.id = 5;
  st.val = b + 13;
  st.flag = (short) 4;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 11;
  int cnt = 0;
  while (cnt < 2)
  {
    acc += (cnt + 1) * 4;
    cnt++;
  }

  return (acc + st.flag) & 127;
}

void helper_R000010_370_5_2(int a_1, int b_1, int a_2, int b_2)
{
  int acc_1 = a_1 + 16;
  int acc_2 = a_2 + 16;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 6;
  st_2.id = 6;
  st_1.val = b_1 + 15;
  st_2.val = b_2 + 15;
  st_1.flag = (short) 5;
  st_2.flag = (short) 5;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  if (st_1.val > 35)
  {
    acc_1 += ((st_1.buffer[0] * 2) + 3) & 31;
    if (acc_1 > 20)
    {
      acc_1 -= 7;
    }
    else
    {
      acc_1 += 5;
    }
  }
  else
  {
    acc_1 -= (st_1.buffer[1] + 1) & 15;
  }
  if (st_2.val > 35)
  {
    acc_2 += ((st_2.buffer[0] * 2) + 3) & 31;
    if (acc_2 > 20)
    {
      acc_2 -= 7;
    }
    else
    {
      acc_2 += 5;
    }
  }
  else
  {
    acc_2 -= (st_2.buffer[1] + 1) & 15;
  }
  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_5(int a, int b)
{
  int acc = a + 16;
  struct State_R000010_370 st;
  st.id = 6;
  st.val = b + 15;
  st.flag = (short) 5;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 12;
  if (st.val > 35)
  {
    acc += ((st.buffer[0] * 2) + 3) & 31;
    if (acc > 20)
    {
      acc -= 7;
    }
    else
    {
      acc += 5;
    }
  }
  else
  {
    acc -= (st.buffer[1] + 1) & 15;
  }
  return (acc + st.flag) & 127;
}

void helper_R000010_370_6_2(int a_1, int b_1, int c_1, int a_2, int b_2, int c_2)
{
  int acc_1 = a_1 + 19;
  int acc_2 = a_2 + 19;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 7;
  st_2.id = 7;
  st_1.val = b_1 + 17;
  st_2.val = b_2 + 17;
  st_1.flag = (short) 6;
  st_2.flag = (short) 6;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    acc_1 += ((k_1 * 3) + st_1.buffer[k_1]) & 15;
    acc_2 += ((k_2 * 3) + st_2.buffer[k_2]) & 15;
    if (acc_1 > 30)
    {
      acc_1 -= 10;
    }
    if (acc_2 > 30)
    {
      acc_2 -= 10;
    }
  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_6(int a, int b, int c)
{
  int acc = a + 19;
  struct State_R000010_370 st;
  st.id = 7;
  st.val = b + 17;
  st.flag = (short) 6;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 13;
  for (int k = 0; k < 2; k++)
  {
    acc += ((k * 3) + st.buffer[k]) & 15;
    if (acc > 30)
    {
      acc -= 10;
    }
  }

  return (acc + st.flag) & 127;
}

void helper_R000010_370_7_2(int a_1, int b_1, int c_1, int a_2, int b_2, int c_2)
{
  int acc_1 = a_1 + 22;
  int acc_2 = a_2 + 22;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 8;
  st_2.id = 8;
  st_1.val = b_1 + 19;
  st_2.val = b_2 + 19;
  st_1.flag = (short) 7;
  st_2.flag = (short) 7;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  switch (a_1 & 3)
  {
    case 0:
      acc_1 ^= 7;
      break;

    case 1:
      acc_1 += (b_1 & 15) + 3;
      break;

    case 2:
      acc_1 = ((acc_1 * 2) + 1) & 63;
      break;

    default:
      acc_1 -= 5;
      break;

  }

  switch (a_2 & 3)
  {
    case 0:
      acc_2 ^= 7;
      break;

    case 1:
      acc_2 += (b_2 & 15) + 3;
      break;

    case 2:
      acc_2 = ((acc_2 * 2) + 1) & 63;
      break;

    default:
      acc_2 -= 5;
      break;

  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int helper_R000010_370_7(int a, int b, int c)
{
  int acc = a + 22;
  struct State_R000010_370 st;
  st.id = 8;
  st.val = b + 19;
  st.flag = (short) 7;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 14;
  switch (a & 3)
  {
    case 0:
      acc ^= 7;
      break;

    case 1:
      acc += (b & 15) + 3;
      break;

    case 2:
      acc = ((acc * 2) + 1) & 63;
      break;

    default:
      acc -= 5;
      break;

  }

  return (acc + st.flag) & 127;
}

void helper_R000010_370_8_2(int a_1, int b_1, int a_2, int b_2)
{
  int acc_1 = a_1 + 25;
  int acc_2 = a_2 + 25;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 9;
  st_2.id = 9;
  st_1.val = b_1 + 21;
  st_2.val = b_2 + 21;
  st_1.flag = (short) 8;
  st_2.flag = (short) 8;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  union Packet_R000010_370 pkt_1;
  union Packet_R000010_370 pkt_2;
  pkt_1.word = ((a_1 + b_1) + 32) & 255;
  pkt_2.word = ((a_2 + b_2) + 32) & 255;
  acc_1 += (pkt_1.raw[0] ^ pkt_1.raw[1]) & 31;
  acc_2 += (pkt_2.raw[0] ^ pkt_2.raw[1]) & 31;
  if ((acc_1 & 1) != 0)
  {
    acc_1 = (acc_1 << 1) & 127;
  }
  else
  {
    acc_1 = (acc_1 >> 1) + 2;
  }
  if ((acc_2 & 1) != 0)
  {
    acc_2 = (acc_2 << 1) & 127;
  }
  else
  {
    acc_2 = (acc_2 >> 1) + 2;
  }
  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pkt_1.word == pkt_2.word);
  for (int i_raw = 0; i_raw < 4; i_raw++)
  {
    assert(pkt_1.raw[i_raw] == pkt_2.raw[i_raw]);
  }

  for (int i_pairs = 0; i_pairs < 2; i_pairs++)
  {
    assert(pkt_1.pairs[i_pairs] == pkt_2.pairs[i_pairs]);
  }

}

int helper_R000010_370_8(int a, int b)
{
  int acc = a + 25;
  struct State_R000010_370 st;
  st.id = 9;
  st.val = b + 21;
  st.flag = (short) 8;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 15;
  union Packet_R000010_370 pkt;
  pkt.word = ((a + b) + 32) & 255;
  acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;
  if ((acc & 1) != 0)
  {
    acc = (acc << 1) & 127;
  }
  else
  {
    acc = (acc >> 1) + 2;
  }
  return (acc + st.flag) & 127;
}

void helper_R000010_370_9_2(int a_1, int b_1, int c_1, int a_2, int b_2, int c_2)
{
  int acc_1 = a_1 + 28;
  int acc_2 = a_2 + 28;
  struct State_R000010_370 st_1;
  struct State_R000010_370 st_2;
  st_1.id = 10;
  st_2.id = 10;
  st_1.val = b_1 + 23;
  st_2.val = b_2 + 23;
  st_1.flag = (short) 9;
  st_2.flag = (short) 9;
  st_1.buffer[0] = a_1 & 15;
  st_2.buffer[0] = a_2 & 15;
  st_1.buffer[1] = b_1 & 15;
  st_2.buffer[1] = b_2 & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cnt_1 = 0;
  int cnt_2 = 0;
  while ((cnt_1 < 2) && (cnt_2 < 2))
  {
    acc_1 += (cnt_1 + 1) * 4;
    acc_2 += (cnt_2 + 1) * 4;
    cnt_1++;
    cnt_2++;
  }

  assert(acc_1 == acc_2);
  assert(st_1.id == st_2.id);
  assert(st_1.val == st_2.val);
  assert(st_1.flag == st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cnt_1 == cnt_2);
}

int helper_R000010_370_9(int a, int b, int c)
{
  int acc = a + 28;
  struct State_R000010_370 st;
  st.id = 10;
  st.val = b + 23;
  st.flag = (short) 9;
  st.buffer[0] = a & 15;
  st.buffer[1] = b & 15;
  st.buffer[2] = 16;
  int cnt = 0;
  while (cnt < 2)
  {
    acc += (cnt + 1) * 4;
    cnt++;
  }

  return (acc + st.flag) & 127;
}

void main()
{
  int sec_k_0_1;
  int sec_k_0_2;
  int sec_k_1_1;
  int sec_k_1_2;
  int sec_k_2_1;
  int sec_k_2_2;
  int pub_v_0_1;
  int pub_v_0_2;
  int pub_v_1_1;
  int pub_v_1_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int local_arr_1[3];
  int local_arr_2[3];
  struct State_R000010_370 main_st_1;
  struct State_R000010_370 main_st_2;
  union Packet_R000010_370 main_pkt_1;
  union Packet_R000010_370 main_pkt_2;
  main_st_1.id = 1;
  main_st_2.id = 1;
  main_st_1.val = (pub_v_0_1 + 10) & 63;
  main_st_2.val = (pub_v_0_2 + 10) & 63;
  main_st_1.flag = (short) 1;
  main_st_2.flag = (short) 1;
  main_st_1.buffer[0] = (pub_v_0_1 + 1) & 15;
  main_st_2.buffer[0] = (pub_v_0_2 + 1) & 15;
  main_st_1.buffer[1] = (pub_v_0_1 + 2) & 15;
  main_st_2.buffer[1] = (pub_v_0_2 + 2) & 15;
  main_st_1.buffer[2] = (pub_v_0_1 + 3) & 15;
  main_st_2.buffer[2] = (pub_v_0_2 + 3) & 15;
  main_pkt_1.word = (pub_v_0_1 + 42) & 255;
  main_pkt_2.word = (pub_v_0_2 + 42) & 255;
  local_arr_1[0] = (pub_v_0_1 + 5) & 15;
  local_arr_2[0] = (pub_v_0_2 + 5) & 15;
  local_arr_1[1] = (pub_v_0_1 + 7) & 15;
  local_arr_2[1] = (pub_v_0_2 + 7) & 15;
  local_arr_1[2] = (pub_v_0_1 + 9) & 15;
  local_arr_2[2] = (pub_v_0_2 + 9) & 15;
  int h_res_0_1 = helper_R000010_370_0(3, 3, 3, 3);
  int h_res_0_2 = helper_R000010_370_0(3, 3, 3, 3);
  helper_R000010_370_0_2(3, 3, 3, 3, 3, 3, 3, 3);
  out_sink_1 += h_res_0_1;
  out_sink_2 += h_res_0_2;
  chk_sum_1 ^= (h_res_0_1 << 1) & 127;
  chk_sum_2 ^= (h_res_0_2 << 1) & 127;
  int h_res_1_1 = helper_R000010_370_1(4, 5, 6, 7);
  int h_res_1_2 = helper_R000010_370_1(4, 5, 6, 7);
  helper_R000010_370_1_2(4, 5, 6, 7, 4, 5, 6, 7);
  out_sink_1 += h_res_1_1;
  out_sink_2 += h_res_1_2;
  chk_sum_1 ^= (h_res_1_1 << 1) & 127;
  chk_sum_2 ^= (h_res_1_2 << 1) & 127;
  int h_res_2_1 = helper_R000010_370_2(5, 7, 9, 11);
  int h_res_2_2 = helper_R000010_370_2(5, 7, 9, 11);
  helper_R000010_370_2_2(5, 7, 9, 11, 5, 7, 9, 11);
  out_sink_1 += h_res_2_1;
  out_sink_2 += h_res_2_2;
  chk_sum_1 ^= (h_res_2_1 << 1) & 127;
  chk_sum_2 ^= (h_res_2_2 << 1) & 127;
  int h_res_3_1 = helper_R000010_370_3(6, 9);
  int h_res_3_2 = helper_R000010_370_3(6, 9);
  helper_R000010_370_3_2(6, 9, 6, 9);
  out_sink_1 += h_res_3_1;
  out_sink_2 += h_res_3_2;
  chk_sum_1 ^= (h_res_3_1 << 1) & 127;
  chk_sum_2 ^= (h_res_3_2 << 1) & 127;
  int h_res_4_1 = helper_R000010_370_4(7, 11);
  int h_res_4_2 = helper_R000010_370_4(7, 11);
  helper_R000010_370_4_2(7, 11, 7, 11);
  out_sink_1 += h_res_4_1;
  out_sink_2 += h_res_4_2;
  chk_sum_1 ^= (h_res_4_1 << 1) & 127;
  chk_sum_2 ^= (h_res_4_2 << 1) & 127;
  int h_res_5_1 = helper_R000010_370_5(8, 13);
  int h_res_5_2 = helper_R000010_370_5(8, 13);
  helper_R000010_370_5_2(8, 13, 8, 13);
  out_sink_1 += h_res_5_1;
  out_sink_2 += h_res_5_2;
  chk_sum_1 ^= (h_res_5_1 << 1) & 127;
  chk_sum_2 ^= (h_res_5_2 << 1) & 127;
  int h_res_6_1 = helper_R000010_370_6(9, 15, 21);
  int h_res_6_2 = helper_R000010_370_6(9, 15, 21);
  helper_R000010_370_6_2(9, 15, 21, 9, 15, 21);
  out_sink_1 += h_res_6_1;
  out_sink_2 += h_res_6_2;
  chk_sum_1 ^= (h_res_6_1 << 1) & 127;
  chk_sum_2 ^= (h_res_6_2 << 1) & 127;
  int h_res_7_1 = helper_R000010_370_7(10, 17, 24);
  int h_res_7_2 = helper_R000010_370_7(10, 17, 24);
  helper_R000010_370_7_2(10, 17, 24, 10, 17, 24);
  out_sink_1 += h_res_7_1;
  out_sink_2 += h_res_7_2;
  chk_sum_1 ^= (h_res_7_1 << 1) & 127;
  chk_sum_2 ^= (h_res_7_2 << 1) & 127;
  int h_res_8_1 = helper_R000010_370_8(11, 19);
  int h_res_8_2 = helper_R000010_370_8(11, 19);
  helper_R000010_370_8_2(11, 19, 11, 19);
  out_sink_1 += h_res_8_1;
  out_sink_2 += h_res_8_2;
  chk_sum_1 ^= (h_res_8_1 << 1) & 127;
  chk_sum_2 ^= (h_res_8_2 << 1) & 127;
  int h_res_9_1 = helper_R000010_370_9(12, 21, 30);
  int h_res_9_2 = helper_R000010_370_9(12, 21, 30);
  helper_R000010_370_9_2(12, 21, 30, 12, 21, 30);
  out_sink_1 += h_res_9_1;
  out_sink_2 += h_res_9_2;
  chk_sum_1 ^= (h_res_9_1 << 1) & 127;
  chk_sum_2 ^= (h_res_9_2 << 1) & 127;
  int blk_0_1 = (local_arr_1[0] + 3) & 31;
  int blk_0_2 = (local_arr_2[0] + 3) & 31;
  if (blk_0_1 > 15)
  {
    local_arr_1[0] = (local_arr_1[0] + 1) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[0] = (local_arr_1[0] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_0_2 > 15)
  {
    local_arr_2[0] = (local_arr_2[0] + 1) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[0] = (local_arr_2[0] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_0_1;
  chk_sum_2 ^= blk_0_2;
  int blk_1_1 = (local_arr_1[1] + 8) & 31;
  int blk_1_2 = (local_arr_2[1] + 8) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_1_1 = (blk_1_1 + (k_1 * 3)) & 31;
    blk_1_2 = (blk_1_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_1_2) & 127;
  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_1_1;
  chk_sum_2 ^= blk_1_2;
  int blk_2_1 = (local_arr_1[2] + 13) & 31;
  int blk_2_2 = (local_arr_2[2] + 13) & 31;
  switch (blk_2_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_2_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_2_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_2_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_2_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_2_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_2_1;
  chk_sum_2 ^= blk_2_2;
  int blk_3_1 = (local_arr_1[0] + 18) & 31;
  int blk_3_2 = (local_arr_2[0] + 18) & 31;
  main_st_1.val = (main_st_1.val + blk_3_1) & 63;
  main_st_2.val = (main_st_2.val + blk_3_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_3_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_3_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_3_1;
  chk_sum_2 ^= blk_3_2;
  int blk_4_1 = (local_arr_1[1] + 23) & 31;
  int blk_4_2 = (local_arr_2[1] + 23) & 31;
  if (blk_4_1 > 15)
  {
    local_arr_1[1] = (local_arr_1[1] + 5) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[1] = (local_arr_1[1] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_4_2 > 15)
  {
    local_arr_2[1] = (local_arr_2[1] + 5) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[1] = (local_arr_2[1] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_4_1;
  chk_sum_2 ^= blk_4_2;
  int blk_5_1 = (local_arr_1[2] + 28) & 31;
  int blk_5_2 = (local_arr_2[2] + 28) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_5_1 = (blk_5_1 + (k_1 * 3)) & 31;
    blk_5_2 = (blk_5_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_5_2) & 127;
  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_5_1;
  chk_sum_2 ^= blk_5_2;
  int blk_6_1 = (local_arr_1[0] + 33) & 31;
  int blk_6_2 = (local_arr_2[0] + 33) & 31;
  switch (blk_6_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_6_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_6_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_6_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_6_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_6_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_6_1;
  chk_sum_2 ^= blk_6_2;
  int blk_7_1 = (local_arr_1[1] + 38) & 31;
  int blk_7_2 = (local_arr_2[1] + 38) & 31;
  main_st_1.val = (main_st_1.val + blk_7_1) & 63;
  main_st_2.val = (main_st_2.val + blk_7_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_7_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_7_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_7_1;
  chk_sum_2 ^= blk_7_2;
  int blk_8_1 = (local_arr_1[2] + 43) & 31;
  int blk_8_2 = (local_arr_2[2] + 43) & 31;
  if (blk_8_1 > 15)
  {
    local_arr_1[2] = (local_arr_1[2] + 2) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[2] = (local_arr_1[2] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_8_2 > 15)
  {
    local_arr_2[2] = (local_arr_2[2] + 2) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[2] = (local_arr_2[2] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_8_1;
  chk_sum_2 ^= blk_8_2;
  int blk_9_1 = (local_arr_1[0] + 48) & 31;
  int blk_9_2 = (local_arr_2[0] + 48) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_9_1 = (blk_9_1 + (k_1 * 3)) & 31;
    blk_9_2 = (blk_9_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_9_2) & 127;
  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_9_1;
  chk_sum_2 ^= blk_9_2;
  int blk_10_1 = (local_arr_1[1] + 53) & 31;
  int blk_10_2 = (local_arr_2[1] + 53) & 31;
  switch (blk_10_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_10_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_10_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_10_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_10_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_10_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_10_1;
  chk_sum_2 ^= blk_10_2;
  int blk_11_1 = (local_arr_1[2] + 58) & 31;
  int blk_11_2 = (local_arr_2[2] + 58) & 31;
  main_st_1.val = (main_st_1.val + blk_11_1) & 63;
  main_st_2.val = (main_st_2.val + blk_11_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_11_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_11_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_11_1;
  chk_sum_2 ^= blk_11_2;
  int blk_12_1 = (local_arr_1[0] + 63) & 31;
  int blk_12_2 = (local_arr_2[0] + 63) & 31;
  if (blk_12_1 > 15)
  {
    local_arr_1[0] = (local_arr_1[0] + 6) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[0] = (local_arr_1[0] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_12_2 > 15)
  {
    local_arr_2[0] = (local_arr_2[0] + 6) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[0] = (local_arr_2[0] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_12_1;
  chk_sum_2 ^= blk_12_2;
  int blk_13_1 = (local_arr_1[1] + 68) & 31;
  int blk_13_2 = (local_arr_2[1] + 68) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_13_1 = (blk_13_1 + (k_1 * 3)) & 31;
    blk_13_2 = (blk_13_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_13_2) & 127;
  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_13_1;
  chk_sum_2 ^= blk_13_2;
  int blk_14_1 = (local_arr_1[2] + 73) & 31;
  int blk_14_2 = (local_arr_2[2] + 73) & 31;
  switch (blk_14_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_14_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_14_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_14_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_14_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_14_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_14_1;
  chk_sum_2 ^= blk_14_2;
  int blk_15_1 = (local_arr_1[0] + 78) & 31;
  int blk_15_2 = (local_arr_2[0] + 78) & 31;
  main_st_1.val = (main_st_1.val + blk_15_1) & 63;
  main_st_2.val = (main_st_2.val + blk_15_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_15_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_15_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_15_1;
  chk_sum_2 ^= blk_15_2;
  int blk_16_1 = (local_arr_1[1] + 83) & 31;
  int blk_16_2 = (local_arr_2[1] + 83) & 31;
  if (blk_16_1 > 15)
  {
    local_arr_1[1] = (local_arr_1[1] + 3) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[1] = (local_arr_1[1] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_16_2 > 15)
  {
    local_arr_2[1] = (local_arr_2[1] + 3) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[1] = (local_arr_2[1] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_16_1;
  chk_sum_2 ^= blk_16_2;
  int blk_17_1 = (local_arr_1[2] + 88) & 31;
  int blk_17_2 = (local_arr_2[2] + 88) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_17_1 = (blk_17_1 + (k_1 * 3)) & 31;
    blk_17_2 = (blk_17_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_17_2) & 127;
  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_17_1;
  chk_sum_2 ^= blk_17_2;
  int blk_18_1 = (local_arr_1[0] + 93) & 31;
  int blk_18_2 = (local_arr_2[0] + 93) & 31;
  switch (blk_18_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_18_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_18_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_18_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_18_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_18_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_18_1;
  chk_sum_2 ^= blk_18_2;
  int blk_19_1 = (local_arr_1[1] + 98) & 31;
  int blk_19_2 = (local_arr_2[1] + 98) & 31;
  main_st_1.val = (main_st_1.val + blk_19_1) & 63;
  main_st_2.val = (main_st_2.val + blk_19_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_19_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_19_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_19_1;
  chk_sum_2 ^= blk_19_2;
  int blk_20_1 = (local_arr_1[2] + 103) & 31;
  int blk_20_2 = (local_arr_2[2] + 103) & 31;
  if (blk_20_1 > 15)
  {
    local_arr_1[2] = (local_arr_1[2] + 7) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[2] = (local_arr_1[2] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_20_2 > 15)
  {
    local_arr_2[2] = (local_arr_2[2] + 7) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[2] = (local_arr_2[2] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_20_1;
  chk_sum_2 ^= blk_20_2;
  int blk_21_1 = (local_arr_1[0] + 108) & 31;
  int blk_21_2 = (local_arr_2[0] + 108) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_21_1 = (blk_21_1 + (k_1 * 3)) & 31;
    blk_21_2 = (blk_21_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_21_2) & 127;
  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_21_1;
  chk_sum_2 ^= blk_21_2;
  int blk_22_1 = (local_arr_1[1] + 113) & 31;
  int blk_22_2 = (local_arr_2[1] + 113) & 31;
  switch (blk_22_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_22_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_22_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_22_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_22_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_22_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_22_1;
  chk_sum_2 ^= blk_22_2;
  int blk_23_1 = (local_arr_1[2] + 118) & 31;
  int blk_23_2 = (local_arr_2[2] + 118) & 31;
  main_st_1.val = (main_st_1.val + blk_23_1) & 63;
  main_st_2.val = (main_st_2.val + blk_23_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_23_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_23_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_23_1;
  chk_sum_2 ^= blk_23_2;
  int blk_24_1 = (local_arr_1[0] + 123) & 31;
  int blk_24_2 = (local_arr_2[0] + 123) & 31;
  if (blk_24_1 > 15)
  {
    local_arr_1[0] = (local_arr_1[0] + 4) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[0] = (local_arr_1[0] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_24_2 > 15)
  {
    local_arr_2[0] = (local_arr_2[0] + 4) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[0] = (local_arr_2[0] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_24_1;
  chk_sum_2 ^= blk_24_2;
  int blk_25_1 = (local_arr_1[1] + 128) & 31;
  int blk_25_2 = (local_arr_2[1] + 128) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_25_1 = (blk_25_1 + (k_1 * 3)) & 31;
    blk_25_2 = (blk_25_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_25_2) & 127;
  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_25_1;
  chk_sum_2 ^= blk_25_2;
  int blk_26_1 = (local_arr_1[2] + 133) & 31;
  int blk_26_2 = (local_arr_2[2] + 133) & 31;
  switch (blk_26_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_26_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_26_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_26_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_26_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_26_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_26_1;
  chk_sum_2 ^= blk_26_2;
  int blk_27_1 = (local_arr_1[0] + 138) & 31;
  int blk_27_2 = (local_arr_2[0] + 138) & 31;
  main_st_1.val = (main_st_1.val + blk_27_1) & 63;
  main_st_2.val = (main_st_2.val + blk_27_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_27_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_27_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_27_1;
  chk_sum_2 ^= blk_27_2;
  int blk_28_1 = (local_arr_1[1] + 143) & 31;
  int blk_28_2 = (local_arr_2[1] + 143) & 31;
  if (blk_28_1 > 15)
  {
    local_arr_1[1] = (local_arr_1[1] + 1) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[1] = (local_arr_1[1] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_28_2 > 15)
  {
    local_arr_2[1] = (local_arr_2[1] + 1) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[1] = (local_arr_2[1] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_28_1;
  chk_sum_2 ^= blk_28_2;
  int blk_29_1 = (local_arr_1[2] + 148) & 31;
  int blk_29_2 = (local_arr_2[2] + 148) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_29_1 = (blk_29_1 + (k_1 * 3)) & 31;
    blk_29_2 = (blk_29_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_29_2) & 127;
  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_29_1;
  chk_sum_2 ^= blk_29_2;
  int blk_30_1 = (local_arr_1[0] + 153) & 31;
  int blk_30_2 = (local_arr_2[0] + 153) & 31;
  switch (blk_30_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_30_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_30_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_30_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_30_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_30_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_30_1;
  chk_sum_2 ^= blk_30_2;
  int blk_31_1 = (local_arr_1[1] + 158) & 31;
  int blk_31_2 = (local_arr_2[1] + 158) & 31;
  main_st_1.val = (main_st_1.val + blk_31_1) & 63;
  main_st_2.val = (main_st_2.val + blk_31_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_31_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_31_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_31_1;
  chk_sum_2 ^= blk_31_2;
  int blk_32_1 = (local_arr_1[2] + 163) & 31;
  int blk_32_2 = (local_arr_2[2] + 163) & 31;
  if (blk_32_1 > 15)
  {
    local_arr_1[2] = (local_arr_1[2] + 5) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[2] = (local_arr_1[2] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_32_2 > 15)
  {
    local_arr_2[2] = (local_arr_2[2] + 5) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[2] = (local_arr_2[2] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_32_1;
  chk_sum_2 ^= blk_32_2;
  int blk_33_1 = (local_arr_1[0] + 168) & 31;
  int blk_33_2 = (local_arr_2[0] + 168) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_33_1 = (blk_33_1 + (k_1 * 3)) & 31;
    blk_33_2 = (blk_33_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_33_2) & 127;
  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_33_1;
  chk_sum_2 ^= blk_33_2;
  int blk_34_1 = (local_arr_1[1] + 173) & 31;
  int blk_34_2 = (local_arr_2[1] + 173) & 31;
  switch (blk_34_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_34_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_34_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_34_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_34_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_34_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_34_1;
  chk_sum_2 ^= blk_34_2;
  int blk_35_1 = (local_arr_1[2] + 178) & 31;
  int blk_35_2 = (local_arr_2[2] + 178) & 31;
  main_st_1.val = (main_st_1.val + blk_35_1) & 63;
  main_st_2.val = (main_st_2.val + blk_35_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_35_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_35_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_35_1;
  chk_sum_2 ^= blk_35_2;
  int blk_36_1 = (local_arr_1[0] + 183) & 31;
  int blk_36_2 = (local_arr_2[0] + 183) & 31;
  if (blk_36_1 > 15)
  {
    local_arr_1[0] = (local_arr_1[0] + 2) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[0] = (local_arr_1[0] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_36_2 > 15)
  {
    local_arr_2[0] = (local_arr_2[0] + 2) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[0] = (local_arr_2[0] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_36_1;
  chk_sum_2 ^= blk_36_2;
  int blk_37_1 = (local_arr_1[1] + 188) & 31;
  int blk_37_2 = (local_arr_2[1] + 188) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_37_1 = (blk_37_1 + (k_1 * 3)) & 31;
    blk_37_2 = (blk_37_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_37_2) & 127;
  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_37_1;
  chk_sum_2 ^= blk_37_2;
  int blk_38_1 = (local_arr_1[2] + 193) & 31;
  int blk_38_2 = (local_arr_2[2] + 193) & 31;
  switch (blk_38_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_38_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_38_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_38_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_38_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_38_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_38_1;
  chk_sum_2 ^= blk_38_2;
  int blk_39_1 = (local_arr_1[0] + 198) & 31;
  int blk_39_2 = (local_arr_2[0] + 198) & 31;
  main_st_1.val = (main_st_1.val + blk_39_1) & 63;
  main_st_2.val = (main_st_2.val + blk_39_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_39_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_39_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_39_1;
  chk_sum_2 ^= blk_39_2;
  int blk_40_1 = (local_arr_1[1] + 203) & 31;
  int blk_40_2 = (local_arr_2[1] + 203) & 31;
  if (blk_40_1 > 15)
  {
    local_arr_1[1] = (local_arr_1[1] + 6) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[1] = (local_arr_1[1] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_40_2 > 15)
  {
    local_arr_2[1] = (local_arr_2[1] + 6) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[1] = (local_arr_2[1] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_40_1;
  chk_sum_2 ^= blk_40_2;
  int blk_41_1 = (local_arr_1[2] + 208) & 31;
  int blk_41_2 = (local_arr_2[2] + 208) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_41_1 = (blk_41_1 + (k_1 * 3)) & 31;
    blk_41_2 = (blk_41_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_41_2) & 127;
  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_41_1;
  chk_sum_2 ^= blk_41_2;
  int blk_42_1 = (local_arr_1[0] + 213) & 31;
  int blk_42_2 = (local_arr_2[0] + 213) & 31;
  switch (blk_42_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_42_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_42_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_42_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_42_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_42_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_42_1;
  chk_sum_2 ^= blk_42_2;
  int blk_43_1 = (local_arr_1[1] + 218) & 31;
  int blk_43_2 = (local_arr_2[1] + 218) & 31;
  main_st_1.val = (main_st_1.val + blk_43_1) & 63;
  main_st_2.val = (main_st_2.val + blk_43_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_43_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_43_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_43_1;
  chk_sum_2 ^= blk_43_2;
  int blk_44_1 = (local_arr_1[2] + 223) & 31;
  int blk_44_2 = (local_arr_2[2] + 223) & 31;
  if (blk_44_1 > 15)
  {
    local_arr_1[2] = (local_arr_1[2] + 3) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[2] = (local_arr_1[2] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_44_2 > 15)
  {
    local_arr_2[2] = (local_arr_2[2] + 3) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[2] = (local_arr_2[2] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_44_1;
  chk_sum_2 ^= blk_44_2;
  int blk_45_1 = (local_arr_1[0] + 228) & 31;
  int blk_45_2 = (local_arr_2[0] + 228) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_45_1 = (blk_45_1 + (k_1 * 3)) & 31;
    blk_45_2 = (blk_45_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_45_2) & 127;
  }

  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_45_1;
  chk_sum_2 ^= blk_45_2;
  int blk_46_1 = (local_arr_1[1] + 233) & 31;
  int blk_46_2 = (local_arr_2[1] + 233) & 31;
  switch (blk_46_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_46_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_46_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_46_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_46_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_46_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_46_1;
  chk_sum_2 ^= blk_46_2;
  int blk_47_1 = (local_arr_1[2] + 238) & 31;
  int blk_47_2 = (local_arr_2[2] + 238) & 31;
  main_st_1.val = (main_st_1.val + blk_47_1) & 63;
  main_st_2.val = (main_st_2.val + blk_47_2) & 63;
  main_pkt_1.raw[3] = (unsigned char) (blk_47_1 & 255);
  main_pkt_2.raw[3] = (unsigned char) (blk_47_2 & 255);
  out_sink_1 += (main_st_1.val ^ main_pkt_1.raw[3]) & 15;
  out_sink_2 += (main_st_2.val ^ main_pkt_2.raw[3]) & 15;
  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_47_1;
  chk_sum_2 ^= blk_47_2;
  int blk_48_1 = (local_arr_1[0] + 243) & 31;
  int blk_48_2 = (local_arr_2[0] + 243) & 31;
  if (blk_48_1 > 15)
  {
    local_arr_1[0] = (local_arr_1[0] + 7) & 15;
    out_sink_1 += 1;
  }
  else
  {
    local_arr_1[0] = (local_arr_1[0] - 1) & 15;
    out_sink_1 -= 1;
  }
  if (blk_48_2 > 15)
  {
    local_arr_2[0] = (local_arr_2[0] + 7) & 15;
    out_sink_2 += 1;
  }
  else
  {
    local_arr_2[0] = (local_arr_2[0] - 1) & 15;
    out_sink_2 -= 1;
  }
  out_sink_1 += local_arr_1[0];
  out_sink_2 += local_arr_2[0];
  chk_sum_1 ^= blk_48_1;
  chk_sum_2 ^= blk_48_2;
  int blk_49_1 = (local_arr_1[1] + 248) & 31;
  int blk_49_2 = (local_arr_2[1] + 248) & 31;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    blk_49_1 = (blk_49_1 + (k_1 * 3)) & 31;
    blk_49_2 = (blk_49_2 + (k_2 * 3)) & 31;
    chk_sum_1 = (chk_sum_1 + blk_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + blk_49_2) & 127;
  }

  out_sink_1 += local_arr_1[1];
  out_sink_2 += local_arr_2[1];
  chk_sum_1 ^= blk_49_1;
  chk_sum_2 ^= blk_49_2;
  int blk_50_1 = (local_arr_1[2] + 253) & 31;
  int blk_50_2 = (local_arr_2[2] + 253) & 31;
  switch (blk_50_1 & 3)
  {
    case 0:
      out_sink_1 += (blk_50_1 ^ 3) & 15;
      break;

    case 1:
      out_sink_1 -= (blk_50_1 + 2) & 15;
      break;

    default:
      out_sink_1 ^= 5;
      break;

  }

  switch (blk_50_2 & 3)
  {
    case 0:
      out_sink_2 += (blk_50_2 ^ 3) & 15;
      break;

    case 1:
      out_sink_2 -= (blk_50_2 + 2) & 15;
      break;

    default:
      out_sink_2 ^= 5;
      break;

  }

  out_sink_1 += local_arr_1[2];
  out_sink_2 += local_arr_2[2];
  chk_sum_1 ^= blk_50_1;
  chk_sum_2 ^= blk_50_2;
  int mix_temp_1 = (sec_k_0_1 ^ 0x2A) & 63;
  int mix_temp_2 = (sec_k_0_2 ^ 0x2A) & 63;
  if (mix_temp_1 > 20)
  {
    out_sink_1 += ((mix_temp_1 * 2) + pub_v_0_1) & 127;
  }
  else
  {
    out_sink_1 -= (mix_temp_1 + 5) & 31;
  }
  if (mix_temp_2 > 20)
  {
    out_sink_2 += ((mix_temp_2 * 2) + pub_v_0_2) & 127;
  }
  else
  {
    out_sink_2 -= (mix_temp_2 + 5) & 31;
  }
  out_sink_1 ^= sec_k_0_1 & 7;
  out_sink_2 ^= sec_k_0_2 & 7;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_v_0_1 == pub_v_0_2);
  __CPROVER_assume(sec_k_2_1 != sec_k_2_2);
  __CPROVER_assume(pub_v_1_1 == pub_v_1_2);
  __CPROVER_assume(sec_k_1_1 != sec_k_1_2);
  __CPROVER_assume(sec_k_0_1 != sec_k_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(main_st_1.id == main_st_2.id);
  assert(main_st_1.val == main_st_2.val);
  assert(main_st_1.flag == main_st_2.flag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(main_st_1.buffer[i_buffer] == main_st_2.buffer[i_buffer]);
  }

  assert(main_pkt_1.word == main_pkt_2.word);
  for (int i_raw = 0; i_raw < 4; i_raw++)
  {
    assert(main_pkt_1.raw[i_raw] == main_pkt_2.raw[i_raw]);
  }

  for (int i_pairs = 0; i_pairs < 2; i_pairs++)
  {
    assert(main_pkt_1.pairs[i_pairs] == main_pkt_2.pairs[i_pairs]);
  }

  assert(h_res_0_1 == h_res_0_2);
  assert(h_res_1_1 == h_res_1_2);
  assert(h_res_2_1 == h_res_2_2);
  assert(h_res_3_1 == h_res_3_2);
  assert(h_res_4_1 == h_res_4_2);
  assert(h_res_5_1 == h_res_5_2);
  assert(h_res_6_1 == h_res_6_2);
  assert(h_res_7_1 == h_res_7_2);
  assert(h_res_8_1 == h_res_8_2);
  assert(h_res_9_1 == h_res_9_2);
  assert(blk_0_1 == blk_0_2);
  assert(blk_1_1 == blk_1_2);
  assert(blk_2_1 == blk_2_2);
  assert(blk_3_1 == blk_3_2);
  assert(blk_4_1 == blk_4_2);
  assert(blk_5_1 == blk_5_2);
  assert(blk_6_1 == blk_6_2);
  assert(blk_7_1 == blk_7_2);
  assert(blk_8_1 == blk_8_2);
  assert(blk_9_1 == blk_9_2);
  assert(blk_10_1 == blk_10_2);
  assert(blk_11_1 == blk_11_2);
  assert(blk_12_1 == blk_12_2);
  assert(blk_13_1 == blk_13_2);
  assert(blk_14_1 == blk_14_2);
  assert(blk_15_1 == blk_15_2);
  assert(blk_16_1 == blk_16_2);
  assert(blk_17_1 == blk_17_2);
  assert(blk_18_1 == blk_18_2);
  assert(blk_19_1 == blk_19_2);
  assert(blk_20_1 == blk_20_2);
  assert(blk_21_1 == blk_21_2);
  assert(blk_22_1 == blk_22_2);
  assert(blk_23_1 == blk_23_2);
  assert(blk_24_1 == blk_24_2);
  assert(blk_25_1 == blk_25_2);
  assert(blk_26_1 == blk_26_2);
  assert(blk_27_1 == blk_27_2);
  assert(blk_28_1 == blk_28_2);
  assert(blk_29_1 == blk_29_2);
  assert(blk_30_1 == blk_30_2);
  assert(blk_31_1 == blk_31_2);
  assert(blk_32_1 == blk_32_2);
  assert(blk_33_1 == blk_33_2);
  assert(blk_34_1 == blk_34_2);
  assert(blk_35_1 == blk_35_2);
  assert(blk_36_1 == blk_36_2);
  assert(blk_37_1 == blk_37_2);
  assert(blk_38_1 == blk_38_2);
  assert(blk_39_1 == blk_39_2);
  assert(blk_40_1 == blk_40_2);
  assert(blk_41_1 == blk_41_2);
  assert(blk_42_1 == blk_42_2);
  assert(blk_43_1 == blk_43_2);
  assert(blk_44_1 == blk_44_2);
  assert(blk_45_1 == blk_45_2);
  assert(blk_46_1 == blk_46_2);
  assert(blk_47_1 == blk_47_2);
  assert(blk_48_1 == blk_48_2);
  assert(blk_49_1 == blk_49_2);
  assert(blk_50_1 == blk_50_2);
  assert(mix_temp_1 == mix_temp_2);
}


