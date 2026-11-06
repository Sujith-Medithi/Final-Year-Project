#include <assert.h>
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
struct StreamBuffer_R000037_3713_0
{
  int checksum;
  unsigned char capacity;
  int tail;
  int buffer[3];
};
struct Transaction_R000037_3713_1
{
  short fee;
  unsigned char rate;
  int balance;
  int buffer[3];
};
struct CipherContext_R000037_3713_2
{
  unsigned char tag;
  int counter;
  int flags;
  int buffer[3];
};
struct EventLog_R000037_3713_3
{
  int code;
  unsigned char severity;
  unsigned char seq;
  int signature;
  unsigned char facility;
  int buffer[3];
};
union ColorPixel_R000037_3713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
int g_out_1 = 0;
int g_out_2 = 0;
int g_out = 0;
int g_chk_1 = 0;
int g_chk_2 = 0;
int g_chk = 0;
int g_telemetry_1 = 0;
int g_telemetry_2 = 0;
int g_telemetry = 0;
void fn_R000037_3713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_69_1 = local_arr_1[aux_1 % 3];
  int mask_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_69_2 * 2)) & 127;
  int margin_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_37_1) & 63;
  aux_2 = (aux_2 + margin_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_69_1 == mask_69_2);
  assert(margin_37_1 == margin_37_2);
}

int fn_R000037_3713_0(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int mask_69 = local_arr[aux % 3];
  acc = (acc + (mask_69 * 2)) & 127;
  int margin_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_37) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int phase_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_24_1) & 63;
  aux_2 = (aux_2 + phase_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_36_1)
  {
    case 0:
      acc_1 = (acc_1 + 2) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (weight_36_2)
  {
    case 0:
      acc_2 = (acc_2 + 2) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_24_1 == phase_24_2);
  assert(weight_36_1 == weight_36_2);
}

int fn_R000037_3713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_24) & 63;
  acc ^= aux;
  int weight_36 = (aux + st.buffer[1]) & 3;
  switch (weight_36)
  {
    case 0:
      acc = (acc + 2) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int checksum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_38_1 > 46)
  {
    acc_1 = ((acc_1 + (checksum_38_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_38_2 > 46)
  {
    acc_2 = ((acc_2 + (checksum_38_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_81_1) & 63;
  aux_2 = (aux_2 + cursor_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_38_1 == checksum_38_2);
  assert(cursor_81_1 == cursor_81_2);
}

int fn_R000037_3713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int checksum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_38 > 46)
  {
    acc = ((acc + (checksum_38 * 2)) + 5) & 127;
    aux ^= checksum_38 & 15;
  }
  else
  {
    acc = ((acc - checksum_38) + 11) & 127;
    aux += 3;
  }
  int cursor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st_1 = {0};
  struct EventLog_R000037_3713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_94_1 = local_arr_1[aux_1 % 3];
  int phase_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_28_1 == accumulator_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_94_1 == phase_94_2);
}

int fn_R000037_3713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_94 = local_arr[aux % 3];
  acc = (acc + (phase_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st_1 = {0};
  struct EventLog_R000037_3713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int phase_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_50_1)
  {
    case 0:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (phase_50_2)
  {
    case 0:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_28_1 = local_arr_1[aux_1 % 3];
  int tally_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_28_2 * 2)) & 127;
  int cursor_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_32_1 > 26)
  {
    acc_1 = ((acc_1 + (cursor_32_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_32_2 > 26)
  {
    acc_2 = ((acc_2 + (cursor_32_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_50_1 == phase_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_28_1 == tally_28_2);
  assert(cursor_32_1 == cursor_32_2);
}

int fn_R000037_3713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int phase_50 = (aux + st.buffer[1]) & 3;
  switch (phase_50)
  {
    case 0:
      acc = (acc + 9) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_28 = local_arr[aux % 3];
  acc = (acc + (tally_28 * 2)) & 127;
  int cursor_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_32 > 26)
  {
    acc = ((acc + (cursor_32 * 2)) + 5) & 127;
    aux ^= cursor_32 & 15;
  }
  else
  {
    acc = ((acc - cursor_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000037_3713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_11_1 > 35)
  {
    acc_1 = ((acc_1 + (delta_11_1 * 2)) + 5) & 127;
    aux_1 ^= delta_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_11_2 > 35)
  {
    acc_2 = ((acc_2 + (delta_11_2 * 2)) + 5) & 127;
    aux_2 ^= delta_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_40_1) & 63;
  aux_2 = (aux_2 + weight_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_11_1 == delta_11_2);
  assert(weight_40_1 == weight_40_2);
}

int fn_R000037_3713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_11 > 35)
  {
    acc = ((acc + (delta_11 * 2)) + 5) & 127;
    aux ^= delta_11 & 15;
  }
  else
  {
    acc = ((acc - delta_11) + 11) & 127;
    aux += 3;
  }
  int weight_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st_1 = {0};
  struct EventLog_R000037_3713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_90_1 = local_arr_1[aux_1 % 3];
  int parity_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_90_2 * 2)) & 127;
  int threshold_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_30_1) & 63;
  aux_2 = (aux_2 + threshold_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_90_1 == parity_90_2);
  assert(threshold_30_1 == threshold_30_2);
}

int fn_R000037_3713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int parity_90 = local_arr[aux % 3];
  acc = (acc + (parity_90 * 2)) & 127;
  int threshold_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_20_1 = local_arr_1[aux_1 % 3];
  int damping_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_20_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_92_1) & 63;
  aux_2 = (aux_2 + window_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_20_1 == damping_20_2);
  assert(window_92_1 == window_92_2);
}

int fn_R000037_3713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int damping_20 = local_arr[aux % 3];
  acc = (acc + (damping_20 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_91_1 > 40)
  {
    acc_1 = ((acc_1 + (checksum_91_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_91_2 > 40)
  {
    acc_2 = ((acc_2 + (checksum_91_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_18_1) & 63;
  aux_2 = (aux_2 + residue_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_77_1 = local_arr_1[aux_1 % 3];
  int offset_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_91_1 == checksum_91_2);
  assert(residue_18_1 == residue_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_77_1 == offset_77_2);
}

int fn_R000037_3713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_91 > 40)
  {
    acc = ((acc + (checksum_91 * 2)) + 5) & 127;
    aux ^= checksum_91 & 15;
  }
  else
  {
    acc = ((acc - checksum_91) + 11) & 127;
    aux += 3;
  }
  int residue_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_77 = local_arr[aux % 3];
  acc = (acc + (offset_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_59_1 > 49)
  {
    acc_1 = ((acc_1 + (window_59_1 * 2)) + 5) & 127;
    aux_1 ^= window_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_59_2 > 49)
  {
    acc_2 = ((acc_2 + (window_59_2 * 2)) + 5) & 127;
    aux_2 ^= window_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_35_1 = local_arr_1[aux_1 % 3];
  int quotient_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_35_2 * 2)) & 127;
  int segment_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_35_1)
  {
    case 0:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (segment_35_2)
  {
    case 0:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int tally_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_61_1) & 63;
  aux_2 = (aux_2 + tally_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_59_1 == window_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_35_1 == quotient_35_2);
  assert(segment_35_1 == segment_35_2);
  assert(tally_61_1 == tally_61_2);
}

int fn_R000037_3713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_59 > 49)
  {
    acc = ((acc + (window_59 * 2)) + 5) & 127;
    aux ^= window_59 & 15;
  }
  else
  {
    acc = ((acc - window_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_35 = local_arr[aux % 3];
  acc = (acc + (quotient_35 * 2)) & 127;
  int segment_35 = (aux + st.buffer[1]) & 3;
  switch (segment_35)
  {
    case 0:
      acc = (acc + 9) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int tally_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st_1 = {0};
  struct EventLog_R000037_3713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_65_1) & 63;
  aux_2 = (aux_2 + residue_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_65_1 == residue_65_2);
}

int fn_R000037_3713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_96_1)
  {
    case 0:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (factor_96_2)
  {
    case 0:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int segment_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_84_1 > 37)
  {
    acc_1 = ((acc_1 + (segment_84_1 * 2)) + 5) & 127;
    aux_1 ^= segment_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_84_2 > 37)
  {
    acc_2 = ((acc_2 + (segment_84_2 * 2)) + 5) & 127;
    aux_2 ^= segment_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_95_1) & 63;
  aux_2 = (aux_2 + tally_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_31_1 = local_arr_1[aux_1 % 3];
  int phase_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_96_1 == factor_96_2);
  assert(segment_84_1 == segment_84_2);
  assert(tally_95_1 == tally_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_31_1 == phase_31_2);
}

int fn_R000037_3713_11(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_96 = (aux + st.buffer[1]) & 3;
  switch (factor_96)
  {
    case 0:
      acc = (acc + 7) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int segment_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_84 > 37)
  {
    acc = ((acc + (segment_84 * 2)) + 5) & 127;
    aux ^= segment_84 & 15;
  }
  else
  {
    acc = ((acc - segment_84) + 11) & 127;
    aux += 3;
  }
  int tally_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_31 = local_arr[aux % 3];
  acc = (acc + (phase_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_57_1 = local_arr_1[aux_1 % 3];
  int pivot_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_57_2 * 2)) & 127;
  int parity_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_62_1)
  {
    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (parity_62_2)
  {
    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int scale_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_61_1 > 46)
  {
    acc_1 = ((acc_1 + (scale_61_1 * 2)) + 5) & 127;
    aux_1 ^= scale_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_61_2 > 46)
  {
    acc_2 = ((acc_2 + (scale_61_2 * 2)) + 5) & 127;
    aux_2 ^= scale_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_30_1) & 63;
  aux_2 = (aux_2 + phase_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_57_1 == pivot_57_2);
  assert(parity_62_1 == parity_62_2);
  assert(scale_61_1 == scale_61_2);
  assert(phase_30_1 == phase_30_2);
}

int fn_R000037_3713_12(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int pivot_57 = local_arr[aux % 3];
  acc = (acc + (pivot_57 * 2)) & 127;
  int parity_62 = (aux + st.buffer[1]) & 3;
  switch (parity_62)
  {
    case 0:
      acc = (acc + 5) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int scale_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_61 > 46)
  {
    acc = ((acc + (scale_61 * 2)) + 5) & 127;
    aux ^= scale_61 & 15;
  }
  else
  {
    acc = ((acc - scale_61) + 11) & 127;
    aux += 3;
  }
  int phase_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st_1 = {0};
  struct EventLog_R000037_3713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_31_1)
  {
    case 0:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (window_31_2)
  {
    case 0:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_49_1 = local_arr_1[aux_1 % 3];
  int factor_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_49_2 * 2)) & 127;
  int threshold_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_35_1) & 63;
  aux_2 = (aux_2 + threshold_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_31_1 == window_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(threshold_35_1 == threshold_35_2);
}

int fn_R000037_3713_13(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000037_3713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_31 = (aux + st.buffer[1]) & 3;
  switch (window_31)
  {
    case 0:
      acc = (acc + 3) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int local_arr[3] = {4, 9, 15};
  int factor_49 = local_arr[aux % 3];
  acc = (acc + (factor_49 * 2)) & 127;
  int threshold_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int metric_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_68_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_68_1 * 2)) + 5) & 127;
    aux_1 ^= metric_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_68_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_68_2 * 2)) + 5) & 127;
    aux_2 ^= metric_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_11_1) & 63;
  aux_2 = (aux_2 + anchor_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_74_1)
  {
    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (damping_74_2)
  {
    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_68_1 == metric_68_2);
  assert(anchor_11_1 == anchor_11_2);
  assert(damping_74_1 == damping_74_2);
}

int fn_R000037_3713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int metric_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_68 > 16)
  {
    acc = ((acc + (metric_68 * 2)) + 5) & 127;
    aux ^= metric_68 & 15;
  }
  else
  {
    acc = ((acc - metric_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_11) & 63;
  acc ^= aux;
  int damping_74 = (aux + st.buffer[1]) & 3;
  switch (damping_74)
  {
    case 0:
      acc = (acc + 4) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R000037_3713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_32_1 = local_arr_1[aux_1 % 3];
  int accumulator_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_32_2 * 2)) & 127;
  int anchor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_77_1 > 21)
  {
    acc_1 = ((acc_1 + (anchor_77_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_77_2 > 21)
  {
    acc_2 = ((acc_2 + (anchor_77_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_15_1) & 63;
  aux_2 = (aux_2 + tracker_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_72_1)
  {
    case 0:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (mask_72_2)
  {
    case 0:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_32_1 == accumulator_32_2);
  assert(anchor_77_1 == anchor_77_2);
  assert(tracker_15_1 == tracker_15_2);
  assert(mask_72_1 == mask_72_2);
}

int fn_R000037_3713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int accumulator_32 = local_arr[aux % 3];
  acc = (acc + (accumulator_32 * 2)) & 127;
  int anchor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_77 > 21)
  {
    acc = ((acc + (anchor_77 * 2)) + 5) & 127;
    aux ^= anchor_77 & 15;
  }
  else
  {
    acc = ((acc - anchor_77) + 11) & 127;
    aux += 3;
  }
  int tracker_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_15) & 63;
  acc ^= aux;
  int mask_72 = (aux + st.buffer[1]) & 3;
  switch (mask_72)
  {
    case 0:
      acc = (acc + 9) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R000037_3713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_50_1) & 63;
  aux_2 = (aux_2 + offset_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_28_1 = local_arr_1[aux_1 % 3];
  int quotient_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_28_2 * 2)) & 127;
  int mask_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_75_1)
  {
    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (mask_75_2)
  {
    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_50_1 == offset_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_28_1 == quotient_28_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R000037_3713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_28 = local_arr[aux % 3];
  acc = (acc + (quotient_28 * 2)) & 127;
  int mask_75 = (aux + st.buffer[1]) & 3;
  switch (mask_75)
  {
    case 0:
      acc = (acc + 5) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000037_3713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_52_1) & 63;
  aux_2 = (aux_2 + cursor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_52_1 == cursor_52_2);
}

int fn_R000037_3713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_81_1)
  {
    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (anchor_81_2)
  {
    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_11_1 = local_arr_1[aux_1 % 3];
  int coefficient_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_11_2 * 2)) & 127;
  int threshold_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_27_1) & 63;
  aux_2 = (aux_2 + threshold_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_81_1 == anchor_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_11_1 == coefficient_11_2);
  assert(threshold_27_1 == threshold_27_2);
}

int fn_R000037_3713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_81 = (aux + st.buffer[1]) & 3;
  switch (anchor_81)
  {
    case 0:
      acc = (acc + 4) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_11 = local_arr[aux % 3];
  acc = (acc + (coefficient_11 * 2)) & 127;
  int threshold_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_53_1 > 14)
  {
    acc_1 = ((acc_1 + (checksum_53_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_53_2 > 14)
  {
    acc_2 = ((acc_2 + (checksum_53_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_25_1 = local_arr_1[aux_1 % 3];
  int parity_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_25_2 * 2)) & 127;
  int index_reg_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_84_1) & 63;
  aux_2 = (aux_2 + index_reg_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_53_1 == checksum_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_25_1 == parity_25_2);
  assert(index_reg_84_1 == index_reg_84_2);
}

int fn_R000037_3713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_53 > 14)
  {
    acc = ((acc + (checksum_53 * 2)) + 5) & 127;
    aux ^= checksum_53 & 15;
  }
  else
  {
    acc = ((acc - checksum_53) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_25 = local_arr[aux % 3];
  acc = (acc + (parity_25 * 2)) & 127;
  int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000037_3713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int coefficient_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_92_1)
  {
    case 0:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (coefficient_92_2)
  {
    case 0:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_85_1 = local_arr_1[aux_1 % 3];
  int residue_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_87_1 > 23)
  {
    acc_1 = ((acc_1 + (cursor_87_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_87_2 > 23)
  {
    acc_2 = ((acc_2 + (cursor_87_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(cursor_87_1 == cursor_87_2);
}

int fn_R000037_3713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int coefficient_92 = (aux + st.buffer[1]) & 3;
  switch (coefficient_92)
  {
    case 0:
      acc = (acc + 7) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int local_arr[3] = {4, 9, 15};
  int residue_85 = local_arr[aux % 3];
  acc = (acc + (residue_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_87 > 23)
  {
    acc = ((acc + (cursor_87 * 2)) + 5) & 127;
    aux ^= cursor_87 & 15;
  }
  else
  {
    acc = ((acc - cursor_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000037_3713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_74_1) & 63;
  aux_2 = (aux_2 + stride_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_27_1 = local_arr_1[aux_1 % 3];
  int vector_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_27_2 * 2)) & 127;
  int bound_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_79_1 > 40)
  {
    acc_1 = ((acc_1 + (bound_79_1 * 2)) + 5) & 127;
    aux_1 ^= bound_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_79_2 > 40)
  {
    acc_2 = ((acc_2 + (bound_79_2 * 2)) + 5) & 127;
    aux_2 ^= bound_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_97_1)
  {
    case 0:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (index_reg_97_2)
  {
    case 0:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_74_1 == stride_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_27_1 == vector_27_2);
  assert(bound_79_1 == bound_79_2);
  assert(index_reg_97_1 == index_reg_97_2);
}

int fn_R000037_3713_21(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000037_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_27 = local_arr[aux % 3];
  acc = (acc + (vector_27 * 2)) & 127;
  int bound_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_79 > 40)
  {
    acc = ((acc + (bound_79 * 2)) + 5) & 127;
    aux ^= bound_79 & 15;
  }
  else
  {
    acc = ((acc - bound_79) + 11) & 127;
    aux += 3;
  }
  int index_reg_97 = (aux + st.buffer[1]) & 3;
  switch (index_reg_97)
  {
    case 0:
      acc = (acc + 3) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R000037_3713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st_1 = {0};
  struct Transaction_R000037_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int metric_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_66_1)
  {
    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (metric_66_2)
  {
    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int quantum_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_32_1) & 63;
  aux_2 = (aux_2 + quantum_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_84_1 > 45)
  {
    acc_1 = ((acc_1 + (offset_84_1 * 2)) + 5) & 127;
    aux_1 ^= offset_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_84_2 > 45)
  {
    acc_2 = ((acc_2 + (offset_84_2 * 2)) + 5) & 127;
    aux_2 ^= offset_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_66_1 == metric_66_2);
  assert(quantum_32_1 == quantum_32_2);
  assert(offset_84_1 == offset_84_2);
}

int fn_R000037_3713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000037_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int metric_66 = (aux + st.buffer[1]) & 3;
  switch (metric_66)
  {
    case 0:
      acc = (acc + 4) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int quantum_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_32) & 63;
  acc ^= aux;
  int offset_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_84 > 45)
  {
    acc = ((acc + (offset_84 * 2)) + 5) & 127;
    aux ^= offset_84 & 15;
  }
  else
  {
    acc = ((acc - offset_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000037_3713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st_1 = {0};
  struct CipherContext_R000037_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_44_1 > 30)
  {
    acc_1 = ((acc_1 + (offset_44_1 * 2)) + 5) & 127;
    aux_1 ^= offset_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_44_2 > 30)
  {
    acc_2 = ((acc_2 + (offset_44_2 * 2)) + 5) & 127;
    aux_2 ^= offset_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_28_1 == accumulator_28_2);
  assert(offset_44_1 == offset_44_2);
}

int fn_R000037_3713_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000037_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  int offset_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_44 > 30)
  {
    acc = ((acc + (offset_44 * 2)) + 5) & 127;
    aux ^= offset_44 & 15;
  }
  else
  {
    acc = ((acc - offset_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000037_0_1;
  int sec_r000037_0_2;
  int sec_r000037_1_1;
  int sec_r000037_1_2;
  int sec_r000037_2_1;
  int sec_r000037_2_2;
  int sec_r000037_3_1;
  int sec_r000037_3_2;
  int sec_r000037_4_1;
  int sec_r000037_4_2;
  int sec_r000037_5_1;
  int sec_r000037_5_2;
  int sec_r000037_6_1;
  int sec_r000037_6_2;
  int sec_r000037_7_1;
  int sec_r000037_7_2;
  int sec_r000037_8_1;
  int sec_r000037_8_2;
  int sec_r000037_9_1;
  int sec_r000037_9_2;
  int sec_r000037_10_1;
  int sec_r000037_10_2;
  int sec_r000037_11_1;
  int sec_r000037_11_2;
  int sec_r000037_12_1;
  int sec_r000037_12_2;
  int sec_r000037_13_1;
  int sec_r000037_13_2;
  int sec_r000037_14_1;
  int sec_r000037_14_2;
  int sec_r000037_15_1;
  int sec_r000037_15_2;
  int sec_r000037_16_1;
  int sec_r000037_16_2;
  int sec_r000037_17_1;
  int sec_r000037_17_2;
  int sec_r000037_18_1;
  int sec_r000037_18_2;
  int sec_r000037_19_1;
  int sec_r000037_19_2;
  int pub_r000037_0_1;
  int pub_r000037_0_2;
  int pub_r000037_1_1;
  int pub_r000037_1_2;
  int pub_r000037_2_1;
  int pub_r000037_2_2;
  int pub_r000037_3_1;
  int pub_r000037_3_2;
  int pub_r000037_4_1;
  int pub_r000037_4_2;
  int pub_r000037_5_1;
  int pub_r000037_5_2;
  int pub_r000037_6_1;
  int pub_r000037_6_2;
  int pub_r000037_7_1;
  int pub_r000037_7_2;
  int pub_r000037_8_1;
  int pub_r000037_8_2;
  int pub_r000037_9_1;
  int pub_r000037_9_2;
  int pub_r000037_10_1;
  int pub_r000037_10_2;
  int pub_r000037_11_1;
  int pub_r000037_11_2;
  int pub_r000037_12_1;
  int pub_r000037_12_2;
  int pub_r000037_13_1;
  int pub_r000037_13_2;
  int pub_r000037_14_1;
  int pub_r000037_14_2;
  int pub_r000037_15_1;
  int pub_r000037_15_2;
  int pub_r000037_16_1;
  int pub_r000037_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000037_0_1 >= (-100)) && (pub_r000037_0_1 <= 100));
  __CPROVER_assume((pub_r000037_0_2 >= (-100)) && (pub_r000037_0_2 <= 100));
  __CPROVER_assume((pub_r000037_1_1 >= (-100)) && (pub_r000037_1_1 <= 100));
  __CPROVER_assume((pub_r000037_1_2 >= (-100)) && (pub_r000037_1_2 <= 100));
  __CPROVER_assume((pub_r000037_2_1 >= (-100)) && (pub_r000037_2_1 <= 100));
  __CPROVER_assume((pub_r000037_2_2 >= (-100)) && (pub_r000037_2_2 <= 100));
  __CPROVER_assume((pub_r000037_3_1 >= (-100)) && (pub_r000037_3_1 <= 100));
  __CPROVER_assume((pub_r000037_3_2 >= (-100)) && (pub_r000037_3_2 <= 100));
  __CPROVER_assume((pub_r000037_4_1 >= (-100)) && (pub_r000037_4_1 <= 100));
  __CPROVER_assume((pub_r000037_4_2 >= (-100)) && (pub_r000037_4_2 <= 100));
  __CPROVER_assume((pub_r000037_5_1 >= (-100)) && (pub_r000037_5_1 <= 100));
  __CPROVER_assume((pub_r000037_5_2 >= (-100)) && (pub_r000037_5_2 <= 100));
  __CPROVER_assume((pub_r000037_6_1 >= (-100)) && (pub_r000037_6_1 <= 100));
  __CPROVER_assume((pub_r000037_6_2 >= (-100)) && (pub_r000037_6_2 <= 100));
  __CPROVER_assume((pub_r000037_7_1 >= (-100)) && (pub_r000037_7_1 <= 100));
  __CPROVER_assume((pub_r000037_7_2 >= (-100)) && (pub_r000037_7_2 <= 100));
  __CPROVER_assume((pub_r000037_8_1 >= (-100)) && (pub_r000037_8_1 <= 100));
  __CPROVER_assume((pub_r000037_8_2 >= (-100)) && (pub_r000037_8_2 <= 100));
  __CPROVER_assume((pub_r000037_9_1 >= (-100)) && (pub_r000037_9_1 <= 100));
  __CPROVER_assume((pub_r000037_9_2 >= (-100)) && (pub_r000037_9_2 <= 100));
  __CPROVER_assume((pub_r000037_10_1 >= (-100)) && (pub_r000037_10_1 <= 100));
  __CPROVER_assume((pub_r000037_10_2 >= (-100)) && (pub_r000037_10_2 <= 100));
  __CPROVER_assume((pub_r000037_11_1 >= (-100)) && (pub_r000037_11_1 <= 100));
  __CPROVER_assume((pub_r000037_11_2 >= (-100)) && (pub_r000037_11_2 <= 100));
  __CPROVER_assume((pub_r000037_12_1 >= (-100)) && (pub_r000037_12_1 <= 100));
  __CPROVER_assume((pub_r000037_12_2 >= (-100)) && (pub_r000037_12_2 <= 100));
  __CPROVER_assume((pub_r000037_13_1 >= (-100)) && (pub_r000037_13_1 <= 100));
  __CPROVER_assume((pub_r000037_13_2 >= (-100)) && (pub_r000037_13_2 <= 100));
  __CPROVER_assume((pub_r000037_14_1 >= (-100)) && (pub_r000037_14_1 <= 100));
  __CPROVER_assume((pub_r000037_14_2 >= (-100)) && (pub_r000037_14_2 <= 100));
  __CPROVER_assume((pub_r000037_15_1 >= (-100)) && (pub_r000037_15_1 <= 100));
  __CPROVER_assume((pub_r000037_15_2 >= (-100)) && (pub_r000037_15_2 <= 100));
  __CPROVER_assume((pub_r000037_16_1 >= (-100)) && (pub_r000037_16_1 <= 100));
  __CPROVER_assume((pub_r000037_16_2 >= (-100)) && (pub_r000037_16_2 <= 100));
  __CPROVER_assume((sec_r000037_0_1 >= 0) && (sec_r000037_0_1 <= 255));
  __CPROVER_assume((sec_r000037_0_2 >= 0) && (sec_r000037_0_2 <= 255));
  __CPROVER_assume((sec_r000037_1_1 >= 0) && (sec_r000037_1_1 <= 255));
  __CPROVER_assume((sec_r000037_1_2 >= 0) && (sec_r000037_1_2 <= 255));
  __CPROVER_assume((sec_r000037_2_1 >= 0) && (sec_r000037_2_1 <= 255));
  __CPROVER_assume((sec_r000037_2_2 >= 0) && (sec_r000037_2_2 <= 255));
  __CPROVER_assume((sec_r000037_3_1 >= 0) && (sec_r000037_3_1 <= 255));
  __CPROVER_assume((sec_r000037_3_2 >= 0) && (sec_r000037_3_2 <= 255));
  __CPROVER_assume((sec_r000037_4_1 >= 0) && (sec_r000037_4_1 <= 255));
  __CPROVER_assume((sec_r000037_4_2 >= 0) && (sec_r000037_4_2 <= 255));
  __CPROVER_assume((sec_r000037_5_1 >= 0) && (sec_r000037_5_1 <= 255));
  __CPROVER_assume((sec_r000037_5_2 >= 0) && (sec_r000037_5_2 <= 255));
  __CPROVER_assume((sec_r000037_6_1 >= 0) && (sec_r000037_6_1 <= 255));
  __CPROVER_assume((sec_r000037_6_2 >= 0) && (sec_r000037_6_2 <= 255));
  __CPROVER_assume((sec_r000037_7_1 >= 0) && (sec_r000037_7_1 <= 255));
  __CPROVER_assume((sec_r000037_7_2 >= 0) && (sec_r000037_7_2 <= 255));
  __CPROVER_assume((sec_r000037_8_1 >= 0) && (sec_r000037_8_1 <= 255));
  __CPROVER_assume((sec_r000037_8_2 >= 0) && (sec_r000037_8_2 <= 255));
  __CPROVER_assume((sec_r000037_9_1 >= 0) && (sec_r000037_9_1 <= 255));
  __CPROVER_assume((sec_r000037_9_2 >= 0) && (sec_r000037_9_2 <= 255));
  __CPROVER_assume((sec_r000037_10_1 >= 0) && (sec_r000037_10_1 <= 255));
  __CPROVER_assume((sec_r000037_10_2 >= 0) && (sec_r000037_10_2 <= 255));
  __CPROVER_assume((sec_r000037_11_1 >= 0) && (sec_r000037_11_1 <= 255));
  __CPROVER_assume((sec_r000037_11_2 >= 0) && (sec_r000037_11_2 <= 255));
  __CPROVER_assume((sec_r000037_12_1 >= 0) && (sec_r000037_12_1 <= 255));
  __CPROVER_assume((sec_r000037_12_2 >= 0) && (sec_r000037_12_2 <= 255));
  __CPROVER_assume((sec_r000037_13_1 >= 0) && (sec_r000037_13_1 <= 255));
  __CPROVER_assume((sec_r000037_13_2 >= 0) && (sec_r000037_13_2 <= 255));
  __CPROVER_assume((sec_r000037_14_1 >= 0) && (sec_r000037_14_1 <= 255));
  __CPROVER_assume((sec_r000037_14_2 >= 0) && (sec_r000037_14_2 <= 255));
  __CPROVER_assume((sec_r000037_15_1 >= 0) && (sec_r000037_15_1 <= 255));
  __CPROVER_assume((sec_r000037_15_2 >= 0) && (sec_r000037_15_2 <= 255));
  __CPROVER_assume((sec_r000037_16_1 >= 0) && (sec_r000037_16_1 <= 255));
  __CPROVER_assume((sec_r000037_16_2 >= 0) && (sec_r000037_16_2 <= 255));
  __CPROVER_assume((sec_r000037_17_1 >= 0) && (sec_r000037_17_1 <= 255));
  __CPROVER_assume((sec_r000037_17_2 >= 0) && (sec_r000037_17_2 <= 255));
  __CPROVER_assume((sec_r000037_18_1 >= 0) && (sec_r000037_18_1 <= 255));
  __CPROVER_assume((sec_r000037_18_2 >= 0) && (sec_r000037_18_2 <= 255));
  __CPROVER_assume((sec_r000037_19_1 >= 0) && (sec_r000037_19_1 <= 255));
  __CPROVER_assume((sec_r000037_19_2 >= 0) && (sec_r000037_19_2 <= 255));
  struct StreamBuffer_R000037_3713_0 st_var_0_1 = {0};
  struct StreamBuffer_R000037_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000037_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000037_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000037_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000037_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000037_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000037_0_2 + 7) & 15;
  struct Transaction_R000037_3713_1 st_var_1_1 = {0};
  struct Transaction_R000037_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000037_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000037_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000037_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000037_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000037_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000037_0_2 + 9) & 15;
  struct CipherContext_R000037_3713_2 st_var_2_1 = {0};
  struct CipherContext_R000037_3713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000037_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000037_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000037_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000037_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000037_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000037_0_2 + 11) & 15;
  struct EventLog_R000037_3713_3 st_var_3_1 = {0};
  struct EventLog_R000037_3713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000037_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000037_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000037_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000037_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000037_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000037_0_2 + 13) & 15;
  union ColorPixel_R000037_3713_0 u_var_1;
  union ColorPixel_R000037_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 50)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 50)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_5_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_11_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 35)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 35)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 32)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 32)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 29)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 29)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 45)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 45)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_24_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_35_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 42)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 42)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 27)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 27)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 49)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 49)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 32)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 32)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000037_11_1 & 1) != 0)
  {
    if ((sec_r000037_9_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000037_1_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000037_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000037_1_1 + 7) & 127;
  }
  if ((sec_r000037_11_2 & 1) != 0)
  {
    if ((sec_r000037_9_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000037_1_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000037_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000037_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000037_12_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000037_12_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000037_3_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000037_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000037_3_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000037_3_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000037_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000037_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000037_17_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000037_10_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000037_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000037_10_1 + 7) & 127;
  }
  if ((sec_r000037_17_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000037_10_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000037_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000037_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000037_7_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000037_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000037_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000037_9_1 + 7) & 127;
  }
  if ((sec_r000037_7_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000037_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000037_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000037_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000037_18_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((sec_r000037_18_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000037_13_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000037_13_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000037_12_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_12_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000037_2_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000037_2_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000037_4_1 & 1) != 0)
  {
    if ((sec_r000037_8_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((sec_r000037_4_2 & 1) != 0)
  {
    if ((sec_r000037_8_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000037_10_1 & 1) != 0)
  {
    if ((sec_r000037_18_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000037_11_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000037_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000037_11_1 + 7) & 127;
  }
  if ((sec_r000037_10_2 & 1) != 0)
  {
    if ((sec_r000037_18_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000037_11_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000037_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000037_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000037_19_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000037_1_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000037_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000037_1_1 + 7) & 127;
  }
  if ((sec_r000037_19_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000037_1_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000037_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000037_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000037_5_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000037_5_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000037_14_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000037_6_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000037_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000037_6_1 + 7) & 127;
  }
  if ((sec_r000037_14_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000037_6_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000037_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000037_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000037_14_1 & 1) != 0)
  {
    if ((sec_r000037_14_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000037_10_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000037_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000037_10_1 + 7) & 127;
  }
  if ((sec_r000037_14_2 & 1) != 0)
  {
    if ((sec_r000037_14_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000037_10_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000037_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000037_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000037_8_1 & 1) != 0)
  {
    if ((sec_r000037_8_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_8_2 & 1) != 0)
  {
    if ((sec_r000037_8_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000037_8_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000037_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000037_8_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000037_8_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000037_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000037_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000037_10_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_10_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000037_9_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000037_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000037_9_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000037_9_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000037_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000037_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000037_18_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000037_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000037_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000037_10_1 + 7) & 127;
  }
  if ((sec_r000037_18_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000037_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000037_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000037_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000037_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000037_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000037_8_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000037_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000037_8_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000037_8_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000037_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000037_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000037_0_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000037_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000037_0_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000037_0_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000037_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000037_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000037_2_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000037_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000037_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000037_6_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000037_2_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000037_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000037_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000037_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000037_8_1 & 1) != 0)
  {
    if ((sec_r000037_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_8_2 & 1) != 0)
  {
    if ((sec_r000037_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000037_19_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000037_3_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000037_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000037_3_1 + 7) & 127;
  }
  if ((sec_r000037_19_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000037_3_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000037_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000037_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000037_6_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000037_6_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000037_5_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000037_5_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000037_15_1 & 1) != 0)
  {
    if ((sec_r000037_18_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000037_2_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000037_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000037_2_1 + 7) & 127;
  }
  if ((sec_r000037_15_2 & 1) != 0)
  {
    if ((sec_r000037_18_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000037_2_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000037_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000037_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000037_14_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000037_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000037_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000037_16_1 + 7) & 127;
  }
  if ((sec_r000037_14_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000037_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000037_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000037_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000037_16_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000037_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000037_16_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000037_16_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000037_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000037_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000037_12_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000037_16_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000037_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000037_16_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000037_12_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000037_16_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000037_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000037_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000037_12_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000037_0_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000037_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000037_0_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000037_12_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000037_0_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000037_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000037_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000037_15_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_15_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000037_5_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000037_2_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000037_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000037_2_1 + 7) & 127;
  }
  if ((sec_r000037_5_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000037_2_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000037_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000037_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000037_11_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000037_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000037_11_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000037_11_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000037_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000037_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000037_18_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000037_10_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000037_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000037_10_1 + 7) & 127;
  }
  if ((sec_r000037_18_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000037_10_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000037_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000037_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000037_4_1 & 1) != 0)
  {
    if ((sec_r000037_19_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((sec_r000037_4_2 & 1) != 0)
  {
    if ((sec_r000037_19_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000037_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000037_13_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000037_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000037_13_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000037_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000037_13_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000037_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000037_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000037_2_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_2_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000037_11_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000037_8_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000037_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000037_8_1 + 7) & 127;
  }
  if ((sec_r000037_11_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000037_8_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000037_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000037_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000037_9_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((sec_r000037_9_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000037_14_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000037_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000037_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000037_3_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000037_14_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000037_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000037_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000037_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000037_13_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000037_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000037_13_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000037_13_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000037_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000037_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000037_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000037_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000037_10_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000037_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000037_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000037_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000037_1_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000037_1_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000037_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000037_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000037_5_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000037_0_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000037_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000037_0_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000037_5_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000037_0_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000037_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000037_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000037_3_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((sec_r000037_3_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000037_9_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000037_1_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000037_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000037_1_1 + 7) & 127;
  }
  if ((sec_r000037_9_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000037_1_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000037_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000037_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000037_9_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000037_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000037_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000037_9_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000037_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000037_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000037_7_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000037_13_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000037_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000037_13_1 + 7) & 127;
  }
  if ((sec_r000037_7_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000037_13_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000037_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000037_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000037_18_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((sec_r000037_18_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000037_3_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((sec_r000037_3_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000037_1_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000037_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000037_1_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000037_1_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000037_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000037_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000037_9_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000037_9_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000037_11_1 & 1) != 0)
  {
    if ((sec_r000037_1_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((sec_r000037_11_2 & 1) != 0)
  {
    if ((sec_r000037_1_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000037_0_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000037_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000037_0_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000037_0_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000037_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000037_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000037_0_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((sec_r000037_0_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000037_4_1 & 1) != 0)
  {
    if ((sec_r000037_9_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((sec_r000037_4_2 & 1) != 0)
  {
    if ((sec_r000037_9_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000037_16_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_16_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000037_6_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_6_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000037_3_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000037_14_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000037_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000037_14_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000037_3_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000037_14_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000037_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000037_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000037_6_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000037_8_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000037_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000037_8_1 + 7) & 127;
  }
  if ((sec_r000037_6_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000037_8_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000037_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000037_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000037_19_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000037_1_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000037_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000037_1_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000037_19_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000037_1_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000037_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000037_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000037_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000037_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000037_8_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000037_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000037_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000037_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000037_11_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000037_11_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000037_13_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_13_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000037_18_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000037_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000037_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000037_6_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000037_18_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000037_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000037_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000037_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000037_10_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000037_11_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000037_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000037_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000037_10_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000037_11_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000037_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000037_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000037_5_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000037_5_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000037_18_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000037_13_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000037_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000037_13_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000037_18_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000037_13_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000037_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000037_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000037_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000037_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000037_14_1 & 1) != 0)
  {
    if ((sec_r000037_6_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000037_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000037_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000037_4_1 + 7) & 127;
  }
  if ((sec_r000037_14_2 & 1) != 0)
  {
    if ((sec_r000037_6_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000037_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000037_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000037_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000037_11_1 & 1) != 0)
  {
    if ((sec_r000037_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_11_2 & 1) != 0)
  {
    if ((sec_r000037_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000037_13_1 & 1) != 0)
  {
    if ((sec_r000037_15_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((sec_r000037_13_2 & 1) != 0)
  {
    if ((sec_r000037_15_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000037_13_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000037_13_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000037_2_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000037_2_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000037_4_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000037_4_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r000037_17_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r000037_17_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000037_2_1 & 1) != 0)
  {
    if ((sec_r000037_3_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000037_7_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000037_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000037_7_1 + 7) & 127;
  }
  if ((sec_r000037_2_2 & 1) != 0)
  {
    if ((sec_r000037_3_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000037_7_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000037_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000037_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000037_5_1 & 1) != 0)
  {
    if ((sec_r000037_7_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000037_5_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000037_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000037_5_1 + 7) & 127;
  }
  if ((sec_r000037_5_2 & 1) != 0)
  {
    if ((sec_r000037_7_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000037_5_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000037_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000037_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000037_3_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000037_15_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000037_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000037_15_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000037_3_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000037_15_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000037_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000037_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000037_14_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000037_12_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000037_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000037_12_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000037_14_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000037_12_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000037_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000037_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000037_17_1 != sec_r000037_17_2);
  __CPROVER_assume(sec_r000037_15_1 != sec_r000037_15_2);
  __CPROVER_assume(sec_r000037_12_1 != sec_r000037_12_2);
  __CPROVER_assume(pub_r000037_10_1 == pub_r000037_10_2);
  __CPROVER_assume(pub_r000037_11_1 == pub_r000037_11_2);
  __CPROVER_assume(sec_r000037_0_1 != sec_r000037_0_2);
  __CPROVER_assume(sec_r000037_6_1 != sec_r000037_6_2);
  __CPROVER_assume(sec_r000037_8_1 != sec_r000037_8_2);
  __CPROVER_assume(sec_r000037_9_1 != sec_r000037_9_2);
  __CPROVER_assume(sec_r000037_10_1 != sec_r000037_10_2);
  __CPROVER_assume(sec_r000037_14_1 != sec_r000037_14_2);
  __CPROVER_assume(pub_r000037_5_1 == pub_r000037_5_2);
  __CPROVER_assume(pub_r000037_7_1 == pub_r000037_7_2);
  __CPROVER_assume(sec_r000037_19_1 != sec_r000037_19_2);
  __CPROVER_assume(pub_r000037_13_1 == pub_r000037_13_2);
  __CPROVER_assume(sec_r000037_5_1 != sec_r000037_5_2);
  __CPROVER_assume(pub_r000037_14_1 == pub_r000037_14_2);
  __CPROVER_assume(pub_r000037_6_1 == pub_r000037_6_2);
  __CPROVER_assume(pub_r000037_16_1 == pub_r000037_16_2);
  __CPROVER_assume(pub_r000037_4_1 == pub_r000037_4_2);
  __CPROVER_assume(pub_r000037_1_1 == pub_r000037_1_2);
  __CPROVER_assume(sec_r000037_18_1 != sec_r000037_18_2);
  __CPROVER_assume(pub_r000037_8_1 == pub_r000037_8_2);
  __CPROVER_assume(sec_r000037_3_1 != sec_r000037_3_2);
  __CPROVER_assume(pub_r000037_2_1 == pub_r000037_2_2);
  __CPROVER_assume(pub_r000037_15_1 == pub_r000037_15_2);
  __CPROVER_assume(sec_r000037_11_1 != sec_r000037_11_2);
  __CPROVER_assume(sec_r000037_16_1 != sec_r000037_16_2);
  __CPROVER_assume(sec_r000037_13_1 != sec_r000037_13_2);
  __CPROVER_assume(pub_r000037_12_1 == pub_r000037_12_2);
  __CPROVER_assume(sec_r000037_7_1 != sec_r000037_7_2);
  __CPROVER_assume(sec_r000037_4_1 != sec_r000037_4_2);
  __CPROVER_assume(pub_r000037_3_1 == pub_r000037_3_2);
  __CPROVER_assume(sec_r000037_2_1 != sec_r000037_2_2);
  __CPROVER_assume(pub_r000037_0_1 == pub_r000037_0_2);
  __CPROVER_assume(sec_r000037_1_1 != sec_r000037_1_2);
  __CPROVER_assume(pub_r000037_9_1 == pub_r000037_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
  }

  assert(u_var_1.word == u_var_2.word);
  for (int i_raw = 0; i_raw < 4; i_raw++)
  {
    assert(u_var_1.raw[i_raw] == u_var_2.raw[i_raw]);
  }

  for (int i_pairs = 0; i_pairs < 2; i_pairs++)
  {
    assert(u_var_1.pairs[i_pairs] == u_var_2.pairs[i_pairs]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(table_1[i_0] == table_2[i_0]);
  }

  assert(stage_v_0_1 == stage_v_0_2);
  assert(stage_v_1_1 == stage_v_1_2);
  assert(stage_v_2_1 == stage_v_2_2);
  assert(stage_v_3_1 == stage_v_3_2);
  assert(stage_v_4_1 == stage_v_4_2);
  assert(stage_v_5_1 == stage_v_5_2);
  assert(stage_v_6_1 == stage_v_6_2);
  assert(stage_v_7_1 == stage_v_7_2);
  assert(stage_v_8_1 == stage_v_8_2);
  assert(stage_v_9_1 == stage_v_9_2);
  assert(stage_v_10_1 == stage_v_10_2);
  assert(stage_v_11_1 == stage_v_11_2);
  assert(stage_v_12_1 == stage_v_12_2);
  assert(stage_v_13_1 == stage_v_13_2);
  assert(stage_v_14_1 == stage_v_14_2);
  assert(stage_v_15_1 == stage_v_15_2);
  assert(stage_v_16_1 == stage_v_16_2);
  assert(stage_v_17_1 == stage_v_17_2);
  assert(stage_v_18_1 == stage_v_18_2);
  assert(stage_v_19_1 == stage_v_19_2);
  assert(stage_v_20_1 == stage_v_20_2);
  assert(stage_v_21_1 == stage_v_21_2);
  assert(stage_v_22_1 == stage_v_22_2);
  assert(stage_v_23_1 == stage_v_23_2);
  assert(stage_v_24_1 == stage_v_24_2);
  assert(stage_v_25_1 == stage_v_25_2);
  assert(stage_v_26_1 == stage_v_26_2);
  assert(stage_v_27_1 == stage_v_27_2);
  assert(stage_v_28_1 == stage_v_28_2);
  assert(stage_v_29_1 == stage_v_29_2);
  assert(stage_v_30_1 == stage_v_30_2);
  assert(stage_v_31_1 == stage_v_31_2);
  assert(stage_v_32_1 == stage_v_32_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(stage_v_138_1 == stage_v_138_2);
}


