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
struct FilterState_R000358_5813_0
{
  unsigned char gain_db;
  int prev_out;
  short mode;
  int buffer[3];
};
struct StreamBuffer_R000358_5813_1
{
  int tail;
  int checksum;
  int head;
  unsigned char watermark;
  unsigned char capacity;
  int buffer[3];
};
struct CipherContext_R000358_5813_2
{
  short round_key;
  short nonce;
  short iv;
  int counter;
  int flags;
  unsigned char tag;
  int buffer[3];
};
struct EventLog_R000358_5813_3
{
  int timestamp;
  int signature;
  int severity;
  int buffer[3];
};
union RegisterBank_R000358_5813_0
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
void fn_R000358_5813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st_1 = {0};
  struct CipherContext_R000358_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int margin_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_48_1)
  {
    case 0:
      acc_1 = (acc_1 + 6) & 127;
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

  switch (margin_48_2)
  {
    case 0:
      acc_2 = (acc_2 + 6) & 127;
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

  int damping_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_55_1) & 63;
  aux_2 = (aux_2 + damping_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_48_1 == margin_48_2);
  assert(damping_55_1 == damping_55_2);
}

int fn_R000358_5813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int margin_48 = (aux + st.buffer[1]) & 3;
  switch (margin_48)
  {
    case 0:
      acc = (acc + 6) & 127;
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

  int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000358_5813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_31_1 = local_arr_1[aux_1 % 3];
  int checksum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_31_2 * 2)) & 127;
  int anchor_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_63_1 > 25)
  {
    acc_1 = ((acc_1 + (anchor_63_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_63_2 > 25)
  {
    acc_2 = ((acc_2 + (anchor_63_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_31_1 == checksum_31_2);
  assert(anchor_63_1 == anchor_63_2);
}

int fn_R000358_5813_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int checksum_31 = local_arr[aux % 3];
  acc = (acc + (checksum_31 * 2)) & 127;
  int anchor_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_63 > 25)
  {
    acc = ((acc + (anchor_63 * 2)) + 5) & 127;
    aux ^= anchor_63 & 15;
  }
  else
  {
    acc = ((acc - anchor_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000358_5813_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int window_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_59_1) & 63;
  aux_2 = (aux_2 + window_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_17_1)
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

  switch (accumulator_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_61_1 = local_arr_1[aux_1 % 3];
  int index_reg_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_59_1 == window_59_2);
  assert(accumulator_17_1 == accumulator_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
}

int fn_R000358_5813_2(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int window_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_59) & 63;
  acc ^= aux;
  int accumulator_17 = (aux + st.buffer[1]) & 3;
  switch (accumulator_17)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_61 = local_arr[aux % 3];
  acc = (acc + (index_reg_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_43_1 > 36)
  {
    acc_1 = ((acc_1 + (window_43_1 * 2)) + 5) & 127;
    aux_1 ^= window_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_43_2 > 36)
  {
    acc_2 = ((acc_2 + (window_43_2 * 2)) + 5) & 127;
    aux_2 ^= window_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
}

int fn_R000358_5813_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_43 > 36)
  {
    acc = ((acc + (window_43 * 2)) + 5) & 127;
    aux ^= window_43 & 15;
  }
  else
  {
    acc = ((acc - window_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st_1 = {0};
  struct CipherContext_R000358_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_22_1) & 63;
  aux_2 = (aux_2 + bound_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_22_1 == bound_22_2);
}

int fn_R000358_5813_4(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000358_5813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_93_1 > 28)
  {
    acc_1 = ((acc_1 + (checksum_93_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_93_2 > 28)
  {
    acc_2 = ((acc_2 + (checksum_93_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_93_1 == checksum_93_2);
}

int fn_R000358_5813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_93 > 28)
  {
    acc = ((acc + (checksum_93 * 2)) + 5) & 127;
    aux ^= checksum_93 & 15;
  }
  else
  {
    acc = ((acc - checksum_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000358_5813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_54_1 = local_arr_1[aux_1 % 3];
  int quantum_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_54_2 * 2)) & 127;
  int window_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_97_1) & 63;
  aux_2 = (aux_2 + window_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_68_1)
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

  switch (bound_68_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_54_1 == quantum_54_2);
  assert(window_97_1 == window_97_2);
  assert(bound_68_1 == bound_68_2);
}

int fn_R000358_5813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int quantum_54 = local_arr[aux % 3];
  acc = (acc + (quantum_54 * 2)) & 127;
  int window_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_97) & 63;
  acc ^= aux;
  int bound_68 = (aux + st.buffer[1]) & 3;
  switch (bound_68)
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

void fn_R000358_5813_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000358_5813_0 st_1 = {0};
  struct FilterState_R000358_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_80_1)
  {
    case 0:
      acc_1 = (acc_1 + 8) & 127;
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

  switch (phase_80_2)
  {
    case 0:
      acc_2 = (acc_2 + 8) & 127;
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

  int parity_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_41_1) & 63;
  aux_2 = (aux_2 + parity_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_65_1 > 20)
  {
    acc_1 = ((acc_1 + (factor_65_1 * 2)) + 5) & 127;
    aux_1 ^= factor_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_65_2 > 20)
  {
    acc_2 = ((acc_2 + (factor_65_2 * 2)) + 5) & 127;
    aux_2 ^= factor_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_80_1 == phase_80_2);
  assert(parity_41_1 == parity_41_2);
  assert(factor_65_1 == factor_65_2);
}

int fn_R000358_5813_7(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000358_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_80 = (aux + st.buffer[1]) & 3;
  switch (phase_80)
  {
    case 0:
      acc = (acc + 8) & 127;
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

  int parity_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_41) & 63;
  acc ^= aux;
  int factor_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_65 > 20)
  {
    acc = ((acc + (factor_65 * 2)) + 5) & 127;
    aux ^= factor_65 & 15;
  }
  else
  {
    acc = ((acc - factor_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000358_5813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st_1 = {0};
  struct CipherContext_R000358_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_96_1 = local_arr_1[aux_1 % 3];
  int index_reg_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_96_1 == index_reg_96_2);
}

int fn_R000358_5813_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000358_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int index_reg_96 = local_arr[aux % 3];
  acc = (acc + (index_reg_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000358_5813_0 st_1 = {0};
  struct FilterState_R000358_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_51_1) & 63;
  aux_2 = (aux_2 + parity_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_81_1 > 35)
  {
    acc_1 = ((acc_1 + (accumulator_81_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_81_2 > 35)
  {
    acc_2 = ((acc_2 + (accumulator_81_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_81_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_51_1 == parity_51_2);
  assert(accumulator_81_1 == accumulator_81_2);
}

int fn_R000358_5813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000358_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_51) & 63;
  acc ^= aux;
  int accumulator_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_81 > 35)
  {
    acc = ((acc + (accumulator_81 * 2)) + 5) & 127;
    aux ^= accumulator_81 & 15;
  }
  else
  {
    acc = ((acc - accumulator_81) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000358_5813_1 st_1 = {0};
  struct StreamBuffer_R000358_5813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int checksum_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_35_1) & 63;
  aux_2 = (aux_2 + checksum_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_71_1)
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

  switch (offset_71_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_19_1 = local_arr_1[aux_1 % 3];
  int offset_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_35_1 == checksum_35_2);
  assert(offset_71_1 == offset_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_19_1 == offset_19_2);
}

int fn_R000358_5813_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000358_5813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int checksum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_35) & 63;
  acc ^= aux;
  int offset_71 = (aux + st.buffer[1]) & 3;
  switch (offset_71)
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

  int local_arr[3] = {4, 9, 15};
  int offset_19 = local_arr[aux % 3];
  acc = (acc + (offset_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int anchor_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_44_1)
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

  switch (anchor_44_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_62_1) & 63;
  aux_2 = (aux_2 + residue_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_37_1 = local_arr_1[aux_1 % 3];
  int segment_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_44_1 == anchor_44_2);
  assert(residue_62_1 == residue_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_37_1 == segment_37_2);
}

int fn_R000358_5813_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int anchor_44 = (aux + st.buffer[1]) & 3;
  switch (anchor_44)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_37 = local_arr[aux % 3];
  acc = (acc + (segment_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000358_5813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_20_1) & 63;
  aux_2 = (aux_2 + accumulator_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_99_1 = local_arr_1[aux_1 % 3];
  int tracker_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_46_1 > 50)
  {
    acc_1 = ((acc_1 + (margin_46_1 * 2)) + 5) & 127;
    aux_1 ^= margin_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_46_2 > 50)
  {
    acc_2 = ((acc_2 + (margin_46_2 * 2)) + 5) & 127;
    aux_2 ^= margin_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_20_1 == accumulator_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_99_1 == tracker_99_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R000358_5813_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_99 = local_arr[aux % 3];
  acc = (acc + (tracker_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_46 > 50)
  {
    acc = ((acc + (margin_46 * 2)) + 5) & 127;
    aux ^= margin_46 & 15;
  }
  else
  {
    acc = ((acc - margin_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000358_5813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st_1 = {0};
  struct EventLog_R000358_5813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_43_1 > 35)
  {
    acc_1 = ((acc_1 + (residue_43_1 * 2)) + 5) & 127;
    aux_1 ^= residue_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_43_2 > 35)
  {
    acc_2 = ((acc_2 + (residue_43_2 * 2)) + 5) & 127;
    aux_2 ^= residue_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_72_1)
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

  switch (mask_72_2)
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

  int sample_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_83_1) & 63;
  aux_2 = (aux_2 + sample_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_48_1 = local_arr_1[aux_1 % 3];
  int tracker_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_43_1 == residue_43_2);
  assert(mask_72_1 == mask_72_2);
  assert(sample_83_1 == sample_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_48_1 == tracker_48_2);
}

int fn_R000358_5813_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000358_5813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_43 > 35)
  {
    acc = ((acc + (residue_43 * 2)) + 5) & 127;
    aux ^= residue_43 & 15;
  }
  else
  {
    acc = ((acc - residue_43) + 11) & 127;
    aux += 3;
  }
  int mask_72 = (aux + st.buffer[1]) & 3;
  switch (mask_72)
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

  int sample_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_83) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_48 = local_arr[aux % 3];
  acc = (acc + (tracker_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000358_0_1;
  int sec_r000358_0_2;
  int sec_r000358_1_1;
  int sec_r000358_1_2;
  int sec_r000358_2_1;
  int sec_r000358_2_2;
  int sec_r000358_3_1;
  int sec_r000358_3_2;
  int sec_r000358_4_1;
  int sec_r000358_4_2;
  int sec_r000358_5_1;
  int sec_r000358_5_2;
  int sec_r000358_6_1;
  int sec_r000358_6_2;
  int sec_r000358_7_1;
  int sec_r000358_7_2;
  int sec_r000358_8_1;
  int sec_r000358_8_2;
  int sec_r000358_9_1;
  int sec_r000358_9_2;
  int sec_r000358_10_1;
  int sec_r000358_10_2;
  int sec_r000358_11_1;
  int sec_r000358_11_2;
  int sec_r000358_12_1;
  int sec_r000358_12_2;
  int sec_r000358_13_1;
  int sec_r000358_13_2;
  int sec_r000358_14_1;
  int sec_r000358_14_2;
  int sec_r000358_15_1;
  int sec_r000358_15_2;
  int sec_r000358_16_1;
  int sec_r000358_16_2;
  int sec_r000358_17_1;
  int sec_r000358_17_2;
  int pub_r000358_0_1;
  int pub_r000358_0_2;
  int pub_r000358_1_1;
  int pub_r000358_1_2;
  int pub_r000358_2_1;
  int pub_r000358_2_2;
  int pub_r000358_3_1;
  int pub_r000358_3_2;
  int pub_r000358_4_1;
  int pub_r000358_4_2;
  int pub_r000358_5_1;
  int pub_r000358_5_2;
  int pub_r000358_6_1;
  int pub_r000358_6_2;
  int pub_r000358_7_1;
  int pub_r000358_7_2;
  int pub_r000358_8_1;
  int pub_r000358_8_2;
  int pub_r000358_9_1;
  int pub_r000358_9_2;
  int pub_r000358_10_1;
  int pub_r000358_10_2;
  int pub_r000358_11_1;
  int pub_r000358_11_2;
  int pub_r000358_12_1;
  int pub_r000358_12_2;
  int pub_r000358_13_1;
  int pub_r000358_13_2;
  int pub_r000358_14_1;
  int pub_r000358_14_2;
  int pub_r000358_15_1;
  int pub_r000358_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000358_0_1 >= (-100)) && (pub_r000358_0_1 <= 100));
  __CPROVER_assume((pub_r000358_0_2 >= (-100)) && (pub_r000358_0_2 <= 100));
  __CPROVER_assume((pub_r000358_1_1 >= (-100)) && (pub_r000358_1_1 <= 100));
  __CPROVER_assume((pub_r000358_1_2 >= (-100)) && (pub_r000358_1_2 <= 100));
  __CPROVER_assume((pub_r000358_2_1 >= (-100)) && (pub_r000358_2_1 <= 100));
  __CPROVER_assume((pub_r000358_2_2 >= (-100)) && (pub_r000358_2_2 <= 100));
  __CPROVER_assume((pub_r000358_3_1 >= (-100)) && (pub_r000358_3_1 <= 100));
  __CPROVER_assume((pub_r000358_3_2 >= (-100)) && (pub_r000358_3_2 <= 100));
  __CPROVER_assume((pub_r000358_4_1 >= (-100)) && (pub_r000358_4_1 <= 100));
  __CPROVER_assume((pub_r000358_4_2 >= (-100)) && (pub_r000358_4_2 <= 100));
  __CPROVER_assume((pub_r000358_5_1 >= (-100)) && (pub_r000358_5_1 <= 100));
  __CPROVER_assume((pub_r000358_5_2 >= (-100)) && (pub_r000358_5_2 <= 100));
  __CPROVER_assume((pub_r000358_6_1 >= (-100)) && (pub_r000358_6_1 <= 100));
  __CPROVER_assume((pub_r000358_6_2 >= (-100)) && (pub_r000358_6_2 <= 100));
  __CPROVER_assume((pub_r000358_7_1 >= (-100)) && (pub_r000358_7_1 <= 100));
  __CPROVER_assume((pub_r000358_7_2 >= (-100)) && (pub_r000358_7_2 <= 100));
  __CPROVER_assume((pub_r000358_8_1 >= (-100)) && (pub_r000358_8_1 <= 100));
  __CPROVER_assume((pub_r000358_8_2 >= (-100)) && (pub_r000358_8_2 <= 100));
  __CPROVER_assume((pub_r000358_9_1 >= (-100)) && (pub_r000358_9_1 <= 100));
  __CPROVER_assume((pub_r000358_9_2 >= (-100)) && (pub_r000358_9_2 <= 100));
  __CPROVER_assume((pub_r000358_10_1 >= (-100)) && (pub_r000358_10_1 <= 100));
  __CPROVER_assume((pub_r000358_10_2 >= (-100)) && (pub_r000358_10_2 <= 100));
  __CPROVER_assume((pub_r000358_11_1 >= (-100)) && (pub_r000358_11_1 <= 100));
  __CPROVER_assume((pub_r000358_11_2 >= (-100)) && (pub_r000358_11_2 <= 100));
  __CPROVER_assume((pub_r000358_12_1 >= (-100)) && (pub_r000358_12_1 <= 100));
  __CPROVER_assume((pub_r000358_12_2 >= (-100)) && (pub_r000358_12_2 <= 100));
  __CPROVER_assume((pub_r000358_13_1 >= (-100)) && (pub_r000358_13_1 <= 100));
  __CPROVER_assume((pub_r000358_13_2 >= (-100)) && (pub_r000358_13_2 <= 100));
  __CPROVER_assume((pub_r000358_14_1 >= (-100)) && (pub_r000358_14_1 <= 100));
  __CPROVER_assume((pub_r000358_14_2 >= (-100)) && (pub_r000358_14_2 <= 100));
  __CPROVER_assume((pub_r000358_15_1 >= (-100)) && (pub_r000358_15_1 <= 100));
  __CPROVER_assume((pub_r000358_15_2 >= (-100)) && (pub_r000358_15_2 <= 100));
  __CPROVER_assume((sec_r000358_0_1 >= 0) && (sec_r000358_0_1 <= 255));
  __CPROVER_assume((sec_r000358_0_2 >= 0) && (sec_r000358_0_2 <= 255));
  __CPROVER_assume((sec_r000358_1_1 >= 0) && (sec_r000358_1_1 <= 255));
  __CPROVER_assume((sec_r000358_1_2 >= 0) && (sec_r000358_1_2 <= 255));
  __CPROVER_assume((sec_r000358_2_1 >= 0) && (sec_r000358_2_1 <= 255));
  __CPROVER_assume((sec_r000358_2_2 >= 0) && (sec_r000358_2_2 <= 255));
  __CPROVER_assume((sec_r000358_3_1 >= 0) && (sec_r000358_3_1 <= 255));
  __CPROVER_assume((sec_r000358_3_2 >= 0) && (sec_r000358_3_2 <= 255));
  __CPROVER_assume((sec_r000358_4_1 >= 0) && (sec_r000358_4_1 <= 255));
  __CPROVER_assume((sec_r000358_4_2 >= 0) && (sec_r000358_4_2 <= 255));
  __CPROVER_assume((sec_r000358_5_1 >= 0) && (sec_r000358_5_1 <= 255));
  __CPROVER_assume((sec_r000358_5_2 >= 0) && (sec_r000358_5_2 <= 255));
  __CPROVER_assume((sec_r000358_6_1 >= 0) && (sec_r000358_6_1 <= 255));
  __CPROVER_assume((sec_r000358_6_2 >= 0) && (sec_r000358_6_2 <= 255));
  __CPROVER_assume((sec_r000358_7_1 >= 0) && (sec_r000358_7_1 <= 255));
  __CPROVER_assume((sec_r000358_7_2 >= 0) && (sec_r000358_7_2 <= 255));
  __CPROVER_assume((sec_r000358_8_1 >= 0) && (sec_r000358_8_1 <= 255));
  __CPROVER_assume((sec_r000358_8_2 >= 0) && (sec_r000358_8_2 <= 255));
  __CPROVER_assume((sec_r000358_9_1 >= 0) && (sec_r000358_9_1 <= 255));
  __CPROVER_assume((sec_r000358_9_2 >= 0) && (sec_r000358_9_2 <= 255));
  __CPROVER_assume((sec_r000358_10_1 >= 0) && (sec_r000358_10_1 <= 255));
  __CPROVER_assume((sec_r000358_10_2 >= 0) && (sec_r000358_10_2 <= 255));
  __CPROVER_assume((sec_r000358_11_1 >= 0) && (sec_r000358_11_1 <= 255));
  __CPROVER_assume((sec_r000358_11_2 >= 0) && (sec_r000358_11_2 <= 255));
  __CPROVER_assume((sec_r000358_12_1 >= 0) && (sec_r000358_12_1 <= 255));
  __CPROVER_assume((sec_r000358_12_2 >= 0) && (sec_r000358_12_2 <= 255));
  __CPROVER_assume((sec_r000358_13_1 >= 0) && (sec_r000358_13_1 <= 255));
  __CPROVER_assume((sec_r000358_13_2 >= 0) && (sec_r000358_13_2 <= 255));
  __CPROVER_assume((sec_r000358_14_1 >= 0) && (sec_r000358_14_1 <= 255));
  __CPROVER_assume((sec_r000358_14_2 >= 0) && (sec_r000358_14_2 <= 255));
  __CPROVER_assume((sec_r000358_15_1 >= 0) && (sec_r000358_15_1 <= 255));
  __CPROVER_assume((sec_r000358_15_2 >= 0) && (sec_r000358_15_2 <= 255));
  __CPROVER_assume((sec_r000358_16_1 >= 0) && (sec_r000358_16_1 <= 255));
  __CPROVER_assume((sec_r000358_16_2 >= 0) && (sec_r000358_16_2 <= 255));
  __CPROVER_assume((sec_r000358_17_1 >= 0) && (sec_r000358_17_1 <= 255));
  __CPROVER_assume((sec_r000358_17_2 >= 0) && (sec_r000358_17_2 <= 255));
  struct FilterState_R000358_5813_0 st_var_0_1 = {0};
  struct FilterState_R000358_5813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000358_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000358_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000358_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000358_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000358_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000358_0_2 + 7) & 15;
  struct StreamBuffer_R000358_5813_1 st_var_1_1 = {0};
  struct StreamBuffer_R000358_5813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000358_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000358_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000358_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000358_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000358_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000358_0_2 + 9) & 15;
  struct CipherContext_R000358_5813_2 st_var_2_1 = {0};
  struct CipherContext_R000358_5813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000358_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000358_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000358_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000358_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000358_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000358_0_2 + 11) & 15;
  struct EventLog_R000358_5813_3 st_var_3_1 = {0};
  struct EventLog_R000358_5813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000358_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000358_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000358_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000358_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000358_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000358_0_2 + 13) & 15;
  union RegisterBank_R000358_5813_0 u_var_1;
  union RegisterBank_R000358_5813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_0_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 26)
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
  if (stage_v_4_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 26)
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
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
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

  switch (stage_v_9_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
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

  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 36)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 36)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 26)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 26)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 50)
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
  if (stage_v_23_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 50)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_15_1 & 1) == step_1)
    {
      stage_v_25_1 = ((stage_v_25_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_25_1 = ((stage_v_25_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((sec_r000358_15_2 & 1) == step_2)
    {
      stage_v_25_2 = ((stage_v_25_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_25_2 = ((stage_v_25_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_26_1 = ((stage_v_26_1 + (step_1 * 4)) + pub_r000358_1_1) & 63;
    }
    else
    {
      stage_v_26_1 = ((stage_v_26_1 + pub_r000358_4_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_26_2 = ((stage_v_26_2 + (step_2 * 4)) + pub_r000358_1_2) & 63;
    }
    else
    {
      stage_v_26_2 = ((stage_v_26_2 + pub_r000358_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_26_1 & 1) == step_1)
    {
      stage_v_27_1 = ((stage_v_27_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_27_1 = ((stage_v_27_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_26_2 & 1) == step_2)
    {
      stage_v_27_2 = ((stage_v_27_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_27_2 = ((stage_v_27_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_12_1 & 1) == step_1)
    {
      stage_v_28_1 = ((stage_v_28_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_28_1 = ((stage_v_28_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((sec_r000358_12_2 & 1) == step_2)
    {
      stage_v_28_2 = ((stage_v_28_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_28_2 = ((stage_v_28_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_29_1 = ((stage_v_29_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_29_1 = ((stage_v_29_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_29_2 = ((stage_v_29_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_29_2 = ((stage_v_29_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_30_1 = ((stage_v_30_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_30_1 = ((stage_v_30_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_30_2 = ((stage_v_30_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_30_2 = ((stage_v_30_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_13_1 & 1) == step_1)
    {
      stage_v_31_1 = ((stage_v_31_1 + (step_1 * 4)) + pub_r000358_15_1) & 63;
    }
    else
    {
      stage_v_31_1 = ((stage_v_31_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((sec_r000358_13_2 & 1) == step_2)
    {
      stage_v_31_2 = ((stage_v_31_2 + (step_2 * 4)) + pub_r000358_15_2) & 63;
    }
    else
    {
      stage_v_31_2 = ((stage_v_31_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_30_1 & 1) == step_1)
    {
      stage_v_32_1 = ((stage_v_32_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_32_1 = ((stage_v_32_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_30_2 & 1) == step_2)
    {
      stage_v_32_2 = ((stage_v_32_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_32_2 = ((stage_v_32_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_26_1 & 1) == step_1)
    {
      stage_v_33_1 = ((stage_v_33_1 + (step_1 * 4)) + pub_r000358_7_1) & 63;
    }
    else
    {
      stage_v_33_1 = ((stage_v_33_1 + pub_r000358_14_1) + 5) & 63;
    }
    if ((stage_v_26_2 & 1) == step_2)
    {
      stage_v_33_2 = ((stage_v_33_2 + (step_2 * 4)) + pub_r000358_7_2) & 63;
    }
    else
    {
      stage_v_33_2 = ((stage_v_33_2 + pub_r000358_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_34_1 = ((stage_v_34_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_34_1 = ((stage_v_34_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_34_2 = ((stage_v_34_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_34_2 = ((stage_v_34_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_35_1 = ((stage_v_35_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_35_1 = ((stage_v_35_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_35_2 = ((stage_v_35_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_35_2 = ((stage_v_35_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_26_1 & 1) == step_1)
    {
      stage_v_36_1 = ((stage_v_36_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_36_1 = ((stage_v_36_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((stage_v_26_2 & 1) == step_2)
    {
      stage_v_36_2 = ((stage_v_36_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_36_2 = ((stage_v_36_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_36_1 & 1) == step_1)
    {
      stage_v_37_1 = ((stage_v_37_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_37_1 = ((stage_v_37_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_36_2 & 1) == step_2)
    {
      stage_v_37_2 = ((stage_v_37_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_37_2 = ((stage_v_37_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_38_1 = ((stage_v_38_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_38_1 = ((stage_v_38_1 + pub_r000358_10_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_38_2 = ((stage_v_38_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_38_2 = ((stage_v_38_2 + pub_r000358_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_2_1 & 1) == step_1)
    {
      stage_v_39_1 = ((stage_v_39_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_39_1 = ((stage_v_39_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((sec_r000358_2_2 & 1) == step_2)
    {
      stage_v_39_2 = ((stage_v_39_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_39_2 = ((stage_v_39_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_32_1 & 1) == step_1)
    {
      stage_v_40_1 = ((stage_v_40_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_40_1 = ((stage_v_40_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_32_2 & 1) == step_2)
    {
      stage_v_40_2 = ((stage_v_40_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_40_2 = ((stage_v_40_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_41_1 = ((stage_v_41_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_41_1 = ((stage_v_41_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_41_2 = ((stage_v_41_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_41_2 = ((stage_v_41_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_38_1 & 1) == step_1)
    {
      stage_v_42_1 = ((stage_v_42_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_42_1 = ((stage_v_42_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_38_2 & 1) == step_2)
    {
      stage_v_42_2 = ((stage_v_42_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_42_2 = ((stage_v_42_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_11_1 & 1) == step_1)
    {
      stage_v_43_1 = ((stage_v_43_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_43_1 = ((stage_v_43_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((sec_r000358_11_2 & 1) == step_2)
    {
      stage_v_43_2 = ((stage_v_43_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_43_2 = ((stage_v_43_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_44_1 = ((stage_v_44_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_44_1 = ((stage_v_44_1 + pub_r000358_11_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_44_2 = ((stage_v_44_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_44_2 = ((stage_v_44_2 + pub_r000358_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_45_1 = ((stage_v_45_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_45_1 = ((stage_v_45_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_45_2 = ((stage_v_45_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_45_2 = ((stage_v_45_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_46_1 = ((stage_v_46_1 + (step_1 * 4)) + pub_r000358_1_1) & 63;
    }
    else
    {
      stage_v_46_1 = ((stage_v_46_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_46_2 = ((stage_v_46_2 + (step_2 * 4)) + pub_r000358_1_2) & 63;
    }
    else
    {
      stage_v_46_2 = ((stage_v_46_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_36_1 & 1) == step_1)
    {
      stage_v_47_1 = ((stage_v_47_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_47_1 = ((stage_v_47_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((stage_v_36_2 & 1) == step_2)
    {
      stage_v_47_2 = ((stage_v_47_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_47_2 = ((stage_v_47_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_41_1 & 1) == step_1)
    {
      stage_v_48_1 = ((stage_v_48_1 + (step_1 * 4)) + pub_r000358_1_1) & 63;
    }
    else
    {
      stage_v_48_1 = ((stage_v_48_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_41_2 & 1) == step_2)
    {
      stage_v_48_2 = ((stage_v_48_2 + (step_2 * 4)) + pub_r000358_1_2) & 63;
    }
    else
    {
      stage_v_48_2 = ((stage_v_48_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_29_1 & 1) == step_1)
    {
      stage_v_49_1 = ((stage_v_49_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_49_1 = ((stage_v_49_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_29_2 & 1) == step_2)
    {
      stage_v_49_2 = ((stage_v_49_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_49_2 = ((stage_v_49_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_50_1 = ((stage_v_50_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_50_1 = ((stage_v_50_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_50_2 = ((stage_v_50_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_50_2 = ((stage_v_50_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_51_1 = ((stage_v_51_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_51_1 = ((stage_v_51_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_51_2 = ((stage_v_51_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_51_2 = ((stage_v_51_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_17_1 & 1) == step_1)
    {
      stage_v_52_1 = ((stage_v_52_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_52_1 = ((stage_v_52_1 + pub_r000358_4_1) + 5) & 63;
    }
    if ((sec_r000358_17_2 & 1) == step_2)
    {
      stage_v_52_2 = ((stage_v_52_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_52_2 = ((stage_v_52_2 + pub_r000358_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_31_1 & 1) == step_1)
    {
      stage_v_53_1 = ((stage_v_53_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_53_1 = ((stage_v_53_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((stage_v_31_2 & 1) == step_2)
    {
      stage_v_53_2 = ((stage_v_53_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_53_2 = ((stage_v_53_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_54_1 = ((stage_v_54_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_54_1 = ((stage_v_54_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_54_2 = ((stage_v_54_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_54_2 = ((stage_v_54_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_2_1 & 1) == step_1)
    {
      stage_v_55_1 = ((stage_v_55_1 + (step_1 * 4)) + pub_r000358_9_1) & 63;
    }
    else
    {
      stage_v_55_1 = ((stage_v_55_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((sec_r000358_2_2 & 1) == step_2)
    {
      stage_v_55_2 = ((stage_v_55_2 + (step_2 * 4)) + pub_r000358_9_2) & 63;
    }
    else
    {
      stage_v_55_2 = ((stage_v_55_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_56_1 = ((stage_v_56_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_56_1 = ((stage_v_56_1 + pub_r000358_10_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_56_2 = ((stage_v_56_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_56_2 = ((stage_v_56_2 + pub_r000358_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_16_1 & 1) == step_1)
    {
      stage_v_57_1 = ((stage_v_57_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_57_1 = ((stage_v_57_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((sec_r000358_16_2 & 1) == step_2)
    {
      stage_v_57_2 = ((stage_v_57_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_57_2 = ((stage_v_57_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_58_1 = ((stage_v_58_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_58_1 = ((stage_v_58_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_58_2 = ((stage_v_58_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_58_2 = ((stage_v_58_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_59_1 = ((stage_v_59_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_59_1 = ((stage_v_59_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_59_2 = ((stage_v_59_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_59_2 = ((stage_v_59_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_60_1 = ((stage_v_60_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_60_1 = ((stage_v_60_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_60_2 = ((stage_v_60_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_60_2 = ((stage_v_60_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_41_1 & 1) == step_1)
    {
      stage_v_61_1 = ((stage_v_61_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_61_1 = ((stage_v_61_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((stage_v_41_2 & 1) == step_2)
    {
      stage_v_61_2 = ((stage_v_61_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_61_2 = ((stage_v_61_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_58_1 & 1) == step_1)
    {
      stage_v_62_1 = ((stage_v_62_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_62_1 = ((stage_v_62_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_58_2 & 1) == step_2)
    {
      stage_v_62_2 = ((stage_v_62_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_62_2 = ((stage_v_62_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_43_1 & 1) == step_1)
    {
      stage_v_63_1 = ((stage_v_63_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_63_1 = ((stage_v_63_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((stage_v_43_2 & 1) == step_2)
    {
      stage_v_63_2 = ((stage_v_63_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_63_2 = ((stage_v_63_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_64_1 = ((stage_v_64_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_64_1 = ((stage_v_64_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_64_2 = ((stage_v_64_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_64_2 = ((stage_v_64_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_32_1 & 1) == step_1)
    {
      stage_v_65_1 = ((stage_v_65_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_65_1 = ((stage_v_65_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_32_2 & 1) == step_2)
    {
      stage_v_65_2 = ((stage_v_65_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_65_2 = ((stage_v_65_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_7_1 & 1) == step_1)
    {
      stage_v_66_1 = ((stage_v_66_1 + (step_1 * 4)) + pub_r000358_7_1) & 63;
    }
    else
    {
      stage_v_66_1 = ((stage_v_66_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((sec_r000358_7_2 & 1) == step_2)
    {
      stage_v_66_2 = ((stage_v_66_2 + (step_2 * 4)) + pub_r000358_7_2) & 63;
    }
    else
    {
      stage_v_66_2 = ((stage_v_66_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_67_1 = ((stage_v_67_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_67_1 = ((stage_v_67_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_67_2 = ((stage_v_67_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_67_2 = ((stage_v_67_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_68_1 = ((stage_v_68_1 + (step_1 * 4)) + pub_r000358_1_1) & 63;
    }
    else
    {
      stage_v_68_1 = ((stage_v_68_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_68_2 = ((stage_v_68_2 + (step_2 * 4)) + pub_r000358_1_2) & 63;
    }
    else
    {
      stage_v_68_2 = ((stage_v_68_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_13_1 & 1) == step_1)
    {
      stage_v_69_1 = ((stage_v_69_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_69_1 = ((stage_v_69_1 + pub_r000358_10_1) + 5) & 63;
    }
    if ((sec_r000358_13_2 & 1) == step_2)
    {
      stage_v_69_2 = ((stage_v_69_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_69_2 = ((stage_v_69_2 + pub_r000358_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_51_1 & 1) == step_1)
    {
      stage_v_70_1 = ((stage_v_70_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_70_1 = ((stage_v_70_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_51_2 & 1) == step_2)
    {
      stage_v_70_2 = ((stage_v_70_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_70_2 = ((stage_v_70_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_71_1 = ((stage_v_71_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_71_1 = ((stage_v_71_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_71_2 = ((stage_v_71_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_71_2 = ((stage_v_71_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_72_1 = ((stage_v_72_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_72_1 = ((stage_v_72_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_72_2 = ((stage_v_72_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_72_2 = ((stage_v_72_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_14_1 & 1) == step_1)
    {
      stage_v_73_1 = ((stage_v_73_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_73_1 = ((stage_v_73_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((sec_r000358_14_2 & 1) == step_2)
    {
      stage_v_73_2 = ((stage_v_73_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_73_2 = ((stage_v_73_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_0_1 & 1) == step_1)
    {
      stage_v_74_1 = ((stage_v_74_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_74_1 = ((stage_v_74_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((sec_r000358_0_2 & 1) == step_2)
    {
      stage_v_74_2 = ((stage_v_74_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_74_2 = ((stage_v_74_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_75_1 = ((stage_v_75_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_75_1 = ((stage_v_75_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_75_2 = ((stage_v_75_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_75_2 = ((stage_v_75_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_57_1 & 1) == step_1)
    {
      stage_v_76_1 = ((stage_v_76_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_76_1 = ((stage_v_76_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_57_2 & 1) == step_2)
    {
      stage_v_76_2 = ((stage_v_76_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_76_2 = ((stage_v_76_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_77_1 = ((stage_v_77_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_77_1 = ((stage_v_77_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_77_2 = ((stage_v_77_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_77_2 = ((stage_v_77_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_76_1 & 1) == step_1)
    {
      stage_v_78_1 = ((stage_v_78_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_78_1 = ((stage_v_78_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_76_2 & 1) == step_2)
    {
      stage_v_78_2 = ((stage_v_78_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_78_2 = ((stage_v_78_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_67_1 & 1) == step_1)
    {
      stage_v_79_1 = ((stage_v_79_1 + (step_1 * 4)) + pub_r000358_9_1) & 63;
    }
    else
    {
      stage_v_79_1 = ((stage_v_79_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_67_2 & 1) == step_2)
    {
      stage_v_79_2 = ((stage_v_79_2 + (step_2 * 4)) + pub_r000358_9_2) & 63;
    }
    else
    {
      stage_v_79_2 = ((stage_v_79_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_29_1 & 1) == step_1)
    {
      stage_v_80_1 = ((stage_v_80_1 + (step_1 * 4)) + pub_r000358_15_1) & 63;
    }
    else
    {
      stage_v_80_1 = ((stage_v_80_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_29_2 & 1) == step_2)
    {
      stage_v_80_2 = ((stage_v_80_2 + (step_2 * 4)) + pub_r000358_15_2) & 63;
    }
    else
    {
      stage_v_80_2 = ((stage_v_80_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_81_1 = ((stage_v_81_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_81_1 = ((stage_v_81_1 + pub_r000358_10_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_81_2 = ((stage_v_81_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_81_2 = ((stage_v_81_2 + pub_r000358_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_82_1 = ((stage_v_82_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_82_1 = ((stage_v_82_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_82_2 = ((stage_v_82_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_82_2 = ((stage_v_82_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_83_1 = ((stage_v_83_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_83_1 = ((stage_v_83_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_83_2 = ((stage_v_83_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_83_2 = ((stage_v_83_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_16_1 & 1) == step_1)
    {
      stage_v_84_1 = ((stage_v_84_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_84_1 = ((stage_v_84_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((sec_r000358_16_2 & 1) == step_2)
    {
      stage_v_84_2 = ((stage_v_84_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_84_2 = ((stage_v_84_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_85_1 = ((stage_v_85_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_85_1 = ((stage_v_85_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_85_2 = ((stage_v_85_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_85_2 = ((stage_v_85_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_26_1 & 1) == step_1)
    {
      stage_v_86_1 = ((stage_v_86_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_86_1 = ((stage_v_86_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_26_2 & 1) == step_2)
    {
      stage_v_86_2 = ((stage_v_86_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_86_2 = ((stage_v_86_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_82_1 & 1) == step_1)
    {
      stage_v_87_1 = ((stage_v_87_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_87_1 = ((stage_v_87_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_82_2 & 1) == step_2)
    {
      stage_v_87_2 = ((stage_v_87_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_87_2 = ((stage_v_87_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_9_1 & 1) == step_1)
    {
      stage_v_88_1 = ((stage_v_88_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_88_1 = ((stage_v_88_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((sec_r000358_9_2 & 1) == step_2)
    {
      stage_v_88_2 = ((stage_v_88_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_88_2 = ((stage_v_88_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_0_1 & 1) == step_1)
    {
      stage_v_89_1 = ((stage_v_89_1 + (step_1 * 4)) + pub_r000358_15_1) & 63;
    }
    else
    {
      stage_v_89_1 = ((stage_v_89_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((sec_r000358_0_2 & 1) == step_2)
    {
      stage_v_89_2 = ((stage_v_89_2 + (step_2 * 4)) + pub_r000358_15_2) & 63;
    }
    else
    {
      stage_v_89_2 = ((stage_v_89_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_54_1 & 1) == step_1)
    {
      stage_v_90_1 = ((stage_v_90_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_90_1 = ((stage_v_90_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_54_2 & 1) == step_2)
    {
      stage_v_90_2 = ((stage_v_90_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_90_2 = ((stage_v_90_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_91_1 = ((stage_v_91_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_91_1 = ((stage_v_91_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_91_2 = ((stage_v_91_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_91_2 = ((stage_v_91_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_6_1 & 1) == step_1)
    {
      stage_v_92_1 = ((stage_v_92_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_92_1 = ((stage_v_92_1 + pub_r000358_4_1) + 5) & 63;
    }
    if ((sec_r000358_6_2 & 1) == step_2)
    {
      stage_v_92_2 = ((stage_v_92_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_92_2 = ((stage_v_92_2 + pub_r000358_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_62_1 & 1) == step_1)
    {
      stage_v_93_1 = ((stage_v_93_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_93_1 = ((stage_v_93_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_62_2 & 1) == step_2)
    {
      stage_v_93_2 = ((stage_v_93_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_93_2 = ((stage_v_93_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_94_1 = ((stage_v_94_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_94_1 = ((stage_v_94_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_94_2 = ((stage_v_94_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_94_2 = ((stage_v_94_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_31_1 & 1) == step_1)
    {
      stage_v_95_1 = ((stage_v_95_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_95_1 = ((stage_v_95_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((stage_v_31_2 & 1) == step_2)
    {
      stage_v_95_2 = ((stage_v_95_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_95_2 = ((stage_v_95_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_96_1 = ((stage_v_96_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_96_1 = ((stage_v_96_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_96_2 = ((stage_v_96_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_96_2 = ((stage_v_96_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_51_1 & 1) == step_1)
    {
      stage_v_97_1 = ((stage_v_97_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_97_1 = ((stage_v_97_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((stage_v_51_2 & 1) == step_2)
    {
      stage_v_97_2 = ((stage_v_97_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_97_2 = ((stage_v_97_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_12_1 & 1) == step_1)
    {
      stage_v_98_1 = ((stage_v_98_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_98_1 = ((stage_v_98_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((sec_r000358_12_2 & 1) == step_2)
    {
      stage_v_98_2 = ((stage_v_98_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_98_2 = ((stage_v_98_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_1_1 & 1) == step_1)
    {
      stage_v_99_1 = ((stage_v_99_1 + (step_1 * 4)) + pub_r000358_15_1) & 63;
    }
    else
    {
      stage_v_99_1 = ((stage_v_99_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((sec_r000358_1_2 & 1) == step_2)
    {
      stage_v_99_2 = ((stage_v_99_2 + (step_2 * 4)) + pub_r000358_15_2) & 63;
    }
    else
    {
      stage_v_99_2 = ((stage_v_99_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_27_1 & 1) == step_1)
    {
      stage_v_100_1 = ((stage_v_100_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_100_1 = ((stage_v_100_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((stage_v_27_2 & 1) == step_2)
    {
      stage_v_100_2 = ((stage_v_100_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_100_2 = ((stage_v_100_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_71_1 & 1) == step_1)
    {
      stage_v_101_1 = ((stage_v_101_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_101_1 = ((stage_v_101_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_71_2 & 1) == step_2)
    {
      stage_v_101_2 = ((stage_v_101_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_101_2 = ((stage_v_101_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_3_1 & 1) == step_1)
    {
      stage_v_102_1 = ((stage_v_102_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_102_1 = ((stage_v_102_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((sec_r000358_3_2 & 1) == step_2)
    {
      stage_v_102_2 = ((stage_v_102_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_102_2 = ((stage_v_102_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_103_1 = ((stage_v_103_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_103_1 = ((stage_v_103_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_103_2 = ((stage_v_103_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_103_2 = ((stage_v_103_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_1_1 & 1) == step_1)
    {
      stage_v_104_1 = ((stage_v_104_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_104_1 = ((stage_v_104_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((sec_r000358_1_2 & 1) == step_2)
    {
      stage_v_104_2 = ((stage_v_104_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_104_2 = ((stage_v_104_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_51_1 & 1) == step_1)
    {
      stage_v_105_1 = ((stage_v_105_1 + (step_1 * 4)) + pub_r000358_7_1) & 63;
    }
    else
    {
      stage_v_105_1 = ((stage_v_105_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_51_2 & 1) == step_2)
    {
      stage_v_105_2 = ((stage_v_105_2 + (step_2 * 4)) + pub_r000358_7_2) & 63;
    }
    else
    {
      stage_v_105_2 = ((stage_v_105_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_39_1 & 1) == step_1)
    {
      stage_v_106_1 = ((stage_v_106_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_106_1 = ((stage_v_106_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_39_2 & 1) == step_2)
    {
      stage_v_106_2 = ((stage_v_106_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_106_2 = ((stage_v_106_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_0_1 & 1) == step_1)
    {
      stage_v_107_1 = ((stage_v_107_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_107_1 = ((stage_v_107_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((sec_r000358_0_2 & 1) == step_2)
    {
      stage_v_107_2 = ((stage_v_107_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_107_2 = ((stage_v_107_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_108_1 = ((stage_v_108_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_108_1 = ((stage_v_108_1 + pub_r000358_11_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_108_2 = ((stage_v_108_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_108_2 = ((stage_v_108_2 + pub_r000358_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_59_1 & 1) == step_1)
    {
      stage_v_109_1 = ((stage_v_109_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_109_1 = ((stage_v_109_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_59_2 & 1) == step_2)
    {
      stage_v_109_2 = ((stage_v_109_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_109_2 = ((stage_v_109_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_105_1 & 1) == step_1)
    {
      stage_v_110_1 = ((stage_v_110_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_110_1 = ((stage_v_110_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_105_2 & 1) == step_2)
    {
      stage_v_110_2 = ((stage_v_110_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_110_2 = ((stage_v_110_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_111_1 = ((stage_v_111_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_111_1 = ((stage_v_111_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_111_2 = ((stage_v_111_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_111_2 = ((stage_v_111_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_55_1 & 1) == step_1)
    {
      stage_v_112_1 = ((stage_v_112_1 + (step_1 * 4)) + pub_r000358_9_1) & 63;
    }
    else
    {
      stage_v_112_1 = ((stage_v_112_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_55_2 & 1) == step_2)
    {
      stage_v_112_2 = ((stage_v_112_2 + (step_2 * 4)) + pub_r000358_9_2) & 63;
    }
    else
    {
      stage_v_112_2 = ((stage_v_112_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_10_1 & 1) == step_1)
    {
      stage_v_113_1 = ((stage_v_113_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_113_1 = ((stage_v_113_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((sec_r000358_10_2 & 1) == step_2)
    {
      stage_v_113_2 = ((stage_v_113_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_113_2 = ((stage_v_113_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_39_1 & 1) == step_1)
    {
      stage_v_114_1 = ((stage_v_114_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_114_1 = ((stage_v_114_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_39_2 & 1) == step_2)
    {
      stage_v_114_2 = ((stage_v_114_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_114_2 = ((stage_v_114_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_108_1 & 1) == step_1)
    {
      stage_v_115_1 = ((stage_v_115_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_115_1 = ((stage_v_115_1 + pub_r000358_4_1) + 5) & 63;
    }
    if ((stage_v_108_2 & 1) == step_2)
    {
      stage_v_115_2 = ((stage_v_115_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_115_2 = ((stage_v_115_2 + pub_r000358_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_113_1 & 1) == step_1)
    {
      stage_v_116_1 = ((stage_v_116_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_116_1 = ((stage_v_116_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_113_2 & 1) == step_2)
    {
      stage_v_116_2 = ((stage_v_116_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_116_2 = ((stage_v_116_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_54_1 & 1) == step_1)
    {
      stage_v_117_1 = ((stage_v_117_1 + (step_1 * 4)) + pub_r000358_10_1) & 63;
    }
    else
    {
      stage_v_117_1 = ((stage_v_117_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_54_2 & 1) == step_2)
    {
      stage_v_117_2 = ((stage_v_117_2 + (step_2 * 4)) + pub_r000358_10_2) & 63;
    }
    else
    {
      stage_v_117_2 = ((stage_v_117_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_15_1 & 1) == step_1)
    {
      stage_v_118_1 = ((stage_v_118_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_118_1 = ((stage_v_118_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((sec_r000358_15_2 & 1) == step_2)
    {
      stage_v_118_2 = ((stage_v_118_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_118_2 = ((stage_v_118_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_119_1 = ((stage_v_119_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_119_1 = ((stage_v_119_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_119_2 = ((stage_v_119_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_119_2 = ((stage_v_119_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_118_1 & 1) == step_1)
    {
      stage_v_120_1 = ((stage_v_120_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_120_1 = ((stage_v_120_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_118_2 & 1) == step_2)
    {
      stage_v_120_2 = ((stage_v_120_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_120_2 = ((stage_v_120_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_121_1 = ((stage_v_121_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_121_1 = ((stage_v_121_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_121_2 = ((stage_v_121_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_121_2 = ((stage_v_121_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_74_1 & 1) == step_1)
    {
      stage_v_122_1 = ((stage_v_122_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_122_1 = ((stage_v_122_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((stage_v_74_2 & 1) == step_2)
    {
      stage_v_122_2 = ((stage_v_122_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_122_2 = ((stage_v_122_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_123_1 = ((stage_v_123_1 + (step_1 * 4)) + pub_r000358_9_1) & 63;
    }
    else
    {
      stage_v_123_1 = ((stage_v_123_1 + pub_r000358_10_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_123_2 = ((stage_v_123_2 + (step_2 * 4)) + pub_r000358_9_2) & 63;
    }
    else
    {
      stage_v_123_2 = ((stage_v_123_2 + pub_r000358_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_65_1 & 1) == step_1)
    {
      stage_v_124_1 = ((stage_v_124_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_124_1 = ((stage_v_124_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_65_2 & 1) == step_2)
    {
      stage_v_124_2 = ((stage_v_124_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_124_2 = ((stage_v_124_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_125_1 = ((stage_v_125_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_125_1 = ((stage_v_125_1 + pub_r000358_14_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_125_2 = ((stage_v_125_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_125_2 = ((stage_v_125_2 + pub_r000358_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_11_1 & 1) == step_1)
    {
      stage_v_126_1 = ((stage_v_126_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_126_1 = ((stage_v_126_1 + pub_r000358_0_1) + 5) & 63;
    }
    if ((sec_r000358_11_2 & 1) == step_2)
    {
      stage_v_126_2 = ((stage_v_126_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_126_2 = ((stage_v_126_2 + pub_r000358_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_46_1 & 1) == step_1)
    {
      stage_v_127_1 = ((stage_v_127_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_127_1 = ((stage_v_127_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_46_2 & 1) == step_2)
    {
      stage_v_127_2 = ((stage_v_127_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_127_2 = ((stage_v_127_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_103_1 & 1) == step_1)
    {
      stage_v_128_1 = ((stage_v_128_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_128_1 = ((stage_v_128_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_103_2 & 1) == step_2)
    {
      stage_v_128_2 = ((stage_v_128_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_128_2 = ((stage_v_128_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_124_1 & 1) == step_1)
    {
      stage_v_129_1 = ((stage_v_129_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_129_1 = ((stage_v_129_1 + pub_r000358_11_1) + 5) & 63;
    }
    if ((stage_v_124_2 & 1) == step_2)
    {
      stage_v_129_2 = ((stage_v_129_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_129_2 = ((stage_v_129_2 + pub_r000358_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_63_1 & 1) == step_1)
    {
      stage_v_130_1 = ((stage_v_130_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_130_1 = ((stage_v_130_1 + pub_r000358_13_1) + 5) & 63;
    }
    if ((stage_v_63_2 & 1) == step_2)
    {
      stage_v_130_2 = ((stage_v_130_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_130_2 = ((stage_v_130_2 + pub_r000358_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_131_1 = ((stage_v_131_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_131_1 = ((stage_v_131_1 + pub_r000358_15_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_131_2 = ((stage_v_131_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_131_2 = ((stage_v_131_2 + pub_r000358_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_132_1 = ((stage_v_132_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_132_1 = ((stage_v_132_1 + pub_r000358_6_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_132_2 = ((stage_v_132_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_132_2 = ((stage_v_132_2 + pub_r000358_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_11_1 & 1) == step_1)
    {
      stage_v_133_1 = ((stage_v_133_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_133_1 = ((stage_v_133_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((sec_r000358_11_2 & 1) == step_2)
    {
      stage_v_133_2 = ((stage_v_133_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_133_2 = ((stage_v_133_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_57_1 & 1) == step_1)
    {
      stage_v_134_1 = ((stage_v_134_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_134_1 = ((stage_v_134_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((stage_v_57_2 & 1) == step_2)
    {
      stage_v_134_2 = ((stage_v_134_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_134_2 = ((stage_v_134_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_8_1 & 1) == step_1)
    {
      stage_v_135_1 = ((stage_v_135_1 + (step_1 * 4)) + pub_r000358_12_1) & 63;
    }
    else
    {
      stage_v_135_1 = ((stage_v_135_1 + pub_r000358_11_1) + 5) & 63;
    }
    if ((sec_r000358_8_2 & 1) == step_2)
    {
      stage_v_135_2 = ((stage_v_135_2 + (step_2 * 4)) + pub_r000358_12_2) & 63;
    }
    else
    {
      stage_v_135_2 = ((stage_v_135_2 + pub_r000358_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_126_1 & 1) == step_1)
    {
      stage_v_136_1 = ((stage_v_136_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_136_1 = ((stage_v_136_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_126_2 & 1) == step_2)
    {
      stage_v_136_2 = ((stage_v_136_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_136_2 = ((stage_v_136_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_14_1 & 1) == step_1)
    {
      stage_v_137_1 = ((stage_v_137_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_137_1 = ((stage_v_137_1 + pub_r000358_14_1) + 5) & 63;
    }
    if ((sec_r000358_14_2 & 1) == step_2)
    {
      stage_v_137_2 = ((stage_v_137_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_137_2 = ((stage_v_137_2 + pub_r000358_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_12_1 & 1) == step_1)
    {
      stage_v_138_1 = ((stage_v_138_1 + (step_1 * 4)) + pub_r000358_8_1) & 63;
    }
    else
    {
      stage_v_138_1 = ((stage_v_138_1 + pub_r000358_2_1) + 5) & 63;
    }
    if ((sec_r000358_12_2 & 1) == step_2)
    {
      stage_v_138_2 = ((stage_v_138_2 + (step_2 * 4)) + pub_r000358_8_2) & 63;
    }
    else
    {
      stage_v_138_2 = ((stage_v_138_2 + pub_r000358_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_122_1 & 1) == step_1)
    {
      stage_v_139_1 = ((stage_v_139_1 + (step_1 * 4)) + pub_r000358_9_1) & 63;
    }
    else
    {
      stage_v_139_1 = ((stage_v_139_1 + pub_r000358_11_1) + 5) & 63;
    }
    if ((stage_v_122_2 & 1) == step_2)
    {
      stage_v_139_2 = ((stage_v_139_2 + (step_2 * 4)) + pub_r000358_9_2) & 63;
    }
    else
    {
      stage_v_139_2 = ((stage_v_139_2 + pub_r000358_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_136_1 & 1) == step_1)
    {
      stage_v_140_1 = ((stage_v_140_1 + (step_1 * 4)) + pub_r000358_3_1) & 63;
    }
    else
    {
      stage_v_140_1 = ((stage_v_140_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((stage_v_136_2 & 1) == step_2)
    {
      stage_v_140_2 = ((stage_v_140_2 + (step_2 * 4)) + pub_r000358_3_2) & 63;
    }
    else
    {
      stage_v_140_2 = ((stage_v_140_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_11_1 & 1) == step_1)
    {
      stage_v_141_1 = ((stage_v_141_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_141_1 = ((stage_v_141_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((sec_r000358_11_2 & 1) == step_2)
    {
      stage_v_141_2 = ((stage_v_141_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_141_2 = ((stage_v_141_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_16_1 & 1) == step_1)
    {
      stage_v_142_1 = ((stage_v_142_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_142_1 = ((stage_v_142_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((sec_r000358_16_2 & 1) == step_2)
    {
      stage_v_142_2 = ((stage_v_142_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_142_2 = ((stage_v_142_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_55_1 & 1) == step_1)
    {
      stage_v_143_1 = ((stage_v_143_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_143_1 = ((stage_v_143_1 + pub_r000358_5_1) + 5) & 63;
    }
    if ((stage_v_55_2 & 1) == step_2)
    {
      stage_v_143_2 = ((stage_v_143_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_143_2 = ((stage_v_143_2 + pub_r000358_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_89_1 & 1) == step_1)
    {
      stage_v_144_1 = ((stage_v_144_1 + (step_1 * 4)) + pub_r000358_14_1) & 63;
    }
    else
    {
      stage_v_144_1 = ((stage_v_144_1 + pub_r000358_3_1) + 5) & 63;
    }
    if ((stage_v_89_2 & 1) == step_2)
    {
      stage_v_144_2 = ((stage_v_144_2 + (step_2 * 4)) + pub_r000358_14_2) & 63;
    }
    else
    {
      stage_v_144_2 = ((stage_v_144_2 + pub_r000358_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_122_1 & 1) == step_1)
    {
      stage_v_145_1 = ((stage_v_145_1 + (step_1 * 4)) + pub_r000358_13_1) & 63;
    }
    else
    {
      stage_v_145_1 = ((stage_v_145_1 + pub_r000358_7_1) + 5) & 63;
    }
    if ((stage_v_122_2 & 1) == step_2)
    {
      stage_v_145_2 = ((stage_v_145_2 + (step_2 * 4)) + pub_r000358_13_2) & 63;
    }
    else
    {
      stage_v_145_2 = ((stage_v_145_2 + pub_r000358_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_137_1 & 1) == step_1)
    {
      stage_v_146_1 = ((stage_v_146_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_146_1 = ((stage_v_146_1 + pub_r000358_9_1) + 5) & 63;
    }
    if ((stage_v_137_2 & 1) == step_2)
    {
      stage_v_146_2 = ((stage_v_146_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_146_2 = ((stage_v_146_2 + pub_r000358_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_12_1 & 1) == step_1)
    {
      stage_v_147_1 = ((stage_v_147_1 + (step_1 * 4)) + pub_r000358_2_1) & 63;
    }
    else
    {
      stage_v_147_1 = ((stage_v_147_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((sec_r000358_12_2 & 1) == step_2)
    {
      stage_v_147_2 = ((stage_v_147_2 + (step_2 * 4)) + pub_r000358_2_2) & 63;
    }
    else
    {
      stage_v_147_2 = ((stage_v_147_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_77_1 & 1) == step_1)
    {
      stage_v_148_1 = ((stage_v_148_1 + (step_1 * 4)) + pub_r000358_4_1) & 63;
    }
    else
    {
      stage_v_148_1 = ((stage_v_148_1 + pub_r000358_4_1) + 5) & 63;
    }
    if ((stage_v_77_2 & 1) == step_2)
    {
      stage_v_148_2 = ((stage_v_148_2 + (step_2 * 4)) + pub_r000358_4_2) & 63;
    }
    else
    {
      stage_v_148_2 = ((stage_v_148_2 + pub_r000358_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_83_1 & 1) == step_1)
    {
      stage_v_149_1 = ((stage_v_149_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_149_1 = ((stage_v_149_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_83_2 & 1) == step_2)
    {
      stage_v_149_2 = ((stage_v_149_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_149_2 = ((stage_v_149_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_105_1 & 1) == step_1)
    {
      stage_v_150_1 = ((stage_v_150_1 + (step_1 * 4)) + pub_r000358_0_1) & 63;
    }
    else
    {
      stage_v_150_1 = ((stage_v_150_1 + pub_r000358_1_1) + 5) & 63;
    }
    if ((stage_v_105_2 & 1) == step_2)
    {
      stage_v_150_2 = ((stage_v_150_2 + (step_2 * 4)) + pub_r000358_0_2) & 63;
    }
    else
    {
      stage_v_150_2 = ((stage_v_150_2 + pub_r000358_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_151_1 = ((stage_v_151_1 + (step_1 * 4)) + pub_r000358_5_1) & 63;
    }
    else
    {
      stage_v_151_1 = ((stage_v_151_1 + pub_r000358_12_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_151_2 = ((stage_v_151_2 + (step_2 * 4)) + pub_r000358_5_2) & 63;
    }
    else
    {
      stage_v_151_2 = ((stage_v_151_2 + pub_r000358_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_17_1 & 1) == step_1)
    {
      stage_v_152_1 = ((stage_v_152_1 + (step_1 * 4)) + pub_r000358_6_1) & 63;
    }
    else
    {
      stage_v_152_1 = ((stage_v_152_1 + pub_r000358_14_1) + 5) & 63;
    }
    if ((sec_r000358_17_2 & 1) == step_2)
    {
      stage_v_152_2 = ((stage_v_152_2 + (step_2 * 4)) + pub_r000358_6_2) & 63;
    }
    else
    {
      stage_v_152_2 = ((stage_v_152_2 + pub_r000358_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000358_10_1 & 1) == step_1)
    {
      stage_v_153_1 = ((stage_v_153_1 + (step_1 * 4)) + pub_r000358_11_1) & 63;
    }
    else
    {
      stage_v_153_1 = ((stage_v_153_1 + pub_r000358_8_1) + 5) & 63;
    }
    if ((sec_r000358_10_2 & 1) == step_2)
    {
      stage_v_153_2 = ((stage_v_153_2 + (step_2 * 4)) + pub_r000358_11_2) & 63;
    }
    else
    {
      stage_v_153_2 = ((stage_v_153_2 + pub_r000358_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000358_3_1 != sec_r000358_3_2);
  __CPROVER_assume(sec_r000358_15_1 != sec_r000358_15_2);
  __CPROVER_assume(pub_r000358_0_1 == pub_r000358_0_2);
  __CPROVER_assume(pub_r000358_9_1 == pub_r000358_9_2);
  __CPROVER_assume(pub_r000358_11_1 == pub_r000358_11_2);
  __CPROVER_assume(pub_r000358_5_1 == pub_r000358_5_2);
  __CPROVER_assume(pub_r000358_13_1 == pub_r000358_13_2);
  __CPROVER_assume(pub_r000358_4_1 == pub_r000358_4_2);
  __CPROVER_assume(sec_r000358_0_1 != sec_r000358_0_2);
  __CPROVER_assume(pub_r000358_12_1 == pub_r000358_12_2);
  __CPROVER_assume(sec_r000358_12_1 != sec_r000358_12_2);
  __CPROVER_assume(sec_r000358_6_1 != sec_r000358_6_2);
  __CPROVER_assume(pub_r000358_1_1 == pub_r000358_1_2);
  __CPROVER_assume(pub_r000358_2_1 == pub_r000358_2_2);
  __CPROVER_assume(sec_r000358_9_1 != sec_r000358_9_2);
  __CPROVER_assume(sec_r000358_5_1 != sec_r000358_5_2);
  __CPROVER_assume(sec_r000358_1_1 != sec_r000358_1_2);
  __CPROVER_assume(sec_r000358_8_1 != sec_r000358_8_2);
  __CPROVER_assume(pub_r000358_15_1 == pub_r000358_15_2);
  __CPROVER_assume(pub_r000358_14_1 == pub_r000358_14_2);
  __CPROVER_assume(sec_r000358_17_1 != sec_r000358_17_2);
  __CPROVER_assume(sec_r000358_11_1 != sec_r000358_11_2);
  __CPROVER_assume(pub_r000358_3_1 == pub_r000358_3_2);
  __CPROVER_assume(pub_r000358_7_1 == pub_r000358_7_2);
  __CPROVER_assume(sec_r000358_13_1 != sec_r000358_13_2);
  __CPROVER_assume(sec_r000358_2_1 != sec_r000358_2_2);
  __CPROVER_assume(sec_r000358_4_1 != sec_r000358_4_2);
  __CPROVER_assume(pub_r000358_6_1 == pub_r000358_6_2);
  __CPROVER_assume(pub_r000358_8_1 == pub_r000358_8_2);
  __CPROVER_assume(sec_r000358_14_1 != sec_r000358_14_2);
  __CPROVER_assume(sec_r000358_10_1 != sec_r000358_10_2);
  __CPROVER_assume(sec_r000358_16_1 != sec_r000358_16_2);
  __CPROVER_assume(pub_r000358_10_1 == pub_r000358_10_2);
  __CPROVER_assume(sec_r000358_7_1 != sec_r000358_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.severity == st_var_3_2.severity);
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
  assert(stage_v_139_1 == stage_v_139_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(stage_v_153_1 == stage_v_153_2);
}


