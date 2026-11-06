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
struct DeviceConfig_R000248_4813_0
{
  short stop_bits;
  unsigned char id;
  unsigned char baud_rate;
  unsigned char parity;
  short timeout;
  int buffer[3];
};
struct StreamBuffer_R000248_4813_1
{
  short head;
  int state;
  int capacity;
  short watermark;
  int buffer[3];
};
struct Transaction_R000248_4813_2
{
  int account_id;
  int fee;
  unsigned char rate;
  int auth_code;
  int buffer[3];
};
struct CipherContext_R000248_4813_3
{
  int tag;
  int iv;
  int round_key;
  unsigned char nonce;
  int buffer[3];
};
union RegisterBank_R000248_4813_0
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
void fn_R000248_4813_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st_1 = {0};
  struct DeviceConfig_R000248_4813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_21_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_21_1 * 2)) + 5) & 127;
    aux_1 ^= margin_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_21_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_21_2 * 2)) + 5) & 127;
    aux_2 ^= margin_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_37_1)
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

  switch (cursor_37_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_78_1) & 63;
  aux_2 = (aux_2 + accumulator_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_21_1 == margin_21_2);
  assert(cursor_37_1 == cursor_37_2);
  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R000248_4813_0(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_21 > 34)
  {
    acc = ((acc + (margin_21 * 2)) + 5) & 127;
    aux ^= margin_21 & 15;
  }
  else
  {
    acc = ((acc - margin_21) + 11) & 127;
    aux += 3;
  }
  int cursor_37 = (aux + st.buffer[1]) & 3;
  switch (cursor_37)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_41_1 = local_arr_1[aux_1 % 3];
  int segment_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_41_2 * 2)) & 127;
  int delta_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_52_1)
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

  switch (delta_52_2)
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

  int sample_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_87_1) & 63;
  aux_2 = (aux_2 + sample_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_41_1 == segment_41_2);
  assert(delta_52_1 == delta_52_2);
  assert(sample_87_1 == sample_87_2);
}

int fn_R000248_4813_1(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int segment_41 = local_arr[aux % 3];
  acc = (acc + (segment_41 * 2)) & 127;
  int delta_52 = (aux + st.buffer[1]) & 3;
  switch (delta_52)
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

  int sample_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_87) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int parity_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_58_1) & 63;
  aux_2 = (aux_2 + parity_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_15_1 = local_arr_1[aux_1 % 3];
  int threshold_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_15_2 * 2)) & 127;
  int threshold_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_22_1)
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

  switch (threshold_22_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_58_1 == parity_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_15_1 == threshold_15_2);
  assert(threshold_22_1 == threshold_22_2);
}

int fn_R000248_4813_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int parity_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_58) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_15 = local_arr[aux % 3];
  acc = (acc + (threshold_15 * 2)) & 127;
  int threshold_22 = (aux + st.buffer[1]) & 3;
  switch (threshold_22)
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

void fn_R000248_4813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st_1 = {0};
  struct CipherContext_R000248_4813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_76_1 = local_arr_1[aux_1 % 3];
  int accumulator_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_76_2 * 2)) & 127;
  int stride_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_47_1) & 63;
  aux_2 = (aux_2 + stride_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_14_1)
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

  switch (phase_14_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_76_1 == accumulator_76_2);
  assert(stride_47_1 == stride_47_2);
  assert(phase_14_1 == phase_14_2);
}

int fn_R000248_4813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int accumulator_76 = local_arr[aux % 3];
  acc = (acc + (accumulator_76 * 2)) & 127;
  int stride_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_47) & 63;
  acc ^= aux;
  int phase_14 = (aux + st.buffer[1]) & 3;
  switch (phase_14)
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

void fn_R000248_4813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_48_1) & 63;
  aux_2 = (aux_2 + segment_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_44_1 = local_arr_1[aux_1 % 3];
  int stride_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_28_1)
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

  switch (stride_28_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(stride_28_1 == stride_28_2);
}

int fn_R000248_4813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_44 = local_arr[aux % 3];
  acc = (acc + (stride_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_28 = (aux + st.buffer[1]) & 3;
  switch (stride_28)
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

void fn_R000248_4813_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_42_1 = local_arr_1[aux_1 % 3];
  int anchor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_42_2 * 2)) & 127;
  int offset_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_84_1) & 63;
  aux_2 = (aux_2 + offset_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_42_1 == anchor_42_2);
  assert(offset_84_1 == offset_84_2);
}

int fn_R000248_4813_5(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int anchor_42 = local_arr[aux % 3];
  acc = (acc + (anchor_42 * 2)) & 127;
  int offset_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st_1 = {0};
  struct DeviceConfig_R000248_4813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_45_1 = local_arr_1[aux_1 % 3];
  int coefficient_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_45_2 * 2)) & 127;
  int window_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_91_1 > 49)
  {
    acc_1 = ((acc_1 + (window_91_1 * 2)) + 5) & 127;
    aux_1 ^= window_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_91_2 > 49)
  {
    acc_2 = ((acc_2 + (window_91_2 * 2)) + 5) & 127;
    aux_2 ^= window_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_44_1)
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

  switch (parity_44_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_45_1 == coefficient_45_2);
  assert(window_91_1 == window_91_2);
  assert(parity_44_1 == parity_44_2);
}

int fn_R000248_4813_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int coefficient_45 = local_arr[aux % 3];
  acc = (acc + (coefficient_45 * 2)) & 127;
  int window_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_91 > 49)
  {
    acc = ((acc + (window_91 * 2)) + 5) & 127;
    aux ^= window_91 & 15;
  }
  else
  {
    acc = ((acc - window_91) + 11) & 127;
    aux += 3;
  }
  int parity_44 = (aux + st.buffer[1]) & 3;
  switch (parity_44)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st_1 = {0};
  struct CipherContext_R000248_4813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_90_1 = local_arr_1[aux_1 % 3];
  int vector_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_90_2 * 2)) & 127;
  int parity_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_50_1)
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

  switch (parity_50_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_90_1 == vector_90_2);
  assert(parity_50_1 == parity_50_2);
}

int fn_R000248_4813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int vector_90 = local_arr[aux % 3];
  acc = (acc + (vector_90 * 2)) & 127;
  int parity_50 = (aux + st.buffer[1]) & 3;
  switch (parity_50)
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

void fn_R000248_4813_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_88_1 > 46)
  {
    acc_1 = ((acc_1 + (residue_88_1 * 2)) + 5) & 127;
    aux_1 ^= residue_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_88_2 > 46)
  {
    acc_2 = ((acc_2 + (residue_88_2 * 2)) + 5) & 127;
    aux_2 ^= residue_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_88_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_45_1 = local_arr_1[aux_1 % 3];
  int metric_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_45_2 * 2)) & 127;
  int stride_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_93_1) & 63;
  aux_2 = (aux_2 + stride_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_88_1 == residue_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_45_1 == metric_45_2);
  assert(stride_93_1 == stride_93_2);
}

int fn_R000248_4813_8(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_88 > 46)
  {
    acc = ((acc + (residue_88 * 2)) + 5) & 127;
    aux ^= residue_88 & 15;
  }
  else
  {
    acc = ((acc - residue_88) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_45 = local_arr[aux % 3];
  acc = (acc + (metric_45 * 2)) & 127;
  int stride_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st_1 = {0};
  struct CipherContext_R000248_4813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_53_1) & 63;
  aux_2 = (aux_2 + scale_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_53_1 == scale_53_2);
}

int fn_R000248_4813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_82_1)
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

  switch (weight_82_2)
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

  int window_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_65_1) & 63;
  aux_2 = (aux_2 + window_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_30_1 = local_arr_1[aux_1 % 3];
  int pivot_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_82_1 == weight_82_2);
  assert(window_65_1 == window_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_30_1 == pivot_30_2);
}

int fn_R000248_4813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_82 = (aux + st.buffer[1]) & 3;
  switch (weight_82)
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

  int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_30 = local_arr[aux % 3];
  acc = (acc + (pivot_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_22_1 > 50)
  {
    acc_1 = ((acc_1 + (weight_22_1 * 2)) + 5) & 127;
    aux_1 ^= weight_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_22_2 > 50)
  {
    acc_2 = ((acc_2 + (weight_22_2 * 2)) + 5) & 127;
    aux_2 ^= weight_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_80_1) & 63;
  aux_2 = (aux_2 + offset_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_22_1 == weight_22_2);
  assert(offset_80_1 == offset_80_2);
}

int fn_R000248_4813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_22 > 50)
  {
    acc = ((acc + (weight_22 * 2)) + 5) & 127;
    aux ^= weight_22 & 15;
  }
  else
  {
    acc = ((acc - weight_22) + 11) & 127;
    aux += 3;
  }
  int offset_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st_1 = {0};
  struct DeviceConfig_R000248_4813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tally_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_30_1)
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

  switch (tally_30_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_85_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_85_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_85_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_85_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_30_1 == tally_30_2);
  assert(index_reg_85_1 == index_reg_85_2);
}

int fn_R000248_4813_12(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000248_4813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tally_30 = (aux + st.buffer[1]) & 3;
  switch (tally_30)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_85 > 35)
  {
    acc = ((acc + (index_reg_85 * 2)) + 5) & 127;
    aux ^= index_reg_85 & 15;
  }
  else
  {
    acc = ((acc - index_reg_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000248_4813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quantum_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_12_1 > 20)
  {
    acc_1 = ((acc_1 + (quantum_12_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_12_2 > 20)
  {
    acc_2 = ((acc_2 + (quantum_12_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_55_1)
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

  switch (residue_55_2)
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

  int sample_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_38_1) & 63;
  aux_2 = (aux_2 + sample_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_12_1 == quantum_12_2);
  assert(residue_55_1 == residue_55_2);
  assert(sample_38_1 == sample_38_2);
}

int fn_R000248_4813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quantum_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_12 > 20)
  {
    acc = ((acc + (quantum_12 * 2)) + 5) & 127;
    aux ^= quantum_12 & 15;
  }
  else
  {
    acc = ((acc - quantum_12) + 11) & 127;
    aux += 3;
  }
  int residue_55 = (aux + st.buffer[1]) & 3;
  switch (residue_55)
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

  int sample_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000248_4813_2 st_1 = {0};
  struct Transaction_R000248_4813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_14_1 = local_arr_1[aux_1 % 3];
  int delta_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_14_2 * 2)) & 127;
  int checksum_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_79_1) & 63;
  aux_2 = (aux_2 + checksum_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_98_1)
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

  switch (tally_98_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_14_1 == delta_14_2);
  assert(checksum_79_1 == checksum_79_2);
  assert(tally_98_1 == tally_98_2);
}

int fn_R000248_4813_14(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000248_4813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int delta_14 = local_arr[aux % 3];
  acc = (acc + (delta_14 * 2)) & 127;
  int checksum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_79) & 63;
  acc ^= aux;
  int tally_98 = (aux + st.buffer[1]) & 3;
  switch (tally_98)
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

void fn_R000248_4813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_80_1 = local_arr_1[aux_1 % 3];
  int tally_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_80_2 * 2)) & 127;
  int anchor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_82_1 > 20)
  {
    acc_1 = ((acc_1 + (anchor_82_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_82_2 > 20)
  {
    acc_2 = ((acc_2 + (anchor_82_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_86_1) & 63;
  aux_2 = (aux_2 + parity_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_80_1 == tally_80_2);
  assert(anchor_82_1 == anchor_82_2);
  assert(parity_86_1 == parity_86_2);
}

int fn_R000248_4813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000248_4813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_80 = local_arr[aux % 3];
  acc = (acc + (tally_80 * 2)) & 127;
  int anchor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_82 > 20)
  {
    acc = ((acc + (anchor_82 * 2)) + 5) & 127;
    aux ^= anchor_82 & 15;
  }
  else
  {
    acc = ((acc - anchor_82) + 11) & 127;
    aux += 3;
  }
  int parity_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000248_4813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st_1 = {0};
  struct CipherContext_R000248_4813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_33_1)
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

  switch (margin_33_2)
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

  int weight_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_64_1) & 63;
  aux_2 = (aux_2 + weight_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_12_1 = local_arr_1[aux_1 % 3];
  int parity_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_33_1 == margin_33_2);
  assert(weight_64_1 == weight_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_12_1 == parity_12_2);
}

int fn_R000248_4813_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_33 = (aux + st.buffer[1]) & 3;
  switch (margin_33)
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

  int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_64) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_12 = local_arr[aux % 3];
  acc = (acc + (parity_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000248_4813_2 st_1 = {0};
  struct Transaction_R000248_4813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int checksum_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_77_1) & 63;
  aux_2 = (aux_2 + checksum_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_39_1)
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

  switch (quotient_39_2)
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
  int bound_40_1 = local_arr_1[aux_1 % 3];
  int bound_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_77_1 == checksum_77_2);
  assert(quotient_39_1 == quotient_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_40_1 == bound_40_2);
}

int fn_R000248_4813_17(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000248_4813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int checksum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_77) & 63;
  acc ^= aux;
  int quotient_39 = (aux + st.buffer[1]) & 3;
  switch (quotient_39)
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
  int bound_40 = local_arr[aux % 3];
  acc = (acc + (bound_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000248_4813_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st_1 = {0};
  struct CipherContext_R000248_4813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_94_1)
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

  switch (anchor_94_2)
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

  int tracker_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_32_1) & 63;
  aux_2 = (aux_2 + tracker_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_94_1 == anchor_94_2);
  assert(tracker_32_1 == tracker_32_2);
}

int fn_R000248_4813_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000248_4813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_94 = (aux + st.buffer[1]) & 3;
  switch (anchor_94)
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

  int tracker_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000248_0_1;
  int sec_r000248_0_2;
  int sec_r000248_1_1;
  int sec_r000248_1_2;
  int sec_r000248_2_1;
  int sec_r000248_2_2;
  int sec_r000248_3_1;
  int sec_r000248_3_2;
  int sec_r000248_4_1;
  int sec_r000248_4_2;
  int sec_r000248_5_1;
  int sec_r000248_5_2;
  int sec_r000248_6_1;
  int sec_r000248_6_2;
  int sec_r000248_7_1;
  int sec_r000248_7_2;
  int sec_r000248_8_1;
  int sec_r000248_8_2;
  int sec_r000248_9_1;
  int sec_r000248_9_2;
  int sec_r000248_10_1;
  int sec_r000248_10_2;
  int sec_r000248_11_1;
  int sec_r000248_11_2;
  int sec_r000248_12_1;
  int sec_r000248_12_2;
  int sec_r000248_13_1;
  int sec_r000248_13_2;
  int sec_r000248_14_1;
  int sec_r000248_14_2;
  int sec_r000248_15_1;
  int sec_r000248_15_2;
  int sec_r000248_16_1;
  int sec_r000248_16_2;
  int sec_r000248_17_1;
  int sec_r000248_17_2;
  int sec_r000248_18_1;
  int sec_r000248_18_2;
  int sec_r000248_19_1;
  int sec_r000248_19_2;
  int sec_r000248_20_1;
  int sec_r000248_20_2;
  int sec_r000248_21_1;
  int sec_r000248_21_2;
  int sec_r000248_22_1;
  int sec_r000248_22_2;
  int sec_r000248_23_1;
  int sec_r000248_23_2;
  int pub_r000248_0_1;
  int pub_r000248_0_2;
  int pub_r000248_1_1;
  int pub_r000248_1_2;
  int pub_r000248_2_1;
  int pub_r000248_2_2;
  int pub_r000248_3_1;
  int pub_r000248_3_2;
  int pub_r000248_4_1;
  int pub_r000248_4_2;
  int pub_r000248_5_1;
  int pub_r000248_5_2;
  int pub_r000248_6_1;
  int pub_r000248_6_2;
  int pub_r000248_7_1;
  int pub_r000248_7_2;
  int pub_r000248_8_1;
  int pub_r000248_8_2;
  int pub_r000248_9_1;
  int pub_r000248_9_2;
  int pub_r000248_10_1;
  int pub_r000248_10_2;
  int pub_r000248_11_1;
  int pub_r000248_11_2;
  int pub_r000248_12_1;
  int pub_r000248_12_2;
  int pub_r000248_13_1;
  int pub_r000248_13_2;
  int pub_r000248_14_1;
  int pub_r000248_14_2;
  int pub_r000248_15_1;
  int pub_r000248_15_2;
  int pub_r000248_16_1;
  int pub_r000248_16_2;
  int pub_r000248_17_1;
  int pub_r000248_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000248_0_1 >= (-100)) && (pub_r000248_0_1 <= 100));
  __CPROVER_assume((pub_r000248_0_2 >= (-100)) && (pub_r000248_0_2 <= 100));
  __CPROVER_assume((pub_r000248_1_1 >= (-100)) && (pub_r000248_1_1 <= 100));
  __CPROVER_assume((pub_r000248_1_2 >= (-100)) && (pub_r000248_1_2 <= 100));
  __CPROVER_assume((pub_r000248_2_1 >= (-100)) && (pub_r000248_2_1 <= 100));
  __CPROVER_assume((pub_r000248_2_2 >= (-100)) && (pub_r000248_2_2 <= 100));
  __CPROVER_assume((pub_r000248_3_1 >= (-100)) && (pub_r000248_3_1 <= 100));
  __CPROVER_assume((pub_r000248_3_2 >= (-100)) && (pub_r000248_3_2 <= 100));
  __CPROVER_assume((pub_r000248_4_1 >= (-100)) && (pub_r000248_4_1 <= 100));
  __CPROVER_assume((pub_r000248_4_2 >= (-100)) && (pub_r000248_4_2 <= 100));
  __CPROVER_assume((pub_r000248_5_1 >= (-100)) && (pub_r000248_5_1 <= 100));
  __CPROVER_assume((pub_r000248_5_2 >= (-100)) && (pub_r000248_5_2 <= 100));
  __CPROVER_assume((pub_r000248_6_1 >= (-100)) && (pub_r000248_6_1 <= 100));
  __CPROVER_assume((pub_r000248_6_2 >= (-100)) && (pub_r000248_6_2 <= 100));
  __CPROVER_assume((pub_r000248_7_1 >= (-100)) && (pub_r000248_7_1 <= 100));
  __CPROVER_assume((pub_r000248_7_2 >= (-100)) && (pub_r000248_7_2 <= 100));
  __CPROVER_assume((pub_r000248_8_1 >= (-100)) && (pub_r000248_8_1 <= 100));
  __CPROVER_assume((pub_r000248_8_2 >= (-100)) && (pub_r000248_8_2 <= 100));
  __CPROVER_assume((pub_r000248_9_1 >= (-100)) && (pub_r000248_9_1 <= 100));
  __CPROVER_assume((pub_r000248_9_2 >= (-100)) && (pub_r000248_9_2 <= 100));
  __CPROVER_assume((pub_r000248_10_1 >= (-100)) && (pub_r000248_10_1 <= 100));
  __CPROVER_assume((pub_r000248_10_2 >= (-100)) && (pub_r000248_10_2 <= 100));
  __CPROVER_assume((pub_r000248_11_1 >= (-100)) && (pub_r000248_11_1 <= 100));
  __CPROVER_assume((pub_r000248_11_2 >= (-100)) && (pub_r000248_11_2 <= 100));
  __CPROVER_assume((pub_r000248_12_1 >= (-100)) && (pub_r000248_12_1 <= 100));
  __CPROVER_assume((pub_r000248_12_2 >= (-100)) && (pub_r000248_12_2 <= 100));
  __CPROVER_assume((pub_r000248_13_1 >= (-100)) && (pub_r000248_13_1 <= 100));
  __CPROVER_assume((pub_r000248_13_2 >= (-100)) && (pub_r000248_13_2 <= 100));
  __CPROVER_assume((pub_r000248_14_1 >= (-100)) && (pub_r000248_14_1 <= 100));
  __CPROVER_assume((pub_r000248_14_2 >= (-100)) && (pub_r000248_14_2 <= 100));
  __CPROVER_assume((pub_r000248_15_1 >= (-100)) && (pub_r000248_15_1 <= 100));
  __CPROVER_assume((pub_r000248_15_2 >= (-100)) && (pub_r000248_15_2 <= 100));
  __CPROVER_assume((pub_r000248_16_1 >= (-100)) && (pub_r000248_16_1 <= 100));
  __CPROVER_assume((pub_r000248_16_2 >= (-100)) && (pub_r000248_16_2 <= 100));
  __CPROVER_assume((pub_r000248_17_1 >= (-100)) && (pub_r000248_17_1 <= 100));
  __CPROVER_assume((pub_r000248_17_2 >= (-100)) && (pub_r000248_17_2 <= 100));
  __CPROVER_assume((sec_r000248_0_1 >= 0) && (sec_r000248_0_1 <= 255));
  __CPROVER_assume((sec_r000248_0_2 >= 0) && (sec_r000248_0_2 <= 255));
  __CPROVER_assume((sec_r000248_1_1 >= 0) && (sec_r000248_1_1 <= 255));
  __CPROVER_assume((sec_r000248_1_2 >= 0) && (sec_r000248_1_2 <= 255));
  __CPROVER_assume((sec_r000248_2_1 >= 0) && (sec_r000248_2_1 <= 255));
  __CPROVER_assume((sec_r000248_2_2 >= 0) && (sec_r000248_2_2 <= 255));
  __CPROVER_assume((sec_r000248_3_1 >= 0) && (sec_r000248_3_1 <= 255));
  __CPROVER_assume((sec_r000248_3_2 >= 0) && (sec_r000248_3_2 <= 255));
  __CPROVER_assume((sec_r000248_4_1 >= 0) && (sec_r000248_4_1 <= 255));
  __CPROVER_assume((sec_r000248_4_2 >= 0) && (sec_r000248_4_2 <= 255));
  __CPROVER_assume((sec_r000248_5_1 >= 0) && (sec_r000248_5_1 <= 255));
  __CPROVER_assume((sec_r000248_5_2 >= 0) && (sec_r000248_5_2 <= 255));
  __CPROVER_assume((sec_r000248_6_1 >= 0) && (sec_r000248_6_1 <= 255));
  __CPROVER_assume((sec_r000248_6_2 >= 0) && (sec_r000248_6_2 <= 255));
  __CPROVER_assume((sec_r000248_7_1 >= 0) && (sec_r000248_7_1 <= 255));
  __CPROVER_assume((sec_r000248_7_2 >= 0) && (sec_r000248_7_2 <= 255));
  __CPROVER_assume((sec_r000248_8_1 >= 0) && (sec_r000248_8_1 <= 255));
  __CPROVER_assume((sec_r000248_8_2 >= 0) && (sec_r000248_8_2 <= 255));
  __CPROVER_assume((sec_r000248_9_1 >= 0) && (sec_r000248_9_1 <= 255));
  __CPROVER_assume((sec_r000248_9_2 >= 0) && (sec_r000248_9_2 <= 255));
  __CPROVER_assume((sec_r000248_10_1 >= 0) && (sec_r000248_10_1 <= 255));
  __CPROVER_assume((sec_r000248_10_2 >= 0) && (sec_r000248_10_2 <= 255));
  __CPROVER_assume((sec_r000248_11_1 >= 0) && (sec_r000248_11_1 <= 255));
  __CPROVER_assume((sec_r000248_11_2 >= 0) && (sec_r000248_11_2 <= 255));
  __CPROVER_assume((sec_r000248_12_1 >= 0) && (sec_r000248_12_1 <= 255));
  __CPROVER_assume((sec_r000248_12_2 >= 0) && (sec_r000248_12_2 <= 255));
  __CPROVER_assume((sec_r000248_13_1 >= 0) && (sec_r000248_13_1 <= 255));
  __CPROVER_assume((sec_r000248_13_2 >= 0) && (sec_r000248_13_2 <= 255));
  __CPROVER_assume((sec_r000248_14_1 >= 0) && (sec_r000248_14_1 <= 255));
  __CPROVER_assume((sec_r000248_14_2 >= 0) && (sec_r000248_14_2 <= 255));
  __CPROVER_assume((sec_r000248_15_1 >= 0) && (sec_r000248_15_1 <= 255));
  __CPROVER_assume((sec_r000248_15_2 >= 0) && (sec_r000248_15_2 <= 255));
  __CPROVER_assume((sec_r000248_16_1 >= 0) && (sec_r000248_16_1 <= 255));
  __CPROVER_assume((sec_r000248_16_2 >= 0) && (sec_r000248_16_2 <= 255));
  __CPROVER_assume((sec_r000248_17_1 >= 0) && (sec_r000248_17_1 <= 255));
  __CPROVER_assume((sec_r000248_17_2 >= 0) && (sec_r000248_17_2 <= 255));
  __CPROVER_assume((sec_r000248_18_1 >= 0) && (sec_r000248_18_1 <= 255));
  __CPROVER_assume((sec_r000248_18_2 >= 0) && (sec_r000248_18_2 <= 255));
  __CPROVER_assume((sec_r000248_19_1 >= 0) && (sec_r000248_19_1 <= 255));
  __CPROVER_assume((sec_r000248_19_2 >= 0) && (sec_r000248_19_2 <= 255));
  __CPROVER_assume((sec_r000248_20_1 >= 0) && (sec_r000248_20_1 <= 255));
  __CPROVER_assume((sec_r000248_20_2 >= 0) && (sec_r000248_20_2 <= 255));
  __CPROVER_assume((sec_r000248_21_1 >= 0) && (sec_r000248_21_1 <= 255));
  __CPROVER_assume((sec_r000248_21_2 >= 0) && (sec_r000248_21_2 <= 255));
  __CPROVER_assume((sec_r000248_22_1 >= 0) && (sec_r000248_22_1 <= 255));
  __CPROVER_assume((sec_r000248_22_2 >= 0) && (sec_r000248_22_2 <= 255));
  __CPROVER_assume((sec_r000248_23_1 >= 0) && (sec_r000248_23_1 <= 255));
  __CPROVER_assume((sec_r000248_23_2 >= 0) && (sec_r000248_23_2 <= 255));
  struct DeviceConfig_R000248_4813_0 st_var_0_1 = {0};
  struct DeviceConfig_R000248_4813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000248_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000248_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000248_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000248_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000248_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000248_0_2 + 7) & 15;
  struct StreamBuffer_R000248_4813_1 st_var_1_1 = {0};
  struct StreamBuffer_R000248_4813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000248_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000248_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000248_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000248_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000248_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000248_0_2 + 9) & 15;
  struct Transaction_R000248_4813_2 st_var_2_1 = {0};
  struct Transaction_R000248_4813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000248_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000248_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000248_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000248_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000248_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000248_0_2 + 11) & 15;
  struct CipherContext_R000248_4813_3 st_var_3_1 = {0};
  struct CipherContext_R000248_4813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000248_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000248_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000248_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000248_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000248_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000248_0_2 + 13) & 15;
  union RegisterBank_R000248_4813_0 u_var_1;
  union RegisterBank_R000248_4813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 34)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 34)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 20) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 29)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 29)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 35)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 35)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((st_var_2_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_2_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 50)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 50)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 55) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 34)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 34)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 29)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 29)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (st_var_3_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_3_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000248_13_1 & 1) == step_1)
    {
      stage_v_68_1 = ((stage_v_68_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_68_1 = ((stage_v_68_1 + pub_r000248_17_1) + 5) & 63;
    }
    if ((sec_r000248_13_2 & 1) == step_2)
    {
      stage_v_68_2 = ((stage_v_68_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_68_2 = ((stage_v_68_2 + pub_r000248_17_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_69_1 = ((stage_v_69_1 + (step_1 * 4)) + pub_r000248_13_1) & 63;
    }
    else
    {
      stage_v_69_1 = ((stage_v_69_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_69_2 = ((stage_v_69_2 + (step_2 * 4)) + pub_r000248_13_2) & 63;
    }
    else
    {
      stage_v_69_2 = ((stage_v_69_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_70_1 = ((stage_v_70_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_70_1 = ((stage_v_70_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_70_2 = ((stage_v_70_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_70_2 = ((stage_v_70_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_70_1 & 1) == step_1)
    {
      stage_v_71_1 = ((stage_v_71_1 + (step_1 * 4)) + pub_r000248_3_1) & 63;
    }
    else
    {
      stage_v_71_1 = ((stage_v_71_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((stage_v_70_2 & 1) == step_2)
    {
      stage_v_71_2 = ((stage_v_71_2 + (step_2 * 4)) + pub_r000248_3_2) & 63;
    }
    else
    {
      stage_v_71_2 = ((stage_v_71_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_70_1 & 1) == step_1)
    {
      stage_v_72_1 = ((stage_v_72_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_72_1 = ((stage_v_72_1 + pub_r000248_17_1) + 5) & 63;
    }
    if ((stage_v_70_2 & 1) == step_2)
    {
      stage_v_72_2 = ((stage_v_72_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_72_2 = ((stage_v_72_2 + pub_r000248_17_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_73_1 = ((stage_v_73_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_73_1 = ((stage_v_73_1 + pub_r000248_0_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_73_2 = ((stage_v_73_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_73_2 = ((stage_v_73_2 + pub_r000248_0_2) + 5) & 63;
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
    if ((sec_r000248_4_1 & 1) == step_1)
    {
      stage_v_74_1 = ((stage_v_74_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_74_1 = ((stage_v_74_1 + pub_r000248_13_1) + 5) & 63;
    }
    if ((sec_r000248_4_2 & 1) == step_2)
    {
      stage_v_74_2 = ((stage_v_74_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_74_2 = ((stage_v_74_2 + pub_r000248_13_2) + 5) & 63;
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
    if ((sec_r000248_9_1 & 1) == step_1)
    {
      stage_v_75_1 = ((stage_v_75_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_75_1 = ((stage_v_75_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((sec_r000248_9_2 & 1) == step_2)
    {
      stage_v_75_2 = ((stage_v_75_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_75_2 = ((stage_v_75_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((sec_r000248_22_1 & 1) == step_1)
    {
      stage_v_76_1 = ((stage_v_76_1 + (step_1 * 4)) + pub_r000248_0_1) & 63;
    }
    else
    {
      stage_v_76_1 = ((stage_v_76_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((sec_r000248_22_2 & 1) == step_2)
    {
      stage_v_76_2 = ((stage_v_76_2 + (step_2 * 4)) + pub_r000248_0_2) & 63;
    }
    else
    {
      stage_v_76_2 = ((stage_v_76_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_73_1 & 1) == step_1)
    {
      stage_v_77_1 = ((stage_v_77_1 + (step_1 * 4)) + pub_r000248_9_1) & 63;
    }
    else
    {
      stage_v_77_1 = ((stage_v_77_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_73_2 & 1) == step_2)
    {
      stage_v_77_2 = ((stage_v_77_2 + (step_2 * 4)) + pub_r000248_9_2) & 63;
    }
    else
    {
      stage_v_77_2 = ((stage_v_77_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((sec_r000248_9_1 & 1) == step_1)
    {
      stage_v_78_1 = ((stage_v_78_1 + (step_1 * 4)) + pub_r000248_9_1) & 63;
    }
    else
    {
      stage_v_78_1 = ((stage_v_78_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((sec_r000248_9_2 & 1) == step_2)
    {
      stage_v_78_2 = ((stage_v_78_2 + (step_2 * 4)) + pub_r000248_9_2) & 63;
    }
    else
    {
      stage_v_78_2 = ((stage_v_78_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((stage_v_75_1 & 1) == step_1)
    {
      stage_v_79_1 = ((stage_v_79_1 + (step_1 * 4)) + pub_r000248_12_1) & 63;
    }
    else
    {
      stage_v_79_1 = ((stage_v_79_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_75_2 & 1) == step_2)
    {
      stage_v_79_2 = ((stage_v_79_2 + (step_2 * 4)) + pub_r000248_12_2) & 63;
    }
    else
    {
      stage_v_79_2 = ((stage_v_79_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_76_1 & 1) == step_1)
    {
      stage_v_80_1 = ((stage_v_80_1 + (step_1 * 4)) + pub_r000248_14_1) & 63;
    }
    else
    {
      stage_v_80_1 = ((stage_v_80_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_76_2 & 1) == step_2)
    {
      stage_v_80_2 = ((stage_v_80_2 + (step_2 * 4)) + pub_r000248_14_2) & 63;
    }
    else
    {
      stage_v_80_2 = ((stage_v_80_2 + pub_r000248_12_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_81_1 = ((stage_v_81_1 + (step_1 * 4)) + pub_r000248_12_1) & 63;
    }
    else
    {
      stage_v_81_1 = ((stage_v_81_1 + pub_r000248_8_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_81_2 = ((stage_v_81_2 + (step_2 * 4)) + pub_r000248_12_2) & 63;
    }
    else
    {
      stage_v_81_2 = ((stage_v_81_2 + pub_r000248_8_2) + 5) & 63;
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
    if ((sec_r000248_7_1 & 1) == step_1)
    {
      stage_v_82_1 = ((stage_v_82_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_82_1 = ((stage_v_82_1 + pub_r000248_2_1) + 5) & 63;
    }
    if ((sec_r000248_7_2 & 1) == step_2)
    {
      stage_v_82_2 = ((stage_v_82_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_82_2 = ((stage_v_82_2 + pub_r000248_2_2) + 5) & 63;
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
    if ((stage_v_71_1 & 1) == step_1)
    {
      stage_v_83_1 = ((stage_v_83_1 + (step_1 * 4)) + pub_r000248_13_1) & 63;
    }
    else
    {
      stage_v_83_1 = ((stage_v_83_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_71_2 & 1) == step_2)
    {
      stage_v_83_2 = ((stage_v_83_2 + (step_2 * 4)) + pub_r000248_13_2) & 63;
    }
    else
    {
      stage_v_83_2 = ((stage_v_83_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((sec_r000248_16_1 & 1) == step_1)
    {
      stage_v_84_1 = ((stage_v_84_1 + (step_1 * 4)) + pub_r000248_13_1) & 63;
    }
    else
    {
      stage_v_84_1 = ((stage_v_84_1 + pub_r000248_9_1) + 5) & 63;
    }
    if ((sec_r000248_16_2 & 1) == step_2)
    {
      stage_v_84_2 = ((stage_v_84_2 + (step_2 * 4)) + pub_r000248_13_2) & 63;
    }
    else
    {
      stage_v_84_2 = ((stage_v_84_2 + pub_r000248_9_2) + 5) & 63;
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
    if ((sec_r000248_21_1 & 1) == step_1)
    {
      stage_v_85_1 = ((stage_v_85_1 + (step_1 * 4)) + pub_r000248_10_1) & 63;
    }
    else
    {
      stage_v_85_1 = ((stage_v_85_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((sec_r000248_21_2 & 1) == step_2)
    {
      stage_v_85_2 = ((stage_v_85_2 + (step_2 * 4)) + pub_r000248_10_2) & 63;
    }
    else
    {
      stage_v_85_2 = ((stage_v_85_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_86_1 = ((stage_v_86_1 + (step_1 * 4)) + pub_r000248_5_1) & 63;
    }
    else
    {
      stage_v_86_1 = ((stage_v_86_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_86_2 = ((stage_v_86_2 + (step_2 * 4)) + pub_r000248_5_2) & 63;
    }
    else
    {
      stage_v_86_2 = ((stage_v_86_2 + pub_r000248_12_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_87_1 = ((stage_v_87_1 + (step_1 * 4)) + pub_r000248_3_1) & 63;
    }
    else
    {
      stage_v_87_1 = ((stage_v_87_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_87_2 = ((stage_v_87_2 + (step_2 * 4)) + pub_r000248_3_2) & 63;
    }
    else
    {
      stage_v_87_2 = ((stage_v_87_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((sec_r000248_0_1 & 1) == step_1)
    {
      stage_v_88_1 = ((stage_v_88_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_88_1 = ((stage_v_88_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((sec_r000248_0_2 & 1) == step_2)
    {
      stage_v_88_2 = ((stage_v_88_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_88_2 = ((stage_v_88_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_89_1 = ((stage_v_89_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_89_1 = ((stage_v_89_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_89_2 = ((stage_v_89_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_89_2 = ((stage_v_89_2 + pub_r000248_12_2) + 5) & 63;
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
    if ((stage_v_73_1 & 1) == step_1)
    {
      stage_v_90_1 = ((stage_v_90_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_90_1 = ((stage_v_90_1 + pub_r000248_4_1) + 5) & 63;
    }
    if ((stage_v_73_2 & 1) == step_2)
    {
      stage_v_90_2 = ((stage_v_90_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_90_2 = ((stage_v_90_2 + pub_r000248_4_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_91_1 = ((stage_v_91_1 + (step_1 * 4)) + pub_r000248_5_1) & 63;
    }
    else
    {
      stage_v_91_1 = ((stage_v_91_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_91_2 = ((stage_v_91_2 + (step_2 * 4)) + pub_r000248_5_2) & 63;
    }
    else
    {
      stage_v_91_2 = ((stage_v_91_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_90_1 & 1) == step_1)
    {
      stage_v_92_1 = ((stage_v_92_1 + (step_1 * 4)) + pub_r000248_9_1) & 63;
    }
    else
    {
      stage_v_92_1 = ((stage_v_92_1 + pub_r000248_14_1) + 5) & 63;
    }
    if ((stage_v_90_2 & 1) == step_2)
    {
      stage_v_92_2 = ((stage_v_92_2 + (step_2 * 4)) + pub_r000248_9_2) & 63;
    }
    else
    {
      stage_v_92_2 = ((stage_v_92_2 + pub_r000248_14_2) + 5) & 63;
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
    if ((sec_r000248_22_1 & 1) == step_1)
    {
      stage_v_93_1 = ((stage_v_93_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_93_1 = ((stage_v_93_1 + pub_r000248_5_1) + 5) & 63;
    }
    if ((sec_r000248_22_2 & 1) == step_2)
    {
      stage_v_93_2 = ((stage_v_93_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_93_2 = ((stage_v_93_2 + pub_r000248_5_2) + 5) & 63;
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
    if ((stage_v_85_1 & 1) == step_1)
    {
      stage_v_94_1 = ((stage_v_94_1 + (step_1 * 4)) + pub_r000248_12_1) & 63;
    }
    else
    {
      stage_v_94_1 = ((stage_v_94_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_85_2 & 1) == step_2)
    {
      stage_v_94_2 = ((stage_v_94_2 + (step_2 * 4)) + pub_r000248_12_2) & 63;
    }
    else
    {
      stage_v_94_2 = ((stage_v_94_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((sec_r000248_23_1 & 1) == step_1)
    {
      stage_v_95_1 = ((stage_v_95_1 + (step_1 * 4)) + pub_r000248_2_1) & 63;
    }
    else
    {
      stage_v_95_1 = ((stage_v_95_1 + pub_r000248_15_1) + 5) & 63;
    }
    if ((sec_r000248_23_2 & 1) == step_2)
    {
      stage_v_95_2 = ((stage_v_95_2 + (step_2 * 4)) + pub_r000248_2_2) & 63;
    }
    else
    {
      stage_v_95_2 = ((stage_v_95_2 + pub_r000248_15_2) + 5) & 63;
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
    if ((sec_r000248_5_1 & 1) == step_1)
    {
      stage_v_96_1 = ((stage_v_96_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_96_1 = ((stage_v_96_1 + pub_r000248_13_1) + 5) & 63;
    }
    if ((sec_r000248_5_2 & 1) == step_2)
    {
      stage_v_96_2 = ((stage_v_96_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_96_2 = ((stage_v_96_2 + pub_r000248_13_2) + 5) & 63;
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
    if ((stage_v_89_1 & 1) == step_1)
    {
      stage_v_97_1 = ((stage_v_97_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_97_1 = ((stage_v_97_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_89_2 & 1) == step_2)
    {
      stage_v_97_2 = ((stage_v_97_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_97_2 = ((stage_v_97_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((stage_v_92_1 & 1) == step_1)
    {
      stage_v_98_1 = ((stage_v_98_1 + (step_1 * 4)) + pub_r000248_10_1) & 63;
    }
    else
    {
      stage_v_98_1 = ((stage_v_98_1 + pub_r000248_4_1) + 5) & 63;
    }
    if ((stage_v_92_2 & 1) == step_2)
    {
      stage_v_98_2 = ((stage_v_98_2 + (step_2 * 4)) + pub_r000248_10_2) & 63;
    }
    else
    {
      stage_v_98_2 = ((stage_v_98_2 + pub_r000248_4_2) + 5) & 63;
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
    if ((stage_v_92_1 & 1) == step_1)
    {
      stage_v_99_1 = ((stage_v_99_1 + (step_1 * 4)) + pub_r000248_3_1) & 63;
    }
    else
    {
      stage_v_99_1 = ((stage_v_99_1 + pub_r000248_9_1) + 5) & 63;
    }
    if ((stage_v_92_2 & 1) == step_2)
    {
      stage_v_99_2 = ((stage_v_99_2 + (step_2 * 4)) + pub_r000248_3_2) & 63;
    }
    else
    {
      stage_v_99_2 = ((stage_v_99_2 + pub_r000248_9_2) + 5) & 63;
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
    if ((sec_r000248_23_1 & 1) == step_1)
    {
      stage_v_100_1 = ((stage_v_100_1 + (step_1 * 4)) + pub_r000248_1_1) & 63;
    }
    else
    {
      stage_v_100_1 = ((stage_v_100_1 + pub_r000248_9_1) + 5) & 63;
    }
    if ((sec_r000248_23_2 & 1) == step_2)
    {
      stage_v_100_2 = ((stage_v_100_2 + (step_2 * 4)) + pub_r000248_1_2) & 63;
    }
    else
    {
      stage_v_100_2 = ((stage_v_100_2 + pub_r000248_9_2) + 5) & 63;
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
    if ((stage_v_70_1 & 1) == step_1)
    {
      stage_v_101_1 = ((stage_v_101_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_101_1 = ((stage_v_101_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_70_2 & 1) == step_2)
    {
      stage_v_101_2 = ((stage_v_101_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_101_2 = ((stage_v_101_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_102_1 = ((stage_v_102_1 + (step_1 * 4)) + pub_r000248_5_1) & 63;
    }
    else
    {
      stage_v_102_1 = ((stage_v_102_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_102_2 = ((stage_v_102_2 + (step_2 * 4)) + pub_r000248_5_2) & 63;
    }
    else
    {
      stage_v_102_2 = ((stage_v_102_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((stage_v_85_1 & 1) == step_1)
    {
      stage_v_103_1 = ((stage_v_103_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_103_1 = ((stage_v_103_1 + pub_r000248_5_1) + 5) & 63;
    }
    if ((stage_v_85_2 & 1) == step_2)
    {
      stage_v_103_2 = ((stage_v_103_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_103_2 = ((stage_v_103_2 + pub_r000248_5_2) + 5) & 63;
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
    if ((stage_v_90_1 & 1) == step_1)
    {
      stage_v_104_1 = ((stage_v_104_1 + (step_1 * 4)) + pub_r000248_14_1) & 63;
    }
    else
    {
      stage_v_104_1 = ((stage_v_104_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_90_2 & 1) == step_2)
    {
      stage_v_104_2 = ((stage_v_104_2 + (step_2 * 4)) + pub_r000248_14_2) & 63;
    }
    else
    {
      stage_v_104_2 = ((stage_v_104_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((sec_r000248_9_1 & 1) == step_1)
    {
      stage_v_105_1 = ((stage_v_105_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_105_1 = ((stage_v_105_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((sec_r000248_9_2 & 1) == step_2)
    {
      stage_v_105_2 = ((stage_v_105_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_105_2 = ((stage_v_105_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((stage_v_95_1 & 1) == step_1)
    {
      stage_v_106_1 = ((stage_v_106_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_106_1 = ((stage_v_106_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_95_2 & 1) == step_2)
    {
      stage_v_106_2 = ((stage_v_106_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_106_2 = ((stage_v_106_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_79_1 & 1) == step_1)
    {
      stage_v_107_1 = ((stage_v_107_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_107_1 = ((stage_v_107_1 + pub_r000248_5_1) + 5) & 63;
    }
    if ((stage_v_79_2 & 1) == step_2)
    {
      stage_v_107_2 = ((stage_v_107_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_107_2 = ((stage_v_107_2 + pub_r000248_5_2) + 5) & 63;
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
    if ((sec_r000248_17_1 & 1) == step_1)
    {
      stage_v_108_1 = ((stage_v_108_1 + (step_1 * 4)) + pub_r000248_13_1) & 63;
    }
    else
    {
      stage_v_108_1 = ((stage_v_108_1 + pub_r000248_17_1) + 5) & 63;
    }
    if ((sec_r000248_17_2 & 1) == step_2)
    {
      stage_v_108_2 = ((stage_v_108_2 + (step_2 * 4)) + pub_r000248_13_2) & 63;
    }
    else
    {
      stage_v_108_2 = ((stage_v_108_2 + pub_r000248_17_2) + 5) & 63;
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
    if ((stage_v_81_1 & 1) == step_1)
    {
      stage_v_109_1 = ((stage_v_109_1 + (step_1 * 4)) + pub_r000248_2_1) & 63;
    }
    else
    {
      stage_v_109_1 = ((stage_v_109_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_81_2 & 1) == step_2)
    {
      stage_v_109_2 = ((stage_v_109_2 + (step_2 * 4)) + pub_r000248_2_2) & 63;
    }
    else
    {
      stage_v_109_2 = ((stage_v_109_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((stage_v_97_1 & 1) == step_1)
    {
      stage_v_110_1 = ((stage_v_110_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_110_1 = ((stage_v_110_1 + pub_r000248_8_1) + 5) & 63;
    }
    if ((stage_v_97_2 & 1) == step_2)
    {
      stage_v_110_2 = ((stage_v_110_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_110_2 = ((stage_v_110_2 + pub_r000248_8_2) + 5) & 63;
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
    if ((stage_v_81_1 & 1) == step_1)
    {
      stage_v_111_1 = ((stage_v_111_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_111_1 = ((stage_v_111_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((stage_v_81_2 & 1) == step_2)
    {
      stage_v_111_2 = ((stage_v_111_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_111_2 = ((stage_v_111_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((sec_r000248_4_1 & 1) == step_1)
    {
      stage_v_112_1 = ((stage_v_112_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_112_1 = ((stage_v_112_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((sec_r000248_4_2 & 1) == step_2)
    {
      stage_v_112_2 = ((stage_v_112_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_112_2 = ((stage_v_112_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((stage_v_83_1 & 1) == step_1)
    {
      stage_v_113_1 = ((stage_v_113_1 + (step_1 * 4)) + pub_r000248_15_1) & 63;
    }
    else
    {
      stage_v_113_1 = ((stage_v_113_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_83_2 & 1) == step_2)
    {
      stage_v_113_2 = ((stage_v_113_2 + (step_2 * 4)) + pub_r000248_15_2) & 63;
    }
    else
    {
      stage_v_113_2 = ((stage_v_113_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((stage_v_78_1 & 1) == step_1)
    {
      stage_v_114_1 = ((stage_v_114_1 + (step_1 * 4)) + pub_r000248_3_1) & 63;
    }
    else
    {
      stage_v_114_1 = ((stage_v_114_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_78_2 & 1) == step_2)
    {
      stage_v_114_2 = ((stage_v_114_2 + (step_2 * 4)) + pub_r000248_3_2) & 63;
    }
    else
    {
      stage_v_114_2 = ((stage_v_114_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((stage_v_94_1 & 1) == step_1)
    {
      stage_v_115_1 = ((stage_v_115_1 + (step_1 * 4)) + pub_r000248_10_1) & 63;
    }
    else
    {
      stage_v_115_1 = ((stage_v_115_1 + pub_r000248_14_1) + 5) & 63;
    }
    if ((stage_v_94_2 & 1) == step_2)
    {
      stage_v_115_2 = ((stage_v_115_2 + (step_2 * 4)) + pub_r000248_10_2) & 63;
    }
    else
    {
      stage_v_115_2 = ((stage_v_115_2 + pub_r000248_14_2) + 5) & 63;
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
    if ((sec_r000248_23_1 & 1) == step_1)
    {
      stage_v_116_1 = ((stage_v_116_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_116_1 = ((stage_v_116_1 + pub_r000248_10_1) + 5) & 63;
    }
    if ((sec_r000248_23_2 & 1) == step_2)
    {
      stage_v_116_2 = ((stage_v_116_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_116_2 = ((stage_v_116_2 + pub_r000248_10_2) + 5) & 63;
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
    if ((sec_r000248_10_1 & 1) == step_1)
    {
      stage_v_117_1 = ((stage_v_117_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_117_1 = ((stage_v_117_1 + pub_r000248_13_1) + 5) & 63;
    }
    if ((sec_r000248_10_2 & 1) == step_2)
    {
      stage_v_117_2 = ((stage_v_117_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_117_2 = ((stage_v_117_2 + pub_r000248_13_2) + 5) & 63;
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
    if ((stage_v_106_1 & 1) == step_1)
    {
      stage_v_118_1 = ((stage_v_118_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_118_1 = ((stage_v_118_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_106_2 & 1) == step_2)
    {
      stage_v_118_2 = ((stage_v_118_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_118_2 = ((stage_v_118_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_119_1 = ((stage_v_119_1 + (step_1 * 4)) + pub_r000248_11_1) & 63;
    }
    else
    {
      stage_v_119_1 = ((stage_v_119_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_119_2 = ((stage_v_119_2 + (step_2 * 4)) + pub_r000248_11_2) & 63;
    }
    else
    {
      stage_v_119_2 = ((stage_v_119_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((stage_v_80_1 & 1) == step_1)
    {
      stage_v_120_1 = ((stage_v_120_1 + (step_1 * 4)) + pub_r000248_5_1) & 63;
    }
    else
    {
      stage_v_120_1 = ((stage_v_120_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((stage_v_80_2 & 1) == step_2)
    {
      stage_v_120_2 = ((stage_v_120_2 + (step_2 * 4)) + pub_r000248_5_2) & 63;
    }
    else
    {
      stage_v_120_2 = ((stage_v_120_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((sec_r000248_3_1 & 1) == step_1)
    {
      stage_v_121_1 = ((stage_v_121_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_121_1 = ((stage_v_121_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((sec_r000248_3_2 & 1) == step_2)
    {
      stage_v_121_2 = ((stage_v_121_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_121_2 = ((stage_v_121_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_122_1 = ((stage_v_122_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_122_1 = ((stage_v_122_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_122_2 = ((stage_v_122_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_122_2 = ((stage_v_122_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_98_1 & 1) == step_1)
    {
      stage_v_123_1 = ((stage_v_123_1 + (step_1 * 4)) + pub_r000248_16_1) & 63;
    }
    else
    {
      stage_v_123_1 = ((stage_v_123_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((stage_v_98_2 & 1) == step_2)
    {
      stage_v_123_2 = ((stage_v_123_2 + (step_2 * 4)) + pub_r000248_16_2) & 63;
    }
    else
    {
      stage_v_123_2 = ((stage_v_123_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((sec_r000248_12_1 & 1) == step_1)
    {
      stage_v_124_1 = ((stage_v_124_1 + (step_1 * 4)) + pub_r000248_0_1) & 63;
    }
    else
    {
      stage_v_124_1 = ((stage_v_124_1 + pub_r000248_3_1) + 5) & 63;
    }
    if ((sec_r000248_12_2 & 1) == step_2)
    {
      stage_v_124_2 = ((stage_v_124_2 + (step_2 * 4)) + pub_r000248_0_2) & 63;
    }
    else
    {
      stage_v_124_2 = ((stage_v_124_2 + pub_r000248_3_2) + 5) & 63;
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
    if ((stage_v_78_1 & 1) == step_1)
    {
      stage_v_125_1 = ((stage_v_125_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_125_1 = ((stage_v_125_1 + pub_r000248_4_1) + 5) & 63;
    }
    if ((stage_v_78_2 & 1) == step_2)
    {
      stage_v_125_2 = ((stage_v_125_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_125_2 = ((stage_v_125_2 + pub_r000248_4_2) + 5) & 63;
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
    if ((stage_v_99_1 & 1) == step_1)
    {
      stage_v_126_1 = ((stage_v_126_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_126_1 = ((stage_v_126_1 + pub_r000248_10_1) + 5) & 63;
    }
    if ((stage_v_99_2 & 1) == step_2)
    {
      stage_v_126_2 = ((stage_v_126_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_126_2 = ((stage_v_126_2 + pub_r000248_10_2) + 5) & 63;
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
    if ((sec_r000248_13_1 & 1) == step_1)
    {
      stage_v_127_1 = ((stage_v_127_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_127_1 = ((stage_v_127_1 + pub_r000248_2_1) + 5) & 63;
    }
    if ((sec_r000248_13_2 & 1) == step_2)
    {
      stage_v_127_2 = ((stage_v_127_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_127_2 = ((stage_v_127_2 + pub_r000248_2_2) + 5) & 63;
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
    if ((sec_r000248_21_1 & 1) == step_1)
    {
      stage_v_128_1 = ((stage_v_128_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_128_1 = ((stage_v_128_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((sec_r000248_21_2 & 1) == step_2)
    {
      stage_v_128_2 = ((stage_v_128_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_128_2 = ((stage_v_128_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_113_1 & 1) == step_1)
    {
      stage_v_129_1 = ((stage_v_129_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_129_1 = ((stage_v_129_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_113_2 & 1) == step_2)
    {
      stage_v_129_2 = ((stage_v_129_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_129_2 = ((stage_v_129_2 + pub_r000248_12_2) + 5) & 63;
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
    if ((stage_v_98_1 & 1) == step_1)
    {
      stage_v_130_1 = ((stage_v_130_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_130_1 = ((stage_v_130_1 + pub_r000248_14_1) + 5) & 63;
    }
    if ((stage_v_98_2 & 1) == step_2)
    {
      stage_v_130_2 = ((stage_v_130_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_130_2 = ((stage_v_130_2 + pub_r000248_14_2) + 5) & 63;
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
    if ((sec_r000248_13_1 & 1) == step_1)
    {
      stage_v_131_1 = ((stage_v_131_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_131_1 = ((stage_v_131_1 + pub_r000248_17_1) + 5) & 63;
    }
    if ((sec_r000248_13_2 & 1) == step_2)
    {
      stage_v_131_2 = ((stage_v_131_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_131_2 = ((stage_v_131_2 + pub_r000248_17_2) + 5) & 63;
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
    if ((sec_r000248_21_1 & 1) == step_1)
    {
      stage_v_132_1 = ((stage_v_132_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_132_1 = ((stage_v_132_1 + pub_r000248_13_1) + 5) & 63;
    }
    if ((sec_r000248_21_2 & 1) == step_2)
    {
      stage_v_132_2 = ((stage_v_132_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_132_2 = ((stage_v_132_2 + pub_r000248_13_2) + 5) & 63;
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
    if ((stage_v_71_1 & 1) == step_1)
    {
      stage_v_133_1 = ((stage_v_133_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_133_1 = ((stage_v_133_1 + pub_r000248_7_1) + 5) & 63;
    }
    if ((stage_v_71_2 & 1) == step_2)
    {
      stage_v_133_2 = ((stage_v_133_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_133_2 = ((stage_v_133_2 + pub_r000248_7_2) + 5) & 63;
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
    if ((stage_v_103_1 & 1) == step_1)
    {
      stage_v_134_1 = ((stage_v_134_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_134_1 = ((stage_v_134_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((stage_v_103_2 & 1) == step_2)
    {
      stage_v_134_2 = ((stage_v_134_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_134_2 = ((stage_v_134_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_127_1 & 1) == step_1)
    {
      stage_v_135_1 = ((stage_v_135_1 + (step_1 * 4)) + pub_r000248_9_1) & 63;
    }
    else
    {
      stage_v_135_1 = ((stage_v_135_1 + pub_r000248_0_1) + 5) & 63;
    }
    if ((stage_v_127_2 & 1) == step_2)
    {
      stage_v_135_2 = ((stage_v_135_2 + (step_2 * 4)) + pub_r000248_9_2) & 63;
    }
    else
    {
      stage_v_135_2 = ((stage_v_135_2 + pub_r000248_0_2) + 5) & 63;
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
    if ((stage_v_133_1 & 1) == step_1)
    {
      stage_v_136_1 = ((stage_v_136_1 + (step_1 * 4)) + pub_r000248_15_1) & 63;
    }
    else
    {
      stage_v_136_1 = ((stage_v_136_1 + pub_r000248_5_1) + 5) & 63;
    }
    if ((stage_v_133_2 & 1) == step_2)
    {
      stage_v_136_2 = ((stage_v_136_2 + (step_2 * 4)) + pub_r000248_15_2) & 63;
    }
    else
    {
      stage_v_136_2 = ((stage_v_136_2 + pub_r000248_5_2) + 5) & 63;
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
    if ((stage_v_118_1 & 1) == step_1)
    {
      stage_v_137_1 = ((stage_v_137_1 + (step_1 * 4)) + pub_r000248_8_1) & 63;
    }
    else
    {
      stage_v_137_1 = ((stage_v_137_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_118_2 & 1) == step_2)
    {
      stage_v_137_2 = ((stage_v_137_2 + (step_2 * 4)) + pub_r000248_8_2) & 63;
    }
    else
    {
      stage_v_137_2 = ((stage_v_137_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((sec_r000248_3_1 & 1) == step_1)
    {
      stage_v_138_1 = ((stage_v_138_1 + (step_1 * 4)) + pub_r000248_14_1) & 63;
    }
    else
    {
      stage_v_138_1 = ((stage_v_138_1 + pub_r000248_7_1) + 5) & 63;
    }
    if ((sec_r000248_3_2 & 1) == step_2)
    {
      stage_v_138_2 = ((stage_v_138_2 + (step_2 * 4)) + pub_r000248_14_2) & 63;
    }
    else
    {
      stage_v_138_2 = ((stage_v_138_2 + pub_r000248_7_2) + 5) & 63;
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
    if ((stage_v_120_1 & 1) == step_1)
    {
      stage_v_139_1 = ((stage_v_139_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_139_1 = ((stage_v_139_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_120_2 & 1) == step_2)
    {
      stage_v_139_2 = ((stage_v_139_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_139_2 = ((stage_v_139_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_140_1 = ((stage_v_140_1 + (step_1 * 4)) + pub_r000248_17_1) & 63;
    }
    else
    {
      stage_v_140_1 = ((stage_v_140_1 + pub_r000248_16_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_140_2 = ((stage_v_140_2 + (step_2 * 4)) + pub_r000248_17_2) & 63;
    }
    else
    {
      stage_v_140_2 = ((stage_v_140_2 + pub_r000248_16_2) + 5) & 63;
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
    if ((stage_v_122_1 & 1) == step_1)
    {
      stage_v_141_1 = ((stage_v_141_1 + (step_1 * 4)) + pub_r000248_3_1) & 63;
    }
    else
    {
      stage_v_141_1 = ((stage_v_141_1 + pub_r000248_4_1) + 5) & 63;
    }
    if ((stage_v_122_2 & 1) == step_2)
    {
      stage_v_141_2 = ((stage_v_141_2 + (step_2 * 4)) + pub_r000248_3_2) & 63;
    }
    else
    {
      stage_v_141_2 = ((stage_v_141_2 + pub_r000248_4_2) + 5) & 63;
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
    if ((stage_v_135_1 & 1) == step_1)
    {
      stage_v_142_1 = ((stage_v_142_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_142_1 = ((stage_v_142_1 + pub_r000248_11_1) + 5) & 63;
    }
    if ((stage_v_135_2 & 1) == step_2)
    {
      stage_v_142_2 = ((stage_v_142_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_142_2 = ((stage_v_142_2 + pub_r000248_11_2) + 5) & 63;
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
    if ((sec_r000248_4_1 & 1) == step_1)
    {
      stage_v_143_1 = ((stage_v_143_1 + (step_1 * 4)) + pub_r000248_2_1) & 63;
    }
    else
    {
      stage_v_143_1 = ((stage_v_143_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((sec_r000248_4_2 & 1) == step_2)
    {
      stage_v_143_2 = ((stage_v_143_2 + (step_2 * 4)) + pub_r000248_2_2) & 63;
    }
    else
    {
      stage_v_143_2 = ((stage_v_143_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((sec_r000248_1_1 & 1) == step_1)
    {
      stage_v_144_1 = ((stage_v_144_1 + (step_1 * 4)) + pub_r000248_5_1) & 63;
    }
    else
    {
      stage_v_144_1 = ((stage_v_144_1 + pub_r000248_4_1) + 5) & 63;
    }
    if ((sec_r000248_1_2 & 1) == step_2)
    {
      stage_v_144_2 = ((stage_v_144_2 + (step_2 * 4)) + pub_r000248_5_2) & 63;
    }
    else
    {
      stage_v_144_2 = ((stage_v_144_2 + pub_r000248_4_2) + 5) & 63;
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
    if ((sec_r000248_0_1 & 1) == step_1)
    {
      stage_v_145_1 = ((stage_v_145_1 + (step_1 * 4)) + pub_r000248_0_1) & 63;
    }
    else
    {
      stage_v_145_1 = ((stage_v_145_1 + pub_r000248_17_1) + 5) & 63;
    }
    if ((sec_r000248_0_2 & 1) == step_2)
    {
      stage_v_145_2 = ((stage_v_145_2 + (step_2 * 4)) + pub_r000248_0_2) & 63;
    }
    else
    {
      stage_v_145_2 = ((stage_v_145_2 + pub_r000248_17_2) + 5) & 63;
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
    if ((sec_r000248_5_1 & 1) == step_1)
    {
      stage_v_146_1 = ((stage_v_146_1 + (step_1 * 4)) + pub_r000248_12_1) & 63;
    }
    else
    {
      stage_v_146_1 = ((stage_v_146_1 + pub_r000248_1_1) + 5) & 63;
    }
    if ((sec_r000248_5_2 & 1) == step_2)
    {
      stage_v_146_2 = ((stage_v_146_2 + (step_2 * 4)) + pub_r000248_12_2) & 63;
    }
    else
    {
      stage_v_146_2 = ((stage_v_146_2 + pub_r000248_1_2) + 5) & 63;
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
    if ((stage_v_82_1 & 1) == step_1)
    {
      stage_v_147_1 = ((stage_v_147_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_147_1 = ((stage_v_147_1 + pub_r000248_2_1) + 5) & 63;
    }
    if ((stage_v_82_2 & 1) == step_2)
    {
      stage_v_147_2 = ((stage_v_147_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_147_2 = ((stage_v_147_2 + pub_r000248_2_2) + 5) & 63;
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
    if ((stage_v_128_1 & 1) == step_1)
    {
      stage_v_148_1 = ((stage_v_148_1 + (step_1 * 4)) + pub_r000248_14_1) & 63;
    }
    else
    {
      stage_v_148_1 = ((stage_v_148_1 + pub_r000248_9_1) + 5) & 63;
    }
    if ((stage_v_128_2 & 1) == step_2)
    {
      stage_v_148_2 = ((stage_v_148_2 + (step_2 * 4)) + pub_r000248_14_2) & 63;
    }
    else
    {
      stage_v_148_2 = ((stage_v_148_2 + pub_r000248_9_2) + 5) & 63;
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
    if ((stage_v_112_1 & 1) == step_1)
    {
      stage_v_149_1 = ((stage_v_149_1 + (step_1 * 4)) + pub_r000248_4_1) & 63;
    }
    else
    {
      stage_v_149_1 = ((stage_v_149_1 + pub_r000248_8_1) + 5) & 63;
    }
    if ((stage_v_112_2 & 1) == step_2)
    {
      stage_v_149_2 = ((stage_v_149_2 + (step_2 * 4)) + pub_r000248_4_2) & 63;
    }
    else
    {
      stage_v_149_2 = ((stage_v_149_2 + pub_r000248_8_2) + 5) & 63;
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
    if ((stage_v_126_1 & 1) == step_1)
    {
      stage_v_150_1 = ((stage_v_150_1 + (step_1 * 4)) + pub_r000248_7_1) & 63;
    }
    else
    {
      stage_v_150_1 = ((stage_v_150_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_126_2 & 1) == step_2)
    {
      stage_v_150_2 = ((stage_v_150_2 + (step_2 * 4)) + pub_r000248_7_2) & 63;
    }
    else
    {
      stage_v_150_2 = ((stage_v_150_2 + pub_r000248_12_2) + 5) & 63;
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
    if ((stage_v_145_1 & 1) == step_1)
    {
      stage_v_151_1 = ((stage_v_151_1 + (step_1 * 4)) + pub_r000248_15_1) & 63;
    }
    else
    {
      stage_v_151_1 = ((stage_v_151_1 + pub_r000248_2_1) + 5) & 63;
    }
    if ((stage_v_145_2 & 1) == step_2)
    {
      stage_v_151_2 = ((stage_v_151_2 + (step_2 * 4)) + pub_r000248_15_2) & 63;
    }
    else
    {
      stage_v_151_2 = ((stage_v_151_2 + pub_r000248_2_2) + 5) & 63;
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
    if ((stage_v_126_1 & 1) == step_1)
    {
      stage_v_152_1 = ((stage_v_152_1 + (step_1 * 4)) + pub_r000248_11_1) & 63;
    }
    else
    {
      stage_v_152_1 = ((stage_v_152_1 + pub_r000248_6_1) + 5) & 63;
    }
    if ((stage_v_126_2 & 1) == step_2)
    {
      stage_v_152_2 = ((stage_v_152_2 + (step_2 * 4)) + pub_r000248_11_2) & 63;
    }
    else
    {
      stage_v_152_2 = ((stage_v_152_2 + pub_r000248_6_2) + 5) & 63;
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
    if ((stage_v_138_1 & 1) == step_1)
    {
      stage_v_153_1 = ((stage_v_153_1 + (step_1 * 4)) + pub_r000248_10_1) & 63;
    }
    else
    {
      stage_v_153_1 = ((stage_v_153_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_138_2 & 1) == step_2)
    {
      stage_v_153_2 = ((stage_v_153_2 + (step_2 * 4)) + pub_r000248_10_2) & 63;
    }
    else
    {
      stage_v_153_2 = ((stage_v_153_2 + pub_r000248_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_95_1 & 1) == step_1)
    {
      stage_v_154_1 = ((stage_v_154_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_154_1 = ((stage_v_154_1 + pub_r000248_13_1) + 5) & 63;
    }
    if ((stage_v_95_2 & 1) == step_2)
    {
      stage_v_154_2 = ((stage_v_154_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_154_2 = ((stage_v_154_2 + pub_r000248_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000248_1_1 & 1) == step_1)
    {
      stage_v_155_1 = ((stage_v_155_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_155_1 = ((stage_v_155_1 + pub_r000248_2_1) + 5) & 63;
    }
    if ((sec_r000248_1_2 & 1) == step_2)
    {
      stage_v_155_2 = ((stage_v_155_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_155_2 = ((stage_v_155_2 + pub_r000248_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_114_1 & 1) == step_1)
    {
      stage_v_156_1 = ((stage_v_156_1 + (step_1 * 4)) + pub_r000248_6_1) & 63;
    }
    else
    {
      stage_v_156_1 = ((stage_v_156_1 + pub_r000248_12_1) + 5) & 63;
    }
    if ((stage_v_114_2 & 1) == step_2)
    {
      stage_v_156_2 = ((stage_v_156_2 + (step_2 * 4)) + pub_r000248_6_2) & 63;
    }
    else
    {
      stage_v_156_2 = ((stage_v_156_2 + pub_r000248_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000248_14_1 != sec_r000248_14_2);
  __CPROVER_assume(pub_r000248_13_1 == pub_r000248_13_2);
  __CPROVER_assume(sec_r000248_2_1 != sec_r000248_2_2);
  __CPROVER_assume(sec_r000248_5_1 != sec_r000248_5_2);
  __CPROVER_assume(sec_r000248_8_1 != sec_r000248_8_2);
  __CPROVER_assume(pub_r000248_17_1 == pub_r000248_17_2);
  __CPROVER_assume(sec_r000248_3_1 != sec_r000248_3_2);
  __CPROVER_assume(pub_r000248_1_1 == pub_r000248_1_2);
  __CPROVER_assume(sec_r000248_16_1 != sec_r000248_16_2);
  __CPROVER_assume(pub_r000248_3_1 == pub_r000248_3_2);
  __CPROVER_assume(pub_r000248_6_1 == pub_r000248_6_2);
  __CPROVER_assume(sec_r000248_10_1 != sec_r000248_10_2);
  __CPROVER_assume(pub_r000248_0_1 == pub_r000248_0_2);
  __CPROVER_assume(pub_r000248_11_1 == pub_r000248_11_2);
  __CPROVER_assume(pub_r000248_12_1 == pub_r000248_12_2);
  __CPROVER_assume(pub_r000248_16_1 == pub_r000248_16_2);
  __CPROVER_assume(sec_r000248_13_1 != sec_r000248_13_2);
  __CPROVER_assume(pub_r000248_9_1 == pub_r000248_9_2);
  __CPROVER_assume(sec_r000248_19_1 != sec_r000248_19_2);
  __CPROVER_assume(pub_r000248_8_1 == pub_r000248_8_2);
  __CPROVER_assume(pub_r000248_14_1 == pub_r000248_14_2);
  __CPROVER_assume(sec_r000248_9_1 != sec_r000248_9_2);
  __CPROVER_assume(sec_r000248_4_1 != sec_r000248_4_2);
  __CPROVER_assume(pub_r000248_15_1 == pub_r000248_15_2);
  __CPROVER_assume(sec_r000248_20_1 != sec_r000248_20_2);
  __CPROVER_assume(sec_r000248_23_1 != sec_r000248_23_2);
  __CPROVER_assume(pub_r000248_10_1 == pub_r000248_10_2);
  __CPROVER_assume(pub_r000248_2_1 == pub_r000248_2_2);
  __CPROVER_assume(sec_r000248_22_1 != sec_r000248_22_2);
  __CPROVER_assume(pub_r000248_7_1 == pub_r000248_7_2);
  __CPROVER_assume(sec_r000248_12_1 != sec_r000248_12_2);
  __CPROVER_assume(sec_r000248_6_1 != sec_r000248_6_2);
  __CPROVER_assume(sec_r000248_17_1 != sec_r000248_17_2);
  __CPROVER_assume(sec_r000248_7_1 != sec_r000248_7_2);
  __CPROVER_assume(sec_r000248_0_1 != sec_r000248_0_2);
  __CPROVER_assume(sec_r000248_21_1 != sec_r000248_21_2);
  __CPROVER_assume(pub_r000248_5_1 == pub_r000248_5_2);
  __CPROVER_assume(sec_r000248_1_1 != sec_r000248_1_2);
  __CPROVER_assume(sec_r000248_15_1 != sec_r000248_15_2);
  __CPROVER_assume(sec_r000248_18_1 != sec_r000248_18_2);
  __CPROVER_assume(pub_r000248_4_1 == pub_r000248_4_2);
  __CPROVER_assume(sec_r000248_11_1 != sec_r000248_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
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
  assert(stage_v_154_1 == stage_v_154_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(stage_v_156_1 == stage_v_156_2);
}


