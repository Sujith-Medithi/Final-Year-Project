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
struct FilterState_R001880_8013_0
{
  short mode;
  unsigned char gain_db;
  int prev_out;
  int buffer[3];
};
struct AudioFrame_R001880_8013_1
{
  short rms;
  short gain;
  short envelope;
  int channels;
  int buffer[3];
};
struct SensorNode_R001880_8013_2
{
  int threshold;
  int status;
  int gain;
  int buffer[3];
};
union TelemetryField_R001880_8013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001880_8013_1
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
void fn_R001880_8013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quotient_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_32_1)
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

  switch (quotient_32_2)
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

  int offset_94_1 = 0;
  int offset_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_94_1 = ((offset_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_94_2 = ((offset_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_94_1) & 127;
    acc_2 = (acc_2 + offset_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_32_1 == quotient_32_2);
  assert(offset_94_1 == offset_94_2);
}

int fn_R001880_8013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quotient_32 = (aux + st.buffer[1]) & 3;
  switch (quotient_32)
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

  int offset_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_94 = ((offset_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001880_8013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_73_1) & 63;
  aux_2 = (aux_2 + damping_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_36_1 = 0;
  int factor_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_36_1 = ((factor_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_36_2 = ((factor_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_36_1) & 127;
    acc_2 = (acc_2 + factor_36_2) & 127;
  }

  int sample_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_80_1)
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

  switch (sample_80_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_73_1 == damping_73_2);
  assert(factor_36_1 == factor_36_2);
  assert(sample_80_1 == sample_80_2);
}

int fn_R001880_8013_1(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_73) & 63;
  acc ^= aux;
  int factor_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_36 = ((factor_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_36) & 127;
  }

  int sample_80 = (aux + st.buffer[1]) & 3;
  switch (sample_80)
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

void fn_R001880_8013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_13_1 > 46)
  {
    acc_1 = ((acc_1 + (sample_13_1 * 2)) + 5) & 127;
    aux_1 ^= sample_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_13_2 > 46)
  {
    acc_2 = ((acc_2 + (sample_13_2 * 2)) + 5) & 127;
    aux_2 ^= sample_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_13_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_43_1)
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

  switch (checksum_43_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_23_1 = local_arr_1[aux_1 % 3];
  int stride_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_13_1 == sample_13_2);
  assert(checksum_43_1 == checksum_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_23_1 == stride_23_2);
}

int fn_R001880_8013_2(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_13 > 46)
  {
    acc = ((acc + (sample_13 * 2)) + 5) & 127;
    aux ^= sample_13 & 15;
  }
  else
  {
    acc = ((acc - sample_13) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_43 = (aux + st.buffer[1]) & 3;
  switch (checksum_43)
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

  int local_arr[3] = {4, 9, 15};
  int stride_23 = local_arr[aux % 3];
  acc = (acc + (stride_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int coefficient_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_77_1 > 33)
  {
    acc_1 = ((acc_1 + (coefficient_77_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_77_2 > 33)
  {
    acc_2 = ((acc_2 + (coefficient_77_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_14_1) & 63;
  aux_2 = (aux_2 + margin_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_77_1 == coefficient_77_2);
  assert(margin_14_1 == margin_14_2);
}

int fn_R001880_8013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int coefficient_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_77 > 33)
  {
    acc = ((acc + (coefficient_77 * 2)) + 5) & 127;
    aux ^= coefficient_77 & 15;
  }
  else
  {
    acc = ((acc - coefficient_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001880_8013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int metric_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_20_1 > 40)
  {
    acc_1 = ((acc_1 + (metric_20_1 * 2)) + 5) & 127;
    aux_1 ^= metric_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_20_2 > 40)
  {
    acc_2 = ((acc_2 + (metric_20_2 * 2)) + 5) & 127;
    aux_2 ^= metric_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_52_1)
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

  switch (damping_52_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_20_1 == metric_20_2);
  assert(damping_52_1 == damping_52_2);
}

int fn_R001880_8013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int metric_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_20 > 40)
  {
    acc = ((acc + (metric_20 * 2)) + 5) & 127;
    aux ^= metric_20 & 15;
  }
  else
  {
    acc = ((acc - metric_20) + 11) & 127;
    aux += 3;
  }
  int damping_52 = (aux + st.buffer[1]) & 3;
  switch (damping_52)
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

void fn_R001880_8013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_29_1 = local_arr_1[aux_1 % 3];
  int scale_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_29_1 == scale_29_2);
}

int fn_R001880_8013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_29 = local_arr[aux % 3];
  acc = (acc + (scale_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int coefficient_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_79_1)
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

  switch (coefficient_79_2)
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

  int checksum_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_53_1 > 28)
  {
    acc_1 = ((acc_1 + (checksum_53_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_53_2 > 28)
  {
    acc_2 = ((acc_2 + (checksum_53_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
  assert(checksum_53_1 == checksum_53_2);
}

int fn_R001880_8013_6(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int coefficient_79 = (aux + st.buffer[1]) & 3;
  switch (coefficient_79)
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

  int checksum_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_53 > 28)
  {
    acc = ((acc + (checksum_53 * 2)) + 5) & 127;
    aux ^= checksum_53 & 15;
  }
  else
  {
    acc = ((acc - checksum_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_30_1)
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

  switch (metric_30_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_30_1 == metric_30_2);
}

int fn_R001880_8013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_30 = (aux + st.buffer[1]) & 3;
  switch (metric_30)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_21_1 = local_arr_1[aux_1 % 3];
  int cursor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_21_2 * 2)) & 127;
  int phase_99_1 = 0;
  int phase_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_99_1 = ((phase_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_99_2 = ((phase_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_99_1) & 127;
    acc_2 = (acc_2 + phase_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(phase_99_1 == phase_99_2);
}

int fn_R001880_8013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int cursor_21 = local_arr[aux % 3];
  acc = (acc + (cursor_21 * 2)) & 127;
  int phase_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_99 = ((phase_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001880_8013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int delta_22_1 = 0;
  int delta_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_22_1 = ((delta_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_22_2 = ((delta_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_22_1) & 127;
    acc_2 = (acc_2 + delta_22_2) & 127;
  }

  int checksum_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_21_1)
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

  switch (checksum_21_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_22_1 == delta_22_2);
  assert(checksum_21_1 == checksum_21_2);
}

int fn_R001880_8013_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int delta_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_22 = ((delta_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_22) & 127;
  }

  int checksum_21 = (aux + st.buffer[1]) & 3;
  switch (checksum_21)
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

void fn_R001880_8013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int coefficient_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_40_1)
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

  switch (coefficient_40_2)
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
  int quotient_10_1 = local_arr_1[aux_1 % 3];
  int quotient_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_40_1 == coefficient_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_10_1 == quotient_10_2);
}

int fn_R001880_8013_10(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int coefficient_40 = (aux + st.buffer[1]) & 3;
  switch (coefficient_40)
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
  int quotient_10 = local_arr[aux % 3];
  acc = (acc + (quotient_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_36_1 = local_arr_1[aux_1 % 3];
  int tracker_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_36_2 * 2)) & 127;
  int sample_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_88_1 > 18)
  {
    acc_1 = ((acc_1 + (sample_88_1 * 2)) + 5) & 127;
    aux_1 ^= sample_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_88_2 > 18)
  {
    acc_2 = ((acc_2 + (sample_88_2 * 2)) + 5) & 127;
    aux_2 ^= sample_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_65_1) & 63;
  aux_2 = (aux_2 + weight_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_36_1 == tracker_36_2);
  assert(sample_88_1 == sample_88_2);
  assert(weight_65_1 == weight_65_2);
}

int fn_R001880_8013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int tracker_36 = local_arr[aux % 3];
  acc = (acc + (tracker_36 * 2)) & 127;
  int sample_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_88 > 18)
  {
    acc = ((acc + (sample_88 * 2)) + 5) & 127;
    aux ^= sample_88 & 15;
  }
  else
  {
    acc = ((acc - sample_88) + 11) & 127;
    aux += 3;
  }
  int weight_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001880_8013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int stride_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_40_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_40_1 * 2)) + 5) & 127;
    aux_1 ^= stride_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_40_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_40_2 * 2)) + 5) & 127;
    aux_2 ^= stride_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_67_1 = local_arr_1[aux_1 % 3];
  int stride_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_40_1 == stride_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_67_1 == stride_67_2);
}

int fn_R001880_8013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int stride_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_40 > 12)
  {
    acc = ((acc + (stride_40 * 2)) + 5) & 127;
    aux ^= stride_40 & 15;
  }
  else
  {
    acc = ((acc - stride_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_67 = local_arr[aux % 3];
  acc = (acc + (stride_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_87_1 > 39)
  {
    acc_1 = ((acc_1 + (quantum_87_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_87_2 > 39)
  {
    acc_2 = ((acc_2 + (quantum_87_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_27_1 = 0;
  int cursor_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_27_1 = ((cursor_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_27_2 = ((cursor_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_27_1) & 127;
    acc_2 = (acc_2 + cursor_27_2) & 127;
  }

  int cursor_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_87_1)
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

  switch (cursor_87_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_87_1 == quantum_87_2);
  assert(cursor_27_1 == cursor_27_2);
  assert(cursor_87_1 == cursor_87_2);
}

int fn_R001880_8013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_87 > 39)
  {
    acc = ((acc + (quantum_87 * 2)) + 5) & 127;
    aux ^= quantum_87 & 15;
  }
  else
  {
    acc = ((acc - quantum_87) + 11) & 127;
    aux += 3;
  }
  int cursor_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_27 = ((cursor_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_27) & 127;
  }

  int cursor_87 = (aux + st.buffer[1]) & 3;
  switch (cursor_87)
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

void fn_R001880_8013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_15_1)
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

  switch (anchor_15_2)
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

  int tally_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_75_1 > 48)
  {
    acc_1 = ((acc_1 + (tally_75_1 * 2)) + 5) & 127;
    aux_1 ^= tally_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_75_2 > 48)
  {
    acc_2 = ((acc_2 + (tally_75_2 * 2)) + 5) & 127;
    aux_2 ^= tally_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_15_1 == anchor_15_2);
  assert(tally_75_1 == tally_75_2);
}

int fn_R001880_8013_14(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_15 = (aux + st.buffer[1]) & 3;
  switch (anchor_15)
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

  int tally_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_75 > 48)
  {
    acc = ((acc + (tally_75 * 2)) + 5) & 127;
    aux ^= tally_75 & 15;
  }
  else
  {
    acc = ((acc - tally_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001880_8013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int index_reg_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_14_1)
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

  switch (index_reg_14_2)
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

  int accumulator_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_56_1) & 63;
  aux_2 = (aux_2 + accumulator_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_37_1 > 31)
  {
    acc_1 = ((acc_1 + (quantum_37_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_37_2 > 31)
  {
    acc_2 = ((acc_2 + (quantum_37_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_65_1 = local_arr_1[aux_1 % 3];
  int accumulator_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_14_1 == index_reg_14_2);
  assert(accumulator_56_1 == accumulator_56_2);
  assert(quantum_37_1 == quantum_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
}

int fn_R001880_8013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int index_reg_14 = (aux + st.buffer[1]) & 3;
  switch (index_reg_14)
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

  int accumulator_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_56) & 63;
  acc ^= aux;
  int quantum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_37 > 31)
  {
    acc = ((acc + (quantum_37 * 2)) + 5) & 127;
    aux ^= quantum_37 & 15;
  }
  else
  {
    acc = ((acc - quantum_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_65 = local_arr[aux % 3];
  acc = (acc + (accumulator_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_72_1) & 63;
  aux_2 = (aux_2 + index_reg_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_35_1)
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

  switch (metric_35_2)
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
  int margin_98_1 = local_arr_1[aux_1 % 3];
  int margin_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_98_2 * 2)) & 127;
  int quantum_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_13_1 > 24)
  {
    acc_1 = ((acc_1 + (quantum_13_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_13_2 > 24)
  {
    acc_2 = ((acc_2 + (quantum_13_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_72_1 == index_reg_72_2);
  assert(metric_35_1 == metric_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_98_1 == margin_98_2);
  assert(quantum_13_1 == quantum_13_2);
}

int fn_R001880_8013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_72) & 63;
  acc ^= aux;
  int metric_35 = (aux + st.buffer[1]) & 3;
  switch (metric_35)
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
  int margin_98 = local_arr[aux % 3];
  acc = (acc + (margin_98 * 2)) & 127;
  int quantum_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_13 > 24)
  {
    acc = ((acc + (quantum_13 * 2)) + 5) & 127;
    aux ^= quantum_13 & 15;
  }
  else
  {
    acc = ((acc - quantum_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001880_8013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_53_1) & 63;
  aux_2 = (aux_2 + vector_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_16_1 = 0;
  int parity_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_16_1 = ((parity_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_16_2 = ((parity_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_16_1) & 127;
    acc_2 = (acc_2 + parity_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_53_1 == vector_53_2);
  assert(parity_16_1 == parity_16_2);
}

int fn_R001880_8013_17(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_16 = ((parity_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001880_8013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_33_1 = 0;
  int mask_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_33_1 = ((mask_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_33_2 = ((mask_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_33_1) & 127;
    acc_2 = (acc_2 + mask_33_2) & 127;
  }

  int margin_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_22_1) & 63;
  aux_2 = (aux_2 + margin_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_26_1 = local_arr_1[aux_1 % 3];
  int parity_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_33_1 == mask_33_2);
  assert(margin_22_1 == margin_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_26_1 == parity_26_2);
}

int fn_R001880_8013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_33 = ((mask_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_33) & 127;
  }

  int margin_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_26 = local_arr[aux % 3];
  acc = (acc + (parity_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int window_35_1 = 0;
  int window_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_35_1 = ((window_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_35_2 = ((window_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_35_1) & 127;
    acc_2 = (acc_2 + window_35_2) & 127;
  }

  int window_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_14_1 > 43)
  {
    acc_1 = ((acc_1 + (window_14_1 * 2)) + 5) & 127;
    aux_1 ^= window_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_14_2 > 43)
  {
    acc_2 = ((acc_2 + (window_14_2 * 2)) + 5) & 127;
    aux_2 ^= window_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_15_1)
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

  switch (cursor_15_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_35_1 == window_35_2);
  assert(window_14_1 == window_14_2);
  assert(cursor_15_1 == cursor_15_2);
}

int fn_R001880_8013_19(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int window_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_35 = ((window_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_35) & 127;
  }

  int window_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_14 > 43)
  {
    acc = ((acc + (window_14 * 2)) + 5) & 127;
    aux ^= window_14 & 15;
  }
  else
  {
    acc = ((acc - window_14) + 11) & 127;
    aux += 3;
  }
  int cursor_15 = (aux + st.buffer[1]) & 3;
  switch (cursor_15)
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

void fn_R001880_8013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_41_1 = 0;
  int margin_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_41_1 = ((margin_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_41_2 = ((margin_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_41_1) & 127;
    acc_2 = (acc_2 + margin_41_2) & 127;
  }

  int scale_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_90_1) & 63;
  aux_2 = (aux_2 + scale_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_41_1 == margin_41_2);
  assert(scale_90_1 == scale_90_2);
}

int fn_R001880_8013_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_41 = ((margin_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_41) & 127;
  }

  int scale_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001880_8013_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st_1 = {0};
  struct AudioFrame_R001880_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int scale_56_1 = 0;
  int scale_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_56_1 = ((scale_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_56_2 = ((scale_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_56_1) & 127;
    acc_2 = (acc_2 + scale_56_2) & 127;
  }

  int scale_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_74_1 > 28)
  {
    acc_1 = ((acc_1 + (scale_74_1 * 2)) + 5) & 127;
    aux_1 ^= scale_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_74_2 > 28)
  {
    acc_2 = ((acc_2 + (scale_74_2 * 2)) + 5) & 127;
    aux_2 ^= scale_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_56_1 == scale_56_2);
  assert(scale_74_1 == scale_74_2);
}

int fn_R001880_8013_21(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001880_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int scale_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_56 = ((scale_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_56) & 127;
  }

  int scale_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_74 > 28)
  {
    acc = ((acc + (scale_74 * 2)) + 5) & 127;
    aux ^= scale_74 & 15;
  }
  else
  {
    acc = ((acc - scale_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001880_8013_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st_1 = {0};
  struct FilterState_R001880_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int window_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_44_1) & 63;
  aux_2 = (aux_2 + window_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_44_1 == window_44_2);
}

int fn_R001880_8013_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001880_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int window_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_44) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001880_8013_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st_1 = {0};
  struct SensorNode_R001880_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int delta_63_1 = 0;
  int delta_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_63_1 = ((delta_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_63_2 = ((delta_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_63_1) & 127;
    acc_2 = (acc_2 + delta_63_2) & 127;
  }

  int weight_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_90_1) & 63;
  aux_2 = (aux_2 + weight_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_67_1 = local_arr_1[aux_1 % 3];
  int factor_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_67_2 * 2)) & 127;
  int tally_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_27_1)
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

  switch (tally_27_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_63_1 == delta_63_2);
  assert(weight_90_1 == weight_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_67_1 == factor_67_2);
  assert(tally_27_1 == tally_27_2);
}

int fn_R001880_8013_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001880_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int delta_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_63 = ((delta_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_63) & 127;
  }

  int weight_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_67 = local_arr[aux % 3];
  acc = (acc + (factor_67 * 2)) & 127;
  int tally_27 = (aux + st.buffer[1]) & 3;
  switch (tally_27)
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

void main()
{
  int sec_r001880_0_1;
  int sec_r001880_0_2;
  int sec_r001880_1_1;
  int sec_r001880_1_2;
  int sec_r001880_2_1;
  int sec_r001880_2_2;
  int sec_r001880_3_1;
  int sec_r001880_3_2;
  int sec_r001880_4_1;
  int sec_r001880_4_2;
  int sec_r001880_5_1;
  int sec_r001880_5_2;
  int sec_r001880_6_1;
  int sec_r001880_6_2;
  int sec_r001880_7_1;
  int sec_r001880_7_2;
  int sec_r001880_8_1;
  int sec_r001880_8_2;
  int sec_r001880_9_1;
  int sec_r001880_9_2;
  int sec_r001880_10_1;
  int sec_r001880_10_2;
  int sec_r001880_11_1;
  int sec_r001880_11_2;
  int sec_r001880_12_1;
  int sec_r001880_12_2;
  int sec_r001880_13_1;
  int sec_r001880_13_2;
  int sec_r001880_14_1;
  int sec_r001880_14_2;
  int sec_r001880_15_1;
  int sec_r001880_15_2;
  int sec_r001880_16_1;
  int sec_r001880_16_2;
  int sec_r001880_17_1;
  int sec_r001880_17_2;
  int sec_r001880_18_1;
  int sec_r001880_18_2;
  int sec_r001880_19_1;
  int sec_r001880_19_2;
  int sec_r001880_20_1;
  int sec_r001880_20_2;
  int sec_r001880_21_1;
  int sec_r001880_21_2;
  int sec_r001880_22_1;
  int sec_r001880_22_2;
  int sec_r001880_23_1;
  int sec_r001880_23_2;
  int pub_r001880_0_1;
  int pub_r001880_0_2;
  int pub_r001880_1_1;
  int pub_r001880_1_2;
  int pub_r001880_2_1;
  int pub_r001880_2_2;
  int pub_r001880_3_1;
  int pub_r001880_3_2;
  int pub_r001880_4_1;
  int pub_r001880_4_2;
  int pub_r001880_5_1;
  int pub_r001880_5_2;
  int pub_r001880_6_1;
  int pub_r001880_6_2;
  int pub_r001880_7_1;
  int pub_r001880_7_2;
  int pub_r001880_8_1;
  int pub_r001880_8_2;
  int pub_r001880_9_1;
  int pub_r001880_9_2;
  int pub_r001880_10_1;
  int pub_r001880_10_2;
  int pub_r001880_11_1;
  int pub_r001880_11_2;
  int pub_r001880_12_1;
  int pub_r001880_12_2;
  int pub_r001880_13_1;
  int pub_r001880_13_2;
  int pub_r001880_14_1;
  int pub_r001880_14_2;
  int pub_r001880_15_1;
  int pub_r001880_15_2;
  int pub_r001880_16_1;
  int pub_r001880_16_2;
  int pub_r001880_17_1;
  int pub_r001880_17_2;
  int pub_r001880_18_1;
  int pub_r001880_18_2;
  int pub_r001880_19_1;
  int pub_r001880_19_2;
  int pub_r001880_20_1;
  int pub_r001880_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001880_0_1 >= (-100)) && (pub_r001880_0_1 <= 100));
  __CPROVER_assume((pub_r001880_0_2 >= (-100)) && (pub_r001880_0_2 <= 100));
  __CPROVER_assume((pub_r001880_1_1 >= (-100)) && (pub_r001880_1_1 <= 100));
  __CPROVER_assume((pub_r001880_1_2 >= (-100)) && (pub_r001880_1_2 <= 100));
  __CPROVER_assume((pub_r001880_2_1 >= (-100)) && (pub_r001880_2_1 <= 100));
  __CPROVER_assume((pub_r001880_2_2 >= (-100)) && (pub_r001880_2_2 <= 100));
  __CPROVER_assume((pub_r001880_3_1 >= (-100)) && (pub_r001880_3_1 <= 100));
  __CPROVER_assume((pub_r001880_3_2 >= (-100)) && (pub_r001880_3_2 <= 100));
  __CPROVER_assume((pub_r001880_4_1 >= (-100)) && (pub_r001880_4_1 <= 100));
  __CPROVER_assume((pub_r001880_4_2 >= (-100)) && (pub_r001880_4_2 <= 100));
  __CPROVER_assume((pub_r001880_5_1 >= (-100)) && (pub_r001880_5_1 <= 100));
  __CPROVER_assume((pub_r001880_5_2 >= (-100)) && (pub_r001880_5_2 <= 100));
  __CPROVER_assume((pub_r001880_6_1 >= (-100)) && (pub_r001880_6_1 <= 100));
  __CPROVER_assume((pub_r001880_6_2 >= (-100)) && (pub_r001880_6_2 <= 100));
  __CPROVER_assume((pub_r001880_7_1 >= (-100)) && (pub_r001880_7_1 <= 100));
  __CPROVER_assume((pub_r001880_7_2 >= (-100)) && (pub_r001880_7_2 <= 100));
  __CPROVER_assume((pub_r001880_8_1 >= (-100)) && (pub_r001880_8_1 <= 100));
  __CPROVER_assume((pub_r001880_8_2 >= (-100)) && (pub_r001880_8_2 <= 100));
  __CPROVER_assume((pub_r001880_9_1 >= (-100)) && (pub_r001880_9_1 <= 100));
  __CPROVER_assume((pub_r001880_9_2 >= (-100)) && (pub_r001880_9_2 <= 100));
  __CPROVER_assume((pub_r001880_10_1 >= (-100)) && (pub_r001880_10_1 <= 100));
  __CPROVER_assume((pub_r001880_10_2 >= (-100)) && (pub_r001880_10_2 <= 100));
  __CPROVER_assume((pub_r001880_11_1 >= (-100)) && (pub_r001880_11_1 <= 100));
  __CPROVER_assume((pub_r001880_11_2 >= (-100)) && (pub_r001880_11_2 <= 100));
  __CPROVER_assume((pub_r001880_12_1 >= (-100)) && (pub_r001880_12_1 <= 100));
  __CPROVER_assume((pub_r001880_12_2 >= (-100)) && (pub_r001880_12_2 <= 100));
  __CPROVER_assume((pub_r001880_13_1 >= (-100)) && (pub_r001880_13_1 <= 100));
  __CPROVER_assume((pub_r001880_13_2 >= (-100)) && (pub_r001880_13_2 <= 100));
  __CPROVER_assume((pub_r001880_14_1 >= (-100)) && (pub_r001880_14_1 <= 100));
  __CPROVER_assume((pub_r001880_14_2 >= (-100)) && (pub_r001880_14_2 <= 100));
  __CPROVER_assume((pub_r001880_15_1 >= (-100)) && (pub_r001880_15_1 <= 100));
  __CPROVER_assume((pub_r001880_15_2 >= (-100)) && (pub_r001880_15_2 <= 100));
  __CPROVER_assume((pub_r001880_16_1 >= (-100)) && (pub_r001880_16_1 <= 100));
  __CPROVER_assume((pub_r001880_16_2 >= (-100)) && (pub_r001880_16_2 <= 100));
  __CPROVER_assume((pub_r001880_17_1 >= (-100)) && (pub_r001880_17_1 <= 100));
  __CPROVER_assume((pub_r001880_17_2 >= (-100)) && (pub_r001880_17_2 <= 100));
  __CPROVER_assume((pub_r001880_18_1 >= (-100)) && (pub_r001880_18_1 <= 100));
  __CPROVER_assume((pub_r001880_18_2 >= (-100)) && (pub_r001880_18_2 <= 100));
  __CPROVER_assume((pub_r001880_19_1 >= (-100)) && (pub_r001880_19_1 <= 100));
  __CPROVER_assume((pub_r001880_19_2 >= (-100)) && (pub_r001880_19_2 <= 100));
  __CPROVER_assume((pub_r001880_20_1 >= (-100)) && (pub_r001880_20_1 <= 100));
  __CPROVER_assume((pub_r001880_20_2 >= (-100)) && (pub_r001880_20_2 <= 100));
  __CPROVER_assume((sec_r001880_0_1 >= 0) && (sec_r001880_0_1 <= 255));
  __CPROVER_assume((sec_r001880_0_2 >= 0) && (sec_r001880_0_2 <= 255));
  __CPROVER_assume((sec_r001880_1_1 >= 0) && (sec_r001880_1_1 <= 255));
  __CPROVER_assume((sec_r001880_1_2 >= 0) && (sec_r001880_1_2 <= 255));
  __CPROVER_assume((sec_r001880_2_1 >= 0) && (sec_r001880_2_1 <= 255));
  __CPROVER_assume((sec_r001880_2_2 >= 0) && (sec_r001880_2_2 <= 255));
  __CPROVER_assume((sec_r001880_3_1 >= 0) && (sec_r001880_3_1 <= 255));
  __CPROVER_assume((sec_r001880_3_2 >= 0) && (sec_r001880_3_2 <= 255));
  __CPROVER_assume((sec_r001880_4_1 >= 0) && (sec_r001880_4_1 <= 255));
  __CPROVER_assume((sec_r001880_4_2 >= 0) && (sec_r001880_4_2 <= 255));
  __CPROVER_assume((sec_r001880_5_1 >= 0) && (sec_r001880_5_1 <= 255));
  __CPROVER_assume((sec_r001880_5_2 >= 0) && (sec_r001880_5_2 <= 255));
  __CPROVER_assume((sec_r001880_6_1 >= 0) && (sec_r001880_6_1 <= 255));
  __CPROVER_assume((sec_r001880_6_2 >= 0) && (sec_r001880_6_2 <= 255));
  __CPROVER_assume((sec_r001880_7_1 >= 0) && (sec_r001880_7_1 <= 255));
  __CPROVER_assume((sec_r001880_7_2 >= 0) && (sec_r001880_7_2 <= 255));
  __CPROVER_assume((sec_r001880_8_1 >= 0) && (sec_r001880_8_1 <= 255));
  __CPROVER_assume((sec_r001880_8_2 >= 0) && (sec_r001880_8_2 <= 255));
  __CPROVER_assume((sec_r001880_9_1 >= 0) && (sec_r001880_9_1 <= 255));
  __CPROVER_assume((sec_r001880_9_2 >= 0) && (sec_r001880_9_2 <= 255));
  __CPROVER_assume((sec_r001880_10_1 >= 0) && (sec_r001880_10_1 <= 255));
  __CPROVER_assume((sec_r001880_10_2 >= 0) && (sec_r001880_10_2 <= 255));
  __CPROVER_assume((sec_r001880_11_1 >= 0) && (sec_r001880_11_1 <= 255));
  __CPROVER_assume((sec_r001880_11_2 >= 0) && (sec_r001880_11_2 <= 255));
  __CPROVER_assume((sec_r001880_12_1 >= 0) && (sec_r001880_12_1 <= 255));
  __CPROVER_assume((sec_r001880_12_2 >= 0) && (sec_r001880_12_2 <= 255));
  __CPROVER_assume((sec_r001880_13_1 >= 0) && (sec_r001880_13_1 <= 255));
  __CPROVER_assume((sec_r001880_13_2 >= 0) && (sec_r001880_13_2 <= 255));
  __CPROVER_assume((sec_r001880_14_1 >= 0) && (sec_r001880_14_1 <= 255));
  __CPROVER_assume((sec_r001880_14_2 >= 0) && (sec_r001880_14_2 <= 255));
  __CPROVER_assume((sec_r001880_15_1 >= 0) && (sec_r001880_15_1 <= 255));
  __CPROVER_assume((sec_r001880_15_2 >= 0) && (sec_r001880_15_2 <= 255));
  __CPROVER_assume((sec_r001880_16_1 >= 0) && (sec_r001880_16_1 <= 255));
  __CPROVER_assume((sec_r001880_16_2 >= 0) && (sec_r001880_16_2 <= 255));
  __CPROVER_assume((sec_r001880_17_1 >= 0) && (sec_r001880_17_1 <= 255));
  __CPROVER_assume((sec_r001880_17_2 >= 0) && (sec_r001880_17_2 <= 255));
  __CPROVER_assume((sec_r001880_18_1 >= 0) && (sec_r001880_18_1 <= 255));
  __CPROVER_assume((sec_r001880_18_2 >= 0) && (sec_r001880_18_2 <= 255));
  __CPROVER_assume((sec_r001880_19_1 >= 0) && (sec_r001880_19_1 <= 255));
  __CPROVER_assume((sec_r001880_19_2 >= 0) && (sec_r001880_19_2 <= 255));
  __CPROVER_assume((sec_r001880_20_1 >= 0) && (sec_r001880_20_1 <= 255));
  __CPROVER_assume((sec_r001880_20_2 >= 0) && (sec_r001880_20_2 <= 255));
  __CPROVER_assume((sec_r001880_21_1 >= 0) && (sec_r001880_21_1 <= 255));
  __CPROVER_assume((sec_r001880_21_2 >= 0) && (sec_r001880_21_2 <= 255));
  __CPROVER_assume((sec_r001880_22_1 >= 0) && (sec_r001880_22_1 <= 255));
  __CPROVER_assume((sec_r001880_22_2 >= 0) && (sec_r001880_22_2 <= 255));
  __CPROVER_assume((sec_r001880_23_1 >= 0) && (sec_r001880_23_1 <= 255));
  __CPROVER_assume((sec_r001880_23_2 >= 0) && (sec_r001880_23_2 <= 255));
  struct FilterState_R001880_8013_0 st_var_0_1 = {0};
  struct FilterState_R001880_8013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001880_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001880_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001880_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001880_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001880_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001880_0_2 + 7) & 15;
  struct AudioFrame_R001880_8013_1 st_var_1_1 = {0};
  struct AudioFrame_R001880_8013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001880_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001880_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001880_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001880_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001880_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001880_0_2 + 9) & 15;
  struct SensorNode_R001880_8013_2 st_var_2_1 = {0};
  struct SensorNode_R001880_8013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001880_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001880_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001880_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001880_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001880_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001880_0_2 + 11) & 15;
  union TelemetryField_R001880_8013_0 u_var_1;
  union TelemetryField_R001880_8013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001880_8013_0(sec_r001880_0_1, pub_r001880_1_1, pub_r001880_2_1);
  int helper_flow_0_2 = fn_R001880_8013_0(sec_r001880_0_2, pub_r001880_1_2, pub_r001880_2_2);
  fn_R001880_8013_0_2(sec_r001880_0_1, pub_r001880_1_1, pub_r001880_2_1, sec_r001880_0_2, pub_r001880_1_2, pub_r001880_2_2);
  int helper_flow_1_1 = fn_R001880_8013_1(sec_r001880_1_1, sec_r001880_2_1);
  int helper_flow_1_2 = fn_R001880_8013_1(sec_r001880_1_2, sec_r001880_2_2);
  fn_R001880_8013_1_2(sec_r001880_1_1, sec_r001880_2_1, sec_r001880_1_2, sec_r001880_2_2);
  int helper_flow_2_1 = fn_R001880_8013_2(sec_r001880_2_1, sec_r001880_3_1);
  int helper_flow_2_2 = fn_R001880_8013_2(sec_r001880_2_2, sec_r001880_3_2);
  fn_R001880_8013_2_2(sec_r001880_2_1, sec_r001880_3_1, sec_r001880_2_2, sec_r001880_3_2);
  int helper_flow_3_1 = fn_R001880_8013_3(sec_r001880_3_1, pub_r001880_4_1, pub_r001880_5_1, pub_r001880_6_1, pub_r001880_7_1);
  int helper_flow_3_2 = fn_R001880_8013_3(sec_r001880_3_2, pub_r001880_4_2, pub_r001880_5_2, pub_r001880_6_2, pub_r001880_7_2);
  fn_R001880_8013_3_2(sec_r001880_3_1, pub_r001880_4_1, pub_r001880_5_1, pub_r001880_6_1, pub_r001880_7_1, sec_r001880_3_2, pub_r001880_4_2, pub_r001880_5_2, pub_r001880_6_2, pub_r001880_7_2);
  int helper_flow_4_1 = fn_R001880_8013_4(sec_r001880_4_1, pub_r001880_5_1, pub_r001880_6_1);
  int helper_flow_4_2 = fn_R001880_8013_4(sec_r001880_4_2, pub_r001880_5_2, pub_r001880_6_2);
  fn_R001880_8013_4_2(sec_r001880_4_1, pub_r001880_5_1, pub_r001880_6_1, sec_r001880_4_2, pub_r001880_5_2, pub_r001880_6_2);
  int helper_flow_5_1 = fn_R001880_8013_5(sec_r001880_5_1, sec_r001880_6_1, pub_r001880_7_1, pub_r001880_8_1);
  int helper_flow_5_2 = fn_R001880_8013_5(sec_r001880_5_2, sec_r001880_6_2, pub_r001880_7_2, pub_r001880_8_2);
  fn_R001880_8013_5_2(sec_r001880_5_1, sec_r001880_6_1, pub_r001880_7_1, pub_r001880_8_1, sec_r001880_5_2, sec_r001880_6_2, pub_r001880_7_2, pub_r001880_8_2);
  int helper_flow_6_1 = fn_R001880_8013_6(sec_r001880_6_1, sec_r001880_7_1);
  int helper_flow_6_2 = fn_R001880_8013_6(sec_r001880_6_2, sec_r001880_7_2);
  fn_R001880_8013_6_2(sec_r001880_6_1, sec_r001880_7_1, sec_r001880_6_2, sec_r001880_7_2);
  int helper_flow_7_1 = fn_R001880_8013_7(sec_r001880_7_1, pub_r001880_8_1, pub_r001880_9_1, pub_r001880_10_1);
  int helper_flow_7_2 = fn_R001880_8013_7(sec_r001880_7_2, pub_r001880_8_2, pub_r001880_9_2, pub_r001880_10_2);
  fn_R001880_8013_7_2(sec_r001880_7_1, pub_r001880_8_1, pub_r001880_9_1, pub_r001880_10_1, sec_r001880_7_2, pub_r001880_8_2, pub_r001880_9_2, pub_r001880_10_2);
  int helper_flow_8_1 = fn_R001880_8013_8(sec_r001880_8_1, sec_r001880_9_1, pub_r001880_10_1, pub_r001880_11_1);
  int helper_flow_8_2 = fn_R001880_8013_8(sec_r001880_8_2, sec_r001880_9_2, pub_r001880_10_2, pub_r001880_11_2);
  fn_R001880_8013_8_2(sec_r001880_8_1, sec_r001880_9_1, pub_r001880_10_1, pub_r001880_11_1, sec_r001880_8_2, sec_r001880_9_2, pub_r001880_10_2, pub_r001880_11_2);
  int helper_flow_9_1 = fn_R001880_8013_9(sec_r001880_9_1, pub_r001880_10_1);
  int helper_flow_9_2 = fn_R001880_8013_9(sec_r001880_9_2, pub_r001880_10_2);
  fn_R001880_8013_9_2(sec_r001880_9_1, pub_r001880_10_1, sec_r001880_9_2, pub_r001880_10_2);
  int helper_flow_10_1 = fn_R001880_8013_10(sec_r001880_10_1, sec_r001880_11_1);
  int helper_flow_10_2 = fn_R001880_8013_10(sec_r001880_10_2, sec_r001880_11_2);
  fn_R001880_8013_10_2(sec_r001880_10_1, sec_r001880_11_1, sec_r001880_10_2, sec_r001880_11_2);
  int helper_flow_11_1 = fn_R001880_8013_11(sec_r001880_11_1, pub_r001880_12_1, pub_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1);
  int helper_flow_11_2 = fn_R001880_8013_11(sec_r001880_11_2, pub_r001880_12_2, pub_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2);
  fn_R001880_8013_11_2(sec_r001880_11_1, pub_r001880_12_1, pub_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1, sec_r001880_11_2, pub_r001880_12_2, pub_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2);
  int helper_flow_12_1 = fn_R001880_8013_12(sec_r001880_12_1, sec_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1);
  int helper_flow_12_2 = fn_R001880_8013_12(sec_r001880_12_2, sec_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2);
  fn_R001880_8013_12_2(sec_r001880_12_1, sec_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1, sec_r001880_12_2, sec_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2);
  int helper_flow_13_1 = fn_R001880_8013_13(sec_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1, pub_r001880_16_1);
  int helper_flow_13_2 = fn_R001880_8013_13(sec_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2, pub_r001880_16_2);
  fn_R001880_8013_13_2(sec_r001880_13_1, pub_r001880_14_1, pub_r001880_15_1, pub_r001880_16_1, sec_r001880_13_2, pub_r001880_14_2, pub_r001880_15_2, pub_r001880_16_2);
  int stage_v_0_1 = (((sec_r001880_19_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_0_2 = (((sec_r001880_19_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_0_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_1_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_1_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_2_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_2_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001880_1_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_3_2 = (((sec_r001880_1_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_3_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_4_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_4_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((pub_r001880_11_1 * 2) + 18) & 63;
  int stage_v_5_2 = ((pub_r001880_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_6_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_6_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_7_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_7_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001880_3_1 ^ 0x2A) * 2) + pub_r001880_8_1) & 127;
  int stage_v_8_2 = (((sec_r001880_3_2 ^ 0x2A) * 2) + pub_r001880_8_2) & 127;
  if (stage_v_8_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001880_0_1 * 2) + 12) & 63;
  int stage_v_9_2 = ((pub_r001880_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001880_20_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_10_2 = (((sec_r001880_20_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_10_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001880_4_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_11_2 = (((sec_r001880_4_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_11_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001880_6_1 * 2) + 26) & 63;
  int stage_v_12_2 = ((pub_r001880_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001880_7_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_13_2 = (((sec_r001880_7_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_13_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_14_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_14_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001880_12_1 * 2) + 8) & 63;
  int stage_v_15_2 = ((pub_r001880_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_16_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_16_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001880_8_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_17_2 = (((sec_r001880_8_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_17_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001880_9_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_18_2 = (((sec_r001880_9_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_18_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001880_8_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_19_2 = (((sec_r001880_8_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_19_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001880_14_1) & 127;
  int stage_v_20_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001880_14_2) & 127;
  if (stage_v_20_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_21_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_21_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001880_19_1 * 2) + 48) & 63;
  int stage_v_22_2 = ((pub_r001880_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001880_8_1) & 127;
  int stage_v_23_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001880_8_2) & 127;
  if (stage_v_23_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001880_13_1 ^ 0x2A) * 2) + pub_r001880_18_1) & 127;
  int stage_v_24_2 = (((sec_r001880_13_2 ^ 0x2A) * 2) + pub_r001880_18_2) & 127;
  if (stage_v_24_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_25_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_25_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_26_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_26_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001880_12_1 * 2) + 31) & 63;
  int stage_v_27_2 = ((pub_r001880_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_28_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_28_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_29_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_29_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_30_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_30_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001880_22_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_31_2 = (((sec_r001880_22_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_31_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((pub_r001880_6_1 * 2) + 8) & 63;
  int stage_v_32_2 = ((pub_r001880_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001880_14_1 * 2) + 38) & 63;
  int stage_v_33_2 = ((pub_r001880_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((sec_r001880_15_1 ^ 0x2A) * 2) + pub_r001880_1_1) & 127;
  int stage_v_34_2 = (((sec_r001880_15_2 ^ 0x2A) * 2) + pub_r001880_1_2) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_35_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_35_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((pub_r001880_13_1 * 2) + 37) & 63;
  int stage_v_36_2 = ((pub_r001880_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_37_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_37_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_38_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_38_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((sec_r001880_11_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_39_2 = (((sec_r001880_11_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_39_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001880_12_1 * 2) + 33) & 63;
  int stage_v_40_2 = ((pub_r001880_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001880_19_1 * 2) + 8) & 63;
  int stage_v_41_2 = ((pub_r001880_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001880_17_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_42_2 = (((sec_r001880_17_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_42_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001880_9_1 * 2) + 8) & 63;
  int stage_v_43_2 = ((pub_r001880_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001880_5_1 * 2) + 31) & 63;
  int stage_v_44_2 = ((pub_r001880_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001880_14_1) & 127;
  int stage_v_45_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001880_14_2) & 127;
  if (stage_v_45_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001880_18_1 * 2) + 29) & 63;
  int stage_v_46_2 = ((pub_r001880_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_47_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_47_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001880_7_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_48_2 = (((sec_r001880_7_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_48_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((pub_r001880_14_1 * 2) + 13) & 63;
  int stage_v_49_2 = ((pub_r001880_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001880_15_1 * 2) + 31) & 63;
  int stage_v_50_2 = ((pub_r001880_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_51_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_51_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001880_0_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001880_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_53_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_53_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001880_15_1 * 2) + 8) & 63;
  int stage_v_54_2 = ((pub_r001880_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((sec_r001880_2_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_55_2 = (((sec_r001880_2_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_55_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((pub_r001880_1_1 * 2) + 39) & 63;
  int stage_v_56_2 = ((pub_r001880_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001880_18_1 * 2) + 38) & 63;
  int stage_v_57_2 = ((pub_r001880_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_58_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_58_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((pub_r001880_10_1 * 2) + 22) & 63;
  int stage_v_59_2 = ((pub_r001880_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_60_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_60_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_61_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_61_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_62_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_62_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_63_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_63_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_64_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_64_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_65_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_65_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_66_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_66_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_67_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_67_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_68_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_68_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_69_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_69_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001880_2_1) & 127;
  int stage_v_70_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001880_2_2) & 127;
  if (stage_v_70_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001880_8_1) & 127;
  int stage_v_71_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001880_8_2) & 127;
  if (stage_v_71_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((sec_r001880_18_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_72_2 = (((sec_r001880_18_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_72_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((pub_r001880_12_1 * 2) + 43) & 63;
  int stage_v_73_2 = ((pub_r001880_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_74_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_74_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((pub_r001880_17_1 * 2) + 32) & 63;
  int stage_v_75_2 = ((pub_r001880_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001880_18_1 * 2) + 17) & 63;
  int stage_v_76_2 = ((pub_r001880_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001880_15_1 * 2) + 19) & 63;
  int stage_v_77_2 = ((pub_r001880_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((sec_r001880_16_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_78_2 = (((sec_r001880_16_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_78_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_79_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_79_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_80_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_80_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_81_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_81_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_82_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_82_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001880_22_1 ^ 0x2A) * 2) + pub_r001880_1_1) & 127;
  int stage_v_83_2 = (((sec_r001880_22_2 ^ 0x2A) * 2) + pub_r001880_1_2) & 127;
  if (stage_v_83_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_84_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_85_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_85_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001880_5_1 * 2) + 23) & 63;
  int stage_v_86_2 = ((pub_r001880_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001880_13_1) & 127;
  int stage_v_87_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001880_13_2) & 127;
  if (stage_v_87_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((sec_r001880_3_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_88_2 = (((sec_r001880_3_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_88_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((sec_r001880_16_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_89_2 = (((sec_r001880_16_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_89_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_90_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_90_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_91_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_91_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((sec_r001880_23_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_92_2 = (((sec_r001880_23_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_92_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((sec_r001880_17_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_93_2 = (((sec_r001880_17_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_93_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001880_15_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_94_2 = (((sec_r001880_15_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_94_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_95_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_95_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_96_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_96_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_97_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_97_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_98_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_98_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001880_1_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_99_2 = (((sec_r001880_1_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_99_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_100_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_100_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_101_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_101_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_102_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_102_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001880_13_1) & 127;
  int stage_v_103_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001880_13_2) & 127;
  if (stage_v_103_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_104_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_104_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001880_2_1 * 2) + 7) & 63;
  int stage_v_105_2 = ((pub_r001880_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001880_1_1) & 127;
  int stage_v_106_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001880_1_2) & 127;
  if (stage_v_106_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_107_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_107_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((sec_r001880_10_1 ^ 0x2A) * 2) + pub_r001880_15_1) & 127;
  int stage_v_108_2 = (((sec_r001880_10_2 ^ 0x2A) * 2) + pub_r001880_15_2) & 127;
  if (stage_v_108_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001880_9_1 * 2) + 28) & 63;
  int stage_v_109_2 = ((pub_r001880_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_110_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_110_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_111_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_111_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001880_12_1 * 2) + 38) & 63;
  int stage_v_112_2 = ((pub_r001880_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_113_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_113_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_114_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_114_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((sec_r001880_12_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_115_2 = (((sec_r001880_12_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_115_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((pub_r001880_15_1 * 2) + 13) & 63;
  int stage_v_116_2 = ((pub_r001880_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_117_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_117_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_118_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_118_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_119_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_119_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((pub_r001880_7_1 * 2) + 14) & 63;
  int stage_v_120_2 = ((pub_r001880_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001880_16_1 * 2) + 20) & 63;
  int stage_v_121_2 = ((pub_r001880_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001880_19_1 * 2) + 9) & 63;
  int stage_v_122_2 = ((pub_r001880_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001880_20_1 * 2) + 44) & 63;
  int stage_v_123_2 = ((pub_r001880_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_124_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_124_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001880_1_1 * 2) + 5) & 63;
  int stage_v_125_2 = ((pub_r001880_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_126_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_126_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001880_8_1) & 127;
  int stage_v_127_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001880_8_2) & 127;
  if (stage_v_127_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001880_2_1) & 127;
  int stage_v_128_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001880_2_2) & 127;
  if (stage_v_128_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_129_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_129_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_130_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_130_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_131_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_131_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001880_19_1 * 2) + 33) & 63;
  int stage_v_132_2 = ((pub_r001880_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_133_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_133_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_134_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_134_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_135_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_135_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_136_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_137_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_137_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_138_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_138_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_139_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_139_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_140_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_140_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001880_17_1 * 2) + 21) & 63;
  int stage_v_141_2 = ((pub_r001880_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_142_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_142_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_143_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_143_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_144_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_144_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001880_14_1) & 127;
  int stage_v_145_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001880_14_2) & 127;
  if (stage_v_145_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001880_12_1 * 2) + 25) & 63;
  int stage_v_146_2 = ((pub_r001880_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_147_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_147_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001880_13_1) & 127;
  int stage_v_148_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001880_13_2) & 127;
  if (stage_v_148_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_149_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_149_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((sec_r001880_7_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_150_2 = (((sec_r001880_7_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_150_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001880_19_1 * 2) + 44) & 63;
  int stage_v_151_2 = ((pub_r001880_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_152_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_152_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001880_8_1) & 127;
  int stage_v_153_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001880_8_2) & 127;
  if (stage_v_153_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_154_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_154_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001880_14_1) & 127;
  int stage_v_155_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001880_14_2) & 127;
  if (stage_v_155_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_156_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_156_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_157_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_157_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001880_13_1) & 127;
  int stage_v_158_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001880_13_2) & 127;
  if (stage_v_158_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((pub_r001880_18_1 * 2) + 33) & 63;
  int stage_v_159_2 = ((pub_r001880_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_160_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_160_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((pub_r001880_17_1 * 2) + 25) & 63;
  int stage_v_161_2 = ((pub_r001880_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_162_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_162_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001880_18_1) & 127;
  int stage_v_163_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001880_18_2) & 127;
  if (stage_v_163_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001880_11_1 * 2) + 22) & 63;
  int stage_v_164_2 = ((pub_r001880_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_165_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_165_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_166_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_166_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_167_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_167_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_168_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_168_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_169_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_169_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((sec_r001880_20_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_170_2 = (((sec_r001880_20_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_170_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001880_16_1) & 127;
  int stage_v_171_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001880_16_2) & 127;
  if (stage_v_171_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001880_7_1 * 2) + 50) & 63;
  int stage_v_172_2 = ((pub_r001880_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_139_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_173_2 = (((stage_v_139_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_173_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((sec_r001880_15_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_174_2 = (((sec_r001880_15_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_174_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001880_0_1) & 127;
  int stage_v_175_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001880_0_2) & 127;
  if (stage_v_175_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001880_2_1) & 127;
  int stage_v_176_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001880_2_2) & 127;
  if (stage_v_176_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001880_17_1) & 127;
  int stage_v_177_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001880_17_2) & 127;
  if (stage_v_177_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((pub_r001880_10_1 * 2) + 34) & 63;
  int stage_v_178_2 = ((pub_r001880_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001880_19_1) & 127;
  int stage_v_179_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001880_19_2) & 127;
  if (stage_v_179_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_180_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_180_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_181_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_181_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_182_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_182_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001880_0_1 * 2) + 42) & 63;
  int stage_v_183_2 = ((pub_r001880_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_184_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_184_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001880_7_1 * 2) + 44) & 63;
  int stage_v_185_2 = ((pub_r001880_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_179_1 ^ 0x2A) * 2) + pub_r001880_20_1) & 127;
  int stage_v_186_2 = (((stage_v_179_2 ^ 0x2A) * 2) + pub_r001880_20_2) & 127;
  if (stage_v_186_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_187_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_187_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001880_6_1) & 127;
  int stage_v_188_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001880_6_2) & 127;
  if (stage_v_188_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001880_12_1) & 127;
  int stage_v_189_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001880_12_2) & 127;
  if (stage_v_189_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((pub_r001880_1_1 * 2) + 41) & 63;
  int stage_v_190_2 = ((pub_r001880_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001880_19_1 * 2) + 44) & 63;
  int stage_v_191_2 = ((pub_r001880_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_180_1 ^ 0x2A) * 2) + pub_r001880_7_1) & 127;
  int stage_v_192_2 = (((stage_v_180_2 ^ 0x2A) * 2) + pub_r001880_7_2) & 127;
  if (stage_v_192_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((sec_r001880_22_1 ^ 0x2A) * 2) + pub_r001880_18_1) & 127;
  int stage_v_193_2 = (((sec_r001880_22_2 ^ 0x2A) * 2) + pub_r001880_18_2) & 127;
  if (stage_v_193_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((pub_r001880_5_1 * 2) + 30) & 63;
  int stage_v_194_2 = ((pub_r001880_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001880_3_1) & 127;
  int stage_v_195_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001880_3_2) & 127;
  if (stage_v_195_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001880_14_1) & 127;
  int stage_v_196_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001880_14_2) & 127;
  if (stage_v_196_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_197_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_197_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001880_4_1) & 127;
  int stage_v_198_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001880_4_2) & 127;
  if (stage_v_198_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001880_12_1 * 2) + 46) & 63;
  int stage_v_199_2 = ((pub_r001880_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001880_10_1 * 2) + 32) & 63;
  int stage_v_200_2 = ((pub_r001880_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001880_10_1) & 127;
  int stage_v_201_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001880_10_2) & 127;
  if (stage_v_201_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001880_2_1) & 127;
  int stage_v_202_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001880_2_2) & 127;
  if (stage_v_202_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001880_5_1 * 2) + 24) & 63;
  int stage_v_203_2 = ((pub_r001880_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001880_11_1) & 127;
  int stage_v_204_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001880_11_2) & 127;
  if (stage_v_204_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001880_9_1) & 127;
  int stage_v_205_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001880_9_2) & 127;
  if (stage_v_205_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001880_5_1) & 127;
  int stage_v_206_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001880_5_2) & 127;
  if (stage_v_206_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001880_22_1 != sec_r001880_22_2);
  __CPROVER_assume(pub_r001880_1_1 == pub_r001880_1_2);
  __CPROVER_assume(pub_r001880_17_1 == pub_r001880_17_2);
  __CPROVER_assume(sec_r001880_2_1 != sec_r001880_2_2);
  __CPROVER_assume(sec_r001880_3_1 != sec_r001880_3_2);
  __CPROVER_assume(pub_r001880_11_1 == pub_r001880_11_2);
  __CPROVER_assume(pub_r001880_15_1 == pub_r001880_15_2);
  __CPROVER_assume(pub_r001880_16_1 == pub_r001880_16_2);
  __CPROVER_assume(sec_r001880_15_1 != sec_r001880_15_2);
  __CPROVER_assume(sec_r001880_16_1 != sec_r001880_16_2);
  __CPROVER_assume(pub_r001880_10_1 == pub_r001880_10_2);
  __CPROVER_assume(sec_r001880_12_1 != sec_r001880_12_2);
  __CPROVER_assume(pub_r001880_13_1 == pub_r001880_13_2);
  __CPROVER_assume(sec_r001880_18_1 != sec_r001880_18_2);
  __CPROVER_assume(pub_r001880_20_1 == pub_r001880_20_2);
  __CPROVER_assume(pub_r001880_9_1 == pub_r001880_9_2);
  __CPROVER_assume(sec_r001880_11_1 != sec_r001880_11_2);
  __CPROVER_assume(pub_r001880_3_1 == pub_r001880_3_2);
  __CPROVER_assume(pub_r001880_6_1 == pub_r001880_6_2);
  __CPROVER_assume(sec_r001880_5_1 != sec_r001880_5_2);
  __CPROVER_assume(sec_r001880_1_1 != sec_r001880_1_2);
  __CPROVER_assume(pub_r001880_14_1 == pub_r001880_14_2);
  __CPROVER_assume(pub_r001880_18_1 == pub_r001880_18_2);
  __CPROVER_assume(sec_r001880_21_1 != sec_r001880_21_2);
  __CPROVER_assume(pub_r001880_12_1 == pub_r001880_12_2);
  __CPROVER_assume(sec_r001880_9_1 != sec_r001880_9_2);
  __CPROVER_assume(sec_r001880_10_1 != sec_r001880_10_2);
  __CPROVER_assume(pub_r001880_7_1 == pub_r001880_7_2);
  __CPROVER_assume(sec_r001880_13_1 != sec_r001880_13_2);
  __CPROVER_assume(sec_r001880_14_1 != sec_r001880_14_2);
  __CPROVER_assume(pub_r001880_4_1 == pub_r001880_4_2);
  __CPROVER_assume(pub_r001880_0_1 == pub_r001880_0_2);
  __CPROVER_assume(sec_r001880_6_1 != sec_r001880_6_2);
  __CPROVER_assume(pub_r001880_5_1 == pub_r001880_5_2);
  __CPROVER_assume(sec_r001880_17_1 != sec_r001880_17_2);
  __CPROVER_assume(sec_r001880_19_1 != sec_r001880_19_2);
  __CPROVER_assume(sec_r001880_20_1 != sec_r001880_20_2);
  __CPROVER_assume(pub_r001880_8_1 == pub_r001880_8_2);
  __CPROVER_assume(pub_r001880_2_1 == pub_r001880_2_2);
  __CPROVER_assume(sec_r001880_7_1 != sec_r001880_7_2);
  __CPROVER_assume(sec_r001880_4_1 != sec_r001880_4_2);
  __CPROVER_assume(pub_r001880_19_1 == pub_r001880_19_2);
  __CPROVER_assume(sec_r001880_8_1 != sec_r001880_8_2);
  __CPROVER_assume(sec_r001880_23_1 != sec_r001880_23_2);
  __CPROVER_assume(sec_r001880_0_1 != sec_r001880_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
  assert(helper_flow_13_1 == helper_flow_13_2);
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
}


