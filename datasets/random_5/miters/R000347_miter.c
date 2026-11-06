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
struct CipherContext_R000347_4713_0
{
  int nonce;
  unsigned char iv;
  int tag;
  unsigned char counter;
  int flags;
  unsigned char round_key;
  int buffer[3];
};
struct MatrixBlock_R000347_4713_1
{
  int density;
  int trace;
  short scale;
  int buffer[3];
};
union RegisterBank_R000347_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000347_4713_1
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
void fn_R000347_4713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_67_1)
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

  switch (metric_67_2)
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

  int quantum_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_82_1) & 63;
  aux_2 = (aux_2 + quantum_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_67_1 == metric_67_2);
  assert(quantum_82_1 == quantum_82_2);
}

int fn_R000347_4713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_67 = (aux + st.buffer[1]) & 3;
  switch (metric_67)
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

  int quantum_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000347_4713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int window_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_78_1)
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

  switch (window_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_69_1) & 63;
  aux_2 = (aux_2 + threshold_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
  assert(threshold_69_1 == threshold_69_2);
}

int fn_R000347_4713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int window_78 = (aux + st.buffer[1]) & 3;
  switch (window_78)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000347_4713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_58_1)
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

  switch (pivot_58_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_58_1 == pivot_58_2);
}

int fn_R000347_4713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_58 = (aux + st.buffer[1]) & 3;
  switch (pivot_58)
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

void fn_R000347_4713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_15_1)
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

  switch (delta_15_2)
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

  int checksum_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_61_1 > 31)
  {
    acc_1 = ((acc_1 + (checksum_61_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_61_2 > 31)
  {
    acc_2 = ((acc_2 + (checksum_61_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_39_1) & 63;
  aux_2 = (aux_2 + quotient_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_68_1 = local_arr_1[aux_1 % 3];
  int segment_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_15_1 == delta_15_2);
  assert(checksum_61_1 == checksum_61_2);
  assert(quotient_39_1 == quotient_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_68_1 == segment_68_2);
}

int fn_R000347_4713_3(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_15 = (aux + st.buffer[1]) & 3;
  switch (delta_15)
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

  int checksum_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_61 > 31)
  {
    acc = ((acc + (checksum_61 * 2)) + 5) & 127;
    aux ^= checksum_61 & 15;
  }
  else
  {
    acc = ((acc - checksum_61) + 11) & 127;
    aux += 3;
  }
  int quotient_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_39) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_68 = local_arr[aux % 3];
  acc = (acc + (segment_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_96_1) & 63;
  aux_2 = (aux_2 + parity_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_47_1)
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

  switch (window_47_2)
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
  int stride_76_1 = local_arr_1[aux_1 % 3];
  int stride_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_76_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_96_1 == parity_96_2);
  assert(window_47_1 == window_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_76_1 == stride_76_2);
}

int fn_R000347_4713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_96) & 63;
  acc ^= aux;
  int window_47 = (aux + st.buffer[1]) & 3;
  switch (window_47)
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
  int stride_76 = local_arr[aux % 3];
  acc = (acc + (stride_76 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_13_1) & 63;
  aux_2 = (aux_2 + segment_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_39_1 > 41)
  {
    acc_1 = ((acc_1 + (threshold_39_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_39_2 > 41)
  {
    acc_2 = ((acc_2 + (threshold_39_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_79_1 = local_arr_1[aux_1 % 3];
  int residue_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_13_1 == segment_13_2);
  assert(threshold_39_1 == threshold_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_79_1 == residue_79_2);
}

int fn_R000347_4713_5(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_13) & 63;
  acc ^= aux;
  int threshold_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_39 > 41)
  {
    acc = ((acc + (threshold_39 * 2)) + 5) & 127;
    aux ^= threshold_39 & 15;
  }
  else
  {
    acc = ((acc - threshold_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_79 = local_arr[aux % 3];
  acc = (acc + (residue_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_68_1) & 63;
  aux_2 = (aux_2 + stride_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_68_1 == stride_68_2);
}

int fn_R000347_4713_6(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000347_4713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_25_1) & 63;
  aux_2 = (aux_2 + cursor_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_13_1)
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

  switch (bound_13_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_25_1 == cursor_25_2);
  assert(bound_13_1 == bound_13_2);
}

int fn_R000347_4713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_25) & 63;
  acc ^= aux;
  int bound_13 = (aux + st.buffer[1]) & 3;
  switch (bound_13)
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

void fn_R000347_4713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_77_1) & 63;
  aux_2 = (aux_2 + anchor_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_77_1 == anchor_77_2);
}

int fn_R000347_4713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_65_1) & 63;
  aux_2 = (aux_2 + damping_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_64_1)
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

  switch (window_64_2)
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
  int factor_49_1 = local_arr_1[aux_1 % 3];
  int factor_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_65_1 == damping_65_2);
  assert(window_64_1 == window_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_49_1 == factor_49_2);
}

int fn_R000347_4713_9(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_65) & 63;
  acc ^= aux;
  int window_64 = (aux + st.buffer[1]) & 3;
  switch (window_64)
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
  int factor_49 = local_arr[aux % 3];
  acc = (acc + (factor_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_29_1) & 63;
  aux_2 = (aux_2 + mask_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_28_1 > 17)
  {
    acc_1 = ((acc_1 + (phase_28_1 * 2)) + 5) & 127;
    aux_1 ^= phase_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_28_2 > 17)
  {
    acc_2 = ((acc_2 + (phase_28_2 * 2)) + 5) & 127;
    aux_2 ^= phase_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_28_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_29_1 == mask_29_2);
  assert(phase_28_1 == phase_28_2);
}

int fn_R000347_4713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_29) & 63;
  acc ^= aux;
  int phase_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_28 > 17)
  {
    acc = ((acc + (phase_28 * 2)) + 5) & 127;
    aux ^= phase_28 & 15;
  }
  else
  {
    acc = ((acc - phase_28) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000347_4713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_95_1 > 35)
  {
    acc_1 = ((acc_1 + (tracker_95_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_95_2 > 35)
  {
    acc_2 = ((acc_2 + (tracker_95_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_95_1 == tracker_95_2);
}

int fn_R000347_4713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_95 > 35)
  {
    acc = ((acc + (tracker_95 * 2)) + 5) & 127;
    aux ^= tracker_95 & 15;
  }
  else
  {
    acc = ((acc - tracker_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000347_4713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_87_1)
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

  switch (anchor_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_26_1 > 25)
  {
    acc_1 = ((acc_1 + (vector_26_1 * 2)) + 5) & 127;
    aux_1 ^= vector_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_26_2 > 25)
  {
    acc_2 = ((acc_2 + (vector_26_2 * 2)) + 5) & 127;
    aux_2 ^= vector_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_87_1 == anchor_87_2);
  assert(vector_26_1 == vector_26_2);
}

int fn_R000347_4713_12(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_87 = (aux + st.buffer[1]) & 3;
  switch (anchor_87)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_26 > 25)
  {
    acc = ((acc + (vector_26 * 2)) + 5) & 127;
    aux ^= vector_26 & 15;
  }
  else
  {
    acc = ((acc - vector_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000347_4713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_85_1 > 12)
  {
    acc_1 = ((acc_1 + (tally_85_1 * 2)) + 5) & 127;
    aux_1 ^= tally_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_85_2 > 12)
  {
    acc_2 = ((acc_2 + (tally_85_2 * 2)) + 5) & 127;
    aux_2 ^= tally_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_18_1) & 63;
  aux_2 = (aux_2 + quantum_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_72_1 = local_arr_1[aux_1 % 3];
  int cursor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_85_1 == tally_85_2);
  assert(quantum_18_1 == quantum_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_72_1 == cursor_72_2);
}

int fn_R000347_4713_13(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_85 > 12)
  {
    acc = ((acc + (tally_85 * 2)) + 5) & 127;
    aux ^= tally_85 & 15;
  }
  else
  {
    acc = ((acc - tally_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_72 = local_arr[aux % 3];
  acc = (acc + (cursor_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_87_1 > 16)
  {
    acc_1 = ((acc_1 + (damping_87_1 * 2)) + 5) & 127;
    aux_1 ^= damping_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_87_2 > 16)
  {
    acc_2 = ((acc_2 + (damping_87_2 * 2)) + 5) & 127;
    aux_2 ^= damping_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_94_1)
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

  switch (coefficient_94_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_87_1 == damping_87_2);
  assert(coefficient_94_1 == coefficient_94_2);
}

int fn_R000347_4713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_87 > 16)
  {
    acc = ((acc + (damping_87 * 2)) + 5) & 127;
    aux ^= damping_87 & 15;
  }
  else
  {
    acc = ((acc - damping_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_94 = (aux + st.buffer[1]) & 3;
  switch (coefficient_94)
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

void fn_R000347_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_89_1)
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

  switch (threshold_89_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_75_1 > 50)
  {
    acc_1 = ((acc_1 + (quotient_75_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_75_2 > 50)
  {
    acc_2 = ((acc_2 + (quotient_75_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_89_1 == threshold_89_2);
  assert(quotient_75_1 == quotient_75_2);
}

int fn_R000347_4713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_89 = (aux + st.buffer[1]) & 3;
  switch (threshold_89)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_75 > 50)
  {
    acc = ((acc + (quotient_75 * 2)) + 5) & 127;
    aux ^= quotient_75 & 15;
  }
  else
  {
    acc = ((acc - quotient_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000347_4713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_50_1) & 63;
  aux_2 = (aux_2 + cursor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_43_1)
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

  switch (vector_43_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(vector_43_1 == vector_43_2);
}

int fn_R000347_4713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_50) & 63;
  acc ^= aux;
  int vector_43 = (aux + st.buffer[1]) & 3;
  switch (vector_43)
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

void fn_R000347_4713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_19_1 > 49)
  {
    acc_1 = ((acc_1 + (delta_19_1 * 2)) + 5) & 127;
    aux_1 ^= delta_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_19_2 > 49)
  {
    acc_2 = ((acc_2 + (delta_19_2 * 2)) + 5) & 127;
    aux_2 ^= delta_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_51_1)
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

  switch (metric_51_2)
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
  int pivot_69_1 = local_arr_1[aux_1 % 3];
  int pivot_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(metric_51_1 == metric_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_69_1 == pivot_69_2);
}

int fn_R000347_4713_17(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_19 > 49)
  {
    acc = ((acc + (delta_19 * 2)) + 5) & 127;
    aux ^= delta_19 & 15;
  }
  else
  {
    acc = ((acc - delta_19) + 11) & 127;
    aux += 3;
  }
  int metric_51 = (aux + st.buffer[1]) & 3;
  switch (metric_51)
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
  int pivot_69 = local_arr[aux % 3];
  acc = (acc + (pivot_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_47_1) & 63;
  aux_2 = (aux_2 + pivot_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_44_1 = local_arr_1[aux_1 % 3];
  int stride_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_47_1 == pivot_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_44_1 == stride_44_2);
}

int fn_R000347_4713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_44 = local_arr[aux % 3];
  acc = (acc + (stride_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000347_4713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_78_1 > 30)
  {
    acc_1 = ((acc_1 + (coefficient_78_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_78_2 > 30)
  {
    acc_2 = ((acc_2 + (coefficient_78_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_78_1 == coefficient_78_2);
}

int fn_R000347_4713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_78 > 30)
  {
    acc = ((acc + (coefficient_78 * 2)) + 5) & 127;
    aux ^= coefficient_78 & 15;
  }
  else
  {
    acc = ((acc - coefficient_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000347_4713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_73_1 = local_arr_1[aux_1 % 3];
  int quotient_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_73_2 * 2)) & 127;
  int quantum_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_94_1) & 63;
  aux_2 = (aux_2 + quantum_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_73_1 == quotient_73_2);
  assert(quantum_94_1 == quantum_94_2);
}

int fn_R000347_4713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000347_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int quotient_73 = local_arr[aux % 3];
  acc = (acc + (quotient_73 * 2)) & 127;
  int quantum_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000347_4713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st_1 = {0};
  struct CipherContext_R000347_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_43_1 > 41)
  {
    acc_1 = ((acc_1 + (pivot_43_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_43_2 > 41)
  {
    acc_2 = ((acc_2 + (pivot_43_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_44_1 = local_arr_1[aux_1 % 3];
  int tally_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_44_2 * 2)) & 127;
  int window_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_72_1)
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

  switch (window_72_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_43_1 == pivot_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_44_1 == tally_44_2);
  assert(window_72_1 == window_72_2);
}

int fn_R000347_4713_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000347_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_43 > 41)
  {
    acc = ((acc + (pivot_43 * 2)) + 5) & 127;
    aux ^= pivot_43 & 15;
  }
  else
  {
    acc = ((acc - pivot_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_44 = local_arr[aux % 3];
  acc = (acc + (tally_44 * 2)) & 127;
  int window_72 = (aux + st.buffer[1]) & 3;
  switch (window_72)
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

void main()
{
  int sec_r000347_0_1;
  int sec_r000347_0_2;
  int sec_r000347_1_1;
  int sec_r000347_1_2;
  int sec_r000347_2_1;
  int sec_r000347_2_2;
  int sec_r000347_3_1;
  int sec_r000347_3_2;
  int sec_r000347_4_1;
  int sec_r000347_4_2;
  int sec_r000347_5_1;
  int sec_r000347_5_2;
  int sec_r000347_6_1;
  int sec_r000347_6_2;
  int sec_r000347_7_1;
  int sec_r000347_7_2;
  int sec_r000347_8_1;
  int sec_r000347_8_2;
  int sec_r000347_9_1;
  int sec_r000347_9_2;
  int sec_r000347_10_1;
  int sec_r000347_10_2;
  int sec_r000347_11_1;
  int sec_r000347_11_2;
  int sec_r000347_12_1;
  int sec_r000347_12_2;
  int sec_r000347_13_1;
  int sec_r000347_13_2;
  int sec_r000347_14_1;
  int sec_r000347_14_2;
  int sec_r000347_15_1;
  int sec_r000347_15_2;
  int pub_r000347_0_1;
  int pub_r000347_0_2;
  int pub_r000347_1_1;
  int pub_r000347_1_2;
  int pub_r000347_2_1;
  int pub_r000347_2_2;
  int pub_r000347_3_1;
  int pub_r000347_3_2;
  int pub_r000347_4_1;
  int pub_r000347_4_2;
  int pub_r000347_5_1;
  int pub_r000347_5_2;
  int pub_r000347_6_1;
  int pub_r000347_6_2;
  int pub_r000347_7_1;
  int pub_r000347_7_2;
  int pub_r000347_8_1;
  int pub_r000347_8_2;
  int pub_r000347_9_1;
  int pub_r000347_9_2;
  int pub_r000347_10_1;
  int pub_r000347_10_2;
  int pub_r000347_11_1;
  int pub_r000347_11_2;
  int pub_r000347_12_1;
  int pub_r000347_12_2;
  int pub_r000347_13_1;
  int pub_r000347_13_2;
  int pub_r000347_14_1;
  int pub_r000347_14_2;
  int pub_r000347_15_1;
  int pub_r000347_15_2;
  int pub_r000347_16_1;
  int pub_r000347_16_2;
  int pub_r000347_17_1;
  int pub_r000347_17_2;
  int pub_r000347_18_1;
  int pub_r000347_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000347_0_1 >= (-100)) && (pub_r000347_0_1 <= 100));
  __CPROVER_assume((pub_r000347_0_2 >= (-100)) && (pub_r000347_0_2 <= 100));
  __CPROVER_assume((pub_r000347_1_1 >= (-100)) && (pub_r000347_1_1 <= 100));
  __CPROVER_assume((pub_r000347_1_2 >= (-100)) && (pub_r000347_1_2 <= 100));
  __CPROVER_assume((pub_r000347_2_1 >= (-100)) && (pub_r000347_2_1 <= 100));
  __CPROVER_assume((pub_r000347_2_2 >= (-100)) && (pub_r000347_2_2 <= 100));
  __CPROVER_assume((pub_r000347_3_1 >= (-100)) && (pub_r000347_3_1 <= 100));
  __CPROVER_assume((pub_r000347_3_2 >= (-100)) && (pub_r000347_3_2 <= 100));
  __CPROVER_assume((pub_r000347_4_1 >= (-100)) && (pub_r000347_4_1 <= 100));
  __CPROVER_assume((pub_r000347_4_2 >= (-100)) && (pub_r000347_4_2 <= 100));
  __CPROVER_assume((pub_r000347_5_1 >= (-100)) && (pub_r000347_5_1 <= 100));
  __CPROVER_assume((pub_r000347_5_2 >= (-100)) && (pub_r000347_5_2 <= 100));
  __CPROVER_assume((pub_r000347_6_1 >= (-100)) && (pub_r000347_6_1 <= 100));
  __CPROVER_assume((pub_r000347_6_2 >= (-100)) && (pub_r000347_6_2 <= 100));
  __CPROVER_assume((pub_r000347_7_1 >= (-100)) && (pub_r000347_7_1 <= 100));
  __CPROVER_assume((pub_r000347_7_2 >= (-100)) && (pub_r000347_7_2 <= 100));
  __CPROVER_assume((pub_r000347_8_1 >= (-100)) && (pub_r000347_8_1 <= 100));
  __CPROVER_assume((pub_r000347_8_2 >= (-100)) && (pub_r000347_8_2 <= 100));
  __CPROVER_assume((pub_r000347_9_1 >= (-100)) && (pub_r000347_9_1 <= 100));
  __CPROVER_assume((pub_r000347_9_2 >= (-100)) && (pub_r000347_9_2 <= 100));
  __CPROVER_assume((pub_r000347_10_1 >= (-100)) && (pub_r000347_10_1 <= 100));
  __CPROVER_assume((pub_r000347_10_2 >= (-100)) && (pub_r000347_10_2 <= 100));
  __CPROVER_assume((pub_r000347_11_1 >= (-100)) && (pub_r000347_11_1 <= 100));
  __CPROVER_assume((pub_r000347_11_2 >= (-100)) && (pub_r000347_11_2 <= 100));
  __CPROVER_assume((pub_r000347_12_1 >= (-100)) && (pub_r000347_12_1 <= 100));
  __CPROVER_assume((pub_r000347_12_2 >= (-100)) && (pub_r000347_12_2 <= 100));
  __CPROVER_assume((pub_r000347_13_1 >= (-100)) && (pub_r000347_13_1 <= 100));
  __CPROVER_assume((pub_r000347_13_2 >= (-100)) && (pub_r000347_13_2 <= 100));
  __CPROVER_assume((pub_r000347_14_1 >= (-100)) && (pub_r000347_14_1 <= 100));
  __CPROVER_assume((pub_r000347_14_2 >= (-100)) && (pub_r000347_14_2 <= 100));
  __CPROVER_assume((pub_r000347_15_1 >= (-100)) && (pub_r000347_15_1 <= 100));
  __CPROVER_assume((pub_r000347_15_2 >= (-100)) && (pub_r000347_15_2 <= 100));
  __CPROVER_assume((pub_r000347_16_1 >= (-100)) && (pub_r000347_16_1 <= 100));
  __CPROVER_assume((pub_r000347_16_2 >= (-100)) && (pub_r000347_16_2 <= 100));
  __CPROVER_assume((pub_r000347_17_1 >= (-100)) && (pub_r000347_17_1 <= 100));
  __CPROVER_assume((pub_r000347_17_2 >= (-100)) && (pub_r000347_17_2 <= 100));
  __CPROVER_assume((pub_r000347_18_1 >= (-100)) && (pub_r000347_18_1 <= 100));
  __CPROVER_assume((pub_r000347_18_2 >= (-100)) && (pub_r000347_18_2 <= 100));
  __CPROVER_assume((sec_r000347_0_1 >= 0) && (sec_r000347_0_1 <= 255));
  __CPROVER_assume((sec_r000347_0_2 >= 0) && (sec_r000347_0_2 <= 255));
  __CPROVER_assume((sec_r000347_1_1 >= 0) && (sec_r000347_1_1 <= 255));
  __CPROVER_assume((sec_r000347_1_2 >= 0) && (sec_r000347_1_2 <= 255));
  __CPROVER_assume((sec_r000347_2_1 >= 0) && (sec_r000347_2_1 <= 255));
  __CPROVER_assume((sec_r000347_2_2 >= 0) && (sec_r000347_2_2 <= 255));
  __CPROVER_assume((sec_r000347_3_1 >= 0) && (sec_r000347_3_1 <= 255));
  __CPROVER_assume((sec_r000347_3_2 >= 0) && (sec_r000347_3_2 <= 255));
  __CPROVER_assume((sec_r000347_4_1 >= 0) && (sec_r000347_4_1 <= 255));
  __CPROVER_assume((sec_r000347_4_2 >= 0) && (sec_r000347_4_2 <= 255));
  __CPROVER_assume((sec_r000347_5_1 >= 0) && (sec_r000347_5_1 <= 255));
  __CPROVER_assume((sec_r000347_5_2 >= 0) && (sec_r000347_5_2 <= 255));
  __CPROVER_assume((sec_r000347_6_1 >= 0) && (sec_r000347_6_1 <= 255));
  __CPROVER_assume((sec_r000347_6_2 >= 0) && (sec_r000347_6_2 <= 255));
  __CPROVER_assume((sec_r000347_7_1 >= 0) && (sec_r000347_7_1 <= 255));
  __CPROVER_assume((sec_r000347_7_2 >= 0) && (sec_r000347_7_2 <= 255));
  __CPROVER_assume((sec_r000347_8_1 >= 0) && (sec_r000347_8_1 <= 255));
  __CPROVER_assume((sec_r000347_8_2 >= 0) && (sec_r000347_8_2 <= 255));
  __CPROVER_assume((sec_r000347_9_1 >= 0) && (sec_r000347_9_1 <= 255));
  __CPROVER_assume((sec_r000347_9_2 >= 0) && (sec_r000347_9_2 <= 255));
  __CPROVER_assume((sec_r000347_10_1 >= 0) && (sec_r000347_10_1 <= 255));
  __CPROVER_assume((sec_r000347_10_2 >= 0) && (sec_r000347_10_2 <= 255));
  __CPROVER_assume((sec_r000347_11_1 >= 0) && (sec_r000347_11_1 <= 255));
  __CPROVER_assume((sec_r000347_11_2 >= 0) && (sec_r000347_11_2 <= 255));
  __CPROVER_assume((sec_r000347_12_1 >= 0) && (sec_r000347_12_1 <= 255));
  __CPROVER_assume((sec_r000347_12_2 >= 0) && (sec_r000347_12_2 <= 255));
  __CPROVER_assume((sec_r000347_13_1 >= 0) && (sec_r000347_13_1 <= 255));
  __CPROVER_assume((sec_r000347_13_2 >= 0) && (sec_r000347_13_2 <= 255));
  __CPROVER_assume((sec_r000347_14_1 >= 0) && (sec_r000347_14_1 <= 255));
  __CPROVER_assume((sec_r000347_14_2 >= 0) && (sec_r000347_14_2 <= 255));
  __CPROVER_assume((sec_r000347_15_1 >= 0) && (sec_r000347_15_1 <= 255));
  __CPROVER_assume((sec_r000347_15_2 >= 0) && (sec_r000347_15_2 <= 255));
  struct CipherContext_R000347_4713_0 st_var_0_1 = {0};
  struct CipherContext_R000347_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000347_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000347_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000347_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000347_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000347_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000347_0_2 + 7) & 15;
  struct MatrixBlock_R000347_4713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000347_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000347_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000347_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000347_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000347_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000347_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000347_0_2 + 9) & 15;
  union RegisterBank_R000347_4713_0 u_var_1;
  union RegisterBank_R000347_4713_0 u_var_2;
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
  int stage_v_2_1 = ((st_var_0_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_0_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 48)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 48)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  if (stage_v_6_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 29)
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
  if (stage_v_6_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 29)
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
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_22_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  if ((sec_r000347_14_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000347_5_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000347_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000347_5_1 + 7) & 127;
  }
  if ((sec_r000347_14_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000347_5_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000347_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000347_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000347_2_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000347_2_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000347_6_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000347_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000347_6_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000347_6_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000347_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000347_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000347_11_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((sec_r000347_11_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000347_14_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((sec_r000347_14_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((sec_r000347_2_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000347_2_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000347_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000347_2_1 + 7) & 127;
  }
  if ((sec_r000347_2_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000347_2_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000347_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000347_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000347_6_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000347_6_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000347_9_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000347_5_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000347_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000347_5_1 + 7) & 127;
  }
  if ((sec_r000347_9_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000347_5_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000347_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000347_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000347_1_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((sec_r000347_1_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000347_13_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000347_13_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000347_10_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_10_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000347_2_1 & 1) != 0)
  {
    if ((sec_r000347_5_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((sec_r000347_2_2 & 1) != 0)
  {
    if ((sec_r000347_5_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000347_0_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000347_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000347_0_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000347_0_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000347_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000347_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000347_2_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000347_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000347_2_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000347_2_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000347_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000347_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000347_1_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000347_5_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000347_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000347_5_1 + 7) & 127;
  }
  if ((sec_r000347_1_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000347_5_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000347_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000347_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000347_3_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000347_17_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000347_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000347_17_1 + 7) & 127;
  }
  if ((sec_r000347_3_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000347_17_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000347_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000347_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000347_9_1 & 1) != 0)
  {
    if ((sec_r000347_6_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((sec_r000347_9_2 & 1) != 0)
  {
    if ((sec_r000347_6_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000347_11_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000347_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000347_11_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000347_11_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000347_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000347_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000347_2_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000347_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000347_2_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000347_2_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000347_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000347_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000347_11_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000347_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000347_11_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000347_11_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000347_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000347_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000347_2_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000347_5_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000347_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000347_5_1 + 7) & 127;
  }
  if ((sec_r000347_2_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000347_5_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000347_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000347_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000347_13_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000347_13_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000347_6_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000347_6_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000347_5_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000347_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000347_5_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000347_5_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000347_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000347_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000347_15_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000347_15_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000347_9_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((sec_r000347_9_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000347_14_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000347_14_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000347_11_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_11_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000347_0_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000347_0_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000347_10_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000347_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000347_10_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000347_10_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000347_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000347_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000347_18_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000347_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000347_18_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000347_18_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000347_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000347_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000347_5_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000347_5_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000347_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000347_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000347_5_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000347_5_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000347_17_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000347_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000347_17_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000347_17_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000347_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000347_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000347_5_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((sec_r000347_5_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000347_10_1 & 1) != 0)
  {
    if ((sec_r000347_14_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((sec_r000347_10_2 & 1) != 0)
  {
    if ((sec_r000347_14_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000347_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000347_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000347_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000347_11_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000347_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000347_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000347_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000347_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000347_14_1 & 1) != 0)
  {
    if ((sec_r000347_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((sec_r000347_14_2 & 1) != 0)
  {
    if ((sec_r000347_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000347_0_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000347_0_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000347_14_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000347_11_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000347_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000347_11_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000347_14_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000347_11_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000347_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000347_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000347_7_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((sec_r000347_7_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000347_0_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000347_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000347_0_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000347_0_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000347_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000347_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000347_14_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000347_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000347_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000347_2_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000347_14_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000347_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000347_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000347_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000347_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000347_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000347_7_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000347_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000347_7_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000347_7_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000347_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000347_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000347_0_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000347_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000347_0_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000347_0_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000347_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000347_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000347_13_1 & 1) != 0)
  {
    if ((sec_r000347_12_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_13_2 & 1) != 0)
  {
    if ((sec_r000347_12_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000347_6_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000347_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000347_6_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000347_6_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000347_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000347_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000347_1_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((sec_r000347_1_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000347_2_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_2_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000347_15_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000347_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000347_15_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000347_15_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000347_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000347_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000347_1_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000347_17_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000347_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000347_17_1 + 7) & 127;
  }
  if ((sec_r000347_1_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000347_17_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000347_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000347_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000347_17_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000347_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000347_17_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000347_17_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000347_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000347_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000347_14_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_14_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000347_1_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000347_12_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000347_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000347_12_1 + 7) & 127;
  }
  if ((sec_r000347_1_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000347_12_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000347_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000347_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000347_4_1 & 1) != 0)
  {
    if ((sec_r000347_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000347_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000347_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000347_8_1 + 7) & 127;
  }
  if ((sec_r000347_4_2 & 1) != 0)
  {
    if ((sec_r000347_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000347_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000347_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000347_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000347_13_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000347_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000347_13_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000347_13_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000347_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000347_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000347_4_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000347_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000347_4_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000347_4_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000347_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000347_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000347_1_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000347_9_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000347_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000347_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000347_1_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000347_9_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000347_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000347_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000347_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000347_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000347_0_1 & 1) != 0)
  {
    if ((sec_r000347_5_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000347_14_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000347_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000347_14_1 + 7) & 127;
  }
  if ((sec_r000347_0_2 & 1) != 0)
  {
    if ((sec_r000347_5_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000347_14_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000347_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000347_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000347_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000347_18_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000347_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000347_18_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000347_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000347_18_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000347_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000347_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000347_13_1 & 1) != 0)
  {
    if ((sec_r000347_13_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000347_6_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000347_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000347_6_1 + 7) & 127;
  }
  if ((sec_r000347_13_2 & 1) != 0)
  {
    if ((sec_r000347_13_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000347_6_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000347_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000347_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000347_8_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000347_8_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000347_14_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000347_7_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000347_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000347_7_1 + 7) & 127;
  }
  if ((sec_r000347_14_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000347_7_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000347_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000347_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000347_3_1 & 1) != 0)
  {
    if ((sec_r000347_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000347_3_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000347_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000347_3_1 + 7) & 127;
  }
  if ((sec_r000347_3_2 & 1) != 0)
  {
    if ((sec_r000347_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000347_3_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000347_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000347_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000347_12_1 & 1) != 0)
  {
    if ((sec_r000347_9_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000347_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000347_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000347_6_1 + 7) & 127;
  }
  if ((sec_r000347_12_2 & 1) != 0)
  {
    if ((sec_r000347_9_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000347_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000347_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000347_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000347_13_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000347_16_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000347_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000347_16_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000347_13_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000347_16_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000347_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000347_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000347_11_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000347_0_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000347_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000347_0_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000347_11_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000347_0_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000347_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000347_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000347_11_1 & 1) != 0)
  {
    if ((sec_r000347_4_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000347_1_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000347_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000347_1_1 + 7) & 127;
  }
  if ((sec_r000347_11_2 & 1) != 0)
  {
    if ((sec_r000347_4_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000347_1_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000347_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000347_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000347_3_1 & 1) != 0)
  {
    if ((sec_r000347_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000347_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000347_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000347_7_1 + 7) & 127;
  }
  if ((sec_r000347_3_2 & 1) != 0)
  {
    if ((sec_r000347_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000347_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000347_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000347_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000347_14_1 == pub_r000347_14_2);
  __CPROVER_assume(pub_r000347_3_1 == pub_r000347_3_2);
  __CPROVER_assume(sec_r000347_0_1 != sec_r000347_0_2);
  __CPROVER_assume(sec_r000347_9_1 != sec_r000347_9_2);
  __CPROVER_assume(sec_r000347_13_1 != sec_r000347_13_2);
  __CPROVER_assume(pub_r000347_17_1 == pub_r000347_17_2);
  __CPROVER_assume(sec_r000347_2_1 != sec_r000347_2_2);
  __CPROVER_assume(pub_r000347_6_1 == pub_r000347_6_2);
  __CPROVER_assume(sec_r000347_11_1 != sec_r000347_11_2);
  __CPROVER_assume(sec_r000347_3_1 != sec_r000347_3_2);
  __CPROVER_assume(pub_r000347_4_1 == pub_r000347_4_2);
  __CPROVER_assume(pub_r000347_9_1 == pub_r000347_9_2);
  __CPROVER_assume(pub_r000347_5_1 == pub_r000347_5_2);
  __CPROVER_assume(sec_r000347_1_1 != sec_r000347_1_2);
  __CPROVER_assume(pub_r000347_2_1 == pub_r000347_2_2);
  __CPROVER_assume(pub_r000347_11_1 == pub_r000347_11_2);
  __CPROVER_assume(sec_r000347_8_1 != sec_r000347_8_2);
  __CPROVER_assume(sec_r000347_7_1 != sec_r000347_7_2);
  __CPROVER_assume(pub_r000347_8_1 == pub_r000347_8_2);
  __CPROVER_assume(sec_r000347_4_1 != sec_r000347_4_2);
  __CPROVER_assume(sec_r000347_10_1 != sec_r000347_10_2);
  __CPROVER_assume(pub_r000347_15_1 == pub_r000347_15_2);
  __CPROVER_assume(sec_r000347_15_1 != sec_r000347_15_2);
  __CPROVER_assume(sec_r000347_14_1 != sec_r000347_14_2);
  __CPROVER_assume(pub_r000347_12_1 == pub_r000347_12_2);
  __CPROVER_assume(pub_r000347_1_1 == pub_r000347_1_2);
  __CPROVER_assume(sec_r000347_12_1 != sec_r000347_12_2);
  __CPROVER_assume(pub_r000347_18_1 == pub_r000347_18_2);
  __CPROVER_assume(pub_r000347_0_1 == pub_r000347_0_2);
  __CPROVER_assume(sec_r000347_6_1 != sec_r000347_6_2);
  __CPROVER_assume(sec_r000347_5_1 != sec_r000347_5_2);
  __CPROVER_assume(pub_r000347_10_1 == pub_r000347_10_2);
  __CPROVER_assume(pub_r000347_16_1 == pub_r000347_16_2);
  __CPROVER_assume(pub_r000347_7_1 == pub_r000347_7_2);
  __CPROVER_assume(pub_r000347_13_1 == pub_r000347_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.scale == st_var_1_2.scale);
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
  assert(stage_v_123_1 == stage_v_123_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(stage_v_126_1 == stage_v_126_2);
}


