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
struct CipherContext_R000117_1713_0
{
  unsigned char flags;
  int round_key;
  unsigned char tag;
  int nonce;
  int buffer[3];
};
struct EventLog_R000117_1713_1
{
  int code;
  short facility;
  unsigned char signature;
  int timestamp;
  int severity;
  int seq;
  int buffer[3];
};
union TelemetryField_R000117_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000117_1713_1
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
void fn_R000117_1713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_31_1 = local_arr_1[aux_1 % 3];
  int bound_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_92_1 > 30)
  {
    acc_1 = ((acc_1 + (tally_92_1 * 2)) + 5) & 127;
    aux_1 ^= tally_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_92_2 > 30)
  {
    acc_2 = ((acc_2 + (tally_92_2 * 2)) + 5) & 127;
    aux_2 ^= tally_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_50_1)
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

  switch (cursor_50_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_31_1 == bound_31_2);
  assert(tally_92_1 == tally_92_2);
  assert(cursor_50_1 == cursor_50_2);
}

int fn_R000117_1713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int bound_31 = local_arr[aux % 3];
  acc = (acc + (bound_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_92 > 30)
  {
    acc = ((acc + (tally_92 * 2)) + 5) & 127;
    aux ^= tally_92 & 15;
  }
  else
  {
    acc = ((acc - tally_92) + 11) & 127;
    aux += 3;
  }
  int cursor_50 = (aux + st.buffer[1]) & 3;
  switch (cursor_50)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_51_1) & 63;
  aux_2 = (aux_2 + sample_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_71_1 = local_arr_1[aux_1 % 3];
  int pivot_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_71_2 * 2)) & 127;
  int quotient_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_93_1)
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

  switch (quotient_93_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_51_1 == sample_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_71_1 == pivot_71_2);
  assert(quotient_93_1 == quotient_93_2);
}

int fn_R000117_1713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_51) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_71 = local_arr[aux % 3];
  acc = (acc + (pivot_71 * 2)) & 127;
  int quotient_93 = (aux + st.buffer[1]) & 3;
  switch (quotient_93)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_16_1 = local_arr_1[aux_1 % 3];
  int tally_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_16_2 * 2)) & 127;
  int window_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_80_1)
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

  switch (window_80_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_16_1 == tally_16_2);
  assert(window_80_1 == window_80_2);
}

int fn_R000117_1713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int tally_16 = local_arr[aux % 3];
  acc = (acc + (tally_16 * 2)) & 127;
  int window_80 = (aux + st.buffer[1]) & 3;
  switch (window_80)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_43_1) & 63;
  aux_2 = (aux_2 + stride_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_99_1)
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

  switch (vector_99_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  assert(vector_99_1 == vector_99_2);
}

int fn_R000117_1713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_43) & 63;
  acc ^= aux;
  int vector_99 = (aux + st.buffer[1]) & 3;
  switch (vector_99)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_33_1) & 63;
  aux_2 = (aux_2 + index_reg_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_75_1)
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

  switch (scale_75_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_84_1 = local_arr_1[aux_1 % 3];
  int weight_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
  assert(scale_75_1 == scale_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_84_1 == weight_84_2);
}

int fn_R000117_1713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_33) & 63;
  acc ^= aux;
  int scale_75 = (aux + st.buffer[1]) & 3;
  switch (scale_75)
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

  int local_arr[3] = {4, 9, 15};
  int weight_84 = local_arr[aux % 3];
  acc = (acc + (weight_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int factor_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_72_1 > 13)
  {
    acc_1 = ((acc_1 + (factor_72_1 * 2)) + 5) & 127;
    aux_1 ^= factor_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_72_2 > 13)
  {
    acc_2 = ((acc_2 + (factor_72_2 * 2)) + 5) & 127;
    aux_2 ^= factor_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_15_1)
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

  switch (vector_15_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_72_1 == factor_72_2);
  assert(vector_15_1 == vector_15_2);
}

int fn_R000117_1713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int factor_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_72 > 13)
  {
    acc = ((acc + (factor_72 * 2)) + 5) & 127;
    aux ^= factor_72 & 15;
  }
  else
  {
    acc = ((acc - factor_72) + 11) & 127;
    aux += 3;
  }
  int vector_15 = (aux + st.buffer[1]) & 3;
  switch (vector_15)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int anchor_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_82_1) & 63;
  aux_2 = (aux_2 + anchor_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_66_1)
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

  switch (damping_66_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_82_1 == anchor_82_2);
  assert(damping_66_1 == damping_66_2);
}

int fn_R000117_1713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int anchor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_66 = (aux + st.buffer[1]) & 3;
  switch (damping_66)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_96_1 = local_arr_1[aux_1 % 3];
  int checksum_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_96_2 * 2)) & 127;
  int threshold_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_97_1 > 25)
  {
    acc_1 = ((acc_1 + (threshold_97_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_97_2 > 25)
  {
    acc_2 = ((acc_2 + (threshold_97_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_48_1)
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

  switch (window_48_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_96_1 == checksum_96_2);
  assert(threshold_97_1 == threshold_97_2);
  assert(window_48_1 == window_48_2);
}

int fn_R000117_1713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_96 = local_arr[aux % 3];
  acc = (acc + (checksum_96 * 2)) & 127;
  int threshold_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_97 > 25)
  {
    acc = ((acc + (threshold_97 * 2)) + 5) & 127;
    aux ^= threshold_97 & 15;
  }
  else
  {
    acc = ((acc - threshold_97) + 11) & 127;
    aux += 3;
  }
  int window_48 = (aux + st.buffer[1]) & 3;
  switch (window_48)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_55_1 > 20)
  {
    acc_1 = ((acc_1 + (window_55_1 * 2)) + 5) & 127;
    aux_1 ^= window_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_55_2 > 20)
  {
    acc_2 = ((acc_2 + (window_55_2 * 2)) + 5) & 127;
    aux_2 ^= window_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_81_1 = local_arr_1[aux_1 % 3];
  int quotient_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_32_1) & 63;
  aux_2 = (aux_2 + offset_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_55_1 == window_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_81_1 == quotient_81_2);
  assert(offset_32_1 == offset_32_2);
}

int fn_R000117_1713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_55 > 20)
  {
    acc = ((acc + (window_55 * 2)) + 5) & 127;
    aux ^= window_55 & 15;
  }
  else
  {
    acc = ((acc - window_55) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_81 = local_arr[aux % 3];
  acc = (acc + (quotient_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000117_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_94_1) & 63;
  aux_2 = (aux_2 + margin_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_48_1 > 44)
  {
    acc_1 = ((acc_1 + (bound_48_1 * 2)) + 5) & 127;
    aux_1 ^= bound_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_48_2 > 44)
  {
    acc_2 = ((acc_2 + (bound_48_2 * 2)) + 5) & 127;
    aux_2 ^= bound_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_52_1 = local_arr_1[aux_1 % 3];
  int vector_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_52_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_94_1 == margin_94_2);
  assert(bound_48_1 == bound_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_52_1 == vector_52_2);
}

int fn_R000117_1713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_94) & 63;
  acc ^= aux;
  int bound_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_48 > 44)
  {
    acc = ((acc + (bound_48 * 2)) + 5) & 127;
    aux ^= bound_48 & 15;
  }
  else
  {
    acc = ((acc - bound_48) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_52 = local_arr[aux % 3];
  acc = (acc + (vector_52 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_41_1)
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

  switch (index_reg_41_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_41_1 == index_reg_41_2);
}

int fn_R000117_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_41 = (aux + st.buffer[1]) & 3;
  switch (index_reg_41)
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

void fn_R000117_1713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_23_1 = local_arr_1[aux_1 % 3];
  int tracker_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_23_2 * 2)) & 127;
  int pivot_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_41_1) & 63;
  aux_2 = (aux_2 + pivot_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_14_1 > 36)
  {
    acc_1 = ((acc_1 + (checksum_14_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_14_2 > 36)
  {
    acc_2 = ((acc_2 + (checksum_14_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_14_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_23_1 == tracker_23_2);
  assert(pivot_41_1 == pivot_41_2);
  assert(checksum_14_1 == checksum_14_2);
}

int fn_R000117_1713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int tracker_23 = local_arr[aux % 3];
  acc = (acc + (tracker_23 * 2)) & 127;
  int pivot_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_41) & 63;
  acc ^= aux;
  int checksum_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_14 > 36)
  {
    acc = ((acc + (checksum_14 * 2)) + 5) & 127;
    aux ^= checksum_14 & 15;
  }
  else
  {
    acc = ((acc - checksum_14) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_41_1 = local_arr_1[aux_1 % 3];
  int index_reg_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_41_2 * 2)) & 127;
  int segment_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_69_1)
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

  switch (segment_69_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_41_1 == index_reg_41_2);
  assert(segment_69_1 == segment_69_2);
}

int fn_R000117_1713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_41 = local_arr[aux % 3];
  acc = (acc + (index_reg_41 * 2)) & 127;
  int segment_69 = (aux + st.buffer[1]) & 3;
  switch (segment_69)
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

void fn_R000117_1713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int residue_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_67_1)
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

  switch (residue_67_2)
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
  int residue_59_1 = local_arr_1[aux_1 % 3];
  int residue_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_59_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_67_1 == residue_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_59_1 == residue_59_2);
}

int fn_R000117_1713_13(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int residue_67 = (aux + st.buffer[1]) & 3;
  switch (residue_67)
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
  int residue_59 = local_arr[aux % 3];
  acc = (acc + (residue_59 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_57_1 = local_arr_1[aux_1 % 3];
  int segment_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_57_2 * 2)) & 127;
  int delta_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_87_1)
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

  switch (delta_87_2)
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

  int anchor_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_58_1) & 63;
  aux_2 = (aux_2 + anchor_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_57_1 == segment_57_2);
  assert(delta_87_1 == delta_87_2);
  assert(anchor_58_1 == anchor_58_2);
}

int fn_R000117_1713_14(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int segment_57 = local_arr[aux % 3];
  acc = (acc + (segment_57 * 2)) & 127;
  int delta_87 = (aux + st.buffer[1]) & 3;
  switch (delta_87)
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

  int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000117_1713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_54_1)
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

  switch (mask_54_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_60_1 = local_arr_1[aux_1 % 3];
  int quotient_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_60_2 * 2)) & 127;
  int segment_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_39_1) & 63;
  aux_2 = (aux_2 + segment_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_54_1 == mask_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_60_1 == quotient_60_2);
  assert(segment_39_1 == segment_39_2);
}

int fn_R000117_1713_15(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_54 = (aux + st.buffer[1]) & 3;
  switch (mask_54)
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

  int local_arr[3] = {4, 9, 15};
  int quotient_60 = local_arr[aux % 3];
  acc = (acc + (quotient_60 * 2)) & 127;
  int segment_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000117_1713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quotient_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_94_1) & 63;
  aux_2 = (aux_2 + quotient_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_50_1 = local_arr_1[aux_1 % 3];
  int tracker_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_94_1 == quotient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_50_1 == tracker_50_2);
}

int fn_R000117_1713_16(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quotient_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_94) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_50 = local_arr[aux % 3];
  acc = (acc + (tracker_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_65_1)
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

  switch (scale_65_2)
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

  int parity_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_44_1 > 47)
  {
    acc_1 = ((acc_1 + (parity_44_1 * 2)) + 5) & 127;
    aux_1 ^= parity_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_44_2 > 47)
  {
    acc_2 = ((acc_2 + (parity_44_2 * 2)) + 5) & 127;
    aux_2 ^= parity_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_87_1) & 63;
  aux_2 = (aux_2 + residue_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_65_1 == scale_65_2);
  assert(parity_44_1 == parity_44_2);
  assert(residue_87_1 == residue_87_2);
}

int fn_R000117_1713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_65 = (aux + st.buffer[1]) & 3;
  switch (scale_65)
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

  int parity_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_44 > 47)
  {
    acc = ((acc + (parity_44 * 2)) + 5) & 127;
    aux ^= parity_44 & 15;
  }
  else
  {
    acc = ((acc - parity_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000117_1713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tracker_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_17_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_17_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_17_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_17_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_84_1 = local_arr_1[aux_1 % 3];
  int factor_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_48_1) & 63;
  aux_2 = (aux_2 + quotient_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_17_1 == tracker_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_84_1 == factor_84_2);
  assert(quotient_48_1 == quotient_48_2);
}

int fn_R000117_1713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tracker_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_17 > 45)
  {
    acc = ((acc + (tracker_17 * 2)) + 5) & 127;
    aux ^= tracker_17 & 15;
  }
  else
  {
    acc = ((acc - tracker_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_84 = local_arr[aux % 3];
  acc = (acc + (factor_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000117_1713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_12_1 = local_arr_1[aux_1 % 3];
  int anchor_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_12_2 * 2)) & 127;
  int index_reg_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_27_1)
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

  switch (index_reg_27_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_12_1 == anchor_12_2);
  assert(index_reg_27_1 == index_reg_27_2);
}

int fn_R000117_1713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int anchor_12 = local_arr[aux % 3];
  acc = (acc + (anchor_12 * 2)) & 127;
  int index_reg_27 = (aux + st.buffer[1]) & 3;
  switch (index_reg_27)
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

  return (acc + aux) & 255;
}

void fn_R000117_1713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st_1 = {0};
  struct CipherContext_R000117_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_74_1) & 63;
  aux_2 = (aux_2 + scale_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_40_1 = local_arr_1[aux_1 % 3];
  int delta_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_74_1 == scale_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_40_1 == delta_40_2);
}

int fn_R000117_1713_20(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000117_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_40 = local_arr[aux % 3];
  acc = (acc + (delta_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000117_1713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st_1 = {0};
  struct EventLog_R000117_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_57_1 > 36)
  {
    acc_1 = ((acc_1 + (phase_57_1 * 2)) + 5) & 127;
    aux_1 ^= phase_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_57_2 > 36)
  {
    acc_2 = ((acc_2 + (phase_57_2 * 2)) + 5) & 127;
    aux_2 ^= phase_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_57_1 == phase_57_2);
}

int fn_R000117_1713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000117_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_57 > 36)
  {
    acc = ((acc + (phase_57 * 2)) + 5) & 127;
    aux ^= phase_57 & 15;
  }
  else
  {
    acc = ((acc - phase_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000117_0_1;
  int sec_r000117_0_2;
  int sec_r000117_1_1;
  int sec_r000117_1_2;
  int sec_r000117_2_1;
  int sec_r000117_2_2;
  int sec_r000117_3_1;
  int sec_r000117_3_2;
  int sec_r000117_4_1;
  int sec_r000117_4_2;
  int sec_r000117_5_1;
  int sec_r000117_5_2;
  int sec_r000117_6_1;
  int sec_r000117_6_2;
  int sec_r000117_7_1;
  int sec_r000117_7_2;
  int sec_r000117_8_1;
  int sec_r000117_8_2;
  int sec_r000117_9_1;
  int sec_r000117_9_2;
  int sec_r000117_10_1;
  int sec_r000117_10_2;
  int sec_r000117_11_1;
  int sec_r000117_11_2;
  int sec_r000117_12_1;
  int sec_r000117_12_2;
  int sec_r000117_13_1;
  int sec_r000117_13_2;
  int sec_r000117_14_1;
  int sec_r000117_14_2;
  int sec_r000117_15_1;
  int sec_r000117_15_2;
  int sec_r000117_16_1;
  int sec_r000117_16_2;
  int sec_r000117_17_1;
  int sec_r000117_17_2;
  int sec_r000117_18_1;
  int sec_r000117_18_2;
  int pub_r000117_0_1;
  int pub_r000117_0_2;
  int pub_r000117_1_1;
  int pub_r000117_1_2;
  int pub_r000117_2_1;
  int pub_r000117_2_2;
  int pub_r000117_3_1;
  int pub_r000117_3_2;
  int pub_r000117_4_1;
  int pub_r000117_4_2;
  int pub_r000117_5_1;
  int pub_r000117_5_2;
  int pub_r000117_6_1;
  int pub_r000117_6_2;
  int pub_r000117_7_1;
  int pub_r000117_7_2;
  int pub_r000117_8_1;
  int pub_r000117_8_2;
  int pub_r000117_9_1;
  int pub_r000117_9_2;
  int pub_r000117_10_1;
  int pub_r000117_10_2;
  int pub_r000117_11_1;
  int pub_r000117_11_2;
  int pub_r000117_12_1;
  int pub_r000117_12_2;
  int pub_r000117_13_1;
  int pub_r000117_13_2;
  int pub_r000117_14_1;
  int pub_r000117_14_2;
  int pub_r000117_15_1;
  int pub_r000117_15_2;
  int pub_r000117_16_1;
  int pub_r000117_16_2;
  int pub_r000117_17_1;
  int pub_r000117_17_2;
  int pub_r000117_18_1;
  int pub_r000117_18_2;
  int pub_r000117_19_1;
  int pub_r000117_19_2;
  int pub_r000117_20_1;
  int pub_r000117_20_2;
  int pub_r000117_21_1;
  int pub_r000117_21_2;
  int pub_r000117_22_1;
  int pub_r000117_22_2;
  int pub_r000117_23_1;
  int pub_r000117_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000117_0_1 >= (-100)) && (pub_r000117_0_1 <= 100));
  __CPROVER_assume((pub_r000117_0_2 >= (-100)) && (pub_r000117_0_2 <= 100));
  __CPROVER_assume((pub_r000117_1_1 >= (-100)) && (pub_r000117_1_1 <= 100));
  __CPROVER_assume((pub_r000117_1_2 >= (-100)) && (pub_r000117_1_2 <= 100));
  __CPROVER_assume((pub_r000117_2_1 >= (-100)) && (pub_r000117_2_1 <= 100));
  __CPROVER_assume((pub_r000117_2_2 >= (-100)) && (pub_r000117_2_2 <= 100));
  __CPROVER_assume((pub_r000117_3_1 >= (-100)) && (pub_r000117_3_1 <= 100));
  __CPROVER_assume((pub_r000117_3_2 >= (-100)) && (pub_r000117_3_2 <= 100));
  __CPROVER_assume((pub_r000117_4_1 >= (-100)) && (pub_r000117_4_1 <= 100));
  __CPROVER_assume((pub_r000117_4_2 >= (-100)) && (pub_r000117_4_2 <= 100));
  __CPROVER_assume((pub_r000117_5_1 >= (-100)) && (pub_r000117_5_1 <= 100));
  __CPROVER_assume((pub_r000117_5_2 >= (-100)) && (pub_r000117_5_2 <= 100));
  __CPROVER_assume((pub_r000117_6_1 >= (-100)) && (pub_r000117_6_1 <= 100));
  __CPROVER_assume((pub_r000117_6_2 >= (-100)) && (pub_r000117_6_2 <= 100));
  __CPROVER_assume((pub_r000117_7_1 >= (-100)) && (pub_r000117_7_1 <= 100));
  __CPROVER_assume((pub_r000117_7_2 >= (-100)) && (pub_r000117_7_2 <= 100));
  __CPROVER_assume((pub_r000117_8_1 >= (-100)) && (pub_r000117_8_1 <= 100));
  __CPROVER_assume((pub_r000117_8_2 >= (-100)) && (pub_r000117_8_2 <= 100));
  __CPROVER_assume((pub_r000117_9_1 >= (-100)) && (pub_r000117_9_1 <= 100));
  __CPROVER_assume((pub_r000117_9_2 >= (-100)) && (pub_r000117_9_2 <= 100));
  __CPROVER_assume((pub_r000117_10_1 >= (-100)) && (pub_r000117_10_1 <= 100));
  __CPROVER_assume((pub_r000117_10_2 >= (-100)) && (pub_r000117_10_2 <= 100));
  __CPROVER_assume((pub_r000117_11_1 >= (-100)) && (pub_r000117_11_1 <= 100));
  __CPROVER_assume((pub_r000117_11_2 >= (-100)) && (pub_r000117_11_2 <= 100));
  __CPROVER_assume((pub_r000117_12_1 >= (-100)) && (pub_r000117_12_1 <= 100));
  __CPROVER_assume((pub_r000117_12_2 >= (-100)) && (pub_r000117_12_2 <= 100));
  __CPROVER_assume((pub_r000117_13_1 >= (-100)) && (pub_r000117_13_1 <= 100));
  __CPROVER_assume((pub_r000117_13_2 >= (-100)) && (pub_r000117_13_2 <= 100));
  __CPROVER_assume((pub_r000117_14_1 >= (-100)) && (pub_r000117_14_1 <= 100));
  __CPROVER_assume((pub_r000117_14_2 >= (-100)) && (pub_r000117_14_2 <= 100));
  __CPROVER_assume((pub_r000117_15_1 >= (-100)) && (pub_r000117_15_1 <= 100));
  __CPROVER_assume((pub_r000117_15_2 >= (-100)) && (pub_r000117_15_2 <= 100));
  __CPROVER_assume((pub_r000117_16_1 >= (-100)) && (pub_r000117_16_1 <= 100));
  __CPROVER_assume((pub_r000117_16_2 >= (-100)) && (pub_r000117_16_2 <= 100));
  __CPROVER_assume((pub_r000117_17_1 >= (-100)) && (pub_r000117_17_1 <= 100));
  __CPROVER_assume((pub_r000117_17_2 >= (-100)) && (pub_r000117_17_2 <= 100));
  __CPROVER_assume((pub_r000117_18_1 >= (-100)) && (pub_r000117_18_1 <= 100));
  __CPROVER_assume((pub_r000117_18_2 >= (-100)) && (pub_r000117_18_2 <= 100));
  __CPROVER_assume((pub_r000117_19_1 >= (-100)) && (pub_r000117_19_1 <= 100));
  __CPROVER_assume((pub_r000117_19_2 >= (-100)) && (pub_r000117_19_2 <= 100));
  __CPROVER_assume((pub_r000117_20_1 >= (-100)) && (pub_r000117_20_1 <= 100));
  __CPROVER_assume((pub_r000117_20_2 >= (-100)) && (pub_r000117_20_2 <= 100));
  __CPROVER_assume((pub_r000117_21_1 >= (-100)) && (pub_r000117_21_1 <= 100));
  __CPROVER_assume((pub_r000117_21_2 >= (-100)) && (pub_r000117_21_2 <= 100));
  __CPROVER_assume((pub_r000117_22_1 >= (-100)) && (pub_r000117_22_1 <= 100));
  __CPROVER_assume((pub_r000117_22_2 >= (-100)) && (pub_r000117_22_2 <= 100));
  __CPROVER_assume((pub_r000117_23_1 >= (-100)) && (pub_r000117_23_1 <= 100));
  __CPROVER_assume((pub_r000117_23_2 >= (-100)) && (pub_r000117_23_2 <= 100));
  __CPROVER_assume((sec_r000117_0_1 >= 0) && (sec_r000117_0_1 <= 255));
  __CPROVER_assume((sec_r000117_0_2 >= 0) && (sec_r000117_0_2 <= 255));
  __CPROVER_assume((sec_r000117_1_1 >= 0) && (sec_r000117_1_1 <= 255));
  __CPROVER_assume((sec_r000117_1_2 >= 0) && (sec_r000117_1_2 <= 255));
  __CPROVER_assume((sec_r000117_2_1 >= 0) && (sec_r000117_2_1 <= 255));
  __CPROVER_assume((sec_r000117_2_2 >= 0) && (sec_r000117_2_2 <= 255));
  __CPROVER_assume((sec_r000117_3_1 >= 0) && (sec_r000117_3_1 <= 255));
  __CPROVER_assume((sec_r000117_3_2 >= 0) && (sec_r000117_3_2 <= 255));
  __CPROVER_assume((sec_r000117_4_1 >= 0) && (sec_r000117_4_1 <= 255));
  __CPROVER_assume((sec_r000117_4_2 >= 0) && (sec_r000117_4_2 <= 255));
  __CPROVER_assume((sec_r000117_5_1 >= 0) && (sec_r000117_5_1 <= 255));
  __CPROVER_assume((sec_r000117_5_2 >= 0) && (sec_r000117_5_2 <= 255));
  __CPROVER_assume((sec_r000117_6_1 >= 0) && (sec_r000117_6_1 <= 255));
  __CPROVER_assume((sec_r000117_6_2 >= 0) && (sec_r000117_6_2 <= 255));
  __CPROVER_assume((sec_r000117_7_1 >= 0) && (sec_r000117_7_1 <= 255));
  __CPROVER_assume((sec_r000117_7_2 >= 0) && (sec_r000117_7_2 <= 255));
  __CPROVER_assume((sec_r000117_8_1 >= 0) && (sec_r000117_8_1 <= 255));
  __CPROVER_assume((sec_r000117_8_2 >= 0) && (sec_r000117_8_2 <= 255));
  __CPROVER_assume((sec_r000117_9_1 >= 0) && (sec_r000117_9_1 <= 255));
  __CPROVER_assume((sec_r000117_9_2 >= 0) && (sec_r000117_9_2 <= 255));
  __CPROVER_assume((sec_r000117_10_1 >= 0) && (sec_r000117_10_1 <= 255));
  __CPROVER_assume((sec_r000117_10_2 >= 0) && (sec_r000117_10_2 <= 255));
  __CPROVER_assume((sec_r000117_11_1 >= 0) && (sec_r000117_11_1 <= 255));
  __CPROVER_assume((sec_r000117_11_2 >= 0) && (sec_r000117_11_2 <= 255));
  __CPROVER_assume((sec_r000117_12_1 >= 0) && (sec_r000117_12_1 <= 255));
  __CPROVER_assume((sec_r000117_12_2 >= 0) && (sec_r000117_12_2 <= 255));
  __CPROVER_assume((sec_r000117_13_1 >= 0) && (sec_r000117_13_1 <= 255));
  __CPROVER_assume((sec_r000117_13_2 >= 0) && (sec_r000117_13_2 <= 255));
  __CPROVER_assume((sec_r000117_14_1 >= 0) && (sec_r000117_14_1 <= 255));
  __CPROVER_assume((sec_r000117_14_2 >= 0) && (sec_r000117_14_2 <= 255));
  __CPROVER_assume((sec_r000117_15_1 >= 0) && (sec_r000117_15_1 <= 255));
  __CPROVER_assume((sec_r000117_15_2 >= 0) && (sec_r000117_15_2 <= 255));
  __CPROVER_assume((sec_r000117_16_1 >= 0) && (sec_r000117_16_1 <= 255));
  __CPROVER_assume((sec_r000117_16_2 >= 0) && (sec_r000117_16_2 <= 255));
  __CPROVER_assume((sec_r000117_17_1 >= 0) && (sec_r000117_17_1 <= 255));
  __CPROVER_assume((sec_r000117_17_2 >= 0) && (sec_r000117_17_2 <= 255));
  __CPROVER_assume((sec_r000117_18_1 >= 0) && (sec_r000117_18_1 <= 255));
  __CPROVER_assume((sec_r000117_18_2 >= 0) && (sec_r000117_18_2 <= 255));
  struct CipherContext_R000117_1713_0 st_var_0_1 = {0};
  struct CipherContext_R000117_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000117_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000117_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000117_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000117_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000117_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000117_0_2 + 7) & 15;
  struct EventLog_R000117_1713_1 st_var_1_1 = {0};
  struct EventLog_R000117_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000117_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000117_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000117_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000117_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000117_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000117_0_2 + 9) & 15;
  union TelemetryField_R000117_1713_0 u_var_1;
  union TelemetryField_R000117_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 48)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 48)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 39)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 39)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 52)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 52)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 53)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 53)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_12_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_13_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 30)
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
  if (stage_v_14_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 30)
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
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((st_var_0_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_0_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 52)
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
  if (stage_v_22_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 52)
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
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 51)
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
  if (stage_v_23_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 51)
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
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 28) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 25)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 25)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 34)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 34)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((st_var_1_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_1_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 43)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 43)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_36_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000117_14_1 & 1) != 0)
  {
    if ((sec_r000117_0_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000117_14_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000117_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000117_14_1 + 7) & 127;
  }
  if ((sec_r000117_14_2 & 1) != 0)
  {
    if ((sec_r000117_0_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000117_14_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000117_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000117_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000117_16_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000117_9_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000117_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000117_9_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000117_16_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000117_9_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000117_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000117_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000117_17_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000117_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000117_17_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000117_17_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000117_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000117_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000117_9_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((sec_r000117_9_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000117_13_1 & 1) != 0)
  {
    if ((sec_r000117_15_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000117_18_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000117_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000117_18_1 + 7) & 127;
  }
  if ((sec_r000117_13_2 & 1) != 0)
  {
    if ((sec_r000117_15_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000117_18_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000117_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000117_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000117_8_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000117_8_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000117_18_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000117_18_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000117_16_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000117_16_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000117_17_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000117_17_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000117_5_1 & 1) != 0)
  {
    if ((sec_r000117_17_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((sec_r000117_5_2 & 1) != 0)
  {
    if ((sec_r000117_17_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000117_1_1 & 1) != 0)
  {
    if ((sec_r000117_15_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000117_3_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000117_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000117_3_1 + 7) & 127;
  }
  if ((sec_r000117_1_2 & 1) != 0)
  {
    if ((sec_r000117_15_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000117_3_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000117_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000117_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000117_16_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000117_16_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000117_9_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000117_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000117_9_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000117_9_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000117_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000117_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000117_4_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000117_21_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000117_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000117_21_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000117_4_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000117_21_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000117_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000117_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000117_10_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((sec_r000117_10_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000117_8_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000117_11_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000117_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000117_11_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000117_8_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000117_11_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000117_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000117_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000117_17_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000117_3_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000117_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000117_3_1 + 7) & 127;
  }
  if ((sec_r000117_17_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000117_3_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000117_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000117_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000117_2_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000117_4_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000117_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000117_4_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000117_2_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000117_4_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000117_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000117_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000117_13_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000117_12_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000117_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000117_12_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000117_13_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000117_12_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000117_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000117_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000117_0_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000117_10_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000117_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000117_10_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000117_0_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000117_10_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000117_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000117_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000117_13_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000117_21_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000117_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000117_21_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000117_13_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000117_21_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000117_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000117_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000117_21_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000117_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000117_21_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000117_21_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000117_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000117_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000117_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000117_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000117_10_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000117_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000117_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000117_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000117_16_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000117_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000117_16_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000117_16_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000117_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000117_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000117_8_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000117_8_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000117_10_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000117_7_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000117_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000117_7_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000117_10_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000117_7_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000117_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000117_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000117_17_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000117_17_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000117_1_1 & 1) != 0)
  {
    if ((sec_r000117_5_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000117_10_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000117_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000117_10_1 + 7) & 127;
  }
  if ((sec_r000117_1_2 & 1) != 0)
  {
    if ((sec_r000117_5_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000117_10_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000117_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000117_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000117_0_1 & 1) != 0)
  {
    if ((sec_r000117_18_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((sec_r000117_0_2 & 1) != 0)
  {
    if ((sec_r000117_18_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000117_0_1 & 1) != 0)
  {
    if ((sec_r000117_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000117_7_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000117_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000117_7_1 + 7) & 127;
  }
  if ((sec_r000117_0_2 & 1) != 0)
  {
    if ((sec_r000117_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000117_7_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000117_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000117_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000117_16_1 & 1) != 0)
  {
    if ((sec_r000117_15_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000117_15_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000117_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000117_15_1 + 7) & 127;
  }
  if ((sec_r000117_16_2 & 1) != 0)
  {
    if ((sec_r000117_15_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000117_15_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000117_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000117_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000117_17_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000117_17_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000117_3_1 & 1) != 0)
  {
    if ((sec_r000117_9_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((sec_r000117_3_2 & 1) != 0)
  {
    if ((sec_r000117_9_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000117_4_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000117_11_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000117_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000117_11_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000117_4_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000117_11_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000117_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000117_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000117_2_1 & 1) != 0)
  {
    if ((sec_r000117_17_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000117_5_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000117_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000117_5_1 + 7) & 127;
  }
  if ((sec_r000117_2_2 & 1) != 0)
  {
    if ((sec_r000117_17_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000117_5_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000117_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000117_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000117_11_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000117_11_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000117_1_1 & 1) != 0)
  {
    if ((sec_r000117_2_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000117_13_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000117_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000117_13_1 + 7) & 127;
  }
  if ((sec_r000117_1_2 & 1) != 0)
  {
    if ((sec_r000117_2_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000117_13_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000117_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000117_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000117_5_1 & 1) != 0)
  {
    if ((sec_r000117_4_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((sec_r000117_5_2 & 1) != 0)
  {
    if ((sec_r000117_4_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000117_0_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000117_18_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000117_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000117_18_1 + 7) & 127;
  }
  if ((sec_r000117_0_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000117_18_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000117_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000117_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000117_18_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000117_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000117_18_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000117_18_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000117_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000117_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000117_3_1 & 1) != 0)
  {
    if ((sec_r000117_11_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((sec_r000117_3_2 & 1) != 0)
  {
    if ((sec_r000117_11_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000117_1_1 & 1) != 0)
  {
    if ((sec_r000117_18_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000117_18_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000117_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000117_18_1 + 7) & 127;
  }
  if ((sec_r000117_1_2 & 1) != 0)
  {
    if ((sec_r000117_18_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000117_18_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000117_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000117_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000117_16_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000117_16_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000117_5_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000117_17_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000117_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000117_17_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000117_5_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000117_17_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000117_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000117_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000117_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000117_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000117_5_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000117_21_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000117_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000117_21_1 + 7) & 127;
  }
  if ((sec_r000117_5_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000117_21_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000117_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000117_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000117_7_1 & 1) != 0)
  {
    if ((sec_r000117_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000117_11_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000117_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000117_11_1 + 7) & 127;
  }
  if ((sec_r000117_7_2 & 1) != 0)
  {
    if ((sec_r000117_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000117_11_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000117_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000117_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000117_13_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000117_22_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000117_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000117_22_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000117_13_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000117_22_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000117_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000117_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000117_9_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000117_9_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000117_18_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((sec_r000117_18_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000117_1_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000117_13_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000117_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000117_13_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000117_1_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000117_13_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000117_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000117_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000117_7_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000117_7_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000117_18_1 & 1) != 0)
  {
    if ((sec_r000117_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000117_23_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000117_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000117_23_1 + 7) & 127;
  }
  if ((sec_r000117_18_2 & 1) != 0)
  {
    if ((sec_r000117_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000117_23_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000117_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000117_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000117_2_1 & 1) != 0)
  {
    if ((sec_r000117_11_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000117_12_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000117_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000117_12_1 + 7) & 127;
  }
  if ((sec_r000117_2_2 & 1) != 0)
  {
    if ((sec_r000117_11_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000117_12_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000117_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000117_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000117_0_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000117_0_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000117_2_1 & 1) != 0)
  {
    if ((sec_r000117_1_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((sec_r000117_2_2 & 1) != 0)
  {
    if ((sec_r000117_1_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000117_4_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000117_17_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000117_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000117_17_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000117_4_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000117_17_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000117_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000117_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000117_16_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000117_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000117_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000117_0_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000117_16_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000117_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000117_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000117_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000117_10_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000117_20_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000117_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000117_20_1 + 7) & 127;
  }
  if ((sec_r000117_10_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000117_20_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000117_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000117_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000117_11_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000117_11_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000117_14_1 & 1) != 0)
  {
    if ((sec_r000117_2_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000117_6_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000117_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000117_6_1 + 7) & 127;
  }
  if ((sec_r000117_14_2 & 1) != 0)
  {
    if ((sec_r000117_2_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000117_6_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000117_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000117_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000117_10_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000117_10_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000117_15_1 & 1) != 0)
  {
    if ((sec_r000117_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000117_10_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000117_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000117_10_1 + 7) & 127;
  }
  if ((sec_r000117_15_2 & 1) != 0)
  {
    if ((sec_r000117_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000117_10_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000117_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000117_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000117_9_1 & 1) != 0)
  {
    if ((sec_r000117_5_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000117_3_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000117_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000117_3_1 + 7) & 127;
  }
  if ((sec_r000117_9_2 & 1) != 0)
  {
    if ((sec_r000117_5_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000117_3_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000117_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000117_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000117_18_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000117_18_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000117_11_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000117_7_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000117_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000117_7_1 + 7) & 127;
  }
  if ((sec_r000117_11_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000117_7_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000117_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000117_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000117_10_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000117_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000117_10_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000117_10_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000117_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000117_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000117_3_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000117_19_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000117_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000117_19_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000117_3_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000117_19_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000117_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000117_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000117_10_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000117_10_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000117_3_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000117_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000117_3_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000117_3_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000117_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000117_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000117_1_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000117_1_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000117_6_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000117_4_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000117_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000117_4_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000117_6_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000117_4_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000117_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000117_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000117_15_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000117_2_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000117_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000117_2_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000117_15_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000117_2_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000117_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000117_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000117_2_1 & 1) != 0)
  {
    if ((sec_r000117_13_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000117_17_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000117_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000117_17_1 + 7) & 127;
  }
  if ((sec_r000117_2_2 & 1) != 0)
  {
    if ((sec_r000117_13_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000117_17_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000117_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000117_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000117_12_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000117_11_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000117_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000117_11_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000117_12_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000117_11_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000117_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000117_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000117_15_1 & 1) != 0)
  {
    if ((sec_r000117_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000117_8_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000117_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000117_8_1 + 7) & 127;
  }
  if ((sec_r000117_15_2 & 1) != 0)
  {
    if ((sec_r000117_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000117_8_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000117_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000117_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000117_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000117_18_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000117_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000117_18_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000117_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000117_18_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000117_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000117_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000117_9_1 & 1) != 0)
  {
    if ((sec_r000117_10_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000117_1_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000117_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000117_1_1 + 7) & 127;
  }
  if ((sec_r000117_9_2 & 1) != 0)
  {
    if ((sec_r000117_10_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000117_1_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000117_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000117_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000117_17_1 != sec_r000117_17_2);
  __CPROVER_assume(pub_r000117_16_1 == pub_r000117_16_2);
  __CPROVER_assume(sec_r000117_16_1 != sec_r000117_16_2);
  __CPROVER_assume(pub_r000117_6_1 == pub_r000117_6_2);
  __CPROVER_assume(pub_r000117_1_1 == pub_r000117_1_2);
  __CPROVER_assume(sec_r000117_13_1 != sec_r000117_13_2);
  __CPROVER_assume(sec_r000117_18_1 != sec_r000117_18_2);
  __CPROVER_assume(sec_r000117_7_1 != sec_r000117_7_2);
  __CPROVER_assume(pub_r000117_9_1 == pub_r000117_9_2);
  __CPROVER_assume(pub_r000117_5_1 == pub_r000117_5_2);
  __CPROVER_assume(sec_r000117_4_1 != sec_r000117_4_2);
  __CPROVER_assume(sec_r000117_3_1 != sec_r000117_3_2);
  __CPROVER_assume(sec_r000117_1_1 != sec_r000117_1_2);
  __CPROVER_assume(sec_r000117_15_1 != sec_r000117_15_2);
  __CPROVER_assume(pub_r000117_10_1 == pub_r000117_10_2);
  __CPROVER_assume(pub_r000117_20_1 == pub_r000117_20_2);
  __CPROVER_assume(sec_r000117_5_1 != sec_r000117_5_2);
  __CPROVER_assume(pub_r000117_12_1 == pub_r000117_12_2);
  __CPROVER_assume(sec_r000117_10_1 != sec_r000117_10_2);
  __CPROVER_assume(pub_r000117_3_1 == pub_r000117_3_2);
  __CPROVER_assume(pub_r000117_22_1 == pub_r000117_22_2);
  __CPROVER_assume(pub_r000117_14_1 == pub_r000117_14_2);
  __CPROVER_assume(pub_r000117_11_1 == pub_r000117_11_2);
  __CPROVER_assume(pub_r000117_17_1 == pub_r000117_17_2);
  __CPROVER_assume(pub_r000117_4_1 == pub_r000117_4_2);
  __CPROVER_assume(sec_r000117_11_1 != sec_r000117_11_2);
  __CPROVER_assume(pub_r000117_8_1 == pub_r000117_8_2);
  __CPROVER_assume(pub_r000117_19_1 == pub_r000117_19_2);
  __CPROVER_assume(pub_r000117_21_1 == pub_r000117_21_2);
  __CPROVER_assume(sec_r000117_14_1 != sec_r000117_14_2);
  __CPROVER_assume(pub_r000117_2_1 == pub_r000117_2_2);
  __CPROVER_assume(pub_r000117_18_1 == pub_r000117_18_2);
  __CPROVER_assume(sec_r000117_6_1 != sec_r000117_6_2);
  __CPROVER_assume(pub_r000117_13_1 == pub_r000117_13_2);
  __CPROVER_assume(pub_r000117_15_1 == pub_r000117_15_2);
  __CPROVER_assume(sec_r000117_2_1 != sec_r000117_2_2);
  __CPROVER_assume(pub_r000117_23_1 == pub_r000117_23_2);
  __CPROVER_assume(sec_r000117_0_1 != sec_r000117_0_2);
  __CPROVER_assume(sec_r000117_8_1 != sec_r000117_8_2);
  __CPROVER_assume(sec_r000117_9_1 != sec_r000117_9_2);
  __CPROVER_assume(pub_r000117_0_1 == pub_r000117_0_2);
  __CPROVER_assume(sec_r000117_12_1 != sec_r000117_12_2);
  __CPROVER_assume(pub_r000117_7_1 == pub_r000117_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
}


