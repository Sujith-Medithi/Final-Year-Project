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
struct FilterState_R000414_1413_0
{
  int mode;
  int cutoff;
  int prev_in;
  short gain_db;
  unsigned char damping;
  int buffer[3];
};
struct DeviceConfig_R000414_1413_1
{
  short parity;
  short baud_rate;
  unsigned char id;
  int timeout;
  short port;
  short stop_bits;
  int buffer[3];
};
struct Transaction_R000414_1413_2
{
  short account_id;
  int fee;
  int status;
  int buffer[3];
};
union PacketPayload_R000414_1413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000414_1413_1
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
void fn_R000414_1413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_43_1 > 47)
  {
    acc_1 = ((acc_1 + (bound_43_1 * 2)) + 5) & 127;
    aux_1 ^= bound_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_43_2 > 47)
  {
    acc_2 = ((acc_2 + (bound_43_2 * 2)) + 5) & 127;
    aux_2 ^= bound_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_35_1)
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

  switch (stride_35_2)
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
  int checksum_78_1 = local_arr_1[aux_1 % 3];
  int checksum_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_43_1 == bound_43_2);
  assert(stride_35_1 == stride_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_78_1 == checksum_78_2);
}

int fn_R000414_1413_0(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_43 > 47)
  {
    acc = ((acc + (bound_43 * 2)) + 5) & 127;
    aux ^= bound_43 & 15;
  }
  else
  {
    acc = ((acc - bound_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_35 = (aux + st.buffer[1]) & 3;
  switch (stride_35)
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
  int checksum_78 = local_arr[aux % 3];
  acc = (acc + (checksum_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st_1 = {0};
  struct Transaction_R000414_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_12_1) & 63;
  aux_2 = (aux_2 + factor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_15_1 = local_arr_1[aux_1 % 3];
  int coefficient_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_12_1 == factor_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
}

int fn_R000414_1413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_15 = local_arr[aux % 3];
  acc = (acc + (coefficient_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st_1 = {0};
  struct DeviceConfig_R000414_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_17_1 = local_arr_1[aux_1 % 3];
  int margin_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_17_2 * 2)) & 127;
  int delta_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_70_1) & 63;
  aux_2 = (aux_2 + delta_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_35_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_35_1 * 2)) + 5) & 127;
    aux_1 ^= sample_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_35_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_35_2 * 2)) + 5) & 127;
    aux_2 ^= sample_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_17_1 == margin_17_2);
  assert(delta_70_1 == delta_70_2);
  assert(sample_35_1 == sample_35_2);
}

int fn_R000414_1413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int margin_17 = local_arr[aux % 3];
  acc = (acc + (margin_17 * 2)) & 127;
  int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_70) & 63;
  acc ^= aux;
  int sample_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_35 > 30)
  {
    acc = ((acc + (sample_35 * 2)) + 5) & 127;
    aux ^= sample_35 & 15;
  }
  else
  {
    acc = ((acc - sample_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_15_1 = local_arr_1[aux_1 % 3];
  int accumulator_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_15_1 == accumulator_15_2);
}

int fn_R000414_1413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int accumulator_15 = local_arr[aux % 3];
  acc = (acc + (accumulator_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st_1 = {0};
  struct Transaction_R000414_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_95_1) & 63;
  aux_2 = (aux_2 + weight_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_52_1 = local_arr_1[aux_1 % 3];
  int scale_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_95_1 == weight_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_52_1 == scale_52_2);
}

int fn_R000414_1413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_52 = local_arr[aux % 3];
  acc = (acc + (scale_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_88_1 = local_arr_1[aux_1 % 3];
  int phase_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_88_2 * 2)) & 127;
  int weight_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_24_1 > 36)
  {
    acc_1 = ((acc_1 + (weight_24_1 * 2)) + 5) & 127;
    aux_1 ^= weight_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_24_2 > 36)
  {
    acc_2 = ((acc_2 + (weight_24_2 * 2)) + 5) & 127;
    aux_2 ^= weight_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_88_1 == phase_88_2);
  assert(weight_24_1 == weight_24_2);
}

int fn_R000414_1413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int phase_88 = local_arr[aux % 3];
  acc = (acc + (phase_88 * 2)) & 127;
  int weight_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_24 > 36)
  {
    acc = ((acc + (weight_24 * 2)) + 5) & 127;
    aux ^= weight_24 & 15;
  }
  else
  {
    acc = ((acc - weight_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_35_1)
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

  switch (cursor_35_2)
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
  int quotient_31_1 = local_arr_1[aux_1 % 3];
  int quotient_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_35_1 == cursor_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_31_1 == quotient_31_2);
}

int fn_R000414_1413_6(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_35 = (aux + st.buffer[1]) & 3;
  switch (cursor_35)
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
  int quotient_31 = local_arr[aux % 3];
  acc = (acc + (quotient_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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

  int phase_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_52_1) & 63;
  aux_2 = (aux_2 + phase_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_53_1 = local_arr_1[aux_1 % 3];
  int tracker_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_50_1 == damping_50_2);
  assert(phase_52_1 == phase_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_53_1 == tracker_53_2);
}

int fn_R000414_1413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

  int phase_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_52) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_53 = local_arr[aux % 3];
  acc = (acc + (tracker_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st_1 = {0};
  struct DeviceConfig_R000414_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_78_1)
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

  switch (weight_78_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_85_1 = local_arr_1[aux_1 % 3];
  int phase_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_78_1 == weight_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_85_1 == phase_85_2);
}

int fn_R000414_1413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_78 = (aux + st.buffer[1]) & 3;
  switch (weight_78)
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

  int local_arr[3] = {4, 9, 15};
  int phase_85 = local_arr[aux % 3];
  acc = (acc + (phase_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st_1 = {0};
  struct Transaction_R000414_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_83_1) & 63;
  aux_2 = (aux_2 + cursor_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_76_1 > 37)
  {
    acc_1 = ((acc_1 + (pivot_76_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_76_2 > 37)
  {
    acc_2 = ((acc_2 + (pivot_76_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_76_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_20_1 = local_arr_1[aux_1 % 3];
  int anchor_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_83_1 == cursor_83_2);
  assert(pivot_76_1 == pivot_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_20_1 == anchor_20_2);
}

int fn_R000414_1413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_83) & 63;
  acc ^= aux;
  int pivot_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_76 > 37)
  {
    acc = ((acc + (pivot_76 * 2)) + 5) & 127;
    aux ^= pivot_76 & 15;
  }
  else
  {
    acc = ((acc - pivot_76) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_20 = local_arr[aux % 3];
  acc = (acc + (anchor_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st_1 = {0};
  struct Transaction_R000414_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_59_1 > 12)
  {
    acc_1 = ((acc_1 + (damping_59_1 * 2)) + 5) & 127;
    aux_1 ^= damping_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_59_2 > 12)
  {
    acc_2 = ((acc_2 + (damping_59_2 * 2)) + 5) & 127;
    aux_2 ^= damping_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_90_1)
  {
    case 0:
      acc_1 = (acc_1 + 1) & 127;
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

  switch (pivot_90_2)
  {
    case 0:
      acc_2 = (acc_2 + 1) & 127;
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
  int pivot_11_1 = local_arr_1[aux_1 % 3];
  int pivot_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
  assert(pivot_90_1 == pivot_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_11_1 == pivot_11_2);
}

int fn_R000414_1413_10(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_59 > 12)
  {
    acc = ((acc + (damping_59 * 2)) + 5) & 127;
    aux ^= damping_59 & 15;
  }
  else
  {
    acc = ((acc - damping_59) + 11) & 127;
    aux += 3;
  }
  int pivot_90 = (aux + st.buffer[1]) & 3;
  switch (pivot_90)
  {
    case 0:
      acc = (acc + 1) & 127;
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
  int pivot_11 = local_arr[aux % 3];
  acc = (acc + (pivot_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st_1 = {0};
  struct FilterState_R000414_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_68_1) & 63;
  aux_2 = (aux_2 + parity_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_37_1 > 21)
  {
    acc_1 = ((acc_1 + (quotient_37_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_37_2 > 21)
  {
    acc_2 = ((acc_2 + (quotient_37_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_68_1 == parity_68_2);
  assert(quotient_37_1 == quotient_37_2);
}

int fn_R000414_1413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000414_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_68) & 63;
  acc ^= aux;
  int quotient_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_37 > 21)
  {
    acc = ((acc + (quotient_37 * 2)) + 5) & 127;
    aux ^= quotient_37 & 15;
  }
  else
  {
    acc = ((acc - quotient_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st_1 = {0};
  struct DeviceConfig_R000414_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_78_1 = local_arr_1[aux_1 % 3];
  int index_reg_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_78_2 * 2)) & 127;
  int coefficient_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_96_1) & 63;
  aux_2 = (aux_2 + coefficient_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_78_1 == index_reg_78_2);
  assert(coefficient_96_1 == coefficient_96_2);
}

int fn_R000414_1413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int index_reg_78 = local_arr[aux % 3];
  acc = (acc + (index_reg_78 * 2)) & 127;
  int coefficient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000414_1413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st_1 = {0};
  struct Transaction_R000414_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_94_1)
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

  switch (vector_94_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_39_1 = local_arr_1[aux_1 % 3];
  int pivot_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_94_1 == vector_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_39_1 == pivot_39_2);
}

int fn_R000414_1413_13(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000414_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_94 = (aux + st.buffer[1]) & 3;
  switch (vector_94)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_39 = local_arr[aux % 3];
  acc = (acc + (pivot_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000414_1413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st_1 = {0};
  struct DeviceConfig_R000414_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_53_1) & 63;
  aux_2 = (aux_2 + phase_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_85_1 > 43)
  {
    acc_1 = ((acc_1 + (delta_85_1 * 2)) + 5) & 127;
    aux_1 ^= delta_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_85_2 > 43)
  {
    acc_2 = ((acc_2 + (delta_85_2 * 2)) + 5) & 127;
    aux_2 ^= delta_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_94_1 = local_arr_1[aux_1 % 3];
  int metric_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_94_2 * 2)) & 127;
  int tracker_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_57_1)
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

  switch (tracker_57_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_53_1 == phase_53_2);
  assert(delta_85_1 == delta_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_94_1 == metric_94_2);
  assert(tracker_57_1 == tracker_57_2);
}

int fn_R000414_1413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000414_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_53) & 63;
  acc ^= aux;
  int delta_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_85 > 43)
  {
    acc = ((acc + (delta_85 * 2)) + 5) & 127;
    aux ^= delta_85 & 15;
  }
  else
  {
    acc = ((acc - delta_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_94 = local_arr[aux % 3];
  acc = (acc + (metric_94 * 2)) & 127;
  int tracker_57 = (aux + st.buffer[1]) & 3;
  switch (tracker_57)
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

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000414_0_1;
  int sec_r000414_0_2;
  int sec_r000414_1_1;
  int sec_r000414_1_2;
  int sec_r000414_2_1;
  int sec_r000414_2_2;
  int sec_r000414_3_1;
  int sec_r000414_3_2;
  int sec_r000414_4_1;
  int sec_r000414_4_2;
  int sec_r000414_5_1;
  int sec_r000414_5_2;
  int sec_r000414_6_1;
  int sec_r000414_6_2;
  int sec_r000414_7_1;
  int sec_r000414_7_2;
  int sec_r000414_8_1;
  int sec_r000414_8_2;
  int sec_r000414_9_1;
  int sec_r000414_9_2;
  int sec_r000414_10_1;
  int sec_r000414_10_2;
  int sec_r000414_11_1;
  int sec_r000414_11_2;
  int sec_r000414_12_1;
  int sec_r000414_12_2;
  int sec_r000414_13_1;
  int sec_r000414_13_2;
  int sec_r000414_14_1;
  int sec_r000414_14_2;
  int sec_r000414_15_1;
  int sec_r000414_15_2;
  int sec_r000414_16_1;
  int sec_r000414_16_2;
  int sec_r000414_17_1;
  int sec_r000414_17_2;
  int pub_r000414_0_1;
  int pub_r000414_0_2;
  int pub_r000414_1_1;
  int pub_r000414_1_2;
  int pub_r000414_2_1;
  int pub_r000414_2_2;
  int pub_r000414_3_1;
  int pub_r000414_3_2;
  int pub_r000414_4_1;
  int pub_r000414_4_2;
  int pub_r000414_5_1;
  int pub_r000414_5_2;
  int pub_r000414_6_1;
  int pub_r000414_6_2;
  int pub_r000414_7_1;
  int pub_r000414_7_2;
  int pub_r000414_8_1;
  int pub_r000414_8_2;
  int pub_r000414_9_1;
  int pub_r000414_9_2;
  int pub_r000414_10_1;
  int pub_r000414_10_2;
  int pub_r000414_11_1;
  int pub_r000414_11_2;
  int pub_r000414_12_1;
  int pub_r000414_12_2;
  int pub_r000414_13_1;
  int pub_r000414_13_2;
  int pub_r000414_14_1;
  int pub_r000414_14_2;
  int pub_r000414_15_1;
  int pub_r000414_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000414_0_1 >= (-100)) && (pub_r000414_0_1 <= 100));
  __CPROVER_assume((pub_r000414_0_2 >= (-100)) && (pub_r000414_0_2 <= 100));
  __CPROVER_assume((pub_r000414_1_1 >= (-100)) && (pub_r000414_1_1 <= 100));
  __CPROVER_assume((pub_r000414_1_2 >= (-100)) && (pub_r000414_1_2 <= 100));
  __CPROVER_assume((pub_r000414_2_1 >= (-100)) && (pub_r000414_2_1 <= 100));
  __CPROVER_assume((pub_r000414_2_2 >= (-100)) && (pub_r000414_2_2 <= 100));
  __CPROVER_assume((pub_r000414_3_1 >= (-100)) && (pub_r000414_3_1 <= 100));
  __CPROVER_assume((pub_r000414_3_2 >= (-100)) && (pub_r000414_3_2 <= 100));
  __CPROVER_assume((pub_r000414_4_1 >= (-100)) && (pub_r000414_4_1 <= 100));
  __CPROVER_assume((pub_r000414_4_2 >= (-100)) && (pub_r000414_4_2 <= 100));
  __CPROVER_assume((pub_r000414_5_1 >= (-100)) && (pub_r000414_5_1 <= 100));
  __CPROVER_assume((pub_r000414_5_2 >= (-100)) && (pub_r000414_5_2 <= 100));
  __CPROVER_assume((pub_r000414_6_1 >= (-100)) && (pub_r000414_6_1 <= 100));
  __CPROVER_assume((pub_r000414_6_2 >= (-100)) && (pub_r000414_6_2 <= 100));
  __CPROVER_assume((pub_r000414_7_1 >= (-100)) && (pub_r000414_7_1 <= 100));
  __CPROVER_assume((pub_r000414_7_2 >= (-100)) && (pub_r000414_7_2 <= 100));
  __CPROVER_assume((pub_r000414_8_1 >= (-100)) && (pub_r000414_8_1 <= 100));
  __CPROVER_assume((pub_r000414_8_2 >= (-100)) && (pub_r000414_8_2 <= 100));
  __CPROVER_assume((pub_r000414_9_1 >= (-100)) && (pub_r000414_9_1 <= 100));
  __CPROVER_assume((pub_r000414_9_2 >= (-100)) && (pub_r000414_9_2 <= 100));
  __CPROVER_assume((pub_r000414_10_1 >= (-100)) && (pub_r000414_10_1 <= 100));
  __CPROVER_assume((pub_r000414_10_2 >= (-100)) && (pub_r000414_10_2 <= 100));
  __CPROVER_assume((pub_r000414_11_1 >= (-100)) && (pub_r000414_11_1 <= 100));
  __CPROVER_assume((pub_r000414_11_2 >= (-100)) && (pub_r000414_11_2 <= 100));
  __CPROVER_assume((pub_r000414_12_1 >= (-100)) && (pub_r000414_12_1 <= 100));
  __CPROVER_assume((pub_r000414_12_2 >= (-100)) && (pub_r000414_12_2 <= 100));
  __CPROVER_assume((pub_r000414_13_1 >= (-100)) && (pub_r000414_13_1 <= 100));
  __CPROVER_assume((pub_r000414_13_2 >= (-100)) && (pub_r000414_13_2 <= 100));
  __CPROVER_assume((pub_r000414_14_1 >= (-100)) && (pub_r000414_14_1 <= 100));
  __CPROVER_assume((pub_r000414_14_2 >= (-100)) && (pub_r000414_14_2 <= 100));
  __CPROVER_assume((pub_r000414_15_1 >= (-100)) && (pub_r000414_15_1 <= 100));
  __CPROVER_assume((pub_r000414_15_2 >= (-100)) && (pub_r000414_15_2 <= 100));
  __CPROVER_assume((sec_r000414_0_1 >= 0) && (sec_r000414_0_1 <= 255));
  __CPROVER_assume((sec_r000414_0_2 >= 0) && (sec_r000414_0_2 <= 255));
  __CPROVER_assume((sec_r000414_1_1 >= 0) && (sec_r000414_1_1 <= 255));
  __CPROVER_assume((sec_r000414_1_2 >= 0) && (sec_r000414_1_2 <= 255));
  __CPROVER_assume((sec_r000414_2_1 >= 0) && (sec_r000414_2_1 <= 255));
  __CPROVER_assume((sec_r000414_2_2 >= 0) && (sec_r000414_2_2 <= 255));
  __CPROVER_assume((sec_r000414_3_1 >= 0) && (sec_r000414_3_1 <= 255));
  __CPROVER_assume((sec_r000414_3_2 >= 0) && (sec_r000414_3_2 <= 255));
  __CPROVER_assume((sec_r000414_4_1 >= 0) && (sec_r000414_4_1 <= 255));
  __CPROVER_assume((sec_r000414_4_2 >= 0) && (sec_r000414_4_2 <= 255));
  __CPROVER_assume((sec_r000414_5_1 >= 0) && (sec_r000414_5_1 <= 255));
  __CPROVER_assume((sec_r000414_5_2 >= 0) && (sec_r000414_5_2 <= 255));
  __CPROVER_assume((sec_r000414_6_1 >= 0) && (sec_r000414_6_1 <= 255));
  __CPROVER_assume((sec_r000414_6_2 >= 0) && (sec_r000414_6_2 <= 255));
  __CPROVER_assume((sec_r000414_7_1 >= 0) && (sec_r000414_7_1 <= 255));
  __CPROVER_assume((sec_r000414_7_2 >= 0) && (sec_r000414_7_2 <= 255));
  __CPROVER_assume((sec_r000414_8_1 >= 0) && (sec_r000414_8_1 <= 255));
  __CPROVER_assume((sec_r000414_8_2 >= 0) && (sec_r000414_8_2 <= 255));
  __CPROVER_assume((sec_r000414_9_1 >= 0) && (sec_r000414_9_1 <= 255));
  __CPROVER_assume((sec_r000414_9_2 >= 0) && (sec_r000414_9_2 <= 255));
  __CPROVER_assume((sec_r000414_10_1 >= 0) && (sec_r000414_10_1 <= 255));
  __CPROVER_assume((sec_r000414_10_2 >= 0) && (sec_r000414_10_2 <= 255));
  __CPROVER_assume((sec_r000414_11_1 >= 0) && (sec_r000414_11_1 <= 255));
  __CPROVER_assume((sec_r000414_11_2 >= 0) && (sec_r000414_11_2 <= 255));
  __CPROVER_assume((sec_r000414_12_1 >= 0) && (sec_r000414_12_1 <= 255));
  __CPROVER_assume((sec_r000414_12_2 >= 0) && (sec_r000414_12_2 <= 255));
  __CPROVER_assume((sec_r000414_13_1 >= 0) && (sec_r000414_13_1 <= 255));
  __CPROVER_assume((sec_r000414_13_2 >= 0) && (sec_r000414_13_2 <= 255));
  __CPROVER_assume((sec_r000414_14_1 >= 0) && (sec_r000414_14_1 <= 255));
  __CPROVER_assume((sec_r000414_14_2 >= 0) && (sec_r000414_14_2 <= 255));
  __CPROVER_assume((sec_r000414_15_1 >= 0) && (sec_r000414_15_1 <= 255));
  __CPROVER_assume((sec_r000414_15_2 >= 0) && (sec_r000414_15_2 <= 255));
  __CPROVER_assume((sec_r000414_16_1 >= 0) && (sec_r000414_16_1 <= 255));
  __CPROVER_assume((sec_r000414_16_2 >= 0) && (sec_r000414_16_2 <= 255));
  __CPROVER_assume((sec_r000414_17_1 >= 0) && (sec_r000414_17_1 <= 255));
  __CPROVER_assume((sec_r000414_17_2 >= 0) && (sec_r000414_17_2 <= 255));
  struct FilterState_R000414_1413_0 st_var_0_1 = {0};
  struct FilterState_R000414_1413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000414_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000414_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000414_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000414_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000414_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000414_0_2 + 7) & 15;
  struct DeviceConfig_R000414_1413_1 st_var_1_1 = {0};
  struct DeviceConfig_R000414_1413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000414_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000414_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000414_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000414_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000414_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000414_0_2 + 9) & 15;
  struct Transaction_R000414_1413_2 st_var_2_1 = {0};
  struct Transaction_R000414_1413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000414_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000414_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000414_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000414_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000414_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000414_0_2 + 11) & 15;
  union PacketPayload_R000414_1413_0 u_var_1;
  union PacketPayload_R000414_1413_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 49)
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
  if (stage_v_4_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 49)
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
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
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
  if (stage_v_13_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 38)
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
  if (stage_v_13_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 38)
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
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
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 22) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_10_1) + 13) & 127;
  int stage_v_23_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_4_1) + 7) & 127;
  int stage_v_24_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((((stage_v_23_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_5_1) + 3) & 127;
  int stage_v_25_2 = ((((stage_v_23_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((((stage_v_25_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_14_1) + 5) & 127;
  int stage_v_26_2 = ((((stage_v_25_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((((sec_r000414_15_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_3_1) + 26) & 127;
  int stage_v_27_2 = ((((sec_r000414_15_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((((stage_v_23_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_11_1) + 31) & 127;
  int stage_v_28_2 = ((((stage_v_23_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_11_1) + 32) & 127;
  int stage_v_29_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((((stage_v_26_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_10_1) + 28) & 127;
  int stage_v_30_2 = ((((stage_v_26_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((((stage_v_30_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_4_1) + 9) & 127;
  int stage_v_31_2 = ((((stage_v_30_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_6_1) + 26) & 127;
  int stage_v_32_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((((stage_v_25_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_7_1) + 36) & 127;
  int stage_v_33_2 = ((((stage_v_25_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_0_1) + 16) & 127;
  int stage_v_34_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((((stage_v_26_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_10_1) + 33) & 127;
  int stage_v_35_2 = ((((stage_v_26_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((((stage_v_25_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_11_1) + 5) & 127;
  int stage_v_36_2 = ((((stage_v_25_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_5_1) + 5) & 127;
  int stage_v_37_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((((stage_v_23_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_6_1) + 4) & 127;
  int stage_v_38_2 = ((((stage_v_23_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((((stage_v_37_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_1_1) + 9) & 127;
  int stage_v_39_2 = ((((stage_v_37_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((((sec_r000414_15_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_12_1) + 7) & 127;
  int stage_v_40_2 = ((((sec_r000414_15_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_12_1) + 34) & 127;
  int stage_v_41_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_7_1) + 24) & 127;
  int stage_v_42_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((((stage_v_31_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_2_1) + 18) & 127;
  int stage_v_43_2 = ((((stage_v_31_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((((stage_v_41_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_4_1) + 18) & 127;
  int stage_v_44_2 = ((((stage_v_41_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((((stage_v_24_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 3) & 127;
  int stage_v_45_2 = ((((stage_v_24_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_0_1) + 30) & 127;
  int stage_v_46_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_4_1) + 36) & 127;
  int stage_v_47_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((((stage_v_47_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_8_1) + 21) & 127;
  int stage_v_48_2 = ((((stage_v_47_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((((stage_v_38_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_0_1) + 16) & 127;
  int stage_v_49_2 = ((((stage_v_38_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_3_1) + 15) & 127;
  int stage_v_50_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((((stage_v_45_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_6_1) + 31) & 127;
  int stage_v_51_2 = ((((stage_v_45_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((((stage_v_46_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_14_1) + 26) & 127;
  int stage_v_52_2 = ((((stage_v_46_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((((stage_v_42_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_14_1) + 19) & 127;
  int stage_v_53_2 = ((((stage_v_42_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((((stage_v_36_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_0_1) + 20) & 127;
  int stage_v_54_2 = ((((stage_v_36_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_1_1) + 13) & 127;
  int stage_v_55_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((((stage_v_31_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_11_1) + 4) & 127;
  int stage_v_56_2 = ((((stage_v_31_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_9_1) + 12) & 127;
  int stage_v_57_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_4_1) + 5) & 127;
  int stage_v_58_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((((stage_v_56_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_15_1) + 4) & 127;
  int stage_v_59_2 = ((((stage_v_56_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((stage_v_41_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_7_1) + 12) & 127;
  int stage_v_60_2 = ((((stage_v_41_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((stage_v_52_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_5_1) + 25) & 127;
  int stage_v_61_2 = ((((stage_v_52_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_5_1) + 7) & 127;
  int stage_v_62_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((stage_v_48_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_12_1) + 9) & 127;
  int stage_v_63_2 = ((((stage_v_48_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_1_1) + 7) & 127;
  int stage_v_64_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((stage_v_42_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_6_1) + 29) & 127;
  int stage_v_65_2 = ((((stage_v_42_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((stage_v_27_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_5_1) + 37) & 127;
  int stage_v_66_2 = ((((stage_v_27_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((stage_v_23_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_5_1) + 4) & 127;
  int stage_v_67_2 = ((((stage_v_23_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((stage_v_33_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_3_1) + 11) & 127;
  int stage_v_68_2 = ((((stage_v_33_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((stage_v_63_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_2_1) + 6) & 127;
  int stage_v_69_2 = ((((stage_v_63_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((stage_v_69_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_10_1) + 17) & 127;
  int stage_v_70_2 = ((((stage_v_69_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_23_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_14_1) + 7) & 127;
  int stage_v_71_2 = ((((stage_v_23_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_38_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_5_1) + 37) & 127;
  int stage_v_72_2 = ((((stage_v_38_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_53_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_13_1) + 27) & 127;
  int stage_v_73_2 = ((((stage_v_53_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((stage_v_60_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_15_1) + 34) & 127;
  int stage_v_74_2 = ((((stage_v_60_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_32_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_3_1) + 8) & 127;
  int stage_v_75_2 = ((((stage_v_32_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((stage_v_74_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_6_1) + 21) & 127;
  int stage_v_76_2 = ((((stage_v_74_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_13_1) + 32) & 127;
  int stage_v_77_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((stage_v_41_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_12_1) + 12) & 127;
  int stage_v_78_2 = ((((stage_v_41_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_2_1) + 6) & 127;
  int stage_v_79_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_53_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_7_1) + 16) & 127;
  int stage_v_80_2 = ((((stage_v_53_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_6_1) + 11) & 127;
  int stage_v_81_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((stage_v_44_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_3_1) + 10) & 127;
  int stage_v_82_2 = ((((stage_v_44_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_65_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_8_1) + 29) & 127;
  int stage_v_83_2 = ((((stage_v_65_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_42_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_5_1) + 32) & 127;
  int stage_v_84_2 = ((((stage_v_42_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_32_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_9_1) + 14) & 127;
  int stage_v_85_2 = ((((stage_v_32_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_14_1) + 30) & 127;
  int stage_v_86_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_36_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_10_1) + 30) & 127;
  int stage_v_87_2 = ((((stage_v_36_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_42_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_14_1) + 9) & 127;
  int stage_v_88_2 = ((((stage_v_42_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_71_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_14_1) + 18) & 127;
  int stage_v_89_2 = ((((stage_v_71_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_60_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_1_1) + 19) & 127;
  int stage_v_90_2 = ((((stage_v_60_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_67_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_2_1) + 10) & 127;
  int stage_v_91_2 = ((((stage_v_67_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_0_1) + 36) & 127;
  int stage_v_92_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_5_1) + 9) & 127;
  int stage_v_93_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_4_1) + 9) & 127;
  int stage_v_94_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_13_1) + 27) & 127;
  int stage_v_95_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_59_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_5_1) + 18) & 127;
  int stage_v_96_2 = ((((stage_v_59_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_14_1) + 32) & 127;
  int stage_v_97_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_39_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_10_1) + 35) & 127;
  int stage_v_98_2 = ((((stage_v_39_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 23) & 127;
  int stage_v_99_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_1_1) + 25) & 127;
  int stage_v_100_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_82_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_1_1) + 27) & 127;
  int stage_v_101_2 = ((((stage_v_82_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_5_1) + 24) & 127;
  int stage_v_102_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_8_1) + 26) & 127;
  int stage_v_103_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_15_1) + 21) & 127;
  int stage_v_104_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_6_1) + 21) & 127;
  int stage_v_105_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_43_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_9_1) + 9) & 127;
  int stage_v_106_2 = ((((stage_v_43_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((stage_v_102_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_0_1) + 5) & 127;
  int stage_v_107_2 = ((((stage_v_102_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_8_1) + 7) & 127;
  int stage_v_108_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_81_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_13_1) + 28) & 127;
  int stage_v_109_2 = ((((stage_v_81_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_0_1) + 8) & 127;
  int stage_v_110_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_50_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_13_1) + 35) & 127;
  int stage_v_111_2 = ((((stage_v_50_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_9_1) + 32) & 127;
  int stage_v_112_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_9_1) + 26) & 127;
  int stage_v_113_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_95_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_4_1) + 6) & 127;
  int stage_v_114_2 = ((((stage_v_95_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_35_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_11_1) + 37) & 127;
  int stage_v_115_2 = ((((stage_v_35_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_111_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_15_1) + 27) & 127;
  int stage_v_116_2 = ((((stage_v_111_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_50_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_9_1) + 26) & 127;
  int stage_v_117_2 = ((((stage_v_50_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_13_1) + 17) & 127;
  int stage_v_118_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_34_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_5_1) + 13) & 127;
  int stage_v_119_2 = ((((stage_v_34_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_31_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_14_1) + 10) & 127;
  int stage_v_120_2 = ((((stage_v_31_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_91_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_7_1) + 6) & 127;
  int stage_v_121_2 = ((((stage_v_91_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_37_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_9_1) + 6) & 127;
  int stage_v_122_2 = ((((stage_v_37_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_11_1) + 19) & 127;
  int stage_v_123_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_8_1) + 31) & 127;
  int stage_v_124_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_118_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_11_1) + 13) & 127;
  int stage_v_125_2 = ((((stage_v_118_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_15_1) + 30) & 127;
  int stage_v_126_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_33_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_12_1) + 5) & 127;
  int stage_v_127_2 = ((((stage_v_33_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_56_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_0_1) + 21) & 127;
  int stage_v_128_2 = ((((stage_v_56_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_24_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_1_1) + 26) & 127;
  int stage_v_129_2 = ((((stage_v_24_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_110_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_11_1) + 29) & 127;
  int stage_v_130_2 = ((((stage_v_110_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_13_1) + 30) & 127;
  int stage_v_131_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_93_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_14_1) + 18) & 127;
  int stage_v_132_2 = ((((stage_v_93_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_5_1) + 34) & 127;
  int stage_v_133_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_4_1) + 37) & 127;
  int stage_v_134_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_120_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_6_1) + 10) & 127;
  int stage_v_135_2 = ((((stage_v_120_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_6_1) + 7) & 127;
  int stage_v_136_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_59_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_12_1) + 34) & 127;
  int stage_v_137_2 = ((((stage_v_59_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_137_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_2_1) + 5) & 127;
  int stage_v_138_2 = ((((stage_v_137_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_52_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_0_1) + 4) & 127;
  int stage_v_139_2 = ((((stage_v_52_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_0_1) + 31) & 127;
  int stage_v_140_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_136_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_12_1) + 21) & 127;
  int stage_v_141_2 = ((((stage_v_136_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_5_1) + 23) & 127;
  int stage_v_142_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_14_1) + 6) & 127;
  int stage_v_143_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_129_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_12_1) + 32) & 127;
  int stage_v_144_2 = ((((stage_v_129_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_5_1) + 10) & 127;
  int stage_v_145_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_58_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_2_1) + 31) & 127;
  int stage_v_146_2 = ((((stage_v_58_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_7_1) + 27) & 127;
  int stage_v_147_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_109_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_3_1) + 37) & 127;
  int stage_v_148_2 = ((((stage_v_109_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_10_1) + 22) & 127;
  int stage_v_149_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_1_1) + 10) & 127;
  int stage_v_150_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_13_1) + 16) & 127;
  int stage_v_151_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_40_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_10_1) + 19) & 127;
  int stage_v_152_2 = ((((stage_v_40_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_58_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_2_1) + 20) & 127;
  int stage_v_153_2 = ((((stage_v_58_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_136_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_14_1) + 34) & 127;
  int stage_v_154_2 = ((((stage_v_136_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_93_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_9_1) + 35) & 127;
  int stage_v_155_2 = ((((stage_v_93_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_88_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_7_1) + 13) & 127;
  int stage_v_156_2 = ((((stage_v_88_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_15_1) + 4) & 127;
  int stage_v_157_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_119_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_11_1) + 22) & 127;
  int stage_v_158_2 = ((((stage_v_119_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_126_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 18) & 127;
  int stage_v_159_2 = ((((stage_v_126_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_80_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_11_1) + 7) & 127;
  int stage_v_160_2 = ((((stage_v_80_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_8_1) + 35) & 127;
  int stage_v_161_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_4_1) + 32) & 127;
  int stage_v_162_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_149_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_5_1) + 22) & 127;
  int stage_v_163_2 = ((((stage_v_149_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_67_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_2_1) + 5) & 127;
  int stage_v_164_2 = ((((stage_v_67_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_8_1) + 29) & 127;
  int stage_v_165_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_112_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_2_1) + 22) & 127;
  int stage_v_166_2 = ((((stage_v_112_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_10_1) + 25) & 127;
  int stage_v_167_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_12_1) + 17) & 127;
  int stage_v_168_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_152_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_3_1) + 22) & 127;
  int stage_v_169_2 = ((((stage_v_152_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_104_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_10_1) + 30) & 127;
  int stage_v_170_2 = ((((stage_v_104_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_10_1) + 27) & 127;
  int stage_v_171_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_92_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_9_1) + 16) & 127;
  int stage_v_172_2 = ((((stage_v_92_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_164_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_8_1) + 6) & 127;
  int stage_v_173_2 = ((((stage_v_164_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_80_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_15_1) + 8) & 127;
  int stage_v_174_2 = ((((stage_v_80_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_138_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 6) & 127;
  int stage_v_175_2 = ((((stage_v_138_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_43_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_2_1) + 14) & 127;
  int stage_v_176_2 = ((((stage_v_43_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_96_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_0_1) + 32) & 127;
  int stage_v_177_2 = ((((stage_v_96_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_101_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_2_1) + 22) & 127;
  int stage_v_178_2 = ((((stage_v_101_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_49_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_4_1) + 16) & 127;
  int stage_v_179_2 = ((((stage_v_49_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_173_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_2_1) + 4) & 127;
  int stage_v_180_2 = ((((stage_v_173_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_74_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_11_1) + 14) & 127;
  int stage_v_181_2 = ((((stage_v_74_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_159_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_2_1) + 34) & 127;
  int stage_v_182_2 = ((((stage_v_159_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_2_1) + 26) & 127;
  int stage_v_183_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_95_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_1_1) + 29) & 127;
  int stage_v_184_2 = ((((stage_v_95_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((stage_v_111_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_5_1) + 5) & 127;
  int stage_v_185_2 = ((((stage_v_111_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_163_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_4_1) + 28) & 127;
  int stage_v_186_2 = ((((stage_v_163_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_12_1) + 12) & 127;
  int stage_v_187_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_149_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_11_1) + 30) & 127;
  int stage_v_188_2 = ((((stage_v_149_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_84_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_9_1) + 33) & 127;
  int stage_v_189_2 = ((((stage_v_84_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_125_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 20) & 127;
  int stage_v_190_2 = ((((stage_v_125_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_168_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_1_1) + 31) & 127;
  int stage_v_191_2 = ((((stage_v_168_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_46_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_2_1) + 20) & 127;
  int stage_v_192_2 = ((((stage_v_46_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_15_1) + 7) & 127;
  int stage_v_193_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_77_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_14_1) + 6) & 127;
  int stage_v_194_2 = ((((stage_v_77_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_13_1) + 12) & 127;
  int stage_v_195_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_23_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_0_1) + 30) & 127;
  int stage_v_196_2 = ((((stage_v_23_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((stage_v_174_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_11_1) + 3) & 127;
  int stage_v_197_2 = ((((stage_v_174_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_32_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_5_1) + 24) & 127;
  int stage_v_198_2 = ((((stage_v_32_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_195_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_1_1) + 6) & 127;
  int stage_v_199_2 = ((((stage_v_195_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_55_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_6_1) + 12) & 127;
  int stage_v_200_2 = ((((stage_v_55_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_64_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_0_1) + 33) & 127;
  int stage_v_201_2 = ((((stage_v_64_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_100_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_1_1) + 18) & 127;
  int stage_v_202_2 = ((((stage_v_100_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_44_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_10_1) + 28) & 127;
  int stage_v_203_2 = ((((stage_v_44_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_10_1) + 7) & 127;
  int stage_v_204_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_129_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_12_1) + 4) & 127;
  int stage_v_205_2 = ((((stage_v_129_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_155_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_0_1) + 27) & 127;
  int stage_v_206_2 = ((((stage_v_155_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_185_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_12_1) + 37) & 127;
  int stage_v_207_2 = ((((stage_v_185_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_12_1) + 7) & 127;
  int stage_v_208_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_7_1) + 11) & 127;
  int stage_v_209_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_4_1) + 19) & 127;
  int stage_v_210_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_4_1) + 10) & 127;
  int stage_v_211_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_45_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_1_1) + 27) & 127;
  int stage_v_212_2 = ((((stage_v_45_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_8_1) + 30) & 127;
  int stage_v_213_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_11_1) + 19) & 127;
  int stage_v_214_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_174_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_4_1) + 28) & 127;
  int stage_v_215_2 = ((((stage_v_174_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_13_1) + 34) & 127;
  int stage_v_216_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_14_1) + 25) & 127;
  int stage_v_217_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_97_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_0_1) + 21) & 127;
  int stage_v_218_2 = ((((stage_v_97_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_186_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_15_1) + 32) & 127;
  int stage_v_219_2 = ((((stage_v_186_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_117_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_1_1) + 31) & 127;
  int stage_v_220_2 = ((((stage_v_117_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_120_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_13_1) + 13) & 127;
  int stage_v_221_2 = ((((stage_v_120_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_71_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_11_1) + 30) & 127;
  int stage_v_222_2 = ((((stage_v_71_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_154_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_5_1) + 15) & 127;
  int stage_v_223_2 = ((((stage_v_154_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_7_1) + 18) & 127;
  int stage_v_224_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_223_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_15_1) + 28) & 127;
  int stage_v_225_2 = ((((stage_v_223_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_58_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_3_1) + 5) & 127;
  int stage_v_226_2 = ((((stage_v_58_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_12_1) + 10) & 127;
  int stage_v_227_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((sec_r000414_10_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_4_1) + 14) & 127;
  int stage_v_228_2 = ((((sec_r000414_10_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_12_1) + 5) & 127;
  int stage_v_229_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_14_1) + 35) & 127;
  int stage_v_230_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_33_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_10_1) + 27) & 127;
  int stage_v_231_2 = ((((stage_v_33_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_79_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 24) & 127;
  int stage_v_232_2 = ((((stage_v_79_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_64_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_10_1) + 35) & 127;
  int stage_v_233_2 = ((((stage_v_64_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_3_1) + 19) & 127;
  int stage_v_234_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_216_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_3_1) + 26) & 127;
  int stage_v_235_2 = ((((stage_v_216_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_10_1) + 25) & 127;
  int stage_v_236_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_27_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_2_1) + 19) & 127;
  int stage_v_237_2 = ((((stage_v_27_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_3_1) + 14) & 127;
  int stage_v_238_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_72_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_4_1) + 35) & 127;
  int stage_v_239_2 = ((((stage_v_72_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_226_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_12_1) + 33) & 127;
  int stage_v_240_2 = ((((stage_v_226_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_1_1) + 7) & 127;
  int stage_v_241_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_107_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_8_1) + 36) & 127;
  int stage_v_242_2 = ((((stage_v_107_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_154_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_13_1) + 6) & 127;
  int stage_v_243_2 = ((((stage_v_154_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_239_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_11_1) + 20) & 127;
  int stage_v_244_2 = ((((stage_v_239_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_238_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_15_1) + 9) & 127;
  int stage_v_245_2 = ((((stage_v_238_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_218_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_13_1) + 24) & 127;
  int stage_v_246_2 = ((((stage_v_218_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_52_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_3_1) + 9) & 127;
  int stage_v_247_2 = ((((stage_v_52_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_116_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_10_1) + 24) & 127;
  int stage_v_248_2 = ((((stage_v_116_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_92_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_2_1) + 33) & 127;
  int stage_v_249_2 = ((((stage_v_92_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_91_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_4_1) + 8) & 127;
  int stage_v_250_2 = ((((stage_v_91_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000414_15_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_3_1) + 15) & 127;
  int stage_v_251_2 = ((((sec_r000414_15_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_213_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_14_1) + 29) & 127;
  int stage_v_252_2 = ((((stage_v_213_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_240_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_10_1) + 26) & 127;
  int stage_v_253_2 = ((((stage_v_240_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_13_1) + 8) & 127;
  int stage_v_254_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((sec_r000414_10_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_7_1) + 17) & 127;
  int stage_v_255_2 = ((((sec_r000414_10_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_110_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_14_1) + 25) & 127;
  int stage_v_256_2 = ((((stage_v_110_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_194_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_4_1) + 6) & 127;
  int stage_v_257_2 = ((((stage_v_194_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_10_1) + 21) & 127;
  int stage_v_258_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_74_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_1_1) + 11) & 127;
  int stage_v_259_2 = ((((stage_v_74_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_25_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_2_1) + 25) & 127;
  int stage_v_260_2 = ((((stage_v_25_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_13_1) + 6) & 127;
  int stage_v_261_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_6_1) + 28) & 127;
  int stage_v_262_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_10_1) + 34) & 127;
  int stage_v_263_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_14_1) + 13) & 127;
  int stage_v_264_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_159_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_6_1) + 23) & 127;
  int stage_v_265_2 = ((((stage_v_159_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_14_1) + 28) & 127;
  int stage_v_266_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_147_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_10_1) + 28) & 127;
  int stage_v_267_2 = ((((stage_v_147_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_2_1) + 17) & 127;
  int stage_v_268_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_2_1) + 11) & 127;
  int stage_v_269_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_6_1) + 5) & 127;
  int stage_v_270_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_15_1) + 3) & 127;
  int stage_v_271_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_188_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_6_1) + 21) & 127;
  int stage_v_272_2 = ((((stage_v_188_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((stage_v_237_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_11_1) + 12) & 127;
  int stage_v_273_2 = ((((stage_v_237_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_5_1) + 31) & 127;
  int stage_v_274_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_7_1) + 11) & 127;
  int stage_v_275_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_161_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_14_1) + 11) & 127;
  int stage_v_276_2 = ((((stage_v_161_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_62_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_10_1) + 14) & 127;
  int stage_v_277_2 = ((((stage_v_62_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_152_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_6_1) + 36) & 127;
  int stage_v_278_2 = ((((stage_v_152_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_13_1) + 10) & 127;
  int stage_v_279_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_95_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_1_1) + 31) & 127;
  int stage_v_280_2 = ((((stage_v_95_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_148_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_7_1) + 18) & 127;
  int stage_v_281_2 = ((((stage_v_148_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_8_1) + 21) & 127;
  int stage_v_282_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_4_1) + 33) & 127;
  int stage_v_283_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((stage_v_279_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_3_1) + 7) & 127;
  int stage_v_284_2 = ((((stage_v_279_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_97_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_1_1) + 3) & 127;
  int stage_v_285_2 = ((((stage_v_97_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_14_1) + 25) & 127;
  int stage_v_286_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_114_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_3_1) + 15) & 127;
  int stage_v_287_2 = ((((stage_v_114_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_12_1) + 37) & 127;
  int stage_v_288_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_68_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_6_1) + 4) & 127;
  int stage_v_289_2 = ((((stage_v_68_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_162_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_10_1) + 32) & 127;
  int stage_v_290_2 = ((((stage_v_162_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_38_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_14_1) + 17) & 127;
  int stage_v_291_2 = ((((stage_v_38_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_77_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_14_1) + 7) & 127;
  int stage_v_292_2 = ((((stage_v_77_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_78_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_7_1) + 5) & 127;
  int stage_v_293_2 = ((((stage_v_78_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_103_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_12_1) + 23) & 127;
  int stage_v_294_2 = ((((stage_v_103_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_225_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_5_1) + 29) & 127;
  int stage_v_295_2 = ((((stage_v_225_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_4_1) + 8) & 127;
  int stage_v_296_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_2_1) + 19) & 127;
  int stage_v_297_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_29_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_11_1) + 32) & 127;
  int stage_v_298_2 = ((((stage_v_29_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_212_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_2_1) + 37) & 127;
  int stage_v_299_2 = ((((stage_v_212_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_246_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_6_1) + 10) & 127;
  int stage_v_300_2 = ((((stage_v_246_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_295_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_1_1) + 32) & 127;
  int stage_v_301_2 = ((((stage_v_295_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_43_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_14_1) + 5) & 127;
  int stage_v_302_2 = ((((stage_v_43_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_10_1) + 12) & 127;
  int stage_v_303_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_10_1) + 15) & 127;
  int stage_v_304_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_70_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_1_1) + 28) & 127;
  int stage_v_305_2 = ((((stage_v_70_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_299_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_7_1) + 18) & 127;
  int stage_v_306_2 = ((((stage_v_299_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_282_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_13_1) + 33) & 127;
  int stage_v_307_2 = ((((stage_v_282_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_304_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_14_1) + 20) & 127;
  int stage_v_308_2 = ((((stage_v_304_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_14_1) + 27) & 127;
  int stage_v_309_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_247_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_7_1) + 19) & 127;
  int stage_v_310_2 = ((((stage_v_247_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_228_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_12_1) + 25) & 127;
  int stage_v_311_2 = ((((stage_v_228_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_30_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_6_1) + 21) & 127;
  int stage_v_312_2 = ((((stage_v_30_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_305_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_6_1) + 28) & 127;
  int stage_v_313_2 = ((((stage_v_305_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_112_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_5_1) + 12) & 127;
  int stage_v_314_2 = ((((stage_v_112_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((stage_v_194_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_10_1) + 32) & 127;
  int stage_v_315_2 = ((((stage_v_194_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((stage_v_241_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_7_1) + 11) & 127;
  int stage_v_316_2 = ((((stage_v_241_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_5_1) + 7) & 127;
  int stage_v_317_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_7_1) + 9) & 127;
  int stage_v_318_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_85_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_12_1) + 37) & 127;
  int stage_v_319_2 = ((((stage_v_85_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_263_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_14_1) + 18) & 127;
  int stage_v_320_2 = ((((stage_v_263_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((stage_v_288_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_13_1) + 21) & 127;
  int stage_v_321_2 = ((((stage_v_288_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_294_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_10_1) + 17) & 127;
  int stage_v_322_2 = ((((stage_v_294_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_158_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_15_1) + 26) & 127;
  int stage_v_323_2 = ((((stage_v_158_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_152_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_7_1) + 11) & 127;
  int stage_v_324_2 = ((((stage_v_152_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((stage_v_261_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_13_1) + 32) & 127;
  int stage_v_325_2 = ((((stage_v_261_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_47_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_13_1) + 16) & 127;
  int stage_v_326_2 = ((((stage_v_47_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_15_1) + 19) & 127;
  int stage_v_327_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((stage_v_216_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_10_1) + 25) & 127;
  int stage_v_328_2 = ((((stage_v_216_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((stage_v_161_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_10_1) + 36) & 127;
  int stage_v_329_2 = ((((stage_v_161_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_1_1) + 29) & 127;
  int stage_v_330_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_35_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_12_1) + 37) & 127;
  int stage_v_331_2 = ((((stage_v_35_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((stage_v_294_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_8_1) + 19) & 127;
  int stage_v_332_2 = ((((stage_v_294_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_0_1) + 34) & 127;
  int stage_v_333_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_100_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_1_1) + 10) & 127;
  int stage_v_334_2 = ((((stage_v_100_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_1_1) + 31) & 127;
  int stage_v_335_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 32) & 127;
  int stage_v_336_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((((stage_v_174_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_9_1) + 28) & 127;
  int stage_v_337_2 = ((((stage_v_174_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_337_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_337_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((((stage_v_82_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_14_1) + 3) & 127;
  int stage_v_338_2 = ((((stage_v_82_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_338_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_338_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((((stage_v_269_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_8_1) + 7) & 127;
  int stage_v_339_2 = ((((stage_v_269_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_339_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_339_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((((stage_v_153_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_2_1) + 31) & 127;
  int stage_v_340_2 = ((((stage_v_153_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_340_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_340_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_5_1) + 6) & 127;
  int stage_v_341_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_341_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_341_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((((stage_v_71_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_11_1) + 20) & 127;
  int stage_v_342_2 = ((((stage_v_71_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_342_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_342_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((((stage_v_267_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_11_1) + 10) & 127;
  int stage_v_343_2 = ((((stage_v_267_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_343_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_343_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((((stage_v_211_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_9_1) + 21) & 127;
  int stage_v_344_2 = ((((stage_v_211_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_344_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_344_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_14_1) + 30) & 127;
  int stage_v_345_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_345_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_345_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((((stage_v_90_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_12_1) + 28) & 127;
  int stage_v_346_2 = ((((stage_v_90_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_346_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_346_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_2_1) + 9) & 127;
  int stage_v_347_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_347_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_347_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((((stage_v_114_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_11_1) + 24) & 127;
  int stage_v_348_2 = ((((stage_v_114_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_348_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_348_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((((stage_v_66_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_15_1) + 12) & 127;
  int stage_v_349_2 = ((((stage_v_66_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_349_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_349_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((((stage_v_181_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_8_1) + 16) & 127;
  int stage_v_350_2 = ((((stage_v_181_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_350_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_350_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((((stage_v_127_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_10_1) + 18) & 127;
  int stage_v_351_2 = ((((stage_v_127_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_351_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_351_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_2_1) + 26) & 127;
  int stage_v_352_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_352_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_352_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((((stage_v_117_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_11_1) + 8) & 127;
  int stage_v_353_2 = ((((stage_v_117_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_353_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_353_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_8_1) + 19) & 127;
  int stage_v_354_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_354_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_354_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((((stage_v_333_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_14_1) + 37) & 127;
  int stage_v_355_2 = ((((stage_v_333_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_355_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_355_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_1_1) + 15) & 127;
  int stage_v_356_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_356_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_356_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_7_1) + 14) & 127;
  int stage_v_357_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_357_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_357_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((((stage_v_165_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_13_1) + 22) & 127;
  int stage_v_358_2 = ((((stage_v_165_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_358_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_358_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((((stage_v_117_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_3_1) + 21) & 127;
  int stage_v_359_2 = ((((stage_v_117_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_359_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_359_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((((stage_v_328_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_1_1) + 17) & 127;
  int stage_v_360_2 = ((((stage_v_328_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_360_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_360_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((((stage_v_187_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_11_1) + 22) & 127;
  int stage_v_361_2 = ((((stage_v_187_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_361_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_361_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_0_1) + 27) & 127;
  int stage_v_362_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_362_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_362_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_14_1) + 24) & 127;
  int stage_v_363_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_363_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_363_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((((stage_v_25_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_5_1) + 20) & 127;
  int stage_v_364_2 = ((((stage_v_25_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_364_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_364_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((((stage_v_167_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_1_1) + 14) & 127;
  int stage_v_365_2 = ((((stage_v_167_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_365_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_365_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((((stage_v_266_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_1_1) + 32) & 127;
  int stage_v_366_2 = ((((stage_v_266_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_366_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_366_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((((stage_v_247_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_13_1) + 11) & 127;
  int stage_v_367_2 = ((((stage_v_247_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_367_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_367_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((((stage_v_82_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_13_1) + 16) & 127;
  int stage_v_368_2 = ((((stage_v_82_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_368_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_368_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_4_1) + 17) & 127;
  int stage_v_369_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_369_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_369_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((((stage_v_81_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_5_1) + 36) & 127;
  int stage_v_370_2 = ((((stage_v_81_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_370_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_370_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((((sec_r000414_15_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_7_1) + 27) & 127;
  int stage_v_371_2 = ((((sec_r000414_15_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_371_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_371_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((((stage_v_49_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_7_1) + 18) & 127;
  int stage_v_372_2 = ((((stage_v_49_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_372_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_372_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((((stage_v_78_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_15_1) + 23) & 127;
  int stage_v_373_2 = ((((stage_v_78_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_373_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_373_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((((stage_v_318_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_2_1) + 34) & 127;
  int stage_v_374_2 = ((((stage_v_318_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_374_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_374_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_0_1) + 34) & 127;
  int stage_v_375_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_375_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_375_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_4_1) + 16) & 127;
  int stage_v_376_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_376_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_376_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_0_1) + 19) & 127;
  int stage_v_377_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_377_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_377_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_13_1) + 17) & 127;
  int stage_v_378_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_378_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_378_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_2_1) + 7) & 127;
  int stage_v_379_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_379_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_379_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((((stage_v_265_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_14_1) + 12) & 127;
  int stage_v_380_2 = ((((stage_v_265_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_380_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_380_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((((stage_v_244_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_11_1) + 34) & 127;
  int stage_v_381_2 = ((((stage_v_244_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_381_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_381_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((((sec_r000414_0_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_7_1) + 19) & 127;
  int stage_v_382_2 = ((((sec_r000414_0_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_382_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_382_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((((stage_v_349_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_12_1) + 31) & 127;
  int stage_v_383_2 = ((((stage_v_349_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_383_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_383_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((((stage_v_348_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_4_1) + 24) & 127;
  int stage_v_384_2 = ((((stage_v_348_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_384_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_384_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((((stage_v_153_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_13_1) + 10) & 127;
  int stage_v_385_2 = ((((stage_v_153_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_385_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_385_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((((stage_v_114_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_13_1) + 18) & 127;
  int stage_v_386_2 = ((((stage_v_114_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_386_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_386_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((((stage_v_36_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_9_1) + 6) & 127;
  int stage_v_387_2 = ((((stage_v_36_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_387_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_387_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((((stage_v_142_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_1_1) + 16) & 127;
  int stage_v_388_2 = ((((stage_v_142_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_388_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_388_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_9_1) + 36) & 127;
  int stage_v_389_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_389_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_389_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((((sec_r000414_5_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_0_1) + 13) & 127;
  int stage_v_390_2 = ((((sec_r000414_5_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_390_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_390_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((((stage_v_142_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_1_1) + 27) & 127;
  int stage_v_391_2 = ((((stage_v_142_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_391_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_391_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((((stage_v_305_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_10_1) + 9) & 127;
  int stage_v_392_2 = ((((stage_v_305_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_392_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_392_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((((stage_v_159_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_14_1) + 8) & 127;
  int stage_v_393_2 = ((((stage_v_159_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_393_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_393_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((((sec_r000414_14_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_2_1) + 14) & 127;
  int stage_v_394_2 = ((((sec_r000414_14_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_394_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_394_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  int stage_v_395_1 = ((((sec_r000414_7_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_3_1) + 3) & 127;
  int stage_v_395_2 = ((((sec_r000414_7_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_395_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_395_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_395_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_395_2) & 255;
  int stage_v_396_1 = ((((stage_v_28_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_7_1) + 13) & 127;
  int stage_v_396_2 = ((((stage_v_28_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_396_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_396_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_396_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_396_2) & 255;
  int stage_v_397_1 = ((((stage_v_223_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_0_1) + 11) & 127;
  int stage_v_397_2 = ((((stage_v_223_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_397_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_397_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_397_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_397_2) & 255;
  int stage_v_398_1 = ((((stage_v_67_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_12_1) + 36) & 127;
  int stage_v_398_2 = ((((stage_v_67_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_398_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_398_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_398_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_398_2) & 255;
  int stage_v_399_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_10_1) + 12) & 127;
  int stage_v_399_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_399_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_399_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_399_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_399_2) & 255;
  int stage_v_400_1 = ((((sec_r000414_10_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_3_1) + 18) & 127;
  int stage_v_400_2 = ((((sec_r000414_10_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_400_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_400_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_400_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_400_2) & 255;
  int stage_v_401_1 = ((((sec_r000414_9_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_10_1) + 24) & 127;
  int stage_v_401_2 = ((((sec_r000414_9_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_401_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_401_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_401_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_401_2) & 255;
  int stage_v_402_1 = ((((stage_v_99_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_3_1) + 3) & 127;
  int stage_v_402_2 = ((((stage_v_99_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_402_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_402_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_402_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_402_2) & 255;
  int stage_v_403_1 = ((((stage_v_300_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_0_1) + 18) & 127;
  int stage_v_403_2 = ((((stage_v_300_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_403_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_403_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_403_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_403_2) & 255;
  int stage_v_404_1 = ((((stage_v_293_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_3_1) + 32) & 127;
  int stage_v_404_2 = ((((stage_v_293_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_404_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_404_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_404_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_404_2) & 255;
  int stage_v_405_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_11_1) + 5) & 127;
  int stage_v_405_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_405_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_405_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_405_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_405_2) & 255;
  int stage_v_406_1 = ((((stage_v_158_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_12_1) + 5) & 127;
  int stage_v_406_2 = ((((stage_v_158_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_406_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_406_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_406_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_406_2) & 255;
  int stage_v_407_1 = ((((stage_v_327_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_6_1) + 10) & 127;
  int stage_v_407_2 = ((((stage_v_327_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_407_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_407_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_407_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_407_2) & 255;
  int stage_v_408_1 = ((((stage_v_403_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_2_1) + 4) & 127;
  int stage_v_408_2 = ((((stage_v_403_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_408_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_408_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_408_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_408_2) & 255;
  int stage_v_409_1 = ((((stage_v_100_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_14_1) + 7) & 127;
  int stage_v_409_2 = ((((stage_v_100_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_409_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_409_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_409_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_409_2) & 255;
  int stage_v_410_1 = ((((stage_v_176_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_5_1) + 3) & 127;
  int stage_v_410_2 = ((((stage_v_176_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_410_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_410_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_410_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_410_2) & 255;
  int stage_v_411_1 = ((((stage_v_122_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_1_1) + 21) & 127;
  int stage_v_411_2 = ((((stage_v_122_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_411_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_411_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_411_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_411_2) & 255;
  int stage_v_412_1 = ((((stage_v_59_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_4_1) + 29) & 127;
  int stage_v_412_2 = ((((stage_v_59_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_412_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_412_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_412_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_412_2) & 255;
  int stage_v_413_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_15_1) + 25) & 127;
  int stage_v_413_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_413_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_413_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_413_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_413_2) & 255;
  int stage_v_414_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_14_1) + 32) & 127;
  int stage_v_414_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_414_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_414_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_414_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_414_2) & 255;
  int stage_v_415_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_15_1) + 33) & 127;
  int stage_v_415_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_415_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_415_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_415_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_415_2) & 255;
  int stage_v_416_1 = ((((stage_v_383_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_1_1) + 13) & 127;
  int stage_v_416_2 = ((((stage_v_383_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_416_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_416_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_416_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_416_2) & 255;
  int stage_v_417_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_2_1) + 15) & 127;
  int stage_v_417_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_417_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_417_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_417_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_417_2) & 255;
  int stage_v_418_1 = ((((stage_v_37_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_13_1) + 26) & 127;
  int stage_v_418_2 = ((((stage_v_37_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_418_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_418_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_418_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_418_2) & 255;
  int stage_v_419_1 = ((((stage_v_203_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_4_1) + 28) & 127;
  int stage_v_419_2 = ((((stage_v_203_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_419_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_419_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_419_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_419_2) & 255;
  int stage_v_420_1 = ((((stage_v_369_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_7_1) + 21) & 127;
  int stage_v_420_2 = ((((stage_v_369_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_420_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_420_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_420_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_420_2) & 255;
  int stage_v_421_1 = ((((stage_v_360_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_5_1) + 14) & 127;
  int stage_v_421_2 = ((((stage_v_360_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_421_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_421_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_421_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_421_2) & 255;
  int stage_v_422_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_15_1) + 25) & 127;
  int stage_v_422_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_422_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_422_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_422_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_422_2) & 255;
  int stage_v_423_1 = ((((stage_v_159_1 * 3) + (sec_r000414_7_1 * 2)) - pub_r000414_5_1) + 24) & 127;
  int stage_v_423_2 = ((((stage_v_159_2 * 3) + (sec_r000414_7_2 * 2)) - pub_r000414_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_423_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_423_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_423_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_423_2) & 255;
  int stage_v_424_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_12_1) + 28) & 127;
  int stage_v_424_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_424_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_424_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_424_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_424_2) & 255;
  int stage_v_425_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_14_1) + 11) & 127;
  int stage_v_425_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_425_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_425_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_425_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_425_2) & 255;
  int stage_v_426_1 = ((((stage_v_390_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_14_1) + 12) & 127;
  int stage_v_426_2 = ((((stage_v_390_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_426_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_426_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_426_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_426_2) & 255;
  int stage_v_427_1 = ((((sec_r000414_3_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_1_1) + 18) & 127;
  int stage_v_427_2 = ((((sec_r000414_3_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_427_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_427_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_427_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_427_2) & 255;
  int stage_v_428_1 = ((((stage_v_382_1 * 3) + (sec_r000414_15_1 * 2)) - pub_r000414_12_1) + 34) & 127;
  int stage_v_428_2 = ((((stage_v_382_2 * 3) + (sec_r000414_15_2 * 2)) - pub_r000414_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_428_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_428_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_428_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_428_2) & 255;
  int stage_v_429_1 = ((((stage_v_126_1 * 3) + (sec_r000414_0_1 * 2)) - pub_r000414_0_1) + 4) & 127;
  int stage_v_429_2 = ((((stage_v_126_2 * 3) + (sec_r000414_0_2 * 2)) - pub_r000414_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_429_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_429_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_429_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_429_2) & 255;
  int stage_v_430_1 = ((((stage_v_326_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_14_1) + 19) & 127;
  int stage_v_430_2 = ((((stage_v_326_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_430_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_430_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_430_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_430_2) & 255;
  int stage_v_431_1 = ((((sec_r000414_16_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_11_1) + 6) & 127;
  int stage_v_431_2 = ((((sec_r000414_16_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_431_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_431_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_431_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_431_2) & 255;
  int stage_v_432_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_15_1) + 30) & 127;
  int stage_v_432_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_432_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_432_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_432_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_432_2) & 255;
  int stage_v_433_1 = ((((stage_v_401_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_11_1) + 12) & 127;
  int stage_v_433_2 = ((((stage_v_401_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_433_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_433_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_433_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_433_2) & 255;
  int stage_v_434_1 = ((((stage_v_41_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_13_1) + 37) & 127;
  int stage_v_434_2 = ((((stage_v_41_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_434_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_434_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_434_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_434_2) & 255;
  int stage_v_435_1 = ((((stage_v_392_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_6_1) + 9) & 127;
  int stage_v_435_2 = ((((stage_v_392_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_435_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_435_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_435_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_435_2) & 255;
  int stage_v_436_1 = ((((sec_r000414_10_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_11_1) + 14) & 127;
  int stage_v_436_2 = ((((sec_r000414_10_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_436_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_436_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_436_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_436_2) & 255;
  int stage_v_437_1 = ((((stage_v_240_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_0_1) + 27) & 127;
  int stage_v_437_2 = ((((stage_v_240_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_437_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_437_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_437_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_437_2) & 255;
  int stage_v_438_1 = ((((stage_v_25_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_2_1) + 3) & 127;
  int stage_v_438_2 = ((((stage_v_25_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_438_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_438_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_438_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_438_2) & 255;
  int stage_v_439_1 = ((((sec_r000414_17_1 * 3) + (sec_r000414_17_1 * 2)) - pub_r000414_2_1) + 23) & 127;
  int stage_v_439_2 = ((((sec_r000414_17_2 * 3) + (sec_r000414_17_2 * 2)) - pub_r000414_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_439_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_439_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_439_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_439_2) & 255;
  int stage_v_440_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_6_1) + 11) & 127;
  int stage_v_440_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_440_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_440_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_440_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_440_2) & 255;
  int stage_v_441_1 = ((((sec_r000414_4_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_8_1) + 33) & 127;
  int stage_v_441_2 = ((((sec_r000414_4_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_441_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_441_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_441_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_441_2) & 255;
  int stage_v_442_1 = ((((stage_v_303_1 * 3) + (sec_r000414_10_1 * 2)) - pub_r000414_6_1) + 5) & 127;
  int stage_v_442_2 = ((((stage_v_303_2 * 3) + (sec_r000414_10_2 * 2)) - pub_r000414_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_442_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_442_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_442_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_442_2) & 255;
  int stage_v_443_1 = ((((stage_v_293_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_10_1) + 15) & 127;
  int stage_v_443_2 = ((((stage_v_293_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_443_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_443_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_443_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_443_2) & 255;
  int stage_v_444_1 = ((((stage_v_265_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_11_1) + 7) & 127;
  int stage_v_444_2 = ((((stage_v_265_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_444_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_444_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_444_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_444_2) & 255;
  int stage_v_445_1 = ((((stage_v_336_1 * 3) + (sec_r000414_4_1 * 2)) - pub_r000414_6_1) + 3) & 127;
  int stage_v_445_2 = ((((stage_v_336_2 * 3) + (sec_r000414_4_2 * 2)) - pub_r000414_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_445_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_445_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_445_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_445_2) & 255;
  int stage_v_446_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_4_1) + 10) & 127;
  int stage_v_446_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_446_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_446_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_446_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_446_2) & 255;
  int stage_v_447_1 = ((((stage_v_107_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_15_1) + 29) & 127;
  int stage_v_447_2 = ((((stage_v_107_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_447_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_447_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_447_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_447_2) & 255;
  int stage_v_448_1 = ((((sec_r000414_13_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_2_1) + 17) & 127;
  int stage_v_448_2 = ((((sec_r000414_13_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_448_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_448_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_448_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_448_2) & 255;
  int stage_v_449_1 = ((((sec_r000414_11_1 * 3) + (sec_r000414_11_1 * 2)) - pub_r000414_9_1) + 17) & 127;
  int stage_v_449_2 = ((((sec_r000414_11_2 * 3) + (sec_r000414_11_2 * 2)) - pub_r000414_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_449_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_449_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_449_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_449_2) & 255;
  int stage_v_450_1 = ((((stage_v_239_1 * 3) + (sec_r000414_3_1 * 2)) - pub_r000414_1_1) + 10) & 127;
  int stage_v_450_2 = ((((stage_v_239_2 * 3) + (sec_r000414_3_2 * 2)) - pub_r000414_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_450_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_450_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_450_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_450_2) & 255;
  int stage_v_451_1 = ((((sec_r000414_12_1 * 3) + (sec_r000414_12_1 * 2)) - pub_r000414_14_1) + 28) & 127;
  int stage_v_451_2 = ((((sec_r000414_12_2 * 3) + (sec_r000414_12_2 * 2)) - pub_r000414_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_451_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_451_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_451_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_451_2) & 255;
  int stage_v_452_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_8_1) + 28) & 127;
  int stage_v_452_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_452_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_452_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_452_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_452_2) & 255;
  int stage_v_453_1 = ((((sec_r000414_8_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_7_1) + 29) & 127;
  int stage_v_453_2 = ((((sec_r000414_8_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_453_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_453_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_453_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_453_2) & 255;
  int stage_v_454_1 = ((((sec_r000414_1_1 * 3) + (sec_r000414_1_1 * 2)) - pub_r000414_11_1) + 34) & 127;
  int stage_v_454_2 = ((((sec_r000414_1_2 * 3) + (sec_r000414_1_2 * 2)) - pub_r000414_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_454_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_454_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_454_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_454_2) & 255;
  int stage_v_455_1 = ((((stage_v_142_1 * 3) + (sec_r000414_9_1 * 2)) - pub_r000414_0_1) + 8) & 127;
  int stage_v_455_2 = ((((stage_v_142_2 * 3) + (sec_r000414_9_2 * 2)) - pub_r000414_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_455_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_455_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_455_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_455_2) & 255;
  int stage_v_456_1 = ((((stage_v_432_1 * 3) + (sec_r000414_13_1 * 2)) - pub_r000414_15_1) + 23) & 127;
  int stage_v_456_2 = ((((stage_v_432_2 * 3) + (sec_r000414_13_2 * 2)) - pub_r000414_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_456_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_456_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_456_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_456_2) & 255;
  int stage_v_457_1 = ((((sec_r000414_2_1 * 3) + (sec_r000414_2_1 * 2)) - pub_r000414_3_1) + 33) & 127;
  int stage_v_457_2 = ((((sec_r000414_2_2 * 3) + (sec_r000414_2_2 * 2)) - pub_r000414_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_457_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_457_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_457_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_457_2) & 255;
  int stage_v_458_1 = ((((stage_v_45_1 * 3) + (sec_r000414_16_1 * 2)) - pub_r000414_1_1) + 35) & 127;
  int stage_v_458_2 = ((((stage_v_45_2 * 3) + (sec_r000414_16_2 * 2)) - pub_r000414_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_458_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_458_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_458_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_458_2) & 255;
  int stage_v_459_1 = ((((sec_r000414_6_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_12_1) + 5) & 127;
  int stage_v_459_2 = ((((sec_r000414_6_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_459_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_459_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_459_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_459_2) & 255;
  int stage_v_460_1 = ((((stage_v_168_1 * 3) + (sec_r000414_8_1 * 2)) - pub_r000414_10_1) + 31) & 127;
  int stage_v_460_2 = ((((stage_v_168_2 * 3) + (sec_r000414_8_2 * 2)) - pub_r000414_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_460_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_460_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_460_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_460_2) & 255;
  int stage_v_461_1 = ((((stage_v_61_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_15_1) + 17) & 127;
  int stage_v_461_2 = ((((stage_v_61_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_461_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_461_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_461_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_461_2) & 255;
  int stage_v_462_1 = ((((stage_v_332_1 * 3) + (sec_r000414_6_1 * 2)) - pub_r000414_2_1) + 21) & 127;
  int stage_v_462_2 = ((((stage_v_332_2 * 3) + (sec_r000414_6_2 * 2)) - pub_r000414_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_462_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_462_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_462_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_462_2) & 255;
  int stage_v_463_1 = ((((stage_v_219_1 * 3) + (sec_r000414_5_1 * 2)) - pub_r000414_2_1) + 17) & 127;
  int stage_v_463_2 = ((((stage_v_219_2 * 3) + (sec_r000414_5_2 * 2)) - pub_r000414_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_463_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_463_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_463_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_463_2) & 255;
  int stage_v_464_1 = ((((stage_v_150_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_11_1) + 30) & 127;
  int stage_v_464_2 = ((((stage_v_150_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_464_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_464_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_464_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_464_2) & 255;
  int stage_v_465_1 = ((((stage_v_310_1 * 3) + (sec_r000414_14_1 * 2)) - pub_r000414_2_1) + 19) & 127;
  int stage_v_465_2 = ((((stage_v_310_2 * 3) + (sec_r000414_14_2 * 2)) - pub_r000414_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_465_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_465_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_465_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_465_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000414_0_1 != sec_r000414_0_2);
  __CPROVER_assume(sec_r000414_8_1 != sec_r000414_8_2);
  __CPROVER_assume(sec_r000414_12_1 != sec_r000414_12_2);
  __CPROVER_assume(sec_r000414_15_1 != sec_r000414_15_2);
  __CPROVER_assume(sec_r000414_6_1 != sec_r000414_6_2);
  __CPROVER_assume(pub_r000414_8_1 == pub_r000414_8_2);
  __CPROVER_assume(sec_r000414_3_1 != sec_r000414_3_2);
  __CPROVER_assume(pub_r000414_15_1 == pub_r000414_15_2);
  __CPROVER_assume(pub_r000414_4_1 == pub_r000414_4_2);
  __CPROVER_assume(pub_r000414_12_1 == pub_r000414_12_2);
  __CPROVER_assume(pub_r000414_9_1 == pub_r000414_9_2);
  __CPROVER_assume(sec_r000414_10_1 != sec_r000414_10_2);
  __CPROVER_assume(pub_r000414_2_1 == pub_r000414_2_2);
  __CPROVER_assume(sec_r000414_11_1 != sec_r000414_11_2);
  __CPROVER_assume(sec_r000414_16_1 != sec_r000414_16_2);
  __CPROVER_assume(sec_r000414_5_1 != sec_r000414_5_2);
  __CPROVER_assume(pub_r000414_0_1 == pub_r000414_0_2);
  __CPROVER_assume(pub_r000414_11_1 == pub_r000414_11_2);
  __CPROVER_assume(sec_r000414_13_1 != sec_r000414_13_2);
  __CPROVER_assume(sec_r000414_17_1 != sec_r000414_17_2);
  __CPROVER_assume(pub_r000414_14_1 == pub_r000414_14_2);
  __CPROVER_assume(pub_r000414_7_1 == pub_r000414_7_2);
  __CPROVER_assume(pub_r000414_5_1 == pub_r000414_5_2);
  __CPROVER_assume(pub_r000414_1_1 == pub_r000414_1_2);
  __CPROVER_assume(sec_r000414_2_1 != sec_r000414_2_2);
  __CPROVER_assume(pub_r000414_6_1 == pub_r000414_6_2);
  __CPROVER_assume(sec_r000414_1_1 != sec_r000414_1_2);
  __CPROVER_assume(pub_r000414_3_1 == pub_r000414_3_2);
  __CPROVER_assume(sec_r000414_4_1 != sec_r000414_4_2);
  __CPROVER_assume(pub_r000414_10_1 == pub_r000414_10_2);
  __CPROVER_assume(sec_r000414_14_1 != sec_r000414_14_2);
  __CPROVER_assume(sec_r000414_7_1 != sec_r000414_7_2);
  __CPROVER_assume(sec_r000414_9_1 != sec_r000414_9_2);
  __CPROVER_assume(pub_r000414_13_1 == pub_r000414_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.status == st_var_2_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
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
  assert(stage_v_157_1 == stage_v_157_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(stage_v_287_1 == stage_v_287_2);
  assert(stage_v_288_1 == stage_v_288_2);
  assert(stage_v_289_1 == stage_v_289_2);
  assert(stage_v_290_1 == stage_v_290_2);
  assert(stage_v_291_1 == stage_v_291_2);
  assert(stage_v_292_1 == stage_v_292_2);
  assert(stage_v_293_1 == stage_v_293_2);
  assert(stage_v_294_1 == stage_v_294_2);
  assert(stage_v_295_1 == stage_v_295_2);
  assert(stage_v_296_1 == stage_v_296_2);
  assert(stage_v_297_1 == stage_v_297_2);
  assert(stage_v_298_1 == stage_v_298_2);
  assert(stage_v_299_1 == stage_v_299_2);
  assert(stage_v_300_1 == stage_v_300_2);
  assert(stage_v_301_1 == stage_v_301_2);
  assert(stage_v_302_1 == stage_v_302_2);
  assert(stage_v_303_1 == stage_v_303_2);
  assert(stage_v_304_1 == stage_v_304_2);
  assert(stage_v_305_1 == stage_v_305_2);
  assert(stage_v_306_1 == stage_v_306_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
}


